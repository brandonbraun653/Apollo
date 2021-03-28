
SRCDIR = . src
INCDIR = . src
# Common source files across all platforms and cores
SRCS_COMMON += pruicss_drv.c pruicss_intc.c

PACKAGE_SRCS_COMMON = makefile pruicss.h pruss_component.mk src include \
                      docs \
                      soc/pruicss_v1.h soc/pruicss_soc.h soc/${SOC} \
                      build

