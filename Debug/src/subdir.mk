################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Closure.cpp \
../src/Environment.cpp \
../src/Main.cpp \
../src/Special.cpp \
../src/Tree.cpp 

O_SRCS += \
../src/Closure.o \
../src/Environment.o \
../src/Main.o \
../src/Parser.o \
../src/Printer.o \
../src/Scanner.o \
../src/Special.o \
../src/Tree.o 

OBJS += \
./src/Closure.o \
./src/Environment.o \
./src/Main.o \
./src/Special.o \
./src/Tree.o 

CPP_DEPS += \
./src/Closure.d \
./src/Environment.d \
./src/Main.d \
./src/Special.d \
./src/Tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


