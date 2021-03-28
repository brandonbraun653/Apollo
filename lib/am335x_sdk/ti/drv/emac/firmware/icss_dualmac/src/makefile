#
#  TEXAS INSTRUMENTS TEXT FILE LICENSE
#
#   Copyright (c) 2018-2019 Texas Instruments Incorporated
#
#  All rights reserved not granted herein.
#
#  Limited License.
#
#  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
#  license under copyrights and patents it now or hereafter owns or controls to
#  make, have made, use, import, offer to sell and sell ("Utilize") this software
#  subject to the terms herein.  With respect to the foregoing patent license,
#  such license is granted  solely to the extent that any such patent is necessary
#  to Utilize the software alone.  The patent license shall not apply to any
#  combinations which include this software, other than combinations with devices
#  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
#
#  Redistributions must preserve existing copyright notices and reproduce this license
#  (including the above copyright notice and the disclaimer and (if applicable) source
#  code license limitations below) in the documentation and/or other materials provided
#  with the distribution.
#
#  Redistribution and use in binary form, without modification, are permitted provided
#  that the following conditions are met:
# 	No reverse engineering, decompilation, or disassembly of this software is
#   permitted with respect to any software provided in binary form.
# 	Any redistribution and use are licensed by TI for use only with TI Devices.
# 	Nothing shall obligate TI to provide you with source code for the software
#   licensed and provided to you in object code.
#
#  If software source code is provided to you, modification and redistribution of the
#  source code are permitted provided that the following conditions are met:
# 	Any redistribution and use of the source code, including any resulting derivative
#   works, are licensed by TI for use only with TI Devices.
# 	Any redistribution and use of any object code compiled from the source code
#   and any resulting derivative works, are licensed by TI for use only with TI Devices.
#
#  Neither the name of Texas Instruments Incorporated nor the names of its suppliers
#  may be used to endorse or promote products derived from this software without
#  specific prior written permission.
#
#  DISCLAIMER.
#
#  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
#  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
#  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S
#  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
#  GOODS OR SERVICES# LOSS OF USE, DATA, OR PROFITS# OR BUSINESS INTERRUPTION) HOWEVER
#  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#------------------------
#make pru&rtu f/w
#  flags:
#  -DSLICE0,SLICE1 -> tell f/w which slice he is
#  -DSWITCH  -> for switch mode
#  -DMAC     -> for macA
#  -DWAIT_FOR_DEBUGGER -> f.w will wait for debugger to attach and poke r11 to continue
#  -DPSA - IET scheduler and reciever
#  -DPSILOOP  - f/w will loop packets received from host back to host via psi
#  -DFORCEALL  - (switch only) must be defined to use helper functions on rtu
#  -DNO_CLASS -> disable classifier use for pkt->flow mapping
#  -DDO_PSI_ABORT  (define to enable psi abort sequence on bad pkts. this requires
#               rx free ring to be in message mode!.  if not define, bad pkts
#               will be delivered to host with word 3 of protocol specific area 
#               set to 0xBAD0)
#-----------------------
include $(RULES_MAKE)

CLPRU = $(CL_PRU_INSTALL_PATH)/bin/clpru
HEXPRU = $(CL_PRU_INSTALL_PATH)/bin/hexpru
WIN_BIN = $(SDK_INSTALL_PATH)/pdk_$(PDK_SOC)_$(PDK_VERSION)/packages/ti/drv/emac/firmware/icss_dualmac/bin

all:
	$(MAKE) mkversion
  ifeq ($(OS),Windows_NT)
	$(MAKE) BLDT=$(WIN_BIN) all_bins
  else
	$(MAKE) BLDT="../bin" all_bins
  endif

all_bins: $(BLDT)/rxl2_txl2_rgmii0_bin.h $(BLDT)/rxl2_txl2_rgmii1_bin.h \
		$(BLDT)/rtu_test0_bin.h $(BLDT)/rtu_test1_bin.h

CL_FLAGS = --endian=little \
	   -v4 \
	   -g \
	   --diag_wrap=off \
	   --diag_warning=225 \
	   --display_error_number \
	   --hardware_mac=on \
           --code_address_listing_unit=word \

FLAGS = -al \
	--preproc_with_compile \
	-eo.opru \

EF_PRU0 = -DMAC  -DSLICE0 -DPRU0
EF_PRU1 = -DMAC  -DSLICE1 -DPRU1
EF_RTU0 = -DMAC  -DSLICE0 -DRTU0 -DDO_PSI_ABORT
EF_RTU1 = -DMAC  -DSLICE1 -DRTU1 -DDO_PSI_ABORT

APP_DEFS = --define=RGMII \
	   -z \
	   --stack_size=0 \
	   --heap_size=0 \
	   --reread_libs \
	   --warn_sections

PRUS = rxl2_txl2
PRU0 = $(PRUS)_rgmii0
PRU1 = $(PRUS)_rgmii1
RTU = rtu
RTUS = rtu_v2
RTU0 = rtu_test0
RTU1 = rtu_test1

.PHONY: mkversion

mkversion:
  ifeq ($(OS),Windows_NT)
#		@echo ;there is no version scring when building from Windows > version_file.h
  else
	./makeversion.sh
  endif

$(BLDT)/$(PRU0)_bin.h: $(PRUS).asm pru.cmd
	mkdir -p $(BLDT)/$(PRU0)
	$(CLPRU) $(CL_FLAGS) $(FLAGS) \
		-DRGMII $(EF_PRU0) -fr=$(BLDT)/$(PRU0) \
		-fs=$(BLDT)/$(PRU0) --preproc_dependency="$(PRUS).d" $(PRUS).asm
	$(CLPRU) $(CL_FLAGS) $(APP_DEFS) \
		--entry_point=Start $(BLDT)/$(PRU0)/$(PRUS).opru pru.cmd \
		-o $(BLDT)/$(PRU0)/$(PRUS).out -m $(BLDT)/$(PRU0)/$(PRUS).map \
		--xml_link_info="$(BLDT)/$(PRU0)/$(PRUS)_linkInfo.xml"
	$(HEXPRU) --array --array:name_prefix=PDSPcode --array:page0_type_size=32 \
					      --exclude=.resource_table \
					      $(BLDT)/$(PRU0)/$(PRUS).out -o $(BLDT)/$(PRU0)_bin.h

$(BLDT)/$(PRU1)_bin.h: $(PRUS).asm pru.cmd
	mkdir -p $(BLDT)/$(PRU1)
	$(CLPRU) $(CL_FLAGS) $(FLAGS) \
		-DRGMII $(EF_PRU1) -fr=$(BLDT)/$(PRU1) \
		-fs=$(BLDT)/$(PRU1) --preproc_dependency="$(PRUS).d" $(PRUS).asm
	$(CLPRU) $(CL_FLAGS) $(APP_DEFS) \
		--entry_point=Start $(BLDT)/$(PRU1)/$(PRUS).opru pru.cmd \
		-o $(BLDT)/$(PRU1)/$(PRUS).out -m $(BLDT)/$(PRU1)/$(PRUS).map \
		--xml_link_info="$(BLDT)/$(PRU1)/$(PRUS)_linkInfo.xml"
	$(HEXPRU) --array --array:name_prefix=PDSP3code --array:page0_type_size=32 \
					      --exclude=.resource_table \
					      $(BLDT)/$(PRU1)/$(PRUS).out -o $(BLDT)/$(PRU1)_bin.h

$(BLDT)/$(RTU0)_bin.h: $(RTUS).asm pru.cmd
	mkdir -p $(BLDT)/$(RTU0)
	$(CLPRU) $(CL_FLAGS) $(FLAGS) \
		-ss \
		-DRGMII $(EF_RTU0) -fr=$(BLDT)/$(RTU0) \
		-fs=$(BLDT)/$(RTU0) --preproc_dependency="$(RTUS).d" $(RTUS).asm
	$(CLPRU) $(CL_FLAGS) $(APP_DEFS) \
		--entry_point=Start $(BLDT)/$(RTU0)/$(RTUS).opru pru.cmd \
		-o $(BLDT)/$(RTU0)/$(RTUS).out -m $(BLDT)/$(RTU0)/$(RTUS).map \
		--xml_link_info="$(BLDT)/$(RTU0)/$(RTUS)_linkInfo.xml"
	$(HEXPRU) --array --array:name_prefix=PDSP2code --array:page0_type_size=32 \
					      --exclude=.resource_table \
					      $(BLDT)/$(RTU0)/$(RTUS).out -o $(BLDT)/$(RTU0)_bin.h

$(BLDT)/$(RTU1)_bin.h: $(RTUS).asm pru.cmd
	mkdir -p $(BLDT)/$(RTU1)
	$(CLPRU) $(CL_FLAGS) $(FLAGS) \
		-ss \
		-DRGMII $(EF_RTU1) -fr=$(BLDT)/$(RTU1) \
		-fs=$(BLDT)/$(RTU1) --preproc_dependency="$(RTUS).d" $(RTUS).asm
	$(CLPRU) $(CL_FLAGS) $(APP_DEFS) \
		--entry_point=Start $(BLDT)/$(RTU1)/$(RTUS).opru pru.cmd \
		-o $(BLDT)/$(RTU1)/$(RTUS).out -m $(BLDT)/$(RTU1)/$(RTUS).map \
		--xml_link_info="$(BLDT)/$(RTU1)/$(RTUS)_linkInfo.xml"
	$(HEXPRU) --array --array:name_prefix=PDSP4code --array:page0_type_size=32 \
					      --exclude=.resource_table \
					      $(BLDT)/$(RTU1)/$(RTUS).out -o $(BLDT)/$(RTU1)_bin.h

clean:  
ifeq ($(OS),Windows_NT)
	cmd /c "rmdir /Q /S ..\bin"
else
	rm -rf ../bin
endif
