################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../backend/converter/CodeGenerator.cpp \
../backend/converter/Converter.cpp 

OBJS += \
./backend/converter/CodeGenerator.o \
./backend/converter/Converter.o 

CPP_DEPS += \
./backend/converter/CodeGenerator.d \
./backend/converter/Converter.d 


# Each subdirectory must supply rules for building sources it contributes
backend/converter/%.o: ../backend/converter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/Users/patrick/eclipse-workspace/152lab5" -I"/Users/patrick/eclipse-workspace/152lab5/TESTS" -I"/Users/patrick/eclipse-workspace/152lab5/backend/converter" -I"/Users/patrick/eclipse-workspace/152lab5/backend/interpreter" -I"/Users/patrick/eclipse-workspace/152lab5/frontend" -I"/Users/patrick/eclipse-workspace/152lab5/intermediate/symtab" -I"/Users/patrick/eclipse-workspace/152lab5/intermediate/type" -I"/Users/patrick/eclipse-workspace/152lab5/intermediate/util" -I"/Users/patrick/eclipse-workspace/152lab5/target/generated-sources/antlr4" -I/Users/patrick/ANTLR-4.8/antlr4-runtime -I/Users/patrick/ANTLR-4.8/lib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


