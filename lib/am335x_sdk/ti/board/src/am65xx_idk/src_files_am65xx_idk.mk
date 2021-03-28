
SRCDIR += src/am65xx_idk src/am65xx_idk/include
INCDIR += src/am65xx_idk src/am65xx_idk/include

# Common source files across all platforms and cores
SRCS_COMMON += am65xx_idk.c am65xx_idk_pinmux.c AM65xx_pinmux_data.c am65xx_idk_pll.c am65xx_idk_clock.c am65xx_idk_ethernet_config.c am65xx_idk_info.c am65xx_idk_serdes_cfg.c

PACKAGE_SRCS_COMMON =   src/am65xx_idk/src_files_am65xx_idk.mk
