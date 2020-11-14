################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../backend/compiler/ActionGenerator.cpp \
../backend/compiler/CodeGenerator.cpp \
../backend/compiler/Compiler.cpp \
../backend/compiler/ExpressionGenerator.cpp \
../backend/compiler/ProgramGenerator.cpp \
../backend/compiler/StatementGenerator.cpp \
../backend/compiler/StructuredDataGenerator.cpp 

OBJS += \
./backend/compiler/ActionGenerator.o \
./backend/compiler/CodeGenerator.o \
./backend/compiler/Compiler.o \
./backend/compiler/ExpressionGenerator.o \
./backend/compiler/ProgramGenerator.o \
./backend/compiler/StatementGenerator.o \
./backend/compiler/StructuredDataGenerator.o 

CPP_DEPS += \
./backend/compiler/ActionGenerator.d \
./backend/compiler/CodeGenerator.d \
./backend/compiler/Compiler.d \
./backend/compiler/ExpressionGenerator.d \
./backend/compiler/ProgramGenerator.d \
./backend/compiler/StatementGenerator.d \
./backend/compiler/StructuredDataGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
backend/compiler/%.o: ../backend/compiler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/Users/patrick/eclipse-workspace/152final/target/generated-sources/antlr4" -I"/Users/patrick/eclipse-workspace/152final" -I/Users/patrick/ANTLR-4.8/antlr4-runtime -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


