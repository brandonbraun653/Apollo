################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./pruss_test_pru0.obj" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include bin2header/subdir_vars.mk
-include subdir_rules.mk
-include bin2header/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
pru_firmware.out \

EXE_OUTPUTS__QUOTED += \
"pru_firmware.out" \

BIN_OUTPUTS += \
pru_firmware.hex \

BIN_OUTPUTS__QUOTED += \
"pru_firmware.hex" \


# All Target
all: pru_firmware.out

# Tool invocations
pru_firmware.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: PRU Linker'
	"c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0/bin/clpru" -v3 -g --define=am4379 --define=icss0 --define=pru1 --diag_warning=225 --display_error_number --diag_wrap=off --endian=little --asm_listing --asm_define=PRU1 --asm_define=MAG_ADC_ENABLE --asm_define=ADC_SIMULTANEOUS_SAMPLING --asm_define=MINIMAL_ADC_CONFIG -z -m"pru_firmware.map" --heap_size=0 --stack_size=0 -i"c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0/lib" -i"c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0/include" --reread_libs --warn_sections --xml_link_info="pru_firmware_linkInfo.xml" -o "pru_firmware.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

pru_firmware.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: PRU Hex Utility'
	"c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0/bin/hexpru"  -o "pru_firmware.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "pruss_test_pru0.obj" 
	-$(RM) "pruss_test_pru0.pp" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0\bin\hexpru.exe ..\pru_adc_hexpru.cmd pru_firmware.out
	-C:/ti/pdk_keystone2_3_01_00_03/packages\ti\drv\pruss\test\src\pru_firmware\firmware\bin2header\bin2header.exe pru_firmware.b00 pru_firmware_bin.h SMARTADCPRU1 4
	-copy  .\pru_firmware_bin.h ..\pru_firmware_bin.h
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

