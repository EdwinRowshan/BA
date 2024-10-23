XTS-AES Power Analysis (Final)

In fulfillment for the requirements of the degree 'Bachelor of Science' in Computer Science (Informatik) at TU Berlin under StuPO 2015. 

This repository contains the files related to my work. The project includes modified XTS firmware, analysis scripts, and trace collection utilities.

Structure
XTS/: Contains modified firmware files for XTS-AES implementation on STM32F4. NEEDS TO BE PLACED INSIDE FIRMWARE FOLDER OF CHIPWHISPERER (See CW GitHub).
traces/: Contains power traces used for analysis as well as the reference traces for our analysis to work (Cross Correlation Analysis)

FULL_ATTACK.py: Main script for conducting the power analysis attack.
trace_script.py: Helper script to generate SVGs for our work. 
verifyTweak.py: Script used for verifying the correct tweak value and also aided us during the process.
Usage
preliminary: Contains all the code that needs to be run BEFORE anything happens (Do this after you connected your hardware).

Make files had to be modified but are also provided, the concrete directory structure of that can be inferred from looking at the firmware folder (and hal) on the CW GitHub. 

Attack Execution: _128Analyze() will generate the reconstruction array. This needs to be saved (however you see fit) and then feed this value the function reconstruct_T0() which will then deliver the accurately rebuilt tweak T_0. 

The two folders contain empty files named FINAL so that I could easily get the final commit message as the main message for the overview. 

For more details, please refer to the thesis itself (I'm not sure if I can upload it here, request it by mail edwinrowshan@gmail.com).  
