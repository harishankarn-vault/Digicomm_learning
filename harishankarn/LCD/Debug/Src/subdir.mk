################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/misc.c \
../Src/stm32f4xx_dma.c \
../Src/stm32f4xx_gpio.c \
../Src/stm32f4xx_rcc.c \
../Src/stm32f4xx_spi.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c \
../Src/tm_stm32f4_dma.c \
../Src/tm_stm32f4_fonts.c \
../Src/tm_stm32f4_gpio.c \
../Src/tm_stm32f4_ili9341.c \
../Src/tm_stm32f4_rcc.c \
../Src/tm_stm32f4_spi.c \
../Src/tm_stm32f4_spi_dma.c 

OBJS += \
./Src/main.o \
./Src/misc.o \
./Src/stm32f4xx_dma.o \
./Src/stm32f4xx_gpio.o \
./Src/stm32f4xx_rcc.o \
./Src/stm32f4xx_spi.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o \
./Src/tm_stm32f4_dma.o \
./Src/tm_stm32f4_fonts.o \
./Src/tm_stm32f4_gpio.o \
./Src/tm_stm32f4_ili9341.o \
./Src/tm_stm32f4_rcc.o \
./Src/tm_stm32f4_spi.o \
./Src/tm_stm32f4_spi_dma.o 

C_DEPS += \
./Src/main.d \
./Src/misc.d \
./Src/stm32f4xx_dma.d \
./Src/stm32f4xx_gpio.d \
./Src/stm32f4xx_rcc.d \
./Src/stm32f4xx_spi.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d \
./Src/tm_stm32f4_dma.d \
./Src/tm_stm32f4_fonts.d \
./Src/tm_stm32f4_gpio.d \
./Src/tm_stm32f4_ili9341.d \
./Src/tm_stm32f4_rcc.d \
./Src/tm_stm32f4_spi.d \
./Src/tm_stm32f4_spi_dma.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429_439xx -DUSE_STDPERIPH_DRIVER -c -I../Inc -I/Users/harishankar/Desktop/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/STM32F4xx_StdPeriph_Driver/inc -I/Users/harishankar/Desktop/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/CMSIS/Device/ST/STM32F4xx/Include -I/Users/harishankar/Desktop/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/misc.cyclo ./Src/misc.d ./Src/misc.o ./Src/misc.su ./Src/stm32f4xx_dma.cyclo ./Src/stm32f4xx_dma.d ./Src/stm32f4xx_dma.o ./Src/stm32f4xx_dma.su ./Src/stm32f4xx_gpio.cyclo ./Src/stm32f4xx_gpio.d ./Src/stm32f4xx_gpio.o ./Src/stm32f4xx_gpio.su ./Src/stm32f4xx_rcc.cyclo ./Src/stm32f4xx_rcc.d ./Src/stm32f4xx_rcc.o ./Src/stm32f4xx_rcc.su ./Src/stm32f4xx_spi.cyclo ./Src/stm32f4xx_spi.d ./Src/stm32f4xx_spi.o ./Src/stm32f4xx_spi.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f4xx.cyclo ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/system_stm32f4xx.su ./Src/tm_stm32f4_dma.cyclo ./Src/tm_stm32f4_dma.d ./Src/tm_stm32f4_dma.o ./Src/tm_stm32f4_dma.su ./Src/tm_stm32f4_fonts.cyclo ./Src/tm_stm32f4_fonts.d ./Src/tm_stm32f4_fonts.o ./Src/tm_stm32f4_fonts.su ./Src/tm_stm32f4_gpio.cyclo ./Src/tm_stm32f4_gpio.d ./Src/tm_stm32f4_gpio.o ./Src/tm_stm32f4_gpio.su ./Src/tm_stm32f4_ili9341.cyclo ./Src/tm_stm32f4_ili9341.d ./Src/tm_stm32f4_ili9341.o ./Src/tm_stm32f4_ili9341.su ./Src/tm_stm32f4_rcc.cyclo ./Src/tm_stm32f4_rcc.d ./Src/tm_stm32f4_rcc.o ./Src/tm_stm32f4_rcc.su ./Src/tm_stm32f4_spi.cyclo ./Src/tm_stm32f4_spi.d ./Src/tm_stm32f4_spi.o ./Src/tm_stm32f4_spi.su ./Src/tm_stm32f4_spi_dma.cyclo ./Src/tm_stm32f4_spi_dma.d ./Src/tm_stm32f4_spi_dma.o ./Src/tm_stm32f4_spi_dma.su

.PHONY: clean-Src

