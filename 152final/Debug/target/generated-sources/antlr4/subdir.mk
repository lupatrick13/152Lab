################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../target/generated-sources/antlr4/GooeyBaseVisitor.cpp \
../target/generated-sources/antlr4/GooeyLexer.cpp \
../target/generated-sources/antlr4/GooeyParser.cpp \
../target/generated-sources/antlr4/GooeyVisitor.cpp 

OBJS += \
./target/generated-sources/antlr4/GooeyBaseVisitor.o \
./target/generated-sources/antlr4/GooeyLexer.o \
./target/generated-sources/antlr4/GooeyParser.o \
./target/generated-sources/antlr4/GooeyVisitor.o 

CPP_DEPS += \
./target/generated-sources/antlr4/GooeyBaseVisitor.d \
./target/generated-sources/antlr4/GooeyLexer.d \
./target/generated-sources/antlr4/GooeyParser.d \
./target/generated-sources/antlr4/GooeyVisitor.d 


# Each subdirectory must supply rules for building sources it contributes
target/generated-sources/antlr4/%.o: ../target/generated-sources/antlr4/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/Users/patrick/eclipse-workspace/152final/target/generated-sources/antlr4" -I"/Users/patrick/eclipse-workspace/152final" -I/Users/patrick/ANTLR-4.8/antlr4-runtime -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


