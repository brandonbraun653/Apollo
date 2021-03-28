ifeq ($(SOC),$(filter $(SOC), c6657 omapl137 omapl138))
SRCDIR = . src src/v0
INCDIR = . src src/v0
SRCS_COMMON += emac.c emac_drv.c emac_drv_v0.c mdio.c sgmii.c
PACKAGE_SRCS_COMMON += src/v0 soc/emac_soc_v0.h
endif

ifeq ($(SOC),$(filter $(SOC), k2g))
SRCDIR = . src src/v1
INCDIR = . src src/v1
SRCS_COMMON += emac_cppi_qmss_iface.c emac_cpsw.c emac_drv.c emac_drv_v1.c mdio.c
PACKAGE_SRCS_COMMON += src/v1 soc/emac_soc_v1.h
endif

ifeq ($(SOC),$(filter $(SOC), am574x am572x am571x am437x am335x dra72x dra75x dra78x))
SRCDIR = . src src/v4
INCDIR = . src src/v4
SRCS_COMMON += emac_cpsw.c emac_drv.c emac_drv_v4.c
PACKAGE_SRCS_COMMON += src/v4 soc/emac_soc_v4.h
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
SRCDIR = . src src/v5
INCDIR = . src src/v5
  SRCS_COMMON += emac_drv.c emac_drv_v5.c emac_mdio.c emac_ioctl.c emac_utils.c
PACKAGE_SRCS_COMMON += src/v5 soc/emac_soc_v5.h
endif

PACKAGE_SRCS_COMMON += makefile emac_component.mk nss_if.h \
                      emac_hwcfg.h emac_drv.h emac_ioctl.h emacver.h \
                      src/emac_osal.h \
                      build/makefile.mk \
		      build/makefile_indp.mk \
		      build/makefile_profile_indp.mk \
		      build/makefile_profile.mk \
		      src/src_files_common.mk

#Packaging the firmware
PACKAGE_SRCS_COMMON += firmware/Module.xs \
                        firmware/icss_dualmac \
                        firmware/icss_switch
