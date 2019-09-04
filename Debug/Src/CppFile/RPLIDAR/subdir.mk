################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/CppFile/RPLIDAR/A1Protocol.cpp 

OBJS += \
./Src/CppFile/RPLIDAR/A1Protocol.o 

CPP_DEPS += \
./Src/CppFile/RPLIDAR/A1Protocol.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CppFile/RPLIDAR/A1Protocol.o: ../Src/CppFile/RPLIDAR/A1Protocol.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/RPLIDAR/A1Protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

