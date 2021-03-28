SRCDIR += src src/v4
INCDIR += src src/v4

ifeq ($(CORE),$(filter $(CORE), c66x ipu1_0))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 

# Common source files across all platforms and cores
SRCS_COMMON += cpsw_nimu_eth.c

PACKAGE_SRCS_COMMON += src/v4/ src/v4/nimu_eth.h src/v4/nimu_eth.c
