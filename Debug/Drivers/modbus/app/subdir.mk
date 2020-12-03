################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/modbus/app/user_mb_app.c \
../Drivers/modbus/app/user_mb_app_m.c 

OBJS += \
./Drivers/modbus/app/user_mb_app.o \
./Drivers/modbus/app/user_mb_app_m.o 

C_DEPS += \
./Drivers/modbus/app/user_mb_app.d \
./Drivers/modbus/app/user_mb_app_m.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/modbus/app/user_mb_app.o: ../Drivers/modbus/app/user_mb_app.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/app/user_mb_app.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/app/user_mb_app_m.o: ../Drivers/modbus/app/user_mb_app_m.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/app/user_mb_app_m.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

