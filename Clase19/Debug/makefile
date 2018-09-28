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
-include drivers/gpio/src/subdir.mk
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
all: ADC_Pote_KitInfo.axf

# Tool invocations
ADC_Pote_KitInfo.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="ADC_Pote_KitInfo.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Clase19_Debug.ld" -o "ADC_Pote_KitInfo.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ADC_Pote_KitInfo.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "ADC_Pote_KitInfo.axf"; # arm-none-eabi-objcopy -v -O binary "ADC_Pote_KitInfo.axf" "ADC_Pote_KitInfo.bin" ; # checksum -p LPC1769 -d "ADC_Pote_KitInfo.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
