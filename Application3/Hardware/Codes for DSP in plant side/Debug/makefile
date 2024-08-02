################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"../cmd/F2833xFlash.cmd" \
"./source/DSP2833x_ADC_cal.obj" \
"./source/DSP2833x_Adc.obj" \
"./source/DSP2833x_CodeStartBranch.obj" \
"./source/DSP2833x_EPwm.obj" \
"./source/DSP2833x_GlobalVariableDefs.obj" \
"./source/DSP2833x_Gpio.obj" \
"./source/DSP2833x_PieCtrl.obj" \
"./source/DSP2833x_PieVect.obj" \
"./source/DSP2833x_SWPrioritizedDefaultIsr.obj" \
"./source/DSP2833x_Sci.obj" \
"./source/DSP2833x_SectionCopy_nonBIOS.obj" \
"./source/DSP2833x_SysCtrl.obj" \
"./source/DSP2833x_Xintf.obj" \
"./source/DSP2833x_usDelay.obj" \
"./source/main.obj" \
"../cmd/DSP2833x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-lrts2800_fpu32.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include cmd/subdir_vars.mk
-include source/subdir_vars.mk
-include cmd/subdir_rules.mk
-include source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
F28335_GTI_FLASH.out \

EXE_OUTPUTS__QUOTED += \
"F28335_GTI_FLASH.out" \

BIN_OUTPUTS += \
F28335_GTI_FLASH.hex \

BIN_OUTPUTS__QUOTED += \
"F28335_GTI_FLASH.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "F28335_GTI_FLASH.out"

# Tool invocations
F28335_GTI_FLASH.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/bin/cl2000" -v28 -ml --float_support=fpu32 --define=_DEBUG --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number -z -m"F28335_GTI_FLASH.map" --heap_size=1000 --stack_size=1000 --warn_sections -i"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/lib" -i"C:/Users/YX2030/workspace_v9_2/Basic_DCAC_IGBT_10kHz" -i"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Basic_DCAC_IGBT_10kHz_linkInfo.xml" --rom_model -o "F28335_GTI_FLASH.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

F28335_GTI_FLASH.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"D:/install/CCS/ccs/tools/compiler/ti-cgt-c2000_18.12.3.LTS/bin/hex2000"  -o "F28335_GTI_FLASH.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "source\DSP2833x_ADC_cal.obj" "source\DSP2833x_Adc.obj" "source\DSP2833x_CodeStartBranch.obj" "source\DSP2833x_EPwm.obj" "source\DSP2833x_GlobalVariableDefs.obj" "source\DSP2833x_Gpio.obj" "source\DSP2833x_PieCtrl.obj" "source\DSP2833x_PieVect.obj" "source\DSP2833x_SWPrioritizedDefaultIsr.obj" "source\DSP2833x_Sci.obj" "source\DSP2833x_SectionCopy_nonBIOS.obj" "source\DSP2833x_SysCtrl.obj" "source\DSP2833x_Xintf.obj" "source\DSP2833x_usDelay.obj" "source\main.obj" 
	-$(RM) "source\DSP2833x_Adc.d" "source\DSP2833x_EPwm.d" "source\DSP2833x_GlobalVariableDefs.d" "source\DSP2833x_Gpio.d" "source\DSP2833x_PieCtrl.d" "source\DSP2833x_PieVect.d" "source\DSP2833x_SWPrioritizedDefaultIsr.d" "source\DSP2833x_Sci.d" "source\DSP2833x_SysCtrl.d" "source\DSP2833x_Xintf.d" "source\main.d" 
	-$(RM) "source\DSP2833x_ADC_cal.d" "source\DSP2833x_CodeStartBranch.d" "source\DSP2833x_SectionCopy_nonBIOS.d" "source\DSP2833x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

