################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/bin/cl2000" -v28 -ml --float_support=fpu32 --include_path="C:/Users/YX2030/workspace_v9_2/Basic_DCAC_IGBT_10kHz" --include_path="../include" --include_path="D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/bin/cl2000" -v28 -ml --float_support=fpu32 --include_path="C:/Users/YX2030/workspace_v9_2/Basic_DCAC_IGBT_10kHz" --include_path="../include" --include_path="D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


