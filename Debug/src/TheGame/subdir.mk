################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TheGame/TheGame.cpp \
../src/TheGame/main.cpp 

OBJS += \
./src/TheGame/TheGame.o \
./src/TheGame/main.o 

CPP_DEPS += \
./src/TheGame/TheGame.d \
./src/TheGame/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/TheGame/%.o: ../src/TheGame/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


