
SRCDIR = . src
INCDIR = . src

ifeq ($(CORE),$(filter $(CORE), c66x ipu1_0))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 

# Common source files across all platforms and cores
SRCS_COMMON += nimu_icssEth.c nimu_icssEthDriver.c nimu_icssSwitchEmac.c

PACKAGE_SRCS_COMMON = makefile nimu_icss_component.mk \
                      nimu_icssEth.h nimu_icssIoctl.h src/ \
                      src/nimu_icssEthDriver.h src/nimu_icssSwitchEmac.h \
                      build/makefile_indp.mk build/makefile_profile_indp.mk src/src_files_common.mk

