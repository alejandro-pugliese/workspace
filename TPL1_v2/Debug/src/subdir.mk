################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/main.c 

OBJS += \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/main.o 

C_DEPS += \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=c11 -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/TPL1_v2/inc" -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/TPL1_v2/src/Services/Scheduler" -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/ChipDriverLibrary/inc" -I"/Users/alejandro/Documents/MCUXpressoIDE_10.2.0/workspace/InfotronicDriverLibrary/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


