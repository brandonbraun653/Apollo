
SRCDIR += src/iceAMIC110 src/iceAMIC110/include
INCDIR += src/iceAMIC110 src/iceAMIC110/include

# Common source files across all platforms and cores
SRCS_COMMON += iceAMIC110.c iceAMIC110_info.c iceAMIC110_lld_init.c iceAMIC110_ethernet_config.c iceAMIC110_pinmux.c

PACKAGE_SRCS_COMMON =   src/iceAMIC110/src_files_iceAMIC110.mk
