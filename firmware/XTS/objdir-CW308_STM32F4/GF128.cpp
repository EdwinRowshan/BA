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
  11              		.file	"GF128.cpp"
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
  27              	.LFB11:
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
  37              	.LFE11:
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
  51              	.LFB19:
  52              		.cfi_startproc
  53              		@ args = 0, pretend = 0, frame = 0
  54              		@ frame_needed = 0, uses_anonymous_args = 0
  55              		@ link register save eliminated.
  56 0000 7047     		bx	lr
  57              		.cfi_endproc
  58              	.LFE19:
  59              		.cantunwind
  60              		.fnend
  62              		.section	.text._ZN5GF1287mulInitEPmPKv,"ax",%progbits
  63              		.align	1
  64              		.global	_ZN5GF1287mulInitEPmPKv
  65              		.syntax unified
  66              		.thumb
  67              		.thumb_func
  68              		.fpu softvfp
  70              	_ZN5GF1287mulInitEPmPKv:
  71              		.fnstart
  72              	.LVL1:
  73              	.LFB13:
  74              		.file 2 "GF128.cpp"
   1:GF128.cpp     **** /*
   2:GF128.cpp     ****  * Copyright (C) 2016 Southern Storm Software, Pty Ltd.
   3:GF128.cpp     ****  *
   4:GF128.cpp     ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:GF128.cpp     ****  * copy of this software and associated documentation files (the "Software"),
   6:GF128.cpp     ****  * to deal in the Software without restriction, including without limitation
   7:GF128.cpp     ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:GF128.cpp     ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:GF128.cpp     ****  * Software is furnished to do so, subject to the following conditions:
  10:GF128.cpp     ****  *
  11:GF128.cpp     ****  * The above copyright notice and this permission notice shall be included
  12:GF128.cpp     ****  * in all copies or substantial portions of the Software.
  13:GF128.cpp     ****  *
  14:GF128.cpp     ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:GF128.cpp     ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:GF128.cpp     ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:GF128.cpp     ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:GF128.cpp     ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:GF128.cpp     ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:GF128.cpp     ****  * DEALINGS IN THE SOFTWARE.
  21:GF128.cpp     ****  */
  22:GF128.cpp     **** 
  23:GF128.cpp     **** #include "GF128.h"
  24:GF128.cpp     **** #include "EndianUtil.h"
  25:GF128.cpp     **** #include <string.h>
  26:GF128.cpp     **** #include <cstdint>
  27:GF128.cpp     **** #include <cstring>
  28:GF128.cpp     **** 
  29:GF128.cpp     **** extern "C" {
  30:GF128.cpp     ****     #include "hal.h"
  31:GF128.cpp     **** }
  32:GF128.cpp     **** 
  33:GF128.cpp     **** /**
  34:GF128.cpp     ****  * \class GF128 GF128.h <GF128.h>
  35:GF128.cpp     ****  * \brief Operations in the Galois field GF(2^128).
  36:GF128.cpp     ****  *
  37:GF128.cpp     ****  * This class contains helper functions for performing operations in
  38:GF128.cpp     ****  * the Galois field GF(2^128) which is used as the basis of GCM and GHASH.
  39:GF128.cpp     ****  * These functions are provided for use by other cryptographic protocols
  40:GF128.cpp     ****  * that make use of GF(2^128).
  41:GF128.cpp     ****  *
  42:GF128.cpp     ****  * Most of the functions in this class use the field, polynomial, and
  43:GF128.cpp     ****  * byte ordering conventions described in NIST SP 800-38D (GCM).  The one
  44:GF128.cpp     ****  * exception is dblEAX() which uses the conventions of EAX mode instead.
  45:GF128.cpp     ****  *
  46:GF128.cpp     ****  * References: <a href="http://csrc.nist.gov/publications/nistpubs/800-38D/SP-800-38D.pdf">NIST SP 
  47:GF128.cpp     ****  *
  48:GF128.cpp     ****  * \sa GCM, GHASH
  49:GF128.cpp     ****  */
  50:GF128.cpp     **** 
  51:GF128.cpp     **** /**
  52:GF128.cpp     ****  * \brief Initialize multiplication in the GF(2^128) field.
  53:GF128.cpp     ****  *
  54:GF128.cpp     ****  * \param H The hash state to be initialized.
  55:GF128.cpp     ****  * \param key Points to the 16 byte authentication key which is assumed
  56:GF128.cpp     ****  * to be in big-endian byte order.
  57:GF128.cpp     ****  *
  58:GF128.cpp     ****  * This function and the companion mul() are intended for use by other
  59:GF128.cpp     ****  * classes that need access to the raw GF(2^128) field multiplication of
  60:GF128.cpp     ****  * GHASH without the overhead of GHASH itself.
  61:GF128.cpp     ****  *
  62:GF128.cpp     ****  * \sa mul(), dbl()
  63:GF128.cpp     ****  */
  64:GF128.cpp     **** void GF128::mulInit(uint32_t H[4], const void *key)
  65:GF128.cpp     **** {
  75              		.loc 2 65 1 is_stmt 1 view -0
  76              		.cfi_startproc
  77              		@ args = 0, pretend = 0, frame = 0
  78              		@ frame_needed = 0, uses_anonymous_args = 0
  66:GF128.cpp     **** #if defined(__AVR__)
  67:GF128.cpp     ****     // Copy the key into H but leave it in big endian order because
  68:GF128.cpp     ****     // we can correct for the byte order in mul() below.
  69:GF128.cpp     ****     memcpy(H, key, 16);
  70:GF128.cpp     **** #else
  71:GF128.cpp     ****     // Copy the key into H and convert from big endian to host order.
  72:GF128.cpp     ****     memcpy(H, key, 16);
  79              		.loc 2 72 5 view .LVU3
  65:GF128.cpp     **** #if defined(__AVR__)
  80              		.loc 2 65 1 is_stmt 0 view .LVU4
  81 0000 10B5     		push	{r4, lr}
  82              	.LCFI0:
  83              		.cfi_def_cfa_offset 8
  84              		.cfi_offset 4, -8
  85              		.cfi_offset 14, -4
  86              		.loc 2 72 11 view .LVU5
  87 0002 0346     		mov	r3, r0
  88 0004 01F11002 		add	r2, r1, #16
  89              	.LVL2:
  90              	.L4:
  91              		.loc 2 72 11 view .LVU6
  92 0008 51F8044B 		ldr	r4, [r1], #4	@ unaligned
  93 000c 43F8044B 		str	r4, [r3], #4	@ unaligned
  94 0010 9142     		cmp	r1, r2
  95 0012 F9D1     		bne	.L4
  73:GF128.cpp     **** #if defined(CRYPTO_LITTLE_ENDIAN)
  74:GF128.cpp     ****     H[0] = be32toh(H[0]);
  96              		.loc 2 74 5 is_stmt 1 view .LVU7
  97              	.LBB2:
  98              		.loc 2 74 12 view .LVU8
  99 0014 0368     		ldr	r3, [r0]
 100 0016 1BBA     		rev	r3, r3
 101              	.LVL3:
 102              		.loc 2 74 12 view .LVU9
 103              		.loc 2 74 10 is_stmt 0 view .LVU10
 104 0018 0360     		str	r3, [r0]
 105              	.LVL4:
 106              		.loc 2 74 10 view .LVU11
 107              	.LBE2:
  75:GF128.cpp     ****     H[1] = be32toh(H[1]);
 108              		.loc 2 75 5 is_stmt 1 view .LVU12
 109              	.LBB3:
 110              		.loc 2 75 12 view .LVU13
 111 001a 4368     		ldr	r3, [r0, #4]
 112 001c 1BBA     		rev	r3, r3
 113              	.LVL5:
 114              		.loc 2 75 12 view .LVU14
 115              		.loc 2 75 10 is_stmt 0 view .LVU15
 116 001e 4360     		str	r3, [r0, #4]
 117              	.LVL6:
 118              		.loc 2 75 10 view .LVU16
 119              	.LBE3:
  76:GF128.cpp     ****     H[2] = be32toh(H[2]);
 120              		.loc 2 76 5 is_stmt 1 view .LVU17
 121              	.LBB4:
 122              		.loc 2 76 12 view .LVU18
 123 0020 8368     		ldr	r3, [r0, #8]
 124 0022 1BBA     		rev	r3, r3
 125              	.LVL7:
 126              		.loc 2 76 12 view .LVU19
 127              		.loc 2 76 10 is_stmt 0 view .LVU20
 128 0024 8360     		str	r3, [r0, #8]
 129              	.LVL8:
 130              		.loc 2 76 10 view .LVU21
 131              	.LBE4:
  77:GF128.cpp     ****     H[3] = be32toh(H[3]);
 132              		.loc 2 77 5 is_stmt 1 view .LVU22
 133              	.LBB5:
 134              		.loc 2 77 12 view .LVU23
 135 0026 C368     		ldr	r3, [r0, #12]
 136 0028 1BBA     		rev	r3, r3
 137              	.LVL9:
 138              		.loc 2 77 12 view .LVU24
 139              		.loc 2 77 10 is_stmt 0 view .LVU25
 140 002a C360     		str	r3, [r0, #12]
 141              	.LVL10:
 142              		.loc 2 77 10 view .LVU26
 143              	.LBE5:
  78:GF128.cpp     **** #endif
  79:GF128.cpp     **** #endif
  80:GF128.cpp     **** }
 144              		.loc 2 80 1 view .LVU27
 145 002c 10BD     		pop	{r4, pc}
 146              		.cfi_endproc
 147              	.LFE13:
 148              		.cantunwind
 149              		.fnend
 151              		.section	.text._ZN5GF1283mulEPmPKm,"ax",%progbits
 152              		.align	1
 153              		.global	_ZN5GF1283mulEPmPKm
 154              		.syntax unified
 155              		.thumb
 156              		.thumb_func
 157              		.fpu softvfp
 159              	_ZN5GF1283mulEPmPKm:
 160              		.fnstart
 161              	.LVL11:
 162              	.LFB14:
  81:GF128.cpp     **** 
  82:GF128.cpp     **** /**
  83:GF128.cpp     ****  * \brief Perform a multiplication in the GF(2^128) field.
  84:GF128.cpp     ****  *
  85:GF128.cpp     ****  * \param Y The first value to multiply, and the result.  This array is
  86:GF128.cpp     ****  * assumed to be in big-endian order on entry and exit.
  87:GF128.cpp     ****  * \param H The second value to multiply, which must have been initialized
  88:GF128.cpp     ****  * by the mulInit() function.
  89:GF128.cpp     ****  *
  90:GF128.cpp     ****  * This function and the companion mulInit() are intended for use by other
  91:GF128.cpp     ****  * classes that need access to the raw GF(2^128) field multiplication of
  92:GF128.cpp     ****  * GHASH without the overhead of GHASH itself.
  93:GF128.cpp     ****  *
  94:GF128.cpp     ****  * \sa mulInit(), dbl()
  95:GF128.cpp     ****  */
  96:GF128.cpp     **** void GF128::mul(uint32_t Y[4], const uint32_t H[4])
  97:GF128.cpp     **** {
 163              		.loc 2 97 1 is_stmt 1 view -0
 164              		.cfi_startproc
 165              		@ args = 0, pretend = 0, frame = 8
 166              		@ frame_needed = 0, uses_anonymous_args = 0
  98:GF128.cpp     **** #if defined(__AVR__)
  99:GF128.cpp     ****     uint32_t Z[4] = {0, 0, 0, 0};   // Z = 0
 100:GF128.cpp     ****     uint32_t V0 = H[0];             // V = H
 101:GF128.cpp     ****     uint32_t V1 = H[1];
 102:GF128.cpp     ****     uint32_t V2 = H[2];
 103:GF128.cpp     ****     uint32_t V3 = H[3];
 104:GF128.cpp     **** 
 105:GF128.cpp     ****     // Multiply Z by V for the set bits in Y, starting at the top.
 106:GF128.cpp     ****     // This is a very simple bit by bit version that may not be very
 107:GF128.cpp     ****     // fast but it should be resistant to cache timing attacks.
 108:GF128.cpp     ****     for (uint8_t posn = 0; posn < 16; ++posn) {
 109:GF128.cpp     ****         uint8_t value = ((const uint8_t *)Y)[posn];
 110:GF128.cpp     ****         for (uint8_t bit = 0; bit < 8; ++bit) {
 111:GF128.cpp     ****             __asm__ __volatile__ (
 112:GF128.cpp     ****                 // Extract the high bit of "value" and turn it into a mask.
 113:GF128.cpp     ****                 "ldd r24,%8\n"
 114:GF128.cpp     ****                 "lsl r24\n"
 115:GF128.cpp     ****                 "std %8,r24\n"
 116:GF128.cpp     ****                 "mov __tmp_reg__,__zero_reg__\n"
 117:GF128.cpp     ****                 "sbc __tmp_reg__,__zero_reg__\n"
 118:GF128.cpp     **** 
 119:GF128.cpp     ****                 // XOR V with Z if the bit is 1.
 120:GF128.cpp     ****                 "mov r24,%D0\n"         // Z0 ^= (V0 & mask)
 121:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 122:GF128.cpp     ****                 "ldd r25,%D4\n"
 123:GF128.cpp     ****                 "eor r25,r24\n"
 124:GF128.cpp     ****                 "std %D4,r25\n"
 125:GF128.cpp     ****                 "mov r24,%C0\n"
 126:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 127:GF128.cpp     ****                 "ldd r25,%C4\n"
 128:GF128.cpp     ****                 "eor r25,r24\n"
 129:GF128.cpp     ****                 "std %C4,r25\n"
 130:GF128.cpp     ****                 "mov r24,%B0\n"
 131:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 132:GF128.cpp     ****                 "ldd r25,%B4\n"
 133:GF128.cpp     ****                 "eor r25,r24\n"
 134:GF128.cpp     ****                 "std %B4,r25\n"
 135:GF128.cpp     ****                 "mov r24,%A0\n"
 136:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 137:GF128.cpp     ****                 "ldd r25,%A4\n"
 138:GF128.cpp     ****                 "eor r25,r24\n"
 139:GF128.cpp     ****                 "std %A4,r25\n"
 140:GF128.cpp     ****                 "mov r24,%D1\n"         // Z1 ^= (V1 & mask)
 141:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 142:GF128.cpp     ****                 "ldd r25,%D5\n"
 143:GF128.cpp     ****                 "eor r25,r24\n"
 144:GF128.cpp     ****                 "std %D5,r25\n"
 145:GF128.cpp     ****                 "mov r24,%C1\n"
 146:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 147:GF128.cpp     ****                 "ldd r25,%C5\n"
 148:GF128.cpp     ****                 "eor r25,r24\n"
 149:GF128.cpp     ****                 "std %C5,r25\n"
 150:GF128.cpp     ****                 "mov r24,%B1\n"
 151:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 152:GF128.cpp     ****                 "ldd r25,%B5\n"
 153:GF128.cpp     ****                 "eor r25,r24\n"
 154:GF128.cpp     ****                 "std %B5,r25\n"
 155:GF128.cpp     ****                 "mov r24,%A1\n"
 156:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 157:GF128.cpp     ****                 "ldd r25,%A5\n"
 158:GF128.cpp     ****                 "eor r25,r24\n"
 159:GF128.cpp     ****                 "std %A5,r25\n"
 160:GF128.cpp     ****                 "mov r24,%D2\n"         // Z2 ^= (V2 & mask)
 161:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 162:GF128.cpp     ****                 "ldd r25,%D6\n"
 163:GF128.cpp     ****                 "eor r25,r24\n"
 164:GF128.cpp     ****                 "std %D6,r25\n"
 165:GF128.cpp     ****                 "mov r24,%C2\n"
 166:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 167:GF128.cpp     ****                 "ldd r25,%C6\n"
 168:GF128.cpp     ****                 "eor r25,r24\n"
 169:GF128.cpp     ****                 "std %C6,r25\n"
 170:GF128.cpp     ****                 "mov r24,%B2\n"
 171:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 172:GF128.cpp     ****                 "ldd r25,%B6\n"
 173:GF128.cpp     ****                 "eor r25,r24\n"
 174:GF128.cpp     ****                 "std %B6,r25\n"
 175:GF128.cpp     ****                 "mov r24,%A2\n"
 176:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 177:GF128.cpp     ****                 "ldd r25,%A6\n"
 178:GF128.cpp     ****                 "eor r25,r24\n"
 179:GF128.cpp     ****                 "std %A6,r25\n"
 180:GF128.cpp     ****                 "mov r24,%D3\n"         // Z3 ^= (V3 & mask)
 181:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 182:GF128.cpp     ****                 "ldd r25,%D7\n"
 183:GF128.cpp     ****                 "eor r25,r24\n"
 184:GF128.cpp     ****                 "std %D7,r25\n"
 185:GF128.cpp     ****                 "mov r24,%C3\n"
 186:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 187:GF128.cpp     ****                 "ldd r25,%C7\n"
 188:GF128.cpp     ****                 "eor r25,r24\n"
 189:GF128.cpp     ****                 "std %C7,r25\n"
 190:GF128.cpp     ****                 "mov r24,%B3\n"
 191:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 192:GF128.cpp     ****                 "ldd r25,%B7\n"
 193:GF128.cpp     ****                 "eor r25,r24\n"
 194:GF128.cpp     ****                 "std %B7,r25\n"
 195:GF128.cpp     ****                 "mov r24,%A3\n"
 196:GF128.cpp     ****                 "and r24,__tmp_reg__\n"
 197:GF128.cpp     ****                 "ldd r25,%A7\n"
 198:GF128.cpp     ****                 "eor r25,r24\n"
 199:GF128.cpp     ****                 "std %A7,r25\n"
 200:GF128.cpp     **** 
 201:GF128.cpp     ****                 // Rotate V right by 1 bit.
 202:GF128.cpp     ****                 "lsr %A0\n"
 203:GF128.cpp     ****                 "ror %B0\n"
 204:GF128.cpp     ****                 "ror %C0\n"
 205:GF128.cpp     ****                 "ror %D0\n"
 206:GF128.cpp     ****                 "ror %A1\n"
 207:GF128.cpp     ****                 "ror %B1\n"
 208:GF128.cpp     ****                 "ror %C1\n"
 209:GF128.cpp     ****                 "ror %D1\n"
 210:GF128.cpp     ****                 "ror %A2\n"
 211:GF128.cpp     ****                 "ror %B2\n"
 212:GF128.cpp     ****                 "ror %C2\n"
 213:GF128.cpp     ****                 "ror %D2\n"
 214:GF128.cpp     ****                 "ror %A3\n"
 215:GF128.cpp     ****                 "ror %B3\n"
 216:GF128.cpp     ****                 "ror %C3\n"
 217:GF128.cpp     ****                 "ror %D3\n"
 218:GF128.cpp     ****                 "mov r24,__zero_reg__\n"
 219:GF128.cpp     ****                 "sbc r24,__zero_reg__\n"
 220:GF128.cpp     ****                 "andi r24,0xE1\n"
 221:GF128.cpp     ****                 "eor %A0,r24\n"
 222:GF128.cpp     ****                 : "+r"(V0), "+r"(V1), "+r"(V2), "+r"(V3)
 223:GF128.cpp     ****                 : "Q"(Z[0]), "Q"(Z[1]), "Q"(Z[2]), "Q"(Z[3]), "Q"(value)
 224:GF128.cpp     ****                 : "r24", "r25"
 225:GF128.cpp     ****             );
 226:GF128.cpp     ****         }
 227:GF128.cpp     ****     }
 228:GF128.cpp     **** 
 229:GF128.cpp     ****     // We have finished the block so copy Z into Y and byte-swap.
 230:GF128.cpp     ****     __asm__ __volatile__ (
 231:GF128.cpp     ****         "ldd __tmp_reg__,%A0\n"
 232:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 233:GF128.cpp     ****         "ldd __tmp_reg__,%B0\n"
 234:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 235:GF128.cpp     ****         "ldd __tmp_reg__,%C0\n"
 236:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 237:GF128.cpp     ****         "ldd __tmp_reg__,%D0\n"
 238:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 239:GF128.cpp     ****         "ldd __tmp_reg__,%A1\n"
 240:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 241:GF128.cpp     ****         "ldd __tmp_reg__,%B1\n"
 242:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 243:GF128.cpp     ****         "ldd __tmp_reg__,%C1\n"
 244:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 245:GF128.cpp     ****         "ldd __tmp_reg__,%D1\n"
 246:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 247:GF128.cpp     ****         "ldd __tmp_reg__,%A2\n"
 248:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 249:GF128.cpp     ****         "ldd __tmp_reg__,%B2\n"
 250:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 251:GF128.cpp     ****         "ldd __tmp_reg__,%C2\n"
 252:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 253:GF128.cpp     ****         "ldd __tmp_reg__,%D2\n"
 254:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 255:GF128.cpp     ****         "ldd __tmp_reg__,%A3\n"
 256:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 257:GF128.cpp     ****         "ldd __tmp_reg__,%B3\n"
 258:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 259:GF128.cpp     ****         "ldd __tmp_reg__,%C3\n"
 260:GF128.cpp     ****         "st X+,__tmp_reg__\n"
 261:GF128.cpp     ****         "ldd __tmp_reg__,%D3\n"
 262:GF128.cpp     ****         "st X,__tmp_reg__\n"
 263:GF128.cpp     ****         : : "Q"(Z[0]), "Q"(Z[1]), "Q"(Z[2]), "Q"(Z[3]), "x"(Y)
 264:GF128.cpp     ****     );
 265:GF128.cpp     **** #else // !__AVR__
 266:GF128.cpp     ****     uint32_t Z0 = 0;        // Z = 0
 167              		.loc 2 266 5 view .LVU29
 267:GF128.cpp     ****     uint32_t Z1 = 0;
 168              		.loc 2 267 5 view .LVU30
 268:GF128.cpp     ****     uint32_t Z2 = 0;
 169              		.loc 2 268 5 view .LVU31
 269:GF128.cpp     ****     uint32_t Z3 = 0;
 170              		.loc 2 269 5 view .LVU32
 270:GF128.cpp     ****     uint32_t V0 = H[0];     // V = H
 171              		.loc 2 270 5 view .LVU33
  97:GF128.cpp     **** #if defined(__AVR__)
 172              		.loc 2 97 1 is_stmt 0 view .LVU34
 173 0000 2DE9F74F 		push	{r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, fp, lr}
 174              	.LCFI1:
 175              		.cfi_def_cfa_offset 48
 176              		.cfi_offset 4, -36
 177              		.cfi_offset 5, -32
 178              		.cfi_offset 6, -28
 179              		.cfi_offset 7, -24
 180              		.cfi_offset 8, -20
 181              		.cfi_offset 9, -16
 182              		.cfi_offset 10, -12
 183              		.cfi_offset 11, -8
 184              		.cfi_offset 14, -4
 185 0004 00F10F03 		add	r3, r0, #15
 186 0008 0193     		str	r3, [sp, #4]
 269:GF128.cpp     ****     uint32_t Z3 = 0;
 187              		.loc 2 269 14 view .LVU35
 188 000a 0023     		movs	r3, #0
 271:GF128.cpp     ****     uint32_t V1 = H[1];
 189              		.loc 2 271 14 view .LVU36
 190 000c D1E90098 		ldrd	r9, r8, [r1]
 191              	.LVL12:
 272:GF128.cpp     ****     uint32_t V2 = H[2];
 192              		.loc 2 272 5 is_stmt 1 view .LVU37
 273:GF128.cpp     ****     uint32_t V3 = H[3];
 193              		.loc 2 273 14 is_stmt 0 view .LVU38
 194 0010 D1E902EC 		ldrd	lr, ip, [r1, #8]
 195              	.LVL13:
 274:GF128.cpp     **** 
 275:GF128.cpp     ****     // Multiply Z by V for the set bits in Y, starting at the top.
 276:GF128.cpp     ****     // This is a very simple bit by bit version that may not be very
 277:GF128.cpp     ****     // fast but it should be resistant to cache timing attacks.
 278:GF128.cpp     ****     for (uint8_t posn = 0; posn < 16; ++posn) {
 196              		.loc 2 278 5 is_stmt 1 view .LVU39
 197              	.LBB6:
 198              		.loc 2 278 33 view .LVU40
 199 0014 00F1FF3A 		add	r10, r0, #-1
 200              	.LBE6:
 268:GF128.cpp     ****     uint32_t Z3 = 0;
 201              		.loc 2 268 14 is_stmt 0 view .LVU41
 202 0018 1946     		mov	r1, r3
 203              	.LVL14:
 267:GF128.cpp     ****     uint32_t Z2 = 0;
 204              		.loc 2 267 14 view .LVU42
 205 001a 1C46     		mov	r4, r3
 266:GF128.cpp     ****     uint32_t Z1 = 0;
 206              		.loc 2 266 14 view .LVU43
 207 001c 1D46     		mov	r5, r3
 208              	.LVL15:
 209              	.L8:
 210              	.LBB14:
 211              	.LBB7:
 279:GF128.cpp     ****         uint8_t value = ((const uint8_t *)Y)[posn];
 212              		.loc 2 279 9 is_stmt 1 view .LVU44
 213              		.loc 2 279 17 is_stmt 0 view .LVU45
 214 001e 1AF8017F 		ldrb	r7, [r10, #1]!	@ zero_extendqisi2
 215              	.LVL16:
 280:GF128.cpp     ****         for (uint8_t bit = 0; bit < 8; ++bit, value <<= 1) {
 216              		.loc 2 280 9 is_stmt 1 view .LVU46
 217              	.LBB8:
 218              		.loc 2 280 35 view .LVU47
 219              	.LBE8:
 279:GF128.cpp     ****         uint8_t value = ((const uint8_t *)Y)[posn];
 220              		.loc 2 279 17 is_stmt 0 view .LVU48
 221 0022 0826     		movs	r6, #8
 222              	.LVL17:
 223              	.L7:
 224              	.LBB13:
 225              	.LBB9:
 281:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 282:GF128.cpp     ****             uint32_t mask = (~((uint32_t)(value >> 7))) + 1;
 226              		.loc 2 282 13 is_stmt 1 discriminator 2 view .LVU49
 227              		.loc 2 282 22 is_stmt 0 discriminator 2 view .LVU50
 228 0024 47F3C012 		sbfx	r2, r7, #7, #1
 229              	.LVL18:
 283:GF128.cpp     **** 
 284:GF128.cpp     ****             // XOR V with Z if the bit is 1.
 285:GF128.cpp     ****             Z0 ^= (V0 & mask);
 230              		.loc 2 285 13 is_stmt 1 discriminator 2 view .LVU51
 231              		.loc 2 285 23 is_stmt 0 discriminator 2 view .LVU52
 232 0028 02EA090B 		and	fp, r2, r9
 233              		.loc 2 285 16 discriminator 2 view .LVU53
 234 002c 85EA0B05 		eor	r5, r5, fp
 235              	.LVL19:
 286:GF128.cpp     ****             Z1 ^= (V1 & mask);
 236              		.loc 2 286 13 is_stmt 1 discriminator 2 view .LVU54
 237              		.loc 2 286 23 is_stmt 0 discriminator 2 view .LVU55
 238 0030 02EA080B 		and	fp, r2, r8
 239              		.loc 2 286 16 discriminator 2 view .LVU56
 240 0034 84EA0B04 		eor	r4, r4, fp
 241              	.LVL20:
 287:GF128.cpp     ****             Z2 ^= (V2 & mask);
 242              		.loc 2 287 13 is_stmt 1 discriminator 2 view .LVU57
 243              		.loc 2 287 23 is_stmt 0 discriminator 2 view .LVU58
 244 0038 02EA0E0B 		and	fp, r2, lr
 245              		.loc 2 287 16 discriminator 2 view .LVU59
 246 003c 81EA0B01 		eor	r1, r1, fp
 247              	.LVL21:
 288:GF128.cpp     ****             Z3 ^= (V3 & mask);
 248              		.loc 2 288 13 is_stmt 1 discriminator 2 view .LVU60
 249              		.loc 2 288 23 is_stmt 0 discriminator 2 view .LVU61
 250 0040 02EA0C02 		and	r2, r2, ip
 251              	.LVL22:
 289:GF128.cpp     **** 
 290:GF128.cpp     ****             // Rotate V right by 1 bit.
 291:GF128.cpp     ****             mask = ((~(V3 & 0x01)) + 1) & 0xE1000000;
 292:GF128.cpp     ****             V3 = (V3 >> 1) | (V2 << 31);
 252              		.loc 2 292 34 discriminator 2 view .LVU62
 253 0044 4FEACE7B 		lsl	fp, lr, #31
 288:GF128.cpp     ****             Z3 ^= (V3 & mask);
 254              		.loc 2 288 16 discriminator 2 view .LVU63
 255 0048 5340     		eors	r3, r3, r2
 256              	.LVL23:
 291:GF128.cpp     ****             V3 = (V3 >> 1) | (V2 << 31);
 257              		.loc 2 291 13 is_stmt 1 discriminator 2 view .LVU64
 258              	.LBE9:
 280:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 259              		.loc 2 280 35 is_stmt 0 discriminator 2 view .LVU65
 260 004a 013E     		subs	r6, r6, #1
 261              	.LVL24:
 262              	.LBB10:
 291:GF128.cpp     ****             V3 = (V3 >> 1) | (V2 << 31);
 263              		.loc 2 291 36 discriminator 2 view .LVU66
 264 004c 4CF30002 		sbfx	r2, ip, #0, #1
 265              		.loc 2 292 16 discriminator 2 view .LVU67
 266 0050 4BEA5C0C 		orr	ip, fp, ip, lsr #1
 267              	.LVL25:
 293:GF128.cpp     ****             V2 = (V2 >> 1) | (V1 << 31);
 268              		.loc 2 293 34 discriminator 2 view .LVU68
 269 0054 4FEAC87B 		lsl	fp, r8, #31
 291:GF128.cpp     ****             V3 = (V3 >> 1) | (V2 << 31);
 270              		.loc 2 291 18 discriminator 2 view .LVU69
 271 0058 02F06142 		and	r2, r2, #-520093696
 272              	.LVL26:
 292:GF128.cpp     ****             V2 = (V2 >> 1) | (V1 << 31);
 273              		.loc 2 292 13 is_stmt 1 discriminator 2 view .LVU70
 274              		.loc 2 293 13 discriminator 2 view .LVU71
 275              		.loc 2 293 16 is_stmt 0 discriminator 2 view .LVU72
 276 005c 4BEA5E0E 		orr	lr, fp, lr, lsr #1
 277              	.LVL27:
 294:GF128.cpp     ****             V1 = (V1 >> 1) | (V0 << 31);
 278              		.loc 2 294 13 is_stmt 1 discriminator 2 view .LVU73
 279              	.LBE10:
 280:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 280              		.loc 2 280 53 is_stmt 0 discriminator 2 view .LVU74
 281 0060 7F00     		lsls	r7, r7, #1
 282              	.LVL28:
 283              	.LBB11:
 284              		.loc 2 294 34 discriminator 2 view .LVU75
 285 0062 4FEAC97B 		lsl	fp, r9, #31
 286              	.LBE11:
 280:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 287              		.loc 2 280 35 discriminator 2 view .LVU76
 288 0066 16F0FF06 		ands	r6, r6, #255
 289              	.LBB12:
 290              		.loc 2 294 16 discriminator 2 view .LVU77
 291 006a 4BEA5808 		orr	r8, fp, r8, lsr #1
 292              	.LVL29:
 295:GF128.cpp     ****             V0 = (V0 >> 1) ^ mask;
 293              		.loc 2 295 13 is_stmt 1 discriminator 2 view .LVU78
 294              		.loc 2 295 16 is_stmt 0 discriminator 2 view .LVU79
 295 006e 82EA5909 		eor	r9, r2, r9, lsr #1
 296              	.LVL30:
 297              		.loc 2 295 16 discriminator 2 view .LVU80
 298              	.LBE12:
 280:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 299              		.loc 2 280 9 is_stmt 1 discriminator 2 view .LVU81
 280:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 300              		.loc 2 280 53 is_stmt 0 discriminator 2 view .LVU82
 301 0072 FFB2     		uxtb	r7, r7
 302              	.LVL31:
 280:GF128.cpp     ****             // Extract the high bit of "value" and turn it into a mask.
 303              		.loc 2 280 35 is_stmt 1 discriminator 2 view .LVU83
 304 0074 D6D1     		bne	.L7
 305              	.LBE13:
 306              	.LBE7:
 278:GF128.cpp     ****         uint8_t value = ((const uint8_t *)Y)[posn];
 307              		.loc 2 278 5 discriminator 2 view .LVU84
 278:GF128.cpp     ****         uint8_t value = ((const uint8_t *)Y)[posn];
 308              		.loc 2 278 33 discriminator 2 view .LVU85
 309 0076 019A     		ldr	r2, [sp, #4]
 310              	.LVL32:
 278:GF128.cpp     ****         uint8_t value = ((const uint8_t *)Y)[posn];
 311              		.loc 2 278 33 is_stmt 0 discriminator 2 view .LVU86
 312 0078 9245     		cmp	r10, r2
 313 007a D0D1     		bne	.L8
 314              	.LBE14:
 296:GF128.cpp     ****         }
 297:GF128.cpp     ****     }
 298:GF128.cpp     **** 
 299:GF128.cpp     ****     // We have finished the block so copy Z into Y and byte-swap.
 300:GF128.cpp     ****     Y[0] = htobe32(Z0);
 315              		.loc 2 300 5 is_stmt 1 view .LVU87
 316              	.LBB15:
 317              		.loc 2 300 12 view .LVU88
 318              	.LVL33:
 319              		.loc 2 300 12 view .LVU89
 320 007c 2DBA     		rev	r5, r5
 321              	.LVL34:
 322              		.loc 2 300 12 is_stmt 0 view .LVU90
 323 007e 24BA     		rev	r4, r4
 324              	.LVL35:
 325              		.loc 2 300 12 view .LVU91
 326 0080 09BA     		rev	r1, r1
 327              	.LVL36:
 328              		.loc 2 300 12 view .LVU92
 329 0082 1BBA     		rev	r3, r3
 330              	.LVL37:
 331              		.loc 2 300 10 view .LVU93
 332 0084 0560     		str	r5, [r0]
 333              	.LBE15:
 301:GF128.cpp     ****     Y[1] = htobe32(Z1);
 334              		.loc 2 301 5 is_stmt 1 view .LVU94
 335              	.LBB16:
 336              		.loc 2 301 12 view .LVU95
 337              		.loc 2 301 12 view .LVU96
 338              		.loc 2 301 10 is_stmt 0 view .LVU97
 339 0086 4460     		str	r4, [r0, #4]
 340              	.LBE16:
 302:GF128.cpp     ****     Y[2] = htobe32(Z2);
 341              		.loc 2 302 5 is_stmt 1 view .LVU98
 342              	.LBB17:
 343              		.loc 2 302 12 view .LVU99
 344              		.loc 2 302 12 view .LVU100
 345              		.loc 2 302 10 is_stmt 0 view .LVU101
 346 0088 8160     		str	r1, [r0, #8]
 347              	.LBE17:
 303:GF128.cpp     ****     Y[3] = htobe32(Z3);
 348              		.loc 2 303 5 is_stmt 1 view .LVU102
 349              	.LBB18:
 350              		.loc 2 303 12 view .LVU103
 351              		.loc 2 303 12 view .LVU104
 352              		.loc 2 303 10 is_stmt 0 view .LVU105
 353 008a C360     		str	r3, [r0, #12]
 354              	.LBE18:
 304:GF128.cpp     **** #endif // !__AVR__
 305:GF128.cpp     **** }
 355              		.loc 2 305 1 view .LVU106
 356 008c 03B0     		add	sp, sp, #12
 357              	.LCFI2:
 358              		.cfi_def_cfa_offset 36
 359              		@ sp needed
 360 008e BDE8F08F 		pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
 361              		.loc 2 305 1 view .LVU107
 362              		.cfi_endproc
 363              	.LFE14:
 364              		.cantunwind
 365              		.fnend
 367              		.section	.text._ZN5GF1283dblEPm,"ax",%progbits
 368              		.align	1
 369              		.global	_ZN5GF1283dblEPm
 370              		.syntax unified
 371              		.thumb
 372              		.thumb_func
 373              		.fpu softvfp
 375              	_ZN5GF1283dblEPm:
 376              		.fnstart
 377              	.LVL38:
 378              	.LFB15:
 306:GF128.cpp     **** 
 307:GF128.cpp     **** /**
 308:GF128.cpp     ****  * \brief Doubles a value in the GF(2^128) field.
 309:GF128.cpp     ****  *
 310:GF128.cpp     ****  * \param V The value to double, and the result.  This array is
 311:GF128.cpp     ****  * assumed to be in big-endian order on entry and exit.
 312:GF128.cpp     ****  *
 313:GF128.cpp     ****  * Block cipher modes such as <a href="https://en.wikipedia.org/wiki/Disk_encryption_theory#Xor-enc
 314:GF128.cpp     ****  * are similar to CTR mode but instead of incrementing the nonce every
 315:GF128.cpp     ****  * block, the modes multiply the nonce by 2 in the GF(2^128) field every
 316:GF128.cpp     ****  * block.  This function is provided to help with implementing such modes.
 317:GF128.cpp     ****  *
 318:GF128.cpp     ****  * \sa dblEAX(), dblXTS(), mul()
 319:GF128.cpp     ****  */
 320:GF128.cpp     **** void GF128::dbl(uint32_t V[4])
 321:GF128.cpp     **** {
 379              		.loc 2 321 1 is_stmt 1 view -0
 380              		.cfi_startproc
 381              		@ args = 0, pretend = 0, frame = 0
 382              		@ frame_needed = 0, uses_anonymous_args = 0
 322:GF128.cpp     **** #if defined(__AVR__)
 323:GF128.cpp     ****     __asm__ __volatile__ (
 324:GF128.cpp     ****         "ld r16,Z\n"
 325:GF128.cpp     ****         "ldd r17,Z+1\n"
 326:GF128.cpp     ****         "ldd r18,Z+2\n"
 327:GF128.cpp     ****         "ldd r19,Z+3\n"
 328:GF128.cpp     ****         "lsr r16\n"
 329:GF128.cpp     ****         "ror r17\n"
 330:GF128.cpp     ****         "ror r18\n"
 331:GF128.cpp     ****         "ror r19\n"
 332:GF128.cpp     ****         "std Z+1,r17\n"
 333:GF128.cpp     ****         "std Z+2,r18\n"
 334:GF128.cpp     ****         "std Z+3,r19\n"
 335:GF128.cpp     ****         "ldd r17,Z+4\n"
 336:GF128.cpp     ****         "ldd r18,Z+5\n"
 337:GF128.cpp     ****         "ldd r19,Z+6\n"
 338:GF128.cpp     ****         "ldd r20,Z+7\n"
 339:GF128.cpp     ****         "ror r17\n"
 340:GF128.cpp     ****         "ror r18\n"
 341:GF128.cpp     ****         "ror r19\n"
 342:GF128.cpp     ****         "ror r20\n"
 343:GF128.cpp     ****         "std Z+4,r17\n"
 344:GF128.cpp     ****         "std Z+5,r18\n"
 345:GF128.cpp     ****         "std Z+6,r19\n"
 346:GF128.cpp     ****         "std Z+7,r20\n"
 347:GF128.cpp     ****         "ldd r17,Z+8\n"
 348:GF128.cpp     ****         "ldd r18,Z+9\n"
 349:GF128.cpp     ****         "ldd r19,Z+10\n"
 350:GF128.cpp     ****         "ldd r20,Z+11\n"
 351:GF128.cpp     ****         "ror r17\n"
 352:GF128.cpp     ****         "ror r18\n"
 353:GF128.cpp     ****         "ror r19\n"
 354:GF128.cpp     ****         "ror r20\n"
 355:GF128.cpp     ****         "std Z+8,r17\n"
 356:GF128.cpp     ****         "std Z+9,r18\n"
 357:GF128.cpp     ****         "std Z+10,r19\n"
 358:GF128.cpp     ****         "std Z+11,r20\n"
 359:GF128.cpp     ****         "ldd r17,Z+12\n"
 360:GF128.cpp     ****         "ldd r18,Z+13\n"
 361:GF128.cpp     ****         "ldd r19,Z+14\n"
 362:GF128.cpp     ****         "ldd r20,Z+15\n"
 363:GF128.cpp     ****         "ror r17\n"
 364:GF128.cpp     ****         "ror r18\n"
 365:GF128.cpp     ****         "ror r19\n"
 366:GF128.cpp     ****         "ror r20\n"
 367:GF128.cpp     ****         "std Z+12,r17\n"
 368:GF128.cpp     ****         "std Z+13,r18\n"
 369:GF128.cpp     ****         "std Z+14,r19\n"
 370:GF128.cpp     ****         "std Z+15,r20\n"
 371:GF128.cpp     ****         "mov r17,__zero_reg__\n"
 372:GF128.cpp     ****         "sbc r17,__zero_reg__\n"
 373:GF128.cpp     ****         "andi r17,0xE1\n"
 374:GF128.cpp     ****         "eor r16,r17\n"
 375:GF128.cpp     ****         "st Z,r16\n"
 376:GF128.cpp     ****         : : "z"(V)
 377:GF128.cpp     ****         : "r16", "r17", "r18", "r19", "r20"
 378:GF128.cpp     ****     );
 379:GF128.cpp     **** #else
 380:GF128.cpp     ****     uint32_t V0 = be32toh(V[0]);
 383              		.loc 2 380 5 view .LVU109
 384              		.loc 2 380 19 view .LVU110
 321:GF128.cpp     **** #if defined(__AVR__)
 385              		.loc 2 321 1 is_stmt 0 view .LVU111
 386 0000 30B5     		push	{r4, r5, lr}
 387              	.LCFI3:
 388              		.cfi_def_cfa_offset 12
 389              		.cfi_offset 4, -12
 390              		.cfi_offset 5, -8
 391              		.cfi_offset 14, -4
 392 0002 C568     		ldr	r5, [r0, #12]
 393 0004 0168     		ldr	r1, [r0]
 394 0006 4268     		ldr	r2, [r0, #4]
 395 0008 8368     		ldr	r3, [r0, #8]
 396 000a 2DBA     		rev	r5, r5
 381:GF128.cpp     ****     uint32_t V1 = be32toh(V[1]);
 382:GF128.cpp     ****     uint32_t V2 = be32toh(V[2]);
 383:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 384:GF128.cpp     ****     uint32_t mask = ((~(V3 & 0x01)) + 1) & 0xE1000000;
 397              		.loc 2 384 37 view .LVU112
 398 000c 45F30004 		sbfx	r4, r5, #0, #1
 399 0010 09BA     		rev	r1, r1
 400              	.LVL39:
 380:GF128.cpp     ****     uint32_t V1 = be32toh(V[1]);
 401              		.loc 2 380 19 is_stmt 1 view .LVU113
 381:GF128.cpp     ****     uint32_t V1 = be32toh(V[1]);
 402              		.loc 2 381 5 view .LVU114
 381:GF128.cpp     ****     uint32_t V1 = be32toh(V[1]);
 403              		.loc 2 381 19 view .LVU115
 404              		.loc 2 384 14 is_stmt 0 view .LVU116
 405 0012 04F06144 		and	r4, r4, #-520093696
 406 0016 12BA     		rev	r2, r2
 407              	.LVL40:
 381:GF128.cpp     ****     uint32_t V1 = be32toh(V[1]);
 408              		.loc 2 381 19 is_stmt 1 view .LVU117
 382:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 409              		.loc 2 382 5 view .LVU118
 382:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 410              		.loc 2 382 19 view .LVU119
 385:GF128.cpp     ****     V3 = (V3 >> 1) | (V2 << 31);
 386:GF128.cpp     ****     V2 = (V2 >> 1) | (V1 << 31);
 387:GF128.cpp     ****     V1 = (V1 >> 1) | (V0 << 31);
 388:GF128.cpp     ****     V0 = (V0 >> 1) ^ mask;
 411              		.loc 2 388 8 is_stmt 0 view .LVU120
 412 0018 84EA5104 		eor	r4, r4, r1, lsr #1
 387:GF128.cpp     ****     V0 = (V0 >> 1) ^ mask;
 413              		.loc 2 387 26 view .LVU121
 414 001c C907     		lsls	r1, r1, #31
 415 001e 1BBA     		rev	r3, r3
 416              	.LVL41:
 382:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 417              		.loc 2 382 19 is_stmt 1 view .LVU122
 383:GF128.cpp     ****     uint32_t mask = ((~(V3 & 0x01)) + 1) & 0xE1000000;
 418              		.loc 2 383 5 view .LVU123
 383:GF128.cpp     ****     uint32_t mask = ((~(V3 & 0x01)) + 1) & 0xE1000000;
 419              		.loc 2 383 19 view .LVU124
 383:GF128.cpp     ****     uint32_t mask = ((~(V3 & 0x01)) + 1) & 0xE1000000;
 420              		.loc 2 383 19 view .LVU125
 384:GF128.cpp     ****     V3 = (V3 >> 1) | (V2 << 31);
 421              		.loc 2 384 5 view .LVU126
 385:GF128.cpp     ****     V2 = (V2 >> 1) | (V1 << 31);
 422              		.loc 2 385 5 view .LVU127
 386:GF128.cpp     ****     V1 = (V1 >> 1) | (V0 << 31);
 423              		.loc 2 386 5 view .LVU128
 387:GF128.cpp     ****     V0 = (V0 >> 1) ^ mask;
 424              		.loc 2 387 5 view .LVU129
 425              		.loc 2 388 5 view .LVU130
 389:GF128.cpp     ****     V[0] = htobe32(V0);
 426              		.loc 2 389 5 view .LVU131
 427              	.LBB19:
 428              		.loc 2 389 12 view .LVU132
 429              		.loc 2 389 12 view .LVU133
 430              	.LBE19:
 387:GF128.cpp     ****     V0 = (V0 >> 1) ^ mask;
 431              		.loc 2 387 8 is_stmt 0 view .LVU134
 432 0020 41EA5201 		orr	r1, r1, r2, lsr #1
 386:GF128.cpp     ****     V1 = (V1 >> 1) | (V0 << 31);
 433              		.loc 2 386 26 view .LVU135
 434 0024 D207     		lsls	r2, r2, #31
 435              	.LVL42:
 386:GF128.cpp     ****     V1 = (V1 >> 1) | (V0 << 31);
 436              		.loc 2 386 8 view .LVU136
 437 0026 42EA5302 		orr	r2, r2, r3, lsr #1
 438              	.LVL43:
 385:GF128.cpp     ****     V2 = (V2 >> 1) | (V1 << 31);
 439              		.loc 2 385 26 view .LVU137
 440 002a DB07     		lsls	r3, r3, #31
 441              	.LVL44:
 385:GF128.cpp     ****     V2 = (V2 >> 1) | (V1 << 31);
 442              		.loc 2 385 8 view .LVU138
 443 002c 43EA5503 		orr	r3, r3, r5, lsr #1
 444              	.LVL45:
 385:GF128.cpp     ****     V2 = (V2 >> 1) | (V1 << 31);
 445              		.loc 2 385 8 view .LVU139
 446 0030 24BA     		rev	r4, r4
 447 0032 09BA     		rev	r1, r1
 448 0034 12BA     		rev	r2, r2
 449              	.LVL46:
 385:GF128.cpp     ****     V2 = (V2 >> 1) | (V1 << 31);
 450              		.loc 2 385 8 view .LVU140
 451 0036 1BBA     		rev	r3, r3
 452              	.LVL47:
 453              	.LBB20:
 454              		.loc 2 389 10 view .LVU141
 455 0038 0460     		str	r4, [r0]
 456              	.LVL48:
 457              		.loc 2 389 10 view .LVU142
 458              	.LBE20:
 390:GF128.cpp     ****     V[1] = htobe32(V1);
 459              		.loc 2 390 5 is_stmt 1 view .LVU143
 460              	.LBB21:
 461              		.loc 2 390 12 view .LVU144
 462              		.loc 2 390 12 view .LVU145
 463              		.loc 2 390 10 is_stmt 0 view .LVU146
 464 003a 4160     		str	r1, [r0, #4]
 465              	.LVL49:
 466              		.loc 2 390 10 view .LVU147
 467              	.LBE21:
 391:GF128.cpp     ****     V[2] = htobe32(V2);
 468              		.loc 2 391 5 is_stmt 1 view .LVU148
 469              	.LBB22:
 470              		.loc 2 391 12 view .LVU149
 471              		.loc 2 391 12 view .LVU150
 472              		.loc 2 391 10 is_stmt 0 view .LVU151
 473 003c 8260     		str	r2, [r0, #8]
 474              	.LVL50:
 475              		.loc 2 391 10 view .LVU152
 476              	.LBE22:
 392:GF128.cpp     ****     V[3] = htobe32(V3);
 477              		.loc 2 392 5 is_stmt 1 view .LVU153
 478              	.LBB23:
 479              		.loc 2 392 12 view .LVU154
 480              		.loc 2 392 12 view .LVU155
 481              		.loc 2 392 10 is_stmt 0 view .LVU156
 482 003e C360     		str	r3, [r0, #12]
 483              	.LVL51:
 484              		.loc 2 392 10 view .LVU157
 485              	.LBE23:
 393:GF128.cpp     **** #endif
 394:GF128.cpp     **** }
 486              		.loc 2 394 1 view .LVU158
 487 0040 30BD     		pop	{r4, r5, pc}
 488              		.loc 2 394 1 view .LVU159
 489              		.cfi_endproc
 490              	.LFE15:
 491              		.cantunwind
 492              		.fnend
 494              		.section	.text._ZN5GF1286dblEAXEPm,"ax",%progbits
 495              		.align	1
 496              		.global	_ZN5GF1286dblEAXEPm
 497              		.syntax unified
 498              		.thumb
 499              		.thumb_func
 500              		.fpu softvfp
 502              	_ZN5GF1286dblEAXEPm:
 503              		.fnstart
 504              	.LVL52:
 505              	.LFB16:
 395:GF128.cpp     **** 
 396:GF128.cpp     **** /**
 397:GF128.cpp     ****  * \brief Doubles a value in the GF(2^128) field using EAX conventions.
 398:GF128.cpp     ****  *
 399:GF128.cpp     ****  * \param V The value to double, and the result.  This array is
 400:GF128.cpp     ****  * assumed to be in big-endian order on entry and exit.
 401:GF128.cpp     ****  *
 402:GF128.cpp     ****  * This function differs from dbl() that it uses the conventions of EAX mode
 403:GF128.cpp     ****  * instead of those of NIST SP 800-38D (GCM).  The two operations have
 404:GF128.cpp     ****  * equivalent security but the bits are ordered differently with the
 405:GF128.cpp     ****  * value shifted left instead of right.
 406:GF128.cpp     ****  *
 407:GF128.cpp     ****  * References: https://en.wikipedia.org/wiki/EAX_mode,
 408:GF128.cpp     ****  * http://web.cs.ucdavis.edu/~rogaway/papers/eax.html
 409:GF128.cpp     ****  *
 410:GF128.cpp     ****  * \sa dbl(), dblXTS(), mul()
 411:GF128.cpp     ****  */
 412:GF128.cpp     **** void GF128::dblEAX(uint32_t V[4])
 413:GF128.cpp     **** {
 506              		.loc 2 413 1 is_stmt 1 view -0
 507              		.cfi_startproc
 508              		@ args = 0, pretend = 0, frame = 0
 509              		@ frame_needed = 0, uses_anonymous_args = 0
 414:GF128.cpp     **** #if defined(__AVR__)
 415:GF128.cpp     ****     __asm__ __volatile__ (
 416:GF128.cpp     ****         "ldd r16,Z+15\n"
 417:GF128.cpp     ****         "ldd r17,Z+14\n"
 418:GF128.cpp     ****         "ldd r18,Z+13\n"
 419:GF128.cpp     ****         "ldd r19,Z+12\n"
 420:GF128.cpp     ****         "lsl r16\n"
 421:GF128.cpp     ****         "rol r17\n"
 422:GF128.cpp     ****         "rol r18\n"
 423:GF128.cpp     ****         "rol r19\n"
 424:GF128.cpp     ****         "std Z+14,r17\n"
 425:GF128.cpp     ****         "std Z+13,r18\n"
 426:GF128.cpp     ****         "std Z+12,r19\n"
 427:GF128.cpp     ****         "ldd r17,Z+11\n"
 428:GF128.cpp     ****         "ldd r18,Z+10\n"
 429:GF128.cpp     ****         "ldd r19,Z+9\n"
 430:GF128.cpp     ****         "ldd r20,Z+8\n"
 431:GF128.cpp     ****         "rol r17\n"
 432:GF128.cpp     ****         "rol r18\n"
 433:GF128.cpp     ****         "rol r19\n"
 434:GF128.cpp     ****         "rol r20\n"
 435:GF128.cpp     ****         "std Z+11,r17\n"
 436:GF128.cpp     ****         "std Z+10,r18\n"
 437:GF128.cpp     ****         "std Z+9,r19\n"
 438:GF128.cpp     ****         "std Z+8,r20\n"
 439:GF128.cpp     ****         "ldd r17,Z+7\n"
 440:GF128.cpp     ****         "ldd r18,Z+6\n"
 441:GF128.cpp     ****         "ldd r19,Z+5\n"
 442:GF128.cpp     ****         "ldd r20,Z+4\n"
 443:GF128.cpp     ****         "rol r17\n"
 444:GF128.cpp     ****         "rol r18\n"
 445:GF128.cpp     ****         "rol r19\n"
 446:GF128.cpp     ****         "rol r20\n"
 447:GF128.cpp     ****         "std Z+7,r17\n"
 448:GF128.cpp     ****         "std Z+6,r18\n"
 449:GF128.cpp     ****         "std Z+5,r19\n"
 450:GF128.cpp     ****         "std Z+4,r20\n"
 451:GF128.cpp     ****         "ldd r17,Z+3\n"
 452:GF128.cpp     ****         "ldd r18,Z+2\n"
 453:GF128.cpp     ****         "ldd r19,Z+1\n"
 454:GF128.cpp     ****         "ld r20,Z\n"
 455:GF128.cpp     ****         "rol r17\n"
 456:GF128.cpp     ****         "rol r18\n"
 457:GF128.cpp     ****         "rol r19\n"
 458:GF128.cpp     ****         "rol r20\n"
 459:GF128.cpp     ****         "std Z+3,r17\n"
 460:GF128.cpp     ****         "std Z+2,r18\n"
 461:GF128.cpp     ****         "std Z+1,r19\n"
 462:GF128.cpp     ****         "st Z,r20\n"
 463:GF128.cpp     ****         "mov r17,__zero_reg__\n"
 464:GF128.cpp     ****         "sbc r17,__zero_reg__\n"
 465:GF128.cpp     ****         "andi r17,0x87\n"
 466:GF128.cpp     ****         "eor r16,r17\n"
 467:GF128.cpp     ****         "std Z+15,r16\n"
 468:GF128.cpp     ****         : : "z"(V)
 469:GF128.cpp     ****         : "r16", "r17", "r18", "r19", "r20"
 470:GF128.cpp     ****     );
 471:GF128.cpp     **** #else
 472:GF128.cpp     ****     uint32_t V0 = be32toh(V[0]);
 510              		.loc 2 472 5 view .LVU161
 511              		.loc 2 472 19 view .LVU162
 512 0000 4168     		ldr	r1, [r0, #4]
 513 0002 0368     		ldr	r3, [r0]
 514 0004 8268     		ldr	r2, [r0, #8]
 413:GF128.cpp     **** #if defined(__AVR__)
 515              		.loc 2 413 1 is_stmt 0 view .LVU163
 516 0006 F0B5     		push	{r4, r5, r6, r7, lr}
 517              	.LCFI4:
 518              		.cfi_def_cfa_offset 20
 519              		.cfi_offset 4, -20
 520              		.cfi_offset 5, -16
 521              		.cfi_offset 6, -12
 522              		.cfi_offset 7, -8
 523              		.cfi_offset 14, -4
 524 0008 0FBA     		rev	r7, r1
 525 000a C568     		ldr	r5, [r0, #12]
 526 000c 1BBA     		rev	r3, r3
 527              	.LVL53:
 528              		.loc 2 472 19 is_stmt 1 view .LVU164
 473:GF128.cpp     ****     uint32_t V1 = be32toh(V[1]);
 529              		.loc 2 473 5 view .LVU165
 530              		.loc 2 473 19 view .LVU166
 531              		.loc 2 473 19 view .LVU167
 474:GF128.cpp     ****     uint32_t V2 = be32toh(V[2]);
 532              		.loc 2 474 5 view .LVU168
 533              		.loc 2 474 19 view .LVU169
 475:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 476:GF128.cpp     ****     uint32_t mask = ((~(V0 >> 31)) + 1) & 0x00000087;
 477:GF128.cpp     ****     V0 = (V0 << 1) | (V1 >> 31);
 534              		.loc 2 477 26 is_stmt 0 view .LVU170
 535 000e FC0F     		lsrs	r4, r7, #31
 536 0010 16BA     		rev	r6, r2
 537              	.LVL54:
 474:GF128.cpp     ****     uint32_t V2 = be32toh(V[2]);
 538              		.loc 2 474 19 is_stmt 1 view .LVU171
 475:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 539              		.loc 2 475 5 view .LVU172
 475:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 540              		.loc 2 475 19 view .LVU173
 541 0012 2DBA     		rev	r5, r5
 542              	.LVL55:
 475:GF128.cpp     ****     uint32_t V3 = be32toh(V[3]);
 543              		.loc 2 475 19 view .LVU174
 476:GF128.cpp     ****     V0 = (V0 << 1) | (V1 >> 31);
 544              		.loc 2 476 5 view .LVU175
 545              		.loc 2 477 5 view .LVU176
 478:GF128.cpp     ****     V1 = (V1 << 1) | (V2 >> 31);
 546              		.loc 2 478 5 view .LVU177
 479:GF128.cpp     ****     V2 = (V2 << 1) | (V3 >> 31);
 547              		.loc 2 479 5 view .LVU178
 480:GF128.cpp     ****     V3 = (V3 << 1) ^ mask;
 548              		.loc 2 480 5 view .LVU179
 481:GF128.cpp     ****     V[0] = htobe32(V0);
 549              		.loc 2 481 5 view .LVU180
 550              	.LBB24:
 551              		.loc 2 481 12 view .LVU181
 552              		.loc 2 481 12 view .LVU182
 553              	.LBE24:
 477:GF128.cpp     ****     V1 = (V1 << 1) | (V2 >> 31);
 554              		.loc 2 477 8 is_stmt 0 view .LVU183
 555 0014 44EA4304 		orr	r4, r4, r3, lsl #1
 556              	.LVL56:
 476:GF128.cpp     ****     V0 = (V0 << 1) | (V1 >> 31);
 557              		.loc 2 476 36 view .LVU184
 558 0018 DB17     		asrs	r3, r3, #31
 559              	.LVL57:
 478:GF128.cpp     ****     V2 = (V2 << 1) | (V3 >> 31);
 560              		.loc 2 478 26 view .LVU185
 561 001a F10F     		lsrs	r1, r6, #31
 479:GF128.cpp     ****     V3 = (V3 << 1) ^ mask;
 562              		.loc 2 479 26 view .LVU186
 563 001c EA0F     		lsrs	r2, r5, #31
 476:GF128.cpp     ****     V0 = (V0 << 1) | (V1 >> 31);
 564              		.loc 2 476 14 view .LVU187
 565 001e 03F08703 		and	r3, r3, #135
 566              	.LVL58:
 478:GF128.cpp     ****     V2 = (V2 << 1) | (V3 >> 31);
 567              		.loc 2 478 8 view .LVU188
 568 0022 41EA4701 		orr	r1, r1, r7, lsl #1
 569              	.LVL59:
 479:GF128.cpp     ****     V3 = (V3 << 1) ^ mask;
 570              		.loc 2 479 8 view .LVU189
 571 0026 42EA4602 		orr	r2, r2, r6, lsl #1
 572              	.LVL60:
 480:GF128.cpp     ****     V[0] = htobe32(V0);
 573              		.loc 2 480 8 view .LVU190
 574 002a 83EA4503 		eor	r3, r3, r5, lsl #1
 575              	.LVL61:
 480:GF128.cpp     ****     V[0] = htobe32(V0);
 576              		.loc 2 480 8 view .LVU191
 577 002e 24BA     		rev	r4, r4
 578              	.LVL62:
 480:GF128.cpp     ****     V[0] = htobe32(V0);
 579              		.loc 2 480 8 view .LVU192
 580 0030 09BA     		rev	r1, r1
 581              	.LVL63:
 480:GF128.cpp     ****     V[0] = htobe32(V0);
 582              		.loc 2 480 8 view .LVU193
 583 0032 12BA     		rev	r2, r2
 584              	.LVL64:
 480:GF128.cpp     ****     V[0] = htobe32(V0);
 585              		.loc 2 480 8 view .LVU194
 586 0034 1BBA     		rev	r3, r3
 587              	.LVL65:
 588              	.LBB25:
 589              		.loc 2 481 10 view .LVU195
 590 0036 0460     		str	r4, [r0]
 591              	.LVL66:
 592              		.loc 2 481 10 view .LVU196
 593              	.LBE25:
 482:GF128.cpp     ****     V[1] = htobe32(V1);
 594              		.loc 2 482 5 is_stmt 1 view .LVU197
 595              	.LBB26:
 596              		.loc 2 482 12 view .LVU198
 597              		.loc 2 482 12 view .LVU199
 598              		.loc 2 482 10 is_stmt 0 view .LVU200
 599 0038 4160     		str	r1, [r0, #4]
 600              	.LVL67:
 601              		.loc 2 482 10 view .LVU201
 602              	.LBE26:
 483:GF128.cpp     ****     V[2] = htobe32(V2);
 603              		.loc 2 483 5 is_stmt 1 view .LVU202
 604              	.LBB27:
 605              		.loc 2 483 12 view .LVU203
 606              		.loc 2 483 12 view .LVU204
 607              		.loc 2 483 10 is_stmt 0 view .LVU205
 608 003a 8260     		str	r2, [r0, #8]
 609              	.LVL68:
 610              		.loc 2 483 10 view .LVU206
 611              	.LBE27:
 484:GF128.cpp     ****     V[3] = htobe32(V3);
 612              		.loc 2 484 5 is_stmt 1 view .LVU207
 613              	.LBB28:
 614              		.loc 2 484 12 view .LVU208
 615              		.loc 2 484 12 view .LVU209
 616              		.loc 2 484 10 is_stmt 0 view .LVU210
 617 003c C360     		str	r3, [r0, #12]
 618              	.LVL69:
 619              		.loc 2 484 10 view .LVU211
 620              	.LBE28:
 485:GF128.cpp     **** #endif
 486:GF128.cpp     **** }
 621              		.loc 2 486 1 view .LVU212
 622 003e F0BD     		pop	{r4, r5, r6, r7, pc}
 623              		.loc 2 486 1 view .LVU213
 624              		.cfi_endproc
 625              	.LFE16:
 626              		.cantunwind
 627              		.fnend
 629              		.section	.text._ZN5GF1286dblXTSEPm,"ax",%progbits
 630              		.align	1
 631              		.global	_ZN5GF1286dblXTSEPm
 632              		.syntax unified
 633              		.thumb
 634              		.thumb_func
 635              		.fpu softvfp
 637              	_ZN5GF1286dblXTSEPm:
 638              		.fnstart
 639              	.LVL70:
 640              	.LFB17:
 487:GF128.cpp     **** 
 488:GF128.cpp     **** /**
 489:GF128.cpp     ****  * \brief Doubles a value in the GF(2^128) field using XTS conventions.
 490:GF128.cpp     ****  *
 491:GF128.cpp     ****  * \param V The value to double, and the result.  This array is
 492:GF128.cpp     ****  * assumed to be in littlen-endian order on entry and exit.
 493:GF128.cpp     ****  *
 494:GF128.cpp     ****  * This function differs from dbl() that it uses the conventions of XTS mode
 495:GF128.cpp     ****  * instead of those of NIST SP 800-38D (GCM).  The two operations have
 496:GF128.cpp     ****  * equivalent security but the bits are ordered differently with the
 497:GF128.cpp     ****  * value shifted left instead of right.
 498:GF128.cpp     ****  *
 499:GF128.cpp     ****  * References: <a href="http://libeccio.di.unisa.it/Crypto14/Lab/p1619.pdf">IEEE Std. 1619-2007, XT
 500:GF128.cpp     ****  *
 501:GF128.cpp     ****  * \sa dbl(), dblEAX(), mul()
 502:GF128.cpp     ****  */
 503:GF128.cpp     **** #pragma GCC push_options
 504:GF128.cpp     **** #pragma GCC optimize ("O0")
 505:GF128.cpp     **** void GF128::dblXTS(uint32_t V[4])
 506:GF128.cpp     **** {
 641              		.loc 2 506 1 is_stmt 1 view -0
 642              		.cfi_startproc
 643              		@ args = 0, pretend = 0, frame = 40
 644              		@ frame_needed = 1, uses_anonymous_args = 0
 645              		@ link register save eliminated.
 646              		.loc 2 506 1 is_stmt 0 view .LVU215
 647 0000 80B4     		push	{r7}
 648              	.LCFI5:
 649              		.cfi_def_cfa_offset 4
 650              		.cfi_offset 7, -4
 651 0002 8BB0     		sub	sp, sp, #44
 652              	.LCFI6:
 653              		.cfi_def_cfa_offset 48
 654 0004 00AF     		add	r7, sp, #0
 655              	.LCFI7:
 656              		.cfi_def_cfa_register 7
 657 0006 7860     		str	r0, [r7, #4]
 507:GF128.cpp     **** #if defined(__AVR__)
 508:GF128.cpp     ****     __asm__ __volatile__ (
 509:GF128.cpp     ****         "ld r16,Z\n"
 510:GF128.cpp     ****         "ldd r17,Z+1\n"
 511:GF128.cpp     ****         "ldd r18,Z+2\n"
 512:GF128.cpp     ****         "ldd r19,Z+3\n"
 513:GF128.cpp     ****         "lsl r16\n"
 514:GF128.cpp     ****         "rol r17\n"
 515:GF128.cpp     ****         "rol r18\n"
 516:GF128.cpp     ****         "rol r19\n"
 517:GF128.cpp     ****         "std Z+1,r17\n"
 518:GF128.cpp     ****         "std Z+2,r18\n"
 519:GF128.cpp     ****         "std Z+3,r19\n"
 520:GF128.cpp     ****         "ldd r17,Z+4\n"
 521:GF128.cpp     ****         "ldd r18,Z+5\n"
 522:GF128.cpp     ****         "ldd r19,Z+6\n"
 523:GF128.cpp     ****         "ldd r20,Z+7\n"
 524:GF128.cpp     ****         "rol r17\n"
 525:GF128.cpp     ****         "rol r18\n"
 526:GF128.cpp     ****         "rol r19\n"
 527:GF128.cpp     ****         "rol r20\n"
 528:GF128.cpp     ****         "std Z+4,r17\n"
 529:GF128.cpp     ****         "std Z+5,r18\n"
 530:GF128.cpp     ****         "std Z+6,r19\n"
 531:GF128.cpp     ****         "std Z+7,r20\n"
 532:GF128.cpp     ****         "ldd r17,Z+8\n"
 533:GF128.cpp     ****         "ldd r18,Z+9\n"
 534:GF128.cpp     ****         "ldd r19,Z+10\n"
 535:GF128.cpp     ****         "ldd r20,Z+11\n"
 536:GF128.cpp     ****         "rol r17\n"
 537:GF128.cpp     ****         "rol r18\n"
 538:GF128.cpp     ****         "rol r19\n"
 539:GF128.cpp     ****         "rol r20\n"
 540:GF128.cpp     ****         "std Z+8,r17\n"
 541:GF128.cpp     ****         "std Z+9,r18\n"
 542:GF128.cpp     ****         "std Z+10,r19\n"
 543:GF128.cpp     ****         "std Z+11,r20\n"
 544:GF128.cpp     ****         "ldd r17,Z+12\n"
 545:GF128.cpp     ****         "ldd r18,Z+13\n"
 546:GF128.cpp     ****         "ldd r19,Z+14\n"
 547:GF128.cpp     ****         "ldd r20,Z+15\n"
 548:GF128.cpp     ****         "rol r17\n"
 549:GF128.cpp     ****         "rol r18\n"
 550:GF128.cpp     ****         "rol r19\n"
 551:GF128.cpp     ****         "rol r20\n"
 552:GF128.cpp     ****         "std Z+12,r17\n"
 553:GF128.cpp     ****         "std Z+13,r18\n"
 554:GF128.cpp     ****         "std Z+14,r19\n"
 555:GF128.cpp     ****         "std Z+15,r20\n"
 556:GF128.cpp     ****         "mov r17,__zero_reg__\n"
 557:GF128.cpp     ****         "sbc r17,__zero_reg__\n"
 558:GF128.cpp     ****         "andi r17,0x87\n"
 559:GF128.cpp     ****         "eor r16,r17\n"
 560:GF128.cpp     ****         "st Z,r16\n"
 561:GF128.cpp     ****         : : "z"(V)
 562:GF128.cpp     ****         : "r16", "r17", "r18", "r19", "r20"
 563:GF128.cpp     ****     );
 564:GF128.cpp     **** #else
 565:GF128.cpp     ****    /* uint32_t V0 = le32toh(V[0]);
 566:GF128.cpp     ****     uint32_t V1 = le32toh(V[1]);
 567:GF128.cpp     ****     uint32_t V2 = le32toh(V[2]);
 568:GF128.cpp     ****     uint32_t V3 = le32toh(V[3]);
 569:GF128.cpp     ****     uint32_t mask = ((~(V3 >> 31)) + 1) & 0x00000087;
 570:GF128.cpp     ****     V3 = (V3 << 1) | (V2 >> 31);
 571:GF128.cpp     ****     V2 = (V2 << 1) | (V1 >> 31);
 572:GF128.cpp     ****     V1 = (V1 << 1) | (V0 >> 31);
 573:GF128.cpp     ****     V0 = (V0 << 1) ^ mask;
 574:GF128.cpp     ****     V[0] = htole32(V0);
 575:GF128.cpp     ****     V[1] = htole32(V1);
 576:GF128.cpp     ****     V[2] = htole32(V2);
 577:GF128.cpp     ****     V[3] = htole32(V3); */
 578:GF128.cpp     **** 
 579:GF128.cpp     ****     
 580:GF128.cpp     ****     uint8_t T[16];
 658              		.loc 2 580 5 is_stmt 1 view .LVU216
 581:GF128.cpp     ****     uint8_t Cin = 0, Cout;
 659              		.loc 2 581 5 view .LVU217
 660              		.loc 2 581 13 is_stmt 0 view .LVU218
 661 0008 0023     		movs	r3, #0
 662 000a 87F82730 		strb	r3, [r7, #39]
 663              	.LVL71:
 582:GF128.cpp     **** 
 583:GF128.cpp     ****     // 32 bits / 8 = 4 bytes since 8 bits = 1 byte, therefore one single V index is 4 T index, as i
 584:GF128.cpp     ****     // Conversion vice versa is the same except memcpy locations are changed because 4 T index = 1 
 585:GF128.cpp     ****     
 586:GF128.cpp     ****     // Convert 4x uint32_t to 16x uint8_t
 587:GF128.cpp     ****     for (int i = 0; i < 4; i++) {
 664              		.loc 2 587 5 is_stmt 1 view .LVU219
 665              	.LBB29:
 666              		.loc 2 587 14 is_stmt 0 view .LVU220
 667 000e 0023     		movs	r3, #0
 668              	.LVL72:
 669              		.loc 2 587 14 view .LVU221
 670 0010 3B62     		str	r3, [r7, #32]
 671              	.LVL73:
 672              	.L15:
 673              		.loc 2 587 23 is_stmt 1 discriminator 3 view .LVU222
 674 0012 3B6A     		ldr	r3, [r7, #32]
 675 0014 032B     		cmp	r3, #3
 676 0016 18DC     		bgt	.L14
 588:GF128.cpp     ****         V[i] = le32toh(V[i]);
 677              		.loc 2 588 9 discriminator 2 view .LVU223
 678              		.loc 2 588 16 is_stmt 0 discriminator 2 view .LVU224
 679 0018 3B6A     		ldr	r3, [r7, #32]
 680 001a 9B00     		lsls	r3, r3, #2
 681 001c 7A68     		ldr	r2, [r7, #4]
 682 001e 1A44     		add	r2, r2, r3
 683              		.loc 2 588 11 discriminator 2 view .LVU225
 684 0020 3B6A     		ldr	r3, [r7, #32]
 685              		.loc 2 588 12 discriminator 2 view .LVU226
 686 0022 9B00     		lsls	r3, r3, #2
 687 0024 7968     		ldr	r1, [r7, #4]
 688 0026 0B44     		add	r3, r3, r1
 689              		.loc 2 588 16 discriminator 2 view .LVU227
 690 0028 1268     		ldr	r2, [r2]
 691              		.loc 2 588 14 discriminator 2 view .LVU228
 692 002a 1A60     		str	r2, [r3]
 589:GF128.cpp     ****         std::memcpy(&T[i * 4], &V[i], sizeof(uint32_t));
 693              		.loc 2 589 9 is_stmt 1 discriminator 2 view .LVU229
 694              		.loc 2 589 26 is_stmt 0 discriminator 2 view .LVU230
 695 002c 3B6A     		ldr	r3, [r7, #32]
 696 002e 9B00     		lsls	r3, r3, #2
 697              		.loc 2 589 21 discriminator 2 view .LVU231
 698 0030 07F10802 		add	r2, r7, #8
 699 0034 1344     		add	r3, r3, r2
 700              		.loc 2 589 35 discriminator 2 view .LVU232
 701 0036 3A6A     		ldr	r2, [r7, #32]
 702              		.loc 2 589 36 discriminator 2 view .LVU233
 703 0038 9200     		lsls	r2, r2, #2
 704              		.loc 2 589 32 discriminator 2 view .LVU234
 705 003a 7968     		ldr	r1, [r7, #4]
 706 003c 0A44     		add	r2, r2, r1
 707 003e 1268     		ldr	r2, [r2]	@ unaligned
 708              		.loc 2 589 20 discriminator 2 view .LVU235
 709 0040 1A60     		str	r2, [r3]	@ unaligned
 587:GF128.cpp     ****         V[i] = le32toh(V[i]);
 710              		.loc 2 587 5 is_stmt 1 discriminator 2 view .LVU236
 711 0042 3B6A     		ldr	r3, [r7, #32]
 712 0044 0133     		adds	r3, r3, #1
 713 0046 3B62     		str	r3, [r7, #32]
 714              	.LVL74:
 587:GF128.cpp     ****         V[i] = le32toh(V[i]);
 715              		.loc 2 587 5 is_stmt 0 discriminator 2 view .LVU237
 716 0048 E3E7     		b	.L15
 717              	.L14:
 587:GF128.cpp     ****         V[i] = le32toh(V[i]);
 718              		.loc 2 587 5 discriminator 2 view .LVU238
 719              	.LBE29:
 590:GF128.cpp     ****     }
 591:GF128.cpp     ****     
 592:GF128.cpp     ****     //trigger_high();
 593:GF128.cpp     ****     // 16-byte left shifting
 594:GF128.cpp     ****     for (int i = 0; i < 16; i++) {
 720              		.loc 2 594 5 is_stmt 1 view .LVU239
 721              	.LBB30:
 722              		.loc 2 594 14 is_stmt 0 view .LVU240
 723 004a 0023     		movs	r3, #0
 724              	.LVL75:
 725              		.loc 2 594 14 view .LVU241
 726 004c FB61     		str	r3, [r7, #28]
 727              	.LVL76:
 728              	.L17:
 729              		.loc 2 594 23 is_stmt 1 discriminator 3 view .LVU242
 730 004e FB69     		ldr	r3, [r7, #28]
 731 0050 0F2B     		cmp	r3, #15
 732 0052 20DC     		bgt	.L16
 595:GF128.cpp     ****         Cout = (T[i] >> 7) & 1;
 733              		.loc 2 595 9 discriminator 2 view .LVU243
 734              		.loc 2 595 20 is_stmt 0 discriminator 2 view .LVU244
 735 0054 07F10802 		add	r2, r7, #8
 736 0058 FB69     		ldr	r3, [r7, #28]
 737 005a 1344     		add	r3, r3, r2
 738 005c 1B78     		ldrb	r3, [r3]	@ zero_extendqisi2
 739              		.loc 2 595 14 discriminator 2 view .LVU245
 740 005e DB09     		lsrs	r3, r3, #7
 741 0060 87F82630 		strb	r3, [r7, #38]
 742              	.LVL77:
 596:GF128.cpp     ****         T[i] = ((T[i] << 1) + Cin) & 0xFF;
 743              		.loc 2 596 9 is_stmt 1 discriminator 2 view .LVU246
 744              		.loc 2 596 21 is_stmt 0 discriminator 2 view .LVU247
 745 0064 07F10802 		add	r2, r7, #8
 746 0068 FB69     		ldr	r3, [r7, #28]
 747              	.LVL78:
 748              		.loc 2 596 21 discriminator 2 view .LVU248
 749 006a 1344     		add	r3, r3, r2
 750 006c 1B78     		ldrb	r3, [r3]	@ zero_extendqisi2
 751              		.loc 2 596 23 discriminator 2 view .LVU249
 752 006e 5B00     		lsls	r3, r3, #1
 753 0070 DAB2     		uxtb	r2, r3
 754              		.loc 2 596 29 discriminator 2 view .LVU250
 755 0072 97F82730 		ldrb	r3, [r7, #39]
 756 0076 1344     		add	r3, r3, r2
 757 0078 D9B2     		uxtb	r1, r3
 758              		.loc 2 596 14 discriminator 2 view .LVU251
 759 007a 07F10802 		add	r2, r7, #8
 760 007e FB69     		ldr	r3, [r7, #28]
 761 0080 1344     		add	r3, r3, r2
 762 0082 0A46     		mov	r2, r1
 763 0084 1A70     		strb	r2, [r3]
 597:GF128.cpp     ****         Cin = Cout;
 764              		.loc 2 597 9 is_stmt 1 discriminator 2 view .LVU252
 765              		.loc 2 597 13 is_stmt 0 discriminator 2 view .LVU253
 766 0086 97F82630 		ldrb	r3, [r7, #38]
 767 008a 87F82730 		strb	r3, [r7, #39]
 768              	.LVL79:
 594:GF128.cpp     ****         Cout = (T[i] >> 7) & 1;
 769              		.loc 2 594 5 is_stmt 1 discriminator 2 view .LVU254
 770 008e FB69     		ldr	r3, [r7, #28]
 771 0090 0133     		adds	r3, r3, #1
 772 0092 FB61     		str	r3, [r7, #28]
 773              	.LVL80:
 594:GF128.cpp     ****         Cout = (T[i] >> 7) & 1;
 774              		.loc 2 594 5 is_stmt 0 discriminator 2 view .LVU255
 775 0094 DBE7     		b	.L17
 776              	.LVL81:
 777              	.L16:
 594:GF128.cpp     ****         Cout = (T[i] >> 7) & 1;
 778              		.loc 2 594 5 discriminator 2 view .LVU256
 779              	.LBE30:
 598:GF128.cpp     ****     }
 599:GF128.cpp     ****     //trigger_high();
 600:GF128.cpp     ****     // invert the bits if necessary
 601:GF128.cpp     ****     if (Cout == 1) { //!= 1 for testing, == 1 for normal
 780              		.loc 2 601 5 is_stmt 1 view .LVU257
 781 0096 97F82630 		ldrb	r3, [r7, #38]	@ zero_extendqisi2
 782              	.LVL82:
 783              		.loc 2 601 5 is_stmt 0 view .LVU258
 784 009a 012B     		cmp	r3, #1
 785 009c 05D1     		bne	.L18
 602:GF128.cpp     ****         T[0] ^= 0x87; //0x87 for 1, 2, 7
 786              		.loc 2 602 9 is_stmt 1 view .LVU259
 787              		.loc 2 602 14 is_stmt 0 view .LVU260
 788 009e 3B7A     		ldrb	r3, [r7, #8]	@ zero_extendqisi2
 789 00a0 83F07803 		eor	r3, r3, #120
 790 00a4 DB43     		mvns	r3, r3
 791 00a6 DBB2     		uxtb	r3, r3
 792 00a8 3B72     		strb	r3, [r7, #8]
 793              	.L18:
 603:GF128.cpp     ****         //__asm__ __volatile__ ("eor %0, %1" : "=r" (T[0]) : "r" (0x87) : "memory");
 604:GF128.cpp     ****     }
 605:GF128.cpp     ****     // else {
 606:GF128.cpp     ****     //     T[0] ^= 0x00; //XOR MASKING (SIDEOBJ)
 607:GF128.cpp     ****     //     //__asm__ __volatile__ ("eor %0, %1" : "=r" (T[0]) : "r" (0x00) : "memory");
 608:GF128.cpp     ****     // }
 609:GF128.cpp     ****     
 610:GF128.cpp     ****     // //Create the noInv and Inv variables
 611:GF128.cpp     ****     // uint8_t noInv = T[0];            // The value with no inversion
 612:GF128.cpp     ****     // uint8_t Inv = T[0] ^ 0x87;       // The value with inversion
 613:GF128.cpp     **** 
 614:GF128.cpp     ****     // // Choose which value to use based on Cout
 615:GF128.cpp     ****     // if (Cout == 1) {
 616:GF128.cpp     ****     //     T[0] = Inv;
 617:GF128.cpp     ****     // } else {
 618:GF128.cpp     ****     //     T[0] = noInv;
 619:GF128.cpp     ****     // }
 620:GF128.cpp     **** 
 621:GF128.cpp     ****     
 622:GF128.cpp     ****     //trigger_low();
 623:GF128.cpp     ****     // 17 byte sanity test check
 624:GF128.cpp     ****     //START AT 16.4K SAMPLE POINTS USING FULL OPERATION + 20K SAMPLING POINT WINDOW 5K ITERATIONS u
 625:GF128.cpp     ****     /*for (int i = 0; i < 10; i++) {
 626:GF128.cpp     ****         Cout = (T[i] >> 7) & 1;
 627:GF128.cpp     ****         T[i] = ((T[i] << 1) + Cin) & 0xFF;
 628:GF128.cpp     ****         Cin = Cout;
 629:GF128.cpp     ****     } */
 630:GF128.cpp     ****     //trigger_low();
 631:GF128.cpp     ****     
 632:GF128.cpp     ****     // Convert 16x uint8_t to 4x uint32_t 
 633:GF128.cpp     ****     for (int i = 0; i < 4; i++) {
 794              		.loc 2 633 5 is_stmt 1 view .LVU261
 795              	.LBB31:
 796              		.loc 2 633 14 is_stmt 0 view .LVU262
 797 00aa 0023     		movs	r3, #0
 798 00ac BB61     		str	r3, [r7, #24]
 799              	.LVL83:
 800              	.L20:
 801              		.loc 2 633 23 is_stmt 1 discriminator 3 view .LVU263
 802 00ae BB69     		ldr	r3, [r7, #24]
 803 00b0 032B     		cmp	r3, #3
 804 00b2 18DC     		bgt	.L21
 634:GF128.cpp     ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 805              		.loc 2 634 9 discriminator 2 view .LVU264
 806              		.loc 2 634 24 is_stmt 0 discriminator 2 view .LVU265
 807 00b4 BB69     		ldr	r3, [r7, #24]
 808              		.loc 2 634 25 discriminator 2 view .LVU266
 809 00b6 9B00     		lsls	r3, r3, #2
 810              		.loc 2 634 21 discriminator 2 view .LVU267
 811 00b8 7A68     		ldr	r2, [r7, #4]
 812 00ba 1344     		add	r3, r3, r2
 813              		.loc 2 634 33 discriminator 2 view .LVU268
 814 00bc BA69     		ldr	r2, [r7, #24]
 815 00be 9200     		lsls	r2, r2, #2
 816              		.loc 2 634 28 discriminator 2 view .LVU269
 817 00c0 07F10801 		add	r1, r7, #8
 818 00c4 0A44     		add	r2, r2, r1
 819 00c6 1268     		ldr	r2, [r2]	@ unaligned
 820              		.loc 2 634 20 discriminator 2 view .LVU270
 821 00c8 1A60     		str	r2, [r3]	@ unaligned
 635:GF128.cpp     ****         V[i] = htole32(V[i]);
 822              		.loc 2 635 9 is_stmt 1 discriminator 2 view .LVU271
 823              		.loc 2 635 16 is_stmt 0 discriminator 2 view .LVU272
 824 00ca BB69     		ldr	r3, [r7, #24]
 825 00cc 9B00     		lsls	r3, r3, #2
 826 00ce 7A68     		ldr	r2, [r7, #4]
 827 00d0 1A44     		add	r2, r2, r3
 828              		.loc 2 635 11 discriminator 2 view .LVU273
 829 00d2 BB69     		ldr	r3, [r7, #24]
 830              		.loc 2 635 12 discriminator 2 view .LVU274
 831 00d4 9B00     		lsls	r3, r3, #2
 832 00d6 7968     		ldr	r1, [r7, #4]
 833 00d8 0B44     		add	r3, r3, r1
 834              		.loc 2 635 16 discriminator 2 view .LVU275
 835 00da 1268     		ldr	r2, [r2]
 836              		.loc 2 635 14 discriminator 2 view .LVU276
 837 00dc 1A60     		str	r2, [r3]
 633:GF128.cpp     ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 838              		.loc 2 633 5 is_stmt 1 discriminator 2 view .LVU277
 839 00de BB69     		ldr	r3, [r7, #24]
 840 00e0 0133     		adds	r3, r3, #1
 841 00e2 BB61     		str	r3, [r7, #24]
 842              	.LVL84:
 633:GF128.cpp     ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 843              		.loc 2 633 5 is_stmt 0 discriminator 2 view .LVU278
 844 00e4 E3E7     		b	.L20
 845              	.L21:
 633:GF128.cpp     ****         std::memcpy(&V[i], &T[i * 4], sizeof(uint32_t));
 846              		.loc 2 633 5 discriminator 2 view .LVU279
 847              	.LBE31:
 636:GF128.cpp     ****     }
 637:GF128.cpp     **** 
 638:GF128.cpp     **** #endif
 639:GF128.cpp     **** }
 848              		.loc 2 639 1 view .LVU280
 849 00e6 00BF     		nop
 850 00e8 2C37     		adds	r7, r7, #44
 851              	.LCFI8:
 852              		.cfi_def_cfa_offset 4
 853              	.LVL85:
 854              		.loc 2 639 1 view .LVU281
 855 00ea BD46     		mov	sp, r7
 856              	.LCFI9:
 857              		.cfi_def_cfa_register 13
 858              		@ sp needed
 859 00ec 80BC     		pop	{r7}
 860              	.LCFI10:
 861              		.cfi_restore 7
 862              		.cfi_def_cfa_offset 0
 863              	.LVL86:
 864              		.loc 2 639 1 view .LVU282
 865 00ee 7047     		bx	lr
 866              		.cfi_endproc
 867              	.LFE17:
 868              		.cantunwind
 869              		.fnend
 871              		.text
 872              	.Letext0:
 873              		.file 3 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 874              		.file 4 "GF128.h"
 875              		.file 5 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
 876              		.file 6 "/usr/include/newlib/c++/10.3.1/cstdint"
 877              		.file 7 "/usr/include/newlib/c++/10.3.1/cstring"
 878              		.file 8 "/usr/include/newlib/c++/10.3.1/arm-none-eabi/thumb/v7e-m/nofp/bits/c++config.h"
 879              		.file 9 "/usr/include/newlib/string.h"
 880              		.file 10 "<built-in>"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 GF128.cpp
     /tmp/ccduN3YW.s:16     .text.led_ok:0000000000000000 $t
     /tmp/ccduN3YW.s:24     .text.led_ok:0000000000000000 led_ok
           .ARM.exidx.text.led_ok:0000000000000000 $d
     /tmp/ccduN3YW.s:42     .text.led_error:0000000000000000 $t
     /tmp/ccduN3YW.s:49     .text.led_error:0000000000000000 led_error
        .ARM.exidx.text.led_error:0000000000000000 $d
     /tmp/ccduN3YW.s:63     .text._ZN5GF1287mulInitEPmPKv:0000000000000000 $t
     /tmp/ccduN3YW.s:70     .text._ZN5GF1287mulInitEPmPKv:0000000000000000 _ZN5GF1287mulInitEPmPKv
.ARM.exidx.text._ZN5GF1287mulInitEPmPKv:0000000000000000 $d
     /tmp/ccduN3YW.s:152    .text._ZN5GF1283mulEPmPKm:0000000000000000 $t
     /tmp/ccduN3YW.s:159    .text._ZN5GF1283mulEPmPKm:0000000000000000 _ZN5GF1283mulEPmPKm
.ARM.exidx.text._ZN5GF1283mulEPmPKm:0000000000000000 $d
     /tmp/ccduN3YW.s:368    .text._ZN5GF1283dblEPm:0000000000000000 $t
     /tmp/ccduN3YW.s:375    .text._ZN5GF1283dblEPm:0000000000000000 _ZN5GF1283dblEPm
 .ARM.exidx.text._ZN5GF1283dblEPm:0000000000000000 $d
     /tmp/ccduN3YW.s:495    .text._ZN5GF1286dblEAXEPm:0000000000000000 $t
     /tmp/ccduN3YW.s:502    .text._ZN5GF1286dblEAXEPm:0000000000000000 _ZN5GF1286dblEAXEPm
.ARM.exidx.text._ZN5GF1286dblEAXEPm:0000000000000000 $d
     /tmp/ccduN3YW.s:630    .text._ZN5GF1286dblXTSEPm:0000000000000000 $t
     /tmp/ccduN3YW.s:637    .text._ZN5GF1286dblXTSEPm:0000000000000000 _ZN5GF1286dblXTSEPm
.ARM.exidx.text._ZN5GF1286dblXTSEPm:0000000000000000 $d

NO UNDEFINED SYMBOLS
