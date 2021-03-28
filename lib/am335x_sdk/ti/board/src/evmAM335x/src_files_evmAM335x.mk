
SRCDIR += src/evmAM335x src/evmAM335x/device src/evmAM335x/include
INCDIR += src/evmAM335x src/evmAM335x/device src/evmAM335x/include

# Common source files across all platforms and cores
SRCS_COMMON += evmAM335x.c evmAM335x_info.c evmAM335x_lld_init.c evmAM335x_pinmux.c enet_phy.c

PACKAGE_SRCS_COMMON =   src/evmAM335x/src_files_evmAM335x.mk
