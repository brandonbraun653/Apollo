
SRCDIR += src/evmKeystone src/evmKeystone/include
INCDIR += src/evmKeystone src/evmKeystone/include

# Common source files across all platforms and cores
SRCS_COMMON += board_clock.c board_lld_init.c board_pll.c board_utils.c


PACKAGE_SRCS_COMMON =   src/evmKeystone/src_files_evmKeystone.mk
