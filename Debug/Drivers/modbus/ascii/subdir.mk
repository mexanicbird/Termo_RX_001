################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/modbus/ascii/mbascii.c 

OBJS += \
./Drivers/modbus/ascii/mbascii.o 

C_DEPS += \
./Drivers/modbus/ascii/mbascii.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/modbus/ascii/mbascii.o: ../Drivers/modbus/ascii/mbascii.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/ascii/mbascii.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

