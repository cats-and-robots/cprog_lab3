################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cmd/cmd_directions.cpp \
../cmd/cmd_equip_lefthand.cpp \
../cmd/cmd_equip_righthand.cpp \
../cmd/cmd_exit.cpp \
../cmd/cmd_go_to.cpp \
../cmd/cmd_help.cpp \
../cmd/cmd_inventory.cpp \
../cmd/cmd_look_around.cpp \
../cmd/cmd_object_info.cpp \
../cmd/cmd_stats.cpp \
../cmd/cmd_take.cpp \
../cmd/cmd_talk_to.cpp \
../cmd/cmd_unequip_lefthand.cpp \
../cmd/cmd_unequip_righthand.cpp \
../cmd/cmd_use.cpp 

OBJS += \
./cmd/cmd_directions.o \
./cmd/cmd_equip_lefthand.o \
./cmd/cmd_equip_righthand.o \
./cmd/cmd_exit.o \
./cmd/cmd_go_to.o \
./cmd/cmd_help.o \
./cmd/cmd_inventory.o \
./cmd/cmd_look_around.o \
./cmd/cmd_object_info.o \
./cmd/cmd_stats.o \
./cmd/cmd_take.o \
./cmd/cmd_talk_to.o \
./cmd/cmd_unequip_lefthand.o \
./cmd/cmd_unequip_righthand.o \
./cmd/cmd_use.o 

CPP_DEPS += \
./cmd/cmd_directions.d \
./cmd/cmd_equip_lefthand.d \
./cmd/cmd_equip_righthand.d \
./cmd/cmd_exit.d \
./cmd/cmd_go_to.d \
./cmd/cmd_help.d \
./cmd/cmd_inventory.d \
./cmd/cmd_look_around.d \
./cmd/cmd_object_info.d \
./cmd/cmd_stats.d \
./cmd/cmd_take.d \
./cmd/cmd_talk_to.d \
./cmd/cmd_unequip_lefthand.d \
./cmd/cmd_unequip_righthand.d \
./cmd/cmd_use.d 


# Each subdirectory must supply rules for building sources it contributes
cmd/%.o: ../cmd/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


