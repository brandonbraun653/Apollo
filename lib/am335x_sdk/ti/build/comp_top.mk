#  ============================================================================
#  (C) Copyright 2016-2019 Texas Instruments, Inc.
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
#
#  ============================================================================

# This file is included by components to build libraries/examples from within a component
# This file eventually invokes ti/build/makefile with the correct SOC,CORE,BOARD combination


# This is to serialize the targets per every element in LIMIT_SOCS,LIMIT_BOARDS,LIMIT_CORES combination
# However, the parallelism (-j) is supported as it is passed on to ti/build/makefile with a SOC,CORE,BOARD combination
.NOT_PARALLEL:


include $(PDK_INSTALL_PATH)/ti/build/Rules.make

# Targets which are BOARD,CORE,SOC specific
# NOTE: Do not change the order as 'all' needs to be run first if target is unspecified

TARGETS_FOR_MULT_SOC_BOARDS = all 
TARGETS_FOR_MULT_SOC_BOARDS += apps clean lib app_libs firm

# BOARD,CORE,SOC independent targets
TARGETS_SOC_BOARD_INDP      = tar help doxygen xdc_meta

.PHONY : $(TARGETS_FOR_MULT_SOC_BOARDS) $(TARGETS_SOC_BOARD_INDP) release package

# If LIMIT_SOCS is undefined, use the default component's SOC LIST defined in <comp>_component.mk
ifdef LIMIT_SOCS
  SOC_LIST_ALL = $(LIMIT_SOCS)
else
  SOC_LIST_ALL = $($(COMP)_SOCLIST)
endif

# If LIMIT_CORES is undefined, use the default component's _CORELIST defined in <comp>_component.mk
ifdef LIMIT_CORES
  CORE_LIST_ALL = $(LIMIT_CORES)
else
  CORE_LIST_ALL = $(foreach SOC,$(SOC_LIST_ALL),$($(COMP)_$(SOC)_CORELIST))
endif

# If LIMIT_BOARDS is undefined, use the default BOARDLIST defined in platform.mk
ifdef LIMIT_BOARDS
  BOARD_LIST_ALL = $(LIMIT_BOARDS)
else
  BOARD_LIST_ALL = $(foreach SOC,$(SOC_LIST_ALL),$(BOARD_LIST_$(SOC)))
endif

# Invoke the ti/build/makefile with {BOARD,CORE,SOC} and COMP name
# For each SOC, build the BOARD,CORE combination for each relevant BOARD,SOC for that SOC
$(TARGETS_FOR_MULT_SOC_BOARDS):
	$(foreach current_soc, $(SOC_LIST_ALL),\
	$(foreach current_board, $(filter $(BOARD_LIST_ALL),$(BOARD_LIST_$(current_soc))), \
	$(foreach current_core, $(filter $(CORE_LIST_ALL), $(filter-out $(PRUCORE_LIST),$(CORE_LIST_$(current_soc)))),\
	$(MAKE) -f $(PDK_INSTALL_PATH)/ti/build/makefile $@ COMP=$(COMP) CORE=$(current_core) BOARD=$(current_board) SOC=$(current_soc);\
	)))

package:
	$(foreach current_board, $(BOARD),\
	$(MAKE) -f $(PDK_INSTALL_PATH)/ti/build/makefile $@ COMP=$(COMP) BOARD=$(current_board);\
	)

release: lib firm tar 

%_var_display:
	$(ECHO) " $(subst _var_display,,$@) is $($(subst _var_display,,$@))"
	
# Invoke the ti/build/makefile with COMP name
$(TARGETS_SOC_BOARD_INDP):
	$(MAKE) -f $(PDK_INSTALL_PATH)/ti/build/makefile $@ COMP=$(COMP) DOXYGEN_SUPPORT=$($(COMP)_DOXYGEN_SUPPORT)

# nothing beyond this point
