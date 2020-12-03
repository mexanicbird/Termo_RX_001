################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/modbus/port/portcritical.c \
../Drivers/modbus/port/portevent.c \
../Drivers/modbus/port/portevent_m.c \
../Drivers/modbus/port/portserial.c \
../Drivers/modbus/port/portserial_m.c \
../Drivers/modbus/port/porttimer.c \
../Drivers/modbus/port/porttimer_m.c 

OBJS += \
./Drivers/modbus/port/portcritical.o \
./Drivers/modbus/port/portevent.o \
./Drivers/modbus/port/portevent_m.o \
./Drivers/modbus/port/portserial.o \
./Drivers/modbus/port/portserial_m.o \
./Drivers/modbus/port/porttimer.o \
./Drivers/modbus/port/porttimer_m.o 

C_DEPS += \
./Drivers/modbus/port/portcritical.d \
./Drivers/modbus/port/portevent.d \
./Drivers/modbus/port/portevent_m.d \
./Drivers/modbus/port/portserial.d \
./Drivers/modbus/port/portserial_m.d \
./Drivers/modbus/port/porttimer.d \
./Drivers/modbus/port/porttimer_m.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/modbus/port/portcritical.o: ../Drivers/modbus/port/portcritical.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/portcritical.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/port/portevent.o: ../Drivers/modbus/port/portevent.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/portevent.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/port/portevent_m.o: ../Drivers/modbus/port/portevent_m.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/portevent_m.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/port/portserial.o: ../Drivers/modbus/port/portserial.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/portserial.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/port/portserial_m.o: ../Drivers/modbus/port/portserial_m.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/portserial_m.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/port/porttimer.o: ../Drivers/modbus/port/porttimer.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/porttimer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/modbus/port/porttimer_m.o: ../Drivers/modbus/port/porttimer_m.c
	arm-none-eabi-gcc -u _printf_float "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/app" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/ascii" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/functions" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/include" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/port" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/rtu" -I"C:/Users/Alexey/STM32CubeIDE/workspace_1.4.0/Termo_RX_001/Drivers/modbus/tcp" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/modbus/port/porttimer_m.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

