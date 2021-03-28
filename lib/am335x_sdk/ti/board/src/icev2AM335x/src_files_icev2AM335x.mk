
SRCDIR += src/icev2AM335x src/icev2AM335x/device src/icev2AM335x/include
INCDIR += src/icev2AM335x src/icev2AM335x/device src/icev2AM335x/include

# Common source files across all platforms and cores
SRCS_COMMON += icev2AM335x.c icev2AM335x_info.c icev2AM335x_lld_init.c icev2AM335x_ethernet_config.c icev2AM335x_pinmux.c enet_phy.c

PACKAGE_SRCS_COMMON =   src/icev2AM335x/src_files_icev2AM335x.mk
