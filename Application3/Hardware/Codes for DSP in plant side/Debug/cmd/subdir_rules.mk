################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
cmd/DSP2833x_Headers_nonBIOS.out: ../cmd/DSP2833x_Headers_nonBIOS.cmd $(GEN_CMDS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Linker'
	"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/bin/cl2000" -v28 -ml --float_support=fpu32 --define=_DEBUG --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number -z -m"../cmd/Debug/F28335_GTI_FLASH.map" --heap_size=1000 --stack_size=1000 --warn_sections -i"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/lib" -i"C:/Users/YX2030/workspace_v9_2/Basic_DCAC_IGBT_10kHz" -i"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Basic_DCAC_IGBT_10kHz_linkInfo.xml" --rom_model -o "$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

cmd/F2833xFlash.out: ../cmd/F2833xFlash.cmd $(GEN_CMDS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Linker'
	"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/bin/cl2000" -v28 -ml --float_support=fpu32 --define=_DEBUG --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number -z -m"../cmd/Debug/F28335_GTI_FLASH.map" --heap_size=1000 --stack_size=1000 --warn_sections -i"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/lib" -i"C:/Users/YX2030/workspace_v9_2/Basic_DCAC_IGBT_10kHz" -i"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Basic_DCAC_IGBT_10kHz_linkInfo.xml" --rom_model -o "$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


