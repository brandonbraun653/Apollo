
SRCDIR += src/skAM335x src/skAM335x/device src/skAM335x/include
INCDIR += src/skAM335x src/skAM335x/device src/skAM335x/include

# Common source files across all platforms and cores
SRCS_COMMON += skAM335x.c skAM335x_info.c skAM335x_lld_init.c skAM335x_pinmux.c enet_phy.c

PACKAGE_SRCS_COMMON =   src/skAM335x/src_files_skAM335x.mk
