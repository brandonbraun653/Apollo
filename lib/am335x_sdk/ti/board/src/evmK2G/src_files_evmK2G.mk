
SRCDIR +=   src/evmK2G src/evmK2G/include \
            $(PDK_INSTALL_PATH)/ti/csl
INCDIR +=   src/evmK2G src/evmK2G/include \
            $(PDK_INSTALL_PATH)/ti/csl

# Common source files across all platforms and cores
SRCS_COMMON += evmK2G.c evmK2G_pinmux.c evmK2G_clock.c evmK2G_ddr.c evmK2G_pll.c evmK2G_info.c 66AK2G0x_pinmux_data.c


PACKAGE_SRCS_COMMON =   src/evmK2G/src_files_evmK2G.mk
