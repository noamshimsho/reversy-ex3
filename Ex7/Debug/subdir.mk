################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CloseCommand.cpp \
../CommandsManager.cpp \
../EndCommand.cpp \
../Game.cpp \
../JoinCommand.cpp \
../ListCommand.cpp \
../PlayCommand.cpp \
../Server.cpp \
../StartCommand.cpp \
../ThreadPool.cpp \
../main.cpp 

OBJS += \
./CloseCommand.o \
./CommandsManager.o \
./EndCommand.o \
./Game.o \
./JoinCommand.o \
./ListCommand.o \
./PlayCommand.o \
./Server.o \
./StartCommand.o \
./ThreadPool.o \
./main.o 

CPP_DEPS += \
./CloseCommand.d \
./CommandsManager.d \
./EndCommand.d \
./Game.d \
./JoinCommand.d \
./ListCommand.d \
./PlayCommand.d \
./Server.d \
./StartCommand.d \
./ThreadPool.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


