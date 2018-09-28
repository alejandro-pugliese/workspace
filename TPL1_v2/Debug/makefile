################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Services/Scheduler/subdir.mk
-include src/subdir.mk
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
all: TPL1_v2.axf

# Tool invocations
TPL1_v2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/ChipDriverLibrary/Debug" -L"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/InfotronicDriverLibrary/Debug" -Xlinker -Map="TPL1_v2.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "test_2018_06_21_Debug.ld" -o "TPL1_v2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) TPL1_v2.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "TPL1_v2.axf"; # arm-none-eabi-objcopy -v -O binary "TPL1_v2.axf" "TPL1_v2.bin" ; # checksum -p LPC1769 -d "TPL1_v2.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
