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
  11              		.file	"Crypto.cpp"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text._Z5cleanPvj,"ax",%progbits
  16              		.align	1
  17              		.global	_Z5cleanPvj
  18              		.arch armv7e-m
  19              		.syntax unified
  20              		.thumb
  21              		.thumb_func
  22              		.fpu softvfp
  24              	_Z5cleanPvj:
  25              		.fnstart
  26              	.LVL0:
  27              	.LFB1:
  28              		.file 1 "Crypto.cpp"
   1:Crypto.cpp    **** /*
   2:Crypto.cpp    ****  * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
   3:Crypto.cpp    ****  *
   4:Crypto.cpp    ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:Crypto.cpp    ****  * copy of this software and associated documentation files (the "Software"),
   6:Crypto.cpp    ****  * to deal in the Software without restriction, including without limitation
   7:Crypto.cpp    ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:Crypto.cpp    ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:Crypto.cpp    ****  * Software is furnished to do so, subject to the following conditions:
  10:Crypto.cpp    ****  *
  11:Crypto.cpp    ****  * The above copyright notice and this permission notice shall be included
  12:Crypto.cpp    ****  * in all copies or substantial portions of the Software.
  13:Crypto.cpp    ****  *
  14:Crypto.cpp    ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:Crypto.cpp    ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:Crypto.cpp    ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:Crypto.cpp    ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:Crypto.cpp    ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:Crypto.cpp    ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:Crypto.cpp    ****  * DEALINGS IN THE SOFTWARE.
  21:Crypto.cpp    ****  */
  22:Crypto.cpp    **** 
  23:Crypto.cpp    **** #include "Crypto.h"
  24:Crypto.cpp    **** 
  25:Crypto.cpp    **** /**
  26:Crypto.cpp    ****  * \brief Cleans a block of bytes.
  27:Crypto.cpp    ****  *
  28:Crypto.cpp    ****  * \param dest The destination block to be cleaned.
  29:Crypto.cpp    ****  * \param size The size of the destination to be cleaned in bytes.
  30:Crypto.cpp    ****  *
  31:Crypto.cpp    ****  * Unlike memset(), this function attempts to prevent the compiler
  32:Crypto.cpp    ****  * from optimizing away the clear on a memory buffer.
  33:Crypto.cpp    ****  */
  34:Crypto.cpp    **** void clean(void *dest, size_t size)
  35:Crypto.cpp    **** {
  29              		.loc 1 35 1 view -0
  30              		.cfi_startproc
  31              		@ args = 0, pretend = 0, frame = 0
  32              		@ frame_needed = 0, uses_anonymous_args = 0
  33              		@ link register save eliminated.
  36:Crypto.cpp    ****     // Force the use of volatile so that we actually clear the memory.
  37:Crypto.cpp    ****     // Otherwise the compiler might optimise the entire contents of this
  38:Crypto.cpp    ****     // function away, which will not be secure.
  39:Crypto.cpp    ****     volatile uint8_t *d = (volatile uint8_t *)dest;
  34              		.loc 1 39 5 view .LVU1
  35              		.loc 1 39 5 is_stmt 0 view .LVU2
  36 0000 0144     		add	r1, r1, r0
  37              	.LVL1:
  40:Crypto.cpp    ****     while (size > 0) {
  41:Crypto.cpp    ****         *d++ = 0;
  38              		.loc 1 41 14 view .LVU3
  39 0002 0023     		movs	r3, #0
  40              	.LVL2:
  41              	.L3:
  40:Crypto.cpp    ****     while (size > 0) {
  42              		.loc 1 40 5 is_stmt 1 view .LVU4
  40:Crypto.cpp    ****     while (size > 0) {
  43              		.loc 1 40 17 view .LVU5
  44 0004 8842     		cmp	r0, r1
  45 0006 02D0     		beq	.L1
  46              		.loc 1 41 9 view .LVU6
  47              	.LVL3:
  48              		.loc 1 41 14 is_stmt 0 view .LVU7
  49 0008 00F8013B 		strb	r3, [r0], #1
  50              	.LVL4:
  42:Crypto.cpp    ****         --size;
  51              		.loc 1 42 9 is_stmt 1 view .LVU8
  40:Crypto.cpp    ****     while (size > 0) {
  52              		.loc 1 40 5 is_stmt 0 view .LVU9
  53 000c FAE7     		b	.L3
  54              	.L1:
  43:Crypto.cpp    ****     }
  44:Crypto.cpp    **** }
  55              		.loc 1 44 1 view .LVU10
  56 000e 7047     		bx	lr
  57              		.cfi_endproc
  58              	.LFE1:
  59              		.cantunwind
  60              		.fnend
  62              		.section	.text._Z14secure_comparePKvS0_j,"ax",%progbits
  63              		.align	1
  64              		.global	_Z14secure_comparePKvS0_j
  65              		.syntax unified
  66              		.thumb
  67              		.thumb_func
  68              		.fpu softvfp
  70              	_Z14secure_comparePKvS0_j:
  71              		.fnstart
  72              	.LVL5:
  73              	.LFB2:
  45:Crypto.cpp    **** 
  46:Crypto.cpp    **** /**
  47:Crypto.cpp    ****  * \fn void clean(T &var)
  48:Crypto.cpp    ****  * \brief Template function that cleans a variable.
  49:Crypto.cpp    ****  *
  50:Crypto.cpp    ****  * \param var A reference to the variable to clean.
  51:Crypto.cpp    ****  *
  52:Crypto.cpp    ****  * The variable will be cleared to all-zeroes in a secure manner.
  53:Crypto.cpp    ****  * Unlike memset(), this function attempts to prevent the compiler
  54:Crypto.cpp    ****  * from optimizing away the variable clear.
  55:Crypto.cpp    ****  */
  56:Crypto.cpp    **** 
  57:Crypto.cpp    **** /**
  58:Crypto.cpp    ****  * \brief Compares two memory blocks for equality.
  59:Crypto.cpp    ****  *
  60:Crypto.cpp    ****  * \param data1 Points to the first memory block.
  61:Crypto.cpp    ****  * \param data2 Points to the second memory block.
  62:Crypto.cpp    ****  * \param len The size of the memory blocks in bytes.
  63:Crypto.cpp    ****  *
  64:Crypto.cpp    ****  * Unlike memcmp(), this function attempts to compare the two memory blocks
  65:Crypto.cpp    ****  * in a way that will not reveal the contents in the instruction timing.
  66:Crypto.cpp    ****  * In particular, this function will not stop early if a byte is different.
  67:Crypto.cpp    ****  * It will instead continue onto the end of the array.
  68:Crypto.cpp    ****  */
  69:Crypto.cpp    **** bool secure_compare(const void *data1, const void *data2, size_t len)
  70:Crypto.cpp    **** {
  74              		.loc 1 70 1 is_stmt 1 view -0
  75              		.cfi_startproc
  76              		@ args = 0, pretend = 0, frame = 0
  77              		@ frame_needed = 0, uses_anonymous_args = 0
  71:Crypto.cpp    ****     uint8_t result = 0;
  78              		.loc 1 71 5 view .LVU12
  72:Crypto.cpp    ****     const uint8_t *d1 = (const uint8_t *)data1;
  79              		.loc 1 72 5 view .LVU13
  73:Crypto.cpp    ****     const uint8_t *d2 = (const uint8_t *)data2;
  80              		.loc 1 73 5 view .LVU14
  70:Crypto.cpp    ****     uint8_t result = 0;
  81              		.loc 1 70 1 is_stmt 0 view .LVU15
  82 0000 30B5     		push	{r4, r5, lr}
  83              	.LCFI0:
  84              		.cfi_def_cfa_offset 12
  85              		.cfi_offset 4, -12
  86              		.cfi_offset 5, -8
  87              		.cfi_offset 14, -4
  88 0002 0244     		add	r2, r2, r0
  89              	.LVL6:
  71:Crypto.cpp    ****     const uint8_t *d1 = (const uint8_t *)data1;
  90              		.loc 1 71 13 view .LVU16
  91 0004 0023     		movs	r3, #0
  92              	.LVL7:
  93              	.L7:
  74:Crypto.cpp    ****     while (len > 0) {
  94              		.loc 1 74 5 is_stmt 1 view .LVU17
  95              		.loc 1 74 16 view .LVU18
  96 0006 9042     		cmp	r0, r2
  97 0008 06D0     		beq	.L6
  75:Crypto.cpp    ****         result |= (*d1++ ^ *d2++);
  98              		.loc 1 75 9 view .LVU19
  99              	.LVL8:
 100              		.loc 1 75 26 is_stmt 0 view .LVU20
 101 000a 10F8014B 		ldrb	r4, [r0], #1	@ zero_extendqisi2
 102              	.LVL9:
 103              		.loc 1 75 26 view .LVU21
 104 000e 11F8015B 		ldrb	r5, [r1], #1	@ zero_extendqisi2
 105              	.LVL10:
 106              		.loc 1 75 26 view .LVU22
 107 0012 6C40     		eors	r4, r4, r5
 108              		.loc 1 75 16 view .LVU23
 109 0014 2343     		orrs	r3, r3, r4
 110              	.LVL11:
  76:Crypto.cpp    ****         --len;
 111              		.loc 1 76 9 is_stmt 1 view .LVU24
  74:Crypto.cpp    ****     while (len > 0) {
 112              		.loc 1 74 5 is_stmt 0 view .LVU25
 113 0016 F6E7     		b	.L7
 114              	.L6:
  77:Crypto.cpp    ****     }
  78:Crypto.cpp    ****     return (bool)((((uint16_t)0x0100) - result) >> 8);
 115              		.loc 1 78 5 is_stmt 1 view .LVU26
 116              		.loc 1 78 39 is_stmt 0 view .LVU27
 117 0018 C3F58070 		rsb	r0, r3, #256
 118              	.LVL12:
  79:Crypto.cpp    **** }
 119              		.loc 1 79 1 view .LVU28
 120 001c C0F30020 		ubfx	r0, r0, #8, #1
 121 0020 30BD     		pop	{r4, r5, pc}
 122              		.cfi_endproc
 123              	.LFE2:
 124              		.cantunwind
 125              		.fnend
 127              		.section	.text._Z11crypto_crc8hPKvj,"ax",%progbits
 128              		.align	1
 129              		.global	_Z11crypto_crc8hPKvj
 130              		.syntax unified
 131              		.thumb
 132              		.thumb_func
 133              		.fpu softvfp
 135              	_Z11crypto_crc8hPKvj:
 136              		.fnstart
 137              	.LVL13:
 138              	.LFB3:
  80:Crypto.cpp    **** 
  81:Crypto.cpp    **** /**
  82:Crypto.cpp    ****  * \brief Calculates the CRC-8 value over an array in memory.
  83:Crypto.cpp    ****  *
  84:Crypto.cpp    ****  * \param tag Starting tag to distinguish this calculation.
  85:Crypto.cpp    ****  * \param data The data to checksum.
  86:Crypto.cpp    ****  * \param size The number of bytes to checksum.
  87:Crypto.cpp    ****  * \return The CRC-8 value over the data.
  88:Crypto.cpp    ****  *
  89:Crypto.cpp    ****  * This function does not provide any real security.  It is a simple
  90:Crypto.cpp    ****  * check that seed values have been initialized within EEPROM or Flash.
  91:Crypto.cpp    ****  * If the CRC-8 check fails, then it is assumed that the EEPROM/Flash
  92:Crypto.cpp    ****  * contents are invalid and should be re-initialized.
  93:Crypto.cpp    ****  *
  94:Crypto.cpp    ****  * Reference: http://www.sunshine2k.de/articles/coding/crc/understanding_crc.html#ch4
  95:Crypto.cpp    ****  */
  96:Crypto.cpp    **** uint8_t crypto_crc8(uint8_t tag, const void *data, unsigned size)
  97:Crypto.cpp    **** {
 139              		.loc 1 97 1 is_stmt 1 view -0
 140              		.cfi_startproc
 141              		@ args = 0, pretend = 0, frame = 0
 142              		@ frame_needed = 0, uses_anonymous_args = 0
  98:Crypto.cpp    ****     const uint8_t *d = (const uint8_t *)data;
 143              		.loc 1 98 5 view .LVU30
  99:Crypto.cpp    ****     uint8_t crc = 0xFF ^ tag;
 144              		.loc 1 99 5 view .LVU31
  97:Crypto.cpp    ****     const uint8_t *d = (const uint8_t *)data;
 145              		.loc 1 97 1 is_stmt 0 view .LVU32
 146 0000 10B5     		push	{r4, lr}
 147              	.LCFI1:
 148              		.cfi_def_cfa_offset 8
 149              		.cfi_offset 4, -8
 150              		.cfi_offset 14, -4
 151              		.loc 1 99 13 view .LVU33
 152 0002 C043     		mvns	r0, r0
 153              	.LVL14:
 154              		.loc 1 99 13 view .LVU34
 155 0004 C0B2     		uxtb	r0, r0
 156              	.LVL15:
 157              		.loc 1 99 13 view .LVU35
 158 0006 0A44     		add	r2, r2, r1
 159              	.LVL16:
 160              	.L11:
 100:Crypto.cpp    ****     uint8_t bit;
 161              		.loc 1 100 5 is_stmt 1 view .LVU36
 101:Crypto.cpp    ****     while (size > 0) {
 162              		.loc 1 101 5 view .LVU37
 163              		.loc 1 101 17 view .LVU38
 164 0008 9142     		cmp	r1, r2
 165 000a 0FD0     		beq	.L10
 166              	.LBB2:
 102:Crypto.cpp    ****         crc ^= *d++;
 167              		.loc 1 102 9 view .LVU39
 168              	.LVL17:
 169              		.loc 1 102 13 is_stmt 0 view .LVU40
 170 000c 11F8013B 		ldrb	r3, [r1], #1	@ zero_extendqisi2
 171              	.LVL18:
 172              		.loc 1 102 13 view .LVU41
 173 0010 5840     		eors	r0, r0, r3
 174              	.LVL19:
 103:Crypto.cpp    ****         for (bit = 0; bit < 8; ++bit) {
 175              		.loc 1 103 9 is_stmt 1 view .LVU42
 176              	.LBB3:
 177              		.loc 1 103 27 view .LVU43
 178              	.LBE3:
 102:Crypto.cpp    ****         crc ^= *d++;
 179              		.loc 1 102 13 is_stmt 0 view .LVU44
 180 0012 0823     		movs	r3, #8
 181              	.LVL20:
 182              	.L12:
 183              	.LBB7:
 184              	.LBB4:
 104:Crypto.cpp    ****             // if (crc & 0x80)
 105:Crypto.cpp    ****             //     crc = (crc << 1) ^ 0x1D;
 106:Crypto.cpp    ****             // else
 107:Crypto.cpp    ****             //     crc = (crc << 1);
 108:Crypto.cpp    ****             uint8_t generator = (uint8_t)((((int8_t)crc) >> 7) & 0x1D);
 185              		.loc 1 108 13 is_stmt 1 discriminator 2 view .LVU45
 109:Crypto.cpp    ****             crc = (crc << 1) ^ generator;
 186              		.loc 1 109 13 discriminator 2 view .LVU46
 108:Crypto.cpp    ****             crc = (crc << 1) ^ generator;
 187              		.loc 1 108 58 is_stmt 0 discriminator 2 view .LVU47
 188 0014 40F3C014 		sbfx	r4, r0, #7, #1
 108:Crypto.cpp    ****             crc = (crc << 1) ^ generator;
 189              		.loc 1 108 21 discriminator 2 view .LVU48
 190 0018 04F01D04 		and	r4, r4, #29
 191              	.LBE4:
 103:Crypto.cpp    ****             // if (crc & 0x80)
 192              		.loc 1 103 27 discriminator 2 view .LVU49
 193 001c 013B     		subs	r3, r3, #1
 194              	.LVL21:
 195              	.LBB5:
 196              		.loc 1 109 30 discriminator 2 view .LVU50
 197 001e 84EA4000 		eor	r0, r4, r0, lsl #1
 198              	.LVL22:
 199              		.loc 1 109 30 discriminator 2 view .LVU51
 200              	.LBE5:
 103:Crypto.cpp    ****             // if (crc & 0x80)
 201              		.loc 1 103 27 discriminator 2 view .LVU52
 202 0022 13F0FF03 		ands	r3, r3, #255
 203              	.LBB6:
 204              		.loc 1 109 17 discriminator 2 view .LVU53
 205 0026 C0B2     		uxtb	r0, r0
 206              	.LVL23:
 207              		.loc 1 109 17 discriminator 2 view .LVU54
 208              	.LBE6:
 103:Crypto.cpp    ****             // if (crc & 0x80)
 209              		.loc 1 103 9 is_stmt 1 discriminator 2 view .LVU55
 103:Crypto.cpp    ****             // if (crc & 0x80)
 210              		.loc 1 103 27 discriminator 2 view .LVU56
 211 0028 F4D1     		bne	.L12
 212 002a EDE7     		b	.L11
 213              	.L10:
 103:Crypto.cpp    ****             // if (crc & 0x80)
 214              		.loc 1 103 27 is_stmt 0 discriminator 2 view .LVU57
 215              	.LBE7:
 216              	.LBE2:
 110:Crypto.cpp    ****         }
 111:Crypto.cpp    ****         --size;
 112:Crypto.cpp    ****     }
 113:Crypto.cpp    ****     return crc;
 217              		.loc 1 113 5 is_stmt 1 view .LVU58
 114:Crypto.cpp    **** }
 218              		.loc 1 114 1 is_stmt 0 view .LVU59
 219 002c 10BD     		pop	{r4, pc}
 220              		.cfi_endproc
 221              	.LFE3:
 222              		.cantunwind
 223              		.fnend
 225              		.text
 226              	.Letext0:
 227              		.file 2 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 228              		.file 3 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 Crypto.cpp
     /tmp/ccvoXWAC.s:16     .text._Z5cleanPvj:0000000000000000 $t
     /tmp/ccvoXWAC.s:24     .text._Z5cleanPvj:0000000000000000 _Z5cleanPvj
      .ARM.exidx.text._Z5cleanPvj:0000000000000000 $d
     /tmp/ccvoXWAC.s:63     .text._Z14secure_comparePKvS0_j:0000000000000000 $t
     /tmp/ccvoXWAC.s:70     .text._Z14secure_comparePKvS0_j:0000000000000000 _Z14secure_comparePKvS0_j
.ARM.exidx.text._Z14secure_comparePKvS0_j:0000000000000000 $d
     /tmp/ccvoXWAC.s:128    .text._Z11crypto_crc8hPKvj:0000000000000000 $t
     /tmp/ccvoXWAC.s:135    .text._Z11crypto_crc8hPKvj:0000000000000000 _Z11crypto_crc8hPKvj
.ARM.exidx.text._Z11crypto_crc8hPKvj:0000000000000000 $d

NO UNDEFINED SYMBOLS
