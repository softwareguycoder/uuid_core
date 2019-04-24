################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libuuid_core.so

dependents:
	-cd /home/bhart/git/common_core/common_core/Debug && $(MAKE) clean all

# Tool invocations
libuuid_core.so: $(OBJS) $(USER_OBJS) /home/bhart/git/common_core/common_core/Debug/libcommon_core.so
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/bhart/git/common_core/common_core/Debug" -shared -o "libuuid_core.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(LIBRARIES)$(OBJS)$(C_DEPS) libuuid_core.so
	-@echo ' '

post-build:
	-cp -f libuuid_core.so "/home/bhart/lib/Debug"
	-@echo ' '

.PHONY: all clean dependents post-build
/home/bhart/git/common_core/common_core/Debug/libcommon_core.so:

-include ../makefile.targets
