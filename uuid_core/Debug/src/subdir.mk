################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/stdafx.c \
../src/uuid_core.c 

OBJS += \
./src/stdafx.o \
./src/uuid_core.o 

C_DEPS += \
./src/stdafx.d \
./src/uuid_core.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/bhart/git/common_core/common_core" -I"/home/bhart/git/uuid_core/uuid_core/include" -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


