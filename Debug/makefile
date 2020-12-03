################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/modbus/tcp/subdir.mk
-include Drivers/modbus/rtu/subdir.mk
-include Drivers/modbus/port/subdir.mk
-include Drivers/modbus/functions/subdir.mk
-include Drivers/modbus/ascii/subdir.mk
-include Drivers/modbus/app/subdir.mk
-include Drivers/modbus/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Termo_RX_001.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Termo_RX_001.list \

OBJCOPY_BIN += \
Termo_RX_001.bin \


# All Target
all: Termo_RX_001.elf secondary-outputs

# Tool invocations
Termo_RX_001.elf: $(OBJS) $(USER_OBJS) C:\Users\Alexey\STM32CubeIDE\workspace_1.4.0\Termo_RX_001\STM32F103CBTX_FLASH.ld
	arm-none-eabi-gcc -u _printf_float -o "Termo_RX_001.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Alexey\STM32CubeIDE\workspace_1.4.0\Termo_RX_001\STM32F103CBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Termo_RX_001.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Termo_RX_001.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Termo_RX_001.list"
	@echo 'Finished building: $@'
	@echo ' '

Termo_RX_001.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Termo_RX_001.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
