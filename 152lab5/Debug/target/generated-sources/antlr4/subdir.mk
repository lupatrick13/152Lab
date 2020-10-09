################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../target/generated-sources/antlr4/PascalBaseVisitor.cpp \
../target/generated-sources/antlr4/PascalLexer.cpp \
../target/generated-sources/antlr4/PascalParser.cpp \
../target/generated-sources/antlr4/PascalVisitor.cpp 

OBJS += \
./target/generated-sources/antlr4/PascalBaseVisitor.o \
./target/generated-sources/antlr4/PascalLexer.o \
./target/generated-sources/antlr4/PascalParser.o \
./target/generated-sources/antlr4/PascalVisitor.o 

CPP_DEPS += \
./target/generated-sources/antlr4/PascalBaseVisitor.d \
./target/generated-sources/antlr4/PascalLexer.d \
./target/generated-sources/antlr4/PascalParser.d \
./target/generated-sources/antlr4/PascalVisitor.d 


# Each subdirectory must supply rules for building sources it contributes
target/generated-sources/antlr4/%.o: ../target/generated-sources/antlr4/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/Users/patrick/eclipse-workspace/152lab5" -I"/Users/patrick/eclipse-workspace/152lab5/TESTS" -I"/Users/patrick/eclipse-workspace/152lab5/backend/converter" -I"/Users/patrick/eclipse-workspace/152lab5/backend/interpreter" -I"/Users/patrick/eclipse-workspace/152lab5/frontend" -I"/Users/patrick/eclipse-workspace/152lab5/intermediate/symtab" -I"/Users/patrick/eclipse-workspace/152lab5/intermediate/type" -I"/Users/patrick/eclipse-workspace/152lab5/intermediate/util" -I"/Users/patrick/eclipse-workspace/152lab5/target/generated-sources/antlr4" -I/Users/patrick/ANTLR-4.8/antlr4-runtime -I/Users/patrick/ANTLR-4.8/lib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


