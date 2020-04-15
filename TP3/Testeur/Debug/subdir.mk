################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AnnuaireTesteur.cpp \
../EntraineurTesteur.cpp \
../JoueurTesteur.cpp \
../PersonneTesteur.cpp 

OBJS += \
./AnnuaireTesteur.o \
./EntraineurTesteur.o \
./JoueurTesteur.o \
./PersonneTesteur.o 

CPP_DEPS += \
./AnnuaireTesteur.d \
./EntraineurTesteur.d \
./JoueurTesteur.d \
./PersonneTesteur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/mnt/hgfs/C++/Sauvegarde TP3/TP3/source" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


