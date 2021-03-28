SOC_DEP_LIB_SOCS=k2h k2hk k2l k2e k2g c6678 c6657 omapl137 omapl138 am65xx j721e am77x j7200

# Common source files across all platforms and cores
ifeq ($(SOC),$(filter $(SOC),$(SOC_DEP_LIB_SOCS) ))
   SRCDIR = . src src/v0
   INCDIR = . src src/v0
   SRCS_COMMON += GPIO_drv.c GPIO_v0.c
else
   SRCDIR = . src src/v1 src/v0
   INCDIR = . src src/v1 src/v0
   SRCS_COMMON += GPIO_drv.c GPIO_v0.c GPIO_v1.c
endif

PACKAGE_SRCS_COMMON = makefile GPIO.h gpio_component.mk src/GPIO_osal.h \
              docs/ReleaseNotes_GPIO_LLD.pdf \
              src/GPIO_drv.c src/GPIO_drv_log.h \
			  soc/GPIO_v1.h \
	 	      build/makefile_profile_indp.mk \
	 	      build/makefile_indp.mk \
	 	      build/makefile_profile.mk \
	 	      build/makefile.mk \
	 	      src/src_files_common.mk

ifeq ($(SOC),$(filter $(SOC),$(SOC_DEP_LIB_SOCS) ))
PACKAGE_SRCS_COMMON += src/v0 src/v0/GPIO_v0.h src/v0/GPIO_v0.c test
else
PACKAGE_SRCS_COMMON += src/v0 src/v0/GPIO_v0.h src/v0/GPIO_v0.c \
	 	      src/v1 src/v1/GPIO_v1.h src/v1/GPIO_v1.c test
endif
			  

