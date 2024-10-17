SCOPETYPE = 'OPENADC'
PLATFORM= 'CW308_STM32F4'
SS_VER = 'SS_VER_2_1'

%run "../../chipwhisperer-jupyter/Setup_Scripts/Setup_Generic.ipynb"
%%bash -s "$PLATFORM" "$SS_VER"
cd ./firmware/XTS
make PLATFORM=$1 CRYPTO_TARGET=NONE SS_VER=$2 -j

cw.program_target(scope, prog, "./firmware/XTS/main-{}.hex".format(PLATFORM))

import chipwhisperer as cw
import matplotlib.pyplot as plt
from tqdm import trange
import numpy as np
from time import sleep

def normalize_trace(trace):
    mean = np.mean(trace)
    std = np.std(trace)
    return (trace - mean) / std if std != 0 else trace

def capture_trace(iteration):
    scope.arm()
    #target.simpleserial_write('s', bytearray())  # trigger updateTweak/dblXTS() or c / s / p 
    target.simpleserial_write('s', bytearray([iteration]))  
    ret = scope.capture()
    if ret:
        print("Capture failed")
        # return None
    return scope.get_last_trace()

def truncate(segment):
    return segment[209:225]


def capture_normalize_and_average_traces(num_traces, iteration):
    traces = []
    for _ in trange(num_traces):
        trace = capture_trace(iteration)
        sleep(0.2) 
        if trace is not None:
            normalized_trace = normalize_trace(trace)
            traces.append(normalized_trace)
    return np.mean(traces, axis=0) if traces else None

scope.default_setup()
scope.adc.samples = 24400 #24400 max
scope.clock.adc_src = "clkgen_x1" #clkgen_x1 or clkgen_x4
scope.adc.fifo_fill_mode = "normal"
scope.adc.timeout = 2
reset_target(scope)

yes = np.load("0xffCOMPARISON_SEG2.npy")
no = np.load("0x00COMPARISON_SEG2.npy")

def _128Analyze(inversion_signal, noninversion_signal, total):
    topMostHolder = np.empty(total)
    inverted = truncate(inversion_signal)
    noninverted = truncate(noninversion_signal)  
    for i in range(total):
        singular_segment = capture_normalize_and_average_traces(1, i)
        trunc_seg = truncate(singular_segment)

        val_a = np.corrcoef(inverted, trunc_seg)[0, 1]
        val_b = np.corrcoef(noninverted, trunc_seg)[0, 1]
        
        if val_a > val_b:
            topMostHolder[i] = 1  # Inversion
        else:
            topMostHolder[i] = 0  # No inversion
    
        print(f"Tweak update {i}: Inversion correlation = {val_a}, No Inversion correlation = {val_b}")
    # np.save("inversion_signals2", topMostHolder)
    print(topMostHolder, sep=", ")

# _128Analyze(yes, no, 128) #128 for full sequence

def reconstruct_T0(inversion_results):
    T_0 = [0] * 128

    for n in range(7, 128):
        T_0[n] = inversion_results[127 - n]

    for n in range(2, 7):
        T_0[n] = inversion_results[127 - n] ^ T_0[121 + n]

    T_0[1] = inversion_results[126] ^ T_0[122] ^ T_0[127]
    T_0[0] = inversion_results[127] ^ T_0[121] ^ T_0[127] ^ T_0[126]

    # Fix bit ordering (msb vs. lsb?)
    hex_str = ''
    for i in range(0, len(T_0), 8):
        byte = T_0[i:i+8]
        byte.reverse()
        binary_string = ''.join(str(bit) for bit in byte)
        decimal_value = int(binary_string, 2)
        hex_str += f'{decimal_value:02x}'

    return T_0, hex_str  # Return both the T_0 array and its hexadecimal representation

# reconstruct_T0(BA_test)

# single_segment = capture_normalize_and_average_traces(500, 2)
# np.save("NORMAL_INVERTED_OPTIMIZATIONOFF", single_segment)
# cw.plot(CONTROLL) * cw.plot(NWAY)
# cw.plot(yes) * cw.plot(NWAY)

