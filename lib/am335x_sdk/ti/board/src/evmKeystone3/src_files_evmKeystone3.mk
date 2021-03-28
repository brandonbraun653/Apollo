
SRCDIR += src/evmKeystone3 src/evmKeystone3/include
INCDIR += src/evmKeystone3 src/evmKeystone3/include

# Common source files across all platforms and cores
SRCS_COMMON += board_pll.c board_lld_init.c board_i2c_io_exp.c board_detect.c board_mmr.c board_ddr.c board_ethernet_config.c board_clock.c


PACKAGE_SRCS_COMMON =   src/evmKeystone3/src_files_evmKeystone3.mk
