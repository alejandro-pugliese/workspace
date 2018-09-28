################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Services/Scheduler/Scheduler.c 

OBJS += \
./src/Services/Scheduler/Scheduler.o 

C_DEPS += \
./src/Services/Scheduler/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
src/Services/Scheduler/%.o: ../src/Services/Scheduler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=c11 -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/TPL1_v2/inc" -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/TPL1_v2/src/Services/Scheduler" -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/ChipDriverLibrary/inc" -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/InfotronicDriverLibrary/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


