################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/nvic/src/nvic.c 

OBJS += \
./drivers/nvic/src/nvic.o 

C_DEPS += \
./drivers/nvic/src/nvic.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/nvic/src/%.o: ../drivers/nvic/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/agustin/project/clasespracticas/Clase19/drivers/gpio/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/adc/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/nvic/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/system/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/systick/api" -I"/home/agustin/project/clasespracticas/Clase19/primitivas/api" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


