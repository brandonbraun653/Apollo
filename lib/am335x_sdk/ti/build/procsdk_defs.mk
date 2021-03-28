
#Definitions pertaining to PDK when built from Processor SDK.
# Processor SDK defines "PDK_SOC" which is the SOC name used in the processor sdk installer.
# Many SOCs can be included in the processor sdk installer and the pdk directory takes the form "pdk_<PDK_SOC>_<version>
# For example, pdk_am57xx_x_x_x holds am571x,am572x,am574x. The PDK_SOC here is "am57xx"
# In this file, the make variables below are derived from PDK_SOC

include $(PDK_INSTALL_PATH)/ti/build/soc_info.mk

# Below are the supported PDK_SOCs in Processor SDK
export PROCSDK_SUPPORTED_PDK_SOCS = am335x am437x am437x-hs am57xx omapl137 omapl138 k2hk k2e k2l k2g k2g-hs c665x c667x am65xx am65xx-hs j7 tpr12

#if PDK_SOC is specified , derive LIMIT_SOCS/LIMIT_BOARDS/LIMIT_CORES from it (if not specified explicitly)
ifneq ($(PDK_SOC),)
#Check if PDK_SOC exists within the supported SOCs 
ifeq ($(PDK_SOC),$(filter $(PDK_SOC), $(PROCSDK_SUPPORTED_PDK_SOCS)))

LIMIT_CORES_am335x    = $(CORE_LIST_am335x)
LIMIT_CORES_am437x    = $(CORE_LIST_am437x)
LIMIT_CORES_am437x-hs = $(CORE_LIST_am437x)
# Filter out arp32_1 as Processor SDK does not build it
LIMIT_CORES_am57xx    = $(filter-out arp32_1,$(sort $(CORE_LIST_am571x) $(CORE_LIST_am572x) $(CORE_LIST_am574x)))
LIMIT_CORES_omapl137  = $(CORE_LIST_omapl137)
LIMIT_CORES_omapl138  = $(CORE_LIST_omapl138)
LIMIT_CORES_k2hk      = $(sort $(CORE_LIST_k2h) $(CORE_LIST_k2k))
LIMIT_CORES_k2e       = $(CORE_LIST_k2e)
LIMIT_CORES_k2l       = $(CORE_LIST_k2l)
LIMIT_CORES_k2g       = $(CORE_LIST_k2g)
LIMIT_CORES_k2g-hs    = $(CORE_LIST_k2g)
LIMIT_CORES_c665x     = $(CORE_LIST_c6657)
LIMIT_CORES_c667x     = $(CORE_LIST_c6678)
LIMIT_CORES_am65xx    = $(CORE_LIST_am65xx)
LIMIT_CORES_am65xx-hs = $(CORE_LIST_am65xx)
LIMIT_CORES_tpr12     = $(CORE_LIST_tpr12)
# Filter out c7x-hostemu as Processor SDK does not build use it
LIMIT_CORES_j7        = $(filter-out c7x-hostemu,$(sort $(CORE_LIST_j721e) $(CORE_LIST_j7200)))

export LIMIT_CORES ?= $(LIMIT_CORES_$(PDK_SOC))

LIMIT_SOCS_k2g       = k2g
LIMIT_SOCS_k2g-hs    = k2g
LIMIT_SOCS_k2hk      = k2hk
LIMIT_SOCS_k2e       = k2e
LIMIT_SOCS_k2l       = k2l
LIMIT_SOCS_c665x     = c6657
LIMIT_SOCS_c667x     = c6678
LIMIT_SOCS_am57xx    = am571x am572x am574x
LIMIT_SOCS_am437x    = am437x
LIMIT_SOCS_am437x-hs = am437x
LIMIT_SOCS_am335x    = am335x
LIMIT_SOCS_am65xx    = am65xx
LIMIT_SOCS_am65xx-hs = am65xx
LIMIT_SOCS_j7        = j721e j7200
LIMIT_SOCS_tpr12     = tpr12
LIMIT_SOCS_omapl137  = omapl137
LIMIT_SOCS_omapl138  = omapl138

export LIMIT_SOCS ?= $(LIMIT_SOCS_$(PDK_SOC))

ifeq ($(findstring hs,$(PDK_SOC)),hs)
export BUILD_HS ?= yes
endif

LIMIT_BOARDS_j7        = $(BOARD_LIST_j721e) $(BOARD_LIST_j7200)
LIMIT_BOARDS_am335x    = $(BOARD_LIST_am335x)
LIMIT_BOARDS_omapl137  = $(BOARD_LIST_omapl137)
LIMIT_BOARDS_k2l       = $(BOARD_LIST_k2l)
LIMIT_BOARDS_am437x    = $(BOARD_LIST_am437x)
LIMIT_BOARDS_am437x-hs = $(BOARD_LIST_am437x)
LIMIT_BOARDS_k2hk      = $(BOARD_LIST_k2h) $(BOARD_LIST_k2k)
LIMIT_BOARDS_k2g       = $(BOARD_LIST_k2g)
LIMIT_BOARDS_k2g-hs    = $(BOARD_LIST_k2g)
LIMIT_BOARDS_k2e       = $(BOARD_LIST_k2e)
LIMIT_BOARDS_am65xx    = $(BOARD_LIST_am65xx)
LIMIT_BOARDS_am65xx-hs = $(BOARD_LIST_am65xx)
LIMIT_BOARDS_c665x     = $(BOARD_LIST_c6657)
LIMIT_BOARDS_c667x     = $(BOARD_LIST_c6678)
LIMIT_BOARDS_omapl138  = $(BOARD_LIST_omapl138)
LIMIT_BOARDS_am57xx    = $(BOARD_LIST_am571x) $(BOARD_LIST_am572x) $(BOARD_LIST_am574x)
LIMIT_BOARDS_tpr12     = $(BOARD_LIST_tpr12)

export LIMIT_BOARDS ?= $(LIMIT_BOARDS_$(PDK_SOC))

endif
endif
