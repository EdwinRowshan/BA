# BA

Bachelor of Science Computer Science (TU Berlin) 

Thesis: Breaking XTS-AES Encryption via Side Channel Attack: Power Analysis on Horizontal Modular Multiplication

In the file FULL_ATTACK.py you will find all the relevant information (that and reading my thesis ofc). The firmware folder contains a folder named XTS, where the actual XTS-AES implementation resides, the main.cpp can be modified for different tweaks and the GF128.cpp contains the actual horizontal modular multiplication (tweak updating) itself which can also be tweaked in numerous ways such as introducing a counter method. The .npy files are all the traces I took and saved during the entire process and two of them specifically are used in the attack (yes.npy, no.npy).

As for the attack itself, _128Analyze will spit out the reconstruction array, you need to hammer this into reconstruct_T0 which will then deliver the original T_0 value. I'm pretty sure you can modify it so that it directly saves it as an array or whatever, but alas my hands are tied and I can no longer bear the burden of having to deal with any of this anymore. single_segment delivers a singular tweak update specified by the number and the bigger number indicates how many traces you want averaged to reduce noise or whatever. (The program works even if you use a singular trace instead of averaging out idk 500 or sum). 
