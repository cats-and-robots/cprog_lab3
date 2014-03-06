################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Characters/CafeRobot.cpp \
../src/Characters/Cat.cpp \
../src/Characters/EvilCat.cpp \
../src/Characters/EvilRobot.cpp \
../src/Characters/GuardianCat.cpp \
../src/Characters/Player.cpp 

OBJS += \
./src/Characters/CafeRobot.o \
./src/Characters/Cat.o \
./src/Characters/EvilCat.o \
./src/Characters/EvilRobot.o \
./src/Characters/GuardianCat.o \
./src/Characters/Player.o 

CPP_DEPS += \
./src/Characters/CafeRobot.d \
./src/Characters/Cat.d \
./src/Characters/EvilCat.d \
./src/Characters/EvilRobot.d \
./src/Characters/GuardianCat.d \
./src/Characters/Player.d 


# Each subdirectory must supply rules for building sources it contributes
src/Characters/%.o: ../src/Characters/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


