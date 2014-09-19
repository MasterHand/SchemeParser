################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Main.cpp \
../src/Parser.cpp \
../src/Scanner.cpp \
../src/Special.cpp \
../src/Tree.cpp 

O_SRCS += \
../src/Main.o \
../src/Parser.o \
../src/Scanner.o \
../src/Special.o \
../src/Tree.o 

OBJS += \
./src/Main.o \
./src/Parser.o \
./src/Scanner.o \
./src/Special.o \
./src/Tree.o 

CPP_DEPS += \
./src/Main.d \
./src/Parser.d \
./src/Scanner.d \
./src/Special.d \
./src/Tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


