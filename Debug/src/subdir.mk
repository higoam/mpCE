################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Counterexample.cpp \
../src/Flags.cpp \
../src/GenerateFiles.cpp \
../src/RunAlgorithm.cpp \
../src/SetExperiments.cpp \
../src/mpCE.cpp 

OBJS += \
./src/Counterexample.o \
./src/Flags.o \
./src/GenerateFiles.o \
./src/RunAlgorithm.o \
./src/SetExperiments.o \
./src/mpCE.o 

CPP_DEPS += \
./src/Counterexample.d \
./src/Flags.d \
./src/GenerateFiles.d \
./src/RunAlgorithm.d \
./src/SetExperiments.d \
./src/mpCE.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


