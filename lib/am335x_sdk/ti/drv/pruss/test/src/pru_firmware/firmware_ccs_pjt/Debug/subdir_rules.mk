################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
pruss_test_pru0.obj: ../pruss_test_pru0.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: PRU Compiler'
	"c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0/bin/clpru" -v3 --include_path="c:/ti/ccsv6/tools/compiler/ti-cgt-pru_2.1.0/include" -g --define=am4379 --define=icss0 --define=pru1 --diag_warning=225 --display_error_number --diag_wrap=off --endian=little --asm_listing --asm_define=PRU1 --asm_define=MAG_ADC_ENABLE --asm_define=ADC_SIMULTANEOUS_SAMPLING --asm_define=MINIMAL_ADC_CONFIG --preproc_with_compile --preproc_dependency="pruss_test_pru0.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


