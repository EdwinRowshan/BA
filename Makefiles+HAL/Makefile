# Set HAL path
HALPATH = ./stm32f4

# Include Makefile.hal 
include ./hal/Makefile.hal

# Target file name (without extension)
TARGET = basic-passwdcheck

# Source files (only basic-passwdcheck.c here)
SRC = basic-passwdcheck.c

# Include directories
INCLUDES = -I. -I./hal -I$(HALPATH) -I$(HALPATH)/CMSIS/Include -I$(HALPATH)/CMSIS/Device/ST/STM32F4xx/Include -I$(HALPATH)/Legacy

# Compiler settings
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# Output format
FORMAT = ihex

# Source object files
OBJ = $(SRC:.c=.o)

# Build rules
all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O $(FORMAT) $< $@

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(OBJ)

.PHONY: all clean

