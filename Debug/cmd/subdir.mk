################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cmd/cmd_equip_righthand.cpp \
../cmd/cmd_help.cpp \
../cmd/cmd_inventory.cpp \
../cmd/cmd_stats.cpp 

OBJS += \
./cmd/cmd_equip_righthand.o \
./cmd/cmd_help.o \
./cmd/cmd_inventory.o \
./cmd/cmd_stats.o 

CPP_DEPS += \
./cmd/cmd_equip_righthand.d \
./cmd/cmd_help.d \
./cmd/cmd_inventory.d \
./cmd/cmd_stats.d 


# Each subdirectory must supply rules for building sources it contributes
cmd/%.o: ../cmd/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 "-std=c++0x" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


