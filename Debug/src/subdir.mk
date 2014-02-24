################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Animal.cpp \
../src/CafeRobot.cpp \
../src/Cat.cpp \
../src/EvilCat.cpp \
../src/EvilRobot.cpp \
../src/Fighter.cpp \
../src/Inventory.cpp \
../src/Item.cpp \
../src/Object.cpp \
../src/Player.cpp \
../src/Robot.cpp \
../src/Room.cpp \
../src/TheGame.cpp \
../src/Weapon.cpp 

OBJS += \
./src/Animal.o \
./src/CafeRobot.o \
./src/Cat.o \
./src/EvilCat.o \
./src/EvilRobot.o \
./src/Fighter.o \
./src/Inventory.o \
./src/Item.o \
./src/Object.o \
./src/Player.o \
./src/Robot.o \
./src/Room.o \
./src/TheGame.o \
./src/Weapon.o 

CPP_DEPS += \
./src/Animal.d \
./src/CafeRobot.d \
./src/Cat.d \
./src/EvilCat.d \
./src/EvilRobot.d \
./src/Fighter.d \
./src/Inventory.d \
./src/Item.d \
./src/Object.d \
./src/Player.d \
./src/Robot.d \
./src/Room.d \
./src/TheGame.d \
./src/Weapon.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


