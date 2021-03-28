
SRCDIR += src/am65xx_evm src/am65xx_evm/include
INCDIR += src/am65xx_evm src/am65xx_evm/include

# Common source files across all platforms and cores
SRCS_COMMON += am65xx_evm.c am65xx_evm_pinmux.c AM65xx_pinmux_data.c am65xx_evm_pll.c am65xx_evm_clock.c am65xx_evm_ethernet_config.c am65xx_evm_info.c am65xx_evm_serdes_cfg.c

PACKAGE_SRCS_COMMON =   src/am65xx_evm/src_files_am65xx_evm.mk
