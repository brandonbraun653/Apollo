
SRCDIR +=   src/evmOMAPL137 src/evmOMAPL137/include \
            $(PDK_INSTALL_PATH)/ti/csl
INCDIR +=   src/evmOMAPL137 src/evmOMAPL137/include \
            $(PDK_INSTALL_PATH)/ti/csl

# Common source files across all platforms and cores
SRCS_COMMON += evmOMAPL137.c evmOMAPL137_pinmux.c evmOMAPL137_clock.c evmOMAPL137_ddr.c evmOMAPL137_pll.c evmOMAPL137_lld_init.c evmOMAPL137_ethernet_config.c

PACKAGE_SRCS_COMMON =   src/evmOMAPL137/src_files_evmOMAPL137.mk
