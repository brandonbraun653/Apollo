
SRCDIR += src/$(BOARD) src/evmAM572x/device
INCDIR += src/$(BOARD) src/$(BOARD)/include src/evmAM572x/device

# Common source files across all platforms and cores
SRCS_COMMON += $(BOARD).c
SRCS_COMMON += enet_phy.c 

CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)

PACKAGE_SRCS_COMMON =   src/$(BOARD)/src_files_$(BOARD).mk
