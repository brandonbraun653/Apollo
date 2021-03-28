
SRCDIR += src/bbbAM335x src/bbbAM335x/device src/bbbAM335x/include
INCDIR += src/bbbAM335x src/bbbAM335x/device src/bbbAM335x/include

# Common source files across all platforms and cores
SRCS_COMMON += bbbAM335x.c bbbAM335x_info.c bbbAM335x_lld_init.c bbbAM335x_pinmux.c enet_phy.c

PACKAGE_SRCS_COMMON =   src/bbbAM335x/src_files_bbbAM335x.mk
