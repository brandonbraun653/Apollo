#
# This file is the makefile for building CSL library.
#
#   Copyright (c) Texas Instruments Incorporated 2015
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

MODULE_NAME = csl

SRCDIR = .
INCDIR = .

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl

# List all the internal submodules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES += csl

# Common source files and CFLAGS across all platforms and cores

#Include src files for only the modules defined under csl_COMP_LIST
SRCS_COMMON =
# Include all common files and also the top level makefiles as CSL is the base module
PACKAGE_SRCS_COMMON  = makefile makefile.mk csl_component.mk .gitignore csl.h cslr.h csl_error.h
PACKAGE_SRCS_COMMON += cslr_device.h soc.h csl_mainpage.h
PACKAGE_SRCS_COMMON += hw_types.h tistdtypes.h csl_types.h csl_utils.h
PACKAGE_SRCS_COMMON += docs
#Package Build folder as well as build folder doesn't have a make package on its own
PACKAGE_SRCS_COMMON += ../build/makefile ../build/Rules.make ../build/makerules ../build/makefile_non-buildinfra ../build/readme.txt
PACKAGE_SRCS_COMMON += ../build/comp_paths.mk ../build/comp_top.mk ../build/pdk_tools_path.mk
PACKAGE_SRCS_COMMON += ../build/procsdk_defs.mk ../build/soc_info.mk 
PACKAGE_SRCS_COMMON += ../build/docs
PACKAGE_SRCS_COMMON += ../build/unit-test
ifeq ($(SOC),$(filter $(SOC), tda2px))
PACKAGE_SRCS_COMMON += ../build/tda2xx
else
PACKAGE_SRCS_COMMON += ../build/$(SOC)
endif

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

#SOC modules
-include $(PDK_CSL_COMP_PATH)/soc/src_files_soc.mk
# Arch modules
-include $(PDK_CSL_COMP_PATH)/arch/src_files_arch.mk
# IP modules
-include src/ip/adc/src_files_adc.mk
-include src/ip/cache/src_files_cache.mk
-include src/ip/cal/src_files_cal.mk
-include src/ip/cbass/src_files_cbass.mk
-include src/ip/cgem/src_files_cgem.mk
-include src/ip/chr_us/src_files_chr_us.mk
-include src/ip/cpts/src_files_cpts.mk
-include src/ip/clec/src_files_clec.mk
-include src/ip/csirx/src_files_csirx.mk
-include src/ip/csitx/src_files_csitx.mk
-include src/ip/crc/src_files_crc.mk
-include src/ip/csc/src_files_csc.mk
-include src/ip/dcan/src_files_dcan.mk
-include src/ip/dcc/src_files_dcc.mk
-include src/ip/lpddr/src_files_lpddr.mk
-include src/ip/dei/src_files_dei.mk
-include src/ip/dru/src_files_dru.mk
-include src/ip/dss/src_files_dss.mk
-include src/ip/dmpac/src_files_dmpac.mk
-include src/ip/ecc_aggr/src_files_ecc_aggr.mk
-include src/ip/edma/src_files_edma.mk
-include src/ip/elm/src_files_elm.mk
-include src/ip/emif/src_files_emif.mk
-include src/ip/emif4/src_files_emif4f.mk
-include src/ip/epwm/src_files_epwm.mk
-include src/ip/esm/src_files_esm.mk
-include src/ip/eve/src_files_eve.mk
-include src/ip/fss/src_files_fss.mk
-include src/ip/gpio/src_files_gpio.mk
-include src/ip/gpmc/src_files_gpmc.mk
-include src/ip/hyperbus/src_files_hyperbus.mk
-include src/ip/i2c/src_files_i2c.mk
-include src/ip/i3c/src_files_i3c.mk
-include src/ip/intaggr/src_files_intaggr.mk
-include src/ip/intr_router/src_files_intr_router.mk
-include src/ip/iss/src_files_iss.mk
-include src/ip/l3fw/src_files_l3fw.mk
-include src/ip/l4fw/src_files_l4fw.mk
-include src/ip/mailbox/src_files_mailbox.mk
-include src/ip/mcan/src_files_mcan.mk
-include src/ip/mcasp/src_files_mcasp.mk
-include src/ip/mcspi/src_files_mcspi.mk
-include src/ip/mmc/src_files_mmc.mk
-include src/ip/mmu/src_files_mmu.mk
-include src/ip/navss/src_files_navss.mk
-include src/ip/ocmc/src_files_ocmc.mk
-include src/ip/ospi/src_files_ospi.mk
-include src/ip/pat/src_files_pat.mk
-include src/ip/pcie/src_files_pcie.mk
-include src/ip/proxy/src_files_proxy.mk
-include src/ip/psilcfg/src_files_psilcfg.mk
-include src/ip/psilss/src_files_psilss.mk
-include src/ip/pvu/src_files_pvu.mk
-include src/ip/qspi/src_files_qspi.mk
-include src/ip/rat/src_files_rat.mk
-include src/ip/ringacc/src_files_ringacc.mk
-include src/ip/rti/src_files_rti.mk
-include src/ip/sc/src_files_sc.mk
-include src/ip/sci/src_files_sci.mk
-include src/ip/sec_proxy/src_files_sec_proxy.mk
-include src/ip/spinlock/src_files_spinlock.mk
-include src/ip/synctimer/src_files_synctimer.mk
-include src/ip/tesoc/src_files_tesoc.mk
-include src/ip/timer/src_files_timer.mk
-include src/ip/timer_mgr/src_files_timer_mgr.mk
-include src/ip/uart/src_files_uart.mk
-include src/ip/usb/src_files_usb.mk
-include src/ip/udmap/src_files_udmap.mk
-include src/ip/vip/src_files_vip.mk
-include src/ip/vpdma/src_files_vpdma.mk
-include src/ip/vpe/src_files_vpe.mk
-include src/ip/wd_timer/src_files_wd_timer.mk
-include src/ip/tsc/src_files_tsc.mk
-include src/ip/chip/src_files_chip.mk
-include src/ip/aif2/src_files_aif2.mk
-include src/ip/cpsw/src_files_cpsw.mk
-include src/ip/mdio/src_files_mdio.mk
-include src/ip/tac2/src_files_tac2.mk
-include src/ip/serdes_sb/src_files_serdessb.mk
-include src/ip/serdes_cd/src_files_serdescd.mk
-include src/ip/srio/src_files_srio.mk
-include src/ip/sgmii/src_files_sgmii.mk
-include src/ip/vcp2/src_files_vcp2.mk
-include src/ip/vpac/src_files_vpac.mk
-include src/ip/vpfe/src_files_vpfe.mk
-include src/ip/usim/src_files_usim.mk
-include src/ip/xge/src_files_xge.mk
-include src/ip/ecap/src_files_ecap.mk
-include src/ip/arm_gic/src_files_arm_gic.mk
-include src/ip/vtm/src_files_vtm.mk
-include src/ip/hts/src_files_hts.mk
-include src/ip/lse/src_files_lse.mk
-include src/ip/ctset2/src_files_ctset2.mk
-include src/ip/ale/src_files_ale.mk
-include src/ip/icss/src_files_icss.mk
-include src/ip/emac/src_files_emac.mk
-include src/ip/cpgmac/src_files_cpgmac.mk
-include src/ip/tog/src_files_tog.mk
-include src/ip/pbist/src_files_pbist.mk
-include src/ip/gtc/src_files_gtc.mk
-include src/ip/fsi_rx/src_files_fsi_rx.mk
-include src/ip/fsi_tx/src_files_fsi_tx.mk
-include src/ip/lbist/src_files_lbist.mk
-include src/ip/psc/src_files_psc.mk

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
