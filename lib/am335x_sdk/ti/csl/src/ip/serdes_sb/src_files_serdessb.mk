
ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g))

PACKAGE_SRCS_COMMON += csl_serdes_10ge.h csl_serdes_dfe.h csl_serdes.h
PACKAGE_SRCS_COMMON += csl_serdes_iqn.h csl_serdes_restore_default.h
PACKAGE_SRCS_COMMON += csl_serdes_aif2.h csl_serdes_ethernet.h
PACKAGE_SRCS_COMMON += csl_serdes_hyperlink.h csl_serdes_pcie.h csl_serdes_srio.h

PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/cslr_wiz8b4m4sb.h     
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/cslr_wiz8b8m4sb.h   
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_aif2.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_pcie.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_wiz8_sb.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/cslr_wiz8b4sb_2ckr.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/cslr_wiz8b8sb.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_dfe.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_hyperlink.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_restore_default.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/cslr_wiz8b4sb.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_10ge.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_ethernet.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_iqn.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V0/csl_serdes2_srio.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/src_files_serdessb.mk src/ip/serdes_sb/V0

SRCS_COMMON += cslr_wiz8b4m4sb_resetread.c
SRCS_COMMON += csl_wiz8_sb_PhyB_reset_clr.c
SRCS_COMMON += csl_wiz8_sb_refclk153p6MHz_20bit_6p144Gbps_2l1c.c
SRCS_COMMON += cslr_wiz8b4sb_2ckr_resetread.c
SRCS_COMMON += csl_wiz8_sb_refclk100MHz_pci_5Gbps.c
SRCS_COMMON += csl_wiz8_sb_refclk153p6MHz_20bit_6p144Gbps.c
SRCS_COMMON += cslr_wiz8b4sb_resetread.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps_2l1c.c
SRCS_COMMON += csl_wiz8_sb_refclk156p25MHz_10bit_5Gbps.c
SRCS_COMMON += cslr_wiz8b8m4sb_resetread.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps.c
SRCS_COMMON += csl_wiz8_sb_refclk156p25MHz_20bit_10Gbps_sr1.c
SRCS_COMMON += cslr_wiz8b8sb_resetread.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps_2l1c.c
SRCS_COMMON += csl_wiz8_sb_refclk156p25MHz_20bit_12p5Gbps_sr1.c
SRCS_COMMON += csl_wiz8_sb_PhyB_10p3125G_156p25MHz_cmu1.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps.c
SRCS_COMMON += csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps.c
SRCS_COMMON += csl_wiz8_sb_PhyB_10p3125G_16bit_lane1.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_7p3728Gbps_2l1c.c
SRCS_COMMON += csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps_sr1.c
SRCS_COMMON += csl_wiz8_sb_PhyB_10p3125G_16bit_lane2.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_9p8304Gbps_2l1c_AIF_sr1.c
SRCS_COMMON += csl_wiz8_sb_refclk156p25MHz_20bit_6p25Gbps.c
SRCS_COMMON += csl_wiz8_sb_PhyB_10p3125G_comlane.c
SRCS_COMMON += csl_wiz8_sb_refclk122p88MHz_20bit_9p8304Gbps_2l1c_JESD.c     
SRCS_COMMON += csl_wiz8_sb_refclk312p5MHz_20bit_10Gbps_sr1.c
SRCS_COMMON += csl_wiz8_sb_PhyB_1p25G_156p25MHz_cmu0.c
SRCS_COMMON += csl_wiz8_sb_refclk125MHz_10bit_5Gbps.c
SRCS_COMMON += csl_wiz8_sb_refclk312p5MHz_20bit_12p5Gbps_sr1.c
SRCS_COMMON += csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane.c
SRCS_COMMON += csl_wiz8_sb_refclk125MHz_20bit_5Gbps.c
SRCS_COMMON += csl_wiz8_sb_refclk312p5MHz_20bit_5Gbps.c
SRCS_COMMON += csl_wiz8_sb_PhyB_aneg_lane1.c
SRCS_COMMON += csl_wiz8_sb_refclk125MHz_20bit_6p25Gbps.c
SRCS_COMMON += csl_wiz8_sb_refclk312p5MHz_20bit_5Gbps_sr1.c
SRCS_COMMON += csl_wiz8_sb_PhyB_aneg_lane2.c
SRCS_COMMON += csl_wiz8_sb_refclk153p6MHz_20bit_4p9152Gbps_2l1c_sr1.c
SRCS_COMMON += csl_wiz8_sb_refclk312p5MHz_20bit_6p25Gbps.c
SRCS_COMMON += csl_wiz8_sb_PhyB_Firmware.c
SRCS_COMMON += csl_wiz8_sb_refclk153p6MHz_20bit_4p9152Gbps_sr1.c

SRCDIR += src/ip/serdes_sb/V0
INCDIR += . src/ip/serdes_sb/V0

endif

ifeq ($(SOC),$(filter $(SOC), am65xx))

PACKAGE_SRCS_COMMON += src/ip/serdes_sb/V1 csl_serdes_ethernet.h
PACKAGE_SRCS_COMMON += csl_serdes.h csl_serdes_pcie.h csl_serdes_usb.h
PACKAGE_SRCS_COMMON += src/ip/serdes_sb/src_files_serdessb.mk

SRCS_COMMON += csl_serdes3.c
SRCS_COMMON += csl_serdes3_ethernet.c
SRCS_COMMON += csl_serdes3_pcie.c
SRCS_COMMON += csl_serdes3_usb.c
SRCS_COMMON += csl_wiz8m_sb_refclk20p0MHz_16b_5p0Gbps_USB_1l1c_sr.c
SRCS_COMMON += csl_wiz8m_sb_refclk100p0MHz_16b_5p0Gbps_USB_1l1c_sr.c
SRCS_COMMON += csl_wiz8m_sb_refclk100p0MHz_32b_8Gbps_PCIE_1l1c.c
SRCS_COMMON += csl_wiz8m_sb_refclk100p0MHz_32b_8Gbps_PCIE_2l1c.c
SRCS_COMMON += csl_wiz8m_sb_refclk125p0MHz_10b_1p25Gbps_SGMII_1l1c_sr4.c
SRCS_COMMON += csl_wiz8m_sb_refclk125p0MHz_10b_1p25Gbps_SGMII_2l1c_sr4.c
SRCS_COMMON += csl_wiz8m_sb_refclk156p25MHz_10b_1p25Gbps_SGMII_1l1c_sr4.c
SRCS_COMMON += csl_wiz8m_sb_refclk156p25MHz_10b_1p25Gbps_SGMII_2l1c_sr4.c
SRCS_COMMON += csl_wiz8m_sb_refclk156p25MHz_10b_3p125Gbps_SGMII_1l1c_sr2.c
SRCS_COMMON += csl_wiz8m_sb_refclk156p25MHz_10b_3p125Gbps_SGMII_2l1c_sr2.c

SRCDIR += src/ip/serdes_sb/V1
INCDIR += . src/ip/serdes_sb/V1

endif
