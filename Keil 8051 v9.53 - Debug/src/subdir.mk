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

src/EFM8BB1_FlashPrimitives.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/EFM8BB1_FlashPrimitives.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/EFM8BB1_FlashUtils.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/EFM8BB1_FlashPrimitives.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/EFM8BB1_FlashUtils.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/EFM8BB1_PCA_CaptureInput.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/InitDevice.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/logic.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_led.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wdt_0.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/userclock.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_recv.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/logic.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_led.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/key.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/key.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/key.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/logic.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_led.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/userclock.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/logic.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/logic.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/key.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_recv.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_led.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/EFM8BB1_FlashPrimitives.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/EFM8BB1_FlashUtils.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/userclock.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/userclock.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/logic.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/userclock.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/wdt_0.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wdt_0.h C:/SiliconLabs/SimplicityStudio/v3/developer/toolchains/keil_8051/9.53/INC/ASSERT.H C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/wireless_led.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_led.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/userclock.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/wireless_recv.OBJ: D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/wireless_recv.h D:/VM/share/EFM8_PROJ/SONOFF-C1-EFM8/inc/logic.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h


