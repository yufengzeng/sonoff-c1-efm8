################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/EFM8BB1_FlashPrimitives.c \
../src/EFM8BB1_FlashUtils.c \
../src/EFM8BB1_PCA_CaptureInput.c \
../src/InitDevice.c \
../src/Interrupts.c \
../src/key.c \
../src/logic.c \
../src/userclock.c \
../src/wdt_0.c \
../src/wireless_led.c \
../src/wireless_recv.c 

OBJS += \
./src/EFM8BB1_FlashPrimitives.OBJ \
./src/EFM8BB1_FlashUtils.OBJ \
./src/EFM8BB1_PCA_CaptureInput.OBJ \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/key.OBJ \
./src/logic.OBJ \
./src/userclock.OBJ \
./src/wdt_0.OBJ \
./src/wireless_led.OBJ \
./src/wireless_recv.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '


