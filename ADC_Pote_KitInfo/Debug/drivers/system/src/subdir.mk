################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/system/src/lpc17xx_clkpwr.c \
../drivers/system/src/system_LPC17xx.c 

OBJS += \
./drivers/system/src/lpc17xx_clkpwr.o \
./drivers/system/src/system_LPC17xx.o 

C_DEPS += \
./drivers/system/src/lpc17xx_clkpwr.d \
./drivers/system/src/system_LPC17xx.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/system/src/%.o: ../drivers/system/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/agustin/project/clasespracticas/Clase19/drivers/gpio/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/adc/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/nvic/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/system/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/systick/api" -I"/home/agustin/project/clasespracticas/Clase19/primitivas/api" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


