################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Inventory/Inventory.cpp \
../src/Inventory/Item.cpp \
../src/Inventory/Potion.cpp \
../src/Inventory/Weapon.cpp 

OBJS += \
./src/Inventory/Inventory.o \
./src/Inventory/Item.o \
./src/Inventory/Potion.o \
./src/Inventory/Weapon.o 

CPP_DEPS += \
./src/Inventory/Inventory.d \
./src/Inventory/Item.d \
./src/Inventory/Potion.d \
./src/Inventory/Weapon.d 


# Each subdirectory must supply rules for building sources it contributes
src/Inventory/%.o: ../src/Inventory/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


