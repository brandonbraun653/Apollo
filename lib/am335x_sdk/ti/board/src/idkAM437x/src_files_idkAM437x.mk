
SRCDIR += src/idkAM437x src/idkAM437x/device src/idkAM437x/include
INCDIR += src/idkAM437x src/idkAM437x/device src/idkAM437x/include

# Common source files across all platforms and cores
SRCS_COMMON += idkAM437x.c idkAM437x_info.c idkAM437x_lld_init.c idkAM437x_pinmux.c enet_phy.c qspi_flash.c idkAM437x_ethernet_config.c

PACKAGE_SRCS_COMMON =   src/idkAM437x/src_files_idkAM437x.mk
