################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../primitivas/src/boardinit.c \
../primitivas/src/salidasdigitales_infotronic.c \
../primitivas/src/tecladofijo_infotronic.c 

OBJS += \
./primitivas/src/boardinit.o \
./primitivas/src/salidasdigitales_infotronic.o \
./primitivas/src/tecladofijo_infotronic.o 

C_DEPS += \
./primitivas/src/boardinit.d \
./primitivas/src/salidasdigitales_infotronic.d \
./primitivas/src/tecladofijo_infotronic.d 


# Each subdirectory must supply rules for building sources it contributes
primitivas/src/%.o: ../primitivas/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/agustin/project/clasespracticas/Clase19/drivers/gpio/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/uart/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/nvic/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/system/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/systick/api" -I"/home/agustin/project/clasespracticas/Clase19/primitivas/api" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


