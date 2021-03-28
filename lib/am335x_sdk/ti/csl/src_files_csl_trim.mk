#
# This file is the source file lists for building CSL_TRIM library.
#
#   Copyright (c) Texas Instruments Incorporated 2019
#

# Arch modules
ifeq ($(SOC),$(filter $(SOC), am65xx))
-include $(PDK_CSL_COMP_PATH)/arch/a53/src_files_a53.mk
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5.mk
endif

# IP modules
# IP modules
-include src/ip/adc/src_files_adc.mk
-include src/ip/cache/src_files_cache.mk
-include src/ip/cal/src_files_cal.mk
-include src/ip/chr_us/src_files_chr_us.mk
-include src/ip/cpts/src_files_cpts.mk
-include src/ip/clec/src_files_clec.mk
-include src/ip/csc/src_files_csc.mk
-include src/ip/dcan/src_files_dcan.mk
-include src/ip/dcc/src_files_dcc.mk
-include src/ip/dei/src_files_dei.mk
-include src/ip/dru/src_files_dru.mk
-include src/ip/dss/src_files_dss.mk
-include src/ip/edma/src_files_edma.mk
-include src/ip/elm/src_files_elm.mk
-include src/ip/emif/src_files_emif.mk
-include src/ip/epwm/src_files_epwm.mk
-include src/ip/eve/src_files_eve.mk
-include src/ip/gpio/src_files_gpio.mk
-include src/ip/gpmc/src_files_gpmc.mk
-include src/ip/hyperbus/src_files_hyperbus.mk
-include src/ip/i2c/src_files_i2c.mk
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
-include src/ip/ocmc/src_files_ocmc.mk
-include src/ip/ospi/src_files_ospi.mk
-include src/ip/pat/src_files_pat.mk
-include src/ip/pcie/src_files_pcie.mk
-include src/ip/proxy/src_files_proxy.mk
-include src/ip/psilcfg/src_files_psilcfg.mk
-include src/ip/pvu/src_files_pvu.mk
-include src/ip/qspi/src_files_qspi.mk
-include src/ip/ringacc/src_files_ringacc.mk
-include src/ip/sc/src_files_sc.mk
-include src/ip/sec_proxy/src_files_sec_proxy.mk
-include src/ip/spinlock/src_files_spinlock.mk
-include src/ip/synctimer/src_files_synctimer.mk
-include src/ip/tesoc/src_files_tesoc.mk
-include src/ip/timer_mgr/src_files_timer_mgr.mk
-include src/ip/uart/src_files_uart.mk
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
-include src/ip/srio/src_files_srio.mk
-include src/ip/sgmii/src_files_sgmii.mk
-include src/ip/vcp2/src_files_vcp2.mk
-include src/ip/usim/src_files_usim.mk
-include src/ip/xge/src_files_xge.mk
-include src/ip/ecap/src_files_ecap.mk
-include src/ip/arm_gic/src_files_arm_gic.mk
-include src/ip/vtm/src_files_vtm.mk
-include src/ip/fss/src_files_fss.mk

