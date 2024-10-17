   1              		.cpu cortex-m4
   2              		.eabi_attribute 20, 1
   3              		.eabi_attribute 21, 1
   4              		.eabi_attribute 23, 3
   5              		.eabi_attribute 24, 1
   6              		.eabi_attribute 25, 1
   7              		.eabi_attribute 26, 1
   8              		.eabi_attribute 30, 4
   9              		.eabi_attribute 34, 1
  10              		.eabi_attribute 18, 4
  11              		.file	"main.cpp"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text.led_ok,"ax",%progbits
  16              		.align	1
  17              		.weak	led_ok
  18              		.arch armv7e-m
  19              		.syntax unified
  20              		.thumb
  21              		.thumb_func
  22              		.fpu softvfp
  24              	led_ok:
  25              		.fnstart
  26              	.LVL0:
  27              	.LFB1561:
  28              		.file 1 ".././hal/hal.h"
   1:.././hal/hal.h **** /*
   2:.././hal/hal.h ****     This file is part of the ChipWhisperer Example Targets
   3:.././hal/hal.h ****     Copyright (C) 2012-2015 NewAE Technology Inc.
   4:.././hal/hal.h **** 
   5:.././hal/hal.h ****     This program is free software: you can redistribute it and/or modify
   6:.././hal/hal.h ****     it under the terms of the GNU General Public License as published by
   7:.././hal/hal.h ****     the Free Software Foundation, either version 3 of the License, or
   8:.././hal/hal.h ****     (at your option) any later version.
   9:.././hal/hal.h **** 
  10:.././hal/hal.h ****     This program is distributed in the hope that it will be useful,
  11:.././hal/hal.h ****     but WITHOUT ANY WARRANTY; without even the implied warranty of
  12:.././hal/hal.h ****     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  13:.././hal/hal.h ****     GNU General Public License for more details.
  14:.././hal/hal.h **** 
  15:.././hal/hal.h ****     You should have received a copy of the GNU General Public License
  16:.././hal/hal.h ****     along with this program.  If not, see <http://www.gnu.org/licenses/>.
  17:.././hal/hal.h **** */
  18:.././hal/hal.h **** 
  19:.././hal/hal.h **** #ifndef HAL_H_
  20:.././hal/hal.h **** #define HAL_H_
  21:.././hal/hal.h **** 
  22:.././hal/hal.h **** #include <stdint.h>
  23:.././hal/hal.h **** 
  24:.././hal/hal.h **** void platform_init(void);
  25:.././hal/hal.h **** 
  26:.././hal/hal.h **** //PLATFORM Define Types
  27:.././hal/hal.h **** #define CW301_AVR      1
  28:.././hal/hal.h **** #define CW301_XMEGA    2
  29:.././hal/hal.h **** #define CW303          3
  30:.././hal/hal.h **** #define CW304          4
  31:.././hal/hal.h **** #define CW308_MEGARF   8
  32:.././hal/hal.h **** #define CW308_PIC24FJ  10
  33:.././hal/hal.h **** #define CW308_SAM4L    11
  34:.././hal/hal.h **** #define CW308_SI4010   12
  35:.././hal/hal.h **** #define CW308_MPC5748G 13
  36:.././hal/hal.h **** #define CW308_STM32F0  14
  37:.././hal/hal.h **** #define CW308_STM32F1  15
  38:.././hal/hal.h **** #define CW308_STM32F2  16
  39:.././hal/hal.h **** #define CW308_STM32F3  17
  40:.././hal/hal.h **** #define CW308_STM32F4  18
  41:.././hal/hal.h **** #define CW308_CC2538   19
  42:.././hal/hal.h **** #define CW308_K24F     20
  43:.././hal/hal.h **** #define CW308_NRF52840 21
  44:.././hal/hal.h **** #define CW308_AURIX    22
  45:.././hal/hal.h **** #define CW308_SAML11   23
  46:.././hal/hal.h **** #define CW308_EFM32TG11B 24
  47:.././hal/hal.h **** #define CW308_K82F     25
  48:.././hal/hal.h **** #define CW308_LPC55S6X 26
  49:.././hal/hal.h **** #define CW308_PSOC62   27
  50:.././hal/hal.h **** #define CW308_IMXRT1062 28
  51:.././hal/hal.h **** #define CW308_FE310    29
  52:.././hal/hal.h **** #define CW308_EFR32MG21A  30
  53:.././hal/hal.h **** #define CW308_EFM32GG11  31
  54:.././hal/hal.h **** #define CW308_STM32L5  32
  55:.././hal/hal.h **** #define CW308_STM32L4  33
  56:.././hal/hal.h **** #define CW308_RX65N  34
  57:.././hal/hal.h **** #define CW308_MPC5676R 35
  58:.././hal/hal.h **** #define CW308_NEORV32  36
  59:.././hal/hal.h **** #define CW305_IBEX  37
  60:.././hal/hal.h **** 
  61:.././hal/hal.h **** //HAL_TYPE Define Types
  62:.././hal/hal.h **** #define HAL_avr      1
  63:.././hal/hal.h **** #define HAL_xmega    2
  64:.././hal/hal.h **** #define HAL_pic24f   3
  65:.././hal/hal.h **** #define HAL_sam4l    4
  66:.././hal/hal.h **** #define HAL_stm32f0  5
  67:.././hal/hal.h **** #define HAL_stm32f1  6
  68:.././hal/hal.h **** #define HAL_stm32f2  7
  69:.././hal/hal.h **** #define HAL_stm32f3  8
  70:.././hal/hal.h **** #define HAL_stm32f4  9
  71:.././hal/hal.h **** #define HAL_cc2538   10
  72:.././hal/hal.h **** #define HAL_k24f     11
  73:.././hal/hal.h **** #define HAL_nrf52840 12
  74:.././hal/hal.h **** #define HAL_stm32f0_nano 13
  75:.././hal/hal.h **** #define HAL_aurix    14
  76:.././hal/hal.h **** #define HAL_saml11   15
  77:.././hal/hal.h **** #define HAL_efm32tg11b 16
  78:.././hal/hal.h **** #define HAL_k82f     17
  79:.././hal/hal.h **** #define HAL_lpc55s6x 18
  80:.././hal/hal.h **** #define HAL_psoc62   19
  81:.././hal/hal.h **** #define HAL_imxrt1062 20
  82:.././hal/hal.h **** #define HAL_fe310    21
  83:.././hal/hal.h **** #define HAL_efr32mg21a 22
  84:.././hal/hal.h **** #define HAL_efm32gg11 23
  85:.././hal/hal.h **** #define HAL_stm32l5 24
  86:.././hal/hal.h **** #define HAL_stm32l4 25
  87:.././hal/hal.h **** #define HAL_rx65n 26
  88:.././hal/hal.h **** #define HAL_mpc5676r 27
  89:.././hal/hal.h **** #define HAL_neorv32  28
  90:.././hal/hal.h **** #define HAL_sam4s  29
  91:.././hal/hal.h **** #define HAL_ibex  30
  92:.././hal/hal.h **** 
  93:.././hal/hal.h **** #if HAL_TYPE == HAL_avr
  94:.././hal/hal.h ****     #include <avr/io.h>
  95:.././hal/hal.h ****     #include <util/delay.h>
  96:.././hal/hal.h ****     #include "avr/avr_hal.h"
  97:.././hal/hal.h **** #elif HAL_TYPE == HAL_xmega
  98:.././hal/hal.h ****     #include <avr/io.h>
  99:.././hal/hal.h ****     #include <util/delay.h>
 100:.././hal/hal.h ****     #include "xmega/xmega_hal.h"
 101:.././hal/hal.h ****     #include "xmega/avr_compiler.h"
 102:.././hal/hal.h **** #elif HAL_TYPE == HAL_pic24f
 103:.././hal/hal.h ****     #include <xc.h>
 104:.././hal/hal.h ****     #include "pic24f/pic24f_hal.h"
 105:.././hal/hal.h ****     #include "pic24f/uart.h"
 106:.././hal/hal.h **** #elif HAL_TYPE == HAL_sam4l
 107:.././hal/hal.h ****     #include "sam4l/sam4l_hal.h"
 108:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32f0
 109:.././hal/hal.h **** 	#include "stm32f0/stm32f0_hal.h"
 110:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32f1
 111:.././hal/hal.h **** 	#include "stm32f1/stm32f1_hal.h"
 112:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32f2
 113:.././hal/hal.h **** 	#include "stm32f2/stm32f2_hal.h"
 114:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32f3
 115:.././hal/hal.h **** 	#include "stm32f3/stm32f3_hal.h"
 116:.././hal/hal.h **** 	#ifdef SECCAN
 117:.././hal/hal.h **** 		#include "stm32f3/stm32f3_hal_seccan.h"
 118:.././hal/hal.h **** 	#endif
 119:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32f4
 120:.././hal/hal.h **** 	#include "stm32f4/stm32f4_hal.h"
 121:.././hal/hal.h **** #elif HAL_TYPE == HAL_cc2538
 122:.././hal/hal.h **** 	#include "cc2538/cc2538_hal.h"
 123:.././hal/hal.h **** #elif HAL_TYPE == HAL_k24f
 124:.././hal/hal.h ****     #include "k24f/k24f_hal.h"
 125:.././hal/hal.h **** #elif HAL_TYPE == HAL_k82f
 126:.././hal/hal.h **** #include "k82f/k82f_hal.h"
 127:.././hal/hal.h **** #elif HAL_TYPE == HAL_nrf52840
 128:.././hal/hal.h ****     #include "nrf52840/nrf52840_hal.h"   
 129:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32f0_nano
 130:.././hal/hal.h ****     #include "stm32f0/stm32f0_hal.h" 
 131:.././hal/hal.h ****     void led_error(unsigned int status);
 132:.././hal/hal.h ****     void led_ok(unsigned int status);
 133:.././hal/hal.h **** #elif HAL_TYPE == HAL_aurix
 134:.././hal/hal.h ****     #include "aurix/aurix_hal.h"
 135:.././hal/hal.h **** #elif HAL_TYPE == HAL_saml11
 136:.././hal/hal.h ****      #include "saml11/saml11_hal.h"
 137:.././hal/hal.h **** #elif HAL_TYPE == HAL_efm32tg11b
 138:.././hal/hal.h ****      #include "efm32tg11b/efm32tg11b_hal.h"
 139:.././hal/hal.h **** #elif HAL_TYPE == HAL_lpc55s6x
 140:.././hal/hal.h ****      #include "lpc55s6x/lpc55s6x_hal.h"
 141:.././hal/hal.h **** #elif HAL_TYPE == HAL_psoc62
 142:.././hal/hal.h ****     #include "psoc62/psoc62_hal.h"
 143:.././hal/hal.h **** #elif HAL_TYPE == HAL_imxrt1062
 144:.././hal/hal.h ****     #include "imxrt1062/imxrt1062_hal.h"
 145:.././hal/hal.h **** #elif HAL_TYPE == HAL_fe310
 146:.././hal/hal.h ****     #include "fe310/fe310_hal.h"
 147:.././hal/hal.h **** #elif HAL_TYPE == HAL_efr32mg21a
 148:.././hal/hal.h ****     #include "efr32mg21a/efr32mg21a_hal.h"
 149:.././hal/hal.h **** #elif HAL_TYPE == HAL_efm32gg11
 150:.././hal/hal.h ****     #include "efm32gg11/efm32gg11_hal.h"
 151:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32l5
 152:.././hal/hal.h ****     #include "stm32l5/stm32l5_hal.h"
 153:.././hal/hal.h **** #elif HAL_TYPE == HAL_stm32l4
 154:.././hal/hal.h ****     #include "stm32l4/stm32l4_hal.h"
 155:.././hal/hal.h **** #elif HAL_TYPE == HAL_rx65n
 156:.././hal/hal.h ****     #include "rx65n/rx65n_hal.h"
 157:.././hal/hal.h **** #elif HAL_TYPE == HAL_mpc5676r
 158:.././hal/hal.h ****     #include "mpc5676r/MPC5676R_hal.h"
 159:.././hal/hal.h **** #elif HAL_TYPE == HAL_neorv32
 160:.././hal/hal.h ****     #include "neorv32/neorv32_hal.h"
 161:.././hal/hal.h **** #elif HAL_TYPE == HAL_sam4s
 162:.././hal/hal.h ****     #include "sam4s/sam4s_hal.h"
 163:.././hal/hal.h **** #elif HAL_TYPE == HAL_ibex
 164:.././hal/hal.h ****     #include "ibex/ibex_hal.h"
 165:.././hal/hal.h **** #else
 166:.././hal/hal.h ****     #error "Unsupported HAL Type"
 167:.././hal/hal.h **** #endif
 168:.././hal/hal.h **** 
 169:.././hal/hal.h **** #if PLATFORM == CW308_MEGARF
 170:.././hal/hal.h ****     #undef trigger_setup
 171:.././hal/hal.h ****     #undef trigger_high
 172:.././hal/hal.h ****     #undef trigger_low
 173:.././hal/hal.h ****     #define trigger_setup() DDRD |= 0x02
 174:.././hal/hal.h ****     #define trigger_high()  PORTD |= 0x02
 175:.././hal/hal.h ****     #define trigger_low()   PORTD &= ~(0x02)
 176:.././hal/hal.h ****     
 177:.././hal/hal.h ****     #define HW_AES128_Init();      AES_CTRL = 0x00;
 178:.././hal/hal.h **** 
 179:.././hal/hal.h ****     #define HW_AES128_LoadKey(key);  for (uint8_t i = 0; i < 16; i++){ \
 180:.././hal/hal.h ****                                      AES_KEY = *(key+i); \
 181:.././hal/hal.h ****                                   }
 182:.././hal/hal.h **** 
 183:.././hal/hal.h ****     #define HW_AES128_Enc(pt);  for (uint8_t i = 0; i < 16; i++){ \
 184:.././hal/hal.h ****                                     AES_STATE = *(pt+i); \
 185:.././hal/hal.h ****                                 } \
 186:.././hal/hal.h ****                                   \
 187:.././hal/hal.h ****                                 AES_CTRL |= 1<<AES_REQUEST; \
 188:.././hal/hal.h ****                                   \
 189:.././hal/hal.h ****                                 /*Wait for done  */ \
 190:.././hal/hal.h ****                                 while ((AES_STATUS & (1<<AES_DONE)) == 0){ \
 191:.././hal/hal.h ****                                     ; \
 192:.././hal/hal.h ****                                 } \
 193:.././hal/hal.h ****                                   \
 194:.././hal/hal.h ****                                 for (uint8_t i = 0; i < 16; i++){ \
 195:.././hal/hal.h ****                                     *(pt+i) = AES_STATE; \
 196:.././hal/hal.h ****                                 }
 197:.././hal/hal.h ****     
 198:.././hal/hal.h **** #endif
 199:.././hal/hal.h **** 
 200:.././hal/hal.h **** __attribute__((weak)) void led_ok(unsigned int status)
 201:.././hal/hal.h **** {
  29              		.loc 1 201 1 view -0
  30              		.cfi_startproc
  31              		@ args = 0, pretend = 0, frame = 0
  32              		@ frame_needed = 0, uses_anonymous_args = 0
  33              		@ link register save eliminated.
 202:.././hal/hal.h **** }
  34              		.loc 1 202 1 is_stmt 0 view .LVU1
  35 0000 7047     		bx	lr
  36              		.cfi_endproc
  37              	.LFE1561:
  38              		.cantunwind
  39              		.fnend
  41              		.section	.text.led_error,"ax",%progbits
  42              		.align	1
  43              		.weak	led_error
  44              		.syntax unified
  45              		.thumb
  46              		.thumb_func
  47              		.fpu softvfp
  49              	led_error:
  50              		.fnstart
  51              	.LFB2069:
  52              		.cfi_startproc
  53              		@ args = 0, pretend = 0, frame = 0
  54              		@ frame_needed = 0, uses_anonymous_args = 0
  55              		@ link register save eliminated.
  56 0000 7047     		bx	lr
  57              		.cfi_endproc
  58              	.LFE2069:
  59              		.cantunwind
  60              		.fnend
  62              		.section	.text._Z11updateTweakPm,"ax",%progbits
  63              		.align	1
  64              		.global	_Z11updateTweakPm
  65              		.syntax unified
  66              		.thumb
  67              		.thumb_func
  68              		.fpu softvfp
  70              	_Z11updateTweakPm:
  71              		.fnstart
  72              	.LVL1:
  73              	.LFB1563:
  74              		.file 2 "main.cpp"
   1:main.cpp      **** #include "XTS.h"
   2:main.cpp      **** #include "BlockCipher.h"
   3:main.cpp      **** #include <cstdint>
   4:main.cpp      **** #include "AES.h"
   5:main.cpp      **** #include "GF128.h"
   6:main.cpp      **** #include "EndianUtil.h"
   7:main.cpp      **** #include <iostream>
   8:main.cpp      **** #define MAX_SECTOR_SIZE 2048
   9:main.cpp      **** //default 64
  10:main.cpp      **** #include <cstring>
  11:main.cpp      **** extern "C" {
  12:main.cpp      ****     #include "simpleserial.h"
  13:main.cpp      ****     #include "hal.h"
  14:main.cpp      **** }
  15:main.cpp      **** //#define SS_VER SS_VER_2_1
  16:main.cpp      **** 
  17:main.cpp      **** typedef unsigned char byte;
  18:main.cpp      **** 
  19:main.cpp      **** struct TestVector
  20:main.cpp      **** {
  21:main.cpp      ****     const char *name;
  22:main.cpp      ****     byte key1[16];
  23:main.cpp      ****     byte key2[16];
  24:main.cpp      ****     byte plaintext[MAX_SECTOR_SIZE];
  25:main.cpp      ****     byte ciphertext[MAX_SECTOR_SIZE];
  26:main.cpp      ****     byte tweak[16];
  27:main.cpp      ****     size_t sectorSize;
  28:main.cpp      **** };
  29:main.cpp      **** 
  30:main.cpp      **** static const struct TestVector testVectorXTSAES128_1 = {
  31:main.cpp      ****     .name        = "XTS-AES-128 #1",
  32:main.cpp      ****     .key1        = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  33:main.cpp      ****                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  34:main.cpp      ****     .key2        = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  35:main.cpp      ****                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  36:main.cpp      ****     .plaintext   = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  37:main.cpp      ****                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  38:main.cpp      ****                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  39:main.cpp      ****                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  40:main.cpp      ****     .ciphertext  = {0x91, 0x7c, 0xf6, 0x9e, 0xbd, 0x68, 0xb2, 0xec,
  41:main.cpp      ****                     0x9b, 0x9f, 0xe9, 0xa3, 0xea, 0xdd, 0xa6, 0x92,
  42:main.cpp      ****                     0xcd, 0x43, 0xd2, 0xf5, 0x95, 0x98, 0xed, 0x85,
  43:main.cpp      ****                     0x8c, 0x02, 0xc2, 0x65, 0x2f, 0xbf, 0x92, 0x2e},
  44:main.cpp      ****     .tweak       = {0x00},
  45:main.cpp      ****     .sectorSize  = 32
  46:main.cpp      **** };
  47:main.cpp      **** static const struct TestVector testVectorXTSAES128_2  = {
  48:main.cpp      ****     .name        = "XTS-AES-128 #2",
  49:main.cpp      ****     .key1        = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
  50:main.cpp      ****                     0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11},
  51:main.cpp      ****     .key2        = {0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
  52:main.cpp      ****                     0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22},
  53:main.cpp      ****     .plaintext   = {0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
  54:main.cpp      ****                     0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
  55:main.cpp      ****                     0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
  56:main.cpp      ****                     0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44},
  57:main.cpp      ****     .ciphertext  = {0xc4, 0x54, 0x18, 0x5e, 0x6a, 0x16, 0x93, 0x6e,
  58:main.cpp      ****                     0x39, 0x33, 0x40, 0x38, 0xac, 0xef, 0x83, 0x8b,
  59:main.cpp      ****                     0xfb, 0x18, 0x6f, 0xff, 0x74, 0x80, 0xad, 0xc4,
  60:main.cpp      ****                     0x28, 0x93, 0x82, 0xec, 0xd6, 0xd3, 0x94, 0xf0},
  61:main.cpp      ****     .tweak       = {0x33, 0x33, 0x33, 0x33, 0x33},
  62:main.cpp      ****     .sectorSize  = 32
  63:main.cpp      **** };
  64:main.cpp      **** static const struct TestVector testVectorXTSAES128_3  = {
  65:main.cpp      ****     .name        = "XTS-AES-128 #3",
  66:main.cpp      ****     .key1        = {0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
  67:main.cpp      ****                     0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0},
  68:main.cpp      ****     .key2        = {0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
  69:main.cpp      ****                     0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22},
  70:main.cpp      ****     .plaintext   = {0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
  71:main.cpp      ****                     0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
  72:main.cpp      ****                     0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
  73:main.cpp      ****                     0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44},
  74:main.cpp      ****     .ciphertext  = {0xaf, 0x85, 0x33, 0x6b, 0x59, 0x7a, 0xfc, 0x1a,
  75:main.cpp      ****                     0x90, 0x0b, 0x2e, 0xb2, 0x1e, 0xc9, 0x49, 0xd2,
  76:main.cpp      ****                     0x92, 0xdf, 0x4c, 0x04, 0x7e, 0x0b, 0x21, 0x53,
  77:main.cpp      ****                     0x21, 0x86, 0xa5, 0x97, 0x1a, 0x22, 0x7a, 0x89},
  78:main.cpp      ****     .tweak       = {0x33, 0x33, 0x33, 0x33, 0x33},
  79:main.cpp      ****     .sectorSize  = 32
  80:main.cpp      **** };
  81:main.cpp      **** static const struct TestVector testVectorXTSAES128_4 = {
  82:main.cpp      ****     // 512 byte test vector from the spec truncated to the first 64 bytes.
  83:main.cpp      ****     .name        = "XTS-AES-128 #4",
  84:main.cpp      ****     .key1        = {0x27, 0x18, 0x28, 0x18, 0x28, 0x45, 0x90, 0x45,
  85:main.cpp      ****                     0x23, 0x53, 0x60, 0x28, 0x74, 0x71, 0x35, 0x26},
  86:main.cpp      ****     .key2        = {0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
  87:main.cpp      ****                     0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95},
  88:main.cpp      ****     .plaintext   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  89:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  90:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
  91:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
  92:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
  93:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  94:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
  95:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f},
  96:main.cpp      ****     .ciphertext  = {0x27, 0xa7, 0x47, 0x9b, 0xef, 0xa1, 0xd4, 0x76,
  97:main.cpp      ****                     0x48, 0x9f, 0x30, 0x8c, 0xd4, 0xcf, 0xa6, 0xe2,
  98:main.cpp      ****                     0xa9, 0x6e, 0x4b, 0xbe, 0x32, 0x08, 0xff, 0x25,
  99:main.cpp      ****                     0x28, 0x7d, 0xd3, 0x81, 0x96, 0x16, 0xe8, 0x9c,
 100:main.cpp      ****                     0xc7, 0x8c, 0xf7, 0xf5, 0xe5, 0x43, 0x44, 0x5f,
 101:main.cpp      ****                     0x83, 0x33, 0xd8, 0xfa, 0x7f, 0x56, 0x00, 0x00,
 102:main.cpp      ****                     0x05, 0x27, 0x9f, 0xa5, 0xd8, 0xb5, 0xe4, 0xad,
 103:main.cpp      ****                     0x40, 0xe7, 0x36, 0xdd, 0xb4, 0xd3, 0x54, 0x12},
 104:main.cpp      ****     .tweak       = {0x00},
 105:main.cpp      ****     .sectorSize  = 64
 106:main.cpp      **** };
 107:main.cpp      **** static const struct TestVector testVectorXTSAES128_15  = {
 108:main.cpp      ****     .name        = "XTS-AES-128 #15",
 109:main.cpp      ****     .key1        = {0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
 110:main.cpp      ****                     0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0},
 111:main.cpp      ****     .key2        = {0xbf, 0xbe, 0xbd, 0xbc, 0xbb, 0xba, 0xb9, 0xb8,
 112:main.cpp      ****                     0xb7, 0xb6, 0xb5, 0xb4, 0xb3, 0xb2, 0xb1, 0xb0},
 113:main.cpp      ****     .plaintext   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 114:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 115:main.cpp      ****                     0x10},
 116:main.cpp      ****     .ciphertext  = {0x6c, 0x16, 0x25, 0xdb, 0x46, 0x71, 0x52, 0x2d,
 117:main.cpp      ****                     0x3d, 0x75, 0x99, 0x60, 0x1d, 0xe7, 0xca, 0x09,
 118:main.cpp      ****                     0xed},
 119:main.cpp      ****     .tweak       = {0x9a, 0x78, 0x56, 0x34, 0x12},
 120:main.cpp      ****     .sectorSize  = 17
 121:main.cpp      **** };
 122:main.cpp      **** // This test vector is from:
 123:main.cpp      **** // https://github.com/heisencoder/XTS-AES/blob/master/testvals/xts.4
 124:main.cpp      **** // We use this one because the main specification doesn't have an odd
 125:main.cpp      **** // block size greater than 32 bytes but less than 64 bytes.
 126:main.cpp      **** static const struct TestVector testVectorXTSAES128_16  = {
 127:main.cpp      ****     .name        = "XTS-AES-128 #16",
 128:main.cpp      ****     .key1        = {0x27, 0x18, 0x28, 0x18, 0x28, 0x45, 0x90, 0x45,
 129:main.cpp      ****                     0x23, 0x53, 0x60, 0x28, 0x74, 0x71, 0x35, 0x26},
 130:main.cpp      ****     .key2        = {0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
 131:main.cpp      ****                     0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95},
 132:main.cpp      ****     .plaintext   = {0x50, 0x00, 0xec, 0xa5, 0xa1, 0xf6, 0xa4, 0x93,
 133:main.cpp      ****                     0x78, 0x03, 0x0d, 0x9e, 0xe8, 0x05, 0xac, 0xef,
 134:main.cpp      ****                     0x46, 0x0f, 0x31, 0x4e, 0xe0, 0x4b, 0xb5, 0x14,
 135:main.cpp      ****                     0x03, 0x4e, 0xb2, 0x7f, 0xb8, 0xdf, 0x2b, 0xc8,
 136:main.cpp      ****                     0x12, 0xae, 0x5b, 0xdf, 0x8c},
 137:main.cpp      ****     .ciphertext  = {0xe5, 0x9e, 0x6f, 0x23, 0x3b, 0xe0, 0xe0, 0x83,
 138:main.cpp      ****                     0x04, 0x83, 0xc6, 0xbd, 0x4e, 0x82, 0xf4, 0xc3,
 139:main.cpp      ****                     0x95, 0x43, 0x55, 0x8a, 0x25, 0xe3, 0xdb, 0x60,
 140:main.cpp      ****                     0xa5, 0x53, 0xa5, 0x94, 0x81, 0x45, 0xa6, 0xff,
 141:main.cpp      ****                     0xb5, 0xe6, 0xbe, 0x1d, 0xb5},
 142:main.cpp      ****     .tweak       = {0x33, 0x22, 0x11, 0x00},
 143:main.cpp      ****     .sectorSize  = 37
 144:main.cpp      **** };
 145:main.cpp      **** //ciphertext 128_16 first entry original: 0xe5, sanity test: 0x52
 146:main.cpp      **** //clone of the above because complexity
 147:main.cpp      **** /* static const struct TestVector attackVector  = {
 148:main.cpp      ****     .name        = "ATTACK VECTOR HARDCODE EXAMPLE",
 149:main.cpp      ****     .key1        = {0x27, 0x18, 0x28, 0x18, 0x28, 0x45, 0x90, 0x45,
 150:main.cpp      ****                     0x23, 0x53, 0x60, 0x28, 0x74, 0x71, 0x35, 0x26},
 151:main.cpp      ****     .key2        = {0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
 152:main.cpp      ****                     0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95},
 153:main.cpp      ****     .plaintext   = {0x50, 0x00, 0xec, 0xa5, 0xa1, 0xf6, 0xa4, 0x93,
 154:main.cpp      ****                     0x78, 0x03, 0x0d, 0x9e, 0xe8, 0x05, 0xac, 0xef,
 155:main.cpp      ****                     0x46, 0x0f, 0x31, 0x4e, 0xe0, 0x4b, 0xb5, 0x14,
 156:main.cpp      ****                     0x03, 0x4e, 0xb2, 0x7f, 0xb8, 0xdf, 0x2b, 0xc8,
 157:main.cpp      ****                     0x12, 0xae, 0x5b, 0xdf, 0x8c},
 158:main.cpp      ****     .ciphertext  = {0xe5, 0x9e, 0x6f, 0x23, 0x3b, 0xe0, 0xe0, 0x83,
 159:main.cpp      ****                     0x04, 0x83, 0xc6, 0xbd, 0x4e, 0x82, 0xf4, 0xc3,
 160:main.cpp      ****                     0x95, 0x43, 0x55, 0x8a, 0x25, 0xe3, 0xdb, 0x60,
 161:main.cpp      ****                     0xa5, 0x53, 0xa5, 0x94, 0x81, 0x45, 0xa6, 0xff,
 162:main.cpp      ****                     0xb5, 0xe6, 0xbe, 0x1d, 0xb5},
 163:main.cpp      ****     .tweak       = {0xff, 0xff, 0xff, 0xff, //0x80 first byte
 164:main.cpp      ****                     0xff, 0xff, 0xff, 0xff,
 165:main.cpp      ****                     0xff, 0xff, 0xff, 0xff,
 166:main.cpp      ****                     0xff, 0xff, 0xff, 0xff},
 167:main.cpp      ****     .sectorSize  = 37
 168:main.cpp      **** }; */
 169:main.cpp      **** /*static const struct TestVector attackVector = {
 170:main.cpp      ****     // 512 byte test vector from the spec truncated to the first 64 bytes.
 171:main.cpp      ****     .name        = "ATTACK VECTOR TEST",
 172:main.cpp      ****     .key1        = {0x27, 0x18, 0x28, 0x18, 0x28, 0x45, 0x90, 0x45,
 173:main.cpp      ****                     0x23, 0x53, 0x60, 0x28, 0x74, 0x71, 0x35, 0x26},
 174:main.cpp      ****     .key2        = {0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
 175:main.cpp      ****                     0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95},
 176:main.cpp      ****     .plaintext   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 177:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 178:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 179:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 180:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 181:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 182:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 183:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f},
 184:main.cpp      ****     .ciphertext  = {0x27, 0xa7, 0x47, 0x9b, 0xef, 0xa1, 0xd4, 0x76,
 185:main.cpp      ****                     0x48, 0x9f, 0x30, 0x8c, 0xd4, 0xcf, 0xa6, 0xe2,
 186:main.cpp      ****                     0xa9, 0x6e, 0x4b, 0xbe, 0x32, 0x08, 0xff, 0x25,
 187:main.cpp      ****                     0x28, 0x7d, 0xd3, 0x81, 0x96, 0x16, 0xe8, 0x9c,
 188:main.cpp      ****                     0xc7, 0x8c, 0xf7, 0xf5, 0xe5, 0x43, 0x44, 0x5f,
 189:main.cpp      ****                     0x83, 0x33, 0xd8, 0xfa, 0x7f, 0x56, 0x00, 0x00,
 190:main.cpp      ****                     0x05, 0x27, 0x9f, 0xa5, 0xd8, 0xb5, 0xe4, 0xad,
 191:main.cpp      ****                     0x40, 0xe7, 0x36, 0xdd, 0xb4, 0xd3, 0x54, 0x12},
 192:main.cpp      ****     .tweak       = {0xff},
 193:main.cpp      ****     .sectorSize  = 64
 194:main.cpp      **** }; */
 195:main.cpp      **** static const struct TestVector attackVector = {
 196:main.cpp      ****     // 512 byte test vector from the spec truncated to the first 64 bytes.
 197:main.cpp      ****     .name        = "ATTACK VECTOR TEST",
 198:main.cpp      ****     .key1        = {0x27, 0x18, 0x28, 0x18, 0x28, 0x45, 0x90, 0x45,
 199:main.cpp      ****                     0x23, 0x53, 0x60, 0x28, 0x74, 0x71, 0x35, 0x26},
 200:main.cpp      ****     .key2        = {0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
 201:main.cpp      ****                     0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95},
 202:main.cpp      ****     .plaintext   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 203:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 204:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 205:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 206:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 207:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 208:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 209:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 210:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 211:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 212:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 213:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 214:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 215:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 216:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 217:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 218:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 219:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 220:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 221:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 222:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 223:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 224:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 225:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 226:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 227:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 228:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 229:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 230:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 231:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 232:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 233:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 234:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 235:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 236:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 237:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 238:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 239:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 240:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 241:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 242:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 243:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 244:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 245:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 246:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 247:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 248:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 249:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 250:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 251:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 252:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 253:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 254:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 255:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 256:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 257:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 258:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 259:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 260:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 261:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 262:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 263:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 264:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 265:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 266:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 267:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 268:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 269:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 270:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 271:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 272:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 273:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 274:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 275:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 276:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 277:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 278:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 279:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 280:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 281:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 282:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 283:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 284:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 285:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 286:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 287:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 288:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 289:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 290:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 291:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 292:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 293:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 294:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 295:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 296:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 297:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 298:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 299:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 300:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 301:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 302:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 303:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 304:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 305:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 306:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 307:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 308:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 309:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 310:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 311:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 312:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 313:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 314:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 315:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 316:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 317:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 318:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 319:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 320:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 321:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 322:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 323:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 324:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 325:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 326:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 327:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 328:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 329:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 330:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 331:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 332:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 333:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 334:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 335:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 336:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 337:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 338:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 339:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 340:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 341:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 342:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 343:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 344:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 345:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 346:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 347:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 348:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 349:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 350:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 351:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 352:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 353:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 354:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 355:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 356:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 357:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 358:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 359:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 360:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 361:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 362:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 363:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 364:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 365:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 366:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 367:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 368:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 369:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 370:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 371:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 372:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 373:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 374:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 375:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 376:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 377:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 378:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 379:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 380:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 381:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 382:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 383:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 384:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 385:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 386:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 387:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 388:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 389:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 390:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 391:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 392:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 393:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 394:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 395:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 396:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 397:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 398:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 399:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 400:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 401:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 402:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 403:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 404:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 405:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 406:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 407:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 408:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 409:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 410:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 411:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 412:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 413:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 414:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 415:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 416:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 417:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 418:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 419:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 420:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 421:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 422:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 423:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 424:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 425:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 426:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 427:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 428:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 429:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 430:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 431:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 432:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 433:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 434:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 435:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 436:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 437:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 438:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 439:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 440:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 441:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 442:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 443:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 444:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 445:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 446:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 447:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 448:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 449:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
 450:main.cpp      ****                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 451:main.cpp      ****                     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
 452:main.cpp      ****                     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
 453:main.cpp      ****                     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
 454:main.cpp      ****                     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
 455:main.cpp      ****                     0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
 456:main.cpp      ****                     0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
 457:main.cpp      ****                     0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f},
 458:main.cpp      ****     .ciphertext  = {0x27, 0xa7, 0x47, 0x9b, 0xef, 0xa1, 0xd4, 0x76,
 459:main.cpp      ****                     0x48, 0x9f, 0x30, 0x8c, 0xd4, 0xcf, 0xa6, 0xe2,
 460:main.cpp      ****                     0xa9, 0x6e, 0x4b, 0xbe, 0x32, 0x08, 0xff, 0x25,
 461:main.cpp      ****                     0x28, 0x7d, 0xd3, 0x81, 0x96, 0x16, 0xe8, 0x9c,
 462:main.cpp      ****                     0xc7, 0x8c, 0xf7, 0xf5, 0xe5, 0x43, 0x44, 0x5f,
 463:main.cpp      ****                     0x83, 0x33, 0xd8, 0xfa, 0x7f, 0x56, 0x00, 0x00,
 464:main.cpp      ****                     0x05, 0x27, 0x9f, 0xa5, 0xd8, 0xb5, 0xe4, 0xad,
 465:main.cpp      ****                     0x40, 0xe7, 0x36, 0xdd, 0xb4, 0xd3, 0x54, 0x12},
 466:main.cpp      ****     .tweak       = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0
 467:main.cpp      ****     .sectorSize  = 2048
 468:main.cpp      **** }; 
 469:main.cpp      **** //.tweak       = {0x33, 0x22, 0x11, 0x00},
 470:main.cpp      **** //2048 sectorSize plaintext 
 471:main.cpp      **** //    .tweak       = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
 472:main.cpp      **** //    .tweak       = {0x01, 0x00, 0xaa, 0x55, 0xd8, 0x54, 0x12, 0x76, 0x56, 0x08, 0x28, 0x7d, 0xd3,
 473:main.cpp      **** // FIRST TEST: ORIGINAL TWEAK PRE ENCRYPT: {0xe0, 0x41, 0xa9, 0xf1, 0x7e, 0xc8, 0xf0, 0x81, 0x99, 0
 474:main.cpp      **** // RUN TWO PRE ENCRYPT: {0x14, 0x3f, 0x9a, 0x76, 0xb2, 0xc7, 0xd9, 0x45, 0x1e, 0x88, 0x32, 0xff, 0x
 475:main.cpp      **** 
 476:main.cpp      **** XTS<AES128> *xtsaes128;
 477:main.cpp      **** struct TestVector testVector;
 478:main.cpp      **** byte buffer[MAX_SECTOR_SIZE];
 479:main.cpp      **** /*
 480:main.cpp      **** bool testXTS(XTSCommon *cipher, const struct TestVector *test) {
 481:main.cpp      ****     bool passed = true;
 482:main.cpp      **** 
 483:main.cpp      ****     memcpy(&testVector, test, sizeof(testVector));
 484:main.cpp      **** 
 485:main.cpp      ****     cipher->setSectorSize(testVector.sectorSize);
 486:main.cpp      ****     cipher->setKey(testVector.key1, 32);
 487:main.cpp      ****     cipher->setTweak(testVector.tweak, sizeof(testVector.tweak));
 488:main.cpp      **** 
 489:main.cpp      ****     // Encryption
 490:main.cpp      ****     cipher->encryptSector(buffer, testVector.plaintext);
 491:main.cpp      ****     if (memcmp(buffer, testVector.ciphertext, testVector.sectorSize)) {
 492:main.cpp      ****         passed = false;
 493:main.cpp      ****     }
 494:main.cpp      **** 
 495:main.cpp      ****     // Decryption
 496:main.cpp      ****     cipher->decryptSector(buffer, testVector.ciphertext);
 497:main.cpp      ****     if (memcmp(buffer, testVector.plaintext, testVector.sectorSize)) {
 498:main.cpp      ****         passed = false;
 499:main.cpp      ****     }
 500:main.cpp      **** 
 501:main.cpp      ****     // In-place Encryption
 502:main.cpp      ****     memcpy(buffer, testVector.plaintext, testVector.sectorSize);
 503:main.cpp      ****     cipher->encryptSector(buffer, buffer);
 504:main.cpp      ****     if (memcmp(buffer, testVector.ciphertext, testVector.sectorSize)) {
 505:main.cpp      ****         passed = false;
 506:main.cpp      ****     }
 507:main.cpp      **** 
 508:main.cpp      ****     // In-place Decryption
 509:main.cpp      ****     memcpy(buffer, testVector.ciphertext, testVector.sectorSize);
 510:main.cpp      ****     cipher->decryptSector(buffer, buffer);
 511:main.cpp      ****     if (memcmp(buffer, testVector.plaintext, testVector.sectorSize)) {
 512:main.cpp      ****         passed = false;
 513:main.cpp      ****     }
 514:main.cpp      **** 
 515:main.cpp      ****     return passed;
 516:main.cpp      **** } */
 517:main.cpp      **** 
 518:main.cpp      **** void updateTweak(uint32_t V[4])
 519:main.cpp      **** {
  75              		.loc 2 519 1 is_stmt 1 view -0
  76              		.cfi_startproc
  77              		@ args = 0, pretend = 0, frame = 16
  78              		@ frame_needed = 0, uses_anonymous_args = 0
 520:main.cpp      ****     uint8_t T[16];
  79              		.loc 2 520 5 view .LVU3
 521:main.cpp      ****     uint8_t Cin = 0, Cout;
  80              		.loc 2 521 5 view .LVU4
 522:main.cpp      **** 
 523:main.cpp      ****     // 32 bits / 8 = 4 bytes since 8 bits = 1 byte, therefore one single V index is 4 T index, as i
 524:main.cpp      ****     // Conversion vice versa is the same except memcpy locations are changed because 4 T index = 1 
 525:main.cpp      ****     
 526:main.cpp      ****     // Convert 4x uint32_t to 16x uint8_t
 527:main.cpp      ****     for (int i = 0; i < 4; i++) {
  81              		.loc 2 527 5 view .LVU5
  82              	.LBB5:
  83              		.loc 2 527 23 view .LVU6
 528:main.cpp      ****         V[i] = le32toh(V[i]);
  84              		.loc 2 528 9 view .LVU7
 529:main.cpp      ****         std::memcpy(&T[i * 4], &V[i], sizeof(uint32_t));
  85              		.loc 2 529 9 view .LVU8
  86              	.LBE5:
 519:main.cpp      ****     uint8_t T[16];
  87              		.loc 2 519 1 is_stmt 0 view .LVU9
  88 0000 30B5     		push	{r4, r5, lr}
  89              		.save {r4, r5, lr}
  90              	.LCFI0:
  91              		.cfi_def_cfa_offset 12
  92              		.cfi_offset 4, -12
  93              		.cfi_offset 5, -8
  94              		.cfi_offset 14, -4
  95              		.pad #20
  96 0002 85B0     		sub	sp, sp, #20
  97              	.LCFI1:
  98              		.cfi_def_cfa_offset 32
  99              	.LBB6:
 100              		.loc 2 529 20 view .LVU10
 101 0004 0368     		ldr	r3, [r0]
 102 0006 0093     		str	r3, [sp]
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 103              		.loc 2 527 5 is_stmt 1 view .LVU11
 104              	.LVL2:
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 105              		.loc 2 527 23 view .LVU12
 528:main.cpp      ****         std::memcpy(&T[i * 4], &V[i], sizeof(uint32_t));
 106              		.loc 2 528 9 view .LVU13
 107              		.loc 2 529 9 view .LVU14
 108              		.loc 2 529 20 is_stmt 0 view .LVU15
 109 0008 4368     		ldr	r3, [r0, #4]
 110 000a 0193     		str	r3, [sp, #4]
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 111              		.loc 2 527 5 is_stmt 1 view .LVU16
 112              	.LVL3:
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 113              		.loc 2 527 23 view .LVU17
 528:main.cpp      ****         std::memcpy(&T[i * 4], &V[i], sizeof(uint32_t));
 114              		.loc 2 528 9 view .LVU18
 115              		.loc 2 529 9 view .LVU19
 116              		.loc 2 529 20 is_stmt 0 view .LVU20
 117 000c 8368     		ldr	r3, [r0, #8]
 118 000e 0293     		str	r3, [sp, #8]
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 119              		.loc 2 527 5 is_stmt 1 view .LVU21
 120              	.LVL4:
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 121              		.loc 2 527 23 view .LVU22
 528:main.cpp      ****         std::memcpy(&T[i * 4], &V[i], sizeof(uint32_t));
 122              		.loc 2 528 9 view .LVU23
 123              		.loc 2 529 9 view .LVU24
 124              		.loc 2 529 20 is_stmt 0 view .LVU25
 125 0010 C368     		ldr	r3, [r0, #12]
 126 0012 0393     		str	r3, [sp, #12]
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 127              		.loc 2 527 5 is_stmt 1 view .LVU26
 128              	.LVL5:
 527:main.cpp      ****         V[i] = le32toh(V[i]);
 129              		.loc 2 527 23 view .LVU27
 130              	.LBE6:
 530:main.cpp      ****     }
 531:main.cpp      ****     
 532:main.cpp      ****     trigger_high();
 131              		.loc 2 532 5 view .LVU28
 519:main.cpp      ****     uint8_t T[16];
 132              		.loc 2 519 1 is_stmt 0 view .LVU29
 133 0014 0446     		mov	r4, r0
 134              		.loc 2 532 17 view .LVU30
 135 0016 FFF7FEFF 		bl	trigger_high
 136              	.LVL6:
 137              	.LBB7:
 533:main.cpp      **** 
 534:main.cpp      ****     // 16-byte left shifting
 535:main.cpp      ****     for (int i = 0; i < 16; i++) {
 138              		.loc 2 535 23 is_stmt 1 view .LVU31
 139              		.loc 2 535 14 is_stmt 0 view .LVU32
 140 001a 0023     		movs	r3, #0
 141 001c 6946     		mov	r1, sp
 142              	.LBE7:
 521:main.cpp      **** 
 143              		.loc 2 521 13 view .LVU33
 144 001e 1A46     		mov	r2, r3
 145              	.LVL7:
 146              	.L4:
 147              	.LBB8:
 536:main.cpp      ****         Cout = (T[i] >> 7) & 1;
 148              		.loc 2 536 9 is_stmt 1 discriminator 2 view .LVU34
 149              		.loc 2 536 20 is_stmt 0 discriminator 2 view .LVU35
 150 0020 0D78     		ldrb	r5, [r1]	@ zero_extendqisi2
 151 0022 1046     		mov	r0, r2
 535:main.cpp      ****         Cout = (T[i] >> 7) & 1;
 152              		.loc 2 535 5 discriminator 2 view .LVU36
 153 0024 0133     		adds	r3, r3, #1
 154              	.LVL8:
 537:main.cpp      ****         T[i] = ((T[i] << 1) + Cin) & 0xFF;
 155              		.loc 2 537 29 discriminator 2 view .LVU37
 156 0026 00EB4500 		add	r0, r0, r5, lsl #1
 535:main.cpp      ****         Cout = (T[i] >> 7) & 1;
 157              		.loc 2 535 23 discriminator 2 view .LVU38
 158 002a 102B     		cmp	r3, #16
 159              		.loc 2 537 14 discriminator 2 view .LVU39
 160 002c 01F8010B 		strb	r0, [r1], #1
 536:main.cpp      ****         Cout = (T[i] >> 7) & 1;
 161              		.loc 2 536 14 discriminator 2 view .LVU40
 162 0030 4FEAD512 		lsr	r2, r5, #7
 163              	.LVL9:
 164              		.loc 2 537 9 is_stmt 1 discriminator 2 view .LVU41
 538:main.cpp      ****         Cin = Cout;
 165              		.loc 2 538 9 discriminator 2 view .LVU42
 535:main.cpp      ****         Cout = (T[i] >> 7) & 1;
 166              		.loc 2 535 5 discriminator 2 view .LVU43
 535:main.cpp      ****         Cout = (T[i] >> 7) & 1;
 167              		.loc 2 535 23 discriminator 2 view .LVU44
 168 0034 F4D1     		bne	.L4
 169              	.LBE8:
 539:main.cpp      ****     }
 540:main.cpp      ****     
 541:main.cpp      ****     // invert the bits if necessary
 542:main.cpp      ****     if (Cout == 1) {
 170              		.loc 2 542 5 view .LVU45
 171 0036 2AB1     		cbz	r2, .L5
 543:main.cpp      ****         T[0] ^= 0x87;
 172              		.loc 2 543 9 view .LVU46
 173              		.loc 2 543 14 is_stmt 0 view .LVU47
 174 0038 9DF80030 		ldrb	r3, [sp]	@ zero_extendqisi2
 175              	.LVL10:
 176              		.loc 2 543 14 view .LVU48
 177 003c 83F08703 		eor	r3, r3, #135
 178 0040 8DF80030 		strb	r3, [sp]
 179              	.L5:
 544:main.cpp      ****     }
 545:main.cpp      ****     
 546:main.cpp      ****     trigger_low();
 180              		.loc 2 546 5 is_stmt 1 view .LVU49
 181              		.loc 2 546 16 is_stmt 0 view .LVU50
 182 0044 FFF7FEFF 		bl	trigger_low
 183              	.LVL11:
 184              	.LBB9:
 547:main.cpp      ****   
 548:main.cpp      ****     // Convert 16x uint8_t to 4x uint32_t 
 549:main.cpp      ****     for (int i = 0; i < 4; i++) {
 185              		.loc 2 549 23 is_stmt 1 view .LVU51
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 186              		.loc 2 550 9 view .LVU52
 187              		.loc 2 550 20 is_stmt 0 view .LVU53
 188 0048 009B     		ldr	r3, [sp]
 189 004a 2360     		str	r3, [r4]	@ unaligned
 551:main.cpp      ****         V[i] = htole32(V[i]);
 190              		.loc 2 551 9 is_stmt 1 view .LVU54
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 191              		.loc 2 549 5 view .LVU55
 192              	.LVL12:
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 193              		.loc 2 549 23 view .LVU56
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 194              		.loc 2 550 9 view .LVU57
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 195              		.loc 2 550 20 is_stmt 0 view .LVU58
 196 004c 019B     		ldr	r3, [sp, #4]
 197 004e 6360     		str	r3, [r4, #4]	@ unaligned
 198              		.loc 2 551 9 is_stmt 1 view .LVU59
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 199              		.loc 2 549 5 view .LVU60
 200              	.LVL13:
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 201              		.loc 2 549 23 view .LVU61
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 202              		.loc 2 550 9 view .LVU62
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 203              		.loc 2 550 20 is_stmt 0 view .LVU63
 204 0050 029B     		ldr	r3, [sp, #8]
 205 0052 A360     		str	r3, [r4, #8]	@ unaligned
 206              		.loc 2 551 9 is_stmt 1 view .LVU64
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 207              		.loc 2 549 5 view .LVU65
 208              	.LVL14:
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 209              		.loc 2 549 23 view .LVU66
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 210              		.loc 2 550 9 view .LVU67
 550:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 211              		.loc 2 550 20 is_stmt 0 view .LVU68
 212 0054 039B     		ldr	r3, [sp, #12]
 213 0056 E360     		str	r3, [r4, #12]	@ unaligned
 214              		.loc 2 551 9 is_stmt 1 view .LVU69
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 215              		.loc 2 549 5 view .LVU70
 216              	.LVL15:
 549:main.cpp      ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 217              		.loc 2 549 23 view .LVU71
 218              	.LBE9:
 552:main.cpp      ****     }
 553:main.cpp      **** }
 219              		.loc 2 553 1 is_stmt 0 view .LVU72
 220 0058 05B0     		add	sp, sp, #20
 221              	.LCFI2:
 222              		.cfi_def_cfa_offset 12
 223              		@ sp needed
 224 005a 30BD     		pop	{r4, r5, pc}
 225              		.loc 2 553 1 view .LVU73
 226              		.cfi_endproc
 227              	.LFE1563:
 228              		.fnend
 230              		.section	.rodata.str1.1,"aMS",%progbits,1
 231              	.LC0:
 232 0000 FFFFFFFF 		.ascii	"\377\377\377\377\377\377\377\377\377\377\377\377\377"
 232      FFFFFFFF 
 232      FFFFFFFF 
 232      FF
 233 000d FFFFFF00 		.ascii	"\377\377\377\000"
 234              		.section	.text._Z15setAndTestTweakv,"ax",%progbits
 235              		.align	1
 236              		.global	_Z15setAndTestTweakv
 237              		.syntax unified
 238              		.thumb
 239              		.thumb_func
 240              		.fpu softvfp
 242              	_Z15setAndTestTweakv:
 243              		.fnstart
 244              	.LFB1564:
 554:main.cpp      **** 
 555:main.cpp      **** 
 556:main.cpp      **** void setAndTestTweak() {
 245              		.loc 2 556 24 is_stmt 1 view -0
 246              		.cfi_startproc
 247              		@ args = 0, pretend = 0, frame = 64
 248              		@ frame_needed = 0, uses_anonymous_args = 0
 557:main.cpp      ****     //first 10 bits of 128 bit tweak vector is set to 1. 
 558:main.cpp      ****     /*uint8_t tweakBytes[16] = {0xFF, 0xC0, 0x00, 0x00, 
 559:main.cpp      ****                               0x00, 0x00, 0x00, 0x00,
 560:main.cpp      ****                               0x00, 0x00, 0x00, 0x00,
 561:main.cpp      ****                               0x00, 0x00, 0x00, 0x00};*/
 562:main.cpp      ****     uint8_t tweakBytes[16] = {0xFF, 0xFF, 0xFF, 0xFF, 
 249              		.loc 2 562 5 view .LVU75
 556:main.cpp      ****     //first 10 bits of 128 bit tweak vector is set to 1. 
 250              		.loc 2 556 24 is_stmt 0 view .LVU76
 251 0000 F0B5     		push	{r4, r5, r6, r7, lr}
 252              		.save {r4, r5, r6, r7, lr}
 253              	.LCFI3:
 254              		.cfi_def_cfa_offset 20
 255              		.cfi_offset 4, -20
 256              		.cfi_offset 5, -16
 257              		.cfi_offset 6, -12
 258              		.cfi_offset 7, -8
 259              		.cfi_offset 14, -4
 260              		.loc 2 562 13 view .LVU77
 261 0002 174B     		ldr	r3, .L14
 556:main.cpp      ****     //first 10 bits of 128 bit tweak vector is set to 1. 
 262              		.loc 2 556 24 view .LVU78
 263              		.pad #68
 264 0004 91B0     		sub	sp, sp, #68
 265              	.LCFI4:
 266              		.cfi_def_cfa_offset 88
 267              		.loc 2 562 13 view .LVU79
 268 0006 6C46     		mov	r4, sp
 269 0008 03F11006 		add	r6, r3, #16
 270 000c 2246     		mov	r2, r4
 271              	.L8:
 272 000e 1868     		ldr	r0, [r3]	@ unaligned
 273 0010 5968     		ldr	r1, [r3, #4]	@ unaligned
 274 0012 2546     		mov	r5, r4
 275 0014 03C5     		stmia	r5!, {r0, r1}
 276 0016 0833     		adds	r3, r3, #8
 277 0018 B342     		cmp	r3, r6
 278 001a 2C46     		mov	r4, r5
 279 001c F7D1     		bne	.L8
 563:main.cpp      ****                               0xFF, 0xFF, 0xFF, 0xFF,
 564:main.cpp      ****                               0xFF, 0xFF, 0xFF, 0xFF,
 565:main.cpp      ****                               0xFF, 0xFF, 0xFF, 0xFF};
 566:main.cpp      **** 
 567:main.cpp      ****     uint8_t tweakBytes2[16] = {0x00, 0x00, 0x00, 0x00, 
 280              		.loc 2 567 5 is_stmt 1 view .LVU80
 281              		.loc 2 567 13 is_stmt 0 view .LVU81
 282 001e 114B     		ldr	r3, .L14+4
 283 0020 04AC     		add	r4, sp, #16
 284 0022 03F11007 		add	r7, r3, #16
 285 0026 2646     		mov	r6, r4
 286              	.L9:
 287 0028 1868     		ldr	r0, [r3]	@ unaligned
 288 002a 5968     		ldr	r1, [r3, #4]	@ unaligned
 289 002c 2546     		mov	r5, r4
 290 002e 03C5     		stmia	r5!, {r0, r1}
 291 0030 0833     		adds	r3, r3, #8
 292 0032 BB42     		cmp	r3, r7
 293 0034 2C46     		mov	r4, r5
 294 0036 F7D1     		bne	.L9
 568:main.cpp      ****                               0x00, 0x00, 0x00, 0x00,
 569:main.cpp      ****                               0x00, 0x00, 0x00, 0x00,
 570:main.cpp      ****                               0x00, 0x00, 0x00, 0x00};
 571:main.cpp      **** 
 572:main.cpp      ****     // Convert to uint32_t array
 573:main.cpp      ****     uint32_t tweakUInt32one[4];
 295              		.loc 2 573 5 is_stmt 1 view .LVU82
 574:main.cpp      ****     std::memcpy(tweakUInt32one, tweakBytes, sizeof(tweakUInt32one));
 296              		.loc 2 574 5 view .LVU83
 297              		.loc 2 574 16 is_stmt 0 view .LVU84
 298 0038 0FCA     		ldm	r2, {r0, r1, r2, r3}
 299 003a 08AD     		add	r5, sp, #32
 300 003c 85E80F00 		stm	r5, {r0, r1, r2, r3}
 575:main.cpp      **** 
 576:main.cpp      ****     uint32_t tweakUInt32two[4];
 301              		.loc 2 576 5 is_stmt 1 view .LVU85
 577:main.cpp      ****     std::memcpy(tweakUInt32two, tweakBytes2, sizeof(tweakUInt32two));
 302              		.loc 2 577 5 view .LVU86
 303              		.loc 2 577 16 is_stmt 0 view .LVU87
 304 0040 96E80F00 		ldm	r6, {r0, r1, r2, r3}
 305 0044 0CAC     		add	r4, sp, #48
 306 0046 84E80F00 		stm	r4, {r0, r1, r2, r3}
 578:main.cpp      **** 
 579:main.cpp      ****     // Pass to updateTweak 5 times
 580:main.cpp      ****     for (int i = 0; i < 5; i++) {
 307              		.loc 2 580 5 is_stmt 1 view .LVU88
 308              	.LVL16:
 309              	.LBB10:
 310              		.loc 2 580 23 view .LVU89
 311              	.LBE10:
 577:main.cpp      ****     std::memcpy(tweakUInt32two, tweakBytes2, sizeof(tweakUInt32two));
 312              		.loc 2 577 16 is_stmt 0 view .LVU90
 313 004a 0526     		movs	r6, #5
 314              	.LVL17:
 315              	.L10:
 316              	.LBB11:
 581:main.cpp      ****         updateTweak(tweakUInt32one);
 317              		.loc 2 581 9 is_stmt 1 view .LVU91
 318              		.loc 2 581 20 is_stmt 0 view .LVU92
 319 004c 2846     		mov	r0, r5
 320 004e FFF7FEFF 		bl	_Z11updateTweakPm
 321              	.LVL18:
 582:main.cpp      ****         updateTweak(tweakUInt32two);
 322              		.loc 2 582 9 is_stmt 1 view .LVU93
 323              		.loc 2 582 20 is_stmt 0 view .LVU94
 324 0052 2046     		mov	r0, r4
 325 0054 FFF7FEFF 		bl	_Z11updateTweakPm
 326              	.LVL19:
 580:main.cpp      ****         updateTweak(tweakUInt32one);
 327              		.loc 2 580 5 is_stmt 1 view .LVU95
 580:main.cpp      ****         updateTweak(tweakUInt32one);
 328              		.loc 2 580 23 view .LVU96
 329 0058 013E     		subs	r6, r6, #1
 330              	.LVL20:
 580:main.cpp      ****         updateTweak(tweakUInt32one);
 331              		.loc 2 580 23 is_stmt 0 view .LVU97
 332 005a F7D1     		bne	.L10
 333              	.LBE11:
 583:main.cpp      ****     }
 584:main.cpp      **** }
 334              		.loc 2 584 1 view .LVU98
 335 005c 11B0     		add	sp, sp, #68
 336              	.LCFI5:
 337              		.cfi_def_cfa_offset 20
 338              		@ sp needed
 339 005e F0BD     		pop	{r4, r5, r6, r7, pc}
 340              	.LVL21:
 341              	.L15:
 342              		.loc 2 584 1 view .LVU99
 343              		.align	2
 344              	.L14:
 345 0060 00000000 		.word	.LC0
 346 0064 00000000 		.word	.LANCHOR0
 347              		.cfi_endproc
 348              	.LFE1564:
 349              		.fnend
 351              		.section	.text._Z8tenTweakhhhPh,"ax",%progbits
 352              		.align	1
 353              		.global	_Z8tenTweakhhhPh
 354              		.syntax unified
 355              		.thumb
 356              		.thumb_func
 357              		.fpu softvfp
 359              	_Z8tenTweakhhhPh:
 360              		.fnstart
 361              	.LVL22:
 362              	.LFB1565:
 585:main.cpp      **** 
 586:main.cpp      **** uint8_t tenTweak(uint8_t cmd, uint8_t scmd, uint8_t len, uint8_t *buf) {
 363              		.loc 2 586 72 is_stmt 1 view -0
 364              		.cfi_startproc
 365              		@ args = 0, pretend = 0, frame = 0
 366              		@ frame_needed = 0, uses_anonymous_args = 0
 587:main.cpp      ****     setAndTestTweak();
 367              		.loc 2 587 5 view .LVU101
 586:main.cpp      ****     setAndTestTweak();
 368              		.loc 2 586 72 is_stmt 0 view .LVU102
 369 0000 08B5     		push	{r3, lr}
 370              		.save {r3, lr}
 371              	.LCFI6:
 372              		.cfi_def_cfa_offset 8
 373              		.cfi_offset 3, -8
 374              		.cfi_offset 14, -4
 375              		.loc 2 587 20 view .LVU103
 376 0002 FFF7FEFF 		bl	_Z15setAndTestTweakv
 377              	.LVL23:
 588:main.cpp      ****     return 0x00;
 378              		.loc 2 588 5 is_stmt 1 view .LVU104
 589:main.cpp      **** }
 379              		.loc 2 589 1 is_stmt 0 view .LVU105
 380 0006 0020     		movs	r0, #0
 381 0008 08BD     		pop	{r3, pc}
 382              		.cfi_endproc
 383              	.LFE1565:
 384              		.fnend
 386              		.section	.text.startup._GLOBAL__sub_I_xtsaes128,"ax",%progbits
 387              		.align	1
 388              		.syntax unified
 389              		.thumb
 390              		.thumb_func
 391              		.fpu softvfp
 393              	_GLOBAL__sub_I_xtsaes128:
 394              		.fnstart
 395              	.LFB2067:
 590:main.cpp      **** 
 591:main.cpp      **** uint8_t attack_example(uint8_t cmd, uint8_t scmd, uint8_t len, uint8_t *buf) {
 592:main.cpp      **** 
 593:main.cpp      ****     XTS<AES128> cipher;
 594:main.cpp      ****     byte buffer[MAX_SECTOR_SIZE];
 595:main.cpp      ****     bool passed = true;
 596:main.cpp      **** 
 597:main.cpp      ****     //ss_iteration
 598:main.cpp      ****     uint8_t iter = buf[0];
 599:main.cpp      ****     
 600:main.cpp      ****     
 601:main.cpp      ****     //trigger_high();
 602:main.cpp      ****     cipher.setSectorSize(attackVector.sectorSize);
 603:main.cpp      ****     cipher.setKey(attackVector.key1, 32); // Assuming 32 bytes for key1 and key2 combined
 604:main.cpp      ****     cipher.setTweak(attackVector.tweak, sizeof(attackVector.tweak));
 605:main.cpp      ****     cipher.encryptSector(buffer, attackVector.plaintext, iter); // In-place encryption
 606:main.cpp      ****     //cipher.encryptSector(buffer, attackVector.plaintext); // In-place encryption
 607:main.cpp      **** 
 608:main.cpp      ****     //if (memcmp(buffer, attackVector.ciphertext, attackVector.sectorSize)) {
 609:main.cpp      ****     //    passed = false;
 610:main.cpp      ****     //}
 611:main.cpp      **** 
 612:main.cpp      ****     //uint8_t result = passed ? 0x00 : 0x01; // Return 0x00 for success, 0x01 for failure
 613:main.cpp      ****     //simpleserial_put('s', 1, &result); // Now using 's' as the command both for request and respo
 614:main.cpp      ****     //trigger_low();
 615:main.cpp      ****     //return result;
 616:main.cpp      ****     
 617:main.cpp      ****         // return iter;
 618:main.cpp      ****     return 0x00;   
 619:main.cpp      **** }
 620:main.cpp      **** /*
 621:main.cpp      **** uint8_t run_tests(uint8_t cmd, uint8_t scmd, uint8_t len, uint8_t *buf) {
 622:main.cpp      **** 
 623:main.cpp      ****     //xtsaes128 = new XTS<AES128>();
 624:main.cpp      ****     XTS<AES128> cipher;
 625:main.cpp      ****     const struct TestVector* tests[] = {
 626:main.cpp      ****         &testVectorXTSAES128_1,
 627:main.cpp      ****         &testVectorXTSAES128_2,
 628:main.cpp      ****         &testVectorXTSAES128_3,
 629:main.cpp      ****         &testVectorXTSAES128_4,
 630:main.cpp      ****         &testVectorXTSAES128_15,
 631:main.cpp      ****         &testVectorXTSAES128_16
 632:main.cpp      ****     };
 633:main.cpp      **** 
 634:main.cpp      ****     bool allTestsPassed = true;
 635:main.cpp      ****     for (const auto& test : tests) {
 636:main.cpp      ****         if (!testXTS(&cipher, test)) {
 637:main.cpp      ****             allTestsPassed = false;
 638:main.cpp      ****             break;
 639:main.cpp      ****         }
 640:main.cpp      ****     }
 641:main.cpp      **** 
 642:main.cpp      ****     uint8_t result = allTestsPassed ? 0x00 : 0x01;
 643:main.cpp      ****     simpleserial_put('t', 1, &result); // Send test result back to host
 644:main.cpp      ****     return result;
 645:main.cpp      **** } */
 646:main.cpp      **** 
 647:main.cpp      **** int main() {
 648:main.cpp      ****     
 649:main.cpp      ****     xtsaes128 = new XTS<AES128>();
 650:main.cpp      ****     platform_init();
 651:main.cpp      ****     init_uart();
 652:main.cpp      ****     trigger_setup();
 653:main.cpp      ****     simpleserial_init();
 654:main.cpp      ****     //simpleserial_addcmd('t', 0, run_tests);
 655:main.cpp      ****     //simpleserial_addcmd('s', 0, attack_example);
 656:main.cpp      ****     // with iter:
 657:main.cpp      ****     simpleserial_addcmd('s', 1, attack_example);
 658:main.cpp      **** 
 659:main.cpp      ****     simpleserial_addcmd('c', 0, tenTweak);
 660:main.cpp      ****     //simpleserial_addcmd('s', 0, run_single);
 661:main.cpp      ****     
 662:main.cpp      ****     while(1){
 663:main.cpp      ****         simpleserial_get();
 664:main.cpp      ****     }
 665:main.cpp      **** 
 666:main.cpp      ****     return 0;
 667:main.cpp      **** }
 396              		.loc 2 667 1 is_stmt 1 view -0
 397              		.cfi_startproc
 398              		@ args = 0, pretend = 0, frame = 0
 399              		@ frame_needed = 0, uses_anonymous_args = 0
 400              	.LBB14:
 401              	.LBI14:
 402              		.loc 2 667 1 view .LVU107
 403              	.LVL24:
 404              		.loc 2 667 1 is_stmt 0 view .LVU108
 405              	.LBE14:
 406 0000 10B5     		push	{r4, lr}
 407              	.LCFI7:
 408              		.cfi_def_cfa_offset 8
 409              		.cfi_offset 4, -8
 410              		.cfi_offset 14, -4
 411              	.LBB17:
 412              	.LBB15:
 413              		.file 3 "/usr/include/newlib/c++/10.3.1/iostream"
   1:/usr/include/newlib/c++/10.3.1/iostream **** // Standard iostream objects -*- C++ -*-
   2:/usr/include/newlib/c++/10.3.1/iostream **** 
   3:/usr/include/newlib/c++/10.3.1/iostream **** // Copyright (C) 1997-2020 Free Software Foundation, Inc.
   4:/usr/include/newlib/c++/10.3.1/iostream **** //
   5:/usr/include/newlib/c++/10.3.1/iostream **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/usr/include/newlib/c++/10.3.1/iostream **** // software; you can redistribute it and/or modify it under the
   7:/usr/include/newlib/c++/10.3.1/iostream **** // terms of the GNU General Public License as published by the
   8:/usr/include/newlib/c++/10.3.1/iostream **** // Free Software Foundation; either version 3, or (at your option)
   9:/usr/include/newlib/c++/10.3.1/iostream **** // any later version.
  10:/usr/include/newlib/c++/10.3.1/iostream **** 
  11:/usr/include/newlib/c++/10.3.1/iostream **** // This library is distributed in the hope that it will be useful,
  12:/usr/include/newlib/c++/10.3.1/iostream **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/usr/include/newlib/c++/10.3.1/iostream **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/usr/include/newlib/c++/10.3.1/iostream **** // GNU General Public License for more details.
  15:/usr/include/newlib/c++/10.3.1/iostream **** 
  16:/usr/include/newlib/c++/10.3.1/iostream **** // Under Section 7 of GPL version 3, you are granted additional
  17:/usr/include/newlib/c++/10.3.1/iostream **** // permissions described in the GCC Runtime Library Exception, version
  18:/usr/include/newlib/c++/10.3.1/iostream **** // 3.1, as published by the Free Software Foundation.
  19:/usr/include/newlib/c++/10.3.1/iostream **** 
  20:/usr/include/newlib/c++/10.3.1/iostream **** // You should have received a copy of the GNU General Public License and
  21:/usr/include/newlib/c++/10.3.1/iostream **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/usr/include/newlib/c++/10.3.1/iostream **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/usr/include/newlib/c++/10.3.1/iostream **** // <http://www.gnu.org/licenses/>.
  24:/usr/include/newlib/c++/10.3.1/iostream **** 
  25:/usr/include/newlib/c++/10.3.1/iostream **** /** @file include/iostream
  26:/usr/include/newlib/c++/10.3.1/iostream ****  *  This is a Standard C++ Library header.
  27:/usr/include/newlib/c++/10.3.1/iostream ****  */
  28:/usr/include/newlib/c++/10.3.1/iostream **** 
  29:/usr/include/newlib/c++/10.3.1/iostream **** //
  30:/usr/include/newlib/c++/10.3.1/iostream **** // ISO C++ 14882: 27.3  Standard iostream objects
  31:/usr/include/newlib/c++/10.3.1/iostream **** //
  32:/usr/include/newlib/c++/10.3.1/iostream **** 
  33:/usr/include/newlib/c++/10.3.1/iostream **** #ifndef _GLIBCXX_IOSTREAM
  34:/usr/include/newlib/c++/10.3.1/iostream **** #define _GLIBCXX_IOSTREAM 1
  35:/usr/include/newlib/c++/10.3.1/iostream **** 
  36:/usr/include/newlib/c++/10.3.1/iostream **** #pragma GCC system_header
  37:/usr/include/newlib/c++/10.3.1/iostream **** 
  38:/usr/include/newlib/c++/10.3.1/iostream **** #include <bits/c++config.h>
  39:/usr/include/newlib/c++/10.3.1/iostream **** #include <ostream>
  40:/usr/include/newlib/c++/10.3.1/iostream **** #include <istream>
  41:/usr/include/newlib/c++/10.3.1/iostream **** 
  42:/usr/include/newlib/c++/10.3.1/iostream **** namespace std _GLIBCXX_VISIBILITY(default)
  43:/usr/include/newlib/c++/10.3.1/iostream **** {
  44:/usr/include/newlib/c++/10.3.1/iostream **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  45:/usr/include/newlib/c++/10.3.1/iostream **** 
  46:/usr/include/newlib/c++/10.3.1/iostream ****   /**
  47:/usr/include/newlib/c++/10.3.1/iostream ****    *  @name Standard Stream Objects
  48:/usr/include/newlib/c++/10.3.1/iostream ****    *
  49:/usr/include/newlib/c++/10.3.1/iostream ****    *  The &lt;iostream&gt; header declares the eight <em>standard stream
  50:/usr/include/newlib/c++/10.3.1/iostream ****    *  objects</em>.  For other declarations, see
  51:/usr/include/newlib/c++/10.3.1/iostream ****    *  http://gcc.gnu.org/onlinedocs/libstdc++/manual/io.html
  52:/usr/include/newlib/c++/10.3.1/iostream ****    *  and the @link iosfwd I/O forward declarations @endlink
  53:/usr/include/newlib/c++/10.3.1/iostream ****    *
  54:/usr/include/newlib/c++/10.3.1/iostream ****    *  They are required by default to cooperate with the global C
  55:/usr/include/newlib/c++/10.3.1/iostream ****    *  library's @c FILE streams, and to be available during program
  56:/usr/include/newlib/c++/10.3.1/iostream ****    *  startup and termination. For more information, see the section of the
  57:/usr/include/newlib/c++/10.3.1/iostream ****    *  manual linked to above.
  58:/usr/include/newlib/c++/10.3.1/iostream ****   */
  59:/usr/include/newlib/c++/10.3.1/iostream ****   ///@{
  60:/usr/include/newlib/c++/10.3.1/iostream ****   extern istream cin;		/// Linked to standard input
  61:/usr/include/newlib/c++/10.3.1/iostream ****   extern ostream cout;		/// Linked to standard output
  62:/usr/include/newlib/c++/10.3.1/iostream ****   extern ostream cerr;		/// Linked to standard error (unbuffered)
  63:/usr/include/newlib/c++/10.3.1/iostream ****   extern ostream clog;		/// Linked to standard error (buffered)
  64:/usr/include/newlib/c++/10.3.1/iostream **** 
  65:/usr/include/newlib/c++/10.3.1/iostream **** #ifdef _GLIBCXX_USE_WCHAR_T
  66:/usr/include/newlib/c++/10.3.1/iostream ****   extern wistream wcin;		/// Linked to standard input
  67:/usr/include/newlib/c++/10.3.1/iostream ****   extern wostream wcout;	/// Linked to standard output
  68:/usr/include/newlib/c++/10.3.1/iostream ****   extern wostream wcerr;	/// Linked to standard error (unbuffered)
  69:/usr/include/newlib/c++/10.3.1/iostream ****   extern wostream wclog;	/// Linked to standard error (buffered)
  70:/usr/include/newlib/c++/10.3.1/iostream **** #endif
  71:/usr/include/newlib/c++/10.3.1/iostream ****   ///@}
  72:/usr/include/newlib/c++/10.3.1/iostream **** 
  73:/usr/include/newlib/c++/10.3.1/iostream ****   // For construction of filebuffers for cout, cin, cerr, clog et. al.
  74:/usr/include/newlib/c++/10.3.1/iostream ****   static ios_base::Init __ioinit;
 414              		.loc 3 74 25 view .LVU109
 415 0002 054C     		ldr	r4, .L18
 416 0004 2046     		mov	r0, r4
 417 0006 FFF7FEFF 		bl	_ZNSt8ios_base4InitC1Ev
 418              	.LVL25:
 419 000a 2046     		mov	r0, r4
 420 000c 034A     		ldr	r2, .L18+4
 421 000e 0449     		ldr	r1, .L18+8
 422              	.LBE15:
 423              	.LBE17:
 424              		.loc 2 667 1 view .LVU110
 425 0010 BDE81040 		pop	{r4, lr}
 426              	.LCFI8:
 427              		.cfi_restore 14
 428              		.cfi_restore 4
 429              		.cfi_def_cfa_offset 0
 430              	.LBB18:
 431              	.LBB16:
 432              		.loc 3 74 25 view .LVU111
 433 0014 FFF7FEBF 		b	__aeabi_atexit
 434              	.LVL26:
 435              	.L19:
 436              		.align	2
 437              	.L18:
 438 0018 00000000 		.word	.LANCHOR1
 439 001c 00000000 		.word	__dso_handle
 440 0020 00000000 		.word	_ZNSt8ios_base4InitD1Ev
 441              	.LBE16:
 442              	.LBE18:
 443              		.cfi_endproc
 444              	.LFE2067:
 445              		.cantunwind
 446              		.fnend
 448              		.section	.init_array,"aw",%init_array
 449              		.align	2
 450 0000 00000000 		.word	_GLOBAL__sub_I_xtsaes128(target1)
 451              		.section	.text._ZN3XTSI6AES128S0_EC2Ev,"axG",%progbits,_ZN3XTSI6AES128S0_EC5Ev,comdat
 452              		.align	1
 453              		.weak	_ZN3XTSI6AES128S0_EC2Ev
 454              		.syntax unified
 455              		.thumb
 456              		.thumb_func
 457              		.fpu softvfp
 459              	_ZN3XTSI6AES128S0_EC2Ev:
 460              		.fnstart
 461              	.LVL27:
 462              	.LFB1812:
 463              		.file 4 "XTS.h"
   1:XTS.h         **** /*
   2:XTS.h         ****  * Copyright (C) 2016 Southern Storm Software, Pty Ltd.
   3:XTS.h         ****  *
   4:XTS.h         ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:XTS.h         ****  * copy of this software and associated documentation files (the "Software"),
   6:XTS.h         ****  * to deal in the Software without restriction, including without limitation
   7:XTS.h         ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:XTS.h         ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:XTS.h         ****  * Software is furnished to do so, subject to the following conditions:
  10:XTS.h         ****  *
  11:XTS.h         ****  * The above copyright notice and this permission notice shall be included
  12:XTS.h         ****  * in all copies or substantial portions of the Software.
  13:XTS.h         ****  *
  14:XTS.h         ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:XTS.h         ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:XTS.h         ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:XTS.h         ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:XTS.h         ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:XTS.h         ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:XTS.h         ****  * DEALINGS IN THE SOFTWARE.
  21:XTS.h         ****  */
  22:XTS.h         **** 
  23:XTS.h         **** #ifndef CRYPTO_XTS_h
  24:XTS.h         **** #define CRYPTO_XTS_h
  25:XTS.h         **** 
  26:XTS.h         **** #include "BlockCipher.h"
  27:XTS.h         **** 
  28:XTS.h         **** class XTSSingleKeyCommon;
  29:XTS.h         **** 
  30:XTS.h         **** class XTSCommon
  31:XTS.h         **** {
  32:XTS.h         **** public:
  33:XTS.h         ****     virtual ~XTSCommon();
  34:XTS.h         **** 
  35:XTS.h         ****     virtual size_t keySize() const;
  36:XTS.h         ****     size_t tweakSize() const;
  37:XTS.h         **** 
  38:XTS.h         ****     size_t sectorSize() const { return sectSize; }
  39:XTS.h         ****     bool setSectorSize(size_t size);
  40:XTS.h         **** 
  41:XTS.h         ****     virtual bool setKey(const uint8_t *key, size_t len);
  42:XTS.h         ****     bool setTweak(const uint8_t *tweak, size_t len);
  43:XTS.h         ****     // uint8_t setTweak(const uint8_t *tweak, size_t len);
  44:XTS.h         **** 
  45:XTS.h         ****     void encryptSector(uint8_t *output, const uint8_t *input, uint8_t iteration);
  46:XTS.h         ****     //void encryptSector(uint8_t *output, const uint8_t *input);
  47:XTS.h         ****     void decryptSector(uint8_t *output, const uint8_t *input);
  48:XTS.h         **** 
  49:XTS.h         ****     void clear();
  50:XTS.h         **** 
  51:XTS.h         **** protected:
  52:XTS.h         ****     XTSCommon();
  53:XTS.h         ****     void setBlockCiphers(BlockCipher *cipher1, BlockCipher *cipher2)
  54:XTS.h         ****     {
  55:XTS.h         ****         blockCipher1 = cipher1;
  56:XTS.h         ****         blockCipher2 = cipher2;
  57:XTS.h         ****     }
  58:XTS.h         **** 
  59:XTS.h         **** private:
  60:XTS.h         ****     BlockCipher *blockCipher1;
  61:XTS.h         ****     BlockCipher *blockCipher2;
  62:XTS.h         ****     uint32_t twk[4];
  63:XTS.h         ****     size_t sectSize;
  64:XTS.h         **** 
  65:XTS.h         ****     friend class XTSSingleKeyCommon;
  66:XTS.h         **** };
  67:XTS.h         **** 
  68:XTS.h         **** class XTSSingleKeyCommon : public XTSCommon
  69:XTS.h         **** {
  70:XTS.h         **** public:
  71:XTS.h         ****     virtual ~XTSSingleKeyCommon();
  72:XTS.h         **** 
  73:XTS.h         ****     size_t keySize() const;
  74:XTS.h         ****     bool setKey(const uint8_t *key, size_t len);
  75:XTS.h         **** 
  76:XTS.h         **** protected:
  77:XTS.h         ****     XTSSingleKeyCommon() : XTSCommon() {}
  78:XTS.h         **** };
  79:XTS.h         **** 
  80:XTS.h         **** template <typename T1, typename T2 = T1>
  81:XTS.h         **** class XTS : public XTSCommon
  82:XTS.h         **** {
  83:XTS.h         **** public:
  84:XTS.h         ****     XTS() { setBlockCiphers(&cipher1, &cipher2); }
 464              		.loc 4 84 5 is_stmt 1 view -0
 465              		.cfi_startproc
 466              		@ args = 0, pretend = 0, frame = 0
 467              		@ frame_needed = 0, uses_anonymous_args = 0
 468              		.loc 4 84 5 is_stmt 0 view .LVU113
 469 0000 70B5     		push	{r4, r5, r6, lr}
 470              		.save {r4, r5, r6, lr}
 471              	.LCFI9:
 472              		.cfi_def_cfa_offset 16
 473              		.cfi_offset 4, -16
 474              		.cfi_offset 5, -12
 475              		.cfi_offset 6, -8
 476              		.cfi_offset 14, -4
 477              		.loc 4 84 5 view .LVU114
 478 0002 0446     		mov	r4, r0
 479              	.LBB19:
 480              		.loc 4 84 11 view .LVU115
 481 0004 2546     		mov	r5, r4
 482              	.LEHB0:
 483 0006 FFF7FEFF 		bl	_ZN9XTSCommonC2Ev
 484              	.LVL28:
 485              	.LEHE0:
 486              		.loc 4 84 11 view .LVU116
 487 000a 0C4B     		ldr	r3, .L28
 488 000c 45F8203B 		str	r3, [r5], #32
 489 0010 2846     		mov	r0, r5
 490              	.LEHB1:
 491 0012 FFF7FEFF 		bl	_ZN6AES128C1Ev
 492              	.LVL29:
 493              	.LEHE1:
 494              		.loc 4 84 11 discriminator 2 view .LVU117
 495 0016 04F1DC06 		add	r6, r4, #220
 496 001a 3046     		mov	r0, r6
 497              	.LEHB2:
 498 001c FFF7FEFF 		bl	_ZN6AES128C1Ev
 499              	.LVL30:
 500              	.LEHE2:
 501 0020 08E0     		b	.L27
 502              	.L24:
 503              		.loc 4 84 11 view .LVU118
 504 0022 2846     		mov	r0, r5
 505 0024 FFF7FEFF 		bl	_ZN6AES128D1Ev
 506              	.LVL31:
 507              	.L22:
 508              		.loc 4 84 11 discriminator 1 view .LVU119
 509 0028 2046     		mov	r0, r4
 510 002a FFF7FEFF 		bl	_ZN9XTSCommonD2Ev
 511              	.LVL32:
 512              	.LEHB3:
 513 002e FFF7FEFF 		bl	__cxa_end_cleanup
 514              	.LVL33:
 515              	.LEHE3:
 516              	.L23:
 517              		.loc 4 84 11 discriminator 1 view .LVU120
 518 0032 F9E7     		b	.L22
 519              	.L27:
 520              	.LVL34:
 521              	.LBB20:
 522              	.LBI20:
  53:XTS.h         ****     {
 523              		.loc 4 53 10 is_stmt 1 discriminator 4 view .LVU121
 524              	.LBB21:
  55:XTS.h         ****         blockCipher2 = cipher2;
 525              		.loc 4 55 9 discriminator 4 view .LVU122
  56:XTS.h         ****     }
 526              		.loc 4 56 22 is_stmt 0 discriminator 4 view .LVU123
 527 0034 C4E90156 		strd	r5, r6, [r4, #4]
 528              	.LVL35:
  56:XTS.h         ****     }
 529              		.loc 4 56 22 discriminator 4 view .LVU124
 530              	.LBE21:
 531              	.LBE20:
 532              	.LBE19:
 533              		.loc 4 84 50 discriminator 4 view .LVU125
 534 0038 2046     		mov	r0, r4
 535 003a 70BD     		pop	{r4, r5, r6, pc}
 536              	.LVL36:
 537              	.L29:
 538              		.loc 4 84 50 discriminator 4 view .LVU126
 539              		.align	2
 540              	.L28:
 541 003c 08000000 		.word	_ZTV3XTSI6AES128S0_E+8
 542              		.cfi_endproc
 543              	.LFE1812:
 544              		.global	__gxx_personality_v0
 545              		.personality	__gxx_personality_v0
 546              		.handlerdata
 547              	.LLSDA1812:
 548 0008 FF       		.byte	0xff
 549 0009 FF       		.byte	0xff
 550 000a 01       		.byte	0x1
 551 000b 10       		.uleb128 .LLSDACSE1812-.LLSDACSB1812
 552              	.LLSDACSB1812:
 553 000c 06       		.uleb128 .LEHB0-.LFB1812
 554 000d 04       		.uleb128 .LEHE0-.LEHB0
 555 000e 00       		.uleb128 0
 556 000f 00       		.uleb128 0
 557 0010 12       		.uleb128 .LEHB1-.LFB1812
 558 0011 04       		.uleb128 .LEHE1-.LEHB1
 559 0012 32       		.uleb128 .L23-.LFB1812
 560 0013 00       		.uleb128 0
 561 0014 1C       		.uleb128 .LEHB2-.LFB1812
 562 0015 04       		.uleb128 .LEHE2-.LEHB2
 563 0016 22       		.uleb128 .L24-.LFB1812
 564 0017 00       		.uleb128 0
 565 0018 2E       		.uleb128 .LEHB3-.LFB1812
 566 0019 04       		.uleb128 .LEHE3-.LEHB3
 567 001a 00       		.uleb128 0
 568 001b 00       		.uleb128 0
 569              	.LLSDACSE1812:
 570              		.section	.text._ZN3XTSI6AES128S0_EC2Ev,"axG",%progbits,_ZN3XTSI6AES128S0_EC5Ev,comdat
 571              		.fnend
 573              		.weak	_ZN3XTSI6AES128S0_EC1Ev
 574              		.thumb_set _ZN3XTSI6AES128S0_EC1Ev,_ZN3XTSI6AES128S0_EC2Ev
 575              		.section	.text.startup.main,"ax",%progbits
 576              		.align	1
 577              		.global	main
 578              		.syntax unified
 579              		.thumb
 580              		.thumb_func
 581              		.fpu softvfp
 583              	main:
 584              		.fnstart
 585              	.LFB1567:
 647:main.cpp      ****     
 586              		.loc 2 647 12 is_stmt 1 view -0
 587              		.cfi_startproc
 588              		@ args = 0, pretend = 0, frame = 0
 589              		@ frame_needed = 0, uses_anonymous_args = 0
 649:main.cpp      ****     platform_init();
 590              		.loc 2 649 5 view .LVU128
 647:main.cpp      ****     
 591              		.loc 2 647 12 is_stmt 0 view .LVU129
 592 0000 10B5     		push	{r4, lr}
 593              		.save {r4, lr}
 594              	.LCFI10:
 595              		.cfi_def_cfa_offset 8
 596              		.cfi_offset 4, -8
 597              		.cfi_offset 14, -4
 649:main.cpp      ****     platform_init();
 598              		.loc 2 649 33 view .LVU130
 599 0002 4FF4CC70 		mov	r0, #408
 600              	.LEHB4:
 601 0006 FFF7FEFF 		bl	_Znwj
 602              	.LVL37:
 603              	.LEHE4:
 604 000a 0446     		mov	r4, r0
 605              	.LEHB5:
 606 000c FFF7FEFF 		bl	_ZN3XTSI6AES128S0_EC1Ev
 607              	.LVL38:
 608              	.LEHE5:
 649:main.cpp      ****     platform_init();
 609              		.loc 2 649 15 view .LVU131
 610 0010 0E4B     		ldr	r3, .L34
 611 0012 5C60     		str	r4, [r3, #4]
 650:main.cpp      ****     init_uart();
 612              		.loc 2 650 5 is_stmt 1 view .LVU132
 613              	.LEHB6:
 650:main.cpp      ****     init_uart();
 614              		.loc 2 650 18 is_stmt 0 view .LVU133
 615 0014 FFF7FEFF 		bl	platform_init
 616              	.LVL39:
 651:main.cpp      ****     trigger_setup();
 617              		.loc 2 651 5 is_stmt 1 view .LVU134
 651:main.cpp      ****     trigger_setup();
 618              		.loc 2 651 14 is_stmt 0 view .LVU135
 619 0018 FFF7FEFF 		bl	init_uart
 620              	.LVL40:
 652:main.cpp      ****     simpleserial_init();
 621              		.loc 2 652 5 is_stmt 1 view .LVU136
 652:main.cpp      ****     simpleserial_init();
 622              		.loc 2 652 18 is_stmt 0 view .LVU137
 623 001c FFF7FEFF 		bl	trigger_setup
 624              	.LVL41:
 653:main.cpp      ****     //simpleserial_addcmd('t', 0, run_tests);
 625              		.loc 2 653 5 is_stmt 1 view .LVU138
 653:main.cpp      ****     //simpleserial_addcmd('t', 0, run_tests);
 626              		.loc 2 653 22 is_stmt 0 view .LVU139
 627 0020 FFF7FEFF 		bl	simpleserial_init
 628              	.LVL42:
 657:main.cpp      **** 
 629              		.loc 2 657 5 is_stmt 1 view .LVU140
 657:main.cpp      **** 
 630              		.loc 2 657 24 is_stmt 0 view .LVU141
 631 0024 0A4A     		ldr	r2, .L34+4
 632 0026 0121     		movs	r1, #1
 633 0028 7320     		movs	r0, #115
 634 002a FFF7FEFF 		bl	simpleserial_addcmd
 635              	.LVL43:
 659:main.cpp      ****     //simpleserial_addcmd('s', 0, run_single);
 636              		.loc 2 659 5 is_stmt 1 view .LVU142
 659:main.cpp      ****     //simpleserial_addcmd('s', 0, run_single);
 637              		.loc 2 659 24 is_stmt 0 view .LVU143
 638 002e 094A     		ldr	r2, .L34+8
 639 0030 0021     		movs	r1, #0
 640 0032 6320     		movs	r0, #99
 641 0034 FFF7FEFF 		bl	simpleserial_addcmd
 642              	.LVL44:
 643              	.L31:
 662:main.cpp      ****         simpleserial_get();
 644              		.loc 2 662 5 is_stmt 1 discriminator 1 view .LVU144
 663:main.cpp      ****     }
 645              		.loc 2 663 9 discriminator 1 view .LVU145
 663:main.cpp      ****     }
 646              		.loc 2 663 25 is_stmt 0 discriminator 1 view .LVU146
 647 0038 FFF7FEFF 		bl	simpleserial_get
 648              	.LVL45:
 662:main.cpp      ****         simpleserial_get();
 649              		.loc 2 662 5 is_stmt 1 discriminator 1 view .LVU147
 650 003c FCE7     		b	.L31
 651              	.L33:
 649:main.cpp      ****     platform_init();
 652              		.loc 2 649 33 is_stmt 0 view .LVU148
 653 003e 4FF4CC71 		mov	r1, #408
 654 0042 2046     		mov	r0, r4
 655 0044 FFF7FEFF 		bl	_ZdlPvj
 656              	.LVL46:
 657 0048 FFF7FEFF 		bl	__cxa_end_cleanup
 658              	.LVL47:
 659              	.LEHE6:
 660              	.L35:
 661              		.align	2
 662              	.L34:
 663 004c 00000000 		.word	.LANCHOR1
 664 0050 00000000 		.word	_Z14attack_examplehhhPh
 665 0054 00000000 		.word	_Z8tenTweakhhhPh
 666              		.cfi_endproc
 667              	.LFE1567:
 668              		.personality	__gxx_personality_v0
 669              		.handlerdata
 670              	.LLSDA1567:
 671 0008 FF       		.byte	0xff
 672 0009 FF       		.byte	0xff
 673 000a 01       		.byte	0x1
 674 000b 0C       		.uleb128 .LLSDACSE1567-.LLSDACSB1567
 675              	.LLSDACSB1567:
 676 000c 06       		.uleb128 .LEHB4-.LFB1567
 677 000d 04       		.uleb128 .LEHE4-.LEHB4
 678 000e 00       		.uleb128 0
 679 000f 00       		.uleb128 0
 680 0010 0C       		.uleb128 .LEHB5-.LFB1567
 681 0011 04       		.uleb128 .LEHE5-.LEHB5
 682 0012 3E       		.uleb128 .L33-.LFB1567
 683 0013 00       		.uleb128 0
 684 0014 14       		.uleb128 .LEHB6-.LFB1567
 685 0015 38       		.uleb128 .LEHE6-.LEHB6
 686 0016 00       		.uleb128 0
 687 0017 00       		.uleb128 0
 688              	.LLSDACSE1567:
 689              		.section	.text.startup.main
 690              		.fnend
 692              		.section	.text._ZN3XTSI6AES128S0_ED2Ev,"axG",%progbits,_ZN3XTSI6AES128S0_ED5Ev,comdat
 693              		.align	1
 694              		.weak	_ZN3XTSI6AES128S0_ED2Ev
 695              		.syntax unified
 696              		.thumb
 697              		.thumb_func
 698              		.fpu softvfp
 700              	_ZN3XTSI6AES128S0_ED2Ev:
 701              		.fnstart
 702              	.LVL48:
 703              	.LFB1815:
  85:XTS.h         ****     ~XTS() {}
 704              		.loc 4 85 5 is_stmt 1 view -0
 705              		.cfi_startproc
 706              		@ args = 0, pretend = 0, frame = 0
 707              		@ frame_needed = 0, uses_anonymous_args = 0
 708              		.loc 4 85 5 is_stmt 0 view .LVU150
 709 0000 10B5     		push	{r4, lr}
 710              	.LCFI11:
 711              		.cfi_def_cfa_offset 8
 712              		.cfi_offset 4, -8
 713              		.cfi_offset 14, -4
 714              	.LBB22:
 715              		.loc 4 85 13 view .LVU151
 716 0002 074B     		ldr	r3, .L37
 717              	.LBE22:
 718              		.loc 4 85 5 view .LVU152
 719 0004 0446     		mov	r4, r0
 720              	.LBB23:
 721              		.loc 4 85 13 view .LVU153
 722 0006 40F8DC3B 		str	r3, [r0], #220
 723              	.LVL49:
 724              		.loc 4 85 13 view .LVU154
 725 000a FFF7FEFF 		bl	_ZN6AES128D1Ev
 726              	.LVL50:
 727 000e 04F12000 		add	r0, r4, #32
 728 0012 FFF7FEFF 		bl	_ZN6AES128D1Ev
 729              	.LVL51:
 730 0016 2046     		mov	r0, r4
 731 0018 FFF7FEFF 		bl	_ZN9XTSCommonD2Ev
 732              	.LVL52:
 733              	.LBE23:
 734 001c 2046     		mov	r0, r4
 735 001e 10BD     		pop	{r4, pc}
 736              	.LVL53:
 737              	.L38:
 738              		.loc 4 85 13 view .LVU155
 739              		.align	2
 740              	.L37:
 741 0020 08000000 		.word	_ZTV3XTSI6AES128S0_E+8
 742              		.cfi_endproc
 743              	.LFE1815:
 744              		.cantunwind
 745              		.fnend
 747              		.weak	_ZN3XTSI6AES128S0_ED1Ev
 748              		.thumb_set _ZN3XTSI6AES128S0_ED1Ev,_ZN3XTSI6AES128S0_ED2Ev
 749              		.section	.text._Z14attack_examplehhhPh,"ax",%progbits
 750              		.align	1
 751              		.global	_Z14attack_examplehhhPh
 752              		.syntax unified
 753              		.thumb
 754              		.thumb_func
 755              		.fpu softvfp
 757              	_Z14attack_examplehhhPh:
 758              		.fnstart
 759              	.LVL54:
 760              	.LFB1566:
 591:main.cpp      **** 
 761              		.loc 2 591 78 is_stmt 1 view -0
 762              		.cfi_startproc
 763              		@ args = 0, pretend = 0, frame = 2456
 764              		@ frame_needed = 0, uses_anonymous_args = 0
 593:main.cpp      ****     byte buffer[MAX_SECTOR_SIZE];
 765              		.loc 2 593 5 view .LVU157
 591:main.cpp      **** 
 766              		.loc 2 591 78 is_stmt 0 view .LVU158
 767 0000 10B5     		push	{r4, lr}
 768              		.save {r4, lr}
 769              	.LCFI12:
 770              		.cfi_def_cfa_offset 8
 771              		.cfi_offset 4, -8
 772              		.cfi_offset 14, -4
 773              		.pad #2456
 774 0002 ADF6981D 		subw	sp, sp, #2456
 775              	.LCFI13:
 776              		.cfi_def_cfa_offset 2464
 591:main.cpp      **** 
 777              		.loc 2 591 78 view .LVU159
 778 0006 1C46     		mov	r4, r3
 593:main.cpp      ****     byte buffer[MAX_SECTOR_SIZE];
 779              		.loc 2 593 17 view .LVU160
 780 0008 6846     		mov	r0, sp
 781              	.LVL55:
 782              	.LEHB7:
 593:main.cpp      ****     byte buffer[MAX_SECTOR_SIZE];
 783              		.loc 2 593 17 view .LVU161
 784 000a FFF7FEFF 		bl	_ZN3XTSI6AES128S0_EC1Ev
 785              	.LVL56:
 786              	.LEHE7:
 594:main.cpp      ****     bool passed = true;
 787              		.loc 2 594 5 is_stmt 1 view .LVU162
 595:main.cpp      **** 
 788              		.loc 2 595 5 view .LVU163
 598:main.cpp      ****     
 789              		.loc 2 598 5 view .LVU164
 602:main.cpp      ****     cipher.setKey(attackVector.key1, 32); // Assuming 32 bytes for key1 and key2 combined
 790              		.loc 2 602 25 is_stmt 0 view .LVU165
 791 000e 4FF40061 		mov	r1, #2048
 792 0012 6846     		mov	r0, sp
 598:main.cpp      ****     
 793              		.loc 2 598 13 view .LVU166
 794 0014 2478     		ldrb	r4, [r4]	@ zero_extendqisi2
 795              	.LVL57:
 602:main.cpp      ****     cipher.setKey(attackVector.key1, 32); // Assuming 32 bytes for key1 and key2 combined
 796              		.loc 2 602 5 is_stmt 1 view .LVU167
 797              	.LEHB8:
 602:main.cpp      ****     cipher.setKey(attackVector.key1, 32); // Assuming 32 bytes for key1 and key2 combined
 798              		.loc 2 602 25 is_stmt 0 view .LVU168
 799 0016 FFF7FEFF 		bl	_ZN9XTSCommon13setSectorSizeEj
 800              	.LVL58:
 603:main.cpp      ****     cipher.setTweak(attackVector.tweak, sizeof(attackVector.tweak));
 801              		.loc 2 603 5 is_stmt 1 view .LVU169
 603:main.cpp      ****     cipher.setTweak(attackVector.tweak, sizeof(attackVector.tweak));
 802              		.loc 2 603 18 is_stmt 0 view .LVU170
 803 001a 0E49     		ldr	r1, .L45
 804 001c 2022     		movs	r2, #32
 805 001e 6846     		mov	r0, sp
 806 0020 FFF7FEFF 		bl	_ZN9XTSCommon6setKeyEPKhj
 807              	.LVL59:
 604:main.cpp      ****     cipher.encryptSector(buffer, attackVector.plaintext, iter); // In-place encryption
 808              		.loc 2 604 5 is_stmt 1 view .LVU171
 604:main.cpp      ****     cipher.encryptSector(buffer, attackVector.plaintext, iter); // In-place encryption
 809              		.loc 2 604 20 is_stmt 0 view .LVU172
 810 0024 0C49     		ldr	r1, .L45+4
 811 0026 1022     		movs	r2, #16
 812 0028 6846     		mov	r0, sp
 813 002a FFF7FEFF 		bl	_ZN9XTSCommon8setTweakEPKhj
 814              	.LVL60:
 605:main.cpp      ****     //cipher.encryptSector(buffer, attackVector.plaintext); // In-place encryption
 815              		.loc 2 605 5 is_stmt 1 view .LVU173
 605:main.cpp      ****     //cipher.encryptSector(buffer, attackVector.plaintext); // In-place encryption
 816              		.loc 2 605 25 is_stmt 0 view .LVU174
 817 002e 0B4A     		ldr	r2, .L45+8
 818 0030 2346     		mov	r3, r4
 819 0032 66A9     		add	r1, sp, #408
 820 0034 6846     		mov	r0, sp
 821 0036 FFF7FEFF 		bl	_ZN9XTSCommon13encryptSectorEPhPKhh
 822              	.LVL61:
 823              	.LEHE8:
 824 003a 04E0     		b	.L44
 825              	.L41:
 593:main.cpp      ****     byte buffer[MAX_SECTOR_SIZE];
 826              		.loc 2 593 17 view .LVU175
 827 003c 6846     		mov	r0, sp
 828 003e FFF7FEFF 		bl	_ZN3XTSI6AES128S0_ED1Ev
 829              	.LVL62:
 830              	.LEHB9:
 831 0042 FFF7FEFF 		bl	__cxa_end_cleanup
 832              	.LVL63:
 833              	.LEHE9:
 834              	.L44:
 618:main.cpp      **** }
 835              		.loc 2 618 5 is_stmt 1 view .LVU176
 593:main.cpp      ****     byte buffer[MAX_SECTOR_SIZE];
 836              		.loc 2 593 17 is_stmt 0 view .LVU177
 837 0046 6846     		mov	r0, sp
 838 0048 FFF7FEFF 		bl	_ZN3XTSI6AES128S0_ED1Ev
 839              	.LVL64:
 619:main.cpp      **** /*
 840              		.loc 2 619 1 view .LVU178
 841 004c 0020     		movs	r0, #0
 842 004e 0DF6981D 		addw	sp, sp, #2456
 843              	.LCFI14:
 844              		.cfi_def_cfa_offset 8
 845              		@ sp needed
 846 0052 10BD     		pop	{r4, pc}
 847              	.LVL65:
 848              	.L46:
 619:main.cpp      **** /*
 849              		.loc 2 619 1 view .LVU179
 850              		.align	2
 851              	.L45:
 852 0054 14000000 		.word	_ZL12attackVector+4
 853 0058 34100000 		.word	_ZL12attackVector+4132
 854 005c 34000000 		.word	_ZL12attackVector+36
 855              		.cfi_endproc
 856              	.LFE1566:
 857              		.personality	__gxx_personality_v0
 858              		.handlerdata
 859              	.LLSDA1566:
 860 000c FF       		.byte	0xff
 861 000d FF       		.byte	0xff
 862 000e 01       		.byte	0x1
 863 000f 0C       		.uleb128 .LLSDACSE1566-.LLSDACSB1566
 864              	.LLSDACSB1566:
 865 0010 0A       		.uleb128 .LEHB7-.LFB1566
 866 0011 04       		.uleb128 .LEHE7-.LEHB7
 867 0012 00       		.uleb128 0
 868 0013 00       		.uleb128 0
 869 0014 16       		.uleb128 .LEHB8-.LFB1566
 870 0015 24       		.uleb128 .LEHE8-.LEHB8
 871 0016 3C       		.uleb128 .L41-.LFB1566
 872 0017 00       		.uleb128 0
 873 0018 42       		.uleb128 .LEHB9-.LFB1566
 874 0019 04       		.uleb128 .LEHE9-.LEHB9
 875 001a 00       		.uleb128 0
 876 001b 00       		.uleb128 0
 877              	.LLSDACSE1566:
 878              		.section	.text._Z14attack_examplehhhPh
 879              		.fnend
 881              		.section	.text._ZN3XTSI6AES128S0_ED0Ev,"axG",%progbits,_ZN3XTSI6AES128S0_ED5Ev,comdat
 882              		.align	1
 883              		.weak	_ZN3XTSI6AES128S0_ED0Ev
 884              		.syntax unified
 885              		.thumb
 886              		.thumb_func
 887              		.fpu softvfp
 889              	_ZN3XTSI6AES128S0_ED0Ev:
 890              		.fnstart
 891              	.LVL66:
 892              	.LFB1817:
 893              		.loc 4 85 5 is_stmt 1 view -0
 894              		.cfi_startproc
 895              		@ args = 0, pretend = 0, frame = 0
 896              		@ frame_needed = 0, uses_anonymous_args = 0
 897              		.loc 4 85 5 is_stmt 0 view .LVU181
 898 0000 10B5     		push	{r4, lr}
 899              	.LCFI15:
 900              		.cfi_def_cfa_offset 8
 901              		.cfi_offset 4, -8
 902              		.cfi_offset 14, -4
 903              		.loc 4 85 5 view .LVU182
 904 0002 0446     		mov	r4, r0
 905              		.loc 4 85 13 view .LVU183
 906 0004 FFF7FEFF 		bl	_ZN3XTSI6AES128S0_ED1Ev
 907              	.LVL67:
 908              		.loc 4 85 13 view .LVU184
 909 0008 2046     		mov	r0, r4
 910 000a 4FF4CC71 		mov	r1, #408
 911 000e FFF7FEFF 		bl	_ZdlPvj
 912              	.LVL68:
 913 0012 2046     		mov	r0, r4
 914 0014 10BD     		pop	{r4, pc}
 915              		.loc 4 85 13 view .LVU185
 916              		.cfi_endproc
 917              	.LFE1817:
 918              		.cantunwind
 919              		.fnend
 921              		.weak	_ZTS3XTSI6AES128S0_E
 922              		.section	.rodata._ZTS3XTSI6AES128S0_E,"aG",%progbits,_ZTS3XTSI6AES128S0_E,comdat
 925              	_ZTS3XTSI6AES128S0_E:
 926 0000 33585453 		.ascii	"3XTSI6AES128S0_E\000"
 926      49364145 
 926      53313238 
 926      53305F45 
 926      00
 927              		.weak	_ZTI3XTSI6AES128S0_E
 928              		.section	.rodata._ZTI3XTSI6AES128S0_E,"aG",%progbits,_ZTI3XTSI6AES128S0_E,comdat
 929              		.align	2
 932              	_ZTI3XTSI6AES128S0_E:
 933 0000 08000000 		.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
 934 0004 00000000 		.word	_ZTS3XTSI6AES128S0_E
 935 0008 00000000 		.word	_ZTI9XTSCommon
 936              		.weak	_ZTV3XTSI6AES128S0_E
 937              		.section	.rodata._ZTV3XTSI6AES128S0_E,"aG",%progbits,_ZTV3XTSI6AES128S0_E,comdat
 938              		.align	2
 941              	_ZTV3XTSI6AES128S0_E:
 942 0000 00000000 		.word	0
 943 0004 00000000 		.word	_ZTI3XTSI6AES128S0_E
 944 0008 00000000 		.word	_ZN3XTSI6AES128S0_ED1Ev
 945 000c 00000000 		.word	_ZN3XTSI6AES128S0_ED0Ev
 946 0010 00000000 		.word	_ZNK9XTSCommon7keySizeEv
 947 0014 00000000 		.word	_ZN9XTSCommon6setKeyEPKhj
 948              		.global	buffer
 949              		.global	testVector
 950              		.global	xtsaes128
 951              		.section	.rodata.str1.1
 952              	.LC2:
 953 0011 41545441 		.ascii	"ATTACK VECTOR TEST\000"
 953      434B2056 
 953      4543544F 
 953      52205445 
 953      535400
 954              		.section	.rodata
 955              		.align	2
 956              		.set	.LANCHOR0,. + 0
 957              	.LC1:
 958 0000 00000000 		.ascii	"\000\000\000\000\000\000\000\000\000\000\000\000\000"
 958      00000000 
 958      00000000 
 958      00
 959 000d 000000   		.ascii	"\000\000\000"
 962              	_ZL12attackVector:
 963 0010 11000000 		.word	.LC2
 964 0014 27182818 		.ascii	"'\030(\030(E\220E#S`(tq5&"
 964      28459045 
 964      23536028 
 964      74713526 
 965 0024 31415926 		.ascii	"1AY&SX\227\223#\204bd3\203'\225"
 965      53589793 
 965      23846264 
 965      33832795 
 966 0034 00010203 		.ascii	"\000\001\002\003\004\005\006\007\010\011\012\013\014"
 966      04050607 
 966      08090A0B 
 966      0C
 967 0041 0D0E0F10 		.ascii	"\015\016\017\020\021\022\023\024\025\026\027\030\031"
 967      11121314 
 967      15161718 
 967      19
 968 004e 1A1B1C1D 		.ascii	"\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789"
 968      1E1F2021 
 968      22232425 
 968      26272829 
 968      2A2B2C2D 
 969 006e 3A3B3C3D 		.ascii	":;<=>?\000\001\002\003\004\005\006\007\010\011\012\013"
 969      3E3F0001 
 969      02030405 
 969      06070809 
 969      0A0B
 970 0080 0C0D0E0F 		.ascii	"\014\015\016\017\020\021\022\023\024\025\026\027\030"
 970      10111213 
 970      14151617 
 970      18
 971 008d 191A1B1C 		.ascii	"\031\032\033\034\035\036\037 !\"#$%&'()*+,-./012345"
 971      1D1E1F20 
 971      21222324 
 971      25262728 
 971      292A2B2C 
 972 00aa 36373839 		.ascii	"6789:;<=>?\000\001\002\003\004\005\006\007\010\011\012"
 972      3A3B3C3D 
 972      3E3F0001 
 972      02030405 
 972      06070809 
 973 00bf 0B0C0D0E 		.ascii	"\013\014\015\016\017\020\021\022\023\024\025\026\027"
 973      0F101112 
 973      13141516 
 973      17
 974 00cc 18191A1B 		.ascii	"\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./01"
 974      1C1D1E1F 
 974      20212223 
 974      24252627 
 974      28292A2B 
 975 00e6 32333435 		.ascii	"23456789:;<=>?\000\001\002\003\004\005\006\007\010\011"
 975      36373839 
 975      3A3B3C3D 
 975      3E3F0001 
 975      02030405 
 976 00fe 0A0B0C0D 		.ascii	"\012\013\014\015\016\017\020\021\022\023\024\025\026"
 976      0E0F1011 
 976      12131415 
 976      16
 977 010b 1718191A 		.ascii	"\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-"
 977      1B1C1D1E 
 977      1F202122 
 977      23242526 
 977      2728292A 
 978 0122 2E2F3031 		.ascii	"./0123456789:;<=>?\000\001\002\003\004\005\006\007\010"
 978      32333435 
 978      36373839 
 978      3A3B3C3D 
 978      3E3F0001 
 979 013d 090A0B0C 		.ascii	"\011\012\013\014\015\016\017\020\021\022\023\024\025"
 979      0D0E0F10 
 979      11121314 
 979      15
 980 014a 16171819 		.ascii	"\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()"
 980      1A1B1C1D 
 980      1E1F2021 
 980      22232425 
 980      26272829 
 981 015e 2A2B2C2D 		.ascii	"*+,-./0123456789:;<=>?\000\001\002\003\004\005\006\007"
 981      2E2F3031 
 981      32333435 
 981      36373839 
 981      3A3B3C3D 
 982 017c 08090A0B 		.ascii	"\010\011\012\013\014\015\016\017\020\021\022\023\024"
 982      0C0D0E0F 
 982      10111213 
 982      14
 983 0189 15161718 		.ascii	"\025\026\027\030\031\032\033\034\035\036\037 !\"#$%"
 983      191A1B1C 
 983      1D1E1F20 
 983      21222324 
 983      25
 984 019a 26272829 		.ascii	"&'()*+,-./0123456789:;<=>?\000\001\002\003\004\005\006"
 984      2A2B2C2D 
 984      2E2F3031 
 984      32333435 
 984      36373839 
 985 01bb 0708090A 		.ascii	"\007\010\011\012\013\014\015\016\017\020\021\022\023"
 985      0B0C0D0E 
 985      0F101112 
 985      13
 986 01c8 14151617 		.ascii	"\024\025\026\027\030\031\032\033\034\035\036\037 !\""
 986      18191A1B 
 986      1C1D1E1F 
 986      202122
 987 01d7 23242526 		.ascii	"#$%&'()*+,-./0123456789:;<=>?\000\001\002\003\004\005"
 987      2728292A 
 987      2B2C2D2E 
 987      2F303132 
 987      33343536 
 988 01fa 06070809 		.ascii	"\006\007\010\011\012\013\014\015\016\017\020\021\022"
 988      0A0B0C0D 
 988      0E0F1011 
 988      12
 989 0207 13141516 		.ascii	"\023\024\025\026\027\030\031\032\033\034\035\036\037"
 989      1718191A 
 989      1B1C1D1E 
 989      1F
 990 0214 20212223 		.ascii	" !\"#$%&'()*+,-./0123456789:;<=>?\000\001\002\003\004"
 990      24252627 
 990      28292A2B 
 990      2C2D2E2F 
 990      30313233 
 991 0239 05060708 		.ascii	"\005\006\007\010\011\012\013\014\015\016\017\020\021"
 991      090A0B0C 
 991      0D0E0F10 
 991      11
 992 0246 12131415 		.ascii	"\022\023\024\025\026\027\030\031\032\033\034\035\036"
 992      16171819 
 992      1A1B1C1D 
 992      1E
 993 0253 1F202122 		.ascii	"\037 !\"#$%&'()*+,-./0123456789:;<=>?\000\001\002\003"
 993      23242526 
 993      2728292A 
 993      2B2C2D2E 
 993      2F303132 
 994 0278 04050607 		.ascii	"\004\005\006\007\010\011\012\013\014\015\016\017\020"
 994      08090A0B 
 994      0C0D0E0F 
 994      10
 995 0285 11121314 		.ascii	"\021\022\023\024\025\026\027\030\031\032\033\034\035"
 995      15161718 
 995      191A1B1C 
 995      1D
 996 0292 1E1F2021 		.ascii	"\036\037 !\"#$%&'()*+,-./0123456789:;<=>?\000\001\002"
 996      22232425 
 996      26272829 
 996      2A2B2C2D 
 996      2E2F3031 
 997 02b7 03040506 		.ascii	"\003\004\005\006\007\010\011\012\013\014\015\016\017"
 997      0708090A 
 997      0B0C0D0E 
 997      0F
 998 02c4 10111213 		.ascii	"\020\021\022\023\024\025\026\027\030\031\032\033\034"
 998      14151617 
 998      18191A1B 
 998      1C
 999 02d1 1D1E1F20 		.ascii	"\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?\000\001"
 999      21222324 
 999      25262728 
 999      292A2B2C 
 999      2D2E2F30 
 1000 02f6 02030405 		.ascii	"\002\003\004\005\006\007\010\011\012\013\014\015\016"
 1000      06070809 
 1000      0A0B0C0D 
 1000      0E
 1001 0303 0F101112 		.ascii	"\017\020\021\022\023\024\025\026\027\030\031\032\033"
 1001      13141516 
 1001      1718191A 
 1001      1B
 1002 0310 1C1D1E1F 		.ascii	"\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?\000"
 1002      20212223 
 1002      24252627 
 1002      28292A2B 
 1002      2C2D2E2F 
 1003 0335 01020304 		.ascii	"\001\002\003\004\005\006\007\010\011\012\013\014\015"
 1003      05060708 
 1003      090A0B0C 
 1003      0D
 1004 0342 0E0F1011 		.ascii	"\016\017\020\021\022\023\024\025\026\027\030\031\032"
 1004      12131415 
 1004      16171819 
 1004      1A
 1005 034f 1B1C1D1E 		.ascii	"\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<="
 1005      1F202122 
 1005      23242526 
 1005      2728292A 
 1005      2B2C2D2E 
 1006 0372 3E3F0001 		.ascii	">?\000\001\002\003\004\005\006\007\010\011\012\013\014"
 1006      02030405 
 1006      06070809 
 1006      0A0B0C
 1007 0381 0D0E0F10 		.ascii	"\015\016\017\020\021\022\023\024\025\026\027\030\031"
 1007      11121314 
 1007      15161718 
 1007      19
 1008 038e 1A1B1C1D 		.ascii	"\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789"
 1008      1E1F2021 
 1008      22232425 
 1008      26272829 
 1008      2A2B2C2D 
 1009 03ae 3A3B3C3D 		.ascii	":;<=>?\000\001\002\003\004\005\006\007\010\011\012\013"
 1009      3E3F0001 
 1009      02030405 
 1009      06070809 
 1009      0A0B
 1010 03c0 0C0D0E0F 		.ascii	"\014\015\016\017\020\021\022\023\024\025\026\027\030"
 1010      10111213 
 1010      14151617 
 1010      18
 1011 03cd 191A1B1C 		.ascii	"\031\032\033\034\035\036\037 !\"#$%&'()*+,-./012345"
 1011      1D1E1F20 
 1011      21222324 
 1011      25262728 
 1011      292A2B2C 
 1012 03ea 36373839 		.ascii	"6789:;<=>?\000\001\002\003\004\005\006\007\010\011\012"
 1012      3A3B3C3D 
 1012      3E3F0001 
 1012      02030405 
 1012      06070809 
 1013 03ff 0B0C0D0E 		.ascii	"\013\014\015\016\017\020\021\022\023\024\025\026\027"
 1013      0F101112 
 1013      13141516 
 1013      17
 1014 040c 18191A1B 		.ascii	"\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./01"
 1014      1C1D1E1F 
 1014      20212223 
 1014      24252627 
 1014      28292A2B 
 1015 0426 32333435 		.ascii	"23456789:;<=>?\000\001\002\003\004\005\006\007\010\011"
 1015      36373839 
 1015      3A3B3C3D 
 1015      3E3F0001 
 1015      02030405 
 1016 043e 0A0B0C0D 		.ascii	"\012\013\014\015\016\017\020\021\022\023\024\025\026"
 1016      0E0F1011 
 1016      12131415 
 1016      16
 1017 044b 1718191A 		.ascii	"\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-"
 1017      1B1C1D1E 
 1017      1F202122 
 1017      23242526 
 1017      2728292A 
 1018 0462 2E2F3031 		.ascii	"./0123456789:;<=>?\000\001\002\003\004\005\006\007\010"
 1018      32333435 
 1018      36373839 
 1018      3A3B3C3D 
 1018      3E3F0001 
 1019 047d 090A0B0C 		.ascii	"\011\012\013\014\015\016\017\020\021\022\023\024\025"
 1019      0D0E0F10 
 1019      11121314 
 1019      15
 1020 048a 16171819 		.ascii	"\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()"
 1020      1A1B1C1D 
 1020      1E1F2021 
 1020      22232425 
 1020      26272829 
 1021 049e 2A2B2C2D 		.ascii	"*+,-./0123456789:;<=>?\000\001\002\003\004\005\006\007"
 1021      2E2F3031 
 1021      32333435 
 1021      36373839 
 1021      3A3B3C3D 
 1022 04bc 08090A0B 		.ascii	"\010\011\012\013\014\015\016\017\020\021\022\023\024"
 1022      0C0D0E0F 
 1022      10111213 
 1022      14
 1023 04c9 15161718 		.ascii	"\025\026\027\030\031\032\033\034\035\036\037 !\"#$%"
 1023      191A1B1C 
 1023      1D1E1F20 
 1023      21222324 
 1023      25
 1024 04da 26272829 		.ascii	"&'()*+,-./0123456789:;<=>?\000\001\002\003\004\005\006"
 1024      2A2B2C2D 
 1024      2E2F3031 
 1024      32333435 
 1024      36373839 
 1025 04fb 0708090A 		.ascii	"\007\010\011\012\013\014\015\016\017\020\021\022\023"
 1025      0B0C0D0E 
 1025      0F101112 
 1025      13
 1026 0508 14151617 		.ascii	"\024\025\026\027\030\031\032\033\034\035\036\037 !\""
 1026      18191A1B 
 1026      1C1D1E1F 
 1026      202122
 1027 0517 23242526 		.ascii	"#$%&'()*+,-./0123456789:;<=>?\000\001\002\003\004\005"
 1027      2728292A 
 1027      2B2C2D2E 
 1027      2F303132 
 1027      33343536 
 1028 053a 06070809 		.ascii	"\006\007\010\011\012\013\014\015\016\017\020\021\022"
 1028      0A0B0C0D 
 1028      0E0F1011 
 1028      12
 1029 0547 13141516 		.ascii	"\023\024\025\026\027\030\031\032\033\034\035\036\037"
 1029      1718191A 
 1029      1B1C1D1E 
 1029      1F
 1030 0554 20212223 		.ascii	" !\"#$%&'()*+,-./0123456789:;<=>?\000\001\002\003\004"
 1030      24252627 
 1030      28292A2B 
 1030      2C2D2E2F 
 1030      30313233 
 1031 0579 05060708 		.ascii	"\005\006\007\010\011\012\013\014\015\016\017\020\021"
 1031      090A0B0C 
 1031      0D0E0F10 
 1031      11
 1032 0586 12131415 		.ascii	"\022\023\024\025\026\027\030\031\032\033\034\035\036"
 1032      16171819 
 1032      1A1B1C1D 
 1032      1E
 1033 0593 1F202122 		.ascii	"\037 !\"#$%&'()*+,-./0123456789:;<=>?\000\001\002\003"
 1033      23242526 
 1033      2728292A 
 1033      2B2C2D2E 
 1033      2F303132 
 1034 05b8 04050607 		.ascii	"\004\005\006\007\010\011\012\013\014\015\016\017\020"
 1034      08090A0B 
 1034      0C0D0E0F 
 1034      10
 1035 05c5 11121314 		.ascii	"\021\022\023\024\025\026\027\030\031\032\033\034\035"
 1035      15161718 
 1035      191A1B1C 
 1035      1D
 1036 05d2 1E1F2021 		.ascii	"\036\037 !\"#$%&'()*+,-./0123456789:;<=>?\000\001\002"
 1036      22232425 
 1036      26272829 
 1036      2A2B2C2D 
 1036      2E2F3031 
 1037 05f7 03040506 		.ascii	"\003\004\005\006\007\010\011\012\013\014\015\016\017"
 1037      0708090A 
 1037      0B0C0D0E 
 1037      0F
 1038 0604 10111213 		.ascii	"\020\021\022\023\024\025\026\027\030\031\032\033\034"
 1038      14151617 
 1038      18191A1B 
 1038      1C
 1039 0611 1D1E1F20 		.ascii	"\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?\000\001"
 1039      21222324 
 1039      25262728 
 1039      292A2B2C 
 1039      2D2E2F30 
 1040 0636 02030405 		.ascii	"\002\003\004\005\006\007\010\011\012\013\014\015\016"
 1040      06070809 
 1040      0A0B0C0D 
 1040      0E
 1041 0643 0F101112 		.ascii	"\017\020\021\022\023\024\025\026\027\030\031\032\033"
 1041      13141516 
 1041      1718191A 
 1041      1B
 1042 0650 1C1D1E1F 		.ascii	"\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?\000"
 1042      20212223 
 1042      24252627 
 1042      28292A2B 
 1042      2C2D2E2F 
 1043 0675 01020304 		.ascii	"\001\002\003\004\005\006\007\010\011\012\013\014\015"
 1043      05060708 
 1043      090A0B0C 
 1043      0D
 1044 0682 0E0F1011 		.ascii	"\016\017\020\021\022\023\024\025\026\027\030\031\032"
 1044      12131415 
 1044      16171819 
 1044      1A
 1045 068f 1B1C1D1E 		.ascii	"\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<="
 1045      1F202122 
 1045      23242526 
 1045      2728292A 
 1045      2B2C2D2E 
 1046 06b2 3E3F0001 		.ascii	">?\000\001\002\003\004\005\006\007\010\011\012\013\014"
 1046      02030405 
 1046      06070809 
 1046      0A0B0C
 1047 06c1 0D0E0F10 		.ascii	"\015\016\017\020\021\022\023\024\025\026\027\030\031"
 1047      11121314 
 1047      15161718 
 1047      19
 1048 06ce 1A1B1C1D 		.ascii	"\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789"
 1048      1E1F2021 
 1048      22232425 
 1048      26272829 
 1048      2A2B2C2D 
 1049 06ee 3A3B3C3D 		.ascii	":;<=>?\000\001\002\003\004\005\006\007\010\011\012\013"
 1049      3E3F0001 
 1049      02030405 
 1049      06070809 
 1049      0A0B
 1050 0700 0C0D0E0F 		.ascii	"\014\015\016\017\020\021\022\023\024\025\026\027\030"
 1050      10111213 
 1050      14151617 
 1050      18
 1051 070d 191A1B1C 		.ascii	"\031\032\033\034\035\036\037 !\"#$%&'()*+,-./012345"
 1051      1D1E1F20 
 1051      21222324 
 1051      25262728 
 1051      292A2B2C 
 1052 072a 36373839 		.ascii	"6789:;<=>?\000\001\002\003\004\005\006\007\010\011\012"
 1052      3A3B3C3D 
 1052      3E3F0001 
 1052      02030405 
 1052      06070809 
 1053 073f 0B0C0D0E 		.ascii	"\013\014\015\016\017\020\021\022\023\024\025\026\027"
 1053      0F101112 
 1053      13141516 
 1053      17
 1054 074c 18191A1B 		.ascii	"\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./01"
 1054      1C1D1E1F 
 1054      20212223 
 1054      24252627 
 1054      28292A2B 
 1055 0766 32333435 		.ascii	"23456789:;<=>?\000\001\002\003\004\005\006\007\010\011"
 1055      36373839 
 1055      3A3B3C3D 
 1055      3E3F0001 
 1055      02030405 
 1056 077e 0A0B0C0D 		.ascii	"\012\013\014\015\016\017\020\021\022\023\024\025\026"
 1056      0E0F1011 
 1056      12131415 
 1056      16
 1057 078b 1718191A 		.ascii	"\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-"
 1057      1B1C1D1E 
 1057      1F202122 
 1057      23242526 
 1057      2728292A 
 1058 07a2 2E2F3031 		.ascii	"./0123456789:;<=>?\000\001\002\003\004\005\006\007\010"
 1058      32333435 
 1058      36373839 
 1058      3A3B3C3D 
 1058      3E3F0001 
 1059 07bd 090A0B0C 		.ascii	"\011\012\013\014\015\016\017\020\021\022\023\024\025"
 1059      0D0E0F10 
 1059      11121314 
 1059      15
 1060 07ca 16171819 		.ascii	"\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()"
 1060      1A1B1C1D 
 1060      1E1F2021 
 1060      22232425 
 1060      26272829 
 1061 07de 2A2B2C2D 		.ascii	"*+,-./0123456789:;<=>?\000\001\002\003\004\005\006\007"
 1061      2E2F3031 
 1061      32333435 
 1061      36373839 
 1061      3A3B3C3D 
 1062 07fc 08090A0B 		.ascii	"\010\011\012\013\014\015\016\017"
 1062      0C0D0E0F 
 1063 0804 10111213 		.ascii	"\020\021\022\023\024\025\026\027\030\031\032\033\034"
 1063      14151617 
 1063      18191A1B 
 1063      1C
 1064 0811 1D1E1F20 		.ascii	"\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?"
 1064      21222324 
 1064      25262728 
 1064      292A2B2C 
 1064      2D2E2F30 
 1065 0834 27A7479B 		.ascii	"'\247G\233\357\241\324vH\2370\214\324\317\246\342\251"
 1065      EFA1D476 
 1065      489F308C 
 1065      D4CFA6E2 
 1065      A9
 1066 0845 6E4BBE32 		.ascii	"nK\2762\010\377%(}\323\201\226\026\350\234\307\214\367"
 1066      08FF2528 
 1066      7DD38196 
 1066      16E89CC7 
 1066      8CF7
 1067 0857 F5E54344 		.ascii	"\365\345CD_\2033\330\372\177V\000\000\005'\237\245\330"
 1067      5F8333D8 
 1067      FA7F5600 
 1067      0005279F 
 1067      A5D8
 1068 0869 B5E4AD40 		.ascii	"\265\344\255@\3476\335\264\323T\022\000"
 1068      E736DDB4 
 1068      D3541200 
 1069 0875 00000000 		.space	1983
 1069      00000000 
 1069      00000000 
 1069      00000000 
 1069      00000000 
 1070 1034 FFFFFFFF 		.ascii	"\377\377\377\377\377\377\377\377\377\377\377\377\377"
 1070      FFFFFFFF 
 1070      FFFFFFFF 
 1070      FF
 1071 1041 FFFFFF   		.ascii	"\377\377\377"
 1072 1044 00080000 		.word	2048
 1073              		.bss
 1074              		.align	2
 1075              		.set	.LANCHOR1,. + 0
 1078              	_ZStL8__ioinit:
 1079 0000 00       		.space	1
 1080 0001 000000   		.space	3
 1083              	xtsaes128:
 1084 0004 00000000 		.space	4
 1087              	buffer:
 1088 0008 00000000 		.space	2048
 1088      00000000 
 1088      00000000 
 1088      00000000 
 1088      00000000 
 1091              	testVector:
 1092 0808 00000000 		.space	4152
 1092      00000000 
 1092      00000000 
 1092      00000000 
 1092      00000000 
 1093              		.text
 1094              	.Letext0:
 1095              		.file 5 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 1096              		.file 6 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
 1097              		.file 7 "/usr/include/newlib/c++/10.3.1/cstdint"
 1098              		.file 8 "/usr/include/newlib/c++/10.3.1/cwchar"
 1099              		.file 9 "/usr/include/newlib/c++/10.3.1/bits/exception_ptr.h"
 1100              		.file 10 "/usr/include/newlib/c++/10.3.1/arm-none-eabi/thumb/v7e-m/nofp/bits/c++config.h"
 1101              		.file 11 "/usr/include/newlib/c++/10.3.1/type_traits"
 1102              		.file 12 "/usr/include/newlib/c++/10.3.1/bits/stl_pair.h"
 1103              		.file 13 "/usr/include/newlib/c++/10.3.1/debug/debug.h"
 1104              		.file 14 "/usr/include/newlib/c++/10.3.1/clocale"
 1105              		.file 15 "/usr/include/newlib/c++/10.3.1/cstdlib"
 1106              		.file 16 "/usr/include/newlib/c++/10.3.1/cstdio"
 1107              		.file 17 "/usr/include/newlib/c++/10.3.1/bits/basic_string.h"
 1108              		.file 18 "/usr/include/newlib/c++/10.3.1/system_error"
 1109              		.file 19 "/usr/include/newlib/c++/10.3.1/bits/ios_base.h"
 1110              		.file 20 "/usr/include/newlib/c++/10.3.1/cwctype"
 1111              		.file 21 "/usr/include/newlib/c++/10.3.1/cstring"
 1112              		.file 22 "/usr/include/newlib/c++/10.3.1/bits/predefined_ops.h"
 1113              		.file 23 "/usr/include/newlib/sys/_types.h"
 1114              		.file 24 "/usr/include/newlib/sys/reent.h"
 1115              		.file 25 "/usr/include/newlib/sys/lock.h"
 1116              		.file 26 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdarg.h"
 1117              		.file 27 "/usr/include/newlib/wchar.h"
 1118              		.file 28 "/usr/include/newlib/locale.h"
 1119              		.file 29 "/usr/include/newlib/c++/10.3.1/arm-none-eabi/thumb/v7e-m/nofp/bits/atomic_word.h"
 1120              		.file 30 "/usr/include/newlib/stdlib.h"
 1121              		.file 31 "/usr/include/newlib/stdio.h"
 1122              		.file 32 "/usr/include/newlib/wctype.h"
 1123              		.file 33 "/usr/include/newlib/string.h"
 1124              		.file 34 "/usr/include/newlib/c++/10.3.1/new"
 1125              		.file 35 ".././hal/stm32f4/stm32f4_hal.h"
 1126              		.file 36 ".././simpleserial/simpleserial.h"
 1127              		.file 37 "<built-in>"
 1128              		.file 38 "/usr/include/newlib/c++/10.3.1/bits/stl_iterator_base_types.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 main.cpp
     /tmp/ccj3I9mN.s:16     .text.led_ok:0000000000000000 $t
     /tmp/ccj3I9mN.s:24     .text.led_ok:0000000000000000 led_ok
           .ARM.exidx.text.led_ok:0000000000000000 $d
     /tmp/ccj3I9mN.s:42     .text.led_error:0000000000000000 $t
     /tmp/ccj3I9mN.s:49     .text.led_error:0000000000000000 led_error
        .ARM.exidx.text.led_error:0000000000000000 $d
     /tmp/ccj3I9mN.s:63     .text._Z11updateTweakPm:0000000000000000 $t
     /tmp/ccj3I9mN.s:70     .text._Z11updateTweakPm:0000000000000000 _Z11updateTweakPm
.ARM.exidx.text._Z11updateTweakPm:0000000000000000 $d
     /tmp/ccj3I9mN.s:235    .text._Z15setAndTestTweakv:0000000000000000 $t
     /tmp/ccj3I9mN.s:242    .text._Z15setAndTestTweakv:0000000000000000 _Z15setAndTestTweakv
     /tmp/ccj3I9mN.s:345    .text._Z15setAndTestTweakv:0000000000000060 $d
.ARM.exidx.text._Z15setAndTestTweakv:0000000000000000 $d
     /tmp/ccj3I9mN.s:352    .text._Z8tenTweakhhhPh:0000000000000000 $t
     /tmp/ccj3I9mN.s:359    .text._Z8tenTweakhhhPh:0000000000000000 _Z8tenTweakhhhPh
 .ARM.extab.text._Z8tenTweakhhhPh:0000000000000000 $d
 .ARM.exidx.text._Z8tenTweakhhhPh:0000000000000000 $d
     /tmp/ccj3I9mN.s:387    .text.startup._GLOBAL__sub_I_xtsaes128:0000000000000000 $t
     /tmp/ccj3I9mN.s:393    .text.startup._GLOBAL__sub_I_xtsaes128:0000000000000000 _GLOBAL__sub_I_xtsaes128
     /tmp/ccj3I9mN.s:438    .text.startup._GLOBAL__sub_I_xtsaes128:0000000000000018 $d
.ARM.exidx.text.startup._GLOBAL__sub_I_xtsaes128:0000000000000000 $d
     /tmp/ccj3I9mN.s:449    .init_array:0000000000000000 $d
     /tmp/ccj3I9mN.s:452    .text._ZN3XTSI6AES128S0_EC2Ev:0000000000000000 $t
     /tmp/ccj3I9mN.s:459    .text._ZN3XTSI6AES128S0_EC2Ev:0000000000000000 _ZN3XTSI6AES128S0_EC2Ev
     /tmp/ccj3I9mN.s:541    .text._ZN3XTSI6AES128S0_EC2Ev:000000000000003c $d
     /tmp/ccj3I9mN.s:941    .rodata._ZTV3XTSI6AES128S0_E:0000000000000000 _ZTV3XTSI6AES128S0_E
.ARM.extab.text._ZN3XTSI6AES128S0_EC2Ev:0000000000000000 $d
.ARM.exidx.text._ZN3XTSI6AES128S0_EC2Ev:0000000000000000 $d
     /tmp/ccj3I9mN.s:459    .text._ZN3XTSI6AES128S0_EC2Ev:0000000000000000 _ZN3XTSI6AES128S0_EC1Ev
     /tmp/ccj3I9mN.s:576    .text.startup.main:0000000000000000 $t
     /tmp/ccj3I9mN.s:583    .text.startup.main:0000000000000000 main
     /tmp/ccj3I9mN.s:663    .text.startup.main:000000000000004c $d
     /tmp/ccj3I9mN.s:757    .text._Z14attack_examplehhhPh:0000000000000000 _Z14attack_examplehhhPh
     .ARM.extab.text.startup.main:0000000000000000 $d
     .ARM.exidx.text.startup.main:0000000000000000 $d
     /tmp/ccj3I9mN.s:693    .text._ZN3XTSI6AES128S0_ED2Ev:0000000000000000 $t
     /tmp/ccj3I9mN.s:700    .text._ZN3XTSI6AES128S0_ED2Ev:0000000000000000 _ZN3XTSI6AES128S0_ED2Ev
     /tmp/ccj3I9mN.s:741    .text._ZN3XTSI6AES128S0_ED2Ev:0000000000000020 $d
.ARM.exidx.text._ZN3XTSI6AES128S0_ED2Ev:0000000000000000 $d
     /tmp/ccj3I9mN.s:700    .text._ZN3XTSI6AES128S0_ED2Ev:0000000000000000 _ZN3XTSI6AES128S0_ED1Ev
     /tmp/ccj3I9mN.s:750    .text._Z14attack_examplehhhPh:0000000000000000 $t
     /tmp/ccj3I9mN.s:852    .text._Z14attack_examplehhhPh:0000000000000054 $d
     /tmp/ccj3I9mN.s:962    .rodata:0000000000000010 _ZL12attackVector
.ARM.extab.text._Z14attack_examplehhhPh:0000000000000000 $d
.ARM.exidx.text._Z14attack_examplehhhPh:0000000000000000 $d
     /tmp/ccj3I9mN.s:882    .text._ZN3XTSI6AES128S0_ED0Ev:0000000000000000 $t
     /tmp/ccj3I9mN.s:889    .text._ZN3XTSI6AES128S0_ED0Ev:0000000000000000 _ZN3XTSI6AES128S0_ED0Ev
.ARM.exidx.text._ZN3XTSI6AES128S0_ED0Ev:0000000000000000 $d
     /tmp/ccj3I9mN.s:925    .rodata._ZTS3XTSI6AES128S0_E:0000000000000000 _ZTS3XTSI6AES128S0_E
     /tmp/ccj3I9mN.s:932    .rodata._ZTI3XTSI6AES128S0_E:0000000000000000 _ZTI3XTSI6AES128S0_E
     /tmp/ccj3I9mN.s:929    .rodata._ZTI3XTSI6AES128S0_E:0000000000000000 $d
     /tmp/ccj3I9mN.s:938    .rodata._ZTV3XTSI6AES128S0_E:0000000000000000 $d
     /tmp/ccj3I9mN.s:1087   .bss:0000000000000008 buffer
     /tmp/ccj3I9mN.s:1091   .bss:0000000000000808 testVector
     /tmp/ccj3I9mN.s:1083   .bss:0000000000000004 xtsaes128
     /tmp/ccj3I9mN.s:955    .rodata:0000000000000000 $d
     /tmp/ccj3I9mN.s:1074   .bss:0000000000000000 $d
     /tmp/ccj3I9mN.s:1078   .bss:0000000000000000 _ZStL8__ioinit
                           .group:0000000000000000 _ZN3XTSI6AES128S0_EC5Ev
                           .group:0000000000000000 _ZN3XTSI6AES128S0_ED5Ev

UNDEFINED SYMBOLS
trigger_high
trigger_low
__aeabi_unwind_cpp_pr0
__aeabi_unwind_cpp_pr1
_ZNSt8ios_base4InitC1Ev
__aeabi_atexit
__dso_handle
_ZNSt8ios_base4InitD1Ev
_ZN9XTSCommonC2Ev
_ZN6AES128C1Ev
_ZN6AES128D1Ev
_ZN9XTSCommonD2Ev
__cxa_end_cleanup
__gxx_personality_v0
_Znwj
platform_init
init_uart
trigger_setup
simpleserial_init
simpleserial_addcmd
simpleserial_get
_ZdlPvj
_ZN9XTSCommon13setSectorSizeEj
_ZN9XTSCommon6setKeyEPKhj
_ZN9XTSCommon8setTweakEPKhj
_ZN9XTSCommon13encryptSectorEPhPKhh
_ZTVN10__cxxabiv120__si_class_type_infoE
_ZTI9XTSCommon
_ZNK9XTSCommon7keySizeEv
