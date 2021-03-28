
SRCDIR += src/evmAM437x src/evmAM437x/device src/evmAM437x/include
INCDIR += src/evmAM437x src/evmAM437x/device src/evmAM437x/include

# Common source files across all platforms and cores
SRCS_COMMON += evmAM437x.c evmAM437x_info.c evmAM437x_lld_init.c evmAM437x_pinmux.c enet_phy.c

PACKAGE_SRCS_COMMON =   src/evmAM437x/src_files_evmAM437x.mk
