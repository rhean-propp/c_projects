################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../pointer_1.c \
../pointer_2.c \
../pointer_3.c \
../pointer_4.c \
../pointer_5.c \
../pointer_6.c 

OBJS += \
./pointer_1.o \
./pointer_2.o \
./pointer_3.o \
./pointer_4.o \
./pointer_5.o \
./pointer_6.o 

C_DEPS += \
./pointer_1.d \
./pointer_2.d \
./pointer_3.d \
./pointer_4.d \
./pointer_5.d \
./pointer_6.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


