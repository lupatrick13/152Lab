################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../intermediate/symtab/Predefined.cpp 

OBJS += \
./intermediate/symtab/Predefined.o 

CPP_DEPS += \
./intermediate/symtab/Predefined.d 


# Each subdirectory must supply rules for building sources it contributes
intermediate/symtab/%.o: ../intermediate/symtab/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/Users/patrick/eclipse-workspace/152final/target/generated-sources/antlr4" -I"/Users/patrick/eclipse-workspace/152final" -I/Users/patrick/ANTLR-4.8/antlr4-runtime -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


