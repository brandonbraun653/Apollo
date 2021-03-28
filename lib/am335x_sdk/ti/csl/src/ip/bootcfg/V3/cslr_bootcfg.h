/********************************************************************
 * Copyright (C) 2013-2018 Texas Instruments Incorporated.
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
#ifndef CSLR_BOOTCFG_H
#define CSLR_BOOTCFG_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
* Register Overlay Structure for bootCfg_mmr_address_block
**************************************************************************/
typedef struct {
    volatile Uint32 BOOTCFG_REVISION;
    volatile Uint8  RSVD0[4];
    volatile Uint32 DIEID[4];
    volatile Uint32 JTAGID;
    volatile Uint8  RSVD1[4];
    volatile Uint32 DEVSTAT;
    volatile Uint8  RSVD2[20];
    volatile Uint32 KICK0;
    volatile Uint32 KICK1;
    volatile Uint32 DSP_BOOT_ADDR0;
    volatile Uint8  RSVD3[156];
    volatile Uint32 BOOTCFG_INTR_RAW_STAT_SET;
    volatile Uint32 BOOTCFG_INTR_ENABLED_STAT_CLR;
    volatile Uint32 BOOTCFG_INTR_ENABLE;
    volatile Uint32 BOOTCFG_INTR_ENABLE_CLR;
    volatile Uint32 BOOTCFG_EOI;
    volatile Uint32 BOOTCFG_FAULT_ADDR;
    volatile Uint32 BOOTCFG_FAULT_STAT;
    volatile Uint32 BOOTCFG_FAULT_CLR;
    volatile Uint8  RSVD4[16];
    volatile Uint32 MACID0;
    volatile Uint32 MACID1;
    volatile Uint8  RSVD5[16];
    volatile Uint32 PCIEVENDORID;
    volatile Uint32 DISABLESTAT;
    volatile Uint32 LRSTNMISTAT_CLR;
    volatile Uint32 RESET_STAT_CLR;
    volatile Uint8  RSVD6[4];
    volatile Uint32 BOOTCOMPLETE;
    volatile Uint32 BOOTPROGRESS;
    volatile Uint32 RESET_STAT;
    volatile Uint32 LRSTNMISTAT;
    volatile Uint32 DEVCFG;
    volatile Uint32 PWR_STATE;
    volatile Uint32 INITIATOR_PRIORITY0;
    volatile Uint32 INITIATOR_PRIORITY1;
    volatile Uint8  RSVD7[36];
    volatile Uint32 SR0_CLASS0;
    volatile Uint8  RSVD8[12];
    volatile Uint32 SR0_OPP0_SEN[4];
    volatile Uint32 SR0_OPP1_SEN[4];
    volatile Uint32 SR0_OPP2_SEN[4];
    volatile Uint32 SR0_OPP3_SEN[4];
    volatile Uint8  RSVD9[48];
    volatile Uint32 NMIGR0;
    volatile Uint8  RSVD10[60];
    volatile Uint32 IPCGR0;
    volatile Uint8  RSVD11[28];
    volatile Uint32 IPCGR8;
    volatile Uint8  RSVD12[8];
    volatile Uint32 IPCGR11_12[2];
    volatile Uint32 IPCGR13_14[2];
    volatile Uint32 IPCGRH;
    volatile Uint32 IPCAR0;
    volatile Uint8  RSVD13[28];
    volatile Uint32 IPCAR8;
    volatile Uint8  RSVD14[8];
    volatile Uint32 IPCAR11_12[2];
    volatile Uint32 IPCAR13_14[2];
    volatile Uint32 IPCARH;
    volatile Uint8  RSVD15[24];
    volatile Uint32 TINPSEL0;
    volatile Uint32 TINPSEL1;
    volatile Uint8  RSVD16[24];
    volatile Uint32 TOUTPSEL0;
    volatile Uint8  RSVD17[12];
    volatile Uint32 RSTMUX0;
    volatile Uint8  RSVD18[28];
    volatile Uint32 RSTMUX8;
    volatile Uint8  RSVD19[36];
    volatile Uint32 MAIN_PLL_CTL0;
    volatile Uint32 MAIN_PLL_CTL1;
    volatile Uint32 NSS_PLL_CTL0;
    volatile Uint32 NSS_PLL_CTL1;
    volatile Uint32 DDR3A_PLL_CTL0;
    volatile Uint32 DDR3A_PLL_CTL1;
    volatile Uint8  RSVD20[8];
    volatile Uint32 ARM_PLL_CTL0;
    volatile Uint32 ARM_PLL_CTL1;
    volatile Uint8  RSVD21[8];
    volatile Uint32 DSS_PLL_CTL0;
    volatile Uint32 DSS_PLL_CTL1;
    volatile Uint32 ICSS_PLL_CTL0;
    volatile Uint32 ICSS_PLL_CTL1;
    volatile Uint32 UART_PLL_CTL0;
    volatile Uint32 UART_PLL_CTL1;
    volatile Uint8  RSVD22[104];
    volatile Uint32 ARMENDIAN_CFG0_0;
    volatile Uint32 ARMENDIAN_CFG0_1;
    volatile Uint32 ARMENDIAN_CFG0_2;
    volatile Uint8  RSVD23[4];
    volatile Uint32 ARMENDIAN_CFG1_0;
    volatile Uint32 ARMENDIAN_CFG1_1;
    volatile Uint32 ARMENDIAN_CFG1_2;
    volatile Uint8  RSVD24[4];
    volatile Uint32 ARMENDIAN_CFG2_0;
    volatile Uint32 ARMENDIAN_CFG2_1;
    volatile Uint32 ARMENDIAN_CFG2_2;
    volatile Uint8  RSVD25[4];
    volatile Uint32 ARMENDIAN_CFG3_0;
    volatile Uint32 ARMENDIAN_CFG3_1;
    volatile Uint32 ARMENDIAN_CFG3_2;
    volatile Uint8  RSVD26[4];
    volatile Uint32 ARMENDIAN_CFG4_0;
    volatile Uint32 ARMENDIAN_CFG4_1;
    volatile Uint32 ARMENDIAN_CFG4_2;
    volatile Uint8  RSVD27[4];
    volatile Uint32 ARMENDIAN_CFG5_0;
    volatile Uint32 ARMENDIAN_CFG5_1;
    volatile Uint32 ARMENDIAN_CFG5_2;
    volatile Uint8  RSVD28[4];
    volatile Uint32 ARMENDIAN_CFG6_0;
    volatile Uint32 ARMENDIAN_CFG6_1;
    volatile Uint32 ARMENDIAN_CFG6_2;
    volatile Uint8  RSVD29[4];
    volatile Uint32 ARMENDIAN_CFG7_0;
    volatile Uint32 ARMENDIAN_CFG7_1;
    volatile Uint32 ARMENDIAN_CFG7_2;
    volatile Uint8  RSVD30[4];
    volatile Uint32 ARMTBR_TRB0_W0;
    volatile Uint32 ARMTBR_TRB0_W1;
    volatile Uint32 ARMTBR_TRB0_W2;
    volatile Uint32 ARMTBR_TRB0_W3;
    volatile Uint32 ARMTBR_TRB1_W0;
    volatile Uint32 ARMTBR_TRB1_W1;
    volatile Uint32 ARMTBR_TRB1_W2;
    volatile Uint32 ARMTBR_TRB1_W3;
    volatile Uint32 ARMTBR_TRB2_W0;
    volatile Uint32 ARMTBR_TRB2_W1;
    volatile Uint32 ARMTBR_TRB2_W2;
    volatile Uint32 ARMTBR_TRB2_W3;
    volatile Uint8  RSVD31[16];
    volatile Uint32 ARMTBR_SHDW_TRB0_W0;
    volatile Uint32 ARMTBR_SHDW_TRB0_W1;
    volatile Uint32 ARMTBR_SHDW_TRB0_W2;
    volatile Uint32 ARMTBR_SHDW_TRB0_W3;
    volatile Uint32 ARMTBR_SHDW_TRB1_W0;
    volatile Uint32 ARMTBR_SHDW_TRB1_W1;
    volatile Uint32 ARMTBR_SHDW_TRB1_W2;
    volatile Uint32 ARMTBR_SHDW_TRB1_W3;
    volatile Uint32 ARMTBR_SHDW_TRB2_W0;
    volatile Uint32 ARMTBR_SHDW_TRB2_W1;
    volatile Uint32 ARMTBR_SHDW_TRB2_W2;
    volatile Uint32 ARMTBR_SHDW_TRB2_W3;
    volatile Uint8  RSVD32[16];
    volatile Uint32 DBGTBR_TRB0_W0;
    volatile Uint32 DBGTBR_TRB0_W1;
    volatile Uint32 DBGTBR_TRB0_W2;
    volatile Uint32 DBGTBR_TRB0_W3;
    volatile Uint32 DBGTBR_TRB1_W0;
    volatile Uint32 DBGTBR_TRB1_W1;
    volatile Uint32 DBGTBR_TRB1_W2;
    volatile Uint32 DBGTBR_TRB1_W3;
    volatile Uint32 DBGTBR_TRB2_W0;
    volatile Uint32 DBGTBR_TRB2_W1;
    volatile Uint32 DBGTBR_TRB2_W2;
    volatile Uint32 DBGTBR_TRB2_W3;
    volatile Uint8  RSVD33[16];
    volatile Uint32 DBGTBR_SHDW_TRB0_W0;
    volatile Uint32 DBGTBR_SHDW_TRB0_W1;
    volatile Uint32 DBGTBR_SHDW_TRB0_W2;
    volatile Uint32 DBGTBR_SHDW_TRB0_W3;
    volatile Uint32 DBGTBR_SHDW_TRB1_W0;
    volatile Uint32 DBGTBR_SHDW_TRB1_W1;
    volatile Uint32 DBGTBR_SHDW_TRB1_W2;
    volatile Uint32 DBGTBR_SHDW_TRB1_W3;
    volatile Uint32 DBGTBR_SHDW_TRB2_W0;
    volatile Uint32 DBGTBR_SHDW_TRB2_W1;
    volatile Uint32 DBGTBR_SHDW_TRB2_W2;
    volatile Uint32 DBGTBR_SHDW_TRB2_W3;
    volatile Uint8  RSVD34[144];
    volatile Uint32 ARM_RETENTION;
    volatile Uint32 DSP_RETENTION;
    volatile Uint8  RSVD35[72];
    volatile Uint32 SPARE0;
    volatile Uint32 SPARE1;
    volatile Uint32 SPARE2;
    volatile Uint32 SPARE3;
    volatile Uint32 SPARE4;
    volatile Uint32 SPARE5;
    volatile Uint32 SPARE6;
    volatile Uint32 SPARE7;
    volatile Uint32 SPARE8;
    volatile Uint32 SPARE9;
    volatile Uint32 SPARE10;
    volatile Uint32 SPARE11;
    volatile Uint32 SPARE12;
    volatile Uint32 SPARE13;
    volatile Uint32 SPARE14;
    volatile Uint32 SPARE15;
    volatile Uint32 DDR_CLKCTL;
    volatile Uint32 ICSS_CLKCTL;
    volatile Uint32 ETHERNET_CLKCTL;
    volatile Uint32 USB0_CLKCTL;
    volatile Uint32 USB1_CLKCTL;
    volatile Uint32 SERIALPORT_CLKCTL;
    volatile Uint32 OSC_CTL;
    volatile Uint32 PCIE_CLKCTL;
    volatile Uint8  RSVD36[80];
    volatile Uint32 CHIP_MISC_CTL0;
    volatile Uint8  RSVD37[12];
    volatile Uint32 SYSENDSTAT;
    volatile Uint32 PLLLOCK_PINCTL;
    volatile Uint32 PLLLOCK_STAT;
    volatile Uint32 PLLLOCK_EVAL;
    volatile Uint32 PLLCLKSEL_STAT;
    volatile Uint8  RSVD38[20];
    volatile Uint32 USB0_PHY_CTL0;
    volatile Uint32 USB0_PHY_CTL1;
    volatile Uint32 USB0_PHY_CTL2;
    volatile Uint32 USB0_PHY_CTL3;
    volatile Uint32 USB0_PHY_CTL4;
    volatile Uint32 USB0_PHY_CTL5;
    volatile Uint32 USB1_PHY_CTL0;
    volatile Uint32 USB1_PHY_CTL1;
    volatile Uint32 USB1_PHY_CTL2;
    volatile Uint32 USB1_PHY_CTL3;
    volatile Uint32 USB1_PHY_CTL4;
    volatile Uint32 USB1_PHY_CTL5;
    volatile Uint32 USB_EBC_IN_CTL[2];
    volatile Uint8  RSVD39[16];
    volatile Uint32 SCRATCH0;
    volatile Uint32 SCRATCH1;
    volatile Uint32 SCRATCH2;
    volatile Uint32 SCRATCH3;
    volatile Uint32 SCRATCH4;
    volatile Uint32 SCRATCH5;
    volatile Uint32 SCRATCH6;
    volatile Uint32 SCRATCH7;
    volatile Uint32 SCRATCH8;
    volatile Uint32 SCRATCH9;
    volatile Uint32 SCRATCH10;
    volatile Uint32 SCRATCH11;
    volatile Uint32 SCRATCH12;
    volatile Uint32 SCRATCH13;
    volatile Uint32 SCRATCH14;
    volatile Uint32 SCRATCH15;
    volatile Uint8  RSVD40[64];
    volatile Uint32 DSP_SECURE_STAT;
    volatile Uint32 DSP_SECURE_EN0;
    volatile Uint8  RSVD41[60];
    volatile Uint32 DSP_BOOT_ADDR0_NS;
    volatile Uint8  RSVD42[60];
    volatile Uint32 SECURE_CONTROL;
    volatile Uint32 SECURE_SCRATCH0;
    volatile Uint32 SECURE_SCRATCH1;
    volatile Uint32 SECURE_SCRATCH2;
    volatile Uint32 SECURE_SCRATCH3;
    volatile Uint32 SECURE_SCRATCH4;
    volatile Uint32 SECURE_SCRATCH5;
    volatile Uint32 SECURE_SCRATCH6;
    volatile Uint32 SECURE_SCRATCH7;
    volatile Uint8  RSVD43[856];
    volatile Uint32 LED_CORE_PASSDONE0;
    volatile Uint32 LED_CORE_PASSDONE1;
    volatile Uint8  RSVD44[24];
    volatile Uint32 LED_ARM_BOOTADDR;
    volatile Uint8  RSVD45[12];
    volatile Uint32 LED_GPIO_CLR0;
    volatile Uint8  RSVD46[4];
    volatile Uint32 LED_GPIO_SET0;
    volatile Uint8  RSVD47[4];
    volatile Uint32 LED_PLLLOCK0;
    volatile Uint32 LED_PLLLOCK1;
    volatile Uint32 LED_CHIP_PASSDONE;
    volatile Uint8  RSVD48[4];
    volatile Uint32 TDIODE;
    volatile Uint32 MARGIN0;
    volatile Uint32 MARGIN1;
    volatile Uint32 MARGIN2;
    volatile Uint32 EFUSE_SECROM_CHKSUM0;
    volatile Uint32 EFUSE_SECROM_CHKSUM1;
    volatile Uint32 EFUSE_SECROM_CHKSUM2;
    volatile Uint32 EFUSE_SECROM_CHKSUM3;
    volatile Uint32 INT_SPARE0;
    volatile Uint32 INT_SPARE1;
    volatile Uint8  RSVD49[4];
    volatile Uint32 CHIP_MISC_CTL1;
    volatile Uint32 OBSCLKCTL;
    volatile Uint8  RSVD50[8];
    volatile Uint32 EFUSE_RSVD_0;
    volatile Uint32 EFUSE_BOOTROM;
    volatile Uint32 EFUSE_SOFTWARE;
    volatile Uint32 EFUSE_TRIM;
    volatile Uint32 EFUSE_RSVD;
    volatile Uint32 PWRSWTCH_WKUP_MODE0_0;
    volatile Uint32 PWRSWTCH_WKUP_MODE0_1;
    volatile Uint32 PWRSWTCH_WKUP_MODE1_0;
    volatile Uint32 PWRSWTCH_WKUP_MODE1_1;
    volatile Uint32 PWRSWTCH_WKUP_CTL;
    volatile Uint32 DFT_USB0_UTMI_CONTROL;
    volatile Uint8  RSVD51[4];
    volatile Uint32 DFT_USB1_UTMI_CONTROL;
    volatile Uint32 DFT_EHRPWM;
    volatile Uint32 MARGIN3;
    volatile Uint32 IO_CLKLB_CTL;
    volatile Uint8  RSVD52[52];
    volatile Uint32 EVENT_MUXCTL0;
    volatile Uint32 EVENT_MUXCTL1;
    volatile Uint32 EVENT_MUXCTL2;
    volatile Uint32 EVENT_MUXCTL3;
    volatile Uint32 EVENT_MUXCTL4;
    volatile Uint32 EVENT_MUXCTL5;
    volatile Uint32 EVENT_MUXCTL6;
    volatile Uint32 EVENT_MUXCTL7;
    volatile Uint32 EVENT_MUXCTL8;
    volatile Uint32 EVENT_MUXCTL9;
    volatile Uint32 EVENT_MUXCTL10;
    volatile Uint32 EVENT_MUXCTL11;
    volatile Uint32 EVENT_MUXCTL12;
    volatile Uint32 EVENT_MUXCTL13;
    volatile Uint8  RSVD53[216];
    volatile Uint32 DCAN_RAMINIT;
    volatile Uint32 DCAN_RAMINIT_SET;
    volatile Uint8  RSVD54[8];
    volatile Uint32 ETHERNET_CFG;
    volatile Uint8  RSVD55[12];
    volatile Uint32 MLB_SIG_IO_CTL;
    volatile Uint32 MLB_DAT_IO_CTL;
    volatile Uint32 MLB_CLK_BG_CTL;
    volatile Uint8  RSVD56[4];
    volatile Uint32 EPWM_CTL;
    volatile Uint8  RSVD57[12];
    volatile Uint32 ECAP_CAPEVT_CTL;
    volatile Uint8  RSVD58[12];
    volatile Uint32 EQEP_STAT;
    volatile Uint8  RSVD59[12];
    volatile Uint32 LVDS_BG_CTL;
    volatile Uint8  RSVD60[12];
    volatile Uint32 LDO_USB_CTL;
    volatile Uint32 LDO_PCIE_CTL;
    volatile Uint8  RSVD61[8];
    volatile Uint32 BAW_CTL;
    volatile Uint32 BAW_TRIM;
    volatile Uint32 BAW_TS;
    volatile Uint8  RSVD62[356];
    volatile Uint32 PADCONFIG0;
    volatile Uint32 PADCONFIG1;
    volatile Uint32 PADCONFIG2;
    volatile Uint32 PADCONFIG3;
    volatile Uint32 PADCONFIG4;
    volatile Uint32 PADCONFIG5;
    volatile Uint32 PADCONFIG6;
    volatile Uint32 PADCONFIG7;
    volatile Uint32 PADCONFIG8;
    volatile Uint32 PADCONFIG9;
    volatile Uint32 PADCONFIG10;
    volatile Uint32 PADCONFIG11;
    volatile Uint32 PADCONFIG12;
    volatile Uint32 PADCONFIG13;
    volatile Uint32 PADCONFIG14;
    volatile Uint32 PADCONFIG15;
    volatile Uint32 PADCONFIG16;
    volatile Uint32 PADCONFIG17;
    volatile Uint32 PADCONFIG18;
    volatile Uint32 PADCONFIG19;
    volatile Uint32 PADCONFIG20;
    volatile Uint32 PADCONFIG21;
    volatile Uint32 PADCONFIG22;
    volatile Uint32 PADCONFIG23;
    volatile Uint32 PADCONFIG24;
    volatile Uint32 PADCONFIG25;
    volatile Uint32 PADCONFIG26;
    volatile Uint32 PADCONFIG27;
    volatile Uint32 PADCONFIG28;
    volatile Uint32 PADCONFIG29;
    volatile Uint32 PADCONFIG30;
    volatile Uint32 PADCONFIG31;
    volatile Uint32 PADCONFIG32;
    volatile Uint32 PADCONFIG33;
    volatile Uint32 PADCONFIG34;
    volatile Uint32 PADCONFIG35;
    volatile Uint32 PADCONFIG36;
    volatile Uint32 PADCONFIG37;
    volatile Uint32 PADCONFIG38;
    volatile Uint32 PADCONFIG39;
    volatile Uint32 PADCONFIG40;
    volatile Uint32 PADCONFIG41;
    volatile Uint32 PADCONFIG42;
    volatile Uint32 PADCONFIG43;
    volatile Uint32 PADCONFIG44;
    volatile Uint32 PADCONFIG45;
    volatile Uint32 PADCONFIG46;
    volatile Uint32 PADCONFIG47;
    volatile Uint32 PADCONFIG48;
    volatile Uint32 PADCONFIG49;
    volatile Uint32 PADCONFIG50;
    volatile Uint32 PADCONFIG51;
    volatile Uint32 PADCONFIG52;
    volatile Uint32 PADCONFIG53;
    volatile Uint32 PADCONFIG54;
    volatile Uint32 PADCONFIG55;
    volatile Uint32 PADCONFIG56;
    volatile Uint32 PADCONFIG57;
    volatile Uint32 PADCONFIG58;
    volatile Uint32 PADCONFIG59;
    volatile Uint32 PADCONFIG60;
    volatile Uint32 PADCONFIG61;
    volatile Uint32 PADCONFIG62;
    volatile Uint32 PADCONFIG63;
    volatile Uint32 PADCONFIG64;
    volatile Uint32 PADCONFIG65;
    volatile Uint32 PADCONFIG66;
    volatile Uint32 PADCONFIG67;
    volatile Uint32 PADCONFIG68;
    volatile Uint32 PADCONFIG69;
    volatile Uint32 PADCONFIG70;
    volatile Uint32 PADCONFIG71;
    volatile Uint32 PADCONFIG72;
    volatile Uint32 PADCONFIG73;
    volatile Uint32 PADCONFIG74;
    volatile Uint32 PADCONFIG75;
    volatile Uint32 PADCONFIG76;
    volatile Uint32 PADCONFIG77;
    volatile Uint32 PADCONFIG78;
    volatile Uint32 PADCONFIG79;
    volatile Uint32 PADCONFIG80;
    volatile Uint32 PADCONFIG81;
    volatile Uint32 PADCONFIG82;
    volatile Uint32 PADCONFIG83;
    volatile Uint32 PADCONFIG84;
    volatile Uint32 PADCONFIG85;
    volatile Uint32 PADCONFIG86;
    volatile Uint32 PADCONFIG87;
    volatile Uint32 PADCONFIG88;
    volatile Uint32 PADCONFIG89;
    volatile Uint32 PADCONFIG90;
    volatile Uint32 PADCONFIG91;
    volatile Uint32 PADCONFIG92;
    volatile Uint32 PADCONFIG93;
    volatile Uint32 PADCONFIG94;
    volatile Uint32 PADCONFIG95;
    volatile Uint32 PADCONFIG96;
    volatile Uint32 PADCONFIG97;
    volatile Uint32 PADCONFIG98;
    volatile Uint32 PADCONFIG99;
    volatile Uint32 PADCONFIG100;
    volatile Uint32 PADCONFIG101;
    volatile Uint32 PADCONFIG102;
    volatile Uint32 PADCONFIG103;
    volatile Uint32 PADCONFIG104;
    volatile Uint32 PADCONFIG105;
    volatile Uint32 PADCONFIG106;
    volatile Uint32 PADCONFIG107;
    volatile Uint32 PADCONFIG108;
    volatile Uint32 PADCONFIG109;
    volatile Uint32 PADCONFIG110;
    volatile Uint32 PADCONFIG111;
    volatile Uint32 PADCONFIG112;
    volatile Uint32 PADCONFIG113;
    volatile Uint32 PADCONFIG114;
    volatile Uint32 PADCONFIG115;
    volatile Uint32 PADCONFIG116;
    volatile Uint32 PADCONFIG117;
    volatile Uint32 PADCONFIG118;
    volatile Uint32 PADCONFIG119;
    volatile Uint32 PADCONFIG120;
    volatile Uint32 PADCONFIG121;
    volatile Uint32 PADCONFIG122;
    volatile Uint32 PADCONFIG123;
    volatile Uint32 PADCONFIG124;
    volatile Uint32 PADCONFIG125;
    volatile Uint32 PADCONFIG126;
    volatile Uint32 PADCONFIG127;
    volatile Uint32 PADCONFIG128;
    volatile Uint32 PADCONFIG129;
    volatile Uint32 PADCONFIG130;
    volatile Uint32 PADCONFIG131;
    volatile Uint32 PADCONFIG132;
    volatile Uint32 PADCONFIG133;
    volatile Uint32 PADCONFIG134;
    volatile Uint32 PADCONFIG135;
    volatile Uint32 PADCONFIG136;
    volatile Uint32 PADCONFIG137;
    volatile Uint32 PADCONFIG138;
    volatile Uint32 PADCONFIG139;
    volatile Uint32 PADCONFIG140;
    volatile Uint32 PADCONFIG141;
    volatile Uint32 PADCONFIG142;
    volatile Uint32 PADCONFIG143;
    volatile Uint32 PADCONFIG144;
    volatile Uint32 PADCONFIG145;
    volatile Uint32 PADCONFIG146;
    volatile Uint32 PADCONFIG147;
    volatile Uint32 PADCONFIG148;
    volatile Uint32 PADCONFIG149;
    volatile Uint32 PADCONFIG150;
    volatile Uint32 PADCONFIG151;
    volatile Uint32 PADCONFIG152;
    volatile Uint32 PADCONFIG153;
    volatile Uint32 PADCONFIG154;
    volatile Uint32 PADCONFIG155;
    volatile Uint32 PADCONFIG156;
    volatile Uint32 PADCONFIG157;
    volatile Uint32 PADCONFIG158;
    volatile Uint32 PADCONFIG159;
    volatile Uint32 PADCONFIG160;
    volatile Uint32 PADCONFIG161;
    volatile Uint32 PADCONFIG162;
    volatile Uint32 PADCONFIG163;
    volatile Uint32 PADCONFIG164;
    volatile Uint32 PADCONFIG165;
    volatile Uint32 PADCONFIG166;
    volatile Uint32 PADCONFIG167;
    volatile Uint32 PADCONFIG168;
    volatile Uint32 PADCONFIG169;
    volatile Uint32 PADCONFIG170;
    volatile Uint32 PADCONFIG171;
    volatile Uint32 PADCONFIG172;
    volatile Uint32 PADCONFIG173;
    volatile Uint32 PADCONFIG174;
    volatile Uint32 PADCONFIG175;
    volatile Uint32 PADCONFIG176;
    volatile Uint32 PADCONFIG177;
    volatile Uint32 PADCONFIG178;
    volatile Uint32 PADCONFIG179;
    volatile Uint32 PADCONFIG180;
    volatile Uint32 PADCONFIG181;
    volatile Uint32 PADCONFIG182;
    volatile Uint32 PADCONFIG183;
    volatile Uint32 PADCONFIG184;
    volatile Uint32 PADCONFIG185;
    volatile Uint32 PADCONFIG186;
    volatile Uint32 PADCONFIG187;
    volatile Uint32 PADCONFIG188;
    volatile Uint32 PADCONFIG189;
    volatile Uint32 PADCONFIG190;
    volatile Uint32 PADCONFIG191;
    volatile Uint32 PADCONFIG192;
    volatile Uint32 PADCONFIG193;
    volatile Uint32 PADCONFIG194;
    volatile Uint32 PADCONFIG195;
    volatile Uint32 PADCONFIG196;
    volatile Uint32 PADCONFIG197;
    volatile Uint32 PADCONFIG198;
    volatile Uint32 PADCONFIG199;
    volatile Uint32 PADCONFIG200;
    volatile Uint32 PADCONFIG201;
    volatile Uint32 PADCONFIG202;
    volatile Uint32 PADCONFIG203;
    volatile Uint32 PADCONFIG204;
    volatile Uint32 PADCONFIG205;
    volatile Uint32 PADCONFIG206;
    volatile Uint32 PADCONFIG207;
    volatile Uint32 PADCONFIG208;
    volatile Uint32 PADCONFIG209;
    volatile Uint32 PADCONFIG210;
    volatile Uint32 PADCONFIG211;
    volatile Uint32 PADCONFIG212;
    volatile Uint32 PADCONFIG213;
    volatile Uint32 PADCONFIG214;
    volatile Uint32 PADCONFIG215;
    volatile Uint32 PADCONFIG216;
    volatile Uint32 PADCONFIG217;
    volatile Uint32 PADCONFIG218;
    volatile Uint32 PADCONFIG219;
    volatile Uint32 PADCONFIG220;
    volatile Uint32 PADCONFIG221;
    volatile Uint32 PADCONFIG222;
    volatile Uint32 PADCONFIG223;
    volatile Uint32 PADCONFIG224;
    volatile Uint32 PADCONFIG225;
    volatile Uint32 PADCONFIG226;
    volatile Uint32 PADCONFIG227;
    volatile Uint32 PADCONFIG228;
    volatile Uint32 PADCONFIG229;
    volatile Uint32 PADCONFIG230;
    volatile Uint32 PADCONFIG231;
    volatile Uint32 PADCONFIG232;
    volatile Uint32 PADCONFIG233;
    volatile Uint32 PADCONFIG234;
    volatile Uint32 PADCONFIG235;
    volatile Uint32 PADCONFIG236;
    volatile Uint32 PADCONFIG237;
    volatile Uint32 PADCONFIG238;
    volatile Uint32 PADCONFIG239;
    volatile Uint32 PADCONFIG240;
    volatile Uint32 PADCONFIG241;
    volatile Uint32 PADCONFIG242;
    volatile Uint32 PADCONFIG243;
    volatile Uint32 PADCONFIG244;
    volatile Uint32 PADCONFIG245;
    volatile Uint32 PADCONFIG246;
    volatile Uint32 PADCONFIG247;
    volatile Uint32 PADCONFIG248;
    volatile Uint32 PADCONFIG249;
    volatile Uint32 PADCONFIG250;
    volatile Uint32 PADCONFIG251;
    volatile Uint32 PADCONFIG252;
    volatile Uint32 PADCONFIG253;
    volatile Uint32 PADCONFIG254;
    volatile Uint32 PADCONFIG255;
    volatile Uint32 PADCONFIG256;
    volatile Uint32 PADCONFIG257;
    volatile Uint32 PADCONFIG258;
    volatile Uint32 PADCONFIG259;
    volatile Uint8  RSVD63[12];
} CSL_BootcfgRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* BOOTCFG Revision ID register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_REVISION                            (0x0U)

/* DIE ID Register */
#define CSL_BOOTCFG_DIEID(i)                                    (0x8U + ((i) * (0x4U)))

/* The JTAGID register must be readable by the configuration bus so that this 
 * can be accessed via the JTAG and CPU. In Boundary Scan mode, this ID should 
 * also be readable with only TCLK present. This means without a valid CPU 
 * clock running and also implies that Fusefarm scan is not necessary. This ID 
 * value will be located at the chip level. The Variant field should be set in 
 * the top metal mask so that this may be changed if a future PG is necessary. 
 * All other fields may be hard coded. */
#define CSL_BOOTCFG_JTAGID                                      (0x18U)

/* Indicates device bootstrap selection upon a power-on reset by PORz or 
 * RESETFULLz. The default value of this register is determined by the 
 * bootstrap pins. Once set, these bits remain set until a power-on reset. */
#define CSL_BOOTCFG_DEVSTAT                                     (0x20U)

/* "The Bootcfg module contains a kicker mechanism to prevent spurious writes 
 * from changing any of the Bootcfg MMR values. When the kicker is locked 
 * (which it is initially after power-on reset), none of the Bootcfg MMRs are 
 * writable (they are only readable). This mechanism requires an MMR write to 
 * each of the KICK0 and KICK1 registers with exact data values before the 
 * kicker lock mechanism is unlocked. Once released, all the Bootcfg MMRs 
 * having write permissions are writable (the read only MMRs are still read 
 * only). The KICK0 data is 0x83e70b13. The KICK1 data is 0x95a4f1e0. Writing 
 * any other data value to either of these kick MMRs locks the kicker 
 * mechanism and blocks writes to Bootcfg MMRs. To ensure protection to all 
 * Bootcfg MMRs, software must always re-lock the kicker mechanism after 
 * completing the MMR writes." */
#define CSL_BOOTCFG_KICK0                                       (0x38U)

/* Bootcfg KICK1 lock register */
#define CSL_BOOTCFG_KICK1                                       (0x3CU)

/* Boot address register for C66x core. Bit 0 of this register is a don't care 
 * and must be masked by software. */
#define CSL_BOOTCFG_DSP_BOOT_ADDR0                              (0x40U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_INTR_RAW_STAT_SET                   (0xE0U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_INTR_ENABLED_STAT_CLR               (0xE4U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_INTR_ENABLE                         (0xE8U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_INTR_ENABLE_CLR                     (0xECU)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_EOI                                 (0xF0U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_FAULT_ADDR                          (0xF4U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_FAULT_STAT                          (0xF8U)

/* Bootcfg internal built-in register. Refer to IP spec for register details. */
#define CSL_BOOTCFG_BOOTCFG_FAULT_CLR                           (0xFCU)

/* "Each individual device has a 48-bit MAC address and consumes only one 
 * unique MAC address out of the range. There are two registers to hold these 
 * values, MACI_D0[31:0] (32 bits) and MAC_ID1[15:0] (16 bits)." */
#define CSL_BOOTCFG_MACID0                                      (0x110U)

/* "Each individual device has a 48-bit MAC address and consumes only one 
 * unique MAC address out of the range. There are two registers to hold these 
 * values, MAC_ID0[31:0] (32 bits) and MAC_ID1[15:0] (16 bits)." */
#define CSL_BOOTCFG_MACID1                                      (0x114U)

/* PCIe device ID and vendor ID register */
#define CSL_BOOTCFG_PCIEVENDORID                                (0x128U)

/* Indicates the status of IPs that are permanently disabled via EFUSE for 
 * paper spins (0 = IP present, 1 = IP permanently disabled) */
#define CSL_BOOTCFG_DISABLESTAT                                 (0x12CU)

/* Local reset and NMI pin status clear register for C66x core(s). The 
 * LRSTNMISTAT bits can be cleared by writing 1 to the corresponding bit in 
 * the LRSTNMISTAT_CLR register. */
#define CSL_BOOTCFG_LRSTNMISTAT_CLR                             (0x130U)

/* The RESET_STAT bits can be cleared by writing 1 to the corresponding bit in 
 * the RESET_STAT_CLR register. */
#define CSL_BOOTCFG_RESET_STAT_CLR                              (0x134U)

/* "Register to control BOOTCOMPLETE pin status to indicate completion of the 
 * ROM booting process. The BCx bit indicates the boot complete status of the 
 * corresponding C66x or ARM cores. All BCx bits are sticky bits - that is, 
 * they can be set only once by the software after device reset and they will 
 * be cleared to 0 on all device resets. Boot ROM code is implemented such 
 * that each C66x and ARM cores sets its corresponding BCx bit immediately 
 * before branching to the predefined location in memory. When all the BCx 
 * bits are set to 1, the BOOTCOMPLETE pin status will be high indicating that 
 * device ROM booting process is complete. Design Note: In order to support 
 * future device derivatives with either DSP or ARM core permanently disabled, 
 * each of the BCx inputs should be Efuse-able. For example on a device 
 * derivative with only ARM core, the boot complete bit corresponding to DSP 
 * core must be set to 1 by EFUSE. This can be implemented by deriving the BCx 
 * value based on the permanent disable efuse bit of the corresponding core." */
#define CSL_BOOTCFG_BOOTCOMPLETE                                (0x13CU)

/* Marker register used by Boot ROM code to indicate internal boot progress */
#define CSL_BOOTCFG_BOOTPROGRESS                                (0x140U)

/* "The Reset Status Register captures the status of local reset (LRx) for 
 * each of the C66x cores and also the global device reset (GR). Software can 
 * use this information to take different device initialization steps. - In 
 * case of local reset: The LRx bits are written as 1 and the GR bit is 
 * written as 0 only when the C66x core receives a local reset without 
 * receiving a global reset. - In case of global reset: The LRx bits are 
 * written as 0 and the GR bit is written as 1 only when a global reset is 
 * asserted." */
#define CSL_BOOTCFG_RESET_STAT                                  (0x144U)

/* Local reset and NMI pin status register for C66x core(s). LRSTNMISTAT is 
 * used to latch the status of LRESETz and NMIz based on LRESETNMIENz pin. The 
 * pin status is latched on the rising edge of LRESETNMIENz. Note that LRESETz 
 * and NMIz are available only for the C66x core(s) and not the ARM core(s). */
#define CSL_BOOTCFG_LRSTNMISTAT                                 (0x148U)

/* Device configuration register */
#define CSL_BOOTCFG_DEVCFG                                      (0x14CU)

/* Register is controlled by the software to indicate the device power-saving 
 * mode. The Boot ROM code reads this register to differentiate between the 
 * various device power saving modes. This register is only accessible by 
 * secure master or secure guest on a secure device, emulation access is not 
 * allowed. */
#define CSL_BOOTCFG_PWR_STATE                                   (0x150U)

/* This register configures the trasaction priority of the initiator (master 
 * port) to control arbitration within the interconnect. Valid settings are 
 * 0x7 (lowest priority) to 0x0 (urgent priority) for each bitfield. */
#define CSL_BOOTCFG_INITIATOR_PRIORITY0                         (0x154U)

/* This register configures the trasaction priority of the initiator (master 
 * port) to control arbitration within the interconnect. Valid settings are 
 * 0x7 (lowest priority) to 0x0 (urgent priority) for each bitfield. */
#define CSL_BOOTCFG_INITIATOR_PRIORITY1                         (0x158U)

/* SmartReflex Class0 Register */
#define CSL_BOOTCFG_SR0_CLASS0                                  (0x180U)

/* SmartReflex Class0 OPP0 Register */
#define CSL_BOOTCFG_SR0_OPP0_SEN(i)                             (0x190U + ((i) * (0x4U)))

/* SmartReflex Class0 OPP1 Register */
#define CSL_BOOTCFG_SR0_OPP1_SEN(i)                             (0x1A0U + ((i) * (0x4U)))

/* SmartReflex Class0 OPP2 Register */
#define CSL_BOOTCFG_SR0_OPP2_SEN(i)                             (0x1B0U + ((i) * (0x4U)))

/* SmartReflex Class0 OPP3 Register */
#define CSL_BOOTCFG_SR0_OPP3_SEN(i)                             (0x1C0U + ((i) * (0x4U)))

/* NMIGR register generates NMI event to C66x core. Writing a 1 to the NMIG 
 * field generates an NMI pulse. Writing a 0 has no effect and reads return 0 
 * and have no other effect. */
#define CSL_BOOTCFG_NMIGR0                                      (0x200U)

/* Register facilitate inter-core interrupt to C66x core 0. A write of 1 to 
 * the IPCG field of the IPCGR0 register generatesan interrupt pulse to C66x 
 * core 0. The register also provide a Source ID facility identifying up to 28 
 * different sourcesof interrupt. Allocation of source bits to source 
 * processor and meaning is entirely based on software convention. Therecan be 
 * numerous sources for the register as this is completely controlled by 
 * software. Any master that has access toBOOTCFG module space can write to 
 * this register. Register is KICK un-locked, that means software need not 
 * gothrough KICK sequence in order to write to this register. */
#define CSL_BOOTCFG_IPCGR0                                      (0x240U)

/* Register facilitate inter-core interrupt to A15 core 0. A write of 1 to the 
 * IPCG field of the IPCGR8 register generatesan interrupt pulse to the 
 * corresponding core. The register also provide a Source ID facility 
 * identifying up to 28different sources of interrupt. Allocation of source 
 * bits to source processor and meaning is entirely based on 
 * softwareconvention. There can be numerous sources for the register as this 
 * is completely controlled by software. Any masterthat has access to BOOTCFG 
 * module space can write to this register. Register is KICK un-locked, that 
 * means software need not go through KICK sequence in order to write to this 
 * register. */
#define CSL_BOOTCFG_IPCGR8                                      (0x260U)

/* Register facilitate inter-core interrupt to ICSS0 PRU {<11:12>-11}. A write 
 * of 1 to the IPCG field of theIPCGR<11:12> register generates an interrupt 
 * pulse to the corresponding core. The register also provide a Source 
 * IDfacility identifying up to 28 different sources of interrupt. Allocation 
 * of source bits to source processor and meaning isentirely based on software 
 * convention. There can be numerous sources for the register as this is 
 * completely controlledby software. Any master that has access to BOOTCFG 
 * module space can write to this register. Register is KICK un-locked, that 
 * means software need not go through KICK sequence in order to write to this 
 * register. */
#define CSL_BOOTCFG_IPCGR11_12(i)                               (0x26CU + ((i) * (0x4U)))

/* Register facilitate inter-core interrupt to ICSS1 PRU {<13:14>-13}. A write 
 * of 1 to the IPCG field of theIPCGR<13:14> register generates an interrupt 
 * pulse to the corresponding core. The register also provide a Source 
 * IDfacility identifying up to 28 different sources of interrupt. Allocation 
 * of source bits to source processor and meaning isentirely based on software 
 * convention. There can be numerous sources for the register as this is 
 * completely controlledby software. Any master that has access to BOOTCFG 
 * module space can write to this register. Register is KICK un-locked, that 
 * means software need not go through KICK sequence in order to write to this 
 * register. */
#define CSL_BOOTCFG_IPCGR13_14(i)                               (0x274U + ((i) * (0x4U)))

/* Register facilitate interrupt to external host. Operation and use of the 
 * IPCGRH register is the same as for other IPCGRregisters. The interrupt 
 * output pulse created by the IPCGRH register appears on device pin HOUT. The 
 * host interruptoutput pulse is stretched so that it is asserted for four 
 * bootcfg clock cycles (CLK/6) followed by a deassertion of fourbootcfg clock 
 * cycles. Generating the pulse results in a pulse-blocking window that is 
 * eight CLK/6-cycles long. Back-to-back writes to the IPCRGH register with 
 * the IPCG bit (bit 0) set, generates only one pulse if the 
 * back-to-backwrites to IPCGRH are less than the eight CLK/6 cycle window - 
 * the pulse blocking window. To generate back-to-backpulses, the back-to-back 
 * writes to the IPCGRH register must be written after the eight CLK/6 cycle 
 * pulse-blockingwindow has elapsed. Register is KICK un-locked, that means 
 * software need not go through KICK sequence in order towrite to this 
 * register. */
#define CSL_BOOTCFG_IPCGRH                                      (0x27CU)

/* Register facilitate inter-core interrupt acknowledgement for C66x core 0. 
 * The register also provide a Source ID facilityby which up to 28 different 
 * sources of interrupt can be identified. Allocation of source bits to source 
 * processor andmeaning is entirely based on software convention. Virtually 
 * anything can be a source for the register as this iscompletely controlled 
 * by software. Any master that has access to BOOTCFG module space can write 
 * to this register.Register is KICK un-locked, that means software need not 
 * go through KICK sequence in order to write to this register. */
#define CSL_BOOTCFG_IPCAR0                                      (0x280U)

/* Reads return current value of internal register bit Writes: 0 - No effect 1 
 * - Clears both SRC_CLRx and the corresponding SRCxbit in IPCGR8 register */
#define CSL_BOOTCFG_IPCAR8                                      (0x2A0U)

/* Register facilitate inter-core interrupt acknowledgement for ICSS0 PRU 
 * {<11:12>-11}. The register also provide aSource ID facility by which up to 
 * 28 different sources of interrupt can be identified. Allocation of source 
 * bits to sourceprocessor and meaning is entirely based on software 
 * convention. Virtually anything can be a source for the register asthis is 
 * completely controlled by software. Any master that has access to BOOTCFG 
 * module space can write to thisregister. Register is KICK un-locked, that 
 * means software need not go through KICK sequence in order to write to 
 * thisregister. */
#define CSL_BOOTCFG_IPCAR11_12(i)                               (0x2ACU + ((i) * (0x4U)))

/* Register facilitate inter-core interrupt acknowledgement for ICSS1 PRU 
 * {<13:14>-13}. The register also provide aSource ID facility by which up to 
 * 28 different sources of interrupt can be identified. Allocation of source 
 * bits to sourceprocessor and meaning is entirely based on software 
 * convention. Virtually anything can be a source for the register asthis is 
 * completely controlled by software. Any master that has access to BOOTCFG 
 * module space can write to thisregister. Register is KICK un-locked, that 
 * means software need not go through KICK sequence in order to write to 
 * thisregister. */
#define CSL_BOOTCFG_IPCAR13_14(i)                               (0x2B4U + ((i) * (0x4U)))

/* Register facilitate interrupt acknowledgement to external host. Operation 
 * and use of the IPCARH register is the sameas for other IPCAR registers. 
 * Register is KICK un-locked, that means software need not go through KICK 
 * sequence inorder to write to this register. */
#define CSL_BOOTCFG_IPCARH                                      (0x2BCU)

/* Register selects timer pin inputs for Timer 0 to 3 */
#define CSL_BOOTCFG_TINPSEL0                                    (0x2D8U)

/* Register selects timer pin inputs for Timer 4 to 7 */
#define CSL_BOOTCFG_TINPSEL1                                    (0x2DCU)

/* Register to select timer pin outputs */
#define CSL_BOOTCFG_TOUTPSEL0                                   (0x2F8U)

/* Reset multiplex register controls the WDT (Watchdog Timer) timeout event 
 * actions for C66x core 0 */
#define CSL_BOOTCFG_RSTMUX0                                     (0x308U)

/* Reset multiplex register controls the WDT (Watchdog Timer) timeout event 
 * actions for A15 core 0 */
#define CSL_BOOTCFG_RSTMUX8                                     (0x328U)

/* Register to control Main PLL */
#define CSL_BOOTCFG_MAIN_PLL_CTL0                               (0x350U)

/* Register to control Main PLL */
#define CSL_BOOTCFG_MAIN_PLL_CTL1                               (0x354U)

/* Register to control NSS PLL */
#define CSL_BOOTCFG_NSS_PLL_CTL0                                (0x358U)

/* Register to control NSS PLL */
#define CSL_BOOTCFG_NSS_PLL_CTL1                                (0x35CU)

/* Register to control DDR3A PLL */
#define CSL_BOOTCFG_DDR3A_PLL_CTL0                              (0x360U)

/* Register to control DDR3A PLL */
#define CSL_BOOTCFG_DDR3A_PLL_CTL1                              (0x364U)

/* Register to control ARM PLL */
#define CSL_BOOTCFG_ARM_PLL_CTL0                                (0x370U)

/* Register to control ARM PLL */
#define CSL_BOOTCFG_ARM_PLL_CTL1                                (0x374U)

/* Register to control DSS PLL */
#define CSL_BOOTCFG_DSS_PLL_CTL0                                (0x380U)

/* Register to control DSS PLL */
#define CSL_BOOTCFG_DSS_PLL_CTL1                                (0x384U)

/* Register to control ICSS PLL */
#define CSL_BOOTCFG_ICSS_PLL_CTL0                               (0x388U)

/* Register to control ICSS PLL */
#define CSL_BOOTCFG_ICSS_PLL_CTL1                               (0x38CU)

/* Register to control UART PLL */
#define CSL_BOOTCFG_UART_PLL_CTL0                               (0x390U)

/* Register to control UART PLL */
#define CSL_BOOTCFG_UART_PLL_CTL1                               (0x394U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 0 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG0_0                            (0x400U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 0 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG0_1                            (0x404U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 0 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG0_2                            (0x408U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 1 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG1_0                            (0x410U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 1 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG1_1                            (0x414U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 1 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG1_2                            (0x418U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 2 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG2_0                            (0x420U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 2 shows up in the A15 processor registers. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG2_1                            (0x424U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 2 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG2_2                            (0x428U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 3 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG3_0                            (0x430U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 3 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG3_1                            (0x434U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 3 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG3_2                            (0x438U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 4 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG4_0                            (0x440U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 4 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG4_1                            (0x444U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 4 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG4_2                            (0x448U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 5 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG5_0                            (0x450U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 5 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG5_1                            (0x454U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 5 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG5_2                            (0x458U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 6 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG6_0                            (0x460U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 6 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG6_1                            (0x464U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 6 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG6_2                            (0x468U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 7 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG7_0                            (0x470U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 7 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG7_1                            (0x474U)

/* These registers control the way A15 core access to peripheral MMRs in 
 * region 7 shows up in the A15 processorregisters. The purpose is to provide 
 * an endian-invariant view of the peripheral MMRs when performing a 
 * 32-bitaccess. */
#define CSL_BOOTCFG_ARMENDIAN_CFG7_2                            (0x478U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the ARM trace buffer. */
#define CSL_BOOTCFG_ARMTBR_TRB0_W0                              (0x480U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the ARM trace buffer. */
#define CSL_BOOTCFG_ARMTBR_TRB0_W1                              (0x484U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the ARM trace buffer. */
#define CSL_BOOTCFG_ARMTBR_TRB0_W2                              (0x488U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the ARM trace buffer. */
#define CSL_BOOTCFG_ARMTBR_TRB0_W3                              (0x48CU)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB1_W0                              (0x490U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB1_W1                              (0x494U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB1_W2                              (0x498U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB1_W3                              (0x49CU)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB2_W0                              (0x4A0U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB2_W1                              (0x4A4U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB2_W2                              (0x4A8U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_ARMTBR_TRB2_W3                              (0x4ACU)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asARMTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W0                         (0x4C0U)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asARMTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W1                         (0x4C4U)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asARMTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W2                         (0x4C8U)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asARMTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W3                         (0x4CCU)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asARMTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W0                         (0x4D0U)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asARMTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor. These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W1                         (0x4D4U)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asARMTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W2                         (0x4D8U)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asARMTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W3                         (0x4DCU)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asARMTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W0                         (0x4E0U)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asARMTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W1                         (0x4E4U)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asARMTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W2                         (0x4E8U)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asARMTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W3                         (0x4ECU)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the Debug Subsystem trace buffer. */
#define CSL_BOOTCFG_DBGTBR_TRB0_W0                              (0x500U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the Debug Subsystem trace buffer. */
#define CSL_BOOTCFG_DBGTBR_TRB0_W1                              (0x504U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the Debug Subsystem trace buffer. */
#define CSL_BOOTCFG_DBGTBR_TRB0_W2                              (0x508U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 0 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. There are three TRBs (0..2) used for 
 * continuously draining the Debug Subsystem trace buffer. */
#define CSL_BOOTCFG_DBGTBR_TRB0_W3                              (0x50CU)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB1_W0                              (0x510U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, as per xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB1_W1                              (0x514U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB1_W2                              (0x518U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 1 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB1_W3                              (0x51CU)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB2_W0                              (0x520U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB2_W1                              (0x524U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB2_W2                              (0x528U)

/* These registers holds the software writable copy of USB xHCI Transfer 
 * Request Block (TRB) 2 for a trace buffer.Each TRB consists of 4 consecutive 
 * 32-bit words (0..3) defining the buffer address, buffer size and other 
 * control, asper xHCI definition. */
#define CSL_BOOTCFG_DBGTBR_TRB2_W3                              (0x52CU)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asDBGTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W0                         (0x540U)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asDBGTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W1                         (0x544U)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asDBGTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W2                         (0x548U)

/* These are shadow registers for Transfer Request Block (TRB) 0 and shall 
 * reflect the same value asDBGTBR_TRB0_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W3                         (0x54CU)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asDBGTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W0                         (0x550U)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asDBGTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W1                         (0x554U)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asDBGTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W2                         (0x558U)

/* These are shadow registers for Transfer Request Block (TRB) 1 and shall 
 * reflect the same value asDBGTBR_TRB1_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W3                         (0x55CU)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asDBGTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W0                         (0x560U)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asDBGTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W1                         (0x564U)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asDBGTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W2                         (0x568U)

/* These are shadow registers for Transfer Request Block (TRB) 2 and shall 
 * reflect the same value asDBGTBR_TRB2_W[3:0] registers. These registers per 
 * trace buffer holds the USB readable versions of the descriptor.These 
 * registers are expected to be written by the USB module, but writes to these 
 * registers shall be ignored silently,without returning any error in the 
 * config bus. The purpose of the shadow registers are to enable USB module to 
 * usethese descriptors continuously without requiring software intervention 
 * to re-initialize the Transfer Request Blocks(TRB). */
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W3                         (0x56CU)

/* Register to control A15 memory retention mode (vdd drooping) */
#define CSL_BOOTCFG_ARM_RETENTION                               (0x600U)

/* Register to control DSP memory retention mode (vdd drooping) */
#define CSL_BOOTCFG_DSP_RETENTION                               (0x604U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE0                                      (0x650U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE1                                      (0x654U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE2                                      (0x658U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE3                                      (0x65CU)

/* Spare Register */
#define CSL_BOOTCFG_SPARE4                                      (0x660U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE5                                      (0x664U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE6                                      (0x668U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE7                                      (0x66CU)

/* Spare Register */
#define CSL_BOOTCFG_SPARE8                                      (0x670U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE9                                      (0x674U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE10                                     (0x678U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE11                                     (0x67CU)

/* Spare Register */
#define CSL_BOOTCFG_SPARE12                                     (0x680U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE13                                     (0x684U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE14                                     (0x688U)

/* Spare Register */
#define CSL_BOOTCFG_SPARE15                                     (0x68CU)

/* DDR PLL Clock Mux Control Register */
#define CSL_BOOTCFG_DDR_CLKCTL                                  (0x690U)

/* ICSS Clock Control Register */
#define CSL_BOOTCFG_ICSS_CLKCTL                                 (0x694U)

/* Ethernet Clock Control Register */
#define CSL_BOOTCFG_ETHERNET_CLKCTL                             (0x698U)

/* USB0 Clock Control Register */
#define CSL_BOOTCFG_USB0_CLKCTL                                 (0x69CU)

/* USB1 Clock Control Register */
#define CSL_BOOTCFG_USB1_CLKCTL                                 (0x6A0U)

/* Serial Port Clock Control Register */
#define CSL_BOOTCFG_SERIALPORT_CLKCTL                           (0x6A4U)

/* Controls the Internal System Oscillator and Audio Oscillator */
#define CSL_BOOTCFG_OSC_CTL                                     (0x6A8U)

/* PCIE Clock Control Register */
#define CSL_BOOTCFG_PCIE_CLKCTL                                 (0x6ACU)

/* Chip Miscellaneous Control Register 0 */
#define CSL_BOOTCFG_CHIP_MISC_CTL0                              (0x700U)

/* This register provides a way for reading the system endianness in an 
 * endian-neutral way from A15 core. TheSYSENDSTAT register captures the 
 * LENDIAN bootmode pin and is used by the BOOTROM to guide the bootflow.The 
 * value is latched on the rising edge of PORz or RESETFULLz */
#define CSL_BOOTCFG_SYSENDSTAT                                  (0x710U)

/* This register controls the PLLLOCK mux and selects which PLL Lock signal is 
 * routed to the PLLLOCK device pin.Only one PLL signal should be selected at 
 * any time. */
#define CSL_BOOTCFG_PLLLOCK_PINCTL                              (0x714U)

/* This register holds the current status of the PLL Lock bit when 
 * PLLLOCK_EVAL bit is set and further captures loss ofLOCK in a sticky 
 * fashion. Note that the PLL being in its initial unlocked state is also a 
 * sticky state and therefore,software has to reevaluate the state using 
 * PLLLOCK_EVAL after initial PLL configuration and lock. */
#define CSL_BOOTCFG_PLLLOCK_STAT                                (0x718U)

/* This register is used to evaluate the PLL Lock signal from the 
 * corresponding on-chip PLL and capture the status in thePLLLOCK_STAT 
 * register. Usage note on PLLLOCK_EVAL and PLLLOCK_STAT Registers: - 
 * PLLLOCK_STAT captures the loss of PLL lock status in a sticky fashion. 
 * Further PLLLOCK_STAT will hold thecurrent status of the PLL lock when the 
 * corresponding EVAL bit is set. - Once the PLL is programmed, software is 
 * expected to set the EVAL bit to get the current status of the PLL lock. In 
 * anormal operation all STAT bits will show the status as '1' indicating the 
 * PLL is locked. Then software can examine theSTAT register at a later time 
 * to detect the loss of lock, because the corresponding status bit will be 
 * cleared to '0' in asticky fashion. If any lock is lost, software can use 
 * EVAL register to re-evaluate the status at any time. */
#define CSL_BOOTCFG_PLLLOCK_EVAL                                (0x71CU)

/* This register is used to read the status of the PLL input clock selection 
 * pins */
#define CSL_BOOTCFG_PLLCLKSEL_STAT                              (0x720U)

/* USB 0 PHY Control Register 0 */
#define CSL_BOOTCFG_USB0_PHY_CTL0                               (0x738U)

/* USB 0 PHY Control Register 1 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB0_PHY_CTL1                               (0x73CU)

/* USB 0 PHY Control Register 2 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB0_PHY_CTL2                               (0x740U)

/* USB 0 PHY Control Register 3 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB0_PHY_CTL3                               (0x744U)

/* USB 0 PHY Control Register 4 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB0_PHY_CTL4                               (0x748U)

/* USB 0 PHY Control Register 5 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB0_PHY_CTL5                               (0x74CU)

/* USB1 PHY Control Register 0 */
#define CSL_BOOTCFG_USB1_PHY_CTL0                               (0x750U)

/* USB 1 PHY Control Register 1 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB1_PHY_CTL1                               (0x754U)

/* USB 1 PHY Control Register 2 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB1_PHY_CTL2                               (0x758U)

/* USB 1 PHY Control Register 3 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB1_PHY_CTL3                               (0x75CU)

/* USB 1 PHY Control Register 4 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB1_PHY_CTL4                               (0x760U)

/* USB 1 PHY Control Register 5 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_USB1_PHY_CTL5                               (0x764U)

/* This register controls the routing of Trace Buffer's (TBR) DMA event called 
 * DAVDMA_TOP_INTR_PEND to the USB module's EBC (External Buffer Control) 
 * signal */
#define CSL_BOOTCFG_USB_EBC_IN_CTL(i)                           (0x768U + ((i) * (0x4U)))

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH0                                    (0x780U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH1                                    (0x784U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH2                                    (0x788U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH3                                    (0x78CU)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH4                                    (0x790U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH5                                    (0x794U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH6                                    (0x798U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH7                                    (0x79CU)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH8                                    (0x7A0U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH9                                    (0x7A4U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH10                                   (0x7A8U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH11                                   (0x7ACU)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH12                                   (0x7B0U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH13                                   (0x7B4U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH14                                   (0x7B8U)

/* General purpose read-write register intended for scratchpad use */
#define CSL_BOOTCFG_SCRATCH15                                   (0x7BCU)

/* Register to indicate secure/non-secure status for each of the C66x cores */
#define CSL_BOOTCFG_DSP_SECURE_STAT                             (0x800U)

/* Register to control C66x core 0 secure/non-secure state. This register is 
 * reset only on POR and the value written is sticky (one time write per POR) 
 * until the next POR. Inorder to switch C66x core from secure to non-secure 
 * state, this register must be set to 0 and a C66x global reset(gresetz) or 
 * any Non-POR device reset must be issued. The intended usage of this 
 * register is determination of C66xsecurity configuration (secure or 
 * non-secure) during development phase. Usage of this register is not 
 * intended in aproduction environment (after customer keys are blown). */
#define CSL_BOOTCFG_DSP_SECURE_EN0                              (0x804U)

/* Register to control the non-secure boot address for C66x core 0. This boot 
 * address will be used by the C66x core whenit is coming out of reset in 
 * non-secure state. */
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_NS                           (0x844U)

/* Register provides enable for functions of the chip that present possible 
 * external access to secured portions of the chip. */
#define CSL_BOOTCFG_SECURE_CONTROL                              (0x884U)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH0                             (0x888U)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH1                             (0x88CU)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH2                             (0x890U)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH3                             (0x894U)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH4                             (0x898U)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH5                             (0x89CU)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH6                             (0x8A0U)

/* Read-write register intended for Secure scratchpad use. This register is 
 * only accessible by secure master or secure gueston a secure device, 
 * emulation access is not allowed. */
#define CSL_BOOTCFG_SECURE_SCRATCH7                             (0x8A4U)

/* LED Core Pass Done Registers */
#define CSL_BOOTCFG_LED_CORE_PASSDONE0                          (0xC00U)

/* LED Core Pass Done Registers */
#define CSL_BOOTCFG_LED_CORE_PASSDONE1                          (0xC04U)

/* This 24-bit output BOOTADDR from bootcfg module is connected to 
 * tetris_wrap.led_address_msb[23:0]. The one bitoutput LEDMODE is connected 
 * to tetris_wrap.led_address_override. This register is applicable in ARM LED 
 * modeonly to boot from a different address than 0x0000_0000. As this can be 
 * a secure hole, this register MUST not bewritable in a secure device type. */
#define CSL_BOOTCFG_LED_ARM_BOOTADDR                            (0xC20U)

/* LED GPIO Clear 0 Register */
#define CSL_BOOTCFG_LED_GPIO_CLR0                               (0xC30U)

/* LED GPIO Set 0 Register */
#define CSL_BOOTCFG_LED_GPIO_SET0                               (0xC38U)

/* LED PLL Lock 0 Register */
#define CSL_BOOTCFG_LED_PLLLOCK0                                (0xC40U)

/* LED PLL Lock 1 Register */
#define CSL_BOOTCFG_LED_PLLLOCK1                                (0xC44U)

/* LED Chip Pass Done Register */
#define CSL_BOOTCFG_LED_CHIP_PASSDONE                           (0xC48U)

/* Thermal Diode Register */
#define CSL_BOOTCFG_TDIODE                                      (0xC50U)

/* Margin 0 register for DFT */
#define CSL_BOOTCFG_MARGIN0                                     (0xC54U)

/* Margin 1 register for DFT */
#define CSL_BOOTCFG_MARGIN1                                     (0xC58U)

/* Margin 2 register for DFT */
#define CSL_BOOTCFG_MARGIN2                                     (0xC5CU)

/* Efuse Secure ROM Checksum 0 Register for DSP bootrom. NOTE - BOOTROM code 
 * doesn't require this register / EFUSE. In Galileo, this register / EFUSE 
 * can be re-purposedfor other usage if needed. */
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM0                        (0xC60U)

/* Efuse Secure ROM Checksum 1 Register for DSP bootrom. NOTE - BOOTROM code 
 * doesn't require this register / EFUSE. In Galileo, this register / EFUSE 
 * can be re-purposedfor other usage if needed. */
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM1                        (0xC64U)

/* Efuse Secure ROM Checksum 2 Register for ARM bootrom. NOTE - BOOTROM code 
 * doesn't require this register / EFUSE. In Galileo, this register / EFUSE 
 * can be re-purposedfor other usage if needed. */
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM2                        (0xC68U)

/* Efuse Secure ROM Checksum 3 Register for ARM bootrom. NOTE - BOOTROM code 
 * doesn't require this register / EFUSE. In Galileo, this register / EFUSE 
 * can be re-purposedfor other usage if needed. */
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM3                        (0xC6CU)

/* Internal Spare 0 Register */
#define CSL_BOOTCFG_INT_SPARE0                                  (0xC70U)

/* Internal Spare 1 Register */
#define CSL_BOOTCFG_INT_SPARE1                                  (0xC74U)

/* Chip Miscellaneous Control Register 1, internal only register */
#define CSL_BOOTCFG_CHIP_MISC_CTL1                              (0xC7CU)

/* The observation clock control register provides control to monitor various 
 * on-chip PLL/OSC clocks onto the deviceOBSCLK pin */
#define CSL_BOOTCFG_OBSCLKCTL                                   (0xC80U)

/* This register is allocated for BOOTROM usage */
#define CSL_BOOTCFG_EFUSE_BOOTROM                               (0xC90U)

/* This register is allocated for software usage */
#define CSL_BOOTCFG_EFUSE_SOFTWARE                              (0xC94U)

/* This register is allocated for internal design use. The allocation of this 
 * register bit to the EFUSE and the details aremaintained by the Design team */
#define CSL_BOOTCFG_EFUSE_TRIM                                  (0xC98U)

/* This register is allocated for future usage. The 32-bits of this register 
 * will be connected to the EFUSE chain. */
#define CSL_BOOTCFG_EFUSE_RSVD                                  (0xC9CU)

/* This register is used to control the pgood chains sequencing. Each power 
 * domain has a 2-bit field (bit 1 from mode1_0register : bit 0 from mode0_0 
 * register) to control the wakeup sequence. mode1_0 (bit 1) : mode0_0 (bit 0) 
 * register decoding 00b - All pgood in series 01b - 2 parallel sets of pgoods 
 * (if there are 8 chains, 2 sets in parallel each having 4 chains) 10b - 4 
 * parallel sets of pgoods (if there are 8 chains, 4 sets in parallel each 
 * having 2 chains) 11b - All pgood in parallel */
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0                       (0xCA0U)

/* Power Switch Wakeup Mode 0_1 Register */
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_1                       (0xCA4U)

/* This register is used to control the pgood chains sequencing. Each power 
 * domain has a 2-bit field (bit 1 from mode1_0register : bit 0 from mode0_0 
 * register) to control the wakeup sequence. mode1_0 (bit 1) : mode0_0 (bit 0) 
 * register decoding 00b - All pgood in series 01b - 2 parallel sets of pgoods 
 * (if there are 8 chains, 2 sets in parallel each having 4 chains) 10b - 4 
 * parallel sets of pgoods (if there are 8 chains, 4 sets in parallel each 
 * having 2 chains) 11b - All pgood in parallel */
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0                       (0xCA8U)

/* Power Switch Wakeup Mode 1_1 Register */
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_1                       (0xCACU)

/* Power Switch Wakeup Control Register */
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL                           (0xCB0U)

/* This register is used to control the USB0 UTMI interface directly for DFT 
 * purposes only. The register control fieldsare valid and shall control the 
 * UTMI interface only when phy_tc_test_utmi = 1. In normal functional mode 
 * (resetstate), this control shall never be set to '1'. */
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL                       (0xCB4U)

/* This register is used to control the USB1 UTMI interface directly for DFT 
 * purposes only. The register control fieldsare valid and shall control the 
 * UTMI interface only when phy_tc_test_utmi = 1. In normal functional mode 
 * (resetstate), this control shall never be set to '1'. */
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL                       (0xCBCU)

/* DFT EHRPWM Control Register */
#define CSL_BOOTCFG_DFT_EHRPWM                                  (0xCC0U)

/* Margin 3 register for DFT */
#define CSL_BOOTCFG_MARGIN3                                     (0xCC4U)

/* IO STA team need clocks to be looped back before and through the IO buffers 
 * to gain flexibility in IO timing closure.Selection between the digital 
 * loopback clocks will be done using this register. */
#define CSL_BOOTCFG_IO_CLKLB_CTL                                (0xCC8U)

/* Selects 1 of 256 events for each of 4 GPIO/ASRC event muxes */
#define CSL_BOOTCFG_EVENT_MUXCTL0                               (0xD00U)

/* Event select for Event Mux3 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL1                               (0xD04U)

/* Event select for Event Mux7 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL2                               (0xD08U)

/* Event select for Event Mux11 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL3                               (0xD0CU)

/* Event select for Event Mux15 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL4                               (0xD10U)

/* Event select for Event Mux19 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL5                               (0xD14U)

/* Event select for Event Mux23 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL6                               (0xD18U)

/* Event select for Event Mux27 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL7                               (0xD1CU)

/* Event select for Event Mux31 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL8                               (0xD20U)

/* Event select for Event Mux35 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL9                               (0xD24U)

/* Event select for Event Mux39 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL10                              (0xD28U)

/* Event select for Event Mux43 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL11                              (0xD2CU)

/* Event select for Event Mux43 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL12                              (0xD30U)

/* Event select for Event Mux43 Reset Type:mod_g_rst_n */
#define CSL_BOOTCFG_EVENT_MUXCTL13                              (0xD34U)

/* Register to start/check status of the auto-initialization process of DCAN 
 * RAM */
#define CSL_BOOTCFG_DCAN_RAMINIT                                (0xE10U)

/* Internal only register for RTL generation flow and not used by software */
#define CSL_BOOTCFG_DCAN_RAMINIT_SET                            (0xE14U)

/* Ethernet Configuration Register */
#define CSL_BOOTCFG_ETHERNET_CFG                                (0xE20U)

/* Register controls the MLB SIG pins IO characteristics */
#define CSL_BOOTCFG_MLB_SIG_IO_CTL                              (0xE30U)

/* Register controls the MLB DAT pins IO characteristics */
#define CSL_BOOTCFG_MLB_DAT_IO_CTL                              (0xE34U)

/* Register controls the MLB LVDS clock receiver IO and the Band Gap 
 * characteristics */
#define CSL_BOOTCFG_MLB_CLK_BG_CTL                              (0xE38U)

/* EPWM Control Register */
#define CSL_BOOTCFG_EPWM_CTL                                    (0xE40U)

/* ECAP Event Control Register */
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL                             (0xE50U)

/* EQEP Status Register */
#define CSL_BOOTCFG_EQEP_STAT                                   (0xE60U)

/* Register controls the LVDS Bandgap cells */
#define CSL_BOOTCFG_LVDS_BG_CTL                                 (0xE70U)

/* Controls USB PHY supply LDO (Low Drop Output) regulator. LDO provides 0.85V 
 * supply to both the USB PHYs */
#define CSL_BOOTCFG_LDO_USB_CTL                                 (0xE80U)

/* Controls PCIe Serdes supply LDO (Low Drop Output) regulator. LDO provides 
 * 0.85V supply to the PCIe Serdes */
#define CSL_BOOTCFG_LDO_PCIE_CTL                                (0xE84U)

/* BAW (Bulk Acoustic Wave) control register */
#define CSL_BOOTCFG_BAW_CTL                                     (0xE90U)

/* BAW trim control register, default value is set by EFUSE and MMR 
 * over-writable */
#define CSL_BOOTCFG_BAW_TRIM                                    (0xE94U)

/* BAW temperature sensor control register */
#define CSL_BOOTCFG_BAW_TS                                      (0xE98U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG0                                  (0x1000U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG1                                  (0x1004U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG2                                  (0x1008U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG3                                  (0x100CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG4                                  (0x1010U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG5                                  (0x1014U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG6                                  (0x1018U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG7                                  (0x101CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG8                                  (0x1020U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG9                                  (0x1024U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG10                                 (0x1028U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG11                                 (0x102CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG12                                 (0x1030U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG13                                 (0x1034U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG14                                 (0x1038U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG15                                 (0x103CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG16                                 (0x1040U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG17                                 (0x1044U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG18                                 (0x1048U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG19                                 (0x104CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG20                                 (0x1050U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG21                                 (0x1054U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG22                                 (0x1058U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG23                                 (0x105CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG24                                 (0x1060U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG25                                 (0x1064U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG26                                 (0x1068U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG27                                 (0x106CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG28                                 (0x1070U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG29                                 (0x1074U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG30                                 (0x1078U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG31                                 (0x107CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG32                                 (0x1080U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG33                                 (0x1084U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG34                                 (0x1088U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG35                                 (0x108CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG36                                 (0x1090U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG37                                 (0x1094U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG38                                 (0x1098U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG39                                 (0x109CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG40                                 (0x10A0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG41                                 (0x10A4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG42                                 (0x10A8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG43                                 (0x10ACU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG44                                 (0x10B0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG45                                 (0x10B4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG46                                 (0x10B8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG47                                 (0x10BCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG48                                 (0x10C0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG49                                 (0x10C4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG50                                 (0x10C8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG51                                 (0x10CCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG52                                 (0x10D0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG53                                 (0x10D4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG54                                 (0x10D8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG55                                 (0x10DCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG56                                 (0x10E0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG57                                 (0x10E4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG58                                 (0x10E8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG59                                 (0x10ECU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG60                                 (0x10F0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG61                                 (0x10F4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG62                                 (0x10F8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG63                                 (0x10FCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG64                                 (0x1100U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG65                                 (0x1104U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG66                                 (0x1108U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG67                                 (0x110CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG68                                 (0x1110U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG69                                 (0x1114U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG70                                 (0x1118U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG71                                 (0x111CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG72                                 (0x1120U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG73                                 (0x1124U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG74                                 (0x1128U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG75                                 (0x112CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG76                                 (0x1130U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG77                                 (0x1134U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG78                                 (0x1138U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG79                                 (0x113CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG80                                 (0x1140U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG81                                 (0x1144U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG82                                 (0x1148U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG83                                 (0x114CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG84                                 (0x1150U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG85                                 (0x1154U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG86                                 (0x1158U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG87                                 (0x115CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG88                                 (0x1160U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG89                                 (0x1164U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG90                                 (0x1168U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG91                                 (0x116CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG92                                 (0x1170U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG93                                 (0x1174U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG94                                 (0x1178U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG95                                 (0x117CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG96                                 (0x1180U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG97                                 (0x1184U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG98                                 (0x1188U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG99                                 (0x118CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG100                                (0x1190U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG101                                (0x1194U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG102                                (0x1198U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG103                                (0x119CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG104                                (0x11A0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG105                                (0x11A4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG106                                (0x11A8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG107                                (0x11ACU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG108                                (0x11B0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG109                                (0x11B4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG110                                (0x11B8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG111                                (0x11BCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG112                                (0x11C0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG113                                (0x11C4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG114                                (0x11C8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG115                                (0x11CCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG116                                (0x11D0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG117                                (0x11D4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG118                                (0x11D8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG119                                (0x11DCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG120                                (0x11E0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG121                                (0x11E4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG122                                (0x11E8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG123                                (0x11ECU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG124                                (0x11F0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG125                                (0x11F4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG126                                (0x11F8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG127                                (0x11FCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG128                                (0x1200U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG129                                (0x1204U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG130                                (0x1208U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG131                                (0x120CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG132                                (0x1210U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG133                                (0x1214U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG134                                (0x1218U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG135                                (0x121CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG136                                (0x1220U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG137                                (0x1224U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG138                                (0x1228U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG139                                (0x122CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG140                                (0x1230U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG141                                (0x1234U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG142                                (0x1238U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG143                                (0x123CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG144                                (0x1240U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG145                                (0x1244U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG146                                (0x1248U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG147                                (0x124CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG148                                (0x1250U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG149                                (0x1254U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG150                                (0x1258U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG151                                (0x125CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG152                                (0x1260U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG153                                (0x1264U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG154                                (0x1268U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG155                                (0x126CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG156                                (0x1270U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG157                                (0x1274U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG158                                (0x1278U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG159                                (0x127CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG160                                (0x1280U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG161                                (0x1284U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG162                                (0x1288U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG163                                (0x128CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG164                                (0x1290U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG165                                (0x1294U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG166                                (0x1298U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG167                                (0x129CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG168                                (0x12A0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG169                                (0x12A4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG170                                (0x12A8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG171                                (0x12ACU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG172                                (0x12B0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG173                                (0x12B4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG174                                (0x12B8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG175                                (0x12BCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG176                                (0x12C0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG177                                (0x12C4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG178                                (0x12C8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG179                                (0x12CCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG180                                (0x12D0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG181                                (0x12D4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG182                                (0x12D8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG183                                (0x12DCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG184                                (0x12E0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG185                                (0x12E4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG186                                (0x12E8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG187                                (0x12ECU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG188                                (0x12F0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG189                                (0x12F4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG190                                (0x12F8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG191                                (0x12FCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG192                                (0x1300U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG193                                (0x1304U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG194                                (0x1308U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG195                                (0x130CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG196                                (0x1310U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG197                                (0x1314U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG198                                (0x1318U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG199                                (0x131CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG200                                (0x1320U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG201                                (0x1324U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG202                                (0x1328U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG203                                (0x132CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG204                                (0x1330U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG205                                (0x1334U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG206                                (0x1338U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG207                                (0x133CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG208                                (0x1340U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG209                                (0x1344U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG210                                (0x1348U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG211                                (0x134CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG212                                (0x1350U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG213                                (0x1354U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG214                                (0x1358U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG215                                (0x135CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG216                                (0x1360U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG217                                (0x1364U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG218                                (0x1368U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG219                                (0x136CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG220                                (0x1370U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG221                                (0x1374U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG222                                (0x1378U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG223                                (0x137CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG224                                (0x1380U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG225                                (0x1384U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG226                                (0x1388U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG227                                (0x138CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG228                                (0x1390U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG229                                (0x1394U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG230                                (0x1398U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG231                                (0x139CU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG232                                (0x13A0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG233                                (0x13A4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG234                                (0x13A8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG235                                (0x13ACU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG236                                (0x13B0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG237                                (0x13B4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG238                                (0x13B8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG239                                (0x13BCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG240                                (0x13C0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG241                                (0x13C4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG242                                (0x13C8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG243                                (0x13CCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG244                                (0x13D0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG245                                (0x13D4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG246                                (0x13D8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG247                                (0x13DCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG248                                (0x13E0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG249                                (0x13E4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG250                                (0x13E8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG251                                (0x13ECU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG252                                (0x13F0U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG253                                (0x13F4U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG254                                (0x13F8U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG255                                (0x13FCU)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG256                                (0x1400U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG257                                (0x1404U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG258                                (0x1408U)

/* Register to control pin configuration and muxing */
#define CSL_BOOTCFG_PADCONFIG259                                (0x140CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* BOOTCFG_REVISION */

#define CSL_BOOTCFG_BOOTCFG_REVISION_RESETVAL                   (0x00000000U)

/* DIEID */

#define CSL_BOOTCFG_DIEID_DIEID_MASK                            (0xFFFFFFFFU)
#define CSL_BOOTCFG_DIEID_DIEID_SHIFT                           (0U)
#define CSL_BOOTCFG_DIEID_DIEID_RESETVAL                        (0x00000000U)
#define CSL_BOOTCFG_DIEID_DIEID_MAX                             (0xffffffffU)

#define CSL_BOOTCFG_DIEID_RESETVAL                              (0x00000000U)

/* JTAGID */

#define CSL_BOOTCFG_JTAGID_LSB_MASK                             (0x00000001U)
#define CSL_BOOTCFG_JTAGID_LSB_SHIFT                            (0U)
#define CSL_BOOTCFG_JTAGID_LSB_RESETVAL                         (0x00000001U)
#define CSL_BOOTCFG_JTAGID_LSB_MAX                              (0x00000001U)

#define CSL_BOOTCFG_JTAGID_MANUFACTURER_MASK                    (0x00000FFEU)
#define CSL_BOOTCFG_JTAGID_MANUFACTURER_SHIFT                   (1U)
#define CSL_BOOTCFG_JTAGID_MANUFACTURER_RESETVAL                (0x00000017U)
#define CSL_BOOTCFG_JTAGID_MANUFACTURER_MAX                     (0x000007ffU)

#define CSL_BOOTCFG_JTAGID_PARTNUMBER_MASK                      (0x0FFFF000U)
#define CSL_BOOTCFG_JTAGID_PARTNUMBER_SHIFT                     (12U)
#define CSL_BOOTCFG_JTAGID_PARTNUMBER_RESETVAL                  (0x0000bb06U)
#define CSL_BOOTCFG_JTAGID_PARTNUMBER_MAX                       (0x0000ffffU)

#define CSL_BOOTCFG_JTAGID_VARIANT_MASK                         (0xF0000000U)
#define CSL_BOOTCFG_JTAGID_VARIANT_SHIFT                        (28U)
#define CSL_BOOTCFG_JTAGID_VARIANT_RESETVAL                     (0x00000000U)
#define CSL_BOOTCFG_JTAGID_VARIANT_MAX                          (0x0000000fU)

#define CSL_BOOTCFG_JTAGID_RESETVAL                             (0x0bb0602fU)

/* DEVSTAT */

#define CSL_BOOTCFG_DEVSTAT_LENDIAN_MASK                        (0x00000001U)
#define CSL_BOOTCFG_DEVSTAT_LENDIAN_SHIFT                       (0U)
#define CSL_BOOTCFG_DEVSTAT_LENDIAN_RESETVAL                    (0x00000001U)
#define CSL_BOOTCFG_DEVSTAT_LENDIAN_MAX                         (0x00000001U)

#define CSL_BOOTCFG_DEVSTAT_BOOTMODE_MASK                       (0x0001FFFEU)
#define CSL_BOOTCFG_DEVSTAT_BOOTMODE_SHIFT                      (1U)
#define CSL_BOOTCFG_DEVSTAT_BOOTMODE_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_DEVSTAT_BOOTMODE_MAX                        (0x0000ffffU)

#define CSL_BOOTCFG_DEVSTAT_AVSIFSEL_MASK                       (0x00060000U)
#define CSL_BOOTCFG_DEVSTAT_AVSIFSEL_SHIFT                      (17U)
#define CSL_BOOTCFG_DEVSTAT_AVSIFSEL_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_DEVSTAT_AVSIFSEL_MAX                        (0x00000003U)

#define CSL_BOOTCFG_DEVSTAT_MAINPLL_ODSEL_MASK                  (0x00080000U)
#define CSL_BOOTCFG_DEVSTAT_MAINPLL_ODSEL_SHIFT                 (19U)
#define CSL_BOOTCFG_DEVSTAT_MAINPLL_ODSEL_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_DEVSTAT_MAINPLL_ODSEL_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DEVSTAT_ARM_BENDIAN_MASK                    (0x00400000U)
#define CSL_BOOTCFG_DEVSTAT_ARM_BENDIAN_SHIFT                   (22U)
#define CSL_BOOTCFG_DEVSTAT_ARM_BENDIAN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_DEVSTAT_ARM_BENDIAN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_DEVSTAT_RESETVAL                            (0x00000001U)

/* KICK0 */

#define CSL_BOOTCFG_KICK0_KICK0_MASK                            (0xFFFFFFFFU)
#define CSL_BOOTCFG_KICK0_KICK0_SHIFT                           (0U)
#define CSL_BOOTCFG_KICK0_KICK0_RESETVAL                        (0x00000000U)
#define CSL_BOOTCFG_KICK0_KICK0_MAX                             (0xffffffffU)

#define CSL_BOOTCFG_KICK0_RESETVAL                              (0x00000000U)

/* KICK1 */

#define CSL_BOOTCFG_KICK1_KICK1_MASK                            (0xFFFFFFFFU)
#define CSL_BOOTCFG_KICK1_KICK1_SHIFT                           (0U)
#define CSL_BOOTCFG_KICK1_KICK1_RESETVAL                        (0x00000000U)
#define CSL_BOOTCFG_KICK1_KICK1_MAX                             (0xffffffffU)

#define CSL_BOOTCFG_KICK1_RESETVAL                              (0x00000000U)

/* DSP_BOOT_ADDR0 */

#define CSL_BOOTCFG_DSP_BOOT_ADDR0_ISTP_RST_VAL_MASK            (0xFFFFFC00U)
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_ISTP_RST_VAL_SHIFT           (10U)
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_ISTP_RST_VAL_RESETVAL        (0x00082c00U)
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_ISTP_RST_VAL_MAX             (0x003fffffU)

#define CSL_BOOTCFG_DSP_BOOT_ADDR0_RESETVAL                     (0x20b00000U)

/* BOOTCFG_INTR_RAW_STAT_SET */

#define CSL_BOOTCFG_BOOTCFG_INTR_RAW_STAT_SET_RESETVAL          (0x00000000U)

/* BOOTCFG_INTR_ENABLED_STAT_CLR */

#define CSL_BOOTCFG_BOOTCFG_INTR_ENABLED_STAT_CLR_RESETVAL      (0x00000000U)

/* BOOTCFG_INTR_ENABLE */

#define CSL_BOOTCFG_BOOTCFG_INTR_ENABLE_RESETVAL                (0x00000000U)

/* BOOTCFG_INTR_ENABLE_CLR */

#define CSL_BOOTCFG_BOOTCFG_INTR_ENABLE_CLR_RESETVAL            (0x00000000U)

/* BOOTCFG_EOI */

#define CSL_BOOTCFG_BOOTCFG_EOI_RESETVAL                        (0x00000000U)

/* BOOTCFG_FAULT_ADDR */

#define CSL_BOOTCFG_BOOTCFG_FAULT_ADDR_RESETVAL                 (0x00000000U)

/* BOOTCFG_FAULT_STAT */

#define CSL_BOOTCFG_BOOTCFG_FAULT_STAT_RESETVAL                 (0x00000000U)

/* BOOTCFG_FAULT_CLR */

#define CSL_BOOTCFG_BOOTCFG_FAULT_CLR_RESETVAL                  (0x00000000U)

/* MACID0 */

#define CSL_BOOTCFG_MACID0_MACID_MASK                           (0xFFFFFFFFU)
#define CSL_BOOTCFG_MACID0_MACID_SHIFT                          (0U)
#define CSL_BOOTCFG_MACID0_MACID_RESETVAL                       (0x00000000U)
#define CSL_BOOTCFG_MACID0_MACID_MAX                            (0xffffffffU)

#define CSL_BOOTCFG_MACID0_RESETVAL                             (0x00000000U)

/* MACID1 */

#define CSL_BOOTCFG_MACID1_MACID_MASK                           (0x0000FFFFU)
#define CSL_BOOTCFG_MACID1_MACID_SHIFT                          (0U)
#define CSL_BOOTCFG_MACID1_MACID_RESETVAL                       (0x00000000U)
#define CSL_BOOTCFG_MACID1_MACID_MAX                            (0x0000ffffU)

#define CSL_BOOTCFG_MACID1_BCAST_MASK                           (0x00010000U)
#define CSL_BOOTCFG_MACID1_BCAST_SHIFT                          (16U)
#define CSL_BOOTCFG_MACID1_BCAST_RESETVAL                       (0x00000000U)
#define CSL_BOOTCFG_MACID1_BCAST_MAX                            (0x00000001U)

#define CSL_BOOTCFG_MACID1_FLOW_MASK                            (0x00020000U)
#define CSL_BOOTCFG_MACID1_FLOW_SHIFT                           (17U)
#define CSL_BOOTCFG_MACID1_FLOW_RESETVAL                        (0x00000000U)
#define CSL_BOOTCFG_MACID1_FLOW_MAX                             (0x00000001U)

#define CSL_BOOTCFG_MACID1_CRC_MASK                             (0xFF000000U)
#define CSL_BOOTCFG_MACID1_CRC_SHIFT                            (24U)
#define CSL_BOOTCFG_MACID1_CRC_RESETVAL                         (0x00000000U)
#define CSL_BOOTCFG_MACID1_CRC_MAX                              (0x000000ffU)

#define CSL_BOOTCFG_MACID1_RESETVAL                             (0x00000000U)

/* PCIEVENDORID */

#define CSL_BOOTCFG_PCIEVENDORID_PCIEVENDORID_MASK              (0x0000FFFFU)
#define CSL_BOOTCFG_PCIEVENDORID_PCIEVENDORID_SHIFT             (0U)
#define CSL_BOOTCFG_PCIEVENDORID_PCIEVENDORID_RESETVAL          (0x0000104cU)
#define CSL_BOOTCFG_PCIEVENDORID_PCIEVENDORID_MAX               (0x0000ffffU)

#define CSL_BOOTCFG_PCIEVENDORID_PCIEDEVICEID_MASK              (0xFFFF0000U)
#define CSL_BOOTCFG_PCIEVENDORID_PCIEDEVICEID_SHIFT             (16U)
#define CSL_BOOTCFG_PCIEVENDORID_PCIEDEVICEID_RESETVAL          (0x0000b00bU)
#define CSL_BOOTCFG_PCIEVENDORID_PCIEDEVICEID_MAX               (0x0000ffffU)

#define CSL_BOOTCFG_PCIEVENDORID_RESETVAL                       (0xb00b104cU)

/* DISABLESTAT */

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GEM0_MASK         (0x00000001U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GEM0_SHIFT        (0U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GEM0_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GEM0_MAX          (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD0_MASK        (0x00000006U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD0_SHIFT       (1U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD0_MAX         (0x00000003U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QSPI_MASK         (0x00000008U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QSPI_SHIFT        (3U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QSPI_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QSPI_MAX          (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MMC01_MASK        (0x00000010U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MMC01_SHIFT       (4U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MMC01_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MMC01_MAX         (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GPMC_ELM_MASK     (0x00000020U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GPMC_ELM_SHIFT    (5U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GPMC_ELM_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_GPMC_ELM_MAX      (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DCAN01_MASK       (0x00000040U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DCAN01_SHIFT      (6U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DCAN01_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DCAN01_MAX        (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MLB_MASK          (0x00000080U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MLB_SHIFT         (7U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MLB_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MLB_MAX           (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_A15_CORE0_MASK    (0x00000100U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_A15_CORE0_SHIFT   (8U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_A15_CORE0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_A15_CORE0_MAX     (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_HRPWM05_MASK      (0x00000200U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_HRPWM05_SHIFT     (9U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_HRPWM05_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_HRPWM05_MAX       (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QEP02_MASK        (0x00000400U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QEP02_SHIFT       (10U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QEP02_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_QEP02_MAX         (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CAP01_MASK        (0x00000800U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CAP01_SHIFT       (11U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CAP01_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CAP01_MAX         (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_TETRIS_MASK       (0x00001000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_TETRIS_SHIFT      (12U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_TETRIS_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_TETRIS_MAX        (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CRYPTO_MASK       (0x00002000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CRYPTO_SHIFT      (13U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CRYPTO_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_CRYPTO_MAX        (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD3_MASK        (0x00004000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD3_SHIFT       (14U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD3_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD3_MAX         (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MCASP02_MASK      (0x00008000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MCASP02_SHIFT     (15U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MCASP02_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_MCASP02_MAX       (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ASRC_MASK         (0x00010000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ASRC_SHIFT        (16U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ASRC_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ASRC_MAX          (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ICSS01_MASK       (0x00020000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ICSS01_SHIFT      (17U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ICSS01_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_ICSS01_MAX        (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DSS_UL_MASK       (0x00080000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DSS_UL_SHIFT      (19U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DSS_UL_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_DSS_UL_MAX        (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_PCIE_MASK         (0x00100000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_PCIE_SHIFT        (20U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_PCIE_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_PCIE_MAX          (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB0_MASK         (0x00200000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB0_SHIFT        (21U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB0_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB0_MAX          (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB1_MASK         (0x00400000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB1_SHIFT        (22U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB1_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_USB1_MAX          (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC0_MASK  (0x00800000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC0_SHIFT  (23U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC0_MAX  (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC1_MASK  (0x01000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC1_SHIFT  (24U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE0_LPSC1_MAX  (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC0_MASK  (0x02000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC0_SHIFT  (25U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC0_MAX  (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC1_MASK  (0x04000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC1_SHIFT  (26U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_SPARE1_LPSC1_MAX  (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD2_MASK        (0xF8000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD2_SHIFT       (27U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD2_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD2_MAX         (0x0000001fU)

#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD1_MASK        (0x00040000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD1_SHIFT       (18U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD1_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DISABLESTAT_EFUSE_DISABLE_RSVD1_MAX         (0x00000001U)

#define CSL_BOOTCFG_DISABLESTAT_RESETVAL                        (0x00000000U)

/* LRSTNMISTAT_CLR */

#define CSL_BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR_MASK      (0x00000001U)
#define CSL_BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR_SHIFT     (0U)
#define CSL_BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR_MAX       (0x00000001U)

#define CSL_BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_0_CLR_MASK         (0x00000100U)
#define CSL_BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_0_CLR_SHIFT        (8U)
#define CSL_BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_0_CLR_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_0_CLR_MAX          (0x00000001U)

#define CSL_BOOTCFG_LRSTNMISTAT_CLR_RESETVAL                    (0x00000000U)

/* RESET_STAT_CLR */

#define CSL_BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR_MASK         (0x00000001U)
#define CSL_BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR_SHIFT        (0U)
#define CSL_BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR_MAX          (0x00000001U)

#define CSL_BOOTCFG_RESET_STAT_CLR_GRST_STAT_CLR_MASK           (0x80000000U)
#define CSL_BOOTCFG_RESET_STAT_CLR_GRST_STAT_CLR_SHIFT          (31U)
#define CSL_BOOTCFG_RESET_STAT_CLR_GRST_STAT_CLR_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_RESET_STAT_CLR_GRST_STAT_CLR_MAX            (0x00000001U)

#define CSL_BOOTCFG_RESET_STAT_CLR_RESETVAL                     (0x00000000U)

/* BOOTCOMPLETE */

#define CSL_BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE_MASK             (0x00000001U)
#define CSL_BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE_SHIFT            (0U)
#define CSL_BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE_MAX              (0x00000001U)

#define CSL_BOOTCFG_BOOTCOMPLETE_ARM0_COMPLETE_MASK             (0x00000100U)
#define CSL_BOOTCFG_BOOTCOMPLETE_ARM0_COMPLETE_SHIFT            (8U)
#define CSL_BOOTCFG_BOOTCOMPLETE_ARM0_COMPLETE_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_BOOTCOMPLETE_ARM0_COMPLETE_MAX              (0x00000001U)

#define CSL_BOOTCFG_BOOTCOMPLETE_RESETVAL                       (0x00000000U)

/* BOOTPROGRESS */

#define CSL_BOOTCFG_BOOTPROGRESS_BOOTPROGRESS_MASK              (0xFFFFFFFFU)
#define CSL_BOOTCFG_BOOTPROGRESS_BOOTPROGRESS_SHIFT             (0U)
#define CSL_BOOTCFG_BOOTPROGRESS_BOOTPROGRESS_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_BOOTPROGRESS_BOOTPROGRESS_MAX               (0xffffffffU)

#define CSL_BOOTCFG_BOOTPROGRESS_RESETVAL                       (0x00000000U)

/* RESET_STAT */

#define CSL_BOOTCFG_RESET_STAT_GRST_STAT_MASK                   (0x80000000U)
#define CSL_BOOTCFG_RESET_STAT_GRST_STAT_SHIFT                  (31U)
#define CSL_BOOTCFG_RESET_STAT_GRST_STAT_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_RESET_STAT_GRST_STAT_MAX                    (0x00000001U)

#define CSL_BOOTCFG_RESET_STAT_LRST_STAT0_MASK                  (0x00000001U)
#define CSL_BOOTCFG_RESET_STAT_LRST_STAT0_SHIFT                 (0U)
#define CSL_BOOTCFG_RESET_STAT_LRST_STAT0_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_RESET_STAT_LRST_STAT0_MAX                   (0x00000001U)

#define CSL_BOOTCFG_RESET_STAT_RESETVAL                         (0x00000000U)

/* LRSTNMISTAT */

#define CSL_BOOTCFG_LRSTNMISTAT_LRESET_STAT_MASK                (0x00000001U)
#define CSL_BOOTCFG_LRSTNMISTAT_LRESET_STAT_SHIFT               (0U)
#define CSL_BOOTCFG_LRSTNMISTAT_LRESET_STAT_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_LRSTNMISTAT_LRESET_STAT_MAX                 (0x00000001U)

#define CSL_BOOTCFG_LRSTNMISTAT_NMI_STAT_MASK                   (0x00000100U)
#define CSL_BOOTCFG_LRSTNMISTAT_NMI_STAT_SHIFT                  (8U)
#define CSL_BOOTCFG_LRSTNMISTAT_NMI_STAT_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_LRSTNMISTAT_NMI_STAT_MAX                    (0x00000001U)

#define CSL_BOOTCFG_LRSTNMISTAT_RESETVAL                        (0x00000000U)

/* DEVCFG */

#define CSL_BOOTCFG_DEVCFG_SYSCLKOUTEN_MASK                     (0x00000001U)
#define CSL_BOOTCFG_DEVCFG_SYSCLKOUTEN_SHIFT                    (0U)
#define CSL_BOOTCFG_DEVCFG_SYSCLKOUTEN_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_DEVCFG_SYSCLKOUTEN_MAX                      (0x00000001U)

#define CSL_BOOTCFG_DEVCFG_PCIE_DEV_TYPE_MASK                   (0x00000006U)
#define CSL_BOOTCFG_DEVCFG_PCIE_DEV_TYPE_SHIFT                  (1U)
#define CSL_BOOTCFG_DEVCFG_PCIE_DEV_TYPE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_DEVCFG_PCIE_DEV_TYPE_ENDPOINT_MODE          (0x00000000U)
#define CSL_BOOTCFG_DEVCFG_PCIE_DEV_TYPE_LEGACY_ENDPOINT_MODE   (0x00000001U)
#define CSL_BOOTCFG_DEVCFG_PCIE_DEV_TYPE_ROOTCOMPLEX_MODE       (0x00000002U)

#define CSL_BOOTCFG_DEVCFG_RESETVAL                             (0x00000001U)

/* PWR_STATE */

#define CSL_BOOTCFG_PWR_STATE_PWR_MODE_MASK                     (0x00000007U)
#define CSL_BOOTCFG_PWR_STATE_PWR_MODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PWR_STATE_PWR_MODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PWR_STATE_PWR_MODE_MAX                      (0x00000007U)

#define CSL_BOOTCFG_PWR_STATE_PMMC_FW_LOAD_MASK                 (0x00000008U)
#define CSL_BOOTCFG_PWR_STATE_PMMC_FW_LOAD_SHIFT                (3U)
#define CSL_BOOTCFG_PWR_STATE_PMMC_FW_LOAD_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PWR_STATE_PMMC_FW_LOAD_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PWR_STATE_PWR_STATE_GENERAL_MASK            (0xFFFFFFF0U)
#define CSL_BOOTCFG_PWR_STATE_PWR_STATE_GENERAL_SHIFT           (4U)
#define CSL_BOOTCFG_PWR_STATE_PWR_STATE_GENERAL_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_PWR_STATE_PWR_STATE_GENERAL_MAX             (0x0fffffffU)

#define CSL_BOOTCFG_PWR_STATE_RESETVAL                          (0x00000000U)

/* INITIATOR_PRIORITY0 */

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_PMMC_PRI_MASK           (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_PMMC_PRI_SHIFT          (0U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_PMMC_PRI_RESETVAL       (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_PMMC_PRI_MAX            (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MLB_PRI_MASK            (0x00000070U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MLB_PRI_SHIFT           (4U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MLB_PRI_RESETVAL        (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MLB_PRI_MAX             (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC0_PRI_MASK           (0x00000700U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC0_PRI_SHIFT          (8U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC0_PRI_RESETVAL       (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC0_PRI_MAX            (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC1_PRI_MASK           (0x00007000U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC1_PRI_SHIFT          (12U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC1_PRI_RESETVAL       (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_MMC1_PRI_MAX            (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU0_PRI_MASK     (0x00070000U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU0_PRI_SHIFT    (16U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU0_PRI_RESETVAL  (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU0_PRI_MAX      (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU1_PRI_MASK     (0x00700000U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU1_PRI_SHIFT    (20U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU1_PRI_RESETVAL  (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS0_PRU1_PRI_MAX      (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU0_PRI_MASK     (0x07000000U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU0_PRI_SHIFT    (24U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU0_PRI_RESETVAL  (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU0_PRI_MAX      (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU1_PRI_MASK     (0x70000000U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU1_PRI_SHIFT    (28U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU1_PRI_RESETVAL  (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY0_ICSS1_PRU1_PRI_MAX      (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY0_RESETVAL                (0x77777777U)

/* INITIATOR_PRIORITY1 */

#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_LO_MASK         (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_LO_SHIFT        (0U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_LO_RESETVAL     (0x00000007U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_LO_MAX          (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_HI_MASK         (0x00000070U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_HI_SHIFT        (4U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_HI_RESETVAL     (0x00000001U)
#define CSL_BOOTCFG_INITIATOR_PRIORITY1_DSS_PRI_HI_MAX          (0x00000007U)

#define CSL_BOOTCFG_INITIATOR_PRIORITY1_RESETVAL                (0x00000017U)

/* SR0_CLASS0 */

#define CSL_BOOTCFG_SR0_CLASS0_SR0_CLASS_MASK                   (0xFFFFFFFFU)
#define CSL_BOOTCFG_SR0_CLASS0_SR0_CLASS_SHIFT                  (0U)
#define CSL_BOOTCFG_SR0_CLASS0_SR0_CLASS_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_SR0_CLASS0_SR0_CLASS_MAX                    (0xffffffffU)

#define CSL_BOOTCFG_SR0_CLASS0_RESETVAL                         (0x00000000U)

/* SR0_OPP0_SEN */

#define CSL_BOOTCFG_SR0_OPP0_SEN_SR0_OPP0_SEN_MASK              (0xFFFFFFFFU)
#define CSL_BOOTCFG_SR0_OPP0_SEN_SR0_OPP0_SEN_SHIFT             (0U)
#define CSL_BOOTCFG_SR0_OPP0_SEN_SR0_OPP0_SEN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_SR0_OPP0_SEN_SR0_OPP0_SEN_MAX               (0xffffffffU)

#define CSL_BOOTCFG_SR0_OPP0_SEN_RESETVAL                       (0x00000000U)

/* SR0_OPP1_SEN */

#define CSL_BOOTCFG_SR0_OPP1_SEN_SR0_OPP1_SEN_MASK              (0xFFFFFFFFU)
#define CSL_BOOTCFG_SR0_OPP1_SEN_SR0_OPP1_SEN_SHIFT             (0U)
#define CSL_BOOTCFG_SR0_OPP1_SEN_SR0_OPP1_SEN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_SR0_OPP1_SEN_SR0_OPP1_SEN_MAX               (0xffffffffU)

#define CSL_BOOTCFG_SR0_OPP1_SEN_RESETVAL                       (0x00000000U)

/* SR0_OPP2_SEN */

#define CSL_BOOTCFG_SR0_OPP2_SEN_SR0_OPP2_SEN_MASK              (0xFFFFFFFFU)
#define CSL_BOOTCFG_SR0_OPP2_SEN_SR0_OPP2_SEN_SHIFT             (0U)
#define CSL_BOOTCFG_SR0_OPP2_SEN_SR0_OPP2_SEN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_SR0_OPP2_SEN_SR0_OPP2_SEN_MAX               (0xffffffffU)

#define CSL_BOOTCFG_SR0_OPP2_SEN_RESETVAL                       (0x00000000U)

/* SR0_OPP3_SEN */

#define CSL_BOOTCFG_SR0_OPP3_SEN_SR0_OPP3_SEN_MASK              (0xFFFFFFFFU)
#define CSL_BOOTCFG_SR0_OPP3_SEN_SR0_OPP3_SEN_SHIFT             (0U)
#define CSL_BOOTCFG_SR0_OPP3_SEN_SR0_OPP3_SEN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_SR0_OPP3_SEN_SR0_OPP3_SEN_MAX               (0xffffffffU)

#define CSL_BOOTCFG_SR0_OPP3_SEN_RESETVAL                       (0x00000000U)

/* NMIGR0 */

#define CSL_BOOTCFG_NMIGR0_NMIGR0_REG_MASK                      (0x00000001U)
#define CSL_BOOTCFG_NMIGR0_NMIGR0_REG_SHIFT                     (0U)
#define CSL_BOOTCFG_NMIGR0_NMIGR0_REG_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_NMIGR0_NMIGR0_REG_MAX                       (0x00000001U)

#define CSL_BOOTCFG_NMIGR0_RESETVAL                             (0x00000000U)

/* IPCGR0 */

#define CSL_BOOTCFG_IPCGR0_IPCGR0_REG_MASK                      (0x00000001U)
#define CSL_BOOTCFG_IPCGR0_IPCGR0_REG_SHIFT                     (0U)
#define CSL_BOOTCFG_IPCGR0_IPCGR0_REG_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_IPCGR0_IPCGR0_REG_MAX                       (0x00000001U)

#define CSL_BOOTCFG_IPCGR0_IPCGR0_SRC_MASK                      (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCGR0_IPCGR0_SRC_SHIFT                     (4U)
#define CSL_BOOTCFG_IPCGR0_IPCGR0_SRC_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_IPCGR0_IPCGR0_SRC_MAX                       (0x0fffffffU)

#define CSL_BOOTCFG_IPCGR0_RESETVAL                             (0x00000000U)

/* IPCGR8 */

#define CSL_BOOTCFG_IPCGR8_IPCGR8_REG_MASK                      (0x00000001U)
#define CSL_BOOTCFG_IPCGR8_IPCGR8_REG_SHIFT                     (0U)
#define CSL_BOOTCFG_IPCGR8_IPCGR8_REG_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_IPCGR8_IPCGR8_REG_MAX                       (0x00000001U)

#define CSL_BOOTCFG_IPCGR8_IPCGR8_SRC_MASK                      (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCGR8_IPCGR8_SRC_SHIFT                     (4U)
#define CSL_BOOTCFG_IPCGR8_IPCGR8_SRC_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_IPCGR8_IPCGR8_SRC_MAX                       (0x0fffffffU)

#define CSL_BOOTCFG_IPCGR8_RESETVAL                             (0x00000000U)

/* IPCGR11_12 */

#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_REG_MASK              (0x00000001U)
#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_REG_SHIFT             (0U)
#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_REG_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_REG_MAX               (0x00000001U)

#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_SRC_MASK              (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_SRC_SHIFT             (4U)
#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_SRC_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_IPCGR11_12_IPCGR11_12_SRC_MAX               (0x0fffffffU)

#define CSL_BOOTCFG_IPCGR11_12_RESETVAL                         (0x00000000U)

/* IPCGR13_14 */

#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_REG_MASK              (0x00000001U)
#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_REG_SHIFT             (0U)
#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_REG_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_REG_MAX               (0x00000001U)

#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_SRC_MASK              (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_SRC_SHIFT             (4U)
#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_SRC_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_IPCGR13_14_IPCGR13_14_SRC_MAX               (0x0fffffffU)

#define CSL_BOOTCFG_IPCGR13_14_RESETVAL                         (0x00000000U)

/* IPCGRH */

#define CSL_BOOTCFG_IPCGRH_IPCGRH_REG_MASK                      (0x00000001U)
#define CSL_BOOTCFG_IPCGRH_IPCGRH_REG_SHIFT                     (0U)
#define CSL_BOOTCFG_IPCGRH_IPCGRH_REG_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_IPCGRH_IPCGRH_REG_MAX                       (0x00000001U)

#define CSL_BOOTCFG_IPCGRH_IPCGRH_SRC_MASK                      (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCGRH_IPCGRH_SRC_SHIFT                     (4U)
#define CSL_BOOTCFG_IPCGRH_IPCGRH_SRC_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_IPCGRH_IPCGRH_SRC_MAX                       (0x0fffffffU)

#define CSL_BOOTCFG_IPCGRH_RESETVAL                             (0x00000000U)

/* IPCAR0 */

#define CSL_BOOTCFG_IPCAR0_IPCGR0_SRC_CLR_MASK                  (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCAR0_IPCGR0_SRC_CLR_SHIFT                 (4U)
#define CSL_BOOTCFG_IPCAR0_IPCGR0_SRC_CLR_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_IPCAR0_IPCGR0_SRC_CLR_MAX                   (0x0fffffffU)

#define CSL_BOOTCFG_IPCAR0_RESETVAL                             (0x00000000U)

/* IPCAR8 */

#define CSL_BOOTCFG_IPCAR8_IPCGR8_SRC_CLR_MASK                  (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCAR8_IPCGR8_SRC_CLR_SHIFT                 (4U)
#define CSL_BOOTCFG_IPCAR8_IPCGR8_SRC_CLR_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_IPCAR8_IPCGR8_SRC_CLR_MAX                   (0x0fffffffU)

#define CSL_BOOTCFG_IPCAR8_RESETVAL                             (0x00000000U)

/* IPCAR11_12 */

#define CSL_BOOTCFG_IPCAR11_12_IPCGR11_12_SRC_CLR_MASK          (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCAR11_12_IPCGR11_12_SRC_CLR_SHIFT         (4U)
#define CSL_BOOTCFG_IPCAR11_12_IPCGR11_12_SRC_CLR_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_IPCAR11_12_IPCGR11_12_SRC_CLR_MAX           (0x0fffffffU)

#define CSL_BOOTCFG_IPCAR11_12_RESETVAL                         (0x00000000U)

/* IPCAR13_14 */

#define CSL_BOOTCFG_IPCAR13_14_IPCGR13_14_SRC_CLR_MASK          (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCAR13_14_IPCGR13_14_SRC_CLR_SHIFT         (4U)
#define CSL_BOOTCFG_IPCAR13_14_IPCGR13_14_SRC_CLR_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_IPCAR13_14_IPCGR13_14_SRC_CLR_MAX           (0x0fffffffU)

#define CSL_BOOTCFG_IPCAR13_14_RESETVAL                         (0x00000000U)

/* IPCARH */

#define CSL_BOOTCFG_IPCARH_IPCGRH_SRC_CLR_MASK                  (0xFFFFFFF0U)
#define CSL_BOOTCFG_IPCARH_IPCGRH_SRC_CLR_SHIFT                 (4U)
#define CSL_BOOTCFG_IPCARH_IPCGRH_SRC_CLR_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_IPCARH_IPCGRH_SRC_CLR_MAX                   (0x0fffffffU)

#define CSL_BOOTCFG_IPCARH_RESETVAL                             (0x00000000U)

/* TINPSEL0 */

#define CSL_BOOTCFG_TINPSEL0_TINPLSEL0_MASK                     (0x00000007U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL0_SHIFT                    (0U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL0_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL0_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL0_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPHSEL0_MASK                     (0x00000070U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL0_SHIFT                    (4U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL0_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL0_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL0_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPLSEL1_MASK                     (0x00000700U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL1_SHIFT                    (8U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL1_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL1_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL1_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPHSEL1_MASK                     (0x00007000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL1_SHIFT                    (12U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL1_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL1_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL1_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPLSEL2_MASK                     (0x00070000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL2_SHIFT                    (16U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL2_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL2_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL2_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPHSEL2_MASK                     (0x00700000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL2_SHIFT                    (20U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL2_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL2_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL2_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPLSEL3_MASK                     (0x07000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL3_SHIFT                    (24U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL3_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL3_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPLSEL3_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_TINPHSEL3_MASK                     (0x70000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL3_SHIFT                    (28U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL3_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL3_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL0_TINPHSEL3_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL0_RESETVAL                           (0x10101010U)

/* TINPSEL1 */

#define CSL_BOOTCFG_TINPSEL1_TINPLSEL4_MASK                     (0x00000007U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL4_SHIFT                    (0U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL4_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL4_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL4_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL1_TINPHSEL4_MASK                     (0x00000070U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL4_SHIFT                    (4U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL4_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL4_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL4_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL1_TINPLSEL5_MASK                     (0x00000700U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL5_SHIFT                    (8U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL5_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL5_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL1_TINPLSEL5_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL1_TINPHSEL5_MASK                     (0x00007000U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL5_SHIFT                    (12U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL5_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL5_TIMI0                    (0x00000000U)
#define CSL_BOOTCFG_TINPSEL1_TINPHSEL5_TIMI1                    (0x00000001U)

#define CSL_BOOTCFG_TINPSEL1_RESETVAL                           (0x00001010U)

/* TOUTPSEL0 */

#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL0_MASK                    (0x0000003FU)
#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL0_SHIFT                   (0U)
#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL0_RESETVAL                (0x00000002U)
#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL0_MAX                     (0x0000003fU)

#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL1_MASK                    (0x00003F00U)
#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL1_SHIFT                   (8U)
#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL1_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_TOUTPSEL0_TOUTPSEL1_MAX                     (0x0000003fU)

#define CSL_BOOTCFG_TOUTPSEL0_RESETVAL                          (0x00000302U)

/* RSTMUX0 */

#define CSL_BOOTCFG_RSTMUX0_RSTMUX_LOCK0_MASK                   (0x00000001U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_LOCK0_SHIFT                  (0U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_LOCK0_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_LOCK0_MAX                    (0x00000001U)

#define CSL_BOOTCFG_RSTMUX0_RSTMUX_OMODE0_MASK                  (0x0000000EU)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_OMODE0_SHIFT                 (1U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_OMODE0_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_OMODE0_MAX                   (0x00000007U)

#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0_MASK                 (0x00000010U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0_SHIFT                (4U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0_MAX                  (0x00000001U)

#define CSL_BOOTCFG_RSTMUX0_RSTMUX_DELAY0_MASK                  (0x000000E0U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_DELAY0_SHIFT                 (5U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_DELAY0_RESETVAL              (0x00000004U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_DELAY0_MAX                   (0x00000007U)

#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTATCLR0_MASK              (0x00000200U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTATCLR0_SHIFT             (9U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTATCLR0_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_RSTMUX0_RSTMUX_EVSTATCLR0_MAX               (0x00000001U)

#define CSL_BOOTCFG_RSTMUX0_RESETVAL                            (0x00000080U)

/* RSTMUX8 */

#define CSL_BOOTCFG_RSTMUX8_RSTMUX_LOCK8_MASK                   (0x00000001U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_LOCK8_SHIFT                  (0U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_LOCK8_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_LOCK8_MAX                    (0x00000001U)

#define CSL_BOOTCFG_RSTMUX8_RSTMUX_OMODE8_MASK                  (0x0000000EU)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_OMODE8_SHIFT                 (1U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_OMODE8_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_OMODE8_MAX                   (0x00000007U)

#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTAT8_MASK                 (0x00000010U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTAT8_SHIFT                (4U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTAT8_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTAT8_MAX                  (0x00000001U)

#define CSL_BOOTCFG_RSTMUX8_RSTMUX_DELAY8_MASK                  (0x000000E0U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_DELAY8_SHIFT                 (5U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_DELAY8_RESETVAL              (0x00000004U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_DELAY8_MAX                   (0x00000007U)

#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTATCLR8_MASK              (0x00000200U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTATCLR8_SHIFT             (9U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTATCLR8_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_RSTMUX8_RSTMUX_EVSTATCLR8_MAX               (0x00000001U)

#define CSL_BOOTCFG_RSTMUX8_RESETVAL                            (0x00000080U)

/* MAIN_PLL_CTL0 */

#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLD_MASK                     (0x0000003FU)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLD_SHIFT                    (0U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLD_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLD_MAX                      (0x0000003fU)

#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLM_MASK                     (0x0007F000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLM_SHIFT                    (12U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLM_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_PLLM_MAX                      (0x0000007fU)

#define CSL_BOOTCFG_MAIN_PLL_CTL0_BWADJ_MASK                    (0xFF000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_BWADJ_SHIFT                   (24U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_BWADJ_RESETVAL                (0x00000005U)
#define CSL_BOOTCFG_MAIN_PLL_CTL0_BWADJ_MAX                     (0x000000ffU)

#define CSL_BOOTCFG_MAIN_PLL_CTL0_RESETVAL                      (0x05000000U)

/* MAIN_PLL_CTL1 */

#define CSL_BOOTCFG_MAIN_PLL_CTL1_BWADJ_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_BWADJ_SHIFT                   (0U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_BWADJ_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_BWADJ_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_TEST_MASK                     (0x00000010U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_TEST_SHIFT                    (4U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_TEST_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_TEST_MAX                      (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_FASTEN_MASK                   (0x00000020U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_FASTEN_SHIFT                  (5U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_FASTEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_FASTEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_ENSAT_MASK                    (0x00000040U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_ENSAT_SHIFT                   (6U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_ENSAT_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_ENSAT_MAX                     (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSIG_MASK                (0x00000080U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSIG_SHIFT               (7U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSIG_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSIG_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSEL_MASK                (0x00000100U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSEL_SHIFT               (8U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGEXTSEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTSEL_MASK               (0x00000200U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTSEL_SHIFT              (9U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTSEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTSEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTREP_MASK               (0x00000400U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTREP_SHIFT              (10U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTREP_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTREP_MAX                (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTOUT_MASK               (0x00000800U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTOUT_SHIFT              (11U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTOUT_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTOUT_MAX                (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTDRV_MASK               (0x00001000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTDRV_SHIFT              (12U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTDRV_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MAIN_PLL_CTL1_REGTESTDRV_MAX                (0x00000001U)

#define CSL_BOOTCFG_MAIN_PLL_CTL1_RESETVAL                      (0x00000040U)

/* NSS_PLL_CTL0 */

#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLD_MASK                      (0x0000003FU)
#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLD_SHIFT                     (0U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLD_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLD_MAX                       (0x0000003fU)

#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLM_MASK                      (0x0007FFC0U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLM_SHIFT                     (6U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLM_RESETVAL                  (0x00000013U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_PLLM_MAX                       (0x00001fffU)

#define CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_MASK                     (0x00780000U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_SHIFT                    (19U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_NSS_PLL_CTL0_BYPASS_MASK                    (0x00800000U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_BYPASS_SHIFT                   (23U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_BYPASS_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_BYPASS_MAX                     (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL0_BWADJ_MASK                     (0xFF000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_BWADJ_SHIFT                    (24U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_BWADJ_RESETVAL                 (0x00000009U)
#define CSL_BOOTCFG_NSS_PLL_CTL0_BWADJ_MAX                      (0x000000ffU)

#define CSL_BOOTCFG_NSS_PLL_CTL0_RESETVAL                       (0x098804c0U)

/* NSS_PLL_CTL1 */

#define CSL_BOOTCFG_NSS_PLL_CTL1_BWADJ_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_NSS_PLL_CTL1_BWADJ_SHIFT                    (0U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_BWADJ_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_BWADJ_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_NSS_PLL_CTL1_TEST_MASK                      (0x00000010U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_TEST_SHIFT                     (4U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_TEST_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_TEST_MAX                       (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_FASTEN_MASK                    (0x00000020U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_FASTEN_SHIFT                   (5U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_FASTEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_FASTEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_ENSAT_MASK                     (0x00000040U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_ENSAT_SHIFT                    (6U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_ENSAT_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_ENSAT_MAX                      (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSIG_MASK                 (0x00000080U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSIG_SHIFT                (7U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSIG_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSIG_MAX                  (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSEL_MASK                 (0x00000100U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSEL_SHIFT                (8U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGEXTSEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTSEL_MASK                (0x00000200U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTSEL_SHIFT               (9U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTSEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTSEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTREP_MASK                (0x00000400U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTREP_SHIFT               (10U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTREP_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTREP_MAX                 (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTOUT_MASK                (0x00000800U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTOUT_SHIFT               (11U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTOUT_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTOUT_MAX                 (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTDRV_MASK                (0x00001000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTDRV_SHIFT               (12U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTDRV_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_REGTESTDRV_MAX                 (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLSEL_MASK                    (0x00002000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLSEL_SHIFT                   (13U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLSEL_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLSEL_MAX                     (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLRST_MASK                    (0x00004000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLRST_SHIFT                   (14U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLRST_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_PLLRST_MAX                     (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_INT_BYPASS_MASK                (0x00008000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_INT_BYPASS_SHIFT               (15U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_INT_BYPASS_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_NSS_PLL_CTL1_INT_BYPASS_MAX                 (0x00000001U)

#define CSL_BOOTCFG_NSS_PLL_CTL1_RESETVAL                       (0x00000040U)

/* DDR3A_PLL_CTL0 */

#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLD_MASK                    (0x0000003FU)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLD_SHIFT                   (0U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLD_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLD_MAX                     (0x0000003fU)

#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLM_MASK                    (0x0007FFC0U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLM_SHIFT                   (6U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLM_RESETVAL                (0x00000013U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_PLLM_MAX                     (0x00001fffU)

#define CSL_BOOTCFG_DDR3A_PLL_CTL0_CLKOD_MASK                   (0x00780000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_CLKOD_SHIFT                  (19U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_CLKOD_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_CLKOD_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BYPASS_MASK                  (0x00800000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BYPASS_SHIFT                 (23U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BYPASS_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BYPASS_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BWADJ_MASK                   (0xFF000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BWADJ_SHIFT                  (24U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BWADJ_RESETVAL               (0x00000009U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL0_BWADJ_MAX                    (0x000000ffU)

#define CSL_BOOTCFG_DDR3A_PLL_CTL0_RESETVAL                     (0x098804c0U)

/* DDR3A_PLL_CTL1 */

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_BWADJ_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_BWADJ_SHIFT                  (0U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_BWADJ_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_BWADJ_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_TEST_MASK                    (0x00000010U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_TEST_SHIFT                   (4U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_TEST_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_TEST_MAX                     (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_FASTEN_MASK                  (0x00000020U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_FASTEN_SHIFT                 (5U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_FASTEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_FASTEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_ENSAT_MASK                   (0x00000040U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_ENSAT_SHIFT                  (6U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_ENSAT_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_ENSAT_MAX                    (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSIG_MASK               (0x00000080U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSIG_SHIFT              (7U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSIG_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSIG_MAX                (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSEL_MASK               (0x00000100U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSEL_SHIFT              (8U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGEXTSEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTSEL_MASK              (0x00000200U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTSEL_SHIFT             (9U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTSEL_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTSEL_MAX               (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTREP_MASK              (0x00000400U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTREP_SHIFT             (10U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTREP_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTREP_MAX               (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTOUT_MASK              (0x00000800U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTOUT_SHIFT             (11U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTOUT_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTOUT_MAX               (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTDRV_MASK              (0x00001000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTDRV_SHIFT             (12U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTDRV_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_REGTESTDRV_MAX               (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_PLLRST_MASK                  (0x00004000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_PLLRST_SHIFT                 (14U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_PLLRST_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_PLLRST_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_INT_BYPASS_MASK              (0x00008000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_INT_BYPASS_SHIFT             (15U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_INT_BYPASS_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_INT_BYPASS_MAX               (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST_MASK           (0x80000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST_SHIFT          (31U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST_MAX            (0x00000001U)

#define CSL_BOOTCFG_DDR3A_PLL_CTL1_RESETVAL                     (0x00000040U)

/* ARM_PLL_CTL0 */

#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLD_MASK                      (0x0000003FU)
#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLD_SHIFT                     (0U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLD_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLD_MAX                       (0x0000003fU)

#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLM_MASK                      (0x0007FFC0U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLM_SHIFT                     (6U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLM_RESETVAL                  (0x00000013U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_PLLM_MAX                       (0x00001fffU)

#define CSL_BOOTCFG_ARM_PLL_CTL0_CLKOD_MASK                     (0x00780000U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_CLKOD_SHIFT                    (19U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_CLKOD_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_CLKOD_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_ARM_PLL_CTL0_BYPASS_MASK                    (0x00800000U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_BYPASS_SHIFT                   (23U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_BYPASS_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_BYPASS_MAX                     (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL0_BWADJ_MASK                     (0xFF000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_BWADJ_SHIFT                    (24U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_BWADJ_RESETVAL                 (0x00000009U)
#define CSL_BOOTCFG_ARM_PLL_CTL0_BWADJ_MAX                      (0x000000ffU)

#define CSL_BOOTCFG_ARM_PLL_CTL0_RESETVAL                       (0x098804c0U)

/* ARM_PLL_CTL1 */

#define CSL_BOOTCFG_ARM_PLL_CTL1_BWADJ_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_ARM_PLL_CTL1_BWADJ_SHIFT                    (0U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_BWADJ_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_BWADJ_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_ARM_PLL_CTL1_TEST_MASK                      (0x00000010U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_TEST_SHIFT                     (4U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_TEST_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_TEST_MAX                       (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_FASTEN_MASK                    (0x00000020U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_FASTEN_SHIFT                   (5U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_FASTEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_FASTEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_ENSAT_MASK                     (0x00000040U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_ENSAT_SHIFT                    (6U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_ENSAT_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_ENSAT_MAX                      (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSIG_MASK                 (0x00000080U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSIG_SHIFT                (7U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSIG_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSIG_MAX                  (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSEL_MASK                 (0x00000100U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSEL_SHIFT                (8U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGEXTSEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTSEL_MASK                (0x00000200U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTSEL_SHIFT               (9U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTSEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTSEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTREP_MASK                (0x00000400U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTREP_SHIFT               (10U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTREP_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTREP_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTOUT_MASK                (0x00000800U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTOUT_SHIFT               (11U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTOUT_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTOUT_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTDRV_MASK                (0x00001000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTDRV_SHIFT               (12U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTDRV_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_REGTESTDRV_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_PLLRST_MASK                    (0x00004000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_PLLRST_SHIFT                   (14U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_PLLRST_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_PLLRST_MAX                     (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_INT_BYPASS_MASK                (0x00008000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_INT_BYPASS_SHIFT               (15U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_INT_BYPASS_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ARM_PLL_CTL1_INT_BYPASS_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ARM_PLL_CTL1_RESETVAL                       (0x00000040U)

/* DSS_PLL_CTL0 */

#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLD_MASK                      (0x0000003FU)
#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLD_SHIFT                     (0U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLD_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLD_MAX                       (0x0000003fU)

#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLM_MASK                      (0x0007FFC0U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLM_SHIFT                     (6U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLM_RESETVAL                  (0x00000013U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_PLLM_MAX                       (0x00001fffU)

#define CSL_BOOTCFG_DSS_PLL_CTL0_CLKOD_MASK                     (0x00780000U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_CLKOD_SHIFT                    (19U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_CLKOD_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_CLKOD_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_DSS_PLL_CTL0_BYPASS_MASK                    (0x00800000U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_BYPASS_SHIFT                   (23U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_BYPASS_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_BYPASS_MAX                     (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL0_BWADJ_MASK                     (0xFF000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_BWADJ_SHIFT                    (24U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_BWADJ_RESETVAL                 (0x00000009U)
#define CSL_BOOTCFG_DSS_PLL_CTL0_BWADJ_MAX                      (0x000000ffU)

#define CSL_BOOTCFG_DSS_PLL_CTL0_RESETVAL                       (0x098804c0U)

/* DSS_PLL_CTL1 */

#define CSL_BOOTCFG_DSS_PLL_CTL1_BWADJ_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_DSS_PLL_CTL1_BWADJ_SHIFT                    (0U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_BWADJ_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_BWADJ_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_DSS_PLL_CTL1_TEST_MASK                      (0x00000010U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_TEST_SHIFT                     (4U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_TEST_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_TEST_MAX                       (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_FASTEN_MASK                    (0x00000020U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_FASTEN_SHIFT                   (5U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_FASTEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_FASTEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_ENSAT_MASK                     (0x00000040U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_ENSAT_SHIFT                    (6U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_ENSAT_RESETVAL                 (0x00000001U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_ENSAT_MAX                      (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSIG_MASK                 (0x00000080U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSIG_SHIFT                (7U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSIG_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSIG_MAX                  (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSEL_MASK                 (0x00000100U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSEL_SHIFT                (8U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGEXTSEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTSEL_MASK                (0x00000200U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTSEL_SHIFT               (9U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTSEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTSEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTREP_MASK                (0x00000400U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTREP_SHIFT               (10U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTREP_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTREP_MAX                 (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTOUT_MASK                (0x00000800U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTOUT_SHIFT               (11U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTOUT_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTOUT_MAX                 (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTDRV_MASK                (0x00001000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTDRV_SHIFT               (12U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTDRV_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_REGTESTDRV_MAX                 (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLSEL_MASK                    (0x00002000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLSEL_SHIFT                   (13U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLSEL_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLSEL_MAX                     (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLRST_MASK                    (0x00004000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLRST_SHIFT                   (14U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLRST_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_PLLRST_MAX                     (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_INT_BYPASS_MASK                (0x00008000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_INT_BYPASS_SHIFT               (15U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_INT_BYPASS_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_DSS_PLL_CTL1_INT_BYPASS_MAX                 (0x00000001U)

#define CSL_BOOTCFG_DSS_PLL_CTL1_RESETVAL                       (0x00000040U)

/* ICSS_PLL_CTL0 */

#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLD_MASK                     (0x0000003FU)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLD_SHIFT                    (0U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLD_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLD_MAX                      (0x0000003fU)

#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLM_MASK                     (0x0007FFC0U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLM_SHIFT                    (6U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLM_RESETVAL                 (0x00000013U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_PLLM_MAX                      (0x00001fffU)

#define CSL_BOOTCFG_ICSS_PLL_CTL0_CLKOD_MASK                    (0x00780000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_CLKOD_SHIFT                   (19U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_CLKOD_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_CLKOD_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_ICSS_PLL_CTL0_BYPASS_MASK                   (0x00800000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_BYPASS_SHIFT                  (23U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_BYPASS_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_BYPASS_MAX                    (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL0_BWADJ_MASK                    (0xFF000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_BWADJ_SHIFT                   (24U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_BWADJ_RESETVAL                (0x00000009U)
#define CSL_BOOTCFG_ICSS_PLL_CTL0_BWADJ_MAX                     (0x000000ffU)

#define CSL_BOOTCFG_ICSS_PLL_CTL0_RESETVAL                      (0x098804c0U)

/* ICSS_PLL_CTL1 */

#define CSL_BOOTCFG_ICSS_PLL_CTL1_BWADJ_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_BWADJ_SHIFT                   (0U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_BWADJ_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_BWADJ_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_TEST_MASK                     (0x00000010U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_TEST_SHIFT                    (4U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_TEST_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_TEST_MAX                      (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_FASTEN_MASK                   (0x00000020U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_FASTEN_SHIFT                  (5U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_FASTEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_FASTEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_ENSAT_MASK                    (0x00000040U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_ENSAT_SHIFT                   (6U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_ENSAT_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_ENSAT_MAX                     (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSIG_MASK                (0x00000080U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSIG_SHIFT               (7U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSIG_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSIG_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSEL_MASK                (0x00000100U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSEL_SHIFT               (8U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGEXTSEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTSEL_MASK               (0x00000200U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTSEL_SHIFT              (9U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTSEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTSEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTREP_MASK               (0x00000400U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTREP_SHIFT              (10U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTREP_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTREP_MAX                (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTOUT_MASK               (0x00000800U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTOUT_SHIFT              (11U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTOUT_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTOUT_MAX                (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTDRV_MASK               (0x00001000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTDRV_SHIFT              (12U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTDRV_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_REGTESTDRV_MAX                (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLSEL_MASK                   (0x00002000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLSEL_SHIFT                  (13U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLSEL_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLSEL_MAX                    (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLRST_MASK                   (0x00004000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLRST_SHIFT                  (14U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLRST_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_PLLRST_MAX                    (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_INT_BYPASS_MASK               (0x00008000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_INT_BYPASS_SHIFT              (15U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_INT_BYPASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_ICSS_PLL_CTL1_INT_BYPASS_MAX                (0x00000001U)

#define CSL_BOOTCFG_ICSS_PLL_CTL1_RESETVAL                      (0x00000040U)

/* UART_PLL_CTL0 */

#define CSL_BOOTCFG_UART_PLL_CTL0_PLLD_MASK                     (0x0000003FU)
#define CSL_BOOTCFG_UART_PLL_CTL0_PLLD_SHIFT                    (0U)
#define CSL_BOOTCFG_UART_PLL_CTL0_PLLD_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL0_PLLD_MAX                      (0x0000003fU)

#define CSL_BOOTCFG_UART_PLL_CTL0_PLLM_MASK                     (0x0007FFC0U)
#define CSL_BOOTCFG_UART_PLL_CTL0_PLLM_SHIFT                    (6U)
#define CSL_BOOTCFG_UART_PLL_CTL0_PLLM_RESETVAL                 (0x00000013U)
#define CSL_BOOTCFG_UART_PLL_CTL0_PLLM_MAX                      (0x00001fffU)

#define CSL_BOOTCFG_UART_PLL_CTL0_CLKOD_MASK                    (0x00780000U)
#define CSL_BOOTCFG_UART_PLL_CTL0_CLKOD_SHIFT                   (19U)
#define CSL_BOOTCFG_UART_PLL_CTL0_CLKOD_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_UART_PLL_CTL0_CLKOD_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_UART_PLL_CTL0_BYPASS_MASK                   (0x00800000U)
#define CSL_BOOTCFG_UART_PLL_CTL0_BYPASS_SHIFT                  (23U)
#define CSL_BOOTCFG_UART_PLL_CTL0_BYPASS_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_UART_PLL_CTL0_BYPASS_MAX                    (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL0_BWADJ_MASK                    (0xFF000000U)
#define CSL_BOOTCFG_UART_PLL_CTL0_BWADJ_SHIFT                   (24U)
#define CSL_BOOTCFG_UART_PLL_CTL0_BWADJ_RESETVAL                (0x00000009U)
#define CSL_BOOTCFG_UART_PLL_CTL0_BWADJ_MAX                     (0x000000ffU)

#define CSL_BOOTCFG_UART_PLL_CTL0_RESETVAL                      (0x098804c0U)

/* UART_PLL_CTL1 */

#define CSL_BOOTCFG_UART_PLL_CTL1_BWADJ_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_UART_PLL_CTL1_BWADJ_SHIFT                   (0U)
#define CSL_BOOTCFG_UART_PLL_CTL1_BWADJ_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_BWADJ_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_UART_PLL_CTL1_TEST_MASK                     (0x00000010U)
#define CSL_BOOTCFG_UART_PLL_CTL1_TEST_SHIFT                    (4U)
#define CSL_BOOTCFG_UART_PLL_CTL1_TEST_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_TEST_MAX                      (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_FASTEN_MASK                   (0x00000020U)
#define CSL_BOOTCFG_UART_PLL_CTL1_FASTEN_SHIFT                  (5U)
#define CSL_BOOTCFG_UART_PLL_CTL1_FASTEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_FASTEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_ENSAT_MASK                    (0x00000040U)
#define CSL_BOOTCFG_UART_PLL_CTL1_ENSAT_SHIFT                   (6U)
#define CSL_BOOTCFG_UART_PLL_CTL1_ENSAT_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_UART_PLL_CTL1_ENSAT_MAX                     (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSIG_MASK                (0x00000080U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSIG_SHIFT               (7U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSIG_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSIG_MAX                 (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSEL_MASK                (0x00000100U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSEL_SHIFT               (8U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGEXTSEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTSEL_MASK               (0x00000200U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTSEL_SHIFT              (9U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTSEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTSEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTREP_MASK               (0x00000400U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTREP_SHIFT              (10U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTREP_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTREP_MAX                (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTOUT_MASK               (0x00000800U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTOUT_SHIFT              (11U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTOUT_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTOUT_MAX                (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTDRV_MASK               (0x00001000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTDRV_SHIFT              (12U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTDRV_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_REGTESTDRV_MAX                (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_PLLRST_MASK                   (0x00004000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_PLLRST_SHIFT                  (14U)
#define CSL_BOOTCFG_UART_PLL_CTL1_PLLRST_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_PLLRST_MAX                    (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_INT_BYPASS_MASK               (0x00008000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_INT_BYPASS_SHIFT              (15U)
#define CSL_BOOTCFG_UART_PLL_CTL1_INT_BYPASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_UART_PLL_CTL1_INT_BYPASS_MAX                (0x00000001U)

#define CSL_BOOTCFG_UART_PLL_CTL1_RESETVAL                      (0x00000040U)

/* ARMENDIAN_CFG0_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG0_0_ARMENDIAN_CFG0_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_0_ARMENDIAN_CFG0_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_0_ARMENDIAN_CFG0_ADDR_RESETVAL  (0x000001c0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_0_ARMENDIAN_CFG0_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG0_0_RESETVAL                   (0x0001c000U)

/* ARMENDIAN_CFG0_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG0_1_ARMENDIAN_CFG0_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_1_ARMENDIAN_CFG0_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_1_ARMENDIAN_CFG0_SIZE_RESETVAL  (0x00000006U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_1_ARMENDIAN_CFG0_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG0_1_RESETVAL                   (0x00000006U)

/* ARMENDIAN_CFG0_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG0_2_ARMENDIAN_CFG0_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_2_ARMENDIAN_CFG0_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_2_ARMENDIAN_CFG0_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG0_2_ARMENDIAN_CFG0_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG0_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG1_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG1_0_ARMENDIAN_CFG1_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_0_ARMENDIAN_CFG1_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_0_ARMENDIAN_CFG1_ADDR_RESETVAL  (0x00000200U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_0_ARMENDIAN_CFG1_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG1_0_RESETVAL                   (0x00020000U)

/* ARMENDIAN_CFG1_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG1_1_ARMENDIAN_CFG1_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_1_ARMENDIAN_CFG1_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_1_ARMENDIAN_CFG1_SIZE_RESETVAL  (0x00000009U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_1_ARMENDIAN_CFG1_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG1_1_RESETVAL                   (0x00000009U)

/* ARMENDIAN_CFG1_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG1_2_ARMENDIAN_CFG1_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_2_ARMENDIAN_CFG1_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_2_ARMENDIAN_CFG1_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG1_2_ARMENDIAN_CFG1_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG1_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG2_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG2_0_ARMENDIAN_CFG2_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_0_ARMENDIAN_CFG2_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_0_ARMENDIAN_CFG2_ADDR_RESETVAL  (0x00000bc0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_0_ARMENDIAN_CFG2_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG2_0_RESETVAL                   (0x000bc000U)

/* ARMENDIAN_CFG2_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG2_1_ARMENDIAN_CFG2_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_1_ARMENDIAN_CFG2_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_1_ARMENDIAN_CFG2_SIZE_RESETVAL  (0x00000004U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_1_ARMENDIAN_CFG2_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG2_1_RESETVAL                   (0x00000004U)

/* ARMENDIAN_CFG2_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG2_2_ARMENDIAN_CFG2_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_2_ARMENDIAN_CFG2_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_2_ARMENDIAN_CFG2_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG2_2_ARMENDIAN_CFG2_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG2_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG3_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG3_0_ARMENDIAN_CFG3_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_0_ARMENDIAN_CFG3_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_0_ARMENDIAN_CFG3_ADDR_RESETVAL  (0x00002100U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_0_ARMENDIAN_CFG3_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG3_0_RESETVAL                   (0x00210000U)

/* ARMENDIAN_CFG3_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG3_1_ARMENDIAN_CFG3_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_1_ARMENDIAN_CFG3_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_1_ARMENDIAN_CFG3_SIZE_RESETVAL  (0x00000008U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_1_ARMENDIAN_CFG3_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG3_1_RESETVAL                   (0x00000008U)

/* ARMENDIAN_CFG3_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG3_2_ARMENDIAN_CFG3_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_2_ARMENDIAN_CFG3_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_2_ARMENDIAN_CFG3_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG3_2_ARMENDIAN_CFG3_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG3_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG4_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG4_0_ARMENDIAN_CFG4_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_0_ARMENDIAN_CFG4_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_0_ARMENDIAN_CFG4_ADDR_RESETVAL  (0x0000023aU)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_0_ARMENDIAN_CFG4_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG4_0_RESETVAL                   (0x00023a00U)

/* ARMENDIAN_CFG4_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG4_1_ARMENDIAN_CFG4_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_1_ARMENDIAN_CFG4_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_1_ARMENDIAN_CFG4_SIZE_RESETVAL  (0x00000005U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_1_ARMENDIAN_CFG4_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG4_1_RESETVAL                   (0x00000005U)

/* ARMENDIAN_CFG4_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG4_2_ARMENDIAN_CFG4_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_2_ARMENDIAN_CFG4_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_2_ARMENDIAN_CFG4_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG4_2_ARMENDIAN_CFG4_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG4_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG5_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG5_0_ARMENDIAN_CFG5_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_0_ARMENDIAN_CFG5_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_0_ARMENDIAN_CFG5_ADDR_RESETVAL  (0x00002400U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_0_ARMENDIAN_CFG5_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG5_0_RESETVAL                   (0x00240000U)

/* ARMENDIAN_CFG5_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG5_1_ARMENDIAN_CFG5_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_1_ARMENDIAN_CFG5_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_1_ARMENDIAN_CFG5_SIZE_RESETVAL  (0x00000006U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_1_ARMENDIAN_CFG5_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG5_1_RESETVAL                   (0x00000006U)

/* ARMENDIAN_CFG5_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG5_2_ARMENDIAN_CFG5_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_2_ARMENDIAN_CFG5_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_2_ARMENDIAN_CFG5_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG5_2_ARMENDIAN_CFG5_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG5_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG6_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG6_0_ARMENDIAN_CFG6_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_0_ARMENDIAN_CFG6_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_0_ARMENDIAN_CFG6_ADDR_RESETVAL  (0x00010000U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_0_ARMENDIAN_CFG6_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG6_0_RESETVAL                   (0x01000000U)

/* ARMENDIAN_CFG6_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG6_1_ARMENDIAN_CFG6_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_1_ARMENDIAN_CFG6_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_1_ARMENDIAN_CFG6_SIZE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_1_ARMENDIAN_CFG6_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG6_1_RESETVAL                   (0x00000000U)

/* ARMENDIAN_CFG6_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG6_2_ARMENDIAN_CFG6_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_2_ARMENDIAN_CFG6_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_2_ARMENDIAN_CFG6_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG6_2_ARMENDIAN_CFG6_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG6_2_RESETVAL                   (0x00000001U)

/* ARMENDIAN_CFG7_0 */

#define CSL_BOOTCFG_ARMENDIAN_CFG7_0_ARMENDIAN_CFG7_ADDR_MASK   (0xFFFFFF00U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_0_ARMENDIAN_CFG7_ADDR_SHIFT  (8U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_0_ARMENDIAN_CFG7_ADDR_RESETVAL  (0x00ffffffU)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_0_ARMENDIAN_CFG7_ADDR_MAX    (0x00ffffffU)

#define CSL_BOOTCFG_ARMENDIAN_CFG7_0_RESETVAL                   (0xffffff00U)

/* ARMENDIAN_CFG7_1 */

#define CSL_BOOTCFG_ARMENDIAN_CFG7_1_ARMENDIAN_CFG7_SIZE_MASK   (0x0000000FU)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_1_ARMENDIAN_CFG7_SIZE_SHIFT  (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_1_ARMENDIAN_CFG7_SIZE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_1_ARMENDIAN_CFG7_SIZE_MAX    (0x0000000fU)

#define CSL_BOOTCFG_ARMENDIAN_CFG7_1_RESETVAL                   (0x00000000U)

/* ARMENDIAN_CFG7_2 */

#define CSL_BOOTCFG_ARMENDIAN_CFG7_2_ARMENDIAN_CFG7_DIS_MASK    (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_2_ARMENDIAN_CFG7_DIS_SHIFT   (0U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_2_ARMENDIAN_CFG7_DIS_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_ARMENDIAN_CFG7_2_ARMENDIAN_CFG7_DIS_MAX     (0x00000001U)

#define CSL_BOOTCFG_ARMENDIAN_CFG7_2_RESETVAL                   (0x00000001U)

/* ARMTBR_TRB0_W0 */

#define CSL_BOOTCFG_ARMTBR_TRB0_W0_ARMTBR_TRB0_W0_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB0_W0_ARMTBR_TRB0_W0_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W0_ARMTBR_TRB0_W0_RESETVAL      (0x20700000U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W0_ARMTBR_TRB0_W0_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB0_W0_RESETVAL                     (0x20700000U)

/* ARMTBR_TRB0_W1 */

#define CSL_BOOTCFG_ARMTBR_TRB0_W1_ARMTBR_TRB0_W1_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB0_W1_ARMTBR_TRB0_W1_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W1_ARMTBR_TRB0_W1_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W1_ARMTBR_TRB0_W1_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB0_W1_RESETVAL                     (0x00000000U)

/* ARMTBR_TRB0_W2 */

#define CSL_BOOTCFG_ARMTBR_TRB0_W2_ARMTBR_TRB0_W2_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB0_W2_ARMTBR_TRB0_W2_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W2_ARMTBR_TRB0_W2_RESETVAL      (0x00003c00U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W2_ARMTBR_TRB0_W2_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB0_W2_RESETVAL                     (0x00003c00U)

/* ARMTBR_TRB0_W3 */

#define CSL_BOOTCFG_ARMTBR_TRB0_W3_ARMTBR_TRB0_W3_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB0_W3_ARMTBR_TRB0_W3_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W3_ARMTBR_TRB0_W3_RESETVAL      (0x00000011U)
#define CSL_BOOTCFG_ARMTBR_TRB0_W3_ARMTBR_TRB0_W3_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB0_W3_RESETVAL                     (0x00000011U)

/* ARMTBR_TRB1_W0 */

#define CSL_BOOTCFG_ARMTBR_TRB1_W0_ARMTBR_TRB1_W0_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB1_W0_ARMTBR_TRB1_W0_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W0_ARMTBR_TRB1_W0_RESETVAL      (0x20700000U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W0_ARMTBR_TRB1_W0_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB1_W0_RESETVAL                     (0x20700000U)

/* ARMTBR_TRB1_W1 */

#define CSL_BOOTCFG_ARMTBR_TRB1_W1_ARMTBR_TRB1_W1_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB1_W1_ARMTBR_TRB1_W1_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W1_ARMTBR_TRB1_W1_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W1_ARMTBR_TRB1_W1_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB1_W1_RESETVAL                     (0x00000000U)

/* ARMTBR_TRB1_W2 */

#define CSL_BOOTCFG_ARMTBR_TRB1_W2_ARMTBR_TRB1_W2_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB1_W2_ARMTBR_TRB1_W2_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W2_ARMTBR_TRB1_W2_RESETVAL      (0x00003c00U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W2_ARMTBR_TRB1_W2_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB1_W2_RESETVAL                     (0x00003c00U)

/* ARMTBR_TRB1_W3 */

#define CSL_BOOTCFG_ARMTBR_TRB1_W3_ARMTBR_TRB1_W3_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB1_W3_ARMTBR_TRB1_W3_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W3_ARMTBR_TRB1_W3_RESETVAL      (0x00000011U)
#define CSL_BOOTCFG_ARMTBR_TRB1_W3_ARMTBR_TRB1_W3_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB1_W3_RESETVAL                     (0x00000011U)

/* ARMTBR_TRB2_W0 */

#define CSL_BOOTCFG_ARMTBR_TRB2_W0_ARMTBR_TRB2_W0_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB2_W0_ARMTBR_TRB2_W0_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W0_ARMTBR_TRB2_W0_RESETVAL      (0x026204c0U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W0_ARMTBR_TRB2_W0_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB2_W0_RESETVAL                     (0x026204c0U)

/* ARMTBR_TRB2_W1 */

#define CSL_BOOTCFG_ARMTBR_TRB2_W1_ARMTBR_TRB2_W1_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB2_W1_ARMTBR_TRB2_W1_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W1_ARMTBR_TRB2_W1_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W1_ARMTBR_TRB2_W1_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB2_W1_RESETVAL                     (0x00000000U)

/* ARMTBR_TRB2_W2 */

#define CSL_BOOTCFG_ARMTBR_TRB2_W2_ARMTBR_TRB2_W2_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB2_W2_ARMTBR_TRB2_W2_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W2_ARMTBR_TRB2_W2_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W2_ARMTBR_TRB2_W2_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB2_W2_RESETVAL                     (0x00000000U)

/* ARMTBR_TRB2_W3 */

#define CSL_BOOTCFG_ARMTBR_TRB2_W3_ARMTBR_TRB2_W3_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_TRB2_W3_ARMTBR_TRB2_W3_SHIFT         (0U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W3_ARMTBR_TRB2_W3_RESETVAL      (0x00000081U)
#define CSL_BOOTCFG_ARMTBR_TRB2_W3_ARMTBR_TRB2_W3_MAX           (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_TRB2_W3_RESETVAL                     (0x00000081U)

/* ARMTBR_SHDW_TRB0_W0 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W0_ARMTBR_SHDW_TRB0_W0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W0_ARMTBR_SHDW_TRB0_W0_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W0_ARMTBR_SHDW_TRB0_W0_RESETVAL  (0x20700000U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W0_ARMTBR_SHDW_TRB0_W0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W0_RESETVAL                (0x20700000U)

/* ARMTBR_SHDW_TRB0_W1 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W1_ARMTBR_SHDW_TRB0_W1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W1_ARMTBR_SHDW_TRB0_W1_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W1_ARMTBR_SHDW_TRB0_W1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W1_ARMTBR_SHDW_TRB0_W1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W1_RESETVAL                (0x00000000U)

/* ARMTBR_SHDW_TRB0_W2 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W2_ARMTBR_SHDW_TRB0_W2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W2_ARMTBR_SHDW_TRB0_W2_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W2_ARMTBR_SHDW_TRB0_W2_RESETVAL  (0x00003c00U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W2_ARMTBR_SHDW_TRB0_W2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W2_RESETVAL                (0x00003c00U)

/* ARMTBR_SHDW_TRB0_W3 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W3_ARMTBR_SHDW_TRB0_W3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W3_ARMTBR_SHDW_TRB0_W3_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W3_ARMTBR_SHDW_TRB0_W3_RESETVAL  (0x00000011U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W3_ARMTBR_SHDW_TRB0_W3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB0_W3_RESETVAL                (0x00000011U)

/* ARMTBR_SHDW_TRB1_W0 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W0_ARMTBR_SHDW_TRB1_W0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W0_ARMTBR_SHDW_TRB1_W0_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W0_ARMTBR_SHDW_TRB1_W0_RESETVAL  (0x20700000U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W0_ARMTBR_SHDW_TRB1_W0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W0_RESETVAL                (0x20700000U)

/* ARMTBR_SHDW_TRB1_W1 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W1_ARMTBR_SHDW_TRB1_W1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W1_ARMTBR_SHDW_TRB1_W1_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W1_ARMTBR_SHDW_TRB1_W1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W1_ARMTBR_SHDW_TRB1_W1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W1_RESETVAL                (0x00000000U)

/* ARMTBR_SHDW_TRB1_W2 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W2_ARMTBR_SHDW_TRB1_W2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W2_ARMTBR_SHDW_TRB1_W2_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W2_ARMTBR_SHDW_TRB1_W2_RESETVAL  (0x00003c00U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W2_ARMTBR_SHDW_TRB1_W2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W2_RESETVAL                (0x00003c00U)

/* ARMTBR_SHDW_TRB1_W3 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W3_ARMTBR_SHDW_TRB1_W3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W3_ARMTBR_SHDW_TRB1_W3_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W3_ARMTBR_SHDW_TRB1_W3_RESETVAL  (0x00000011U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W3_ARMTBR_SHDW_TRB1_W3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB1_W3_RESETVAL                (0x00000011U)

/* ARMTBR_SHDW_TRB2_W0 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W0_ARMTBR_SHDW_TRB2_W0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W0_ARMTBR_SHDW_TRB2_W0_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W0_ARMTBR_SHDW_TRB2_W0_RESETVAL  (0x026204c0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W0_ARMTBR_SHDW_TRB2_W0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W0_RESETVAL                (0x026204c0U)

/* ARMTBR_SHDW_TRB2_W1 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W1_ARMTBR_SHDW_TRB2_W1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W1_ARMTBR_SHDW_TRB2_W1_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W1_ARMTBR_SHDW_TRB2_W1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W1_ARMTBR_SHDW_TRB2_W1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W1_RESETVAL                (0x00000000U)

/* ARMTBR_SHDW_TRB2_W2 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W2_ARMTBR_SHDW_TRB2_W2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W2_ARMTBR_SHDW_TRB2_W2_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W2_ARMTBR_SHDW_TRB2_W2_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W2_ARMTBR_SHDW_TRB2_W2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W2_RESETVAL                (0x00000000U)

/* ARMTBR_SHDW_TRB2_W3 */

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W3_ARMTBR_SHDW_TRB2_W3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W3_ARMTBR_SHDW_TRB2_W3_SHIFT  (0U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W3_ARMTBR_SHDW_TRB2_W3_RESETVAL  (0x00000081U)
#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W3_ARMTBR_SHDW_TRB2_W3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_ARMTBR_SHDW_TRB2_W3_RESETVAL                (0x00000081U)

/* DBGTBR_TRB0_W0 */

#define CSL_BOOTCFG_DBGTBR_TRB0_W0_DBGTBR_TRB0_W0_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB0_W0_DBGTBR_TRB0_W0_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W0_DBGTBR_TRB0_W0_RESETVAL      (0x20600000U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W0_DBGTBR_TRB0_W0_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB0_W0_RESETVAL                     (0x20600000U)

/* DBGTBR_TRB0_W1 */

#define CSL_BOOTCFG_DBGTBR_TRB0_W1_DBGTBR_TRB0_W1_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB0_W1_DBGTBR_TRB0_W1_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W1_DBGTBR_TRB0_W1_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W1_DBGTBR_TRB0_W1_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB0_W1_RESETVAL                     (0x00000000U)

/* DBGTBR_TRB0_W2 */

#define CSL_BOOTCFG_DBGTBR_TRB0_W2_DBGTBR_TRB0_W2_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB0_W2_DBGTBR_TRB0_W2_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W2_DBGTBR_TRB0_W2_RESETVAL      (0x00007c00U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W2_DBGTBR_TRB0_W2_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB0_W2_RESETVAL                     (0x00007c00U)

/* DBGTBR_TRB0_W3 */

#define CSL_BOOTCFG_DBGTBR_TRB0_W3_DBGTBR_TRB0_W3_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB0_W3_DBGTBR_TRB0_W3_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W3_DBGTBR_TRB0_W3_RESETVAL      (0x00000011U)
#define CSL_BOOTCFG_DBGTBR_TRB0_W3_DBGTBR_TRB0_W3_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB0_W3_RESETVAL                     (0x00000011U)

/* DBGTBR_TRB1_W0 */

#define CSL_BOOTCFG_DBGTBR_TRB1_W0_DBGTBR_TRB1_W0_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB1_W0_DBGTBR_TRB1_W0_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W0_DBGTBR_TRB1_W0_RESETVAL      (0x20600000U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W0_DBGTBR_TRB1_W0_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB1_W0_RESETVAL                     (0x20600000U)

/* DBGTBR_TRB1_W1 */

#define CSL_BOOTCFG_DBGTBR_TRB1_W1_DBGTBR_TRB1_W1_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB1_W1_DBGTBR_TRB1_W1_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W1_DBGTBR_TRB1_W1_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W1_DBGTBR_TRB1_W1_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB1_W1_RESETVAL                     (0x00000000U)

/* DBGTBR_TRB1_W2 */

#define CSL_BOOTCFG_DBGTBR_TRB1_W2_DBGTBR_TRB1_W2_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB1_W2_DBGTBR_TRB1_W2_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W2_DBGTBR_TRB1_W2_RESETVAL      (0x00007c00U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W2_DBGTBR_TRB1_W2_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB1_W2_RESETVAL                     (0x00007c00U)

/* DBGTBR_TRB1_W3 */

#define CSL_BOOTCFG_DBGTBR_TRB1_W3_DBGTBR_TRB1_W3_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB1_W3_DBGTBR_TRB1_W3_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W3_DBGTBR_TRB1_W3_RESETVAL      (0x00000011U)
#define CSL_BOOTCFG_DBGTBR_TRB1_W3_DBGTBR_TRB1_W3_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB1_W3_RESETVAL                     (0x00000011U)

/* DBGTBR_TRB2_W0 */

#define CSL_BOOTCFG_DBGTBR_TRB2_W0_DBGTBR_TRB2_W0_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB2_W0_DBGTBR_TRB2_W0_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W0_DBGTBR_TRB2_W0_RESETVAL      (0x02620540U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W0_DBGTBR_TRB2_W0_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB2_W0_RESETVAL                     (0x02620540U)

/* DBGTBR_TRB2_W1 */

#define CSL_BOOTCFG_DBGTBR_TRB2_W1_DBGTBR_TRB2_W1_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB2_W1_DBGTBR_TRB2_W1_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W1_DBGTBR_TRB2_W1_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W1_DBGTBR_TRB2_W1_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB2_W1_RESETVAL                     (0x00000000U)

/* DBGTBR_TRB2_W2 */

#define CSL_BOOTCFG_DBGTBR_TRB2_W2_DBGTBR_TRB2_W2_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB2_W2_DBGTBR_TRB2_W2_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W2_DBGTBR_TRB2_W2_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W2_DBGTBR_TRB2_W2_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB2_W2_RESETVAL                     (0x00000000U)

/* DBGTBR_TRB2_W3 */

#define CSL_BOOTCFG_DBGTBR_TRB2_W3_DBGTBR_TRB2_W3_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_TRB2_W3_DBGTBR_TRB2_W3_SHIFT         (0U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W3_DBGTBR_TRB2_W3_RESETVAL      (0x00000081U)
#define CSL_BOOTCFG_DBGTBR_TRB2_W3_DBGTBR_TRB2_W3_MAX           (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_TRB2_W3_RESETVAL                     (0x00000081U)

/* DBGTBR_SHDW_TRB0_W0 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W0_DBGTBR_SHDW_TRB0_W0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W0_DBGTBR_SHDW_TRB0_W0_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W0_DBGTBR_SHDW_TRB0_W0_RESETVAL  (0x20600000U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W0_DBGTBR_SHDW_TRB0_W0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W0_RESETVAL                (0x20600000U)

/* DBGTBR_SHDW_TRB0_W1 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W1_DBGTBR_SHDW_TRB0_W1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W1_DBGTBR_SHDW_TRB0_W1_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W1_DBGTBR_SHDW_TRB0_W1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W1_DBGTBR_SHDW_TRB0_W1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W1_RESETVAL                (0x00000000U)

/* DBGTBR_SHDW_TRB0_W2 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W2_DBGTBR_SHDW_TRB0_W2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W2_DBGTBR_SHDW_TRB0_W2_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W2_DBGTBR_SHDW_TRB0_W2_RESETVAL  (0x00007c00U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W2_DBGTBR_SHDW_TRB0_W2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W2_RESETVAL                (0x00007c00U)

/* DBGTBR_SHDW_TRB0_W3 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W3_DBGTBR_SHDW_TRB0_W3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W3_DBGTBR_SHDW_TRB0_W3_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W3_DBGTBR_SHDW_TRB0_W3_RESETVAL  (0x00000011U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W3_DBGTBR_SHDW_TRB0_W3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB0_W3_RESETVAL                (0x00000011U)

/* DBGTBR_SHDW_TRB1_W0 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W0_DBGTBR_SHDW_TRB1_W0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W0_DBGTBR_SHDW_TRB1_W0_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W0_DBGTBR_SHDW_TRB1_W0_RESETVAL  (0x20600000U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W0_DBGTBR_SHDW_TRB1_W0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W0_RESETVAL                (0x20600000U)

/* DBGTBR_SHDW_TRB1_W1 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W1_DBGTBR_SHDW_TRB1_W1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W1_DBGTBR_SHDW_TRB1_W1_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W1_DBGTBR_SHDW_TRB1_W1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W1_DBGTBR_SHDW_TRB1_W1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W1_RESETVAL                (0x00000000U)

/* DBGTBR_SHDW_TRB1_W2 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W2_DBGTBR_SHDW_TRB1_W2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W2_DBGTBR_SHDW_TRB1_W2_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W2_DBGTBR_SHDW_TRB1_W2_RESETVAL  (0x00007c00U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W2_DBGTBR_SHDW_TRB1_W2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W2_RESETVAL                (0x00007c00U)

/* DBGTBR_SHDW_TRB1_W3 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W3_DBGTBR_SHDW_TRB1_W3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W3_DBGTBR_SHDW_TRB1_W3_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W3_DBGTBR_SHDW_TRB1_W3_RESETVAL  (0x00000011U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W3_DBGTBR_SHDW_TRB1_W3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB1_W3_RESETVAL                (0x00000011U)

/* DBGTBR_SHDW_TRB2_W0 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W0_DBGTBR_SHDW_TRB2_W0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W0_DBGTBR_SHDW_TRB2_W0_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W0_DBGTBR_SHDW_TRB2_W0_RESETVAL  (0x02620540U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W0_DBGTBR_SHDW_TRB2_W0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W0_RESETVAL                (0x02620540U)

/* DBGTBR_SHDW_TRB2_W1 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W1_DBGTBR_SHDW_TRB2_W1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W1_DBGTBR_SHDW_TRB2_W1_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W1_DBGTBR_SHDW_TRB2_W1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W1_DBGTBR_SHDW_TRB2_W1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W1_RESETVAL                (0x00000000U)

/* DBGTBR_SHDW_TRB2_W2 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W2_DBGTBR_SHDW_TRB2_W2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W2_DBGTBR_SHDW_TRB2_W2_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W2_DBGTBR_SHDW_TRB2_W2_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W2_DBGTBR_SHDW_TRB2_W2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W2_RESETVAL                (0x00000000U)

/* DBGTBR_SHDW_TRB2_W3 */

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W3_DBGTBR_SHDW_TRB2_W3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W3_DBGTBR_SHDW_TRB2_W3_SHIFT  (0U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W3_DBGTBR_SHDW_TRB2_W3_RESETVAL  (0x00000081U)
#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W3_DBGTBR_SHDW_TRB2_W3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_DBGTBR_SHDW_TRB2_W3_RESETVAL                (0x00000081U)

/* ARM_RETENTION */

#define CSL_BOOTCFG_ARM_RETENTION_ARM_RET_MASK                  (0x00000001U)
#define CSL_BOOTCFG_ARM_RETENTION_ARM_RET_SHIFT                 (0U)
#define CSL_BOOTCFG_ARM_RETENTION_ARM_RET_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_ARM_RETENTION_ARM_RET_MAX                   (0x00000001U)

#define CSL_BOOTCFG_ARM_RETENTION_RESETVAL                      (0x00000000U)

/* DSP_RETENTION */

#define CSL_BOOTCFG_DSP_RETENTION_DSP_RET_MASK                  (0x00000001U)
#define CSL_BOOTCFG_DSP_RETENTION_DSP_RET_SHIFT                 (0U)
#define CSL_BOOTCFG_DSP_RETENTION_DSP_RET_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_DSP_RETENTION_DSP_RET_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DSP_RETENTION_RESETVAL                      (0x00000000U)

/* SPARE0 */

#define CSL_BOOTCFG_SPARE0_SPARE_OUT0_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE0_SPARE_OUT0_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE0_SPARE_OUT0_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE0_SPARE_OUT0_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE0_SPARE_PULSE0_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE0_SPARE_PULSE0_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE0_SPARE_PULSE0_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE0_SPARE_PULSE0_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE0_RESETVAL                             (0x00000000U)

/* SPARE1 */

#define CSL_BOOTCFG_SPARE1_SPARE_OUT1_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE1_SPARE_OUT1_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE1_SPARE_OUT1_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE1_SPARE_OUT1_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE1_SPARE_PULSE1_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE1_SPARE_PULSE1_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE1_SPARE_PULSE1_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE1_SPARE_PULSE1_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE1_RESETVAL                             (0x00000000U)

/* SPARE2 */

#define CSL_BOOTCFG_SPARE2_SPARE_OUT2_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE2_SPARE_OUT2_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE2_SPARE_OUT2_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE2_SPARE_OUT2_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE2_SPARE_PULSE2_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE2_SPARE_PULSE2_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE2_SPARE_PULSE2_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE2_SPARE_PULSE2_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE2_RESETVAL                             (0x00000000U)

/* SPARE3 */

#define CSL_BOOTCFG_SPARE3_SPARE_OUT3_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE3_SPARE_OUT3_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE3_SPARE_OUT3_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE3_SPARE_OUT3_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE3_SPARE_PULSE3_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE3_SPARE_PULSE3_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE3_SPARE_PULSE3_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE3_SPARE_PULSE3_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE3_RESETVAL                             (0x00000000U)

/* SPARE4 */

#define CSL_BOOTCFG_SPARE4_SPARE_OUT4_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE4_SPARE_OUT4_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE4_SPARE_OUT4_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE4_SPARE_OUT4_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE4_SPARE_PULSE4_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE4_SPARE_PULSE4_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE4_SPARE_PULSE4_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE4_SPARE_PULSE4_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE4_RESETVAL                             (0x00000000U)

/* SPARE5 */

#define CSL_BOOTCFG_SPARE5_SPARE_OUT5_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE5_SPARE_OUT5_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE5_SPARE_OUT5_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE5_SPARE_OUT5_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE5_SPARE_PULSE5_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE5_SPARE_PULSE5_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE5_SPARE_PULSE5_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE5_SPARE_PULSE5_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE5_RESETVAL                             (0x00000000U)

/* SPARE6 */

#define CSL_BOOTCFG_SPARE6_SPARE_OUT6_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE6_SPARE_OUT6_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE6_SPARE_OUT6_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE6_SPARE_OUT6_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE6_SPARE_PULSE6_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE6_SPARE_PULSE6_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE6_SPARE_PULSE6_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE6_SPARE_PULSE6_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE6_RESETVAL                             (0x00000000U)

/* SPARE7 */

#define CSL_BOOTCFG_SPARE7_SPARE_OUT7_MASK                      (0x7FFFFFFFU)
#define CSL_BOOTCFG_SPARE7_SPARE_OUT7_SHIFT                     (0U)
#define CSL_BOOTCFG_SPARE7_SPARE_OUT7_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SPARE7_SPARE_OUT7_MAX                       (0x7fffffffU)

#define CSL_BOOTCFG_SPARE7_SPARE_PULSE7_MASK                    (0x80000000U)
#define CSL_BOOTCFG_SPARE7_SPARE_PULSE7_SHIFT                   (31U)
#define CSL_BOOTCFG_SPARE7_SPARE_PULSE7_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_SPARE7_SPARE_PULSE7_MAX                     (0x00000001U)

#define CSL_BOOTCFG_SPARE7_RESETVAL                             (0x00000000U)

/* SPARE8 */

#define CSL_BOOTCFG_SPARE8_SPARE_IN8_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE8_SPARE_IN8_SHIFT                      (0U)
#define CSL_BOOTCFG_SPARE8_SPARE_IN8_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SPARE8_SPARE_IN8_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SPARE8_RESETVAL                             (0x00000000U)

/* SPARE9 */

#define CSL_BOOTCFG_SPARE9_SPARE_IN9_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE9_SPARE_IN9_SHIFT                      (0U)
#define CSL_BOOTCFG_SPARE9_SPARE_IN9_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SPARE9_SPARE_IN9_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SPARE9_RESETVAL                             (0x00000000U)

/* SPARE10 */

#define CSL_BOOTCFG_SPARE10_SPARE_IN10_MASK                     (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE10_SPARE_IN10_SHIFT                    (0U)
#define CSL_BOOTCFG_SPARE10_SPARE_IN10_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_SPARE10_SPARE_IN10_MAX                      (0xffffffffU)

#define CSL_BOOTCFG_SPARE10_RESETVAL                            (0x00000000U)

/* SPARE11 */

#define CSL_BOOTCFG_SPARE11_SPARE_IN11_MASK                     (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE11_SPARE_IN11_SHIFT                    (0U)
#define CSL_BOOTCFG_SPARE11_SPARE_IN11_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_SPARE11_SPARE_IN11_MAX                      (0xffffffffU)

#define CSL_BOOTCFG_SPARE11_RESETVAL                            (0x00000000U)

/* SPARE12 */

#define CSL_BOOTCFG_SPARE12_SPARE_IN12_MASK                     (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE12_SPARE_IN12_SHIFT                    (0U)
#define CSL_BOOTCFG_SPARE12_SPARE_IN12_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_SPARE12_SPARE_IN12_MAX                      (0xffffffffU)

#define CSL_BOOTCFG_SPARE12_RESETVAL                            (0x00000000U)

/* SPARE13 */

#define CSL_BOOTCFG_SPARE13_SPARE_IN13_MASK                     (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE13_SPARE_IN13_SHIFT                    (0U)
#define CSL_BOOTCFG_SPARE13_SPARE_IN13_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_SPARE13_SPARE_IN13_MAX                      (0xffffffffU)

#define CSL_BOOTCFG_SPARE13_RESETVAL                            (0x00000000U)

/* SPARE14 */

#define CSL_BOOTCFG_SPARE14_SPARE_IN14_MASK                     (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE14_SPARE_IN14_SHIFT                    (0U)
#define CSL_BOOTCFG_SPARE14_SPARE_IN14_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_SPARE14_SPARE_IN14_MAX                      (0xffffffffU)

#define CSL_BOOTCFG_SPARE14_RESETVAL                            (0x00000000U)

/* SPARE15 */

#define CSL_BOOTCFG_SPARE15_SPARE_IN15_MASK                     (0xFFFFFFFFU)
#define CSL_BOOTCFG_SPARE15_SPARE_IN15_SHIFT                    (0U)
#define CSL_BOOTCFG_SPARE15_SPARE_IN15_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_SPARE15_SPARE_IN15_MAX                      (0xffffffffU)

#define CSL_BOOTCFG_SPARE15_RESETVAL                            (0x00000000U)

/* DDR_CLKCTL */

#define CSL_BOOTCFG_DDR_CLKCTL_DDR_CLK_MUXSEL_MASK              (0x00000001U)
#define CSL_BOOTCFG_DDR_CLKCTL_DDR_CLK_MUXSEL_SHIFT             (0U)
#define CSL_BOOTCFG_DDR_CLKCTL_DDR_CLK_MUXSEL_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_DDR_CLKCTL_DDR_CLK_MUXSEL_MAX               (0x00000001U)

#define CSL_BOOTCFG_DDR_CLKCTL_RESETVAL                         (0x00000000U)

/* ICSS_CLKCTL */

#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS0_PLL_MUXSEL_MASK           (0x00000001U)
#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS0_PLL_MUXSEL_SHIFT          (0U)
#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS0_PLL_MUXSEL_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS0_PLL_MUXSEL_MAX            (0x00000001U)

#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS1_PLL_MUXSEL_MASK           (0x00000100U)
#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS1_PLL_MUXSEL_SHIFT          (8U)
#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS1_PLL_MUXSEL_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_ICSS_CLKCTL_ICSS1_PLL_MUXSEL_MAX            (0x00000001U)

#define CSL_BOOTCFG_ICSS_CLKCTL_RESETVAL                        (0x00000000U)

/* ETHERNET_CLKCTL */

#define CSL_BOOTCFG_ETHERNET_CLKCTL_RMII_CLK_IO_EN_MASK         (0x00000001U)
#define CSL_BOOTCFG_ETHERNET_CLKCTL_RMII_CLK_IO_EN_SHIFT        (0U)
#define CSL_BOOTCFG_ETHERNET_CLKCTL_RMII_CLK_IO_EN_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_ETHERNET_CLKCTL_RMII_CLK_IO_EN_MAX          (0x00000001U)

#define CSL_BOOTCFG_ETHERNET_CLKCTL_RESETVAL                    (0x00000000U)

/* USB0_CLKCTL */

#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_SEL_MASK           (0x00000001U)
#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_SEL_SHIFT          (0U)
#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_SEL_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_SEL_MAX            (0x00000001U)

#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_LOAD_DIV_MASK      (0x00000002U)
#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_LOAD_DIV_SHIFT     (1U)
#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_LOAD_DIV_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_LOAD_DIV_MAX       (0x00000001U)

#define CSL_BOOTCFG_USB0_CLKCTL_RESETVAL                        (0x00000000U)

/* USB1_CLKCTL */

#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_SEL_MASK           (0x00000001U)
#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_SEL_SHIFT          (0U)
#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_SEL_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_SEL_MAX            (0x00000001U)

#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_LOAD_DIV_MASK      (0x00000002U)
#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_LOAD_DIV_SHIFT     (1U)
#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_LOAD_DIV_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_LOAD_DIV_MAX       (0x00000001U)

#define CSL_BOOTCFG_USB1_CLKCTL_RESETVAL                        (0x00000000U)

/* SERIALPORT_CLKCTL */

#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP0_AUXCLK_SEL_MASK    (0x00000007U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP0_AUXCLK_SEL_SHIFT   (0U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP0_AUXCLK_SEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP0_AUXCLK_SEL_MAX     (0x00000007U)

#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP1_AUXCLK_SEL_MASK    (0x00000070U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP1_AUXCLK_SEL_SHIFT   (4U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP1_AUXCLK_SEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP1_AUXCLK_SEL_MAX     (0x00000007U)

#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP2_AUXCLK_SEL_MASK    (0x00000700U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP2_AUXCLK_SEL_SHIFT   (8U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP2_AUXCLK_SEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_SERIALPORT_CLKCTL_MCASP2_AUXCLK_SEL_MAX     (0x00000007U)

#define CSL_BOOTCFG_SERIALPORT_CLKCTL_RESETVAL                  (0x00000000U)

/* OSC_CTL */

#define CSL_BOOTCFG_OSC_CTL_SYSOSC_RES_SEL_MASK                 (0x00000001U)
#define CSL_BOOTCFG_OSC_CTL_SYSOSC_RES_SEL_SHIFT                (0U)
#define CSL_BOOTCFG_OSC_CTL_SYSOSC_RES_SEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_OSC_CTL_SYSOSC_RES_SEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_RES_SEL_MASK               (0x00000100U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_RES_SEL_SHIFT              (8U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_RES_SEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_RES_SEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW1_MASK                   (0x00000200U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW1_SHIFT                  (9U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW1_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW1_MAX                    (0x00000001U)

#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW2_MASK                   (0x00000400U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW2_SHIFT                  (10U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW2_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_OSC_CTL_AUDIOOSC_SW2_MAX                    (0x00000001U)

#define CSL_BOOTCFG_OSC_CTL_RESETVAL                            (0x00000200U)

/* PCIE_CLKCTL */

#define CSL_BOOTCFG_PCIE_CLKCTL_PCIE_REFCLK_INPUT_SEL_MASK      (0x00000007U)
#define CSL_BOOTCFG_PCIE_CLKCTL_PCIE_REFCLK_INPUT_SEL_SHIFT     (0U)
#define CSL_BOOTCFG_PCIE_CLKCTL_PCIE_REFCLK_INPUT_SEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PCIE_CLKCTL_PCIE_REFCLK_INPUT_SEL_MAX       (0x00000007U)

#define CSL_BOOTCFG_PCIE_CLKCTL_RESETVAL                        (0x00000000U)

/* CHIP_MISC_CTL0 */

#define CSL_BOOTCFG_CHIP_MISC_CTL0_MSMC_BLOCK_PARITY_RST_MASK   (0x00001000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_MSMC_BLOCK_PARITY_RST_SHIFT  (12U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_MSMC_BLOCK_PARITY_RST_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_MSMC_BLOCK_PARITY_RST_MAX    (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB0_PME_EN_MASK             (0x00040000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB0_PME_EN_SHIFT            (18U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB0_PME_EN_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB0_PME_EN_MAX              (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL0_RST_ISO_IP_RST_BLK_MASK      (0x03F80000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_RST_ISO_IP_RST_BLK_SHIFT     (19U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_RST_ISO_IP_RST_BLK_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_RST_ISO_IP_RST_BLK_MAX       (0x0000007fU)

#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_REDUND_EN_MASK         (0x04000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_REDUND_EN_SHIFT        (26U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_REDUND_EN_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_REDUND_EN_MAX          (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_ACTUAL_EN_MASK         (0x08000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_ACTUAL_EN_SHIFT        (27U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_ACTUAL_EN_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_EFUSE_ACTUAL_EN_MAX          (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB1_PME_EN_MASK             (0x10000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB1_PME_EN_SHIFT            (28U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB1_PME_EN_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL0_USB1_PME_EN_MAX              (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL0_RESETVAL                     (0x00000000U)

/* SYSENDSTAT */

#define CSL_BOOTCFG_SYSENDSTAT_SYSENDSTAT_MASK                  (0x00000001U)
#define CSL_BOOTCFG_SYSENDSTAT_SYSENDSTAT_SHIFT                 (0U)
#define CSL_BOOTCFG_SYSENDSTAT_SYSENDSTAT_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_SYSENDSTAT_SYSENDSTAT_MAX                   (0x00000001U)

#define CSL_BOOTCFG_SYSENDSTAT_RESETVAL                         (0x00000000U)

/* PLLLOCK_PINCTL */

#define CSL_BOOTCFG_PLLLOCK_PINCTL_MAINPLL_LOCK_SEL_MASK        (0x00000001U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_MAINPLL_LOCK_SEL_SHIFT       (0U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_MAINPLL_LOCK_SEL_RESETVAL    (0x00000001U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_MAINPLL_LOCK_SEL_MAX         (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_DDR3APLL_LOCK_SEL_MASK       (0x00000002U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_DDR3APLL_LOCK_SEL_SHIFT      (1U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_DDR3APLL_LOCK_SEL_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_DDR3APLL_LOCK_SEL_MAX        (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_NSSPLL_LOCK_SEL_MASK         (0x00000008U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_NSSPLL_LOCK_SEL_SHIFT        (3U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_NSSPLL_LOCK_SEL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_NSSPLL_LOCK_SEL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_ARMPLL_LOCK_SEL_MASK         (0x00000010U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_ARMPLL_LOCK_SEL_SHIFT        (4U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_ARMPLL_LOCK_SEL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_ARMPLL_LOCK_SEL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_DSSPLL_LOCK_SEL_MASK         (0x00000020U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_DSSPLL_LOCK_SEL_SHIFT        (5U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_DSSPLL_LOCK_SEL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_DSSPLL_LOCK_SEL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_ICSSPLL_LOCK_SEL_MASK        (0x00000040U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_ICSSPLL_LOCK_SEL_SHIFT       (6U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_ICSSPLL_LOCK_SEL_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_ICSSPLL_LOCK_SEL_MAX         (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_UARTPLL_LOCK_SEL_MASK        (0x00000080U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_UARTPLL_LOCK_SEL_SHIFT       (7U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_UARTPLL_LOCK_SEL_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_UARTPLL_LOCK_SEL_MAX         (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_PCIEPLL_LOCK_SEL_MASK        (0x00000004U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_PCIEPLL_LOCK_SEL_SHIFT       (2U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_PCIEPLL_LOCK_SEL_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_PINCTL_PCIEPLL_LOCK_SEL_MAX         (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_PINCTL_RESETVAL                     (0x00000001U)

/* PLLLOCK_STAT */

#define CSL_BOOTCFG_PLLLOCK_STAT_MAINPLL_LOCK_STAT_MASK         (0x00000001U)
#define CSL_BOOTCFG_PLLLOCK_STAT_MAINPLL_LOCK_STAT_SHIFT        (0U)
#define CSL_BOOTCFG_PLLLOCK_STAT_MAINPLL_LOCK_STAT_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_MAINPLL_LOCK_STAT_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_DDR3APLL_LOCK_STAT_MASK        (0x00000002U)
#define CSL_BOOTCFG_PLLLOCK_STAT_DDR3APLL_LOCK_STAT_SHIFT       (1U)
#define CSL_BOOTCFG_PLLLOCK_STAT_DDR3APLL_LOCK_STAT_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_DDR3APLL_LOCK_STAT_MAX         (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_NSSPLL_LOCK_STAT_MASK          (0x00000008U)
#define CSL_BOOTCFG_PLLLOCK_STAT_NSSPLL_LOCK_STAT_SHIFT         (3U)
#define CSL_BOOTCFG_PLLLOCK_STAT_NSSPLL_LOCK_STAT_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_NSSPLL_LOCK_STAT_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_ARMPLL_LOCK_STAT_MASK          (0x00000010U)
#define CSL_BOOTCFG_PLLLOCK_STAT_ARMPLL_LOCK_STAT_SHIFT         (4U)
#define CSL_BOOTCFG_PLLLOCK_STAT_ARMPLL_LOCK_STAT_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_ARMPLL_LOCK_STAT_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_DSSPLL_LOCK_STAT_MASK          (0x00000020U)
#define CSL_BOOTCFG_PLLLOCK_STAT_DSSPLL_LOCK_STAT_SHIFT         (5U)
#define CSL_BOOTCFG_PLLLOCK_STAT_DSSPLL_LOCK_STAT_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_DSSPLL_LOCK_STAT_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_ICSSPLL_LOCK_STAT_MASK         (0x00000040U)
#define CSL_BOOTCFG_PLLLOCK_STAT_ICSSPLL_LOCK_STAT_SHIFT        (6U)
#define CSL_BOOTCFG_PLLLOCK_STAT_ICSSPLL_LOCK_STAT_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_ICSSPLL_LOCK_STAT_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_UARTPLL_LOCK_STAT_MASK         (0x00000080U)
#define CSL_BOOTCFG_PLLLOCK_STAT_UARTPLL_LOCK_STAT_SHIFT        (7U)
#define CSL_BOOTCFG_PLLLOCK_STAT_UARTPLL_LOCK_STAT_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_UARTPLL_LOCK_STAT_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_PCIEPLL_LOCK_STAT_MASK         (0x00000004U)
#define CSL_BOOTCFG_PLLLOCK_STAT_PCIEPLL_LOCK_STAT_SHIFT        (2U)
#define CSL_BOOTCFG_PLLLOCK_STAT_PCIEPLL_LOCK_STAT_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_STAT_PCIEPLL_LOCK_STAT_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_STAT_RESETVAL                       (0x00000000U)

/* PLLLOCK_EVAL */

#define CSL_BOOTCFG_PLLLOCK_EVAL_MAINPLL_LOCK_EVAL_MASK         (0x00000001U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_MAINPLL_LOCK_EVAL_SHIFT        (0U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_MAINPLL_LOCK_EVAL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_MAINPLL_LOCK_EVAL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_DDR3APLL_LOCK_EVAL_MASK        (0x00000002U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_DDR3APLL_LOCK_EVAL_SHIFT       (1U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_DDR3APLL_LOCK_EVAL_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_DDR3APLL_LOCK_EVAL_MAX         (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_NSSPLL_LOCK_EVAL_MASK          (0x00000008U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_NSSPLL_LOCK_EVAL_SHIFT         (3U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_NSSPLL_LOCK_EVAL_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_NSSPLL_LOCK_EVAL_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_ARMPLL_LOCK_EVAL_MASK          (0x00000010U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_ARMPLL_LOCK_EVAL_SHIFT         (4U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_ARMPLL_LOCK_EVAL_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_ARMPLL_LOCK_EVAL_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_DSSPLL_LOCK_EVAL_MASK          (0x00000020U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_DSSPLL_LOCK_EVAL_SHIFT         (5U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_DSSPLL_LOCK_EVAL_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_DSSPLL_LOCK_EVAL_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_ICSSPLL_LOCK_EVAL_MASK         (0x00000040U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_ICSSPLL_LOCK_EVAL_SHIFT        (6U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_ICSSPLL_LOCK_EVAL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_ICSSPLL_LOCK_EVAL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_UARTPLL_LOCK_EVAL_MASK         (0x00000080U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_UARTPLL_LOCK_EVAL_SHIFT        (7U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_UARTPLL_LOCK_EVAL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_UARTPLL_LOCK_EVAL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_PCIEPLL_LOCK_EVAL_MASK         (0x00000004U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_PCIEPLL_LOCK_EVAL_SHIFT        (2U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_PCIEPLL_LOCK_EVAL_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_PLLLOCK_EVAL_PCIEPLL_LOCK_EVAL_MAX          (0x00000001U)

#define CSL_BOOTCFG_PLLLOCK_EVAL_RESETVAL                       (0x00000000U)

/* PLLCLKSEL_STAT */

#define CSL_BOOTCFG_PLLCLKSEL_STAT_SYSCLKSEL_STAT_MASK          (0x00000001U)
#define CSL_BOOTCFG_PLLCLKSEL_STAT_SYSCLKSEL_STAT_SHIFT         (0U)
#define CSL_BOOTCFG_PLLCLKSEL_STAT_SYSCLKSEL_STAT_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_PLLCLKSEL_STAT_SYSCLKSEL_STAT_MAX           (0x00000001U)

#define CSL_BOOTCFG_PLLCLKSEL_STAT_RESETVAL                     (0x00000000U)

/* USB0_PHY_CTL0 */

#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_MASK    (0x00000001U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_SHIFT   (0U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_MAX     (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_MASK   (0x00000002U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_SHIFT  (1U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_VBUSVLDEXT_MASK      (0x00000004U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_VBUSVLDEXT_SHIFT     (2U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_VBUSVLDEXT_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_UTMI_VBUSVLDEXT_MAX       (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_MASK   (0x00000010U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_SHIFT  (4U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_VATESTENB_MASK     (0x00000180U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_VATESTENB_SHIFT    (7U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_VATESTENB_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL0_USB_PHY_TC_VATESTENB_MAX      (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL0_RESETVAL                      (0x00000000U)

/* USB0_PHY_CTL1 */

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_MASK  (0x00010000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_SHIFT  (16U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_MASK  (0x00020000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_SHIFT  (17U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_MASK  (0x00040000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_SHIFT  (18U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_MASK  (0x00080000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_SHIFT  (19U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_MASK  (0x00100000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_SHIFT  (20U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_MASK  (0x00200000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_SHIFT  (21U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_MASK  (0x00400000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_SHIFT  (22U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_MASK  (0x00800000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_SHIFT  (23U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL1_RESETVAL                      (0x00000000U)

/* USB0_PHY_CTL2 */

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_MASK   (0x00000007U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_SHIFT  (0U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_RESETVAL  (0x00000004U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_MAX    (0x00000007U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_OTGTUNE_MASK       (0x00000070U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_OTGTUNE_SHIFT      (4U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_OTGTUNE_RESETVAL   (0x00000004U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_OTGTUNE_MAX        (0x00000007U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_SQRXTUNE_MASK      (0x00000380U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_SQRXTUNE_SHIFT     (7U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_SQRXTUNE_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_SQRXTUNE_MAX       (0x00000007U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_MASK    (0x00003C00U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_SHIFT   (10U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_MAX     (0x0000000fU)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_MASK    (0x0000C000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_SHIFT   (14U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_MASK  (0x00030000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_SHIFT  (16U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_MAX  (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_MASK  (0x00040000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_SHIFT  (18U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRESTUNE_MASK     (0x00180000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRESTUNE_SHIFT    (19U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRESTUNE_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRESTUNE_MAX      (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRISETUNE_MASK    (0x00600000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRISETUNE_SHIFT   (21U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRISETUNE_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXRISETUNE_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_MASK    (0x07800000U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_SHIFT   (23U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_RESETVAL  (0x00000008U)
#define CSL_BOOTCFG_USB0_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_MAX     (0x0000000fU)

#define CSL_BOOTCFG_USB0_PHY_CTL2_RESETVAL                      (0x0428cdc4U)

/* USB0_PHY_CTL3 */

#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGLPN_MASK     (0x00000800U)
#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGLPN_SHIFT    (11U)
#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGLPN_RESETVAL  (0x00000078U)
#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGLPN_MAX      (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGTEST_MASK    (0x00003000U)
#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGTEST_SHIFT   (12U)
#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGTEST_RESETVAL  (0x00000078U)
#define CSL_BOOTCFG_USB0_PHY_CTL3_USB_PHY_VREG_VREGTEST_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL3_RESETVAL                      (0x0007c000U)

/* USB0_PHY_CTL4 */

#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_MASK   (0x00008000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_SHIFT  (15U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_MASK  (0x00010000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_SHIFT  (16U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_MASK   (0x00020000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_SHIFT  (17U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_COMMONONN_MASK        (0x00040000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_COMMONONN_SHIFT       (18U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_COMMONONN_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_COMMONONN_MAX         (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_MASK    (0x00180000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_SHIFT   (19U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_RESETVAL  (0x00000002U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_FSEL_MASK         (0x01C00000U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_FSEL_SHIFT        (22U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_FSEL_RESETVAL     (0x00000005U)
#define CSL_BOOTCFG_USB0_PHY_CTL4_USB_PHY_OSC_FSEL_MAX          (0x00000007U)

#define CSL_BOOTCFG_USB0_PHY_CTL4_RESETVAL                      (0x01518000U)

/* USB0_PHY_CTL5 */

#define CSL_BOOTCFG_USB0_PHY_CTL5_USB_PHY_TC_SIDDQ_MASK         (0x00200000U)
#define CSL_BOOTCFG_USB0_PHY_CTL5_USB_PHY_TC_SIDDQ_SHIFT        (21U)
#define CSL_BOOTCFG_USB0_PHY_CTL5_USB_PHY_TC_SIDDQ_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_USB0_PHY_CTL5_USB_PHY_TC_SIDDQ_MAX          (0x00000001U)

#define CSL_BOOTCFG_USB0_PHY_CTL5_RESETVAL                      (0x00000000U)

/* USB1_PHY_CTL0 */

#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_MASK    (0x00000001U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_SHIFT   (0U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFEN_MAX     (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_MASK   (0x00000002U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_SHIFT  (1U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_TXBITSTUFFENH_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_VBUSVLDEXT_MASK      (0x00000004U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_VBUSVLDEXT_SHIFT     (2U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_VBUSVLDEXT_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_VBUSVLDEXT_MAX       (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_WORDINTERFACE_MASK   (0x00000008U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_WORDINTERFACE_SHIFT  (3U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_WORDINTERFACE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_UTMI_WORDINTERFACE_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_MASK   (0x00000010U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_SHIFT  (4U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_LOOPBACKENB_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_VATESTENB_MASK     (0x00000180U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_VATESTENB_SHIFT    (7U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_VATESTENB_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL0_USB_PHY_TC_VATESTENB_MAX      (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL0_RESETVAL                      (0x00000000U)

/* USB1_PHY_CTL1 */

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_MASK  (0x00010000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_SHIFT  (16U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_MASK  (0x00020000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_SHIFT  (17U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_MASK  (0x00040000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_SHIFT  (18U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_SEL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_MASK  (0x00080000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_SHIFT  (19U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_MUX_VAL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_MASK  (0x00100000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_SHIFT  (20U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_MASK  (0x00200000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_SHIFT  (21U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_DRVVBUS_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_MASK  (0x00400000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_SHIFT  (22U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_SEL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_MASK  (0x00800000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_SHIFT  (23U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL1_USB_PHY_OTG_DFT_VAL_IDDIG_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL1_RESETVAL                      (0x00000000U)

/* USB1_PHY_CTL2 */

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_MASK   (0x00000007U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_SHIFT  (0U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_RESETVAL  (0x00000004U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_COMPDISTUNE_MAX    (0x00000007U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_OTGTUNE_MASK       (0x00000070U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_OTGTUNE_SHIFT      (4U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_OTGTUNE_RESETVAL   (0x00000004U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_OTGTUNE_MAX        (0x00000007U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_SQRXTUNE_MASK      (0x00000380U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_SQRXTUNE_SHIFT     (7U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_SQRXTUNE_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_SQRXTUNE_MAX       (0x00000007U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_MASK    (0x00003C00U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_SHIFT   (10U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXFSLSTUNE_MAX     (0x0000000fU)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_MASK    (0x0000C000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_SHIFT   (14U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXHSXVTUNE_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_MASK  (0x00030000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_SHIFT  (16U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPAMPTUNE_MAX  (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_MASK  (0x00040000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_SHIFT  (18U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXPREEMPPULSETUNE_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRESTUNE_MASK     (0x00180000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRESTUNE_SHIFT    (19U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRESTUNE_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRESTUNE_MAX      (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRISETUNE_MASK    (0x00600000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRISETUNE_SHIFT   (21U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRISETUNE_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXRISETUNE_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_MASK    (0x07800000U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_SHIFT   (23U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_RESETVAL  (0x00000008U)
#define CSL_BOOTCFG_USB1_PHY_CTL2_USB_PHY_PC_TXVREFTUNE_MAX     (0x0000000fU)

#define CSL_BOOTCFG_USB1_PHY_CTL2_RESETVAL                      (0x0428cdc4U)

/* USB1_PHY_CTL3 */

#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGLPN_MASK     (0x00000800U)
#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGLPN_SHIFT    (11U)
#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGLPN_RESETVAL  (0x00000078U)
#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGLPN_MAX      (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGTEST_MASK    (0x00003000U)
#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGTEST_SHIFT   (12U)
#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGTEST_RESETVAL  (0x00000078U)
#define CSL_BOOTCFG_USB1_PHY_CTL3_USB_PHY_VREG_VREGTEST_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL3_RESETVAL                      (0x0007c000U)

/* USB1_PHY_CTL4 */

#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_MASK   (0x00008000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_SHIFT  (15U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_OTGDISABLE_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_MASK  (0x00010000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_SHIFT  (16U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_RESETVAL  (0x00000001U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OTG_VBUSVLDEXTSEL_MAX  (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_MASK   (0x00020000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_SHIFT  (17U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_CTRL_MISC_DEBUG_EN_MAX    (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_COMMONONN_MASK        (0x00040000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_COMMONONN_SHIFT       (18U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_COMMONONN_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_COMMONONN_MAX         (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_MASK    (0x00180000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_SHIFT   (19U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_RESETVAL  (0x00000002U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_REFCLKSEL_MAX     (0x00000003U)

#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_FSEL_MASK         (0x01C00000U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_FSEL_SHIFT        (22U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_FSEL_RESETVAL     (0x00000005U)
#define CSL_BOOTCFG_USB1_PHY_CTL4_USB_PHY_OSC_FSEL_MAX          (0x00000007U)

#define CSL_BOOTCFG_USB1_PHY_CTL4_RESETVAL                      (0x01518000U)

/* USB1_PHY_CTL5 */

#define CSL_BOOTCFG_USB1_PHY_CTL5_USB_PHY_TC_SIDDQ_MASK         (0x00200000U)
#define CSL_BOOTCFG_USB1_PHY_CTL5_USB_PHY_TC_SIDDQ_SHIFT        (21U)
#define CSL_BOOTCFG_USB1_PHY_CTL5_USB_PHY_TC_SIDDQ_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_USB1_PHY_CTL5_USB_PHY_TC_SIDDQ_MAX          (0x00000001U)

#define CSL_BOOTCFG_USB1_PHY_CTL5_RESETVAL                      (0x00000000U)

/* USB_EBC_IN_CTL */

#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC15_SEL_MASK               (0x00000003U)
#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC15_SEL_SHIFT              (0U)
#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC15_SEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC15_SEL_MAX                (0x00000003U)

#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC14_SEL_MASK               (0x00000030U)
#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC14_SEL_SHIFT              (4U)
#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC14_SEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_USB_EBC_IN_CTL_EBC14_SEL_MAX                (0x00000003U)

#define CSL_BOOTCFG_USB_EBC_IN_CTL_RESETVAL                     (0x00000000U)

/* SCRATCH0 */

#define CSL_BOOTCFG_SCRATCH0_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH0_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH0_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH0_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH0_RESETVAL                           (0x00000000U)

/* SCRATCH1 */

#define CSL_BOOTCFG_SCRATCH1_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH1_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH1_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH1_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH1_RESETVAL                           (0x00000000U)

/* SCRATCH2 */

#define CSL_BOOTCFG_SCRATCH2_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH2_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH2_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH2_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH2_RESETVAL                           (0x00000000U)

/* SCRATCH3 */

#define CSL_BOOTCFG_SCRATCH3_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH3_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH3_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH3_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH3_RESETVAL                           (0x00000000U)

/* SCRATCH4 */

#define CSL_BOOTCFG_SCRATCH4_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH4_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH4_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH4_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH4_RESETVAL                           (0x00000000U)

/* SCRATCH5 */

#define CSL_BOOTCFG_SCRATCH5_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH5_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH5_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH5_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH5_RESETVAL                           (0x00000000U)

/* SCRATCH6 */

#define CSL_BOOTCFG_SCRATCH6_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH6_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH6_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH6_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH6_RESETVAL                           (0x00000000U)

/* SCRATCH7 */

#define CSL_BOOTCFG_SCRATCH7_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH7_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH7_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH7_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH7_RESETVAL                           (0x00000000U)

/* SCRATCH8 */

#define CSL_BOOTCFG_SCRATCH8_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH8_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH8_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH8_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH8_RESETVAL                           (0x00000000U)

/* SCRATCH9 */

#define CSL_BOOTCFG_SCRATCH9_SCRATCH_MASK                       (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH9_SCRATCH_SHIFT                      (0U)
#define CSL_BOOTCFG_SCRATCH9_SCRATCH_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_SCRATCH9_SCRATCH_MAX                        (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH9_RESETVAL                           (0x00000000U)

/* SCRATCH10 */

#define CSL_BOOTCFG_SCRATCH10_SCRATCH_MASK                      (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH10_SCRATCH_SHIFT                     (0U)
#define CSL_BOOTCFG_SCRATCH10_SCRATCH_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SCRATCH10_SCRATCH_MAX                       (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH10_RESETVAL                          (0x00000000U)

/* SCRATCH11 */

#define CSL_BOOTCFG_SCRATCH11_SCRATCH_MASK                      (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH11_SCRATCH_SHIFT                     (0U)
#define CSL_BOOTCFG_SCRATCH11_SCRATCH_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SCRATCH11_SCRATCH_MAX                       (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH11_RESETVAL                          (0x00000000U)

/* SCRATCH12 */

#define CSL_BOOTCFG_SCRATCH12_SCRATCH_MASK                      (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH12_SCRATCH_SHIFT                     (0U)
#define CSL_BOOTCFG_SCRATCH12_SCRATCH_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SCRATCH12_SCRATCH_MAX                       (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH12_RESETVAL                          (0x00000000U)

/* SCRATCH13 */

#define CSL_BOOTCFG_SCRATCH13_SCRATCH_MASK                      (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH13_SCRATCH_SHIFT                     (0U)
#define CSL_BOOTCFG_SCRATCH13_SCRATCH_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SCRATCH13_SCRATCH_MAX                       (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH13_RESETVAL                          (0x00000000U)

/* SCRATCH14 */

#define CSL_BOOTCFG_SCRATCH14_SCRATCH_MASK                      (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH14_SCRATCH_SHIFT                     (0U)
#define CSL_BOOTCFG_SCRATCH14_SCRATCH_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SCRATCH14_SCRATCH_MAX                       (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH14_RESETVAL                          (0x00000000U)

/* SCRATCH15 */

#define CSL_BOOTCFG_SCRATCH15_SCRATCH_MASK                      (0xFFFFFFFFU)
#define CSL_BOOTCFG_SCRATCH15_SCRATCH_SHIFT                     (0U)
#define CSL_BOOTCFG_SCRATCH15_SCRATCH_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_SCRATCH15_SCRATCH_MAX                       (0xffffffffU)

#define CSL_BOOTCFG_SCRATCH15_RESETVAL                          (0x00000000U)

/* DSP_SECURE_STAT */

#define CSL_BOOTCFG_DSP_SECURE_STAT_STAT0_MASK                  (0x00000001U)
#define CSL_BOOTCFG_DSP_SECURE_STAT_STAT0_SHIFT                 (0U)
#define CSL_BOOTCFG_DSP_SECURE_STAT_STAT0_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_DSP_SECURE_STAT_STAT0_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DSP_SECURE_STAT_RESETVAL                    (0x00000001U)

/* DSP_SECURE_EN0 */

#define CSL_BOOTCFG_DSP_SECURE_EN0_ENABLE_MASK                  (0x00000001U)
#define CSL_BOOTCFG_DSP_SECURE_EN0_ENABLE_SHIFT                 (0U)
#define CSL_BOOTCFG_DSP_SECURE_EN0_ENABLE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_DSP_SECURE_EN0_ENABLE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_DSP_SECURE_EN0_RESETVAL                     (0x00000001U)

/* DSP_BOOT_ADDR0_NS */

#define CSL_BOOTCFG_DSP_BOOT_ADDR0_NS_ISTP_RST_VAL_MASK         (0xFFFFFC00U)
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_NS_ISTP_RST_VAL_SHIFT        (10U)
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_NS_ISTP_RST_VAL_RESETVAL     (0x0000082cU)
#define CSL_BOOTCFG_DSP_BOOT_ADDR0_NS_ISTP_RST_VAL_MAX          (0x003fffffU)

#define CSL_BOOTCFG_DSP_BOOT_ADDR0_NS_RESETVAL                  (0x0020b000U)

/* SECURE_CONTROL */

#define CSL_BOOTCFG_SECURE_CONTROL_PBIST_SEC_EN_MASK            (0x00000001U)
#define CSL_BOOTCFG_SECURE_CONTROL_PBIST_SEC_EN_SHIFT           (0U)
#define CSL_BOOTCFG_SECURE_CONTROL_PBIST_SEC_EN_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_SECURE_CONTROL_PBIST_SEC_EN_MAX             (0x00000001U)

#define CSL_BOOTCFG_SECURE_CONTROL_RESETVAL                     (0x00000000U)

/* SECURE_SCRATCH0 */

#define CSL_BOOTCFG_SECURE_SCRATCH0_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH0_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH0_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH0_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH0_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH1 */

#define CSL_BOOTCFG_SECURE_SCRATCH1_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH1_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH1_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH1_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH1_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH2 */

#define CSL_BOOTCFG_SECURE_SCRATCH2_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH2_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH2_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH2_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH2_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH3 */

#define CSL_BOOTCFG_SECURE_SCRATCH3_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH3_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH3_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH3_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH3_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH4 */

#define CSL_BOOTCFG_SECURE_SCRATCH4_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH4_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH4_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH4_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH4_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH5 */

#define CSL_BOOTCFG_SECURE_SCRATCH5_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH5_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH5_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH5_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH5_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH6 */

#define CSL_BOOTCFG_SECURE_SCRATCH6_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH6_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH6_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH6_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH6_RESETVAL                    (0x00000000U)

/* SECURE_SCRATCH7 */

#define CSL_BOOTCFG_SECURE_SCRATCH7_SECURE_SCRATCH_MASK         (0xFFFFFFFFU)
#define CSL_BOOTCFG_SECURE_SCRATCH7_SECURE_SCRATCH_SHIFT        (0U)
#define CSL_BOOTCFG_SECURE_SCRATCH7_SECURE_SCRATCH_RESETVAL     (0x00000000U)
#define CSL_BOOTCFG_SECURE_SCRATCH7_SECURE_SCRATCH_MAX          (0xffffffffU)

#define CSL_BOOTCFG_SECURE_SCRATCH7_RESETVAL                    (0x00000000U)

/* LED_CORE_PASSDONE0 */

#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_P0_MASK        (0x00000001U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_P0_SHIFT       (0U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_P0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_P0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_D0_MASK        (0x00000002U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_D0_SHIFT       (1U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_D0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_D0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_I0_MASK        (0x00000004U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_I0_SHIFT       (2U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_I0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_I0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_L0_MASK        (0x00000008U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_L0_SHIFT       (3U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_L0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE0_PASSDONE0_L0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE0_RESETVAL                 (0x00000000U)

/* LED_CORE_PASSDONE1 */

#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_P0_MASK        (0x00000001U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_P0_SHIFT       (0U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_P0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_P0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_D0_MASK        (0x00000002U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_D0_SHIFT       (1U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_D0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_D0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_I0_MASK        (0x00000004U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_I0_SHIFT       (2U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_I0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_I0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_L0_MASK        (0x00000008U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_L0_SHIFT       (3U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_L0_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_CORE_PASSDONE1_PASSDONE1_L0_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_CORE_PASSDONE1_RESETVAL                 (0x00000000U)

/* LED_ARM_BOOTADDR */

#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_SELECT_MASK        (0x00000001U)
#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_SELECT_SHIFT       (0U)
#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_SELECT_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_SELECT_MAX         (0x00000001U)

#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_BOOTADDR_MASK      (0xFFFFFF00U)
#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_BOOTADDR_SHIFT     (8U)
#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_BOOTADDR_RESETVAL  (0x000000c4U)
#define CSL_BOOTCFG_LED_ARM_BOOTADDR_LED_ARM_BOOTADDR_MAX       (0x00ffffffU)

#define CSL_BOOTCFG_LED_ARM_BOOTADDR_RESETVAL                   (0x0000c400U)

/* LED_GPIO_CLR0 */

#define CSL_BOOTCFG_LED_GPIO_CLR0_LED_GPIO_SRC0_CLR_MASK        (0xFFFFFFFFU)
#define CSL_BOOTCFG_LED_GPIO_CLR0_LED_GPIO_SRC0_CLR_SHIFT       (0U)
#define CSL_BOOTCFG_LED_GPIO_CLR0_LED_GPIO_SRC0_CLR_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_LED_GPIO_CLR0_LED_GPIO_SRC0_CLR_MAX         (0xffffffffU)

#define CSL_BOOTCFG_LED_GPIO_CLR0_RESETVAL                      (0x00000000U)

/* LED_GPIO_SET0 */

#define CSL_BOOTCFG_LED_GPIO_SET0_LED_GPIO_SRC0_MASK            (0xFFFFFFFFU)
#define CSL_BOOTCFG_LED_GPIO_SET0_LED_GPIO_SRC0_SHIFT           (0U)
#define CSL_BOOTCFG_LED_GPIO_SET0_LED_GPIO_SRC0_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_LED_GPIO_SET0_LED_GPIO_SRC0_MAX             (0xffffffffU)

#define CSL_BOOTCFG_LED_GPIO_SET0_RESETVAL                      (0x00000000U)

/* LED_PLLLOCK0 */

#define CSL_BOOTCFG_LED_PLLLOCK0_PLLLOCK_MASK                   (0x00000001U)
#define CSL_BOOTCFG_LED_PLLLOCK0_PLLLOCK_SHIFT                  (0U)
#define CSL_BOOTCFG_LED_PLLLOCK0_PLLLOCK_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_LED_PLLLOCK0_PLLLOCK_MAX                    (0x00000001U)

#define CSL_BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK_MASK            (0x00000002U)
#define CSL_BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK_SHIFT           (1U)
#define CSL_BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK_MAX             (0x00000001U)

#define CSL_BOOTCFG_LED_PLLLOCK0_RESETVAL                       (0x00000000U)

/* LED_PLLLOCK1 */

#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_CODE_LOADED0_MASK          (0x00000001U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_CODE_LOADED0_SHIFT         (0U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_CODE_LOADED0_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_CODE_LOADED0_MAX           (0x00000001U)

#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_EXE_OK0_MASK               (0x00000002U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_EXE_OK0_SHIFT              (1U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_EXE_OK0_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_EXE_OK0_MAX                (0x00000001U)

#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_GENERAL_MASK               (0x1FFF0000U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_GENERAL_SHIFT              (16U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_GENERAL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_GENERAL_MAX                (0x00001fffU)

#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_SUSP_CTL_MASK              (0x80000000U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_SUSP_CTL_SHIFT             (31U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_SUSP_CTL_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_LED_PLLLOCK1_GEM_SUSP_CTL_MAX               (0x00000001U)

#define CSL_BOOTCFG_LED_PLLLOCK1_RESETVAL                       (0x00000002U)

/* LED_CHIP_PASSDONE */

#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS_MASK            (0x00000001U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS_SHIFT           (0U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS_MAX             (0x00000001U)

#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE_MASK            (0x00000002U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE_SHIFT           (1U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE_MAX             (0x00000001U)

#define CSL_BOOTCFG_LED_CHIP_PASSDONE_LED_CHIP_PASSDONE_RSVD_MASK  (0xFFFFFFFCU)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_LED_CHIP_PASSDONE_RSVD_SHIFT  (2U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_LED_CHIP_PASSDONE_RSVD_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_LED_CHIP_PASSDONE_LED_CHIP_PASSDONE_RSVD_MAX  (0x3fffffffU)

#define CSL_BOOTCFG_LED_CHIP_PASSDONE_RESETVAL                  (0x00000000U)

/* TDIODE */

#define CSL_BOOTCFG_TDIODE_TDIODE_MASK                          (0xFFFFFFFFU)
#define CSL_BOOTCFG_TDIODE_TDIODE_SHIFT                         (0U)
#define CSL_BOOTCFG_TDIODE_TDIODE_RESETVAL                      (0x00000000U)
#define CSL_BOOTCFG_TDIODE_TDIODE_MAX                           (0xffffffffU)

#define CSL_BOOTCFG_TDIODE_RESETVAL                             (0x00000000U)

/* MARGIN0 */

#define CSL_BOOTCFG_MARGIN0_DFTWRITE0_MASK                      (0x00FFFFFFU)
#define CSL_BOOTCFG_MARGIN0_DFTWRITE0_SHIFT                     (0U)
#define CSL_BOOTCFG_MARGIN0_DFTWRITE0_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_MARGIN0_DFTWRITE0_MAX                       (0x00ffffffU)

#define CSL_BOOTCFG_MARGIN0_BTCFG_MARGIN_EN_MASK                (0x80000000U)
#define CSL_BOOTCFG_MARGIN0_BTCFG_MARGIN_EN_SHIFT               (31U)
#define CSL_BOOTCFG_MARGIN0_BTCFG_MARGIN_EN_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_MARGIN0_BTCFG_MARGIN_EN_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MARGIN0_RESETVAL                            (0x00000000U)

/* MARGIN1 */

#define CSL_BOOTCFG_MARGIN1_DFTWRITE1_MASK                      (0x00FFFFFFU)
#define CSL_BOOTCFG_MARGIN1_DFTWRITE1_SHIFT                     (0U)
#define CSL_BOOTCFG_MARGIN1_DFTWRITE1_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_MARGIN1_DFTWRITE1_MAX                       (0x00ffffffU)

#define CSL_BOOTCFG_MARGIN1_RESETVAL                            (0x00000000U)

/* MARGIN2 */

#define CSL_BOOTCFG_MARGIN2_DFTREAD0_MASK                       (0x00FFFFFFU)
#define CSL_BOOTCFG_MARGIN2_DFTREAD0_SHIFT                      (0U)
#define CSL_BOOTCFG_MARGIN2_DFTREAD0_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_MARGIN2_DFTREAD0_MAX                        (0x00ffffffU)

#define CSL_BOOTCFG_MARGIN2_RESETVAL                            (0x00000000U)

/* EFUSE_SECROM_CHKSUM0 */

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM0_EFUSE_SECROM_CHKSUM0_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM0_EFUSE_SECROM_CHKSUM0_SHIFT  (0U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM0_EFUSE_SECROM_CHKSUM0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM0_EFUSE_SECROM_CHKSUM0_MAX  (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM0_RESETVAL               (0x00000000U)

/* EFUSE_SECROM_CHKSUM1 */

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM1_EFUSE_SECROM_CHKSUM1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM1_EFUSE_SECROM_CHKSUM1_SHIFT  (0U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM1_EFUSE_SECROM_CHKSUM1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM1_EFUSE_SECROM_CHKSUM1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM1_RESETVAL               (0x00000000U)

/* EFUSE_SECROM_CHKSUM2 */

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM2_EFUSE_SECROM_CHKSUM2_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM2_EFUSE_SECROM_CHKSUM2_SHIFT  (0U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM2_EFUSE_SECROM_CHKSUM2_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM2_EFUSE_SECROM_CHKSUM2_MAX  (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM2_RESETVAL               (0x00000000U)

/* EFUSE_SECROM_CHKSUM3 */

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM3_EFUSE_SECROM_CHKSUM3_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM3_EFUSE_SECROM_CHKSUM3_SHIFT  (0U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM3_EFUSE_SECROM_CHKSUM3_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM3_EFUSE_SECROM_CHKSUM3_MAX  (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_SECROM_CHKSUM3_RESETVAL               (0x00000000U)

/* INT_SPARE0 */

#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_SELECT_MASK          (0x00000007U)
#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_SELECT_SHIFT         (0U)
#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_SELECT_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_SELECT_MAX           (0x00000007U)

#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_EN_MASK              (0x00000008U)
#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_EN_SHIFT             (3U)
#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_EN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_SERDES_TEST_EN_MAX               (0x00000001U)

#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_DONE_MASK           (0x000000F0U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_DONE_SHIFT          (4U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_DONE_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_DONE_MAX            (0x0000000fU)

#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_ERR_MASK            (0x00000F00U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_ERR_SHIFT           (8U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_ERR_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_AUTOLOAD_ERR_MAX             (0x0000000fU)

#define CSL_BOOTCFG_INT_SPARE0_EFC_ERR_MASK                     (0x00001000U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_ERR_SHIFT                    (12U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_ERR_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_ERR_MAX                      (0x00000001U)

#define CSL_BOOTCFG_INT_SPARE0_EFC_INFO_MASK                    (0x00002000U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_INFO_SHIFT                   (13U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_INFO_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_EFC_INFO_MAX                     (0x00000001U)

#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT0_MASK                  (0x1FFFC000U)
#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT0_SHIFT                 (14U)
#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT0_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT0_MAX                   (0x00007fffU)

#define CSL_BOOTCFG_INT_SPARE0_TETRIS_SPAREIN4_MASK             (0x20000000U)
#define CSL_BOOTCFG_INT_SPARE0_TETRIS_SPAREIN4_SHIFT            (29U)
#define CSL_BOOTCFG_INT_SPARE0_TETRIS_SPAREIN4_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_TETRIS_SPAREIN4_MAX              (0x00000001U)

#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT1_MASK                  (0xC0000000U)
#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT1_SHIFT                 (30U)
#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT1_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE0_SPARE_OUT1_MAX                   (0x00000003U)

#define CSL_BOOTCFG_INT_SPARE0_RESETVAL                         (0x00000000U)

/* INT_SPARE1 */

#define CSL_BOOTCFG_INT_SPARE1_SPARE_OUT_MASK                   (0xFFFFFFFFU)
#define CSL_BOOTCFG_INT_SPARE1_SPARE_OUT_SHIFT                  (0U)
#define CSL_BOOTCFG_INT_SPARE1_SPARE_OUT_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_INT_SPARE1_SPARE_OUT_MAX                    (0xffffffffU)

#define CSL_BOOTCFG_INT_SPARE1_RESETVAL                         (0x00000000U)

/* CHIP_MISC_CTL1 */

#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2RDLAT_MASK   (0x00000078U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2RDLAT_SHIFT  (3U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2RDLAT_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2RDLAT_MAX    (0x0000000fU)

#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2ACS_LAT_MASK  (0x00000780U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2ACS_LAT_SHIFT  (7U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2ACS_LAT_RESETVAL  (0x00000003U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_L2ACS_LAT_MAX  (0x0000000fU)

#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_EMIF4F_PSC_LOCK_N_MASK  (0x00000800U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_EMIF4F_PSC_LOCK_N_SHIFT  (11U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_EMIF4F_PSC_LOCK_N_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_CHIP_MISC_GEM_EMIF4F_PSC_LOCK_N_MAX  (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL1_TETRIS_PBIST_ENABLE_MASK     (0x00001000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_TETRIS_PBIST_ENABLE_SHIFT    (12U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_TETRIS_PBIST_ENABLE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_CHIP_MISC_CTL1_TETRIS_PBIST_ENABLE_MAX      (0x00000001U)

#define CSL_BOOTCFG_CHIP_MISC_CTL1_RESETVAL                     (0x00000198U)

/* OBSCLKCTL */

#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_MASK               (0x00000007U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_SHIFT              (0U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_MAIN_PLL           (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_DSS_PLL            (0x00000001U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_ARM_PLL            (0x00000002U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_UART_PLL           (0x00000003U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_ICSS_PLL           (0x00000004U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_DDR3A_PLL          (0x00000005U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_PLL_CONTROLLER_OBSCLK  (0x00000006U)
#define CSL_BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL_NSS_PLL            (0x00000007U)

#define CSL_BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN_MASK            (0x00000008U)
#define CSL_BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN_SHIFT           (3U)
#define CSL_BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN_MAX             (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_ARMPLL_OBSCLK_EN_MASK             (0x00000010U)
#define CSL_BOOTCFG_OBSCLKCTL_ARMPLL_OBSCLK_EN_SHIFT            (4U)
#define CSL_BOOTCFG_OBSCLKCTL_ARMPLL_OBSCLK_EN_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_ARMPLL_OBSCLK_EN_MAX              (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN_MASK           (0x00000020U)
#define CSL_BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN_SHIFT          (5U)
#define CSL_BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN_MAX            (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN_MASK             (0x00000040U)
#define CSL_BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN_SHIFT            (6U)
#define CSL_BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN_MAX              (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_DSSPLL_OBSCLK_EN_MASK             (0x00000080U)
#define CSL_BOOTCFG_OBSCLKCTL_DSSPLL_OBSCLK_EN_SHIFT            (7U)
#define CSL_BOOTCFG_OBSCLKCTL_DSSPLL_OBSCLK_EN_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_DSSPLL_OBSCLK_EN_MAX              (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_ICSSPLL_OBSCLK_EN_MASK            (0x00000100U)
#define CSL_BOOTCFG_OBSCLKCTL_ICSSPLL_OBSCLK_EN_SHIFT           (8U)
#define CSL_BOOTCFG_OBSCLKCTL_ICSSPLL_OBSCLK_EN_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_ICSSPLL_OBSCLK_EN_MAX             (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_UARTPLL_OBSCLK_EN_MASK            (0x00000200U)
#define CSL_BOOTCFG_OBSCLKCTL_UARTPLL_OBSCLK_EN_SHIFT           (9U)
#define CSL_BOOTCFG_OBSCLKCTL_UARTPLL_OBSCLK_EN_RESETVAL        (0x00000000U)
#define CSL_BOOTCFG_OBSCLKCTL_UARTPLL_OBSCLK_EN_MAX             (0x00000001U)

#define CSL_BOOTCFG_OBSCLKCTL_RESETVAL                          (0x00000000U)

/* EFUSE_BOOTROM */

#define CSL_BOOTCFG_EFUSE_BOOTROM_DEVICE_SPEED_MASK             (0x0FFF0000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_DEVICE_SPEED_SHIFT            (16U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_DEVICE_SPEED_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_DEVICE_SPEED_MAX              (0x00000fffU)

#define CSL_BOOTCFG_EFUSE_BOOTROM_ARM_SPEED_MASK                (0x00000FFFU)
#define CSL_BOOTCFG_EFUSE_BOOTROM_ARM_SPEED_SHIFT               (0U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_ARM_SPEED_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_ARM_SPEED_MAX                 (0x00000fffU)

#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD0_MASK              (0x0000F000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD0_SHIFT             (12U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD0_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD0_MAX               (0x0000000fU)

#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD1_MASK              (0x30000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD1_SHIFT             (28U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD1_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_EFUSE_RSVD1_MAX               (0x00000003U)

#define CSL_BOOTCFG_EFUSE_BOOTROM_CHK_ROM_DIS_MASK              (0x40000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_CHK_ROM_DIS_SHIFT             (30U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_CHK_ROM_DIS_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_CHK_ROM_DIS_MAX               (0x00000001U)

#define CSL_BOOTCFG_EFUSE_BOOTROM_CH_OVERRIDE_EN_MASK           (0x80000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_CH_OVERRIDE_EN_SHIFT          (31U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_CH_OVERRIDE_EN_RESETVAL       (0x00000000U)
#define CSL_BOOTCFG_EFUSE_BOOTROM_CH_OVERRIDE_EN_MAX            (0x00000001U)

#define CSL_BOOTCFG_EFUSE_BOOTROM_RESETVAL                      (0x00000000U)

/* EFUSE_SOFTWARE */

#define CSL_BOOTCFG_EFUSE_SOFTWARE_EFUSE_SOFTWARE_MASK          (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_SOFTWARE_EFUSE_SOFTWARE_SHIFT         (0U)
#define CSL_BOOTCFG_EFUSE_SOFTWARE_EFUSE_SOFTWARE_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_EFUSE_SOFTWARE_EFUSE_SOFTWARE_MAX           (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_SOFTWARE_RESETVAL                     (0x00000000U)

/* EFUSE_TRIM */

#define CSL_BOOTCFG_EFUSE_TRIM_EFUSE_TRIM_MASK                  (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_TRIM_EFUSE_TRIM_SHIFT                 (0U)
#define CSL_BOOTCFG_EFUSE_TRIM_EFUSE_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EFUSE_TRIM_EFUSE_TRIM_MAX                   (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_TRIM_RESETVAL                         (0x00000000U)

/* EFUSE_RSVD */

#define CSL_BOOTCFG_EFUSE_RSVD_EFUSE_RSVD_MASK                  (0xFFFFFFFFU)
#define CSL_BOOTCFG_EFUSE_RSVD_EFUSE_RSVD_SHIFT                 (0U)
#define CSL_BOOTCFG_EFUSE_RSVD_EFUSE_RSVD_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EFUSE_RSVD_EFUSE_RSVD_MAX                   (0xffffffffU)

#define CSL_BOOTCFG_EFUSE_RSVD_RESETVAL                         (0x00000000U)

/* PWRSWTCH_WKUP_MODE0_0 */

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD0_MODE0_0_MASK      (0x00000001U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD0_MODE0_0_SHIFT     (0U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD0_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD0_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD1_MODE0_0_MASK      (0x00000002U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD1_MODE0_0_SHIFT     (1U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD1_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD1_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD2_MODE0_0_MASK      (0x00000004U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD2_MODE0_0_SHIFT     (2U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD2_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD2_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD3_MODE0_0_MASK      (0x00000008U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD3_MODE0_0_SHIFT     (3U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD3_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD3_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD4_MODE0_0_MASK      (0x00000010U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD4_MODE0_0_SHIFT     (4U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD4_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD4_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD5_MODE0_0_MASK      (0x00000020U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD5_MODE0_0_SHIFT     (5U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD5_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD5_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD6_MODE0_0_MASK      (0x00000040U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD6_MODE0_0_SHIFT     (6U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD6_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD6_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD7_MODE0_0_MASK      (0x00000080U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD7_MODE0_0_SHIFT     (7U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD7_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD7_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD8_MODE0_0_MASK      (0x00000100U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD8_MODE0_0_SHIFT     (8U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD8_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD8_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD9_MODE0_0_MASK      (0x00000200U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD9_MODE0_0_SHIFT     (9U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD9_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD9_MODE0_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD10_MODE0_0_MASK     (0x00000400U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD10_MODE0_0_SHIFT    (10U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD10_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD10_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD11_MODE0_0_MASK     (0x00000800U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD11_MODE0_0_SHIFT    (11U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD11_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD11_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD12_MODE0_0_MASK     (0x00001000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD12_MODE0_0_SHIFT    (12U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD12_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD12_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD13_MODE0_0_MASK     (0x00002000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD13_MODE0_0_SHIFT    (13U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD13_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD13_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD14_MODE0_0_MASK     (0x00004000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD14_MODE0_0_SHIFT    (14U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD14_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD14_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD15_MODE0_0_MASK     (0x00008000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD15_MODE0_0_SHIFT    (15U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD15_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD15_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD16_MODE0_0_MASK     (0x00010000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD16_MODE0_0_SHIFT    (16U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD16_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD16_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD17_MODE0_0_MASK     (0x00020000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD17_MODE0_0_SHIFT    (17U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD17_MODE0_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_PD17_MODE0_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_0_RESETVAL              (0x00000000U)

/* PWRSWTCH_WKUP_MODE0_1 */

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_1_PWRSWTCH_WKUP_MODE0_1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_1_PWRSWTCH_WKUP_MODE0_1_SHIFT  (0U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_1_PWRSWTCH_WKUP_MODE0_1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_1_PWRSWTCH_WKUP_MODE0_1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE0_1_RESETVAL              (0x00000000U)

/* PWRSWTCH_WKUP_MODE1_0 */

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD0_MODE1_0_MASK      (0x00000001U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD0_MODE1_0_SHIFT     (0U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD0_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD0_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD1_MODE1_0_MASK      (0x00000002U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD1_MODE1_0_SHIFT     (1U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD1_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD1_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD2_MODE1_0_MASK      (0x00000004U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD2_MODE1_0_SHIFT     (2U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD2_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD2_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD3_MODE1_0_MASK      (0x00000008U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD3_MODE1_0_SHIFT     (3U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD3_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD3_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD4_MODE1_0_MASK      (0x00000010U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD4_MODE1_0_SHIFT     (4U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD4_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD4_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD5_MODE1_0_MASK      (0x00000020U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD5_MODE1_0_SHIFT     (5U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD5_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD5_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD6_MODE1_0_MASK      (0x00000040U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD6_MODE1_0_SHIFT     (6U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD6_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD6_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD7_MODE1_0_MASK      (0x00000080U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD7_MODE1_0_SHIFT     (7U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD7_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD7_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD8_MODE1_0_MASK      (0x00000100U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD8_MODE1_0_SHIFT     (8U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD8_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD8_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD9_MODE1_0_MASK      (0x00000200U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD9_MODE1_0_SHIFT     (9U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD9_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD9_MODE1_0_MAX       (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD10_MODE1_0_MASK     (0x00000400U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD10_MODE1_0_SHIFT    (10U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD10_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD10_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD11_MODE1_0_MASK     (0x00000800U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD11_MODE1_0_SHIFT    (11U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD11_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD11_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD12_MODE1_0_MASK     (0x00001000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD12_MODE1_0_SHIFT    (12U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD12_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD12_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD13_MODE1_0_MASK     (0x00002000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD13_MODE1_0_SHIFT    (13U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD13_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD13_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD14_MODE1_0_MASK     (0x00004000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD14_MODE1_0_SHIFT    (14U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD14_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD14_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD15_MODE1_0_MASK     (0x00008000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD15_MODE1_0_SHIFT    (15U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD15_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD15_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD16_MODE1_0_MASK     (0x00010000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD16_MODE1_0_SHIFT    (16U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD16_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD16_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD17_MODE1_0_MASK     (0x00020000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD17_MODE1_0_SHIFT    (17U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD17_MODE1_0_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_PD17_MODE1_0_MAX      (0x00000001U)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_0_RESETVAL              (0x00000000U)

/* PWRSWTCH_WKUP_MODE1_1 */

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_1_PWRSWTCH_WKUP_MODE1_1_MASK  (0xFFFFFFFFU)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_1_PWRSWTCH_WKUP_MODE1_1_SHIFT  (0U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_1_PWRSWTCH_WKUP_MODE1_1_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_1_PWRSWTCH_WKUP_MODE1_1_MAX  (0xffffffffU)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_MODE1_1_RESETVAL              (0x00000000U)

/* PWRSWTCH_WKUP_CTL */

#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_PGOOD_DELAY_CNT_MASK      (0x000000FFU)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_PGOOD_DELAY_CNT_SHIFT     (0U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_PGOOD_DELAY_CNT_RESETVAL  (0x0000000fU)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_PGOOD_DELAY_CNT_MAX       (0x000000ffU)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_DROOP_DELAY_CNT_MASK      (0x0000FF00U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_DROOP_DELAY_CNT_SHIFT     (8U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_DROOP_DELAY_CNT_RESETVAL  (0x0000000fU)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_DROOP_DELAY_CNT_MAX       (0x000000ffU)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_WAKE_CNT_MASK             (0x00FF0000U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_WAKE_CNT_SHIFT            (16U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_WAKE_CNT_RESETVAL         (0x00000088U)
#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_WAKE_CNT_MAX              (0x000000ffU)

#define CSL_BOOTCFG_PWRSWTCH_WKUP_CTL_RESETVAL                  (0x00880f0fU)

/* DFT_USB0_UTMI_CONTROL */

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_MASK  (0x00000001U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_SHIFT  (0U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_MASK  (0x00000002U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_SHIFT  (1U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_MASK  (0x00000004U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_SHIFT  (2U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_OPMODE_MASK  (0x00000018U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_OPMODE_SHIFT  (3U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_OPMODE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_OPMODE_MAX  (0x00000003U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SLEEPM_MASK  (0x00000020U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SLEEPM_SHIFT  (5U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SLEEPM_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SLEEPM_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_MASK  (0x00000040U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_SHIFT  (6U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TERMSEL_MASK  (0x00000080U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TERMSEL_SHIFT  (7U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TERMSEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TERMSEL_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_MASK  (0x00000100U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_SHIFT  (8U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_MASK  (0x00000600U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_SHIFT  (9U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_MAX  (0x00000003U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATA_MASK  (0x0007F800U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATA_SHIFT  (11U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATA_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATA_MAX  (0x000000ffU)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATAH_MASK  (0x07F80000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATAH_SHIFT  (19U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATAH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXDATAH_MAX  (0x000000ffU)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALID_MASK  (0x08000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALID_SHIFT  (27U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALID_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALID_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_MASK  (0x10000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_SHIFT  (28U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB0_UTMI_CONTROL_RESETVAL              (0x00000000U)

/* DFT_USB1_UTMI_CONTROL */

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_MASK  (0x00000001U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_SHIFT  (0U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TC_TEST_UTMI_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_MASK  (0x00000002U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_SHIFT  (1U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DMPULLDOWN_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_MASK  (0x00000004U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_SHIFT  (2U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_DPPULLDOWN_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_OPMODE_MASK  (0x00000018U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_OPMODE_SHIFT  (3U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_OPMODE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_OPMODE_MAX  (0x00000003U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SLEEPM_MASK  (0x00000020U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SLEEPM_SHIFT  (5U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SLEEPM_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SLEEPM_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_MASK  (0x00000040U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_SHIFT  (6U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_SUSPENDM_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TERMSEL_MASK  (0x00000080U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TERMSEL_SHIFT  (7U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TERMSEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TERMSEL_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_MASK  (0x00000100U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_SHIFT  (8U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_WORDINTERFACE_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_MASK  (0x00000600U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_SHIFT  (9U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_XCVRSEL_MAX  (0x00000003U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATA_MASK  (0x0007F800U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATA_SHIFT  (11U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATA_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATA_MAX  (0x000000ffU)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATAH_MASK  (0x07F80000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATAH_SHIFT  (19U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATAH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXDATAH_MAX  (0x000000ffU)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALID_MASK  (0x08000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALID_SHIFT  (27U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALID_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALID_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_MASK  (0x10000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_SHIFT  (28U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_USB_PHY_TU_TXVALIDH_MAX  (0x00000001U)

#define CSL_BOOTCFG_DFT_USB1_UTMI_CONTROL_RESETVAL              (0x00000000U)

/* DFT_EHRPWM */

#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM0_BREAKDELAYLINEPATH_MASK   (0x00000001U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM0_BREAKDELAYLINEPATH_SHIFT  (0U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM0_BREAKDELAYLINEPATH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM0_BREAKDELAYLINEPATH_MAX    (0x00000001U)

#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM1_BREAKDELAYLINEPATH_MASK   (0x00000002U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM1_BREAKDELAYLINEPATH_SHIFT  (1U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM1_BREAKDELAYLINEPATH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM1_BREAKDELAYLINEPATH_MAX    (0x00000001U)

#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM2_BREAKDELAYLINEPATH_MASK   (0x00000004U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM2_BREAKDELAYLINEPATH_SHIFT  (2U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM2_BREAKDELAYLINEPATH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM2_BREAKDELAYLINEPATH_MAX    (0x00000001U)

#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM3_BREAKDELAYLINEPATH_MASK   (0x00000008U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM3_BREAKDELAYLINEPATH_SHIFT  (3U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM3_BREAKDELAYLINEPATH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM3_BREAKDELAYLINEPATH_MAX    (0x00000001U)

#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM4_BREAKDELAYLINEPATH_MASK   (0x00000010U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM4_BREAKDELAYLINEPATH_SHIFT  (4U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM4_BREAKDELAYLINEPATH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM4_BREAKDELAYLINEPATH_MAX    (0x00000001U)

#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM5_BREAKDELAYLINEPATH_MASK   (0x00000020U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM5_BREAKDELAYLINEPATH_SHIFT  (5U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM5_BREAKDELAYLINEPATH_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DFT_EHRPWM_HRPWM5_BREAKDELAYLINEPATH_MAX    (0x00000001U)

#define CSL_BOOTCFG_DFT_EHRPWM_RESETVAL                         (0x00000000U)

/* MARGIN3 */

#define CSL_BOOTCFG_MARGIN3_DFTREAD1_MASK                       (0x00FFFFFFU)
#define CSL_BOOTCFG_MARGIN3_DFTREAD1_SHIFT                      (0U)
#define CSL_BOOTCFG_MARGIN3_DFTREAD1_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_MARGIN3_DFTREAD1_MAX                        (0x00ffffffU)

#define CSL_BOOTCFG_MARGIN3_RESETVAL                            (0x00000000U)

/* IO_CLKLB_CTL */

#define CSL_BOOTCFG_IO_CLKLB_CTL_CLKLB_CTL_MASK                 (0xFFFFFFFFU)
#define CSL_BOOTCFG_IO_CLKLB_CTL_CLKLB_CTL_SHIFT                (0U)
#define CSL_BOOTCFG_IO_CLKLB_CTL_CLKLB_CTL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_IO_CLKLB_CTL_CLKLB_CTL_MAX                  (0xffffffffU)

#define CSL_BOOTCFG_IO_CLKLB_CTL_RESETVAL                       (0x00000000U)

/* EVENT_MUXCTL0 */

#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL0_MASK                  (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL0_SHIFT                 (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL0_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL0_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL1_MASK                  (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL1_SHIFT                 (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL1_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL1_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL2_MASK                  (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL2_SHIFT                 (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL2_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL2_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL3_MASK                  (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL3_SHIFT                 (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL3_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL0_EVTSEL3_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL0_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL1 */

#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL4_MASK                  (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL4_SHIFT                 (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL4_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL4_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL5_MASK                  (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL5_SHIFT                 (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL5_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL5_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL6_MASK                  (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL6_SHIFT                 (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL6_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL6_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL7_MASK                  (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL7_SHIFT                 (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL7_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL1_EVTSEL7_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL1_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL2 */

#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL8_MASK                  (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL8_SHIFT                 (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL8_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL8_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL9_MASK                  (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL9_SHIFT                 (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL9_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL9_MAX                   (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL10_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL10_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL10_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL10_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL11_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL11_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL11_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL2_EVTSEL11_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL2_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL3 */

#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL12_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL12_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL12_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL12_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL13_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL13_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL13_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL13_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL14_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL14_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL14_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL14_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL15_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL15_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL15_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL3_EVTSEL15_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL3_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL4 */

#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL16_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL16_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL16_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL16_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL17_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL17_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL17_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL17_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL18_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL18_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL18_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL18_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL19_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL19_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL19_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL4_EVTSEL19_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL4_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL5 */

#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL20_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL20_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL20_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL20_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL21_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL21_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL21_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL21_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL22_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL22_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL22_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL22_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL23_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL23_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL23_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL5_EVTSEL23_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL5_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL6 */

#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL24_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL24_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL24_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL24_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL25_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL25_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL25_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL25_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL26_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL26_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL26_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL26_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL27_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL27_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL27_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL6_EVTSEL27_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL6_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL7 */

#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL28_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL28_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL28_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL28_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL29_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL29_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL29_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL29_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL30_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL30_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL30_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL30_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL31_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL31_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL31_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL7_EVTSEL31_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL7_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL8 */

#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL32_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL32_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL32_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL32_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL33_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL33_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL33_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL33_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL34_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL34_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL34_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL34_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL35_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL35_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL35_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL8_EVTSEL35_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL8_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL9 */

#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL36_MASK                 (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL36_SHIFT                (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL36_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL36_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL37_MASK                 (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL37_SHIFT                (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL37_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL37_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL38_MASK                 (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL38_SHIFT                (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL38_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL38_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL39_MASK                 (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL39_SHIFT                (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL39_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL9_EVTSEL39_MAX                  (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL9_RESETVAL                      (0x00000000U)

/* EVENT_MUXCTL10 */

#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL40_MASK                (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL40_SHIFT               (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL40_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL40_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL41_MASK                (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL41_SHIFT               (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL41_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL41_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL42_MASK                (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL42_SHIFT               (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL42_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL42_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL43_MASK                (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL43_SHIFT               (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL43_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL10_EVTSEL43_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL10_RESETVAL                     (0x00000000U)

/* EVENT_MUXCTL11 */

#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL44_MASK                (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL44_SHIFT               (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL44_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL44_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL45_MASK                (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL45_SHIFT               (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL45_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL45_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL46_MASK                (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL46_SHIFT               (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL46_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL46_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL47_MASK                (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL47_SHIFT               (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL47_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL11_EVTSEL47_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL11_RESETVAL                     (0x00000000U)

/* EVENT_MUXCTL12 */

#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL48_MASK                (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL48_SHIFT               (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL48_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL48_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL49_MASK                (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL49_SHIFT               (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL49_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL49_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL50_MASK                (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL50_SHIFT               (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL50_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL50_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL51_MASK                (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL51_SHIFT               (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL51_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL12_EVTSEL51_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL12_RESETVAL                     (0x00000000U)

/* EVENT_MUXCTL13 */

#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL52_MASK                (0x000000FFU)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL52_SHIFT               (0U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL52_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL52_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL53_MASK                (0x0000FF00U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL53_SHIFT               (8U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL53_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL53_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL54_MASK                (0x00FF0000U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL54_SHIFT               (16U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL54_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL54_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL55_MASK                (0xFF000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL55_SHIFT               (24U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL55_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_EVENT_MUXCTL13_EVTSEL55_MAX                 (0x000000ffU)

#define CSL_BOOTCFG_EVENT_MUXCTL13_RESETVAL                     (0x00000000U)

/* DCAN_RAMINIT */

#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_START_MASK       (0x00000001U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_START_SHIFT      (0U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_START_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_START_MAX        (0x00000001U)

#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_START_MASK       (0x00000002U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_START_SHIFT      (1U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_START_RESETVAL   (0x00000000U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_START_MAX        (0x00000001U)

#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_DONE_MASK        (0x00000100U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_DONE_SHIFT       (8U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_DONE_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_DONE_MAX         (0x00000001U)

#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_DONE_MASK        (0x00000200U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_DONE_SHIFT       (9U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_DONE_RESETVAL    (0x00000000U)
#define CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_DONE_MAX         (0x00000001U)

#define CSL_BOOTCFG_DCAN_RAMINIT_RESETVAL                       (0x00000000U)

/* DCAN_RAMINIT_SET */

#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN0_RAMINIT_DONE_MASK    (0x00000100U)
#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN0_RAMINIT_DONE_SHIFT   (8U)
#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN0_RAMINIT_DONE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN0_RAMINIT_DONE_MAX     (0x00000001U)

#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN1_RAMINIT_DONE_MASK    (0x00000200U)
#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN1_RAMINIT_DONE_SHIFT   (9U)
#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN1_RAMINIT_DONE_RESETVAL  (0x00000000U)
#define CSL_BOOTCFG_DCAN_RAMINIT_SET_DCAN1_RAMINIT_DONE_MAX     (0x00000001U)

#define CSL_BOOTCFG_DCAN_RAMINIT_SET_RESETVAL                   (0x00000000U)

/* ETHERNET_CFG */

#define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_MASK                  (0x00000003U)
#define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_SHIFT                 (0U)
#define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_GMII_MII              (0x00000000U)
#define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RMII                  (0x00000001U)
#define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RGMII                 (0x00000002U)

#define CSL_BOOTCFG_ETHERNET_CFG_RESETVAL                       (0x00000000U)

/* MLB_SIG_IO_CTL */

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENP_MASK                     (0x00000001U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENP_SHIFT                    (0U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENP_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENP_MAX                      (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENN_MASK                     (0x00000002U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENN_SHIFT                    (1U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENN_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_ENN_MAX                      (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_LVCMOS_MASK               (0x00000004U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_LVCMOS_SHIFT              (2U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_LVCMOS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_LVCMOS_MAX                (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_EXTRES_MASK               (0x00000008U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_EXTRES_SHIFT              (3U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_EXTRES_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_EXTRES_MAX                (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_TX_MASK                (0x00000010U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_TX_SHIFT               (4U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_TX_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_TX_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_RX_MASK                (0x00000020U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_RX_SHIFT               (5U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_RX_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_PWRDN_RX_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_RX_TRIM_MASK              (0x00000040U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_RX_TRIM_SHIFT             (6U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_RX_TRIM_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_EN_RX_TRIM_MAX               (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_REMOVE_SKEW_MASK             (0x00000080U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_REMOVE_SKEW_SHIFT            (7U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_REMOVE_SKEW_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_REMOVE_SKEW_MAX              (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_P_TRIM_MASK                  (0x00000100U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_P_TRIM_SHIFT                 (8U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_P_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_P_TRIM_MAX                   (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_N_TRIM_MASK                  (0x00000200U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_N_TRIM_SHIFT                 (9U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_N_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_MLB_SIG_IO_CTL_N_TRIM_MAX                   (0x00000001U)

#define CSL_BOOTCFG_MLB_SIG_IO_CTL_RESETVAL                     (0x00000000U)

/* MLB_DAT_IO_CTL */

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENP_MASK                     (0x00000001U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENP_SHIFT                    (0U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENP_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENP_MAX                      (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENN_MASK                     (0x00000002U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENN_SHIFT                    (1U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENN_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_ENN_MAX                      (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_LVCMOS_MASK               (0x00000004U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_LVCMOS_SHIFT              (2U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_LVCMOS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_LVCMOS_MAX                (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_EXTRES_MASK               (0x00000008U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_EXTRES_SHIFT              (3U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_EXTRES_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_EXTRES_MAX                (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_TX_MASK                (0x00000010U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_TX_SHIFT               (4U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_TX_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_TX_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_RX_MASK                (0x00000020U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_RX_SHIFT               (5U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_RX_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_PWRDN_RX_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_RX_TRIM_MASK              (0x00000040U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_RX_TRIM_SHIFT             (6U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_RX_TRIM_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_EN_RX_TRIM_MAX               (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_REMOVE_SKEW_MASK             (0x00000080U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_REMOVE_SKEW_SHIFT            (7U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_REMOVE_SKEW_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_REMOVE_SKEW_MAX              (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_P_TRIM_MASK                  (0x00000100U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_P_TRIM_SHIFT                 (8U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_P_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_P_TRIM_MAX                   (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_N_TRIM_MASK                  (0x00010000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_N_TRIM_SHIFT                 (16U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_N_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_MLB_DAT_IO_CTL_N_TRIM_MAX                   (0x00000001U)

#define CSL_BOOTCFG_MLB_DAT_IO_CTL_RESETVAL                     (0x00000028U)

/* MLB_CLK_BG_CTL */

#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_CLK_MASK               (0x00000001U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_CLK_SHIFT              (0U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_CLK_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_CLK_MAX                (0x00000001U)

#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_BG_MASK                (0x00000010U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_BG_SHIFT               (4U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_BG_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_PWRDN_BG_MAX                 (0x00000001U)

#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_SET_MASK             (0x00000020U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_SET_SHIFT            (5U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_SET_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_SET_MAX              (0x00000001U)

#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_MASK                 (0x00003F00U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_SHIFT                (8U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_MLB_CLK_BG_CTL_BG_TRIM_MAX                  (0x0000003fU)

#define CSL_BOOTCFG_MLB_CLK_BG_CTL_RESETVAL                     (0x00000011U)

/* EPWM_CTL */

#define CSL_BOOTCFG_EPWM_CTL_EPWM0_TBCLKEN_MASK                 (0x00000001U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM0_TBCLKEN_SHIFT                (0U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM0_TBCLKEN_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM0_TBCLKEN_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM1_TBCLKEN_MASK                 (0x00000002U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM1_TBCLKEN_SHIFT                (1U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM1_TBCLKEN_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM1_TBCLKEN_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM2_TBCLKEN_MASK                 (0x00000004U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM2_TBCLKEN_SHIFT                (2U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM2_TBCLKEN_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM2_TBCLKEN_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM3_TBCLKEN_MASK                 (0x00000008U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM3_TBCLKEN_SHIFT                (3U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM3_TBCLKEN_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM3_TBCLKEN_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM4_TBCLKEN_MASK                 (0x00000010U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM4_TBCLKEN_SHIFT                (4U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM4_TBCLKEN_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM4_TBCLKEN_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM5_TBCLKEN_MASK                 (0x00000020U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM5_TBCLKEN_SHIFT                (5U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM5_TBCLKEN_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM5_TBCLKEN_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM3_SYNCSEL_MASK                 (0x00000100U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM3_SYNCSEL_SHIFT                (8U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM3_SYNCSEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM3_SYNCSEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCA_SEL_MASK                 (0x00001000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCA_SEL_SHIFT                (12U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCA_SEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCA_SEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCB_SEL_MASK                 (0x00002000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCB_SEL_SHIFT                (13U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCB_SEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_SOCB_SEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_EPWM_EALLOW_MASK                   (0x00010000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_EALLOW_SHIFT                  (16U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_EALLOW_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_EPWM_CTL_EPWM_EALLOW_MAX                    (0x00000001U)

#define CSL_BOOTCFG_EPWM_CTL_RESETVAL                           (0x00000000U)

/* ECAP_CAPEVT_CTL */

#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP0_CAP_EVT_MASK          (0x0000001FU)
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP0_CAP_EVT_SHIFT         (0U)
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP0_CAP_EVT_RESETVAL      (0x00000000U)
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP0_CAP_EVT_MAX           (0x0000001fU)

#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP1_CAP_EVT_MASK          (0x00001F00U)
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP1_CAP_EVT_SHIFT         (8U)
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP1_CAP_EVT_RESETVAL      (0x00000001U)
#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_ECAP1_CAP_EVT_MAX           (0x0000001fU)

#define CSL_BOOTCFG_ECAP_CAPEVT_CTL_RESETVAL                    (0x00000100U)

/* EQEP_STAT */

#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR0_MASK                   (0x00000001U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR0_SHIFT                  (0U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR0_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR0_MAX                    (0x00000001U)

#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR1_MASK                   (0x00000002U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR1_SHIFT                  (1U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR1_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR1_MAX                    (0x00000001U)

#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR2_MASK                   (0x00000004U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR2_SHIFT                  (2U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR2_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_EQEP_STAT_PHASE_ERR2_MAX                    (0x00000001U)

#define CSL_BOOTCFG_EQEP_STAT_RESETVAL                          (0x00000000U)

/* LVDS_BG_CTL */

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_MASK                 (0x00000003U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_SHIFT                (0U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_MAX                  (0x00000003U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_EN_MASK              (0x00000004U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_EN_SHIFT             (2U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_EN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_TRIM_EN_MAX               (0x00000001U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_PWRDN_BG_MASK             (0x00000008U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_PWRDN_BG_SHIFT            (3U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_PWRDN_BG_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS0_PWRDN_BG_MAX              (0x00000001U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_MASK                 (0x00000030U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_SHIFT                (4U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_MAX                  (0x00000003U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_EN_MASK              (0x00000040U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_EN_SHIFT             (6U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_EN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_TRIM_EN_MAX               (0x00000001U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_PWRDN_BG_MASK             (0x00000080U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_PWRDN_BG_SHIFT            (7U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_PWRDN_BG_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS1_PWRDN_BG_MAX              (0x00000001U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_MASK                 (0x00000300U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_SHIFT                (8U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_MAX                  (0x00000003U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_EN_MASK              (0x00000400U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_EN_SHIFT             (10U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_EN_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_TRIM_EN_MAX               (0x00000001U)

#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_PWRDN_BG_MASK             (0x00000800U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_PWRDN_BG_SHIFT            (11U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_PWRDN_BG_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_LVDS_BG_CTL_LVDS2_PWRDN_BG_MAX              (0x00000001U)

#define CSL_BOOTCFG_LVDS_BG_CTL_RESETVAL                        (0x00000000U)

/* LDO_USB_CTL */

#define CSL_BOOTCFG_LDO_USB_CTL_BGAP_TRIM_MASK                  (0x0000001FU)
#define CSL_BOOTCFG_LDO_USB_CTL_BGAP_TRIM_SHIFT                 (0U)
#define CSL_BOOTCFG_LDO_USB_CTL_BGAP_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_LDO_USB_CTL_BGAP_TRIM_MAX                   (0x0000001fU)

#define CSL_BOOTCFG_LDO_USB_CTL_VSET_MASK                       (0x03FF0000U)
#define CSL_BOOTCFG_LDO_USB_CTL_VSET_SHIFT                      (16U)
#define CSL_BOOTCFG_LDO_USB_CTL_VSET_RESETVAL                   (0x00000000U)
#define CSL_BOOTCFG_LDO_USB_CTL_VSET_MAX                        (0x000003ffU)

#define CSL_BOOTCFG_LDO_USB_CTL_ENFUNC_MASK                     (0x70000000U)
#define CSL_BOOTCFG_LDO_USB_CTL_ENFUNC_SHIFT                    (28U)
#define CSL_BOOTCFG_LDO_USB_CTL_ENFUNC_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_LDO_USB_CTL_ENFUNC_MAX                      (0x00000007U)

#define CSL_BOOTCFG_LDO_USB_CTL_RESETVAL                        (0x00000000U)

/* LDO_PCIE_CTL */

#define CSL_BOOTCFG_LDO_PCIE_CTL_BGAP_TRIM_MASK                 (0x0000001FU)
#define CSL_BOOTCFG_LDO_PCIE_CTL_BGAP_TRIM_SHIFT                (0U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_BGAP_TRIM_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_BGAP_TRIM_MAX                  (0x0000001fU)

#define CSL_BOOTCFG_LDO_PCIE_CTL_VSET_MASK                      (0x03FF0000U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_VSET_SHIFT                     (16U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_VSET_RESETVAL                  (0x00000000U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_VSET_MAX                       (0x000003ffU)

#define CSL_BOOTCFG_LDO_PCIE_CTL_ENFUNC_MASK                    (0x70000000U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_ENFUNC_SHIFT                   (28U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_ENFUNC_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_LDO_PCIE_CTL_ENFUNC_MAX                     (0x00000007U)

#define CSL_BOOTCFG_LDO_PCIE_CTL_RESETVAL                       (0x00000000U)

/* BAW_CTL */

#define CSL_BOOTCFG_BAW_CTL_RCOSC_EN_MASK                       (0x00000001U)
#define CSL_BOOTCFG_BAW_CTL_RCOSC_EN_SHIFT                      (0U)
#define CSL_BOOTCFG_BAW_CTL_RCOSC_EN_RESETVAL                   (0x00000001U)
#define CSL_BOOTCFG_BAW_CTL_RCOSC_EN_MAX                        (0x00000001U)

#define CSL_BOOTCFG_BAW_CTL_BAW_EN_MASK                         (0x00000002U)
#define CSL_BOOTCFG_BAW_CTL_BAW_EN_SHIFT                        (1U)
#define CSL_BOOTCFG_BAW_CTL_BAW_EN_RESETVAL                     (0x00000001U)
#define CSL_BOOTCFG_BAW_CTL_BAW_EN_MAX                          (0x00000001U)

#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_PCLKOU_MASK              (0x00000038U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_PCLKOU_SHIFT             (3U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_PCLKOU_RESETVAL          (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_PCLKOU_MAX               (0x00000007U)

#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_CLKOUT_MASK              (0x000001C0U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_CLKOUT_SHIFT             (6U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_CLKOUT_RESETVAL          (0x00000004U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIVSEL_CLKOUT_MAX               (0x00000007U)

#define CSL_BOOTCFG_BAW_CTL_BAW_DIV_RESETZ_MASK                 (0x00000200U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIV_RESETZ_SHIFT                (9U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIV_RESETZ_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIV_RESETZ_MAX                  (0x00000001U)

#define CSL_BOOTCFG_BAW_CTL_BAW_CLKGOOD_MASK                    (0x00000400U)
#define CSL_BOOTCFG_BAW_CTL_BAW_CLKGOOD_SHIFT                   (10U)
#define CSL_BOOTCFG_BAW_CTL_BAW_CLKGOOD_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_CLKGOOD_MAX                     (0x00000001U)

#define CSL_BOOTCFG_BAW_CTL_BAW_CLKOUT_DISABLE_MASK             (0x00000800U)
#define CSL_BOOTCFG_BAW_CTL_BAW_CLKOUT_DISABLE_SHIFT            (11U)
#define CSL_BOOTCFG_BAW_CTL_BAW_CLKOUT_DISABLE_RESETVAL         (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_CLKOUT_DISABLE_MAX              (0x00000001U)

#define CSL_BOOTCFG_BAW_CTL_BAW_ATESTSEL_MASK                   (0x000F0000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_ATESTSEL_SHIFT                  (16U)
#define CSL_BOOTCFG_BAW_CTL_BAW_ATESTSEL_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_ATESTSEL_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_BAW_CTL_BAW_DIGTEST_MASK                    (0x00700000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIGTEST_SHIFT                   (20U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIGTEST_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_DIGTEST_MAX                     (0x00000007U)

#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_IN_PMT_MASK                (0x03800000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_IN_PMT_SHIFT               (23U)
#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_IN_PMT_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_IN_PMT_MAX                 (0x00000007U)

#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_OUT_PMT_MASK               (0x1C000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_OUT_PMT_SHIFT              (26U)
#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_OUT_PMT_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_BAW_CTL_BAW_PDET_OUT_PMT_MAX                (0x00000007U)

#define CSL_BOOTCFG_BAW_CTL_RESETVAL                            (0x00000103U)

/* BAW_TRIM */

#define CSL_BOOTCFG_BAW_TRIM_BAW_BG_TRIM_MASK                   (0x000000FFU)
#define CSL_BOOTCFG_BAW_TRIM_BAW_BG_TRIM_SHIFT                  (0U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_BG_TRIM_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_BG_TRIM_MAX                    (0x000000ffU)

#define CSL_BOOTCFG_BAW_TRIM_BAW_IBIAS_TRIM_MASK                (0x00001F00U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_IBIAS_TRIM_SHIFT               (8U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_IBIAS_TRIM_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_IBIAS_TRIM_MAX                 (0x0000001fU)

#define CSL_BOOTCFG_BAW_TRIM_BAW_OSCCAP_CTRL_MASK               (0x0001E000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_OSCCAP_CTRL_SHIFT              (13U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_OSCCAP_CTRL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_OSCCAP_CTRL_MAX                (0x0000000fU)

#define CSL_BOOTCFG_BAW_TRIM_BAW_CAP_TRIM_MASK                  (0x00FE0000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_CAP_TRIM_SHIFT                 (17U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_CAP_TRIM_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_CAP_TRIM_MAX                   (0x0000007fU)

#define CSL_BOOTCFG_BAW_TRIM_BAW_FILTER_TRIM_MASK               (0x03000000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_FILTER_TRIM_SHIFT              (24U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_FILTER_TRIM_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_BAW_TRIM_BAW_FILTER_TRIM_MAX                (0x00000003U)

#define CSL_BOOTCFG_BAW_TRIM_RESETVAL                           (0x00000000U)

/* BAW_TS */

#define CSL_BOOTCFG_BAW_TS_BAW_TS_TEMP_MASK                     (0x0000003FU)
#define CSL_BOOTCFG_BAW_TS_BAW_TS_TEMP_SHIFT                    (0U)
#define CSL_BOOTCFG_BAW_TS_BAW_TS_TEMP_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_BAW_TS_BAW_TS_TEMP_MAX                      (0x0000003fU)

#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_IN_MASK                    (0x00FF0000U)
#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_IN_SHIFT                   (16U)
#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_IN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_IN_MAX                     (0x000000ffU)

#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_OUT_MASK                   (0xFF000000U)
#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_OUT_SHIFT                  (24U)
#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_OUT_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_BAW_TS_BAW_SPARE_OUT_MAX                    (0x000000ffU)

#define CSL_BOOTCFG_BAW_TS_RESETVAL                             (0x00000000U)

/* PADCONFIG0 */

#define CSL_BOOTCFG_PADCONFIG0_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG0_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG0_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG0_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG0_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG0_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG0_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG0_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG0_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG0_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG0_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG0_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG0_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG0_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG0_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG0_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS__50B                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS__40C                 (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS__40D                 (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG0_BUFFERCLASS__40E                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG0_RESETVAL                         (0x00140000U)

/* PADCONFIG1 */

#define CSL_BOOTCFG_PADCONFIG1_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG1_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG1_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG1_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG1_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG1_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG1_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG1_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG1_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG1_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG1_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG1_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG1_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG1_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG1_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG1_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG1_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG1_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG1_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG1_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG1_RESETVAL                         (0x00140000U)

/* PADCONFIG2 */

#define CSL_BOOTCFG_PADCONFIG2_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG2_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG2_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG2_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG2_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG2_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG2_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG2_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG2_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG2_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG2_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG2_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG2_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG2_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG2_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG2_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG2_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG2_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG2_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG2_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG2_RESETVAL                         (0x00140000U)

/* PADCONFIG3 */

#define CSL_BOOTCFG_PADCONFIG3_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG3_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG3_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG3_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG3_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG3_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG3_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG3_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG3_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG3_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG3_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG3_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG3_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG3_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG3_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG3_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG3_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG3_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG3_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG3_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG3_RESETVAL                         (0x00140000U)

/* PADCONFIG4 */

#define CSL_BOOTCFG_PADCONFIG4_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG4_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG4_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG4_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG4_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG4_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG4_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG4_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG4_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG4_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG4_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG4_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG4_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG4_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG4_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG4_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG4_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG4_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG4_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG4_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG4_RESETVAL                         (0x00140000U)

/* PADCONFIG5 */

#define CSL_BOOTCFG_PADCONFIG5_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG5_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG5_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG5_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG5_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG5_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG5_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG5_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG5_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG5_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG5_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG5_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG5_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG5_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG5_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG5_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG5_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG5_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG5_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG5_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG5_RESETVAL                         (0x00140000U)

/* PADCONFIG6 */

#define CSL_BOOTCFG_PADCONFIG6_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG6_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG6_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG6_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG6_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG6_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG6_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG6_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG6_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG6_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG6_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG6_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG6_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG6_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG6_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG6_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG6_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG6_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG6_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG6_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG6_RESETVAL                         (0x00140000U)

/* PADCONFIG7 */

#define CSL_BOOTCFG_PADCONFIG7_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG7_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG7_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG7_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG7_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG7_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG7_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG7_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG7_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG7_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG7_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG7_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG7_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG7_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG7_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG7_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG7_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG7_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG7_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG7_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG7_RESETVAL                         (0x00140000U)

/* PADCONFIG8 */

#define CSL_BOOTCFG_PADCONFIG8_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG8_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG8_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG8_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG8_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG8_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG8_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG8_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG8_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG8_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG8_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG8_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG8_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG8_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG8_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG8_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG8_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG8_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG8_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG8_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG8_RESETVAL                         (0x00140000U)

/* PADCONFIG9 */

#define CSL_BOOTCFG_PADCONFIG9_MUXMODE_MASK                     (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG9_MUXMODE_SHIFT                    (0U)
#define CSL_BOOTCFG_PADCONFIG9_MUXMODE_RESETVAL                 (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG9_MUXMODE_MAX                      (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG9_PULLUDEN_MASK                    (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG9_PULLUDEN_SHIFT                   (16U)
#define CSL_BOOTCFG_PADCONFIG9_PULLUDEN_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG9_PULLUDEN_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG9_PULLTYPESEL_MASK                 (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG9_PULLTYPESEL_SHIFT                (17U)
#define CSL_BOOTCFG_PADCONFIG9_PULLTYPESEL_RESETVAL             (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG9_PULLTYPESEL_MAX                  (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG9_RXACTIVE_MASK                    (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG9_RXACTIVE_SHIFT                   (18U)
#define CSL_BOOTCFG_PADCONFIG9_RXACTIVE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG9_RXACTIVE_MAX                     (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG9_BUFFERCLASS_MASK                 (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG9_BUFFERCLASS_SHIFT                (19U)
#define CSL_BOOTCFG_PADCONFIG9_BUFFERCLASS_RESETVAL             (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG9_BUFFERCLASS_MAX                  (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG9_RESETVAL                         (0x00140000U)

/* PADCONFIG10 */

#define CSL_BOOTCFG_PADCONFIG10_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG10_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG10_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG10_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG10_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG10_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG10_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG10_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG10_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG10_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG10_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG10_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG10_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG10_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG10_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG10_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG10_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG10_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG10_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG10_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG10_RESETVAL                        (0x00140000U)

/* PADCONFIG11 */

#define CSL_BOOTCFG_PADCONFIG11_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG11_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG11_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG11_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG11_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG11_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG11_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG11_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG11_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG11_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG11_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG11_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG11_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG11_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG11_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG11_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG11_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG11_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG11_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG11_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG11_RESETVAL                        (0x00140000U)

/* PADCONFIG12 */

#define CSL_BOOTCFG_PADCONFIG12_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG12_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG12_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG12_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG12_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG12_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG12_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG12_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG12_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG12_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG12_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG12_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG12_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG12_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG12_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG12_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG12_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG12_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG12_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG12_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG12_RESETVAL                        (0x00140000U)

/* PADCONFIG13 */

#define CSL_BOOTCFG_PADCONFIG13_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG13_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG13_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG13_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG13_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG13_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG13_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG13_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG13_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG13_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG13_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG13_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG13_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG13_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG13_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG13_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG13_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG13_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG13_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG13_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG13_RESETVAL                        (0x00140000U)

/* PADCONFIG14 */

#define CSL_BOOTCFG_PADCONFIG14_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG14_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG14_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG14_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG14_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG14_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG14_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG14_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG14_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG14_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG14_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG14_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG14_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG14_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG14_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG14_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG14_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG14_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG14_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG14_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG14_RESETVAL                        (0x00140000U)

/* PADCONFIG15 */

#define CSL_BOOTCFG_PADCONFIG15_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG15_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG15_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG15_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG15_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG15_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG15_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG15_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG15_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG15_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG15_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG15_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG15_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG15_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG15_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG15_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG15_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG15_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG15_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG15_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG15_RESETVAL                        (0x00140000U)

/* PADCONFIG16 */

#define CSL_BOOTCFG_PADCONFIG16_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG16_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG16_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG16_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG16_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG16_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG16_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG16_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG16_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG16_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG16_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG16_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG16_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG16_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG16_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG16_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG16_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG16_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG16_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG16_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG16_RESETVAL                        (0x00140000U)

/* PADCONFIG17 */

#define CSL_BOOTCFG_PADCONFIG17_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG17_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG17_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG17_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG17_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG17_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG17_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG17_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG17_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG17_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG17_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG17_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG17_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG17_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG17_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG17_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG17_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG17_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG17_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG17_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG17_RESETVAL                        (0x00160000U)

/* PADCONFIG18 */

#define CSL_BOOTCFG_PADCONFIG18_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG18_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG18_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG18_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG18_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG18_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG18_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG18_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG18_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG18_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG18_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG18_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG18_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG18_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG18_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG18_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG18_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG18_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG18_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG18_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG18_RESETVAL                        (0x00160000U)

/* PADCONFIG19 */

#define CSL_BOOTCFG_PADCONFIG19_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG19_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG19_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG19_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG19_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG19_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG19_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG19_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG19_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG19_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG19_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG19_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG19_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG19_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG19_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG19_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG19_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG19_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG19_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG19_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG19_RESETVAL                        (0x00160000U)

/* PADCONFIG20 */

#define CSL_BOOTCFG_PADCONFIG20_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG20_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG20_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG20_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG20_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG20_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG20_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG20_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG20_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG20_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG20_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG20_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG20_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG20_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG20_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG20_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG20_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG20_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG20_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG20_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG20_RESETVAL                        (0x00160000U)

/* PADCONFIG21 */

#define CSL_BOOTCFG_PADCONFIG21_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG21_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG21_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG21_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG21_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG21_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG21_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG21_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG21_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG21_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG21_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG21_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG21_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG21_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG21_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG21_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG21_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG21_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG21_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG21_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG21_RESETVAL                        (0x00160000U)

/* PADCONFIG22 */

#define CSL_BOOTCFG_PADCONFIG22_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG22_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG22_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG22_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG22_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG22_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG22_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG22_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG22_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG22_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG22_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG22_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG22_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG22_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG22_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG22_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG22_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG22_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG22_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG22_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG22_RESETVAL                        (0x00160000U)

/* PADCONFIG23 */

#define CSL_BOOTCFG_PADCONFIG23_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG23_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG23_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG23_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG23_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG23_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG23_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG23_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG23_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG23_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG23_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG23_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG23_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG23_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG23_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG23_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG23_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG23_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG23_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG23_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG23_RESETVAL                        (0x00160000U)

/* PADCONFIG24 */

#define CSL_BOOTCFG_PADCONFIG24_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG24_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG24_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG24_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG24_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG24_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG24_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG24_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG24_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG24_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG24_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG24_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG24_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG24_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG24_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG24_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG24_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG24_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG24_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG24_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG24_RESETVAL                        (0x00160000U)

/* PADCONFIG25 */

#define CSL_BOOTCFG_PADCONFIG25_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG25_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG25_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG25_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG25_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG25_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG25_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG25_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG25_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG25_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG25_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG25_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG25_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG25_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG25_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG25_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG25_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG25_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG25_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG25_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG25_RESETVAL                        (0x00160000U)

/* PADCONFIG26 */

#define CSL_BOOTCFG_PADCONFIG26_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG26_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG26_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG26_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG26_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG26_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG26_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG26_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG26_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG26_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG26_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG26_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG26_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG26_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG26_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG26_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG26_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG26_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG26_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG26_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG26_RESETVAL                        (0x00160000U)

/* PADCONFIG27 */

#define CSL_BOOTCFG_PADCONFIG27_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG27_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG27_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG27_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG27_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG27_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG27_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG27_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG27_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG27_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG27_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG27_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG27_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG27_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG27_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG27_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG27_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG27_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG27_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG27_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG27_RESETVAL                        (0x00160000U)

/* PADCONFIG28 */

#define CSL_BOOTCFG_PADCONFIG28_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG28_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG28_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG28_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG28_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG28_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG28_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG28_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG28_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG28_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG28_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG28_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG28_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG28_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG28_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG28_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG28_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG28_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG28_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG28_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG28_RESETVAL                        (0x00160000U)

/* PADCONFIG29 */

#define CSL_BOOTCFG_PADCONFIG29_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG29_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG29_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG29_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG29_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG29_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG29_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG29_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG29_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG29_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG29_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG29_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG29_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG29_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG29_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG29_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG29_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG29_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG29_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG29_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG29_RESETVAL                        (0x00160000U)

/* PADCONFIG30 */

#define CSL_BOOTCFG_PADCONFIG30_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG30_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG30_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG30_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG30_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG30_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG30_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG30_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG30_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG30_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG30_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG30_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG30_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG30_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG30_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG30_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG30_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG30_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG30_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG30_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG30_RESETVAL                        (0x00140001U)

/* PADCONFIG31 */

#define CSL_BOOTCFG_PADCONFIG31_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG31_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG31_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG31_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG31_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG31_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG31_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG31_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG31_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG31_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG31_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG31_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG31_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG31_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG31_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG31_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG31_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG31_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG31_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG31_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG31_RESETVAL                        (0x00140001U)

/* PADCONFIG32 */

#define CSL_BOOTCFG_PADCONFIG32_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG32_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG32_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG32_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG32_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG32_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG32_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG32_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG32_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG32_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG32_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG32_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG32_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG32_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG32_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG32_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG32_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG32_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG32_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG32_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG32_RESETVAL                        (0x00140001U)

/* PADCONFIG33 */

#define CSL_BOOTCFG_PADCONFIG33_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG33_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG33_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG33_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG33_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG33_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG33_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG33_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG33_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG33_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG33_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG33_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG33_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG33_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG33_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG33_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG33_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG33_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG33_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG33_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG33_RESETVAL                        (0x00140001U)

/* PADCONFIG34 */

#define CSL_BOOTCFG_PADCONFIG34_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG34_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG34_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG34_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG34_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG34_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG34_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG34_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG34_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG34_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG34_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG34_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG34_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG34_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG34_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG34_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG34_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG34_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG34_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG34_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG34_RESETVAL                        (0x00140001U)

/* PADCONFIG35 */

#define CSL_BOOTCFG_PADCONFIG35_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG35_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG35_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG35_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG35_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG35_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG35_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG35_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG35_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG35_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG35_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG35_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG35_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG35_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG35_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG35_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG35_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG35_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG35_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG35_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG35_RESETVAL                        (0x00140001U)

/* PADCONFIG36 */

#define CSL_BOOTCFG_PADCONFIG36_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG36_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG36_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG36_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG36_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG36_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG36_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG36_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG36_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG36_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG36_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG36_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG36_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG36_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG36_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG36_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG36_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG36_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG36_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG36_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG36_RESETVAL                        (0x00140001U)

/* PADCONFIG37 */

#define CSL_BOOTCFG_PADCONFIG37_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG37_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG37_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG37_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG37_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG37_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG37_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG37_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG37_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG37_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG37_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG37_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG37_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG37_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG37_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG37_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG37_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG37_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG37_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG37_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG37_RESETVAL                        (0x00140001U)

/* PADCONFIG38 */

#define CSL_BOOTCFG_PADCONFIG38_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG38_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG38_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG38_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG38_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG38_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG38_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG38_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG38_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG38_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG38_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG38_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG38_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG38_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG38_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG38_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG38_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG38_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG38_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG38_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG38_RESETVAL                        (0x00140001U)

/* PADCONFIG39 */

#define CSL_BOOTCFG_PADCONFIG39_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG39_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG39_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG39_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG39_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG39_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG39_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG39_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG39_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG39_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG39_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG39_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG39_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG39_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG39_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG39_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG39_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG39_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG39_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG39_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG39_RESETVAL                        (0x00140001U)

/* PADCONFIG40 */

#define CSL_BOOTCFG_PADCONFIG40_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG40_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG40_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG40_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG40_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG40_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG40_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG40_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG40_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG40_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG40_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG40_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG40_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG40_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG40_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG40_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG40_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG40_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG40_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG40_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG40_RESETVAL                        (0x00140001U)

/* PADCONFIG41 */

#define CSL_BOOTCFG_PADCONFIG41_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG41_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG41_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG41_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG41_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG41_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG41_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG41_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG41_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG41_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG41_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG41_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG41_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG41_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG41_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG41_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG41_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG41_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG41_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG41_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG41_RESETVAL                        (0x00140001U)

/* PADCONFIG42 */

#define CSL_BOOTCFG_PADCONFIG42_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG42_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG42_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG42_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG42_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG42_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG42_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG42_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG42_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG42_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG42_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG42_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG42_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG42_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG42_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG42_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG42_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG42_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG42_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG42_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG42_RESETVAL                        (0x00140001U)

/* PADCONFIG43 */

#define CSL_BOOTCFG_PADCONFIG43_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG43_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG43_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG43_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG43_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG43_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG43_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG43_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG43_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG43_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG43_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG43_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG43_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG43_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG43_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG43_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG43_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG43_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG43_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG43_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG43_RESETVAL                        (0x00140001U)

/* PADCONFIG44 */

#define CSL_BOOTCFG_PADCONFIG44_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG44_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG44_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG44_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG44_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG44_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG44_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG44_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG44_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG44_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG44_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG44_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG44_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG44_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG44_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG44_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG44_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG44_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG44_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG44_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG44_RESETVAL                        (0x00140001U)

/* PADCONFIG45 */

#define CSL_BOOTCFG_PADCONFIG45_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG45_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG45_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG45_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG45_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG45_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG45_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG45_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG45_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG45_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG45_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG45_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG45_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG45_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG45_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG45_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG45_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG45_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG45_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG45_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG45_RESETVAL                        (0x00140001U)

/* PADCONFIG46 */

#define CSL_BOOTCFG_PADCONFIG46_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG46_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG46_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG46_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG46_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG46_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG46_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG46_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG46_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG46_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG46_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG46_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG46_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG46_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG46_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG46_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG46_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG46_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG46_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG46_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG46_RESETVAL                        (0x00140001U)

/* PADCONFIG47 */

#define CSL_BOOTCFG_PADCONFIG47_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG47_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG47_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG47_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG47_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG47_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG47_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG47_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG47_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG47_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG47_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG47_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG47_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG47_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG47_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG47_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG47_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG47_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG47_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG47_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG47_RESETVAL                        (0x00140001U)

/* PADCONFIG48 */

#define CSL_BOOTCFG_PADCONFIG48_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG48_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG48_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG48_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG48_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG48_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG48_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG48_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG48_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG48_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG48_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG48_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG48_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG48_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG48_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG48_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG48_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG48_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG48_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG48_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG48_RESETVAL                        (0x00140001U)

/* PADCONFIG49 */

#define CSL_BOOTCFG_PADCONFIG49_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG49_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG49_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG49_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG49_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG49_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG49_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG49_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG49_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG49_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG49_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG49_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG49_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG49_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG49_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG49_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG49_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG49_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG49_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG49_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG49_RESETVAL                        (0x00140001U)

/* PADCONFIG50 */

#define CSL_BOOTCFG_PADCONFIG50_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG50_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG50_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG50_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG50_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG50_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG50_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG50_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG50_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG50_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG50_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG50_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG50_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG50_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG50_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG50_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG50_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG50_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG50_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG50_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG50_RESETVAL                        (0x00140001U)

/* PADCONFIG51 */

#define CSL_BOOTCFG_PADCONFIG51_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG51_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG51_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG51_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG51_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG51_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG51_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG51_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG51_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG51_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG51_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG51_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG51_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG51_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG51_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG51_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG51_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG51_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG51_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG51_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG51_RESETVAL                        (0x00140001U)

/* PADCONFIG52 */

#define CSL_BOOTCFG_PADCONFIG52_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG52_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG52_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG52_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG52_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG52_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG52_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG52_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG52_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG52_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG52_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG52_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG52_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG52_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG52_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG52_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG52_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG52_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG52_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG52_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG52_RESETVAL                        (0x00140001U)

/* PADCONFIG53 */

#define CSL_BOOTCFG_PADCONFIG53_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG53_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG53_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG53_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG53_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG53_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG53_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG53_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG53_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG53_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG53_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG53_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG53_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG53_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG53_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG53_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG53_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG53_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG53_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG53_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG53_RESETVAL                        (0x00140001U)

/* PADCONFIG54 */

#define CSL_BOOTCFG_PADCONFIG54_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG54_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG54_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG54_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG54_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG54_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG54_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG54_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG54_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG54_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG54_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG54_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG54_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG54_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG54_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG54_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG54_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG54_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG54_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG54_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG54_RESETVAL                        (0x00140001U)

/* PADCONFIG55 */

#define CSL_BOOTCFG_PADCONFIG55_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG55_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG55_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG55_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG55_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG55_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG55_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG55_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG55_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG55_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG55_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG55_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG55_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG55_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG55_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG55_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG55_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG55_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG55_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG55_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG55_RESETVAL                        (0x00140001U)

/* PADCONFIG56 */

#define CSL_BOOTCFG_PADCONFIG56_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG56_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG56_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG56_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG56_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG56_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG56_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG56_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG56_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG56_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG56_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG56_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG56_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG56_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG56_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG56_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG56_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG56_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG56_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG56_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG56_RESETVAL                        (0x00140001U)

/* PADCONFIG57 */

#define CSL_BOOTCFG_PADCONFIG57_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG57_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG57_MUXMODE_RESETVAL                (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG57_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG57_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG57_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG57_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG57_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG57_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG57_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG57_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG57_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG57_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG57_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG57_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG57_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG57_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG57_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG57_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG57_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG57_RESETVAL                        (0x00140001U)

/* PADCONFIG58 */

#define CSL_BOOTCFG_PADCONFIG58_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG58_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG58_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG58_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG58_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG58_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG58_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG58_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG58_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG58_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG58_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG58_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG58_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG58_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG58_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG58_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG58_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG58_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG58_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG58_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG58_RESETVAL                        (0x00140003U)

/* PADCONFIG59 */

#define CSL_BOOTCFG_PADCONFIG59_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG59_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG59_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG59_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG59_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG59_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG59_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG59_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG59_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG59_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG59_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG59_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG59_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG59_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG59_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG59_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG59_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG59_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG59_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG59_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG59_RESETVAL                        (0x00160003U)

/* PADCONFIG60 */

#define CSL_BOOTCFG_PADCONFIG60_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG60_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG60_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG60_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG60_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG60_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG60_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG60_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG60_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG60_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG60_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG60_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG60_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG60_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG60_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG60_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG60_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG60_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG60_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG60_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG60_RESETVAL                        (0x00160003U)

/* PADCONFIG61 */

#define CSL_BOOTCFG_PADCONFIG61_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG61_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG61_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG61_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG61_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG61_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG61_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG61_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG61_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG61_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG61_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG61_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG61_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG61_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG61_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG61_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG61_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG61_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG61_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG61_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG61_RESETVAL                        (0x00160003U)

/* PADCONFIG62 */

#define CSL_BOOTCFG_PADCONFIG62_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG62_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG62_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG62_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG62_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG62_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG62_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG62_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG62_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG62_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG62_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG62_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG62_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG62_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG62_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG62_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG62_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG62_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG62_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG62_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG62_RESETVAL                        (0x00160003U)

/* PADCONFIG63 */

#define CSL_BOOTCFG_PADCONFIG63_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG63_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG63_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG63_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG63_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG63_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG63_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG63_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG63_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG63_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG63_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG63_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG63_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG63_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG63_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG63_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG63_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG63_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG63_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG63_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG63_RESETVAL                        (0x00160003U)

/* PADCONFIG64 */

#define CSL_BOOTCFG_PADCONFIG64_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG64_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG64_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG64_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG64_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG64_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG64_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG64_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG64_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG64_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG64_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG64_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG64_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG64_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG64_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG64_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG64_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG64_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG64_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG64_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG64_RESETVAL                        (0x00160003U)

/* PADCONFIG65 */

#define CSL_BOOTCFG_PADCONFIG65_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG65_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG65_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG65_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG65_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG65_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG65_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG65_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG65_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG65_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG65_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG65_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG65_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG65_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG65_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG65_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG65_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG65_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG65_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG65_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG65_RESETVAL                        (0x00160003U)

/* PADCONFIG66 */

#define CSL_BOOTCFG_PADCONFIG66_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG66_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG66_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG66_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG66_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG66_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG66_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG66_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG66_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG66_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG66_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG66_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG66_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG66_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG66_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG66_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG66_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG66_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG66_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG66_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG66_RESETVAL                        (0x00160003U)

/* PADCONFIG67 */

#define CSL_BOOTCFG_PADCONFIG67_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG67_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG67_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG67_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG67_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG67_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG67_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG67_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG67_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG67_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG67_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG67_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG67_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG67_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG67_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG67_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG67_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG67_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG67_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG67_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG67_RESETVAL                        (0x00160003U)

/* PADCONFIG68 */

#define CSL_BOOTCFG_PADCONFIG68_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG68_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG68_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG68_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG68_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG68_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG68_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG68_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG68_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG68_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG68_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG68_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG68_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG68_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG68_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG68_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG68_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG68_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG68_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG68_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG68_RESETVAL                        (0x00160003U)

/* PADCONFIG69 */

#define CSL_BOOTCFG_PADCONFIG69_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG69_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG69_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG69_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG69_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG69_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG69_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG69_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG69_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG69_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG69_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG69_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG69_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG69_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG69_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG69_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG69_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG69_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG69_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG69_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG69_RESETVAL                        (0x00160003U)

/* PADCONFIG70 */

#define CSL_BOOTCFG_PADCONFIG70_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG70_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG70_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG70_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG70_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG70_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG70_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG70_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG70_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG70_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG70_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG70_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG70_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG70_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG70_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG70_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG70_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG70_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG70_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG70_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG70_RESETVAL                        (0x00160003U)

/* PADCONFIG71 */

#define CSL_BOOTCFG_PADCONFIG71_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG71_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG71_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG71_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG71_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG71_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG71_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG71_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG71_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG71_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG71_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG71_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG71_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG71_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG71_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG71_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG71_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG71_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG71_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG71_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG71_RESETVAL                        (0x00160003U)

/* PADCONFIG72 */

#define CSL_BOOTCFG_PADCONFIG72_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG72_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG72_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG72_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG72_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG72_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG72_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG72_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG72_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG72_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG72_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG72_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG72_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG72_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG72_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG72_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG72_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG72_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG72_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG72_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG72_RESETVAL                        (0x00140003U)

/* PADCONFIG73 */

#define CSL_BOOTCFG_PADCONFIG73_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG73_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG73_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG73_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG73_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG73_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG73_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG73_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG73_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG73_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG73_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG73_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG73_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG73_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG73_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG73_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG73_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG73_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG73_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG73_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG73_RESETVAL                        (0x00140003U)

/* PADCONFIG74 */

#define CSL_BOOTCFG_PADCONFIG74_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG74_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG74_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG74_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG74_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG74_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG74_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG74_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG74_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG74_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG74_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG74_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG74_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG74_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG74_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG74_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG74_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG74_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG74_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG74_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG74_RESETVAL                        (0x00140003U)

/* PADCONFIG75 */

#define CSL_BOOTCFG_PADCONFIG75_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG75_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG75_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG75_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG75_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG75_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG75_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG75_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG75_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG75_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG75_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG75_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG75_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG75_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG75_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG75_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG75_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG75_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG75_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG75_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG75_RESETVAL                        (0x00140003U)

/* PADCONFIG76 */

#define CSL_BOOTCFG_PADCONFIG76_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG76_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG76_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG76_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG76_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG76_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG76_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG76_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG76_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG76_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG76_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG76_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG76_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG76_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG76_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG76_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG76_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG76_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG76_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG76_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG76_RESETVAL                        (0x00140003U)

/* PADCONFIG77 */

#define CSL_BOOTCFG_PADCONFIG77_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG77_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG77_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG77_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG77_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG77_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG77_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG77_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG77_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG77_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG77_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG77_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG77_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG77_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG77_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG77_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG77_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG77_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG77_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG77_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG77_RESETVAL                        (0x00140003U)

/* PADCONFIG78 */

#define CSL_BOOTCFG_PADCONFIG78_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG78_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG78_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG78_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG78_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG78_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG78_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG78_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG78_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG78_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG78_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG78_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG78_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG78_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG78_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG78_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG78_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG78_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG78_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG78_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG78_RESETVAL                        (0x00140003U)

/* PADCONFIG79 */

#define CSL_BOOTCFG_PADCONFIG79_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG79_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG79_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG79_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG79_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG79_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG79_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG79_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG79_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG79_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG79_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG79_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG79_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG79_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG79_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG79_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG79_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG79_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG79_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG79_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG79_RESETVAL                        (0x00140003U)

/* PADCONFIG80 */

#define CSL_BOOTCFG_PADCONFIG80_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG80_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG80_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG80_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG80_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG80_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG80_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG80_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG80_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG80_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG80_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG80_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG80_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG80_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG80_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG80_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG80_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG80_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG80_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG80_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG80_RESETVAL                        (0x00140003U)

/* PADCONFIG81 */

#define CSL_BOOTCFG_PADCONFIG81_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG81_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG81_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG81_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG81_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG81_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG81_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG81_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG81_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG81_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG81_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG81_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG81_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG81_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG81_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG81_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG81_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG81_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG81_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG81_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG81_RESETVAL                        (0x00140003U)

/* PADCONFIG82 */

#define CSL_BOOTCFG_PADCONFIG82_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG82_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG82_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG82_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG82_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG82_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG82_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG82_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG82_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG82_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG82_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG82_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG82_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG82_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG82_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG82_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG82_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG82_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG82_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG82_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG82_RESETVAL                        (0x00140003U)

/* PADCONFIG83 */

#define CSL_BOOTCFG_PADCONFIG83_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG83_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG83_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG83_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG83_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG83_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG83_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG83_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG83_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG83_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG83_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG83_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG83_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG83_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG83_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG83_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG83_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG83_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG83_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG83_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG83_RESETVAL                        (0x00140003U)

/* PADCONFIG84 */

#define CSL_BOOTCFG_PADCONFIG84_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG84_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG84_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG84_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG84_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG84_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG84_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG84_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG84_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG84_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG84_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG84_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG84_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG84_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG84_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG84_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG84_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG84_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG84_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG84_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG84_RESETVAL                        (0x00140003U)

/* PADCONFIG85 */

#define CSL_BOOTCFG_PADCONFIG85_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG85_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG85_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG85_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG85_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG85_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG85_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG85_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG85_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG85_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG85_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG85_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG85_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG85_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG85_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG85_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG85_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG85_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG85_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG85_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG85_RESETVAL                        (0x00140003U)

/* PADCONFIG86 */

#define CSL_BOOTCFG_PADCONFIG86_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG86_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG86_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG86_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG86_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG86_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG86_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG86_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG86_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG86_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG86_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG86_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG86_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG86_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG86_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG86_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG86_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG86_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG86_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG86_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG86_RESETVAL                        (0x00140003U)

/* PADCONFIG87 */

#define CSL_BOOTCFG_PADCONFIG87_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG87_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG87_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG87_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG87_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG87_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG87_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG87_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG87_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG87_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG87_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG87_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG87_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG87_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG87_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG87_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG87_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG87_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG87_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG87_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG87_RESETVAL                        (0x00140003U)

/* PADCONFIG88 */

#define CSL_BOOTCFG_PADCONFIG88_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG88_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG88_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG88_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG88_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG88_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG88_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG88_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG88_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG88_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG88_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG88_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG88_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG88_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG88_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG88_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG88_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG88_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG88_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG88_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG88_RESETVAL                        (0x00140003U)

/* PADCONFIG89 */

#define CSL_BOOTCFG_PADCONFIG89_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG89_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG89_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG89_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG89_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG89_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG89_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG89_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG89_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG89_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG89_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG89_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG89_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG89_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG89_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG89_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG89_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG89_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG89_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG89_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG89_RESETVAL                        (0x00140003U)

/* PADCONFIG90 */

#define CSL_BOOTCFG_PADCONFIG90_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG90_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG90_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG90_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG90_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG90_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG90_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG90_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG90_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG90_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG90_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG90_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG90_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG90_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG90_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG90_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG90_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG90_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG90_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG90_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG90_RESETVAL                        (0x00140003U)

/* PADCONFIG91 */

#define CSL_BOOTCFG_PADCONFIG91_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG91_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG91_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG91_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG91_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG91_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG91_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG91_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG91_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG91_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG91_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG91_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG91_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG91_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG91_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG91_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG91_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG91_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG91_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG91_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG91_RESETVAL                        (0x00140003U)

/* PADCONFIG92 */

#define CSL_BOOTCFG_PADCONFIG92_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG92_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG92_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG92_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG92_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG92_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG92_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG92_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG92_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG92_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG92_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG92_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG92_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG92_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG92_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG92_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG92_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG92_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG92_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG92_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG92_RESETVAL                        (0x00140003U)

/* PADCONFIG93 */

#define CSL_BOOTCFG_PADCONFIG93_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG93_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG93_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG93_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG93_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG93_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG93_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG93_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG93_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG93_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG93_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG93_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG93_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG93_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG93_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG93_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG93_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG93_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG93_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG93_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG93_RESETVAL                        (0x00140003U)

/* PADCONFIG94 */

#define CSL_BOOTCFG_PADCONFIG94_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG94_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG94_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG94_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG94_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG94_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG94_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG94_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG94_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG94_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG94_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG94_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG94_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG94_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG94_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG94_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG94_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG94_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG94_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG94_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG94_RESETVAL                        (0x00140003U)

/* PADCONFIG95 */

#define CSL_BOOTCFG_PADCONFIG95_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG95_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG95_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG95_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG95_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG95_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG95_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG95_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG95_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG95_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG95_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG95_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG95_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG95_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG95_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG95_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG95_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG95_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG95_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG95_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG95_RESETVAL                        (0x00140003U)

/* PADCONFIG96 */

#define CSL_BOOTCFG_PADCONFIG96_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG96_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG96_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG96_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG96_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG96_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG96_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG96_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG96_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG96_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG96_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG96_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG96_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG96_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG96_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG96_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG96_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG96_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG96_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG96_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG96_RESETVAL                        (0x00140003U)

/* PADCONFIG97 */

#define CSL_BOOTCFG_PADCONFIG97_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG97_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG97_MUXMODE_RESETVAL                (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG97_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG97_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG97_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG97_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG97_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG97_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG97_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG97_PULLTYPESEL_RESETVAL            (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG97_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG97_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG97_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG97_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG97_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG97_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG97_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG97_BUFFERCLASS_RESETVAL            (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG97_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG97_RESETVAL                        (0x00140000U)

/* PADCONFIG98 */

#define CSL_BOOTCFG_PADCONFIG98_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG98_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG98_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG98_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG98_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG98_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG98_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG98_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG98_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG98_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG98_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG98_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG98_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG98_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG98_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG98_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG98_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG98_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG98_BUFFERCLASS_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG98_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG98_RESETVAL                        (0x000e0003U)

/* PADCONFIG99 */

#define CSL_BOOTCFG_PADCONFIG99_MUXMODE_MASK                    (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG99_MUXMODE_SHIFT                   (0U)
#define CSL_BOOTCFG_PADCONFIG99_MUXMODE_RESETVAL                (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG99_MUXMODE_MAX                     (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG99_PULLUDEN_MASK                   (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG99_PULLUDEN_SHIFT                  (16U)
#define CSL_BOOTCFG_PADCONFIG99_PULLUDEN_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG99_PULLUDEN_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG99_PULLTYPESEL_MASK                (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG99_PULLTYPESEL_SHIFT               (17U)
#define CSL_BOOTCFG_PADCONFIG99_PULLTYPESEL_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG99_PULLTYPESEL_MAX                 (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG99_RXACTIVE_MASK                   (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG99_RXACTIVE_SHIFT                  (18U)
#define CSL_BOOTCFG_PADCONFIG99_RXACTIVE_RESETVAL               (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG99_RXACTIVE_MAX                    (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG99_BUFFERCLASS_MASK                (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG99_BUFFERCLASS_SHIFT               (19U)
#define CSL_BOOTCFG_PADCONFIG99_BUFFERCLASS_RESETVAL            (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG99_BUFFERCLASS_MAX                 (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG99_RESETVAL                        (0x000e0003U)

/* PADCONFIG100 */

#define CSL_BOOTCFG_PADCONFIG100_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG100_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG100_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG100_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG100_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG100_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG100_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG100_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG100_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG100_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG100_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG100_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG100_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG100_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG100_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG100_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG100_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG100_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG100_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG100_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG100_RESETVAL                       (0x000e0000U)

/* PADCONFIG101 */

#define CSL_BOOTCFG_PADCONFIG101_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG101_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG101_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG101_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG101_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG101_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG101_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG101_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG101_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG101_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG101_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG101_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG101_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG101_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG101_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG101_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG101_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG101_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG101_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG101_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG101_RESETVAL                       (0x000e0000U)

/* PADCONFIG102 */

#define CSL_BOOTCFG_PADCONFIG102_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG102_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG102_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG102_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG102_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG102_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG102_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG102_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG102_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG102_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG102_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG102_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG102_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG102_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG102_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG102_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG102_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG102_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG102_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG102_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG102_RESETVAL                       (0x000c0000U)

/* PADCONFIG103 */

#define CSL_BOOTCFG_PADCONFIG103_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG103_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG103_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG103_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG103_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG103_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG103_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG103_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG103_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG103_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG103_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG103_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG103_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG103_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG103_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG103_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG103_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG103_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG103_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG103_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG103_RESETVAL                       (0x000c0000U)

/* PADCONFIG104 */

#define CSL_BOOTCFG_PADCONFIG104_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG104_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG104_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG104_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG104_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG104_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG104_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG104_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG104_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG104_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG104_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG104_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG104_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG104_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG104_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG104_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG104_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG104_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG104_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG104_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG104_RESETVAL                       (0x000c0000U)

/* PADCONFIG105 */

#define CSL_BOOTCFG_PADCONFIG105_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG105_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG105_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG105_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG105_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG105_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG105_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG105_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG105_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG105_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG105_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG105_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG105_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG105_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG105_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG105_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG105_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG105_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG105_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG105_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG105_RESETVAL                       (0x000e0000U)

/* PADCONFIG106 */

#define CSL_BOOTCFG_PADCONFIG106_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG106_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG106_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG106_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG106_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG106_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG106_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG106_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG106_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG106_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG106_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG106_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG106_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG106_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG106_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG106_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG106_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG106_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG106_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG106_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG106_RESETVAL                       (0x000e0000U)

/* PADCONFIG107 */

#define CSL_BOOTCFG_PADCONFIG107_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG107_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG107_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG107_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG107_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG107_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG107_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG107_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG107_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG107_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG107_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG107_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG107_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG107_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG107_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG107_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG107_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG107_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG107_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG107_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG107_RESETVAL                       (0x000c0000U)

/* PADCONFIG108 */

#define CSL_BOOTCFG_PADCONFIG108_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG108_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG108_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG108_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG108_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG108_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG108_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG108_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG108_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG108_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG108_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG108_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG108_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG108_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG108_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG108_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG108_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG108_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG108_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG108_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG108_RESETVAL                       (0x000c0000U)

/* PADCONFIG109 */

#define CSL_BOOTCFG_PADCONFIG109_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG109_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG109_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG109_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG109_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG109_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG109_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG109_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG109_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG109_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG109_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG109_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG109_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG109_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG109_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG109_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG109_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG109_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG109_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG109_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG109_RESETVAL                       (0x000c0000U)

/* PADCONFIG110 */

#define CSL_BOOTCFG_PADCONFIG110_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG110_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG110_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG110_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG110_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG110_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG110_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG110_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG110_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG110_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG110_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG110_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG110_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG110_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG110_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG110_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG110_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG110_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG110_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG110_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG110_RESETVAL                       (0x000e0003U)

/* PADCONFIG111 */

#define CSL_BOOTCFG_PADCONFIG111_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG111_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG111_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG111_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG111_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG111_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG111_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG111_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG111_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG111_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG111_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG111_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG111_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG111_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG111_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG111_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG111_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG111_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG111_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG111_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG111_RESETVAL                       (0x000e0003U)

/* PADCONFIG112 */

#define CSL_BOOTCFG_PADCONFIG112_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG112_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG112_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG112_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG112_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG112_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG112_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG112_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG112_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG112_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG112_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG112_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG112_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG112_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG112_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG112_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG112_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG112_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG112_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG112_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG112_RESETVAL                       (0x000c0003U)

/* PADCONFIG113 */

#define CSL_BOOTCFG_PADCONFIG113_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG113_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG113_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG113_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG113_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG113_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG113_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG113_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG113_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG113_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG113_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG113_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG113_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG113_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG113_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG113_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG113_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG113_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG113_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG113_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG113_RESETVAL                       (0x000c0003U)

/* PADCONFIG114 */

#define CSL_BOOTCFG_PADCONFIG114_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG114_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG114_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG114_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG114_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG114_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG114_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG114_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG114_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG114_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG114_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG114_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG114_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG114_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG114_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG114_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG114_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG114_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG114_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG114_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG114_RESETVAL                       (0x000c0003U)

/* PADCONFIG115 */

#define CSL_BOOTCFG_PADCONFIG115_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG115_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG115_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG115_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG115_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG115_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG115_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG115_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG115_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG115_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG115_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG115_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG115_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG115_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG115_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG115_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG115_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG115_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG115_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG115_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG115_RESETVAL                       (0x000e0000U)

/* PADCONFIG116 */

#define CSL_BOOTCFG_PADCONFIG116_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG116_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG116_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG116_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG116_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG116_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG116_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG116_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG116_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG116_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG116_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG116_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG116_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG116_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG116_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG116_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG116_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG116_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG116_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG116_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG116_RESETVAL                       (0x000e0000U)

/* PADCONFIG117 */

#define CSL_BOOTCFG_PADCONFIG117_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG117_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG117_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG117_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG117_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG117_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG117_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG117_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG117_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG117_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG117_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG117_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG117_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG117_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG117_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG117_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG117_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG117_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG117_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG117_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG117_RESETVAL                       (0x000e0000U)

/* PADCONFIG118 */

#define CSL_BOOTCFG_PADCONFIG118_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG118_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG118_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG118_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG118_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG118_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG118_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG118_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG118_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG118_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG118_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG118_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG118_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG118_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG118_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG118_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG118_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG118_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG118_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG118_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG118_RESETVAL                       (0x000e0000U)

/* PADCONFIG119 */

#define CSL_BOOTCFG_PADCONFIG119_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG119_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG119_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG119_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG119_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG119_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG119_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG119_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG119_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG119_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG119_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG119_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG119_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG119_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG119_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG119_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG119_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG119_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG119_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG119_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG119_RESETVAL                       (0x000e0003U)

/* PADCONFIG120 */

#define CSL_BOOTCFG_PADCONFIG120_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG120_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG120_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG120_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG120_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG120_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG120_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG120_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG120_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG120_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG120_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG120_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG120_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG120_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG120_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG120_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG120_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG120_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG120_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG120_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG120_RESETVAL                       (0x000e0003U)

/* PADCONFIG121 */

#define CSL_BOOTCFG_PADCONFIG121_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG121_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG121_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG121_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG121_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG121_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG121_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG121_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG121_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG121_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG121_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG121_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG121_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG121_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG121_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG121_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG121_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG121_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG121_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG121_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG121_RESETVAL                       (0x000e0003U)

/* PADCONFIG122 */

#define CSL_BOOTCFG_PADCONFIG122_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG122_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG122_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG122_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG122_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG122_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG122_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG122_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG122_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG122_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG122_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG122_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG122_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG122_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG122_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG122_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG122_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG122_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG122_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG122_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG122_RESETVAL                       (0x000e0003U)

/* PADCONFIG123 */

#define CSL_BOOTCFG_PADCONFIG123_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG123_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG123_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG123_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG123_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG123_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG123_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG123_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG123_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG123_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG123_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG123_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG123_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG123_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG123_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG123_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG123_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG123_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG123_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG123_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG123_RESETVAL                       (0x000e0003U)

/* PADCONFIG124 */

#define CSL_BOOTCFG_PADCONFIG124_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG124_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG124_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG124_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG124_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG124_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG124_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG124_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG124_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG124_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG124_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG124_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG124_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG124_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG124_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG124_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG124_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG124_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG124_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG124_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG124_RESETVAL                       (0x000e0003U)

/* PADCONFIG125 */

#define CSL_BOOTCFG_PADCONFIG125_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG125_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG125_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG125_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG125_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG125_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG125_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG125_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG125_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG125_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG125_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG125_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG125_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG125_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG125_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG125_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG125_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG125_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG125_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG125_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG125_RESETVAL                       (0x000e0003U)

/* PADCONFIG126 */

#define CSL_BOOTCFG_PADCONFIG126_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG126_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG126_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG126_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG126_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG126_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG126_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG126_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG126_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG126_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG126_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG126_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG126_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG126_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG126_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG126_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG126_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG126_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG126_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG126_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG126_RESETVAL                       (0x000e0003U)

/* PADCONFIG127 */

#define CSL_BOOTCFG_PADCONFIG127_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG127_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG127_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG127_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG127_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG127_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG127_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG127_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG127_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG127_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG127_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG127_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG127_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG127_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG127_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG127_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG127_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG127_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG127_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG127_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG127_RESETVAL                       (0x000e0003U)

/* PADCONFIG128 */

#define CSL_BOOTCFG_PADCONFIG128_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG128_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG128_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG128_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG128_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG128_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG128_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG128_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG128_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG128_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG128_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG128_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG128_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG128_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG128_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG128_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG128_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG128_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG128_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG128_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG128_RESETVAL                       (0x000e0003U)

/* PADCONFIG129 */

#define CSL_BOOTCFG_PADCONFIG129_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG129_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG129_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG129_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG129_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG129_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG129_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG129_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG129_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG129_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG129_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG129_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG129_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG129_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG129_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG129_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG129_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG129_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG129_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG129_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG129_RESETVAL                       (0x00160003U)

/* PADCONFIG130 */

#define CSL_BOOTCFG_PADCONFIG130_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG130_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG130_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG130_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG130_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG130_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG130_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG130_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG130_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG130_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG130_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG130_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG130_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG130_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG130_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG130_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG130_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG130_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG130_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG130_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG130_RESETVAL                       (0x00160003U)

/* PADCONFIG131 */

#define CSL_BOOTCFG_PADCONFIG131_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG131_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG131_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG131_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG131_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG131_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG131_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG131_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG131_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG131_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG131_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG131_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG131_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG131_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG131_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG131_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG131_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG131_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG131_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG131_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG131_RESETVAL                       (0x00160003U)

/* PADCONFIG132 */

#define CSL_BOOTCFG_PADCONFIG132_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG132_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG132_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG132_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG132_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG132_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG132_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG132_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG132_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG132_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG132_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG132_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG132_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG132_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG132_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG132_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG132_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG132_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG132_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG132_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG132_RESETVAL                       (0x00160003U)

/* PADCONFIG133 */

#define CSL_BOOTCFG_PADCONFIG133_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG133_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG133_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG133_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG133_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG133_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG133_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG133_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG133_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG133_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG133_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG133_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG133_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG133_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG133_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG133_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG133_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG133_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG133_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG133_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG133_RESETVAL                       (0x00160003U)

/* PADCONFIG134 */

#define CSL_BOOTCFG_PADCONFIG134_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG134_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG134_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG134_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG134_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG134_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG134_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG134_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG134_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG134_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG134_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG134_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG134_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG134_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG134_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG134_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG134_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG134_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG134_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG134_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG134_RESETVAL                       (0x00160003U)

/* PADCONFIG135 */

#define CSL_BOOTCFG_PADCONFIG135_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG135_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG135_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG135_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG135_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG135_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG135_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG135_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG135_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG135_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG135_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG135_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG135_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG135_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG135_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG135_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG135_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG135_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG135_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG135_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG135_RESETVAL                       (0x00160003U)

/* PADCONFIG136 */

#define CSL_BOOTCFG_PADCONFIG136_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG136_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG136_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG136_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG136_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG136_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG136_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG136_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG136_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG136_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG136_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG136_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG136_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG136_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG136_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG136_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG136_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG136_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG136_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG136_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG136_RESETVAL                       (0x00160003U)

/* PADCONFIG137 */

#define CSL_BOOTCFG_PADCONFIG137_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG137_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG137_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG137_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG137_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG137_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG137_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG137_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG137_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG137_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG137_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG137_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG137_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG137_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG137_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG137_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG137_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG137_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG137_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG137_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG137_RESETVAL                       (0x00160003U)

/* PADCONFIG138 */

#define CSL_BOOTCFG_PADCONFIG138_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG138_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG138_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG138_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG138_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG138_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG138_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG138_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG138_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG138_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG138_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG138_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG138_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG138_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG138_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG138_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG138_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG138_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG138_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG138_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG138_RESETVAL                       (0x00160003U)

/* PADCONFIG139 */

#define CSL_BOOTCFG_PADCONFIG139_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG139_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG139_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG139_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG139_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG139_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG139_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG139_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG139_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG139_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG139_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG139_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG139_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG139_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG139_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG139_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG139_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG139_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG139_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG139_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG139_RESETVAL                       (0x00140003U)

/* PADCONFIG140 */

#define CSL_BOOTCFG_PADCONFIG140_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG140_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG140_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG140_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG140_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG140_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG140_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG140_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG140_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG140_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG140_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG140_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG140_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG140_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG140_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG140_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG140_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG140_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG140_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG140_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG140_RESETVAL                       (0x00140003U)

/* PADCONFIG141 */

#define CSL_BOOTCFG_PADCONFIG141_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG141_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG141_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG141_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG141_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG141_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG141_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG141_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG141_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG141_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG141_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG141_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG141_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG141_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG141_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG141_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG141_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG141_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG141_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG141_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG141_RESETVAL                       (0x00140003U)

/* PADCONFIG142 */

#define CSL_BOOTCFG_PADCONFIG142_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG142_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG142_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG142_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG142_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG142_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG142_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG142_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG142_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG142_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG142_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG142_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG142_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG142_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG142_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG142_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG142_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG142_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG142_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG142_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG142_RESETVAL                       (0x00140003U)

/* PADCONFIG143 */

#define CSL_BOOTCFG_PADCONFIG143_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG143_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG143_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG143_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG143_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG143_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG143_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG143_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG143_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG143_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG143_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG143_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG143_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG143_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG143_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG143_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG143_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG143_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG143_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG143_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG143_RESETVAL                       (0x00140003U)

/* PADCONFIG144 */

#define CSL_BOOTCFG_PADCONFIG144_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG144_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG144_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG144_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG144_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG144_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG144_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG144_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG144_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG144_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG144_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG144_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG144_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG144_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG144_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG144_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG144_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG144_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG144_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG144_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG144_RESETVAL                       (0x00140003U)

/* PADCONFIG145 */

#define CSL_BOOTCFG_PADCONFIG145_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG145_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG145_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG145_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG145_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG145_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG145_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG145_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG145_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG145_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG145_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG145_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG145_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG145_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG145_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG145_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG145_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG145_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG145_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG145_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG145_RESETVAL                       (0x00140003U)

/* PADCONFIG146 */

#define CSL_BOOTCFG_PADCONFIG146_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG146_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG146_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG146_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG146_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG146_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG146_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG146_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG146_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG146_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG146_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG146_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG146_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG146_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG146_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG146_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG146_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG146_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG146_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG146_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG146_RESETVAL                       (0x00140003U)

/* PADCONFIG147 */

#define CSL_BOOTCFG_PADCONFIG147_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG147_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG147_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG147_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG147_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG147_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG147_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG147_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG147_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG147_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG147_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG147_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG147_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG147_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG147_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG147_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG147_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG147_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG147_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG147_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG147_RESETVAL                       (0x00140003U)

/* PADCONFIG148 */

#define CSL_BOOTCFG_PADCONFIG148_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG148_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG148_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG148_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG148_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG148_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG148_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG148_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG148_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG148_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG148_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG148_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG148_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG148_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG148_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG148_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG148_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG148_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG148_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG148_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG148_RESETVAL                       (0x00140003U)

/* PADCONFIG149 */

#define CSL_BOOTCFG_PADCONFIG149_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG149_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG149_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG149_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG149_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG149_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG149_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG149_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG149_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG149_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG149_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG149_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG149_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG149_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG149_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG149_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG149_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG149_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG149_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG149_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG149_RESETVAL                       (0x00140003U)

/* PADCONFIG150 */

#define CSL_BOOTCFG_PADCONFIG150_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG150_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG150_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG150_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG150_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG150_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG150_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG150_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG150_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG150_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG150_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG150_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG150_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG150_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG150_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG150_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG150_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG150_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG150_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG150_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG150_RESETVAL                       (0x00140003U)

/* PADCONFIG151 */

#define CSL_BOOTCFG_PADCONFIG151_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG151_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG151_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG151_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG151_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG151_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG151_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG151_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG151_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG151_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG151_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG151_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG151_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG151_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG151_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG151_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG151_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG151_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG151_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG151_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG151_RESETVAL                       (0x00140003U)

/* PADCONFIG152 */

#define CSL_BOOTCFG_PADCONFIG152_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG152_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG152_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG152_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG152_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG152_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG152_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG152_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG152_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG152_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG152_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG152_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG152_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG152_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG152_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG152_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG152_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG152_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG152_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG152_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG152_RESETVAL                       (0x00140003U)

/* PADCONFIG153 */

#define CSL_BOOTCFG_PADCONFIG153_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG153_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG153_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG153_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG153_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG153_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG153_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG153_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG153_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG153_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG153_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG153_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG153_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG153_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG153_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG153_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG153_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG153_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG153_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG153_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG153_RESETVAL                       (0x00140003U)

/* PADCONFIG154 */

#define CSL_BOOTCFG_PADCONFIG154_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG154_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG154_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG154_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG154_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG154_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG154_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG154_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG154_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG154_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG154_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG154_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG154_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG154_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG154_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG154_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG154_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG154_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG154_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG154_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG154_RESETVAL                       (0x00140003U)

/* PADCONFIG155 */

#define CSL_BOOTCFG_PADCONFIG155_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG155_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG155_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG155_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG155_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG155_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG155_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG155_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG155_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG155_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG155_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG155_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG155_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG155_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG155_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG155_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG155_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG155_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG155_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG155_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG155_RESETVAL                       (0x00140003U)

/* PADCONFIG156 */

#define CSL_BOOTCFG_PADCONFIG156_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG156_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG156_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG156_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG156_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG156_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG156_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG156_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG156_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG156_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG156_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG156_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG156_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG156_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG156_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG156_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG156_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG156_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG156_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG156_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG156_RESETVAL                       (0x00140003U)

/* PADCONFIG157 */

#define CSL_BOOTCFG_PADCONFIG157_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG157_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG157_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG157_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG157_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG157_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG157_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG157_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG157_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG157_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG157_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG157_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG157_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG157_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG157_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG157_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG157_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG157_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG157_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG157_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG157_RESETVAL                       (0x00140003U)

/* PADCONFIG158 */

#define CSL_BOOTCFG_PADCONFIG158_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG158_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG158_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG158_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG158_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG158_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG158_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG158_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG158_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG158_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG158_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG158_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG158_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG158_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG158_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG158_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG158_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG158_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG158_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG158_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG158_RESETVAL                       (0x00140003U)

/* PADCONFIG159 */

#define CSL_BOOTCFG_PADCONFIG159_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG159_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG159_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG159_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG159_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG159_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG159_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG159_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG159_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG159_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG159_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG159_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG159_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG159_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG159_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG159_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG159_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG159_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG159_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG159_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG159_RESETVAL                       (0x00140003U)

/* PADCONFIG160 */

#define CSL_BOOTCFG_PADCONFIG160_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG160_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG160_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG160_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG160_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG160_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG160_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG160_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG160_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG160_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG160_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG160_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG160_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG160_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG160_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG160_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG160_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG160_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG160_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG160_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG160_RESETVAL                       (0x00140003U)

/* PADCONFIG161 */

#define CSL_BOOTCFG_PADCONFIG161_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG161_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG161_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG161_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG161_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG161_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG161_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG161_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG161_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG161_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG161_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG161_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG161_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG161_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG161_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG161_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG161_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG161_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG161_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG161_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG161_RESETVAL                       (0x00140003U)

/* PADCONFIG162 */

#define CSL_BOOTCFG_PADCONFIG162_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG162_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG162_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG162_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG162_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG162_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG162_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG162_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG162_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG162_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG162_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG162_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG162_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG162_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG162_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG162_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG162_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG162_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG162_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG162_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG162_RESETVAL                       (0x00140003U)

/* PADCONFIG163 */

#define CSL_BOOTCFG_PADCONFIG163_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG163_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG163_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG163_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG163_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG163_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG163_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG163_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG163_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG163_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG163_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG163_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG163_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG163_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG163_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG163_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG163_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG163_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG163_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG163_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG163_RESETVAL                       (0x00140003U)

/* PADCONFIG164 */

#define CSL_BOOTCFG_PADCONFIG164_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG164_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG164_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG164_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG164_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG164_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG164_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG164_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG164_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG164_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG164_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG164_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG164_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG164_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG164_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG164_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG164_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG164_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG164_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG164_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG164_RESETVAL                       (0x00140003U)

/* PADCONFIG165 */

#define CSL_BOOTCFG_PADCONFIG165_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG165_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG165_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG165_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG165_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG165_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG165_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG165_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG165_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG165_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG165_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG165_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG165_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG165_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG165_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG165_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG165_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG165_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG165_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG165_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG165_RESETVAL                       (0x00140003U)

/* PADCONFIG166 */

#define CSL_BOOTCFG_PADCONFIG166_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG166_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG166_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG166_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG166_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG166_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG166_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG166_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG166_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG166_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG166_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG166_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG166_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG166_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG166_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG166_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG166_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG166_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG166_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG166_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG166_RESETVAL                       (0x00140003U)

/* PADCONFIG167 */

#define CSL_BOOTCFG_PADCONFIG167_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG167_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG167_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG167_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG167_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG167_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG167_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG167_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG167_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG167_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG167_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG167_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG167_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG167_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG167_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG167_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG167_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG167_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG167_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG167_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG167_RESETVAL                       (0x00140003U)

/* PADCONFIG168 */

#define CSL_BOOTCFG_PADCONFIG168_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG168_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG168_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG168_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG168_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG168_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG168_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG168_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG168_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG168_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG168_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG168_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG168_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG168_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG168_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG168_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG168_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG168_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG168_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG168_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG168_RESETVAL                       (0x00140003U)

/* PADCONFIG169 */

#define CSL_BOOTCFG_PADCONFIG169_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG169_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG169_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG169_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG169_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG169_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG169_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG169_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG169_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG169_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG169_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG169_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG169_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG169_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG169_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG169_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG169_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG169_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG169_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG169_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG169_RESETVAL                       (0x00140003U)

/* PADCONFIG170 */

#define CSL_BOOTCFG_PADCONFIG170_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG170_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG170_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG170_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG170_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG170_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG170_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG170_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG170_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG170_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG170_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG170_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG170_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG170_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG170_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG170_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG170_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG170_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG170_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG170_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG170_RESETVAL                       (0x00140003U)

/* PADCONFIG171 */

#define CSL_BOOTCFG_PADCONFIG171_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG171_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG171_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG171_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG171_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG171_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG171_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG171_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG171_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG171_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG171_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG171_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG171_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG171_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG171_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG171_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG171_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG171_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG171_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG171_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG171_RESETVAL                       (0x00140003U)

/* PADCONFIG172 */

#define CSL_BOOTCFG_PADCONFIG172_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG172_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG172_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG172_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG172_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG172_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG172_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG172_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG172_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG172_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG172_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG172_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG172_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG172_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG172_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG172_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG172_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG172_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG172_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG172_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG172_RESETVAL                       (0x00140003U)

/* PADCONFIG173 */

#define CSL_BOOTCFG_PADCONFIG173_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG173_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG173_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG173_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG173_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG173_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG173_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG173_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG173_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG173_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG173_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG173_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG173_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG173_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG173_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG173_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG173_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG173_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG173_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG173_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG173_RESETVAL                       (0x00140003U)

/* PADCONFIG174 */

#define CSL_BOOTCFG_PADCONFIG174_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG174_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG174_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG174_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG174_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG174_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG174_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG174_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG174_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG174_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG174_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG174_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG174_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG174_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG174_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG174_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG174_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG174_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG174_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG174_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG174_RESETVAL                       (0x00140003U)

/* PADCONFIG175 */

#define CSL_BOOTCFG_PADCONFIG175_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG175_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG175_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG175_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG175_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG175_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG175_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG175_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG175_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG175_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG175_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG175_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG175_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG175_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG175_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG175_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG175_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG175_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG175_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG175_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG175_RESETVAL                       (0x00140003U)

/* PADCONFIG176 */

#define CSL_BOOTCFG_PADCONFIG176_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG176_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG176_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG176_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG176_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG176_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG176_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG176_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG176_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG176_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG176_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG176_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG176_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG176_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG176_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG176_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG176_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG176_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG176_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG176_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG176_RESETVAL                       (0x00140003U)

/* PADCONFIG177 */

#define CSL_BOOTCFG_PADCONFIG177_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG177_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG177_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG177_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG177_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG177_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG177_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG177_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG177_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG177_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG177_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG177_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG177_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG177_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG177_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG177_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG177_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG177_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG177_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG177_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG177_RESETVAL                       (0x00140003U)

/* PADCONFIG178 */

#define CSL_BOOTCFG_PADCONFIG178_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG178_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG178_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG178_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG178_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG178_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG178_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG178_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG178_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG178_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG178_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG178_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG178_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG178_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG178_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG178_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG178_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG178_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG178_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG178_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG178_RESETVAL                       (0x00140003U)

/* PADCONFIG179 */

#define CSL_BOOTCFG_PADCONFIG179_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG179_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG179_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG179_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG179_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG179_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG179_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG179_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG179_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG179_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG179_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG179_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG179_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG179_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG179_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG179_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG179_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG179_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG179_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG179_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG179_RESETVAL                       (0x00140003U)

/* PADCONFIG180 */

#define CSL_BOOTCFG_PADCONFIG180_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG180_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG180_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG180_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG180_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG180_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG180_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG180_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG180_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG180_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG180_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG180_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG180_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG180_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG180_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG180_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG180_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG180_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG180_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG180_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG180_RESETVAL                       (0x00140003U)

/* PADCONFIG181 */

#define CSL_BOOTCFG_PADCONFIG181_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG181_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG181_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG181_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG181_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG181_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG181_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG181_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG181_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG181_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG181_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG181_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG181_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG181_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG181_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG181_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG181_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG181_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG181_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG181_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG181_RESETVAL                       (0x00140003U)

/* PADCONFIG182 */

#define CSL_BOOTCFG_PADCONFIG182_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG182_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG182_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG182_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG182_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG182_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG182_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG182_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG182_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG182_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG182_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG182_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG182_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG182_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG182_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG182_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG182_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG182_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG182_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG182_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG182_RESETVAL                       (0x00140003U)

/* PADCONFIG183 */

#define CSL_BOOTCFG_PADCONFIG183_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG183_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG183_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG183_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG183_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG183_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG183_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG183_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG183_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG183_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG183_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG183_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG183_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG183_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG183_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG183_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG183_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG183_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG183_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG183_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG183_RESETVAL                       (0x00140003U)

/* PADCONFIG184 */

#define CSL_BOOTCFG_PADCONFIG184_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG184_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG184_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG184_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG184_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG184_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG184_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG184_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG184_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG184_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG184_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG184_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG184_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG184_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG184_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG184_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG184_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG184_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG184_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG184_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG184_RESETVAL                       (0x00140003U)

/* PADCONFIG185 */

#define CSL_BOOTCFG_PADCONFIG185_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG185_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG185_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG185_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG185_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG185_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG185_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG185_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG185_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG185_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG185_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG185_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG185_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG185_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG185_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG185_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG185_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG185_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG185_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG185_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG185_RESETVAL                       (0x00140003U)

/* PADCONFIG186 */

#define CSL_BOOTCFG_PADCONFIG186_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG186_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG186_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG186_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG186_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG186_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG186_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG186_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG186_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG186_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG186_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG186_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG186_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG186_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG186_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG186_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG186_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG186_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG186_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG186_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG186_RESETVAL                       (0x00140003U)

/* PADCONFIG187 */

#define CSL_BOOTCFG_PADCONFIG187_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG187_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG187_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG187_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG187_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG187_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG187_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG187_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG187_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG187_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG187_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG187_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG187_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG187_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG187_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG187_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG187_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG187_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG187_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG187_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG187_RESETVAL                       (0x00140003U)

/* PADCONFIG188 */

#define CSL_BOOTCFG_PADCONFIG188_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG188_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG188_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG188_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG188_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG188_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG188_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG188_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG188_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG188_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG188_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG188_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG188_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG188_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG188_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG188_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG188_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG188_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG188_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG188_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG188_RESETVAL                       (0x00140003U)

/* PADCONFIG189 */

#define CSL_BOOTCFG_PADCONFIG189_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG189_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG189_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG189_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG189_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG189_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG189_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG189_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG189_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG189_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG189_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG189_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG189_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG189_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG189_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG189_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG189_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG189_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG189_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG189_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG189_RESETVAL                       (0x00140003U)

/* PADCONFIG190 */

#define CSL_BOOTCFG_PADCONFIG190_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG190_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG190_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG190_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG190_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG190_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG190_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG190_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG190_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG190_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG190_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG190_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG190_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG190_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG190_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG190_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG190_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG190_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG190_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG190_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG190_RESETVAL                       (0x00140003U)

/* PADCONFIG191 */

#define CSL_BOOTCFG_PADCONFIG191_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG191_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG191_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG191_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG191_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG191_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG191_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG191_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG191_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG191_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG191_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG191_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG191_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG191_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG191_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG191_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG191_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG191_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG191_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG191_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG191_RESETVAL                       (0x00140003U)

/* PADCONFIG192 */

#define CSL_BOOTCFG_PADCONFIG192_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG192_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG192_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG192_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG192_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG192_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG192_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG192_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG192_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG192_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG192_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG192_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG192_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG192_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG192_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG192_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG192_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG192_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG192_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG192_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG192_RESETVAL                       (0x00140003U)

/* PADCONFIG193 */

#define CSL_BOOTCFG_PADCONFIG193_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG193_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG193_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG193_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG193_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG193_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG193_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG193_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG193_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG193_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG193_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG193_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG193_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG193_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG193_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG193_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG193_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG193_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG193_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG193_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG193_RESETVAL                       (0x00140003U)

/* PADCONFIG194 */

#define CSL_BOOTCFG_PADCONFIG194_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG194_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG194_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG194_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG194_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG194_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG194_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG194_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG194_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG194_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG194_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG194_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG194_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG194_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG194_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG194_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG194_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG194_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG194_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG194_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG194_RESETVAL                       (0x00140003U)

/* PADCONFIG195 */

#define CSL_BOOTCFG_PADCONFIG195_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG195_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG195_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG195_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG195_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG195_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG195_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG195_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG195_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG195_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG195_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG195_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG195_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG195_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG195_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG195_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG195_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG195_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG195_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG195_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG195_RESETVAL                       (0x00140003U)

/* PADCONFIG196 */

#define CSL_BOOTCFG_PADCONFIG196_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG196_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG196_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG196_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG196_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG196_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG196_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG196_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG196_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG196_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG196_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG196_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG196_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG196_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG196_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG196_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG196_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG196_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG196_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG196_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG196_RESETVAL                       (0x00140003U)

/* PADCONFIG197 */

#define CSL_BOOTCFG_PADCONFIG197_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG197_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG197_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG197_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG197_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG197_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG197_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG197_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG197_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG197_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG197_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG197_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG197_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG197_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG197_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG197_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG197_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG197_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG197_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG197_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG197_RESETVAL                       (0x00140003U)

/* PADCONFIG198 */

#define CSL_BOOTCFG_PADCONFIG198_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG198_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG198_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG198_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG198_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG198_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG198_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG198_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG198_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG198_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG198_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG198_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG198_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG198_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG198_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG198_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG198_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG198_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG198_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG198_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG198_RESETVAL                       (0x00140003U)

/* PADCONFIG199 */

#define CSL_BOOTCFG_PADCONFIG199_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG199_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG199_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG199_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG199_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG199_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG199_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG199_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG199_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG199_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG199_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG199_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG199_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG199_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG199_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG199_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG199_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG199_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG199_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG199_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG199_RESETVAL                       (0x00140003U)

/* PADCONFIG200 */

#define CSL_BOOTCFG_PADCONFIG200_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG200_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG200_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG200_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG200_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG200_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG200_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG200_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG200_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG200_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG200_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG200_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG200_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG200_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG200_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG200_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG200_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG200_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG200_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG200_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG200_RESETVAL                       (0x00140003U)

/* PADCONFIG201 */

#define CSL_BOOTCFG_PADCONFIG201_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG201_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG201_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG201_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG201_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG201_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG201_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG201_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG201_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG201_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG201_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG201_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG201_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG201_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG201_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG201_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG201_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG201_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG201_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG201_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG201_RESETVAL                       (0x00140003U)

/* PADCONFIG202 */

#define CSL_BOOTCFG_PADCONFIG202_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG202_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG202_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG202_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG202_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG202_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG202_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG202_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG202_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG202_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG202_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG202_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG202_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG202_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG202_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG202_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG202_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG202_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG202_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG202_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG202_RESETVAL                       (0x00140003U)

/* PADCONFIG203 */

#define CSL_BOOTCFG_PADCONFIG203_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG203_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG203_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG203_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG203_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG203_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG203_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG203_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG203_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG203_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG203_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG203_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG203_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG203_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG203_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG203_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG203_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG203_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG203_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG203_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG203_RESETVAL                       (0x00140003U)

/* PADCONFIG204 */

#define CSL_BOOTCFG_PADCONFIG204_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG204_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG204_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG204_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG204_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG204_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG204_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG204_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG204_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG204_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG204_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG204_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG204_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG204_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG204_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG204_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG204_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG204_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG204_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG204_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG204_RESETVAL                       (0x00140003U)

/* PADCONFIG205 */

#define CSL_BOOTCFG_PADCONFIG205_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG205_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG205_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG205_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG205_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG205_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG205_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG205_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG205_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG205_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG205_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG205_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG205_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG205_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG205_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG205_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG205_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG205_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG205_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG205_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG205_RESETVAL                       (0x00140003U)

/* PADCONFIG206 */

#define CSL_BOOTCFG_PADCONFIG206_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG206_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG206_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG206_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG206_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG206_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG206_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG206_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG206_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG206_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG206_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG206_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG206_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG206_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG206_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG206_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG206_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG206_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG206_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG206_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG206_RESETVAL                       (0x00140003U)

/* PADCONFIG207 */

#define CSL_BOOTCFG_PADCONFIG207_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG207_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG207_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG207_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG207_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG207_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG207_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG207_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG207_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG207_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG207_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG207_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG207_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG207_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG207_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG207_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG207_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG207_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG207_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG207_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG207_RESETVAL                       (0x00140003U)

/* PADCONFIG208 */

#define CSL_BOOTCFG_PADCONFIG208_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG208_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG208_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG208_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG208_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG208_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG208_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG208_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG208_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG208_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG208_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG208_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG208_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG208_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG208_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG208_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG208_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG208_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG208_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG208_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG208_RESETVAL                       (0x00140003U)

/* PADCONFIG209 */

#define CSL_BOOTCFG_PADCONFIG209_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG209_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG209_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG209_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG209_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG209_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG209_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG209_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG209_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG209_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG209_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG209_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG209_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG209_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG209_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG209_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG209_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG209_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG209_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG209_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG209_RESETVAL                       (0x00140003U)

/* PADCONFIG210 */

#define CSL_BOOTCFG_PADCONFIG210_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG210_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG210_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG210_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG210_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG210_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG210_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG210_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG210_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG210_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG210_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG210_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG210_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG210_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG210_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG210_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG210_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG210_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG210_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG210_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG210_RESETVAL                       (0x00140003U)

/* PADCONFIG211 */

#define CSL_BOOTCFG_PADCONFIG211_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG211_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG211_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG211_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG211_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG211_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG211_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG211_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG211_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG211_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG211_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG211_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG211_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG211_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG211_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG211_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG211_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG211_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG211_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG211_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG211_RESETVAL                       (0x00140003U)

/* PADCONFIG212 */

#define CSL_BOOTCFG_PADCONFIG212_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG212_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG212_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG212_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG212_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG212_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG212_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG212_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG212_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG212_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG212_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG212_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG212_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG212_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG212_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG212_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG212_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG212_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG212_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG212_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG212_RESETVAL                       (0x00140003U)

/* PADCONFIG213 */

#define CSL_BOOTCFG_PADCONFIG213_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG213_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG213_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG213_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG213_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG213_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG213_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG213_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG213_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG213_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG213_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG213_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG213_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG213_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG213_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG213_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG213_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG213_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG213_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG213_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG213_RESETVAL                       (0x00140003U)

/* PADCONFIG214 */

#define CSL_BOOTCFG_PADCONFIG214_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG214_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG214_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG214_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG214_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG214_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG214_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG214_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG214_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG214_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG214_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG214_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG214_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG214_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG214_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG214_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG214_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG214_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG214_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG214_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG214_RESETVAL                       (0x00140003U)

/* PADCONFIG215 */

#define CSL_BOOTCFG_PADCONFIG215_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG215_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG215_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG215_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG215_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG215_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG215_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG215_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG215_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG215_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG215_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG215_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG215_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG215_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG215_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG215_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG215_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG215_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG215_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG215_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG215_RESETVAL                       (0x00140003U)

/* PADCONFIG216 */

#define CSL_BOOTCFG_PADCONFIG216_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG216_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG216_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG216_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG216_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG216_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG216_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG216_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG216_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG216_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG216_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG216_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG216_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG216_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG216_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG216_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG216_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG216_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG216_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG216_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG216_RESETVAL                       (0x00140003U)

/* PADCONFIG217 */

#define CSL_BOOTCFG_PADCONFIG217_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG217_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG217_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG217_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG217_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG217_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG217_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG217_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG217_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG217_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG217_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG217_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG217_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG217_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG217_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG217_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG217_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG217_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG217_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG217_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG217_RESETVAL                       (0x00140003U)

/* PADCONFIG218 */

#define CSL_BOOTCFG_PADCONFIG218_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG218_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG218_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG218_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG218_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG218_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG218_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG218_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG218_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG218_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG218_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG218_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG218_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG218_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG218_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG218_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG218_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG218_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG218_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG218_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG218_RESETVAL                       (0x00140003U)

/* PADCONFIG219 */

#define CSL_BOOTCFG_PADCONFIG219_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG219_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG219_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG219_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG219_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG219_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG219_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG219_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG219_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG219_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG219_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG219_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG219_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG219_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG219_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG219_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG219_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG219_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG219_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG219_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG219_RESETVAL                       (0x00140003U)

/* PADCONFIG220 */

#define CSL_BOOTCFG_PADCONFIG220_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG220_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG220_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG220_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG220_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG220_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG220_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG220_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG220_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG220_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG220_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG220_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG220_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG220_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG220_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG220_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG220_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG220_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG220_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG220_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG220_RESETVAL                       (0x00140003U)

/* PADCONFIG221 */

#define CSL_BOOTCFG_PADCONFIG221_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG221_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG221_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG221_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG221_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG221_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG221_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG221_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG221_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG221_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG221_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG221_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG221_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG221_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG221_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG221_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG221_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG221_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG221_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG221_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG221_RESETVAL                       (0x00140003U)

/* PADCONFIG222 */

#define CSL_BOOTCFG_PADCONFIG222_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG222_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG222_MUXMODE_RESETVAL               (0x00000003U)
#define CSL_BOOTCFG_PADCONFIG222_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG222_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG222_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG222_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG222_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG222_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG222_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG222_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG222_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG222_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG222_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG222_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG222_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG222_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG222_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG222_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG222_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG222_RESETVAL                       (0x00140003U)

/* PADCONFIG223 */

#define CSL_BOOTCFG_PADCONFIG223_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG223_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG223_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG223_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG223_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG223_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG223_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG223_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG223_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG223_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG223_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG223_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG223_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG223_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG223_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG223_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG223_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG223_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG223_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG223_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG223_RESETVAL                       (0x00060000U)

/* PADCONFIG224 */

#define CSL_BOOTCFG_PADCONFIG224_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG224_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG224_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG224_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG224_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG224_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG224_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG224_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG224_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG224_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG224_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG224_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG224_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG224_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG224_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG224_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG224_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG224_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG224_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG224_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG224_RESETVAL                       (0x00060000U)

/* PADCONFIG225 */

#define CSL_BOOTCFG_PADCONFIG225_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG225_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG225_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG225_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG225_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG225_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG225_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG225_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG225_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG225_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG225_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG225_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG225_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG225_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG225_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG225_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG225_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG225_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG225_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG225_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG225_RESETVAL                       (0x00060000U)

/* PADCONFIG226 */

#define CSL_BOOTCFG_PADCONFIG226_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG226_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG226_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG226_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG226_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG226_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG226_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG226_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG226_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG226_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG226_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG226_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG226_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG226_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG226_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG226_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG226_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG226_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG226_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG226_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG226_RESETVAL                       (0x00060000U)

/* PADCONFIG227 */

#define CSL_BOOTCFG_PADCONFIG227_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG227_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG227_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG227_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG227_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG227_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG227_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG227_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG227_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG227_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG227_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG227_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG227_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG227_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG227_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG227_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG227_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG227_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG227_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG227_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG227_RESETVAL                       (0x00060000U)

/* PADCONFIG228 */

#define CSL_BOOTCFG_PADCONFIG228_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG228_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG228_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG228_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG228_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG228_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG228_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG228_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG228_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG228_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG228_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG228_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG228_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG228_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG228_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG228_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG228_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG228_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG228_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG228_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG228_RESETVAL                       (0x00060000U)

/* PADCONFIG229 */

#define CSL_BOOTCFG_PADCONFIG229_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG229_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG229_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG229_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG229_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG229_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG229_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG229_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG229_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG229_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG229_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG229_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG229_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG229_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG229_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG229_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG229_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG229_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG229_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG229_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG229_RESETVAL                       (0x000e0000U)

/* PADCONFIG230 */

#define CSL_BOOTCFG_PADCONFIG230_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG230_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG230_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG230_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG230_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG230_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG230_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG230_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG230_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG230_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG230_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG230_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG230_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG230_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG230_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG230_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG230_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG230_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG230_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG230_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG230_RESETVAL                       (0x000e0000U)

/* PADCONFIG231 */

#define CSL_BOOTCFG_PADCONFIG231_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG231_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG231_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG231_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG231_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG231_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG231_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG231_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG231_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG231_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG231_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG231_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG231_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG231_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG231_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG231_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG231_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG231_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG231_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG231_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG231_RESETVAL                       (0x000e0000U)

/* PADCONFIG232 */

#define CSL_BOOTCFG_PADCONFIG232_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG232_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG232_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG232_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG232_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG232_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG232_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG232_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG232_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG232_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG232_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG232_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG232_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG232_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG232_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG232_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG232_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG232_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG232_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG232_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG232_RESETVAL                       (0x000e0000U)

/* PADCONFIG233 */

#define CSL_BOOTCFG_PADCONFIG233_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG233_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG233_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG233_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG233_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG233_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG233_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG233_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG233_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG233_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG233_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG233_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG233_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG233_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG233_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG233_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG233_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG233_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG233_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG233_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG233_RESETVAL                       (0x000e0000U)

/* PADCONFIG234 */

#define CSL_BOOTCFG_PADCONFIG234_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG234_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG234_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG234_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG234_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG234_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG234_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG234_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG234_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG234_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG234_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG234_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG234_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG234_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG234_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG234_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG234_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG234_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG234_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG234_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG234_RESETVAL                       (0x000d0000U)

/* PADCONFIG235 */

#define CSL_BOOTCFG_PADCONFIG235_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG235_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG235_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG235_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG235_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG235_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG235_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG235_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG235_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG235_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG235_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG235_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG235_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG235_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG235_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG235_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG235_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG235_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG235_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG235_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG235_RESETVAL                       (0x000e0000U)

/* PADCONFIG236 */

#define CSL_BOOTCFG_PADCONFIG236_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG236_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG236_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG236_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG236_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG236_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG236_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG236_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG236_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG236_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG236_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG236_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG236_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG236_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG236_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG236_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG236_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG236_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG236_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG236_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG236_RESETVAL                       (0x000c0000U)

/* PADCONFIG237 */

#define CSL_BOOTCFG_PADCONFIG237_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG237_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG237_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG237_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG237_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG237_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG237_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG237_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG237_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG237_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG237_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG237_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG237_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG237_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG237_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG237_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG237_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG237_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG237_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG237_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG237_RESETVAL                       (0x000c0000U)

/* PADCONFIG238 */

#define CSL_BOOTCFG_PADCONFIG238_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG238_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG238_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG238_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG238_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG238_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG238_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG238_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG238_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG238_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG238_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG238_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG238_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG238_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG238_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG238_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG238_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG238_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG238_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG238_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG238_RESETVAL                       (0x000c0000U)

/* PADCONFIG239 */

#define CSL_BOOTCFG_PADCONFIG239_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG239_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG239_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG239_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG239_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG239_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG239_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG239_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG239_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG239_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG239_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG239_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG239_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG239_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG239_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG239_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG239_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG239_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG239_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG239_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG239_RESETVAL                       (0x00050000U)

/* PADCONFIG240 */

#define CSL_BOOTCFG_PADCONFIG240_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG240_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG240_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG240_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG240_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG240_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG240_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG240_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG240_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG240_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG240_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG240_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG240_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG240_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG240_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG240_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG240_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG240_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG240_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG240_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG240_RESETVAL                       (0x00050000U)

/* PADCONFIG241 */

#define CSL_BOOTCFG_PADCONFIG241_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG241_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG241_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG241_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG241_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG241_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG241_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG241_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG241_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG241_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG241_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG241_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG241_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG241_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG241_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG241_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG241_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG241_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG241_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG241_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG241_RESETVAL                       (0x00050000U)

/* PADCONFIG242 */

#define CSL_BOOTCFG_PADCONFIG242_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG242_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG242_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG242_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG242_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG242_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG242_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG242_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG242_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG242_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG242_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG242_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG242_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG242_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG242_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG242_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG242_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG242_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG242_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG242_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG242_RESETVAL                       (0x00050000U)

/* PADCONFIG243 */

#define CSL_BOOTCFG_PADCONFIG243_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG243_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG243_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG243_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG243_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG243_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG243_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG243_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG243_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG243_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG243_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG243_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG243_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG243_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG243_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG243_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG243_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG243_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG243_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG243_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG243_RESETVAL                       (0x00050000U)

/* PADCONFIG244 */

#define CSL_BOOTCFG_PADCONFIG244_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG244_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG244_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG244_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG244_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG244_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG244_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG244_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG244_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG244_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG244_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG244_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG244_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG244_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG244_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG244_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG244_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG244_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG244_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG244_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG244_RESETVAL                       (0x00050000U)

/* PADCONFIG245 */

#define CSL_BOOTCFG_PADCONFIG245_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG245_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG245_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG245_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG245_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG245_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG245_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG245_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG245_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG245_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG245_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG245_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG245_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG245_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG245_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG245_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG245_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG245_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG245_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG245_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG245_RESETVAL                       (0x00160000U)

/* PADCONFIG246 */

#define CSL_BOOTCFG_PADCONFIG246_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG246_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG246_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG246_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG246_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG246_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG246_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG246_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG246_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG246_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG246_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG246_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG246_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG246_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG246_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG246_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG246_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG246_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG246_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG246_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG246_RESETVAL                       (0x00060000U)

/* PADCONFIG247 */

#define CSL_BOOTCFG_PADCONFIG247_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG247_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG247_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG247_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG247_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG247_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG247_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG247_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG247_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG247_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG247_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG247_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG247_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG247_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG247_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG247_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG247_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG247_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG247_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG247_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG247_RESETVAL                       (0x000e0000U)

/* PADCONFIG248 */

#define CSL_BOOTCFG_PADCONFIG248_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG248_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG248_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG248_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG248_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG248_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG248_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG248_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG248_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG248_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG248_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG248_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG248_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG248_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG248_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG248_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG248_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG248_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG248_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG248_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG248_RESETVAL                       (0x00060000U)

/* PADCONFIG249 */

#define CSL_BOOTCFG_PADCONFIG249_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG249_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG249_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG249_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG249_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG249_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG249_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG249_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG249_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG249_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG249_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG249_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG249_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG249_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG249_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG249_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG249_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG249_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG249_BUFFERCLASS_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG249_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG249_RESETVAL                       (0x00040000U)

/* PADCONFIG250 */

#define CSL_BOOTCFG_PADCONFIG250_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG250_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG250_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG250_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG250_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG250_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG250_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG250_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG250_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG250_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG250_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG250_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG250_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG250_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG250_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG250_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG250_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG250_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG250_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG250_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG250_RESETVAL                       (0x00160000U)

/* PADCONFIG251 */

#define CSL_BOOTCFG_PADCONFIG251_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG251_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG251_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG251_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG251_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG251_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG251_PULLUDEN_RESETVAL              (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG251_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG251_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG251_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG251_PULLTYPESEL_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG251_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG251_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG251_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG251_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG251_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG251_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG251_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG251_BUFFERCLASS_RESETVAL           (0x00000002U)
#define CSL_BOOTCFG_PADCONFIG251_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG251_RESETVAL                       (0x00160000U)

/* PADCONFIG252 */

#define CSL_BOOTCFG_PADCONFIG252_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG252_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG252_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG252_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG252_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG252_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG252_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG252_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG252_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG252_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG252_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG252_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG252_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG252_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG252_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG252_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG252_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG252_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG252_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG252_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG252_RESETVAL                       (0x000d0000U)

/* PADCONFIG253 */

#define CSL_BOOTCFG_PADCONFIG253_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG253_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG253_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG253_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG253_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG253_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG253_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG253_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG253_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG253_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG253_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG253_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG253_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG253_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG253_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG253_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG253_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG253_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG253_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG253_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG253_RESETVAL                       (0x000d0000U)

/* PADCONFIG254 */

#define CSL_BOOTCFG_PADCONFIG254_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG254_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG254_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG254_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG254_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG254_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG254_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG254_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG254_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG254_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG254_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG254_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG254_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG254_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG254_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG254_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG254_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG254_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG254_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG254_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG254_RESETVAL                       (0x000d0000U)

/* PADCONFIG255 */

#define CSL_BOOTCFG_PADCONFIG255_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG255_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG255_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG255_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG255_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG255_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG255_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG255_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG255_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG255_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG255_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG255_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG255_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG255_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG255_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG255_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG255_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG255_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG255_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG255_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG255_RESETVAL                       (0x000d0000U)

/* PADCONFIG256 */

#define CSL_BOOTCFG_PADCONFIG256_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG256_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG256_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG256_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG256_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG256_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG256_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG256_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG256_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG256_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG256_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG256_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG256_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG256_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG256_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG256_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG256_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG256_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG256_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG256_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG256_RESETVAL                       (0x000d0000U)

/* PADCONFIG257 */

#define CSL_BOOTCFG_PADCONFIG257_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG257_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG257_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG257_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG257_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG257_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG257_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG257_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG257_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG257_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG257_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG257_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG257_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG257_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG257_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG257_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG257_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG257_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG257_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG257_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG257_RESETVAL                       (0x000d0000U)

/* PADCONFIG258 */

#define CSL_BOOTCFG_PADCONFIG258_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG258_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG258_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG258_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG258_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG258_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG258_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG258_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG258_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG258_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG258_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG258_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG258_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG258_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG258_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG258_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG258_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG258_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG258_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG258_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG258_RESETVAL                       (0x000d0000U)

/* PADCONFIG259 */

#define CSL_BOOTCFG_PADCONFIG259_MUXMODE_MASK                   (0x0000000FU)
#define CSL_BOOTCFG_PADCONFIG259_MUXMODE_SHIFT                  (0U)
#define CSL_BOOTCFG_PADCONFIG259_MUXMODE_RESETVAL               (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG259_MUXMODE_MAX                    (0x0000000fU)

#define CSL_BOOTCFG_PADCONFIG259_PULLUDEN_MASK                  (0x00010000U)
#define CSL_BOOTCFG_PADCONFIG259_PULLUDEN_SHIFT                 (16U)
#define CSL_BOOTCFG_PADCONFIG259_PULLUDEN_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG259_PULLUDEN_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG259_PULLTYPESEL_MASK               (0x00020000U)
#define CSL_BOOTCFG_PADCONFIG259_PULLTYPESEL_SHIFT              (17U)
#define CSL_BOOTCFG_PADCONFIG259_PULLTYPESEL_RESETVAL           (0x00000000U)
#define CSL_BOOTCFG_PADCONFIG259_PULLTYPESEL_MAX                (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG259_RXACTIVE_MASK                  (0x00040000U)
#define CSL_BOOTCFG_PADCONFIG259_RXACTIVE_SHIFT                 (18U)
#define CSL_BOOTCFG_PADCONFIG259_RXACTIVE_RESETVAL              (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG259_RXACTIVE_MAX                   (0x00000001U)

#define CSL_BOOTCFG_PADCONFIG259_BUFFERCLASS_MASK               (0x00180000U)
#define CSL_BOOTCFG_PADCONFIG259_BUFFERCLASS_SHIFT              (19U)
#define CSL_BOOTCFG_PADCONFIG259_BUFFERCLASS_RESETVAL           (0x00000001U)
#define CSL_BOOTCFG_PADCONFIG259_BUFFERCLASS_MAX                (0x00000003U)

#define CSL_BOOTCFG_PADCONFIG259_RESETVAL                       (0x000d0000U)

#ifdef __cplusplus
}
#endif
#endif
