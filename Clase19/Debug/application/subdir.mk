################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/aplicacion.c \
../application/cr_startup_lpc175x_6x.c \
../application/crp.c 

OBJS += \
./application/aplicacion.o \
./application/cr_startup_lpc175x_6x.o \
./application/crp.o 

C_DEPS += \
./application/aplicacion.d \
./application/cr_startup_lpc175x_6x.d \
./application/crp.d 


# Each subdirectory must supply rules for building sources it contributes
application/%.o: ../application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/agustin/project/clasespracticas/Clase19/drivers/gpio/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/uart/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/nvic/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/system/api" -I"/home/agustin/project/clasespracticas/Clase19/drivers/systick/api" -I"/home/agustin/project/clasespracticas/Clase19/primitivas/api" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


