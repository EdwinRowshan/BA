import argparse
import serial

def main():
    #Prase arguments
    parser = argparse.ArgumentParser(description= "CWSTM32FFlasher")
    parser.add_argument('--hexfile', required=True, help="path to hex to flash")
    parser.add_argument('--port', required=True, help="Port where STM32F is connected")
    args = parser.parse_args()

    hexfile = args.hexfile
    serial_port = args.port

    #Create serial... with default values 
    ser = serial.Serial(port=serial_port, baudrate=115200, parity=serial.PARITY_EVEN, stopbits=serial.STOPBITS_ONE, timeout=1)
    
    #Create flasher object with our serial port assigned
    flasher = STM32FSerial(cwserial = ser)
    
    #AUTOPROGRAMMER OPENS PORT AUTOMATICALLY, WITHOUT AUTOPROGRAM ONLY USING PROGRAM WE NEED TO CALL OTHER FUNCTIONS SEPARATELY 
    try:
        # Automatically program the device
        success = flasher.autoProgram(hexfile)
        if success:
            print("It worked")
        else:
            print("As expected")
    except Exception as e:
        print(f"Some bullshit happened: {e}")
    

if __name__ == "__main__":
    main()

