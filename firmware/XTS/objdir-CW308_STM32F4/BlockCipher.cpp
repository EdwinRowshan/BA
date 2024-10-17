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
  11              		.file	"BlockCipher.cpp"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text._ZN11BlockCipherC2Ev,"ax",%progbits
  16              		.align	1
  17              		.global	_ZN11BlockCipherC2Ev
  18              		.arch armv7e-m
  19              		.syntax unified
  20              		.thumb
  21              		.thumb_func
  22              		.fpu softvfp
  24              	_ZN11BlockCipherC2Ev:
  25              		.fnstart
  26              	.LVL0:
  27              	.LFB1:
  28              		.file 1 "BlockCipher.cpp"
   1:BlockCipher.cpp **** /*
   2:BlockCipher.cpp ****  * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
   3:BlockCipher.cpp ****  *
   4:BlockCipher.cpp ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:BlockCipher.cpp ****  * copy of this software and associated documentation files (the "Software"),
   6:BlockCipher.cpp ****  * to deal in the Software without restriction, including without limitation
   7:BlockCipher.cpp ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:BlockCipher.cpp ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:BlockCipher.cpp ****  * Software is furnished to do so, subject to the following conditions:
  10:BlockCipher.cpp ****  *
  11:BlockCipher.cpp ****  * The above copyright notice and this permission notice shall be included
  12:BlockCipher.cpp ****  * in all copies or substantial portions of the Software.
  13:BlockCipher.cpp ****  *
  14:BlockCipher.cpp ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:BlockCipher.cpp ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:BlockCipher.cpp ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:BlockCipher.cpp ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:BlockCipher.cpp ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:BlockCipher.cpp ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:BlockCipher.cpp ****  * DEALINGS IN THE SOFTWARE.
  21:BlockCipher.cpp ****  */
  22:BlockCipher.cpp **** 
  23:BlockCipher.cpp **** #include "BlockCipher.h"
  24:BlockCipher.cpp **** 
  25:BlockCipher.cpp **** /**
  26:BlockCipher.cpp ****  * \class BlockCipher BlockCipher.h <BlockCipher.h>
  27:BlockCipher.cpp ****  * \brief Abstract base class for block ciphers.
  28:BlockCipher.cpp ****  *
  29:BlockCipher.cpp ****  * Block ciphers always operate in electronic codebook (ECB) mode.
  30:BlockCipher.cpp ****  * Higher-level classes such as CFB128 and CTR128 wrap the block cipher to
  31:BlockCipher.cpp ****  * create more useful classes for encryption and decryption of bulk data.
  32:BlockCipher.cpp ****  *
  33:BlockCipher.cpp ****  * References: http://en.wikipedia.org/wiki/Block_cipher,
  34:BlockCipher.cpp ****  * http://en.wikipedia.org/wiki/Block_cipher_modes_of_operation#Electronic_codebook_.28ECB.29
  35:BlockCipher.cpp ****  */
  36:BlockCipher.cpp **** 
  37:BlockCipher.cpp **** /**
  38:BlockCipher.cpp ****  * \brief Constructs a block cipher.
  39:BlockCipher.cpp ****  */
  40:BlockCipher.cpp **** BlockCipher::BlockCipher()
  29              		.loc 1 40 1 view -0
  30              		.cfi_startproc
  31              		@ args = 0, pretend = 0, frame = 0
  32              		@ frame_needed = 0, uses_anonymous_args = 0
  33              		@ link register save eliminated.
  34              	.LBB5:
  35              		.loc 1 40 26 is_stmt 0 view .LVU1
  36 0000 014B     		ldr	r3, .L2
  37 0002 0360     		str	r3, [r0]
  38              	.LBE5:
  41:BlockCipher.cpp **** {
  42:BlockCipher.cpp **** }
  39              		.loc 1 42 1 view .LVU2
  40 0004 7047     		bx	lr
  41              	.L3:
  42 0006 00BF     		.align	2
  43              	.L2:
  44 0008 08000000 		.word	.LANCHOR0+8
  45              		.cfi_endproc
  46              	.LFE1:
  47              		.cantunwind
  48              		.fnend
  50              		.global	_ZN11BlockCipherC1Ev
  51              		.thumb_set _ZN11BlockCipherC1Ev,_ZN11BlockCipherC2Ev
  52              		.section	.text._ZN11BlockCipherD2Ev,"ax",%progbits
  53              		.align	1
  54              		.global	_ZN11BlockCipherD2Ev
  55              		.syntax unified
  56              		.thumb
  57              		.thumb_func
  58              		.fpu softvfp
  60              	_ZN11BlockCipherD2Ev:
  61              		.fnstart
  62              	.LVL1:
  63              	.LFB4:
  43:BlockCipher.cpp **** 
  44:BlockCipher.cpp **** /**
  45:BlockCipher.cpp ****  * \brief Destroys this block cipher object.
  46:BlockCipher.cpp ****  *
  47:BlockCipher.cpp ****  * Subclasses are responsible for clearing temporary key schedules
  48:BlockCipher.cpp ****  * and other buffers so as to avoid leaking sensitive information.
  49:BlockCipher.cpp ****  *
  50:BlockCipher.cpp ****  * \sa clear()
  51:BlockCipher.cpp ****  */
  52:BlockCipher.cpp **** BlockCipher::~BlockCipher()
  64              		.loc 1 52 1 is_stmt 1 view -0
  65              		.cfi_startproc
  66              		@ args = 0, pretend = 0, frame = 0
  67              		@ frame_needed = 0, uses_anonymous_args = 0
  68              		@ link register save eliminated.
  53:BlockCipher.cpp **** {
  54:BlockCipher.cpp **** }
  69              		.loc 1 54 1 is_stmt 0 view .LVU4
  70 0000 7047     		bx	lr
  71              		.cfi_endproc
  72              	.LFE4:
  73              		.cantunwind
  74              		.fnend
  76              		.global	_ZN11BlockCipherD1Ev
  77              		.thumb_set _ZN11BlockCipherD1Ev,_ZN11BlockCipherD2Ev
  78              		.section	.text._ZN11BlockCipherD0Ev,"ax",%progbits
  79              		.align	1
  80              		.global	_ZN11BlockCipherD0Ev
  81              		.syntax unified
  82              		.thumb
  83              		.thumb_func
  84              		.fpu softvfp
  86              	_ZN11BlockCipherD0Ev:
  87              		.fnstart
  88              	.LVL2:
  89              	.LFB6:
  52:BlockCipher.cpp **** {
  90              		.loc 1 52 1 is_stmt 1 view -0
  91              		.cfi_startproc
  92              		@ args = 0, pretend = 0, frame = 0
  93              		@ frame_needed = 0, uses_anonymous_args = 0
  52:BlockCipher.cpp **** {
  94              		.loc 1 52 1 is_stmt 0 view .LVU6
  95 0000 10B5     		push	{r4, lr}
  96              	.LCFI0:
  97              		.cfi_def_cfa_offset 8
  98              		.cfi_offset 4, -8
  99              		.cfi_offset 14, -4
 100              		.loc 1 54 1 view .LVU7
 101 0002 0421     		movs	r1, #4
  52:BlockCipher.cpp **** {
 102              		.loc 1 52 1 view .LVU8
 103 0004 0446     		mov	r4, r0
 104              	.LVL3:
 105              	.LBB6:
 106              	.LBI6:
  52:BlockCipher.cpp **** {
 107              		.loc 1 52 1 is_stmt 1 view .LVU9
  52:BlockCipher.cpp **** {
 108              		.loc 1 52 1 is_stmt 0 view .LVU10
 109              	.LBE6:
 110              		.loc 1 54 1 view .LVU11
 111 0006 FFF7FEFF 		bl	_ZdlPvj
 112              	.LVL4:
 113              		.loc 1 54 1 view .LVU12
 114 000a 2046     		mov	r0, r4
 115 000c 10BD     		pop	{r4, pc}
 116              		.loc 1 54 1 view .LVU13
 117              		.cfi_endproc
 118              	.LFE6:
 119              		.cantunwind
 120              		.fnend
 122              		.global	_ZTS11BlockCipher
 123              		.global	_ZTI11BlockCipher
 124              		.global	_ZTV11BlockCipher
 125              		.section	.rodata
 126              		.align	2
 127              		.set	.LANCHOR0,. + 0
 130              	_ZTV11BlockCipher:
 131 0000 00000000 		.word	0
 132 0004 00000000 		.word	_ZTI11BlockCipher
 133 0008 00000000 		.word	0
 134 000c 00000000 		.word	0
 135 0010 00000000 		.word	__cxa_pure_virtual
 136 0014 00000000 		.word	__cxa_pure_virtual
 137 0018 00000000 		.word	__cxa_pure_virtual
 138 001c 00000000 		.word	__cxa_pure_virtual
 139 0020 00000000 		.word	__cxa_pure_virtual
 140 0024 00000000 		.word	__cxa_pure_virtual
 143              	_ZTS11BlockCipher:
 144 0028 3131426C 		.ascii	"11BlockCipher\000"
 144      6F636B43 
 144      69706865 
 144      7200
 145 0036 0000     		.space	2
 148              	_ZTI11BlockCipher:
 149 0038 08000000 		.word	_ZTVN10__cxxabiv117__class_type_infoE+8
 150 003c 00000000 		.word	_ZTS11BlockCipher
 151              		.text
 152              	.Letext0:
 153              		.file 2 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 154              		.file 3 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
 155              		.file 4 "BlockCipher.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 BlockCipher.cpp
     /tmp/ccsoeNGk.s:16     .text._ZN11BlockCipherC2Ev:0000000000000000 $t
     /tmp/ccsoeNGk.s:24     .text._ZN11BlockCipherC2Ev:0000000000000000 _ZN11BlockCipherC2Ev
     /tmp/ccsoeNGk.s:44     .text._ZN11BlockCipherC2Ev:0000000000000008 $d
.ARM.exidx.text._ZN11BlockCipherC2Ev:0000000000000000 $d
     /tmp/ccsoeNGk.s:24     .text._ZN11BlockCipherC2Ev:0000000000000000 _ZN11BlockCipherC1Ev
     /tmp/ccsoeNGk.s:53     .text._ZN11BlockCipherD2Ev:0000000000000000 $t
     /tmp/ccsoeNGk.s:60     .text._ZN11BlockCipherD2Ev:0000000000000000 _ZN11BlockCipherD2Ev
.ARM.exidx.text._ZN11BlockCipherD2Ev:0000000000000000 $d
     /tmp/ccsoeNGk.s:60     .text._ZN11BlockCipherD2Ev:0000000000000000 _ZN11BlockCipherD1Ev
     /tmp/ccsoeNGk.s:79     .text._ZN11BlockCipherD0Ev:0000000000000000 $t
     /tmp/ccsoeNGk.s:86     .text._ZN11BlockCipherD0Ev:0000000000000000 _ZN11BlockCipherD0Ev
.ARM.exidx.text._ZN11BlockCipherD0Ev:0000000000000000 $d
     /tmp/ccsoeNGk.s:143    .rodata:0000000000000028 _ZTS11BlockCipher
     /tmp/ccsoeNGk.s:148    .rodata:0000000000000038 _ZTI11BlockCipher
     /tmp/ccsoeNGk.s:130    .rodata:0000000000000000 _ZTV11BlockCipher
     /tmp/ccsoeNGk.s:126    .rodata:0000000000000000 $d

UNDEFINED SYMBOLS
_ZdlPvj
__cxa_pure_virtual
_ZTVN10__cxxabiv117__class_type_infoE
