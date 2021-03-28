
SRCDIR += src/j721e_evm src/j721e_evm/include
INCDIR += src/j721e_evm src/j721e_evm/include

# Common source files across all platforms and cores
SRCS_COMMON += board_init.c board_lld_init.c board_clock.c board_mmr.c board_pll.c board_serdes_cfg.c
SRCS_COMMON += board_ddr.c board_info.c board_ethernet_config.c board_i2c_io_exp.c board_utils.c board_control.c board_power.c
SRCS_COMMON += board_pinmux.c J721E_pinmux_data.c J721E_pinmux_data_info.c J721E_pinmux_data_gesi.c J721E_pinmux_data_gesi_cpsw9g.c
SRCS_COMMON += board_ddrtempmonitor.c
PACKAGE_SRCS_COMMON = src/j721e_evm/src_files_j721e_evm.mk
