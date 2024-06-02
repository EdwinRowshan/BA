import chipwhisperer as cw
import numpy as np
import time

# PLATFORM = CW308_STM32F4
firmware_path = "./Makefiles+HAL/basic-passwdcheck.hex"


try:
    if not scope.connectStatus:
        scope.con()
except NameError:
    scope = cw.scope()
   
try:
    target = cw.target(scope)
except IOError:
    print("INFO: Caught exception on reconnecting to target - attempting to reconnect to scope first.")
    print("INFO: This is a work-around when USB has died without Python knowing. Ignore errors above this line.")
    scope = cw.scope()
    target = cw.target(scope)

print("INFO: Found ChipWhisperer😍")

prog = cw.programmers.STM32FProgrammer

time.sleep(0.05)
scope.default_setup()

def reset_target(scope): 
    scope.io.nrst = 'low'
    time.sleep(0.05)
    scope.io.nrst = 'high_z'
    time.sleep(0.05)

#FLASH FIRMWARE HERE INSTEAD OF USING SELF WRITTEN FLASHER
cw.program_target(scope, prog, firmware_path)

def cap_pass_trace(pass_guess):
    reset_target(scope)
    num_char = target.in_waiting()
    while num_char > 0:
        target.read(num_char, 10)
        time.sleep(0.01)
        num_char = target.in_waiting()

    scope.arm()
    target.write(pass_guess)
    ret = scope.capture()
    if ret:
        print('Timeout happened during acquisition')

    trace = scope.get_last_trace()
    return trace

def attack():
    guessed_pw = ""

    for _ in range(0, 5):  
        biggest_diff = 0
        biggest_char = '\x00'
        ref_trace = cap_pass_trace(guessed_pw + "\x00\n")
        
        for c in 'abcdefghijklmnopqrstuvwxyz0123456789': 
            trace = cap_pass_trace(guessed_pw + c + "\n")
            diff = np.sum(np.abs(trace - ref_trace))

            if diff > biggest_diff:
                biggest_diff = diff
                biggest_char = c
                
        guessed_pw += biggest_char
        print(guessed_pw)

if __name__ == "__main__":
    attack()