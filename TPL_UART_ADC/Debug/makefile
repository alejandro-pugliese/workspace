################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include primitivas/src/subdir.mk
-include drivers/uart/src/subdir.mk
-include drivers/systick/src/subdir.mk
-include drivers/system/src/subdir.mk
-include drivers/nvic/src/subdir.mk
-include drivers/adc/src/subdir.mk
-include application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TPL_UART_ADC.axf

# Tool invocations
TPL_UART_ADC.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/agustin/project/clasespracticas/Clase19/utils/lib" -Xlinker -Map="TPL_UART_ADC.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "TPL_UART_ADC_Debug.ld" -o "TPL_UART_ADC.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) TPL_UART_ADC.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "TPL_UART_ADC.axf"; # arm-none-eabi-objcopy -v -O binary "TPL_UART_ADC.axf" "TPL_UART_ADC.bin" ; # checksum -p LPC1769 -d "TPL_UART_ADC.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
