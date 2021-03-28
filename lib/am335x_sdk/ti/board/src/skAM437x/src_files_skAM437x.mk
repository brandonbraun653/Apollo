
SRCDIR += src/skAM437x src/skAM437x/device src/skAM437x/include
INCDIR += src/skAM437x src/skAM437x/device src/skAM437x/include

# Common source files across all platforms and cores
SRCS_COMMON += skAM437x.c skAM437x_info.c skAM437x_lld_init.c skAM437x_pinmux.c enet_phy.c

PACKAGE_SRCS_COMMON =   src/skAM437x/src_files_skAM437x.mk
