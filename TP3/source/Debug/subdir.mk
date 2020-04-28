################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Annuaire.cpp \
../ContratException.cpp \
../Date.cpp \
../Entraineur.cpp \
../Joueur.cpp \
../Personne.cpp \
../validationFormat.cpp 

OBJS += \
./Annuaire.o \
./ContratException.o \
./Date.o \
./Entraineur.o \
./Joueur.o \
./Personne.o \
./validationFormat.o 

CPP_DEPS += \
./Annuaire.d \
./ContratException.d \
./Date.d \
./Entraineur.d \
./Joueur.d \
./Personne.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


