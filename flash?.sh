#!/bin/bash

# Navigate to the makefile dir
cd /path/to/project

make clean

make all 

make program

echo "this should work and flash the software onto the stm32"

#chmod +x flash_firmware.sh set it executable and then ./flash_firmware. 
