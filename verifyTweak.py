import numpy as np
# def dblXTS(T, cycles):
#     verif = np.zeros(128, dtype=int)  
#     for cycle in range(cycles):  # Perform specified number of cycles
#         Cin = 0
#         for i in range(16):
#             Cout = (T[i] >> 7) & 1
#             T[i] = ((T[i] << 1) + Cin) & 0xFF
#             Cin = Cout
#         print(hex(T[0]))
#         if Cout == 1:
#             T[0] ^= 0x87
#             print(f"Update {cycle} YES inversion")
#         else:
#             print(f"Update {cycle} NO inversion")

def dblXTS(T):
    verif = np.zeros(128, dtype=int)  
    for cycle in range(128): 
        Cin = 0
        for i in range(16):
            Cout = (T[i] >> 7) & 1
            T[i] = ((T[i] << 1) + Cin) & 0xFF
            Cin = Cout
        print(f"Cycle: {cycle}, Cout: {Cout}, Cin: {Cin}, T[0]: {hex(T[0])}")
        if Cout == 1:
            T[0] ^= 0x87
            verif[cycle] = 1  # Assign 1 at the current cycle position
            print(f"Update {cycle} YES inversion")
        else:
            verif[cycle] = 0  # Assign 0 at the current cycle position
            print(f"Update {cycle} NO inversion")
    print("Final verif array:", verif, "SIZE", len(verif))
    return verif

tweak = [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff]
tweak2 = [0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa]
tweak3 = [0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55]
tweak4 = [0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
encrypted0x00 = [0x6d, 0xcf, 0xba, 0x21, 0x2f, 0x5d, 0x82, 0xbf, 0x52, 0x5e, 0xe9, 0x79, 0x3c, 0xfa, 0x50, 0x5a]
encrypted0xff = [0x6d, 0xb7, 0xe5, 0xec, 0xa2, 0x84, 0x95, 0x7e, 0x9c, 0x1f, 0x63, 0x0b, 0x8a, 0x5e, 0x98, 0x6c]

# CWbytearray(b'4a 01 83 3a eb 14 99 fb 8f 87 f1 fb 7c 64 08 76')
firstTestPre = [0xe0, 0x41, 0xa9, 0xf1, 0x7e, 0xc8, 0xf0, 0x81, 0x99, 0xa2, 0xd3, 0x14, 0xee, 0x4c, 0x18, 0x4a]
firstTestT_0 = [0x4a, 0x01, 0x83, 0x3a, 0xeb, 0x14, 0x99, 0xfb, 0x8f, 0x87, 0xf1, 0xfb, 0x7c, 0x64, 0x08, 0x76]
# CWbytearray(b'83 95 51 d6 f8 b3 4c 3e 56 ab 4f 48 ae 2d a6 ce')
secondTestPre = [0x14, 0x3f, 0x9a, 0x76, 0xb2, 0xc7, 0xd9, 0x45, 0x1e, 0x88, 0x32, 0xff, 0x62, 0xa4, 0x3c, 0x7e]
secondTestT_0 = [0x83, 0x95, 0x51, 0xd6, 0xf8, 0xb3, 0x4c, 0x3e, 0x56, 0xab, 0x4f, 0x48, 0xae, 0x2d, 0xa6, 0xce]
#839551d6f8b34c3e56ab4f48ae2da6ce
# results = dblXTS(firstTestT_0)

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

    hex_bytes = [f'0x{hex_str[i:i+2]}' for i in range(0, len(hex_str), 2)]
    return T_0, ', '.join(hex_bytes)

BA_test = [0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 
           1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 
           0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 
           1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 
           1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 
           0, 0, 0]

print(reconstruct_T0(BA_test))

# np.save("secondTestControl", results)
# c[256] = [reference_signals]
# c[0] = ref_sig_0x00
# c[1] = ref_sig0x01
# ... 0x00 - 0xff

# def _128Analyze(inversion_signal, noninversion_signal, total):
#     topMostHolder = np.empty(total)
#     for i in range(total):
        
#         singular_segment = capture_normalize_and_average_traces(250, i) 
#         trunc_seg = truncate(singular_segment)

#         peak = 0
#         out = 0
#         for i, ref_sig in enumerate(c):
#             ref_sig_trunc = truncate(ref_sig)
#             corr = np.corrcoef(ref_sig_trunc, trunc_seg)
#             if corr > peak: 
#                 peak = corr
#                 out = i

#         print(f"Tweak byte = {out}")
#     print(topMostHolder)

# _128Analyze(pre_gen0xaa, pre_gen0x55, 5) #128 for full sequence
