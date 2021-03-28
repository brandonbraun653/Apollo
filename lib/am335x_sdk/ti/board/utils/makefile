# Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

BUILD_UTILS = $(foreach a,$($(btests)),$(a)_build)
CLEAN_UTILS = $(foreach a,$(ALL_BOARDS),$(a)_clean)
CLEAN_APPS = $(foreach a,$($(ctests)),$(a)_clean)
ALL_BOARDS = $(LIMIT_BOARDS)

evmAM335x_UTILS = uartAppLoader uniflash/target
icev2AM335x_UTILS = uartAppLoader uniflash/target
iceAMIC110_UTILS = uartAppLoader uniflash/target
evmAM437x_UTILS = uartAppLoader
idkAM437x_UTILS = uartAppLoader uniflash/target
idkAM571x_UTILS = uartAppLoader uniflash/target
idkAM572x_UTILS = uartAppLoader  uniflash/target
evmAM572x_UTILS = uartAppLoader
idkAM574x_UTILS = uartAppLoader uniflash/target
evmK2G_UTILS = uartAppLoader uniflash/target
iceK2G_UTILS = uartAppLoader uniflash/target
am65xx_evm_UTILS = uniflash/target
am65xx_idk_UTILS = uniflash/target
evmOMAPL137_UTILS = uartAppLoader
lcdkOMAPL138_UTILS = uartAppLoader

.PHONY: $(ALL_BOARDS) $(BUILD_UTILS)

all: $(ALL_BOARDS)

$(ALL_BOARDS):
	$(MAKE) buildutils bboard=$@ btests=$@_UTILS

buildutils: $(BUILD_UTILS)

$(BUILD_UTILS):
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard)

clean: $(CLEAN_UTILS)

$(CLEAN_UTILS):
	$(MAKE) cleanutils cboard=$(subst _clean,,$@) ctests=$(subst _clean,_UTILS,$@)

cleanutils: $(CLEAN_APPS)

$(CLEAN_APPS):
	-$(MAKE) -C $(subst _clean,,$@) BOARD=$(cboard) clean
