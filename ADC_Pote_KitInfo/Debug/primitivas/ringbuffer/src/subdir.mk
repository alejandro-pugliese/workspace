################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../primitivas/ringbuffer/src/ring_buffer.c 

OBJS += \
./primitivas/ringbuffer/src/ring_buffer.o 

C_DEPS += \
./primitivas/ringbuffer/src/ring_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
primitivas/ringbuffer/src/%.o: ../primitivas/ringbuffer/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/agustin/projects/clasespracticas/Clase19/drivers/gpio/api" -I"/home/agustin/projects/clasespracticas/Clase19/primitivas/ringbuffer/api" -I"/home/agustin/projects/clasespracticas/Clase19/drivers/uart/api" -I"/home/agustin/projects/clasespracticas/Clase19/drivers/nvic/api" -I"/home/agustin/projects/clasespracticas/Clase19/drivers/system/api" -I"/home/agustin/projects/clasespracticas/Clase19/drivers/systick/api" -I"/home/agustin/projects/clasespracticas/Clase19/primitivas/api" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


