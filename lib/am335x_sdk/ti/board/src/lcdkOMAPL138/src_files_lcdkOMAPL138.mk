
SRCDIR +=   src/lcdkOMAPL138 src/lcdkOMAPL138/include \
            $(PDK_INSTALL_PATH)/ti/csl
INCDIR +=   src/lcdkOMAPL137 src/lcdkOMAPL138/include \
            $(PDK_INSTALL_PATH)/ti/csl

# Common source files across all platforms and cores
SRCS_COMMON += lcdkOMAPL138.c lcdkOMAPL138_pinmux.c lcdkOMAPL138_clock.c lcdkOMAPL138_ddr.c lcdkOMAPL138_pll.c lcdkOMAPL138_lld_init.c

PACKAGE_SRCS_COMMON =   src/lcdkOMAPL138/src_files_lcdkOMAPL138.mk
