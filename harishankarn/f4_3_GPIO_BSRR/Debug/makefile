################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := f4_3_GPIO_BSRR
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
f4_3_GPIO_BSRR.elf \

MAP_FILES += \
f4_3_GPIO_BSRR.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
f4_3_GPIO_BSRR.list \


# All Target
all: main-build

# Main-build Target
main-build: f4_3_GPIO_BSRR.elf secondary-outputs

# Tool invocations
f4_3_GPIO_BSRR.elf f4_3_GPIO_BSRR.map: $(OBJS) $(USER_OBJS) /Users/harishankar/Desktop/Baremetal_workspace/f4_3_GPIO_BSRR/STM32F429ZITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "f4_3_GPIO_BSRR.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/harishankar/Desktop/Baremetal_workspace/f4_3_GPIO_BSRR/STM32F429ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="f4_3_GPIO_BSRR.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

f4_3_GPIO_BSRR.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "f4_3_GPIO_BSRR.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout f4_3_GPIO_BSRR.elf f4_3_GPIO_BSRR.list f4_3_GPIO_BSRR.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
