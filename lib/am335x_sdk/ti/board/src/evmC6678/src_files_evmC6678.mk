
SRCDIR += src/evmC6678 src/evmC6678/include
INCDIR += src/evmC6678 src/evmC6678/include

# Common source files across all platforms and cores
SRCS_COMMON += evmC6678.c evmC6678_clock.c evmC6678_ddr.c evmC6678_pll.c evmC6678_ecc.c evmC6678_phy.c

PACKAGE_SRCS_COMMON =   src/evmC6678/src_files_evmC6678.mk
