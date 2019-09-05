################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/CppFile/CCommand.cpp \
../Src/CppFile/CDevice.cpp \
../Src/CppFile/CDeviceDecorator.cpp \
../Src/CppFile/CInvoker.cpp \
../Src/CppFile/CObserver.cpp \
../Src/CppFile/CReceiver.cpp \
../Src/CppFile/CStrategy.cpp \
../Src/CppFile/CSubject.cpp 

OBJS += \
./Src/CppFile/CCommand.o \
./Src/CppFile/CDevice.o \
./Src/CppFile/CDeviceDecorator.o \
./Src/CppFile/CInvoker.o \
./Src/CppFile/CObserver.o \
./Src/CppFile/CReceiver.o \
./Src/CppFile/CStrategy.o \
./Src/CppFile/CSubject.o 

CPP_DEPS += \
./Src/CppFile/CCommand.d \
./Src/CppFile/CDevice.d \
./Src/CppFile/CDeviceDecorator.d \
./Src/CppFile/CInvoker.d \
./Src/CppFile/CObserver.d \
./Src/CppFile/CReceiver.d \
./Src/CppFile/CStrategy.d \
./Src/CppFile/CSubject.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CppFile/CCommand.o: ../Src/CppFile/CCommand.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CCommand.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CDevice.o: ../Src/CppFile/CDevice.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CDevice.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CDeviceDecorator.o: ../Src/CppFile/CDeviceDecorator.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CDeviceDecorator.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CInvoker.o: ../Src/CppFile/CInvoker.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CInvoker.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CObserver.o: ../Src/CppFile/CObserver.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CObserver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CReceiver.o: ../Src/CppFile/CReceiver.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CReceiver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CStrategy.o: ../Src/CppFile/CStrategy.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CStrategy.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/CppFile/CSubject.o: ../Src/CppFile/CSubject.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CUart" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/CStateMachine" -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile/RPLIDAR" -I../Inc -I"C:/Users/wyz/source/cubeIDErepos/RobotCar/Src/CppFile" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/CppFile/CSubject.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

