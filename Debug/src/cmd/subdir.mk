################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cmd/cmd_directions.cpp \
../src/cmd/cmd_equip_lefthand.cpp \
../src/cmd/cmd_equip_righthand.cpp \
../src/cmd/cmd_exit.cpp \
../src/cmd/cmd_go_to.cpp \
../src/cmd/cmd_help.cpp \
../src/cmd/cmd_inventory.cpp \
../src/cmd/cmd_look_around.cpp \
../src/cmd/cmd_object_info.cpp \
../src/cmd/cmd_stats.cpp \
../src/cmd/cmd_take.cpp \
../src/cmd/cmd_talk_to.cpp \
../src/cmd/cmd_unequip_lefthand.cpp \
../src/cmd/cmd_unequip_righthand.cpp \
../src/cmd/cmd_use.cpp 

OBJS += \
./src/cmd/cmd_directions.o \
./src/cmd/cmd_equip_lefthand.o \
./src/cmd/cmd_equip_righthand.o \
./src/cmd/cmd_exit.o \
./src/cmd/cmd_go_to.o \
./src/cmd/cmd_help.o \
./src/cmd/cmd_inventory.o \
./src/cmd/cmd_look_around.o \
./src/cmd/cmd_object_info.o \
./src/cmd/cmd_stats.o \
./src/cmd/cmd_take.o \
./src/cmd/cmd_talk_to.o \
./src/cmd/cmd_unequip_lefthand.o \
./src/cmd/cmd_unequip_righthand.o \
./src/cmd/cmd_use.o 

CPP_DEPS += \
./src/cmd/cmd_directions.d \
./src/cmd/cmd_equip_lefthand.d \
./src/cmd/cmd_equip_righthand.d \
./src/cmd/cmd_exit.d \
./src/cmd/cmd_go_to.d \
./src/cmd/cmd_help.d \
./src/cmd/cmd_inventory.d \
./src/cmd/cmd_look_around.d \
./src/cmd/cmd_object_info.d \
./src/cmd/cmd_stats.d \
./src/cmd/cmd_take.d \
./src/cmd/cmd_talk_to.d \
./src/cmd/cmd_unequip_lefthand.d \
./src/cmd/cmd_unequip_righthand.d \
./src/cmd/cmd_use.d 


# Each subdirectory must supply rules for building sources it contributes
src/cmd/%.o: ../src/cmd/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


