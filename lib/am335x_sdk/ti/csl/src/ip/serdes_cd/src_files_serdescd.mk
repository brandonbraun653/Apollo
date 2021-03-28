
ifeq ($(SOC),$(filter $(SOC), j721e))
  # serdes_cd has compilation errors in host emulation build. This is not required in host emu. Hence disable
  ifneq ($(CORE),$(filter $(CORE), c7x-hostemu))
    PACKAGE_SRCS_COMMON += src/ip/serdes_cd/V0
    PACKAGE_SRCS_COMMON += src/ip/serdes_cd/src_files_serdescd.mk
    PACKAGE_SRCS_COMMON += csl_serdes.h
    PACKAGE_SRCS_COMMON += csl_serdes_ethernet.h csl_serdes_edp.h
    PACKAGE_SRCS_COMMON += csl_serdes_pcie.h csl_serdes_usb.h
    
    SRCS_COMMON += csl_serdes3.c
    SRCS_COMMON += csl_serdes3_edp.c
    SRCS_COMMON += csl_serdes3_ethernet.c
    SRCS_COMMON += csl_serdes3_pcie.c
    SRCS_COMMON += csl_serdes3_usb.c
    SRCS_COMMON += csl_serdes3_multilink.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_QSGMII.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_SGMII_cmn.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_SGMII_cmn_pll.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_SGMII_ln.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_USB.c
    SRCS_COMMON += csl_wiz16m_ct_20b_eDP_cmn_2p7G.c
    SRCS_COMMON += csl_wiz16m_ct_20b_eDP_cmn_5p4G.c
    SRCS_COMMON += csl_wiz16m_ct_20b_eDP_cmn_8p1G.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_cmn_pll_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_cmn_pll1_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_cmn_pll_10G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_cmn_pll1_10G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_cmn_pll_6p25G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_cmn_pll1_6p25G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_20b_eDP_cmn_pll_8p1G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_20b_eDP_cmn_pll_10p8G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_20b_eDP_cmn_pll_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_20b_eDP_cmn_pll1_8p1G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_20b_eDP_cmn_pll1_10p8G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_20b_eDP_cmn_pll1_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_20b_QSGMII_cmn.c
    SRCS_COMMON += csl_wiz16m_ct_refclk19p2MHz_refclk_related.c
    SRCS_COMMON += csl_wiz16m_ct_refclk100MHz_20b_eDP_cmn_pll_8p1G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk100MHz_20b_eDP_cmn_pll_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk100MHz_20b_eDP_cmn_pll1_8p1G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk100MHz_20b_eDP_cmn_pll1_all_vco.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_QSGMII_cmn_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_QSGMII_cmn_pll_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_QSGMII_cmn_pll_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_QSGMII_ln_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_QSGMII_ln_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII_cmn_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII_cmn_multilink_pll1_opt3.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII_cmn_pll_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII_cmn_pll_multilink_pll1_opt3.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII_ln_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_SGMII_ln_multilink_pll1_opt3.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_USB_cmn_ext_ssc_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_USB_cmn_pll_ext_ssc_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_20b_USB_ln_ext_ssc_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe_cmn_pll_ext_ssc_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe_cmn_pll_int_ssc_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe_ln_ext_ssc_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe_ln_int_ssc_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI_cmn_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI_cmn_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI_cmn_pll_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI_cmn_pll_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI_ln_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_20b_XAUI_ln_multilink_pll1.c
    SRCS_COMMON += csl_wiz16m_ct_20b_SGMII_cmn.c
    SRCS_COMMON += csl_wiz16m_ct_refclk100MHz_20b_SGMII_QSGMII_cmn_pll_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk100MHz_20b_SGMII_QSGMII_cmn_pll1_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk156p25MHz_20b_XAUI_cmn_pll_6p25G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk156p25MHz_20b_XAUI_cmn_pll_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk156p25MHz_20b_XAUI_cmn_pll1_6p25G_vco.c
    SRCS_COMMON += csl_wiz16m_ct_refclk156p25MHz_20b_XAUI_cmn_pll1_all_vco.c
    SRCS_COMMON += csl_wiz16m_ct_20b_XAUI_cmn.c
    SRCS_COMMON += csl_wiz16m_ct_refclk156p25MHz_refclk_related.c
    SRCS_COMMON += csl_wiz16m_cs_refclk19p2MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_cs_refclk19p2MHz_20b_SGMII.c
    SRCS_COMMON += csl_wiz16m_cs_refclk19p2MHz_20b_USB.c
    SRCS_COMMON += csl_wiz16m_cs_refclk19p2MHz_20b_QSGMII.c
    SRCS_COMMON += csl_wiz16m_cs_refclk156p25MHz_32b_XFI.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe_cmn_pll_no_ssc_multilink_pll0.c
    SRCS_COMMON += csl_wiz16m_cs_refclk100MHz_32b_PCIe_ln_no_ssc_multilink_pll0.c
    
    SRCDIR += src/ip/serdes_cd/V0
    INCDIR += . src/ip/serdes_cd/V0
  endif
endif

ifeq ($(SOC),$(filter $(SOC), j7200 ))
  # serdes_cd has compilation errors in host emulation build. This is not required in host emu. Hence disable
  ifneq ($(CORE),$(filter $(CORE), c7x-hostemu))
    PACKAGE_SRCS_COMMON += src/ip/serdes_cd/V1
    PACKAGE_SRCS_COMMON += src/ip/serdes_cd/src_files_serdescd.mk
    PACKAGE_SRCS_COMMON += csl_serdes.h
    PACKAGE_SRCS_COMMON += csl_serdes_ethernet.h
    PACKAGE_SRCS_COMMON += csl_serdes_pcie.h csl_serdes_usb.h

    SRCS_COMMON += csl_serdes3.c
    SRCS_COMMON += csl_serdes3_ethernet.c
    SRCS_COMMON += csl_serdes3_pcie.c
    SRCS_COMMON += csl_serdes3_usb.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk100MHz_20b_QSGMII.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk100MHz_20b_SGMII.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk100MHz_20b_USXGMII.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk100MHz_20b_XAUI.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk100MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk19p2MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk20MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk24MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk25MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk26MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk27MHz_32b_PCIe.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk100MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk19p2MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk20MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk24MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk25MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk26MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk27MHz_32b_USB.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk125MHz_20b_QSGMII.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk125MHz_20b_SGMII.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk156p25MHz_20b_USXGMII.c
    SRCS_COMMON += csl_wiz16m_ct2_refclk156p25MHz_20b_XAUI.c
    
    SRCDIR += src/ip/serdes_cd/V1
    SRCDIR += src/ip/serdes_cd/V1/V1_0
    INCDIR += . src/ip/serdes_cd/V1
  endif
endif    
