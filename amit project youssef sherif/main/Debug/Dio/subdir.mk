################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio/Dio.c \
../Dio/Dio_cfg.c \
../Dio/main.c 

OBJS += \
./Dio/Dio.o \
./Dio/Dio_cfg.o \
./Dio/main.o 

C_DEPS += \
./Dio/Dio.d \
./Dio/Dio_cfg.d \
./Dio/main.d 


# Each subdirectory must supply rules for building sources it contributes
Dio/%.o: ../Dio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


