
SRCDIR +=   src/iceK2G src/iceK2G/include \
            $(PDK_INSTALL_PATH)/ti/csl
INCDIR +=   src/iceK2G src/iceK2G/include \
            $(PDK_INSTALL_PATH)/ti/csl

# Common source files across all platforms and cores
SRCS_COMMON += iceK2G.c iceK2G_pinmux.c iceK2G_clock.c iceK2G_ddr.c iceK2G_pll.c iceK2G_info.c iceK2G_ethernet_config.c 66AK2G0x_pinmux_data.c


PACKAGE_SRCS_COMMON =   src/iceK2G/src_files_iceK2G.mk
