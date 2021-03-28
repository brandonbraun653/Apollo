
SRCDIR += src/evmK2L src/evmK2L/include
INCDIR += src/evmK2L src/evmK2L/include

# Common source files across all platforms and cores
SRCS_COMMON += evmK2L.c evmK2L_pinmux.c evmK2L_clock.c evmK2L_ddr.c evmK2L_pll.c

PACKAGE_SRCS_COMMON =   src/evmK2L/src_files_evmK2L.mk
