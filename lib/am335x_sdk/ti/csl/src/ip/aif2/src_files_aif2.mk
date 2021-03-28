
ifeq ($(SOC),$(filter $(SOC), k2h k2k))
PACKAGE_SRCS_COMMON += csl_aif2.h  cslr_aif2.h 
PACKAGE_SRCS_COMMON += src/ip/aif2/V0/csl_aif2GetHwStatusAux.h  src/ip/aif2/V0/csl_aif2.h  
PACKAGE_SRCS_COMMON += src/ip/aif2/V0/csl_aif2HwControlAux.h  src/ip/aif2/V0/csl_aif2HwSetupAux.h 
PACKAGE_SRCS_COMMON += src/ip/aif2/V0/csl_aif2.h src/ip/aif2/V0/csl_gpio.h 
PACKAGE_SRCS_COMMON += src/ip/aif2/src_files_aif2.mk src/ip/aif2/V0
SRCS_COMMON += csl_aif2Close.c  csl_aif2GetHwStatus.c  csl_aif2HwControl.c  csl_aif2HwSetup.c  
SRCS_COMMON += csl_aif2Init.c  csl_aif2Open.c  csl_aif2Reset.c
SRCDIR += src/ip/aif2/V0
INCDIR += . src/ip/aif2/V0
endif
