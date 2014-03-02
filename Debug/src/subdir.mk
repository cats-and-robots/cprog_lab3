################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CafeRobot.cpp \
../src/Cat.cpp \
../src/Commands.cpp \
../src/EvilCat.cpp \
../src/EvilRobot.cpp \
../src/Inventory.cpp \
../src/Item.cpp \
../src/Player.cpp \
../src/Room.cpp \
../src/TheGame.cpp \
../src/Weapon.cpp \
../src/main.cpp 

OBJS += \
./src/CafeRobot.o \
./src/Cat.o \
./src/Commands.o \
./src/EvilCat.o \
./src/EvilRobot.o \
./src/Inventory.o \
./src/Item.o \
./src/Player.o \
./src/Room.o \
./src/TheGame.o \
./src/Weapon.o \
./src/main.o 

CPP_DEPS += \
./src/CafeRobot.d \
./src/Cat.d \
./src/Commands.d \
./src/EvilCat.d \
./src/EvilRobot.d \
./src/Inventory.d \
./src/Item.d \
./src/Player.d \
./src/Room.d \
./src/TheGame.d \
./src/Weapon.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


