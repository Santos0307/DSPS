################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Colores.c \
../source/main.c 

OBJS += \
./source/Colores.o \
./source/main.o 

C_DEPS += \
./source/Colores.d \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCPU_MK64FN1M0VLL12_cm4 -DCPU_MK64FN1M0VLL12 -D__REDLIB__ -I"C:\Users\Santos\Documents\MCUXpressoIDE_10.0.2_411\workspace\hmwkrgb\source" -I"C:\Users\Santos\Documents\MCUXpressoIDE_10.0.2_411\workspace\hmwkrgb" -I"C:\Users\Santos\Documents\MCUXpressoIDE_10.0.2_411\workspace\hmwkrgb\startup" -I"C:\Users\Santos\Documents\MCUXpressoIDE_10.0.2_411\workspace\hmwkrgb\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


