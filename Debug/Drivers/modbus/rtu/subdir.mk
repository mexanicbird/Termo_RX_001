################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/modbus/rtu/mbcrc.c \
../Drivers/modbus/rtu/mbrtu.c \
../Drivers/modbus/rtu/mbrtu_m.c 

OBJS += \
./Drivers/modbus/rtu/mbcrc.o \
./Drivers/modbus/rtu/mbrtu.o \
./Drivers/modbus/rtu/mbrtu_m.o 

C_DEPS += \
./Drivers/modbus/rtu/mbcrc.d \
./Drivers/modbus/rtu/mbrtu.d \
./Drivers/modbus/rtu/mbrtu_m.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/modbus/rtu/mbcrc.o: ../Drivers/modbus/rtu/mbcrc.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/rtu/mbcrc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/rtu/mbrtu.o: ../Drivers/modbus/rtu/mbrtu.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/rtu/mbrtu.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/rtu/mbrtu_m.o: ../Drivers/modbus/rtu/mbrtu_m.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/rtu/mbrtu_m.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

