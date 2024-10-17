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
  11              		.file	"AES128.cpp"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text._ZNK6AES1287keySizeEv,"ax",%progbits
  16              		.align	1
  17              		.global	_ZNK6AES1287keySizeEv
  18              		.arch armv7e-m
  19              		.syntax unified
  20              		.thumb
  21              		.thumb_func
  22              		.fpu softvfp
  24              	_ZNK6AES1287keySizeEv:
  25              		.fnstart
  26              	.LVL0:
  27              	.LFB8:
  28              		.file 1 "AES128.cpp"
   1:AES128.cpp    **** /*
   2:AES128.cpp    ****  * Copyright (C) 2015,2018 Southern Storm Software, Pty Ltd.
   3:AES128.cpp    ****  *
   4:AES128.cpp    ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:AES128.cpp    ****  * copy of this software and associated documentation files (the "Software"),
   6:AES128.cpp    ****  * to deal in the Software without restriction, including without limitation
   7:AES128.cpp    ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:AES128.cpp    ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:AES128.cpp    ****  * Software is furnished to do so, subject to the following conditions:
  10:AES128.cpp    ****  *
  11:AES128.cpp    ****  * The above copyright notice and this permission notice shall be included
  12:AES128.cpp    ****  * in all copies or substantial portions of the Software.
  13:AES128.cpp    ****  *
  14:AES128.cpp    ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:AES128.cpp    ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:AES128.cpp    ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:AES128.cpp    ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:AES128.cpp    ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:AES128.cpp    ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:AES128.cpp    ****  * DEALINGS IN THE SOFTWARE.
  21:AES128.cpp    ****  */
  22:AES128.cpp    **** 
  23:AES128.cpp    **** #include "AES.h"
  24:AES128.cpp    **** #include "Crypto.h"
  25:AES128.cpp    **** #include <string.h>
  26:AES128.cpp    **** 
  27:AES128.cpp    **** #if defined(CRYPTO_AES_DEFAULT) || defined(CRYPTO_DOC)
  28:AES128.cpp    **** 
  29:AES128.cpp    **** /**
  30:AES128.cpp    ****  * \class AES128 AES.h <AES.h>
  31:AES128.cpp    ****  * \brief AES block cipher with 128-bit keys.
  32:AES128.cpp    ****  *
  33:AES128.cpp    ****  * \sa AES192, AES256, AESTiny128, AESSmall128
  34:AES128.cpp    ****  */
  35:AES128.cpp    **** 
  36:AES128.cpp    **** /**
  37:AES128.cpp    ****  * \brief Constructs an AES 128-bit block cipher with no initial key.
  38:AES128.cpp    ****  *
  39:AES128.cpp    ****  * This constructor must be followed by a call to setKey() before the
  40:AES128.cpp    ****  * block cipher can be used for encryption or decryption.
  41:AES128.cpp    ****  */
  42:AES128.cpp    **** AES128::AES128()
  43:AES128.cpp    **** {
  44:AES128.cpp    ****     rounds = 10;
  45:AES128.cpp    ****     schedule = sched;
  46:AES128.cpp    **** }
  47:AES128.cpp    **** 
  48:AES128.cpp    **** AES128::~AES128()
  49:AES128.cpp    **** {
  50:AES128.cpp    ****     clean(sched);
  51:AES128.cpp    **** }
  52:AES128.cpp    **** 
  53:AES128.cpp    **** /**
  54:AES128.cpp    ****  * \brief Size of a 128-bit AES key in bytes.
  55:AES128.cpp    ****  * \return Always returns 16.
  56:AES128.cpp    ****  */
  57:AES128.cpp    **** size_t AES128::keySize() const
  58:AES128.cpp    **** {
  29              		.loc 1 58 1 view -0
  30              		.cfi_startproc
  31              		@ args = 0, pretend = 0, frame = 0
  32              		@ frame_needed = 0, uses_anonymous_args = 0
  33              		@ link register save eliminated.
  59:AES128.cpp    ****     return 16;
  34              		.loc 1 59 5 view .LVU1
  60:AES128.cpp    **** }
  35              		.loc 1 60 1 is_stmt 0 view .LVU2
  36 0000 1020     		movs	r0, #16
  37              	.LVL1:
  38              		.loc 1 60 1 view .LVU3
  39 0002 7047     		bx	lr
  40              		.cfi_endproc
  41              	.LFE8:
  42              		.cantunwind
  43              		.fnend
  45              		.global	_ZNK10AESTiny1287keySizeEv
  46              		.thumb_set _ZNK10AESTiny1287keySizeEv,_ZNK6AES1287keySizeEv
  47              		.global	_ZNK10AESTiny1289blockSizeEv
  48              		.thumb_set _ZNK10AESTiny1289blockSizeEv,_ZNK6AES1287keySizeEv
  49              		.section	.text._ZN10AESTiny12812decryptBlockEPhPKh,"ax",%progbits
  50              		.align	1
  51              		.global	_ZN10AESTiny12812decryptBlockEPhPKh
  52              		.syntax unified
  53              		.thumb
  54              		.thumb_func
  55              		.fpu softvfp
  57              	_ZN10AESTiny12812decryptBlockEPhPKh:
  58              		.fnstart
  59              	.LVL2:
  60              	.LFB21:
  61:AES128.cpp    **** 
  62:AES128.cpp    **** bool AES128::setKey(const uint8_t *key, size_t len)
  63:AES128.cpp    **** {
  64:AES128.cpp    ****     if (len != 16)
  65:AES128.cpp    ****         return false;
  66:AES128.cpp    **** 
  67:AES128.cpp    ****     // Copy the key itself into the first 16 bytes of the schedule.
  68:AES128.cpp    ****     uint8_t *schedule = sched;
  69:AES128.cpp    ****     memcpy(schedule, key, 16);
  70:AES128.cpp    **** 
  71:AES128.cpp    ****     // Expand the key schedule until we have 176 bytes of expanded key.
  72:AES128.cpp    ****     uint8_t iteration = 1;
  73:AES128.cpp    ****     uint8_t n = 16;
  74:AES128.cpp    ****     uint8_t w = 4;
  75:AES128.cpp    ****     while (n < 176) {
  76:AES128.cpp    ****         if (w == 4) {
  77:AES128.cpp    ****             // Every 16 bytes (4 words) we need to apply the key schedule core.
  78:AES128.cpp    ****             keyScheduleCore(schedule + 16, schedule + 12, iteration);
  79:AES128.cpp    ****             schedule[16] ^= schedule[0];
  80:AES128.cpp    ****             schedule[17] ^= schedule[1];
  81:AES128.cpp    ****             schedule[18] ^= schedule[2];
  82:AES128.cpp    ****             schedule[19] ^= schedule[3];
  83:AES128.cpp    ****             ++iteration;
  84:AES128.cpp    ****             w = 0;
  85:AES128.cpp    ****         } else {
  86:AES128.cpp    ****             // Otherwise just XOR the word with the one 16 bytes previous.
  87:AES128.cpp    ****             schedule[16] = schedule[12] ^ schedule[0];
  88:AES128.cpp    ****             schedule[17] = schedule[13] ^ schedule[1];
  89:AES128.cpp    ****             schedule[18] = schedule[14] ^ schedule[2];
  90:AES128.cpp    ****             schedule[19] = schedule[15] ^ schedule[3];
  91:AES128.cpp    ****         }
  92:AES128.cpp    **** 
  93:AES128.cpp    ****         // Advance to the next word in the schedule.
  94:AES128.cpp    ****         schedule += 4;
  95:AES128.cpp    ****         n += 4;
  96:AES128.cpp    ****         ++w;
  97:AES128.cpp    ****     }
  98:AES128.cpp    **** 
  99:AES128.cpp    ****     return true;
 100:AES128.cpp    **** }
 101:AES128.cpp    **** 
 102:AES128.cpp    **** /**
 103:AES128.cpp    ****  * \class AESTiny128 AES.h <AES.h>
 104:AES128.cpp    ****  * \brief AES block cipher with 128-bit keys and tiny memory usage.
 105:AES128.cpp    ****  *
 106:AES128.cpp    ****  * This class differs from the AES128 class in the following ways:
 107:AES128.cpp    ****  *
 108:AES128.cpp    ****  * \li RAM requirements are vastly reduced.  The key is stored directly
 109:AES128.cpp    ****  * and then expanded to the full key schedule round by round.  The setKey()
 110:AES128.cpp    ****  * method is very fast because of this.
 111:AES128.cpp    ****  * \li Performance of encryptBlock() is slower than for AES128 due to
 112:AES128.cpp    ****  * expanding the key on the fly rather than ahead of time.
 113:AES128.cpp    ****  * \li The decryptBlock() function is not supported, which means that CBC
 114:AES128.cpp    ****  * mode cannot be used but the CTR, CFB, OFB, EAX, and GCM modes can be used.
 115:AES128.cpp    ****  *
 116:AES128.cpp    ****  * This class is useful when RAM is at a premium, CBC mode is not required,
 117:AES128.cpp    ****  * and reduced encryption performance is not a hindrance to the application.
 118:AES128.cpp    ****  *
 119:AES128.cpp    ****  * The companion AESSmall128 class supports decryptBlock() at the cost of
 120:AES128.cpp    ****  * some additional memory and slower setKey() times.
 121:AES128.cpp    ****  *
 122:AES128.cpp    ****  * \sa AESSmall128, AES128
 123:AES128.cpp    ****  */
 124:AES128.cpp    **** 
 125:AES128.cpp    **** /** @cond */
 126:AES128.cpp    **** 
 127:AES128.cpp    **** // Helper macros.
 128:AES128.cpp    **** #define KCORE(n) \
 129:AES128.cpp    ****     do { \
 130:AES128.cpp    ****         AESCommon::keyScheduleCore(temp, schedule + 12, (n)); \
 131:AES128.cpp    ****         schedule[0] ^= temp[0]; \
 132:AES128.cpp    ****         schedule[1] ^= temp[1]; \
 133:AES128.cpp    ****         schedule[2] ^= temp[2]; \
 134:AES128.cpp    ****         schedule[3] ^= temp[3]; \
 135:AES128.cpp    ****     } while (0)
 136:AES128.cpp    **** #define KXOR(a, b) \
 137:AES128.cpp    ****     do { \
 138:AES128.cpp    ****         schedule[(a) * 4] ^= schedule[(b) * 4]; \
 139:AES128.cpp    ****         schedule[(a) * 4 + 1] ^= schedule[(b) * 4 + 1]; \
 140:AES128.cpp    ****         schedule[(a) * 4 + 2] ^= schedule[(b) * 4 + 2]; \
 141:AES128.cpp    ****         schedule[(a) * 4 + 3] ^= schedule[(b) * 4 + 3]; \
 142:AES128.cpp    ****     } while (0)
 143:AES128.cpp    **** 
 144:AES128.cpp    **** /** @endcond */
 145:AES128.cpp    **** 
 146:AES128.cpp    **** /**
 147:AES128.cpp    ****  * \brief Constructs an AES 128-bit block cipher with no initial key.
 148:AES128.cpp    ****  *
 149:AES128.cpp    ****  * This constructor must be followed by a call to setKey() before the
 150:AES128.cpp    ****  * block cipher can be used for encryption or decryption.
 151:AES128.cpp    ****  */
 152:AES128.cpp    **** AESTiny128::AESTiny128()
 153:AES128.cpp    **** {
 154:AES128.cpp    **** }
 155:AES128.cpp    **** 
 156:AES128.cpp    **** AESTiny128::~AESTiny128()
 157:AES128.cpp    **** {
 158:AES128.cpp    ****     clean(schedule);
 159:AES128.cpp    **** }
 160:AES128.cpp    **** 
 161:AES128.cpp    **** /**
 162:AES128.cpp    ****  * \brief Size of an AES block in bytes.
 163:AES128.cpp    ****  * \return Always returns 16.
 164:AES128.cpp    ****  */
 165:AES128.cpp    **** size_t AESTiny128::blockSize() const
 166:AES128.cpp    **** {
 167:AES128.cpp    ****     return 16;
 168:AES128.cpp    **** }
 169:AES128.cpp    **** 
 170:AES128.cpp    **** /**
 171:AES128.cpp    ****  * \brief Size of a 128-bit AES key in bytes.
 172:AES128.cpp    ****  * \return Always returns 16.
 173:AES128.cpp    ****  */
 174:AES128.cpp    **** size_t AESTiny128::keySize() const
 175:AES128.cpp    **** {
 176:AES128.cpp    ****     return 16;
 177:AES128.cpp    **** }
 178:AES128.cpp    **** 
 179:AES128.cpp    **** bool AESTiny128::setKey(const uint8_t *key, size_t len)
 180:AES128.cpp    **** {
 181:AES128.cpp    ****     if (len == 16) {
 182:AES128.cpp    ****         // Make a copy of the key - it will be expanded in encryptBlock().
 183:AES128.cpp    ****         memcpy(schedule, key, 16);
 184:AES128.cpp    ****         return true;
 185:AES128.cpp    ****     }
 186:AES128.cpp    ****     return false;
 187:AES128.cpp    **** }
 188:AES128.cpp    **** 
 189:AES128.cpp    **** void AESTiny128::encryptBlock(uint8_t *output, const uint8_t *input)
 190:AES128.cpp    **** {
 191:AES128.cpp    ****     uint8_t schedule[16];
 192:AES128.cpp    ****     uint8_t posn;
 193:AES128.cpp    ****     uint8_t round;
 194:AES128.cpp    ****     uint8_t state1[16];
 195:AES128.cpp    ****     uint8_t state2[16];
 196:AES128.cpp    ****     uint8_t temp[4];
 197:AES128.cpp    **** 
 198:AES128.cpp    ****     // Start with the key in the schedule buffer.
 199:AES128.cpp    ****     memcpy(schedule, this->schedule, 16);
 200:AES128.cpp    **** 
 201:AES128.cpp    ****     // Copy the input into the state and XOR with the key schedule.
 202:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 203:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 204:AES128.cpp    **** 
 205:AES128.cpp    ****     // Perform the first 9 rounds of the cipher.
 206:AES128.cpp    ****     for (round = 1; round <= 9; ++round) {
 207:AES128.cpp    ****         // Expand the next 16 bytes of the key schedule.
 208:AES128.cpp    ****         KCORE(round);
 209:AES128.cpp    ****         KXOR(1, 0);
 210:AES128.cpp    ****         KXOR(2, 1);
 211:AES128.cpp    ****         KXOR(3, 2);
 212:AES128.cpp    **** 
 213:AES128.cpp    ****         // Encrypt using the key schedule.
 214:AES128.cpp    ****         AESCommon::subBytesAndShiftRows(state2, state1);
 215:AES128.cpp    ****         AESCommon::mixColumn(state1,      state2);
 216:AES128.cpp    ****         AESCommon::mixColumn(state1 + 4,  state2 + 4);
 217:AES128.cpp    ****         AESCommon::mixColumn(state1 + 8,  state2 + 8);
 218:AES128.cpp    ****         AESCommon::mixColumn(state1 + 12, state2 + 12);
 219:AES128.cpp    ****         for (posn = 0; posn < 16; ++posn)
 220:AES128.cpp    ****             state1[posn] ^= schedule[posn];
 221:AES128.cpp    ****     }
 222:AES128.cpp    **** 
 223:AES128.cpp    ****     // Expand the final 16 bytes of the key schedule.
 224:AES128.cpp    ****     KCORE(10);
 225:AES128.cpp    ****     KXOR(1, 0);
 226:AES128.cpp    ****     KXOR(2, 1);
 227:AES128.cpp    ****     KXOR(3, 2);
 228:AES128.cpp    **** 
 229:AES128.cpp    ****     // Perform the final round.
 230:AES128.cpp    ****     AESCommon::subBytesAndShiftRows(state2, state1);
 231:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 232:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 233:AES128.cpp    **** }
 234:AES128.cpp    **** 
 235:AES128.cpp    **** void AESTiny128::decryptBlock(uint8_t *output, const uint8_t *input)
 236:AES128.cpp    **** {
  61              		.loc 1 236 1 is_stmt 1 view -0
  62              		.cfi_startproc
  63              		@ args = 0, pretend = 0, frame = 0
  64              		@ frame_needed = 0, uses_anonymous_args = 0
  65              		@ link register save eliminated.
 237:AES128.cpp    ****     // Decryption is not supported by AESTiny128.
 238:AES128.cpp    **** }
  66              		.loc 1 238 1 is_stmt 0 view .LVU5
  67 0000 7047     		bx	lr
  68              		.cfi_endproc
  69              	.LFE21:
  70              		.cantunwind
  71              		.fnend
  73              		.section	.text._ZN6AES128D2Ev,"ax",%progbits
  74              		.align	1
  75              		.global	_ZN6AES128D2Ev
  76              		.syntax unified
  77              		.thumb
  78              		.thumb_func
  79              		.fpu softvfp
  81              	_ZN6AES128D2Ev:
  82              		.fnstart
  83              	.LVL3:
  84              	.LFB5:
  48:AES128.cpp    **** {
  85              		.loc 1 48 1 is_stmt 1 view -0
  86              		.cfi_startproc
  87              		@ args = 0, pretend = 0, frame = 0
  88              		@ frame_needed = 0, uses_anonymous_args = 0
  48:AES128.cpp    **** {
  89              		.loc 1 48 1 is_stmt 0 view .LVU7
  90 0000 10B5     		push	{r4, lr}
  91              		.save {r4, lr}
  92              	.LCFI0:
  93              		.cfi_def_cfa_offset 8
  94              		.cfi_offset 4, -8
  95              		.cfi_offset 14, -4
  96              	.LBB7:
  48:AES128.cpp    **** {
  97              		.loc 1 48 17 view .LVU8
  98 0002 064B     		ldr	r3, .L4
  99              	.LBE7:
  48:AES128.cpp    **** {
 100              		.loc 1 48 1 view .LVU9
 101 0004 0446     		mov	r4, r0
 102              	.LBB12:
 103              	.LBB8:
 104              	.LBB9:
 105              		.file 2 "Crypto.h"
   1:Crypto.h      **** /*
   2:Crypto.h      ****  * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
   3:Crypto.h      ****  *
   4:Crypto.h      ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:Crypto.h      ****  * copy of this software and associated documentation files (the "Software"),
   6:Crypto.h      ****  * to deal in the Software without restriction, including without limitation
   7:Crypto.h      ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:Crypto.h      ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:Crypto.h      ****  * Software is furnished to do so, subject to the following conditions:
  10:Crypto.h      ****  *
  11:Crypto.h      ****  * The above copyright notice and this permission notice shall be included
  12:Crypto.h      ****  * in all copies or substantial portions of the Software.
  13:Crypto.h      ****  *
  14:Crypto.h      ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:Crypto.h      ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:Crypto.h      ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:Crypto.h      ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:Crypto.h      ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:Crypto.h      ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:Crypto.h      ****  * DEALINGS IN THE SOFTWARE.
  21:Crypto.h      ****  */
  22:Crypto.h      **** 
  23:Crypto.h      **** #ifndef CRYPTO_h
  24:Crypto.h      **** #define CRYPTO_h
  25:Crypto.h      **** 
  26:Crypto.h      **** #include <inttypes.h>
  27:Crypto.h      **** #include <stddef.h>
  28:Crypto.h      **** 
  29:Crypto.h      **** void clean(void *dest, size_t size);
  30:Crypto.h      **** 
  31:Crypto.h      **** template <typename T>
  32:Crypto.h      **** inline void clean(T &var)
  33:Crypto.h      **** {
  34:Crypto.h      ****     clean(&var, sizeof(T));
 106              		.loc 2 34 10 view .LVU10
 107 0006 B021     		movs	r1, #176
 108              	.LBE9:
 109              	.LBE8:
  48:AES128.cpp    **** {
 110              		.loc 1 48 17 view .LVU11
 111 0008 40F80C3B 		str	r3, [r0], #12
 112              	.LVL4:
  50:AES128.cpp    **** }
 113              		.loc 1 50 5 is_stmt 1 view .LVU12
 114              	.LBB11:
 115              	.LBI8:
  32:Crypto.h      **** {
 116              		.loc 2 32 13 view .LVU13
 117              	.LBB10:
 118              		.loc 2 34 10 is_stmt 0 view .LVU14
 119 000c FFF7FEFF 		bl	_Z5cleanPvj
 120              	.LVL5:
 121              		.loc 2 34 10 view .LVU15
 122              	.LBE10:
 123              	.LBE11:
  48:AES128.cpp    **** {
 124              		.loc 1 48 17 view .LVU16
 125 0010 2046     		mov	r0, r4
 126 0012 FFF7FEFF 		bl	_ZN9AESCommonD2Ev
 127              	.LVL6:
 128              	.LBE12:
  51:AES128.cpp    **** 
 129              		.loc 1 51 1 view .LVU17
 130 0016 2046     		mov	r0, r4
 131 0018 10BD     		pop	{r4, pc}
 132              	.LVL7:
 133              	.L5:
  51:AES128.cpp    **** 
 134              		.loc 1 51 1 view .LVU18
 135 001a 00BF     		.align	2
 136              	.L4:
 137 001c 08000000 		.word	.LANCHOR0+8
 138              		.cfi_endproc
 139              	.LFE5:
 140              		.global	__gxx_personality_v0
 141              		.personality	__gxx_personality_v0
 142              		.handlerdata
 143              	.LLSDA5:
 144 0008 FF       		.byte	0xff
 145 0009 FF       		.byte	0xff
 146 000a 01       		.byte	0x1
 147 000b 00       		.uleb128 .LLSDACSE5-.LLSDACSB5
 148              	.LLSDACSB5:
 149              	.LLSDACSE5:
 150              		.section	.text._ZN6AES128D2Ev
 151              		.fnend
 153              		.global	_ZN6AES128D1Ev
 154              		.thumb_set _ZN6AES128D1Ev,_ZN6AES128D2Ev
 155              		.section	.text._ZN6AES128D0Ev,"ax",%progbits
 156              		.align	1
 157              		.global	_ZN6AES128D0Ev
 158              		.syntax unified
 159              		.thumb
 160              		.thumb_func
 161              		.fpu softvfp
 163              	_ZN6AES128D0Ev:
 164              		.fnstart
 165              	.LVL8:
 166              	.LFB7:
  48:AES128.cpp    **** {
 167              		.loc 1 48 1 is_stmt 1 view -0
 168              		.cfi_startproc
 169              		@ args = 0, pretend = 0, frame = 0
 170              		@ frame_needed = 0, uses_anonymous_args = 0
  48:AES128.cpp    **** {
 171              		.loc 1 48 1 is_stmt 0 view .LVU20
 172 0000 10B5     		push	{r4, lr}
 173              	.LCFI1:
 174              		.cfi_def_cfa_offset 8
 175              		.cfi_offset 4, -8
 176              		.cfi_offset 14, -4
  48:AES128.cpp    **** {
 177              		.loc 1 48 1 view .LVU21
 178 0002 0446     		mov	r4, r0
  51:AES128.cpp    **** 
 179              		.loc 1 51 1 view .LVU22
 180 0004 FFF7FEFF 		bl	_ZN6AES128D1Ev
 181              	.LVL9:
  51:AES128.cpp    **** 
 182              		.loc 1 51 1 view .LVU23
 183 0008 2046     		mov	r0, r4
 184 000a BC21     		movs	r1, #188
 185 000c FFF7FEFF 		bl	_ZdlPvj
 186              	.LVL10:
 187 0010 2046     		mov	r0, r4
 188 0012 10BD     		pop	{r4, pc}
  51:AES128.cpp    **** 
 189              		.loc 1 51 1 view .LVU24
 190              		.cfi_endproc
 191              	.LFE7:
 192              		.cantunwind
 193              		.fnend
 195              		.section	.text._ZN10AESTiny1286setKeyEPKhj,"ax",%progbits
 196              		.align	1
 197              		.global	_ZN10AESTiny1286setKeyEPKhj
 198              		.syntax unified
 199              		.thumb
 200              		.thumb_func
 201              		.fpu softvfp
 203              	_ZN10AESTiny1286setKeyEPKhj:
 204              		.fnstart
 205              	.LVL11:
 206              	.LFB19:
 180:AES128.cpp    ****     if (len == 16) {
 207              		.loc 1 180 1 is_stmt 1 view -0
 208              		.cfi_startproc
 209              		@ args = 0, pretend = 0, frame = 0
 210              		@ frame_needed = 0, uses_anonymous_args = 0
 211              		@ link register save eliminated.
 181:AES128.cpp    ****         // Make a copy of the key - it will be expanded in encryptBlock().
 212              		.loc 1 181 5 view .LVU26
 213 0000 102A     		cmp	r2, #16
 214 0002 0AD1     		bne	.L10
 183:AES128.cpp    ****         return true;
 215              		.loc 1 183 9 view .LVU27
 183:AES128.cpp    ****         return true;
 216              		.loc 1 183 15 is_stmt 0 view .LVU28
 217 0004 0430     		adds	r0, r0, #4
 218              	.LVL12:
 183:AES128.cpp    ****         return true;
 219              		.loc 1 183 15 view .LVU29
 220 0006 01F11003 		add	r3, r1, #16
 221              	.LVL13:
 222              	.L9:
 183:AES128.cpp    ****         return true;
 223              		.loc 1 183 15 view .LVU30
 224 000a 51F8042B 		ldr	r2, [r1], #4	@ unaligned
 225 000e 40F8042B 		str	r2, [r0], #4	@ unaligned
 226 0012 9942     		cmp	r1, r3
 227 0014 F9D1     		bne	.L9
 184:AES128.cpp    ****     }
 228              		.loc 1 184 9 is_stmt 1 view .LVU31
 184:AES128.cpp    ****     }
 229              		.loc 1 184 16 is_stmt 0 view .LVU32
 230 0016 0120     		movs	r0, #1
 231 0018 7047     		bx	lr
 232              	.LVL14:
 233              	.L10:
 186:AES128.cpp    **** }
 234              		.loc 1 186 12 view .LVU33
 235 001a 0020     		movs	r0, #0
 236              	.LVL15:
 187:AES128.cpp    **** 
 237              		.loc 1 187 1 view .LVU34
 238 001c 7047     		bx	lr
 239              		.cfi_endproc
 240              	.LFE19:
 241              		.cantunwind
 242              		.fnend
 244              		.section	.text._ZN10AESTiny128D2Ev,"ax",%progbits
 245              		.align	1
 246              		.global	_ZN10AESTiny128D2Ev
 247              		.syntax unified
 248              		.thumb
 249              		.thumb_func
 250              		.fpu softvfp
 252              	_ZN10AESTiny128D2Ev:
 253              		.fnstart
 254              	.LVL16:
 255              	.LFB14:
 156:AES128.cpp    **** {
 256              		.loc 1 156 1 is_stmt 1 view -0
 257              		.cfi_startproc
 258              		@ args = 0, pretend = 0, frame = 0
 259              		@ frame_needed = 0, uses_anonymous_args = 0
 156:AES128.cpp    **** {
 260              		.loc 1 156 1 is_stmt 0 view .LVU36
 261 0000 10B5     		push	{r4, lr}
 262              		.save {r4, lr}
 263              	.LCFI2:
 264              		.cfi_def_cfa_offset 8
 265              		.cfi_offset 4, -8
 266              		.cfi_offset 14, -4
 267              	.LBB16:
 156:AES128.cpp    **** {
 268              		.loc 1 156 25 view .LVU37
 269 0002 064B     		ldr	r3, .L13
 270              	.LBE16:
 156:AES128.cpp    **** {
 271              		.loc 1 156 1 view .LVU38
 272 0004 0446     		mov	r4, r0
 273              	.LBB21:
 274              	.LBB17:
 275              	.LBB18:
 276              		.loc 2 34 10 view .LVU39
 277 0006 1021     		movs	r1, #16
 278              	.LBE18:
 279              	.LBE17:
 156:AES128.cpp    **** {
 280              		.loc 1 156 25 view .LVU40
 281 0008 40F8043B 		str	r3, [r0], #4
 282              	.LVL17:
 158:AES128.cpp    **** }
 283              		.loc 1 158 5 is_stmt 1 view .LVU41
 284              	.LBB20:
 285              	.LBI17:
  32:Crypto.h      **** {
 286              		.loc 2 32 13 view .LVU42
 287              	.LBB19:
 288              		.loc 2 34 10 is_stmt 0 view .LVU43
 289 000c FFF7FEFF 		bl	_Z5cleanPvj
 290              	.LVL18:
 291              		.loc 2 34 10 view .LVU44
 292              	.LBE19:
 293              	.LBE20:
 156:AES128.cpp    **** {
 294              		.loc 1 156 25 view .LVU45
 295 0010 2046     		mov	r0, r4
 296 0012 FFF7FEFF 		bl	_ZN11BlockCipherD2Ev
 297              	.LVL19:
 298              	.LBE21:
 159:AES128.cpp    **** 
 299              		.loc 1 159 1 view .LVU46
 300 0016 2046     		mov	r0, r4
 301 0018 10BD     		pop	{r4, pc}
 302              	.LVL20:
 303              	.L14:
 159:AES128.cpp    **** 
 304              		.loc 1 159 1 view .LVU47
 305 001a 00BF     		.align	2
 306              	.L13:
 307 001c 30000000 		.word	.LANCHOR0+48
 308              		.cfi_endproc
 309              	.LFE14:
 310              		.personality	__gxx_personality_v0
 311              		.handlerdata
 312              	.LLSDA14:
 313 0008 FF       		.byte	0xff
 314 0009 FF       		.byte	0xff
 315 000a 01       		.byte	0x1
 316 000b 00       		.uleb128 .LLSDACSE14-.LLSDACSB14
 317              	.LLSDACSB14:
 318              	.LLSDACSE14:
 319              		.section	.text._ZN10AESTiny128D2Ev
 320              		.fnend
 322              		.global	_ZN10AESTiny128D1Ev
 323              		.thumb_set _ZN10AESTiny128D1Ev,_ZN10AESTiny128D2Ev
 324              		.section	.text._ZN10AESTiny128D0Ev,"ax",%progbits
 325              		.align	1
 326              		.global	_ZN10AESTiny128D0Ev
 327              		.syntax unified
 328              		.thumb
 329              		.thumb_func
 330              		.fpu softvfp
 332              	_ZN10AESTiny128D0Ev:
 333              		.fnstart
 334              	.LVL21:
 335              	.LFB16:
 156:AES128.cpp    **** {
 336              		.loc 1 156 1 is_stmt 1 view -0
 337              		.cfi_startproc
 338              		@ args = 0, pretend = 0, frame = 0
 339              		@ frame_needed = 0, uses_anonymous_args = 0
 156:AES128.cpp    **** {
 340              		.loc 1 156 1 is_stmt 0 view .LVU49
 341 0000 10B5     		push	{r4, lr}
 342              	.LCFI3:
 343              		.cfi_def_cfa_offset 8
 344              		.cfi_offset 4, -8
 345              		.cfi_offset 14, -4
 156:AES128.cpp    **** {
 346              		.loc 1 156 1 view .LVU50
 347 0002 0446     		mov	r4, r0
 159:AES128.cpp    **** 
 348              		.loc 1 159 1 view .LVU51
 349 0004 FFF7FEFF 		bl	_ZN10AESTiny128D1Ev
 350              	.LVL22:
 159:AES128.cpp    **** 
 351              		.loc 1 159 1 view .LVU52
 352 0008 2046     		mov	r0, r4
 353 000a 1421     		movs	r1, #20
 354 000c FFF7FEFF 		bl	_ZdlPvj
 355              	.LVL23:
 356 0010 2046     		mov	r0, r4
 357 0012 10BD     		pop	{r4, pc}
 159:AES128.cpp    **** 
 358              		.loc 1 159 1 view .LVU53
 359              		.cfi_endproc
 360              	.LFE16:
 361              		.cantunwind
 362              		.fnend
 364              		.section	.text._ZN10AESTiny12812encryptBlockEPhPKh,"ax",%progbits
 365              		.align	1
 366              		.global	_ZN10AESTiny12812encryptBlockEPhPKh
 367              		.syntax unified
 368              		.thumb
 369              		.thumb_func
 370              		.fpu softvfp
 372              	_ZN10AESTiny12812encryptBlockEPhPKh:
 373              		.fnstart
 374              	.LVL24:
 375              	.LFB20:
 190:AES128.cpp    ****     uint8_t schedule[16];
 376              		.loc 1 190 1 is_stmt 1 view -0
 377              		.cfi_startproc
 378              		@ args = 0, pretend = 0, frame = 56
 379              		@ frame_needed = 0, uses_anonymous_args = 0
 190:AES128.cpp    ****     uint8_t schedule[16];
 380              		.loc 1 190 1 is_stmt 0 view .LVU55
 381 0000 2DE9F041 		push	{r4, r5, r6, r7, r8, lr}
 382              		.save {r4, r5, r6, r7, r8, lr}
 383              	.LCFI4:
 384              		.cfi_def_cfa_offset 24
 385              		.cfi_offset 4, -24
 386              		.cfi_offset 5, -20
 387              		.cfi_offset 6, -16
 388              		.cfi_offset 7, -12
 389              		.cfi_offset 8, -8
 390              		.cfi_offset 14, -4
 391              		.pad #56
 392 0004 8EB0     		sub	sp, sp, #56
 393              	.LCFI5:
 394              		.cfi_def_cfa_offset 80
 199:AES128.cpp    **** 
 395              		.loc 1 199 11 view .LVU56
 396 0006 02AE     		add	r6, sp, #8
 190:AES128.cpp    ****     uint8_t schedule[16];
 397              		.loc 1 190 1 view .LVU57
 398 0008 0C46     		mov	r4, r1
 191:AES128.cpp    ****     uint8_t posn;
 399              		.loc 1 191 5 is_stmt 1 view .LVU58
 192:AES128.cpp    ****     uint8_t round;
 400              		.loc 1 192 5 view .LVU59
 193:AES128.cpp    ****     uint8_t state1[16];
 401              		.loc 1 193 5 view .LVU60
 194:AES128.cpp    ****     uint8_t state2[16];
 402              		.loc 1 194 5 view .LVU61
 195:AES128.cpp    ****     uint8_t temp[4];
 403              		.loc 1 195 5 view .LVU62
 196:AES128.cpp    **** 
 404              		.loc 1 196 5 view .LVU63
 199:AES128.cpp    **** 
 405              		.loc 1 199 5 view .LVU64
 199:AES128.cpp    **** 
 406              		.loc 1 199 11 is_stmt 0 view .LVU65
 407 000a 051D     		adds	r5, r0, #4
 408 000c 00F11403 		add	r3, r0, #20
 409 0010 3746     		mov	r7, r6
 410              	.LVL25:
 411              	.L17:
 199:AES128.cpp    **** 
 412              		.loc 1 199 11 view .LVU66
 413 0012 2868     		ldr	r0, [r5]	@ unaligned
 414 0014 6968     		ldr	r1, [r5, #4]	@ unaligned
 415 0016 B446     		mov	ip, r6
 416 0018 ACE80300 		stmia	ip!, {r0, r1}
 417 001c 0835     		adds	r5, r5, #8
 418 001e 9D42     		cmp	r5, r3
 419 0020 6646     		mov	r6, ip
 420 0022 F6D1     		bne	.L17
 202:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 421              		.loc 1 202 5 is_stmt 1 view .LVU67
 422              	.LVL26:
 202:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 423              		.loc 1 202 25 view .LVU68
 424 0024 531E     		subs	r3, r2, #1
 425              	.LVL27:
 202:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 426              		.loc 1 202 25 is_stmt 0 view .LVU69
 427 0026 3D46     		mov	r5, r7
 428 0028 0F32     		adds	r2, r2, #15
 429              	.LVL28:
 199:AES128.cpp    **** 
 430              		.loc 1 199 11 view .LVU70
 431 002a 06A8     		add	r0, sp, #24
 432 002c 3E46     		mov	r6, r7
 433              	.LVL29:
 434              	.L18:
 203:AES128.cpp    **** 
 435              		.loc 1 203 9 is_stmt 1 discriminator 2 view .LVU71
 203:AES128.cpp    **** 
 436              		.loc 1 203 36 is_stmt 0 discriminator 2 view .LVU72
 437 002e 13F801CF 		ldrb	ip, [r3, #1]!	@ zero_extendqisi2
 438              	.LVL30:
 203:AES128.cpp    **** 
 439              		.loc 1 203 51 discriminator 2 view .LVU73
 440 0032 16F8011B 		ldrb	r1, [r6], #1	@ zero_extendqisi2
 202:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 441              		.loc 1 202 25 discriminator 2 view .LVU74
 442 0036 9342     		cmp	r3, r2
 203:AES128.cpp    **** 
 443              		.loc 1 203 36 discriminator 2 view .LVU75
 444 0038 81EA0C01 		eor	r1, r1, ip
 203:AES128.cpp    **** 
 445              		.loc 1 203 22 discriminator 2 view .LVU76
 446 003c 00F8011B 		strb	r1, [r0], #1
 202:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 447              		.loc 1 202 5 is_stmt 1 discriminator 2 view .LVU77
 448              	.LVL31:
 202:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 449              		.loc 1 202 25 discriminator 2 view .LVU78
 450 0040 F5D1     		bne	.L18
 206:AES128.cpp    ****         // Expand the next 16 bytes of the key schedule.
 451              		.loc 1 206 16 is_stmt 0 view .LVU79
 452 0042 4FF00108 		mov	r8, #1
 453              	.LVL32:
 454              	.L20:
 208:AES128.cpp    ****         KXOR(1, 0);
 455              		.loc 1 208 9 is_stmt 1 view .LVU80
 208:AES128.cpp    ****         KXOR(1, 0);
 456              		.loc 1 208 9 view .LVU81
 457 0046 4246     		mov	r2, r8
 458 0048 05A9     		add	r1, sp, #20
 459 004a 01A8     		add	r0, sp, #4
 460 004c FFF7FEFF 		bl	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 461              	.LVL33:
 208:AES128.cpp    ****         KXOR(1, 0);
 462              		.loc 1 208 9 view .LVU82
 463 0050 9DF80860 		ldrb	r6, [sp, #8]	@ zero_extendqisi2
 464 0054 9DF80430 		ldrb	r3, [sp, #4]	@ zero_extendqisi2
 465 0058 9DF80900 		ldrb	r0, [sp, #9]	@ zero_extendqisi2
 466 005c 9DF80A10 		ldrb	r1, [sp, #10]	@ zero_extendqisi2
 467 0060 9DF80B20 		ldrb	r2, [sp, #11]	@ zero_extendqisi2
 468 0064 5E40     		eors	r6, r6, r3
 469 0066 9DF80530 		ldrb	r3, [sp, #5]	@ zero_extendqisi2
 470 006a 8DF80860 		strb	r6, [sp, #8]
 208:AES128.cpp    ****         KXOR(1, 0);
 471              		.loc 1 208 9 view .LVU83
 472 006e 5840     		eors	r0, r0, r3
 473 0070 9DF80630 		ldrb	r3, [sp, #6]	@ zero_extendqisi2
 474 0074 8DF80900 		strb	r0, [sp, #9]
 208:AES128.cpp    ****         KXOR(1, 0);
 475              		.loc 1 208 9 view .LVU84
 476 0078 5940     		eors	r1, r1, r3
 477 007a 9DF80730 		ldrb	r3, [sp, #7]	@ zero_extendqisi2
 478 007e 8DF80A10 		strb	r1, [sp, #10]
 208:AES128.cpp    ****         KXOR(1, 0);
 479              		.loc 1 208 9 view .LVU85
 480 0082 5340     		eors	r3, r3, r2
 209:AES128.cpp    ****         KXOR(2, 1);
 481              		.loc 1 209 9 is_stmt 0 view .LVU86
 482 0084 9DF80C20 		ldrb	r2, [sp, #12]	@ zero_extendqisi2
 208:AES128.cpp    ****         KXOR(1, 0);
 483              		.loc 1 208 9 view .LVU87
 484 0088 8DF80B30 		strb	r3, [sp, #11]
 209:AES128.cpp    ****         KXOR(2, 1);
 485              		.loc 1 209 9 is_stmt 1 view .LVU88
 209:AES128.cpp    ****         KXOR(2, 1);
 486              		.loc 1 209 9 view .LVU89
 487 008c 5640     		eors	r6, r6, r2
 488 008e 9DF80D20 		ldrb	r2, [sp, #13]	@ zero_extendqisi2
 489 0092 8DF80C60 		strb	r6, [sp, #12]
 209:AES128.cpp    ****         KXOR(2, 1);
 490              		.loc 1 209 9 view .LVU90
 491 0096 5040     		eors	r0, r0, r2
 492 0098 9DF80E20 		ldrb	r2, [sp, #14]	@ zero_extendqisi2
 493 009c 8DF80D00 		strb	r0, [sp, #13]
 209:AES128.cpp    ****         KXOR(2, 1);
 494              		.loc 1 209 9 view .LVU91
 495 00a0 5140     		eors	r1, r1, r2
 496 00a2 9DF80F20 		ldrb	r2, [sp, #15]	@ zero_extendqisi2
 497 00a6 8DF80E10 		strb	r1, [sp, #14]
 209:AES128.cpp    ****         KXOR(2, 1);
 498              		.loc 1 209 9 view .LVU92
 499 00aa 5340     		eors	r3, r3, r2
 210:AES128.cpp    ****         KXOR(3, 2);
 500              		.loc 1 210 9 is_stmt 0 view .LVU93
 501 00ac 9DF81020 		ldrb	r2, [sp, #16]	@ zero_extendqisi2
 209:AES128.cpp    ****         KXOR(2, 1);
 502              		.loc 1 209 9 view .LVU94
 503 00b0 8DF80F30 		strb	r3, [sp, #15]
 210:AES128.cpp    ****         KXOR(3, 2);
 504              		.loc 1 210 9 is_stmt 1 view .LVU95
 210:AES128.cpp    ****         KXOR(3, 2);
 505              		.loc 1 210 9 view .LVU96
 506 00b4 5640     		eors	r6, r6, r2
 507 00b6 9DF81120 		ldrb	r2, [sp, #17]	@ zero_extendqisi2
 508 00ba 8DF81060 		strb	r6, [sp, #16]
 210:AES128.cpp    ****         KXOR(3, 2);
 509              		.loc 1 210 9 view .LVU97
 510 00be 5040     		eors	r0, r0, r2
 511 00c0 9DF81220 		ldrb	r2, [sp, #18]	@ zero_extendqisi2
 512 00c4 8DF81100 		strb	r0, [sp, #17]
 210:AES128.cpp    ****         KXOR(3, 2);
 513              		.loc 1 210 9 view .LVU98
 514 00c8 5140     		eors	r1, r1, r2
 515 00ca 9DF81320 		ldrb	r2, [sp, #19]	@ zero_extendqisi2
 516 00ce 8DF81210 		strb	r1, [sp, #18]
 210:AES128.cpp    ****         KXOR(3, 2);
 517              		.loc 1 210 9 view .LVU99
 518 00d2 5340     		eors	r3, r3, r2
 211:AES128.cpp    **** 
 519              		.loc 1 211 9 is_stmt 0 view .LVU100
 520 00d4 9DF81420 		ldrb	r2, [sp, #20]	@ zero_extendqisi2
 210:AES128.cpp    ****         KXOR(3, 2);
 521              		.loc 1 210 9 view .LVU101
 522 00d8 8DF81330 		strb	r3, [sp, #19]
 211:AES128.cpp    **** 
 523              		.loc 1 211 9 is_stmt 1 view .LVU102
 211:AES128.cpp    **** 
 524              		.loc 1 211 9 view .LVU103
 525 00dc 5640     		eors	r6, r6, r2
 526 00de 9DF81520 		ldrb	r2, [sp, #21]	@ zero_extendqisi2
 527 00e2 8DF81460 		strb	r6, [sp, #20]
 211:AES128.cpp    **** 
 528              		.loc 1 211 9 view .LVU104
 529 00e6 5040     		eors	r0, r0, r2
 530 00e8 8DF81500 		strb	r0, [sp, #21]
 211:AES128.cpp    **** 
 531              		.loc 1 211 9 view .LVU105
 532 00ec 9DF81620 		ldrb	r2, [sp, #22]	@ zero_extendqisi2
 533 00f0 5140     		eors	r1, r1, r2
 534 00f2 9DF81720 		ldrb	r2, [sp, #23]	@ zero_extendqisi2
 535 00f6 8DF81610 		strb	r1, [sp, #22]
 211:AES128.cpp    **** 
 536              		.loc 1 211 9 view .LVU106
 537 00fa 5340     		eors	r3, r3, r2
 214:AES128.cpp    ****         AESCommon::mixColumn(state1,      state2);
 538              		.loc 1 214 40 is_stmt 0 view .LVU107
 539 00fc 06A9     		add	r1, sp, #24
 540 00fe 0AA8     		add	r0, sp, #40
 211:AES128.cpp    **** 
 541              		.loc 1 211 9 view .LVU108
 542 0100 8DF81730 		strb	r3, [sp, #23]
 214:AES128.cpp    ****         AESCommon::mixColumn(state1,      state2);
 543              		.loc 1 214 9 is_stmt 1 view .LVU109
 214:AES128.cpp    ****         AESCommon::mixColumn(state1,      state2);
 544              		.loc 1 214 40 is_stmt 0 view .LVU110
 545 0104 FFF7FEFF 		bl	_ZN9AESCommon20subBytesAndShiftRowsEPhPKh
 546              	.LVL34:
 215:AES128.cpp    ****         AESCommon::mixColumn(state1 + 4,  state2 + 4);
 547              		.loc 1 215 9 is_stmt 1 view .LVU111
 215:AES128.cpp    ****         AESCommon::mixColumn(state1 + 4,  state2 + 4);
 548              		.loc 1 215 29 is_stmt 0 view .LVU112
 549 0108 0AA9     		add	r1, sp, #40
 550 010a 06A8     		add	r0, sp, #24
 551 010c FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 552              	.LVL35:
 216:AES128.cpp    ****         AESCommon::mixColumn(state1 + 8,  state2 + 8);
 553              		.loc 1 216 9 is_stmt 1 view .LVU113
 216:AES128.cpp    ****         AESCommon::mixColumn(state1 + 8,  state2 + 8);
 554              		.loc 1 216 29 is_stmt 0 view .LVU114
 555 0110 0BA9     		add	r1, sp, #44
 556 0112 07A8     		add	r0, sp, #28
 557 0114 FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 558              	.LVL36:
 217:AES128.cpp    ****         AESCommon::mixColumn(state1 + 12, state2 + 12);
 559              		.loc 1 217 9 is_stmt 1 view .LVU115
 217:AES128.cpp    ****         AESCommon::mixColumn(state1 + 12, state2 + 12);
 560              		.loc 1 217 29 is_stmt 0 view .LVU116
 561 0118 0CA9     		add	r1, sp, #48
 562 011a 08A8     		add	r0, sp, #32
 563 011c FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 564              	.LVL37:
 218:AES128.cpp    ****         for (posn = 0; posn < 16; ++posn)
 565              		.loc 1 218 9 is_stmt 1 view .LVU117
 218:AES128.cpp    ****         for (posn = 0; posn < 16; ++posn)
 566              		.loc 1 218 29 is_stmt 0 view .LVU118
 567 0120 09A8     		add	r0, sp, #36
 568 0122 0DA9     		add	r1, sp, #52
 569 0124 FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 570              	.LVL38:
 219:AES128.cpp    ****             state1[posn] ^= schedule[posn];
 571              		.loc 1 219 29 is_stmt 1 view .LVU119
 218:AES128.cpp    ****         for (posn = 0; posn < 16; ++posn)
 572              		.loc 1 218 29 is_stmt 0 view .LVU120
 573 0128 3846     		mov	r0, r7
 574 012a 06AA     		add	r2, sp, #24
 575 012c 1023     		movs	r3, #16
 576              	.LVL39:
 577              	.L19:
 220:AES128.cpp    ****     }
 578              		.loc 1 220 13 is_stmt 1 discriminator 2 view .LVU121
 220:AES128.cpp    ****     }
 579              		.loc 1 220 26 is_stmt 0 discriminator 2 view .LVU122
 580 012e 1178     		ldrb	r1, [r2]	@ zero_extendqisi2
 220:AES128.cpp    ****     }
 581              		.loc 1 220 42 discriminator 2 view .LVU123
 582 0130 10F8016B 		ldrb	r6, [r0], #1	@ zero_extendqisi2
 219:AES128.cpp    ****             state1[posn] ^= schedule[posn];
 583              		.loc 1 219 29 discriminator 2 view .LVU124
 584 0134 013B     		subs	r3, r3, #1
 220:AES128.cpp    ****     }
 585              		.loc 1 220 26 discriminator 2 view .LVU125
 586 0136 7140     		eors	r1, r1, r6
 219:AES128.cpp    ****             state1[posn] ^= schedule[posn];
 587              		.loc 1 219 29 discriminator 2 view .LVU126
 588 0138 13F0FF03 		ands	r3, r3, #255
 220:AES128.cpp    ****     }
 589              		.loc 1 220 26 discriminator 2 view .LVU127
 590 013c 02F8011B 		strb	r1, [r2], #1
 591              	.LVL40:
 219:AES128.cpp    ****             state1[posn] ^= schedule[posn];
 592              		.loc 1 219 9 is_stmt 1 discriminator 2 view .LVU128
 219:AES128.cpp    ****             state1[posn] ^= schedule[posn];
 593              		.loc 1 219 29 discriminator 2 view .LVU129
 594 0140 F5D1     		bne	.L19
 206:AES128.cpp    ****         // Expand the next 16 bytes of the key schedule.
 595              		.loc 1 206 5 discriminator 2 view .LVU130
 596 0142 08F10108 		add	r8, r8, #1
 597              	.LVL41:
 206:AES128.cpp    ****         // Expand the next 16 bytes of the key schedule.
 598              		.loc 1 206 5 is_stmt 0 discriminator 2 view .LVU131
 599 0146 5FFA88F8 		uxtb	r8, r8
 600              	.LVL42:
 206:AES128.cpp    ****         // Expand the next 16 bytes of the key schedule.
 601              		.loc 1 206 27 is_stmt 1 discriminator 2 view .LVU132
 602 014a B8F10A0F 		cmp	r8, #10
 603 014e 7FF47AAF 		bne	.L20
 224:AES128.cpp    ****     KXOR(1, 0);
 604              		.loc 1 224 5 view .LVU133
 224:AES128.cpp    ****     KXOR(1, 0);
 605              		.loc 1 224 5 view .LVU134
 606 0152 4246     		mov	r2, r8
 607              	.LVL43:
 224:AES128.cpp    ****     KXOR(1, 0);
 608              		.loc 1 224 5 is_stmt 0 view .LVU135
 609 0154 05A9     		add	r1, sp, #20
 610 0156 01A8     		add	r0, sp, #4
 611 0158 FFF7FEFF 		bl	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 612              	.LVL44:
 224:AES128.cpp    ****     KXOR(1, 0);
 613              		.loc 1 224 5 is_stmt 1 view .LVU136
 614 015c 9DF80800 		ldrb	r0, [sp, #8]	@ zero_extendqisi2
 615 0160 9DF80430 		ldrb	r3, [sp, #4]	@ zero_extendqisi2
 616 0164 9DF80910 		ldrb	r1, [sp, #9]	@ zero_extendqisi2
 617 0168 9DF80A20 		ldrb	r2, [sp, #10]	@ zero_extendqisi2
 618 016c 9DF80760 		ldrb	r6, [sp, #7]	@ zero_extendqisi2
 619 0170 5840     		eors	r0, r0, r3
 620 0172 9DF80530 		ldrb	r3, [sp, #5]	@ zero_extendqisi2
 621 0176 8DF80800 		strb	r0, [sp, #8]
 224:AES128.cpp    ****     KXOR(1, 0);
 622              		.loc 1 224 5 view .LVU137
 623 017a 5940     		eors	r1, r1, r3
 624 017c 9DF80630 		ldrb	r3, [sp, #6]	@ zero_extendqisi2
 625 0180 8DF80910 		strb	r1, [sp, #9]
 224:AES128.cpp    ****     KXOR(1, 0);
 626              		.loc 1 224 5 view .LVU138
 627 0184 5A40     		eors	r2, r2, r3
 628 0186 9DF80B30 		ldrb	r3, [sp, #11]	@ zero_extendqisi2
 629 018a 8DF80A20 		strb	r2, [sp, #10]
 224:AES128.cpp    ****     KXOR(1, 0);
 630              		.loc 1 224 5 view .LVU139
 631 018e 7340     		eors	r3, r3, r6
 225:AES128.cpp    ****     KXOR(2, 1);
 632              		.loc 1 225 5 is_stmt 0 view .LVU140
 633 0190 9DF80C60 		ldrb	r6, [sp, #12]	@ zero_extendqisi2
 224:AES128.cpp    ****     KXOR(1, 0);
 634              		.loc 1 224 5 view .LVU141
 635 0194 8DF80B30 		strb	r3, [sp, #11]
 225:AES128.cpp    ****     KXOR(2, 1);
 636              		.loc 1 225 5 is_stmt 1 view .LVU142
 225:AES128.cpp    ****     KXOR(2, 1);
 637              		.loc 1 225 5 view .LVU143
 638 0198 7040     		eors	r0, r0, r6
 639 019a 9DF80D60 		ldrb	r6, [sp, #13]	@ zero_extendqisi2
 640 019e 8DF80C00 		strb	r0, [sp, #12]
 225:AES128.cpp    ****     KXOR(2, 1);
 641              		.loc 1 225 5 view .LVU144
 642 01a2 7140     		eors	r1, r1, r6
 643 01a4 9DF80E60 		ldrb	r6, [sp, #14]	@ zero_extendqisi2
 644 01a8 8DF80D10 		strb	r1, [sp, #13]
 225:AES128.cpp    ****     KXOR(2, 1);
 645              		.loc 1 225 5 view .LVU145
 646 01ac 7240     		eors	r2, r2, r6
 647 01ae 9DF80F60 		ldrb	r6, [sp, #15]	@ zero_extendqisi2
 648 01b2 8DF80E20 		strb	r2, [sp, #14]
 225:AES128.cpp    ****     KXOR(2, 1);
 649              		.loc 1 225 5 view .LVU146
 650 01b6 7340     		eors	r3, r3, r6
 226:AES128.cpp    ****     KXOR(3, 2);
 651              		.loc 1 226 5 is_stmt 0 view .LVU147
 652 01b8 9DF81060 		ldrb	r6, [sp, #16]	@ zero_extendqisi2
 225:AES128.cpp    ****     KXOR(2, 1);
 653              		.loc 1 225 5 view .LVU148
 654 01bc 8DF80F30 		strb	r3, [sp, #15]
 226:AES128.cpp    ****     KXOR(3, 2);
 655              		.loc 1 226 5 is_stmt 1 view .LVU149
 226:AES128.cpp    ****     KXOR(3, 2);
 656              		.loc 1 226 5 view .LVU150
 657 01c0 7040     		eors	r0, r0, r6
 658 01c2 9DF81160 		ldrb	r6, [sp, #17]	@ zero_extendqisi2
 659 01c6 8DF81000 		strb	r0, [sp, #16]
 226:AES128.cpp    ****     KXOR(3, 2);
 660              		.loc 1 226 5 view .LVU151
 661 01ca 7140     		eors	r1, r1, r6
 662 01cc 9DF81260 		ldrb	r6, [sp, #18]	@ zero_extendqisi2
 663 01d0 8DF81110 		strb	r1, [sp, #17]
 226:AES128.cpp    ****     KXOR(3, 2);
 664              		.loc 1 226 5 view .LVU152
 665 01d4 7240     		eors	r2, r2, r6
 666 01d6 9DF81360 		ldrb	r6, [sp, #19]	@ zero_extendqisi2
 667 01da 8DF81220 		strb	r2, [sp, #18]
 226:AES128.cpp    ****     KXOR(3, 2);
 668              		.loc 1 226 5 view .LVU153
 669 01de 7340     		eors	r3, r3, r6
 227:AES128.cpp    **** 
 670              		.loc 1 227 5 is_stmt 0 view .LVU154
 671 01e0 9DF81460 		ldrb	r6, [sp, #20]	@ zero_extendqisi2
 226:AES128.cpp    ****     KXOR(3, 2);
 672              		.loc 1 226 5 view .LVU155
 673 01e4 8DF81330 		strb	r3, [sp, #19]
 227:AES128.cpp    **** 
 674              		.loc 1 227 5 is_stmt 1 view .LVU156
 227:AES128.cpp    **** 
 675              		.loc 1 227 5 view .LVU157
 676 01e8 7040     		eors	r0, r0, r6
 677 01ea 8DF81400 		strb	r0, [sp, #20]
 227:AES128.cpp    **** 
 678              		.loc 1 227 5 view .LVU158
 679 01ee 9DF81500 		ldrb	r0, [sp, #21]	@ zero_extendqisi2
 680 01f2 4140     		eors	r1, r1, r0
 681 01f4 8DF81510 		strb	r1, [sp, #21]
 227:AES128.cpp    **** 
 682              		.loc 1 227 5 view .LVU159
 683 01f8 9DF81610 		ldrb	r1, [sp, #22]	@ zero_extendqisi2
 684 01fc 4A40     		eors	r2, r2, r1
 685 01fe 8DF81620 		strb	r2, [sp, #22]
 227:AES128.cpp    **** 
 686              		.loc 1 227 5 view .LVU160
 687 0202 9DF81720 		ldrb	r2, [sp, #23]	@ zero_extendqisi2
 230:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 688              		.loc 1 230 36 is_stmt 0 view .LVU161
 689 0206 06A9     		add	r1, sp, #24
 227:AES128.cpp    **** 
 690              		.loc 1 227 5 view .LVU162
 691 0208 5340     		eors	r3, r3, r2
 230:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 692              		.loc 1 230 36 view .LVU163
 693 020a 0AA8     		add	r0, sp, #40
 227:AES128.cpp    **** 
 694              		.loc 1 227 5 view .LVU164
 695 020c 8DF81730 		strb	r3, [sp, #23]
 230:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 696              		.loc 1 230 5 is_stmt 1 view .LVU165
 230:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 697              		.loc 1 230 36 is_stmt 0 view .LVU166
 698 0210 FFF7FEFF 		bl	_ZN9AESCommon20subBytesAndShiftRowsEPhPKh
 699              	.LVL45:
 231:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 700              		.loc 1 231 25 is_stmt 1 view .LVU167
 701 0214 621E     		subs	r2, r4, #1
 702 0216 0AAB     		add	r3, sp, #40
 703 0218 0F34     		adds	r4, r4, #15
 704              	.LVL46:
 705              	.L21:
 232:AES128.cpp    **** }
 706              		.loc 1 232 9 discriminator 2 view .LVU168
 232:AES128.cpp    **** }
 707              		.loc 1 232 35 is_stmt 0 discriminator 2 view .LVU169
 708 021a 13F8011B 		ldrb	r1, [r3], #1	@ zero_extendqisi2
 709              	.LVL47:
 232:AES128.cpp    **** }
 710              		.loc 1 232 52 discriminator 2 view .LVU170
 711 021e 15F8010B 		ldrb	r0, [r5], #1	@ zero_extendqisi2
 232:AES128.cpp    **** }
 712              		.loc 1 232 37 discriminator 2 view .LVU171
 713 0222 4140     		eors	r1, r1, r0
 232:AES128.cpp    **** }
 714              		.loc 1 232 22 discriminator 2 view .LVU172
 715 0224 02F8011F 		strb	r1, [r2, #1]!
 231:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 716              		.loc 1 231 5 is_stmt 1 discriminator 2 view .LVU173
 717              	.LVL48:
 231:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 718              		.loc 1 231 25 discriminator 2 view .LVU174
 719 0228 A242     		cmp	r2, r4
 720 022a F6D1     		bne	.L21
 233:AES128.cpp    **** 
 721              		.loc 1 233 1 is_stmt 0 view .LVU175
 722 022c 0EB0     		add	sp, sp, #56
 723              	.LCFI6:
 724              		.cfi_def_cfa_offset 24
 725              		@ sp needed
 726 022e BDE8F081 		pop	{r4, r5, r6, r7, r8, pc}
 233:AES128.cpp    **** 
 727              		.loc 1 233 1 view .LVU176
 728              		.cfi_endproc
 729              	.LFE20:
 730              		.fnend
 732              		.section	.text._ZN11AESSmall12812decryptBlockEPhPKh,"ax",%progbits
 733              		.align	1
 734              		.global	_ZN11AESSmall12812decryptBlockEPhPKh
 735              		.syntax unified
 736              		.thumb
 737              		.thumb_func
 738              		.fpu softvfp
 740              	_ZN11AESSmall12812decryptBlockEPhPKh:
 741              		.fnstart
 742              	.LVL49:
 743              	.LFB31:
 239:AES128.cpp    **** 
 240:AES128.cpp    **** void AESTiny128::clear()
 241:AES128.cpp    **** {
 242:AES128.cpp    ****     clean(schedule);
 243:AES128.cpp    **** }
 244:AES128.cpp    **** 
 245:AES128.cpp    **** /**
 246:AES128.cpp    ****  * \class AESSmall128 AES.h <AES.h>
 247:AES128.cpp    ****  * \brief AES block cipher with 128-bit keys and reduced memory usage.
 248:AES128.cpp    ****  *
 249:AES128.cpp    ****  * This class differs from the AES128 class in that the RAM requirements are
 250:AES128.cpp    ****  * vastly reduced.  The key schedule is expanded round by round instead of
 251:AES128.cpp    ****  * being generated and stored by setKey().  The performance of encryption
 252:AES128.cpp    ****  * and decryption is slightly less because of this.
 253:AES128.cpp    ****  *
 254:AES128.cpp    ****  * This class is useful when RAM is at a premium and reduced encryption
 255:AES128.cpp    ****  * performance is not a hindrance to the application.
 256:AES128.cpp    ****  *
 257:AES128.cpp    ****  * The companion AESTiny128 class uses even less RAM but only supports the
 258:AES128.cpp    ****  * encryptBlock() operation.  Block cipher modes like CTR, EAX, and GCM
 259:AES128.cpp    ****  * do not need the decryptBlock() operation, so AESTiny128 may be a better
 260:AES128.cpp    ****  * option than AESSmall128 for many applications.
 261:AES128.cpp    ****  *
 262:AES128.cpp    ****  * \sa AESTiny128, AES128
 263:AES128.cpp    ****  */
 264:AES128.cpp    **** 
 265:AES128.cpp    **** /**
 266:AES128.cpp    ****  * \brief Constructs an AES 128-bit block cipher with no initial key.
 267:AES128.cpp    ****  *
 268:AES128.cpp    ****  * This constructor must be followed by a call to setKey() before the
 269:AES128.cpp    ****  * block cipher can be used for encryption or decryption.
 270:AES128.cpp    ****  */
 271:AES128.cpp    **** AESSmall128::AESSmall128()
 272:AES128.cpp    **** {
 273:AES128.cpp    **** }
 274:AES128.cpp    **** 
 275:AES128.cpp    **** AESSmall128::~AESSmall128()
 276:AES128.cpp    **** {
 277:AES128.cpp    ****     clean(reverse);
 278:AES128.cpp    **** }
 279:AES128.cpp    **** 
 280:AES128.cpp    **** bool AESSmall128::setKey(const uint8_t *key, size_t len)
 281:AES128.cpp    **** {
 282:AES128.cpp    ****     uint8_t *schedule;
 283:AES128.cpp    ****     uint8_t round;
 284:AES128.cpp    ****     uint8_t temp[4];
 285:AES128.cpp    **** 
 286:AES128.cpp    ****     // Set the encryption key first.
 287:AES128.cpp    ****     if (!AESTiny128::setKey(key, len))
 288:AES128.cpp    ****         return false;
 289:AES128.cpp    **** 
 290:AES128.cpp    ****     // Expand the key schedule up to the last round which gives
 291:AES128.cpp    ****     // us the round keys to use for the final two rounds.  We can
 292:AES128.cpp    ****     // then work backwards from there in decryptBlock().
 293:AES128.cpp    ****     schedule = reverse;
 294:AES128.cpp    ****     memcpy(schedule, key, 16);
 295:AES128.cpp    ****     for (round = 1; round <= 10; ++round) {
 296:AES128.cpp    ****         KCORE(round);
 297:AES128.cpp    ****         KXOR(1, 0);
 298:AES128.cpp    ****         KXOR(2, 1);
 299:AES128.cpp    ****         KXOR(3, 2);
 300:AES128.cpp    ****     }
 301:AES128.cpp    **** 
 302:AES128.cpp    ****     // Key is ready to go.
 303:AES128.cpp    ****     return true;
 304:AES128.cpp    **** }
 305:AES128.cpp    **** 
 306:AES128.cpp    **** void AESSmall128::decryptBlock(uint8_t *output, const uint8_t *input)
 307:AES128.cpp    **** {
 744              		.loc 1 307 1 is_stmt 1 view -0
 745              		.cfi_startproc
 746              		@ args = 0, pretend = 0, frame = 56
 747              		@ frame_needed = 0, uses_anonymous_args = 0
 748              		.loc 1 307 1 is_stmt 0 view .LVU178
 749 0000 2DE9F043 		push	{r4, r5, r6, r7, r8, r9, lr}
 750              		.save {r4, r5, r6, r7, r8, r9, lr}
 751              	.LCFI7:
 752              		.cfi_def_cfa_offset 28
 753              		.cfi_offset 4, -28
 754              		.cfi_offset 5, -24
 755              		.cfi_offset 6, -20
 756              		.cfi_offset 7, -16
 757              		.cfi_offset 8, -12
 758              		.cfi_offset 9, -8
 759              		.cfi_offset 14, -4
 760              		.pad #60
 761 0004 8FB0     		sub	sp, sp, #60
 762              	.LCFI8:
 763              		.cfi_def_cfa_offset 88
 308:AES128.cpp    ****     uint8_t schedule[16];
 309:AES128.cpp    ****     uint8_t round;
 310:AES128.cpp    ****     uint8_t posn;
 311:AES128.cpp    ****     uint8_t state1[16];
 312:AES128.cpp    ****     uint8_t state2[16];
 313:AES128.cpp    ****     uint8_t temp[4];
 314:AES128.cpp    **** 
 315:AES128.cpp    ****     // Start with the end of the decryption schedule.
 316:AES128.cpp    ****     memcpy(schedule, reverse, 16);
 764              		.loc 1 316 11 view .LVU179
 765 0006 02AF     		add	r7, sp, #8
 307:AES128.cpp    ****     uint8_t schedule[16];
 766              		.loc 1 307 1 view .LVU180
 767 0008 0C46     		mov	r4, r1
 308:AES128.cpp    ****     uint8_t schedule[16];
 768              		.loc 1 308 5 is_stmt 1 view .LVU181
 309:AES128.cpp    ****     uint8_t posn;
 769              		.loc 1 309 5 view .LVU182
 310:AES128.cpp    ****     uint8_t state1[16];
 770              		.loc 1 310 5 view .LVU183
 311:AES128.cpp    ****     uint8_t state2[16];
 771              		.loc 1 311 5 view .LVU184
 312:AES128.cpp    ****     uint8_t temp[4];
 772              		.loc 1 312 5 view .LVU185
 313:AES128.cpp    **** 
 773              		.loc 1 313 5 view .LVU186
 774              		.loc 1 316 5 view .LVU187
 775              		.loc 1 316 11 is_stmt 0 view .LVU188
 776 000a 00F11405 		add	r5, r0, #20
 777 000e 00F12403 		add	r3, r0, #36
 778 0012 3E46     		mov	r6, r7
 779              	.LVL50:
 780              	.L28:
 781              		.loc 1 316 11 view .LVU189
 782 0014 2868     		ldr	r0, [r5]	@ unaligned
 783 0016 6968     		ldr	r1, [r5, #4]	@ unaligned
 784 0018 BC46     		mov	ip, r7
 785 001a ACE80300 		stmia	ip!, {r0, r1}
 786 001e 0835     		adds	r5, r5, #8
 787 0020 9D42     		cmp	r5, r3
 788 0022 6746     		mov	r7, ip
 789 0024 F6D1     		bne	.L28
 317:AES128.cpp    **** 
 318:AES128.cpp    ****     // Copy the input into the state and reverse the final round.
 319:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 790              		.loc 1 319 5 is_stmt 1 view .LVU190
 791              	.LVL51:
 792              		.loc 1 319 25 view .LVU191
 793 0026 06A9     		add	r1, sp, #24
 794 0028 531E     		subs	r3, r2, #1
 795              	.LVL52:
 796              		.loc 1 319 25 is_stmt 0 view .LVU192
 797 002a 3746     		mov	r7, r6
 798 002c 0F32     		adds	r2, r2, #15
 799              	.LVL53:
 316:AES128.cpp    **** 
 800              		.loc 1 316 11 view .LVU193
 801 002e 3546     		mov	r5, r6
 802 0030 8846     		mov	r8, r1
 803              	.LVL54:
 804              	.L29:
 320:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 805              		.loc 1 320 9 is_stmt 1 discriminator 2 view .LVU194
 806              		.loc 1 320 36 is_stmt 0 discriminator 2 view .LVU195
 807 0032 13F801CF 		ldrb	ip, [r3, #1]!	@ zero_extendqisi2
 808              	.LVL55:
 809              		.loc 1 320 51 discriminator 2 view .LVU196
 810 0036 15F8010B 		ldrb	r0, [r5], #1	@ zero_extendqisi2
 319:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 811              		.loc 1 319 25 discriminator 2 view .LVU197
 812 003a 9342     		cmp	r3, r2
 813              		.loc 1 320 36 discriminator 2 view .LVU198
 814 003c 80EA0C00 		eor	r0, r0, ip
 815              		.loc 1 320 22 discriminator 2 view .LVU199
 816 0040 01F8010B 		strb	r0, [r1], #1
 319:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 817              		.loc 1 319 5 is_stmt 1 discriminator 2 view .LVU200
 818              	.LVL56:
 319:AES128.cpp    ****         state1[posn] = input[posn] ^ schedule[posn];
 819              		.loc 1 319 25 discriminator 2 view .LVU201
 820 0044 F5D1     		bne	.L29
 321:AES128.cpp    ****     AESCommon::inverseShiftRowsAndSubBytes(state2, state1);
 821              		.loc 1 321 5 view .LVU202
 822              		.loc 1 321 43 is_stmt 0 view .LVU203
 823 0046 4146     		mov	r1, r8
 824 0048 0AA8     		add	r0, sp, #40
 825 004a FFF7FEFF 		bl	_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
 826              	.LVL57:
 322:AES128.cpp    ****     KXOR(3, 2);
 827              		.loc 1 322 5 is_stmt 1 view .LVU204
 828              		.loc 1 322 5 view .LVU205
 829 004e 9DF81010 		ldrb	r1, [sp, #16]	@ zero_extendqisi2
 830 0052 9DF81430 		ldrb	r3, [sp, #20]	@ zero_extendqisi2
 831 0056 9DF81120 		ldrb	r2, [sp, #17]	@ zero_extendqisi2
 832 005a 9DF81600 		ldrb	r0, [sp, #22]	@ zero_extendqisi2
 833 005e 9DF81350 		ldrb	r5, [sp, #19]	@ zero_extendqisi2
 834 0062 4B40     		eors	r3, r3, r1
 835 0064 8DF81430 		strb	r3, [sp, #20]
 836              		.loc 1 322 5 view .LVU206
 837 0068 9DF81530 		ldrb	r3, [sp, #21]	@ zero_extendqisi2
 838 006c 5340     		eors	r3, r3, r2
 839 006e 8DF81530 		strb	r3, [sp, #21]
 840              		.loc 1 322 5 view .LVU207
 841 0072 9DF81230 		ldrb	r3, [sp, #18]	@ zero_extendqisi2
 842 0076 5840     		eors	r0, r0, r3
 843 0078 8DF81600 		strb	r0, [sp, #22]
 844              		.loc 1 322 5 view .LVU208
 845 007c 9DF81700 		ldrb	r0, [sp, #23]	@ zero_extendqisi2
 846 0080 6840     		eors	r0, r0, r5
 847 0082 8DF81700 		strb	r0, [sp, #23]
 323:AES128.cpp    ****     KXOR(2, 1);
 848              		.loc 1 323 5 view .LVU209
 849              		.loc 1 323 5 view .LVU210
 850 0086 9DF80C00 		ldrb	r0, [sp, #12]	@ zero_extendqisi2
 851 008a 4140     		eors	r1, r1, r0
 852 008c 8DF81010 		strb	r1, [sp, #16]
 853              		.loc 1 323 5 view .LVU211
 854 0090 9DF80D10 		ldrb	r1, [sp, #13]	@ zero_extendqisi2
 855 0094 4A40     		eors	r2, r2, r1
 856 0096 8DF81120 		strb	r2, [sp, #17]
 857              		.loc 1 323 5 view .LVU212
 858 009a 9DF80E20 		ldrb	r2, [sp, #14]	@ zero_extendqisi2
 859 009e 5340     		eors	r3, r3, r2
 860 00a0 8DF81230 		strb	r3, [sp, #18]
 861              		.loc 1 323 5 view .LVU213
 862 00a4 9DF80F30 		ldrb	r3, [sp, #15]	@ zero_extendqisi2
 863 00a8 5D40     		eors	r5, r5, r3
 864 00aa 8DF81350 		strb	r5, [sp, #19]
 324:AES128.cpp    ****     KXOR(1, 0);
 865              		.loc 1 324 5 view .LVU214
 866              		.loc 1 324 5 view .LVU215
 867 00ae 9DF80850 		ldrb	r5, [sp, #8]	@ zero_extendqisi2
 868 00b2 6840     		eors	r0, r0, r5
 869 00b4 8DF80C00 		strb	r0, [sp, #12]
 870              		.loc 1 324 5 view .LVU216
 871 00b8 9DF80900 		ldrb	r0, [sp, #9]	@ zero_extendqisi2
 872 00bc 4140     		eors	r1, r1, r0
 873 00be 8DF80D10 		strb	r1, [sp, #13]
 874              		.loc 1 324 5 view .LVU217
 875 00c2 9DF80A10 		ldrb	r1, [sp, #10]	@ zero_extendqisi2
 876 00c6 4A40     		eors	r2, r2, r1
 877 00c8 8DF80E20 		strb	r2, [sp, #14]
 878              		.loc 1 324 5 view .LVU218
 879 00cc 9DF80B20 		ldrb	r2, [sp, #11]	@ zero_extendqisi2
 325:AES128.cpp    ****     KCORE(10);
 880              		.loc 1 325 5 is_stmt 0 view .LVU219
 881 00d0 05A9     		add	r1, sp, #20
 324:AES128.cpp    ****     KXOR(1, 0);
 882              		.loc 1 324 5 view .LVU220
 883 00d2 5340     		eors	r3, r3, r2
 884              		.loc 1 325 5 view .LVU221
 885 00d4 01A8     		add	r0, sp, #4
 886 00d6 0A22     		movs	r2, #10
 324:AES128.cpp    ****     KXOR(1, 0);
 887              		.loc 1 324 5 view .LVU222
 888 00d8 8DF80F30 		strb	r3, [sp, #15]
 889              		.loc 1 325 5 is_stmt 1 view .LVU223
 890              		.loc 1 325 5 view .LVU224
 891 00dc FFF7FEFF 		bl	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 892              	.LVL58:
 893              		.loc 1 325 5 view .LVU225
 894 00e0 9DF80830 		ldrb	r3, [sp, #8]	@ zero_extendqisi2
 895 00e4 9DF80420 		ldrb	r2, [sp, #4]	@ zero_extendqisi2
 896 00e8 5340     		eors	r3, r3, r2
 897 00ea 8DF80830 		strb	r3, [sp, #8]
 898              		.loc 1 325 5 view .LVU226
 899 00ee 9DF80520 		ldrb	r2, [sp, #5]	@ zero_extendqisi2
 900 00f2 9DF80930 		ldrb	r3, [sp, #9]	@ zero_extendqisi2
 901 00f6 5340     		eors	r3, r3, r2
 902 00f8 8DF80930 		strb	r3, [sp, #9]
 903              		.loc 1 325 5 view .LVU227
 904 00fc 9DF80620 		ldrb	r2, [sp, #6]	@ zero_extendqisi2
 905 0100 9DF80A30 		ldrb	r3, [sp, #10]	@ zero_extendqisi2
 906 0104 5340     		eors	r3, r3, r2
 907 0106 8DF80A30 		strb	r3, [sp, #10]
 908              		.loc 1 325 5 view .LVU228
 909 010a 9DF80720 		ldrb	r2, [sp, #7]	@ zero_extendqisi2
 910 010e 9DF80B30 		ldrb	r3, [sp, #11]	@ zero_extendqisi2
 911 0112 5340     		eors	r3, r3, r2
 912 0114 8DF80B30 		strb	r3, [sp, #11]
 326:AES128.cpp    **** 
 327:AES128.cpp    ****     // Perform the next 9 rounds of the decryption process.
 328:AES128.cpp    ****     for (round = 9; round >= 1; --round) {
 913              		.loc 1 328 5 view .LVU229
 914              	.LVL59:
 915              		.loc 1 328 27 view .LVU230
 916              		.loc 1 328 16 is_stmt 0 view .LVU231
 917 0118 0925     		movs	r5, #9
 918              	.LVL60:
 919              	.L31:
 329:AES128.cpp    ****         // Decrypt using the key schedule.
 330:AES128.cpp    ****         for (posn = 0; posn < 16; ++posn)
 920              		.loc 1 330 29 is_stmt 1 view .LVU232
 921 011a 0DF12809 		add	r9, sp, #40
 328:AES128.cpp    ****         // Decrypt using the key schedule.
 922              		.loc 1 328 16 is_stmt 0 view .LVU233
 923 011e 3046     		mov	r0, r6
 924 0120 4A46     		mov	r2, r9
 925 0122 1023     		movs	r3, #16
 926              	.LVL61:
 927              	.L30:
 331:AES128.cpp    ****             state2[posn] ^= schedule[posn];
 928              		.loc 1 331 13 is_stmt 1 discriminator 2 view .LVU234
 929              		.loc 1 331 26 is_stmt 0 discriminator 2 view .LVU235
 930 0124 1178     		ldrb	r1, [r2]	@ zero_extendqisi2
 931              		.loc 1 331 42 discriminator 2 view .LVU236
 932 0126 10F801CB 		ldrb	ip, [r0], #1	@ zero_extendqisi2
 330:AES128.cpp    ****             state2[posn] ^= schedule[posn];
 933              		.loc 1 330 29 discriminator 2 view .LVU237
 934 012a 013B     		subs	r3, r3, #1
 935              		.loc 1 331 26 discriminator 2 view .LVU238
 936 012c 81EA0C01 		eor	r1, r1, ip
 330:AES128.cpp    ****             state2[posn] ^= schedule[posn];
 937              		.loc 1 330 29 discriminator 2 view .LVU239
 938 0130 13F0FF03 		ands	r3, r3, #255
 939              		.loc 1 331 26 discriminator 2 view .LVU240
 940 0134 02F8011B 		strb	r1, [r2], #1
 941              	.LVL62:
 330:AES128.cpp    ****             state2[posn] ^= schedule[posn];
 942              		.loc 1 330 9 is_stmt 1 discriminator 2 view .LVU241
 330:AES128.cpp    ****             state2[posn] ^= schedule[posn];
 943              		.loc 1 330 29 discriminator 2 view .LVU242
 944 0138 F4D1     		bne	.L30
 332:AES128.cpp    ****         AESCommon::inverseMixColumn(state1,      state2);
 945              		.loc 1 332 9 view .LVU243
 946              		.loc 1 332 36 is_stmt 0 view .LVU244
 947 013a 0AA9     		add	r1, sp, #40
 948 013c 4046     		mov	r0, r8
 949 013e FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 950              	.LVL63:
 333:AES128.cpp    ****         AESCommon::inverseMixColumn(state1 + 4,  state2 + 4);
 951              		.loc 1 333 9 is_stmt 1 view .LVU245
 952              		.loc 1 333 36 is_stmt 0 view .LVU246
 953 0142 0BA9     		add	r1, sp, #44
 954 0144 07A8     		add	r0, sp, #28
 955 0146 FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 956              	.LVL64:
 334:AES128.cpp    ****         AESCommon::inverseMixColumn(state1 + 8,  state2 + 8);
 957              		.loc 1 334 9 is_stmt 1 view .LVU247
 958              		.loc 1 334 36 is_stmt 0 view .LVU248
 959 014a 0CA9     		add	r1, sp, #48
 960 014c 08A8     		add	r0, sp, #32
 961 014e FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 962              	.LVL65:
 335:AES128.cpp    ****         AESCommon::inverseMixColumn(state1 + 12, state2 + 12);
 963              		.loc 1 335 9 is_stmt 1 view .LVU249
 964              		.loc 1 335 36 is_stmt 0 view .LVU250
 965 0152 0DA9     		add	r1, sp, #52
 966 0154 09A8     		add	r0, sp, #36
 967 0156 FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 968              	.LVL66:
 336:AES128.cpp    ****         AESCommon::inverseShiftRowsAndSubBytes(state2, state1);
 969              		.loc 1 336 9 is_stmt 1 view .LVU251
 970              		.loc 1 336 47 is_stmt 0 view .LVU252
 971 015a 4146     		mov	r1, r8
 972 015c 0AA8     		add	r0, sp, #40
 973 015e FFF7FEFF 		bl	_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
 974              	.LVL67:
 337:AES128.cpp    **** 
 338:AES128.cpp    ****         // Expand the next 16 bytes of the key schedule in reverse.
 339:AES128.cpp    ****         KXOR(3, 2);
 975              		.loc 1 339 9 is_stmt 1 view .LVU253
 976              		.loc 1 339 9 view .LVU254
 977 0162 9DF81010 		ldrb	r1, [sp, #16]	@ zero_extendqisi2
 978 0166 9DF81430 		ldrb	r3, [sp, #20]	@ zero_extendqisi2
 979 016a 9DF81120 		ldrb	r2, [sp, #17]	@ zero_extendqisi2
 980 016e 9DF81600 		ldrb	r0, [sp, #22]	@ zero_extendqisi2
 981 0172 9DF813C0 		ldrb	ip, [sp, #19]	@ zero_extendqisi2
 982 0176 4B40     		eors	r3, r3, r1
 983 0178 8DF81430 		strb	r3, [sp, #20]
 984              		.loc 1 339 9 view .LVU255
 985 017c 9DF81530 		ldrb	r3, [sp, #21]	@ zero_extendqisi2
 986 0180 5340     		eors	r3, r3, r2
 987 0182 8DF81530 		strb	r3, [sp, #21]
 988              		.loc 1 339 9 view .LVU256
 989 0186 9DF81230 		ldrb	r3, [sp, #18]	@ zero_extendqisi2
 990 018a 5840     		eors	r0, r0, r3
 991 018c 8DF81600 		strb	r0, [sp, #22]
 992              		.loc 1 339 9 view .LVU257
 993 0190 9DF81700 		ldrb	r0, [sp, #23]	@ zero_extendqisi2
 994 0194 8CEA0000 		eor	r0, ip, r0
 995 0198 8DF81700 		strb	r0, [sp, #23]
 340:AES128.cpp    ****         KXOR(2, 1);
 996              		.loc 1 340 9 view .LVU258
 997              		.loc 1 340 9 view .LVU259
 998 019c 9DF80C00 		ldrb	r0, [sp, #12]	@ zero_extendqisi2
 999 01a0 4140     		eors	r1, r1, r0
 1000 01a2 8DF81010 		strb	r1, [sp, #16]
 1001              		.loc 1 340 9 view .LVU260
 1002 01a6 9DF80D10 		ldrb	r1, [sp, #13]	@ zero_extendqisi2
 1003 01aa 4A40     		eors	r2, r2, r1
 1004 01ac 8DF81120 		strb	r2, [sp, #17]
 1005              		.loc 1 340 9 view .LVU261
 1006 01b0 9DF80E20 		ldrb	r2, [sp, #14]	@ zero_extendqisi2
 1007 01b4 5340     		eors	r3, r3, r2
 1008 01b6 8DF81230 		strb	r3, [sp, #18]
 1009              		.loc 1 340 9 view .LVU262
 1010 01ba 9DF80F30 		ldrb	r3, [sp, #15]	@ zero_extendqisi2
 1011 01be 8CEA030C 		eor	ip, ip, r3
 1012 01c2 8DF813C0 		strb	ip, [sp, #19]
 341:AES128.cpp    ****         KXOR(1, 0);
 1013              		.loc 1 341 9 view .LVU263
 1014              		.loc 1 341 9 view .LVU264
 1015 01c6 9DF808C0 		ldrb	ip, [sp, #8]	@ zero_extendqisi2
 1016 01ca 80EA0C00 		eor	r0, r0, ip
 1017 01ce 8DF80C00 		strb	r0, [sp, #12]
 1018              		.loc 1 341 9 view .LVU265
 1019 01d2 9DF80900 		ldrb	r0, [sp, #9]	@ zero_extendqisi2
 1020 01d6 4140     		eors	r1, r1, r0
 1021 01d8 8DF80D10 		strb	r1, [sp, #13]
 1022              		.loc 1 341 9 view .LVU266
 1023 01dc 9DF80A10 		ldrb	r1, [sp, #10]	@ zero_extendqisi2
 1024 01e0 4A40     		eors	r2, r2, r1
 1025 01e2 8DF80E20 		strb	r2, [sp, #14]
 1026              		.loc 1 341 9 view .LVU267
 1027 01e6 9DF80B20 		ldrb	r2, [sp, #11]	@ zero_extendqisi2
 342:AES128.cpp    ****         KCORE(round);
 1028              		.loc 1 342 9 is_stmt 0 view .LVU268
 1029 01ea 05A9     		add	r1, sp, #20
 341:AES128.cpp    ****         KXOR(1, 0);
 1030              		.loc 1 341 9 view .LVU269
 1031 01ec 5340     		eors	r3, r3, r2
 1032              		.loc 1 342 9 view .LVU270
 1033 01ee 01A8     		add	r0, sp, #4
 1034 01f0 2A46     		mov	r2, r5
 341:AES128.cpp    ****         KXOR(1, 0);
 1035              		.loc 1 341 9 view .LVU271
 1036 01f2 8DF80F30 		strb	r3, [sp, #15]
 1037              		.loc 1 342 9 is_stmt 1 view .LVU272
 1038              		.loc 1 342 9 view .LVU273
 1039 01f6 FFF7FEFF 		bl	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 1040              	.LVL68:
 1041              		.loc 1 342 9 view .LVU274
 1042 01fa 9DF80830 		ldrb	r3, [sp, #8]	@ zero_extendqisi2
 1043 01fe 9DF80420 		ldrb	r2, [sp, #4]	@ zero_extendqisi2
 1044 0202 5340     		eors	r3, r3, r2
 1045 0204 8DF80830 		strb	r3, [sp, #8]
 1046              		.loc 1 342 9 view .LVU275
 1047 0208 9DF80520 		ldrb	r2, [sp, #5]	@ zero_extendqisi2
 1048 020c 9DF80930 		ldrb	r3, [sp, #9]	@ zero_extendqisi2
 1049 0210 5340     		eors	r3, r3, r2
 1050 0212 8DF80930 		strb	r3, [sp, #9]
 1051              		.loc 1 342 9 view .LVU276
 1052 0216 9DF80620 		ldrb	r2, [sp, #6]	@ zero_extendqisi2
 1053 021a 9DF80A30 		ldrb	r3, [sp, #10]	@ zero_extendqisi2
 1054 021e 5340     		eors	r3, r3, r2
 1055 0220 8DF80A30 		strb	r3, [sp, #10]
 1056              		.loc 1 342 9 view .LVU277
 1057 0224 9DF80720 		ldrb	r2, [sp, #7]	@ zero_extendqisi2
 1058 0228 9DF80B30 		ldrb	r3, [sp, #11]	@ zero_extendqisi2
 328:AES128.cpp    ****         // Decrypt using the key schedule.
 1059              		.loc 1 328 5 is_stmt 0 view .LVU278
 1060 022c 013D     		subs	r5, r5, #1
 1061              	.LVL69:
 1062              		.loc 1 342 9 view .LVU279
 1063 022e 5340     		eors	r3, r3, r2
 328:AES128.cpp    ****         // Decrypt using the key schedule.
 1064              		.loc 1 328 27 view .LVU280
 1065 0230 15F0FF05 		ands	r5, r5, #255
 1066              		.loc 1 342 9 view .LVU281
 1067 0234 8DF80B30 		strb	r3, [sp, #11]
 328:AES128.cpp    ****         // Decrypt using the key schedule.
 1068              		.loc 1 328 5 is_stmt 1 view .LVU282
 328:AES128.cpp    ****         // Decrypt using the key schedule.
 1069              		.loc 1 328 27 view .LVU283
 1070 0238 7FF46FAF 		bne	.L31
 1071 023c 631E     		subs	r3, r4, #1
 1072 023e 0F34     		adds	r4, r4, #15
 1073              	.LVL70:
 1074              	.L32:
 343:AES128.cpp    ****     }
 344:AES128.cpp    **** 
 345:AES128.cpp    ****     // Reverse the initial round and create the output words.
 346:AES128.cpp    ****     for (posn = 0; posn < 16; ++posn)
 347:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 1075              		.loc 1 347 9 discriminator 2 view .LVU284
 1076              		.loc 1 347 35 is_stmt 0 discriminator 2 view .LVU285
 1077 0240 19F8012B 		ldrb	r2, [r9], #1	@ zero_extendqisi2
 1078              	.LVL71:
 1079              		.loc 1 347 52 discriminator 2 view .LVU286
 1080 0244 17F8011B 		ldrb	r1, [r7], #1	@ zero_extendqisi2
 1081              		.loc 1 347 37 discriminator 2 view .LVU287
 1082 0248 4A40     		eors	r2, r2, r1
 1083              		.loc 1 347 22 discriminator 2 view .LVU288
 1084 024a 03F8012F 		strb	r2, [r3, #1]!
 346:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 1085              		.loc 1 346 5 is_stmt 1 discriminator 2 view .LVU289
 1086              	.LVL72:
 346:AES128.cpp    ****         output[posn] = state2[posn] ^ schedule[posn];
 1087              		.loc 1 346 25 discriminator 2 view .LVU290
 1088 024e A342     		cmp	r3, r4
 1089 0250 F6D1     		bne	.L32
 348:AES128.cpp    **** }
 1090              		.loc 1 348 1 is_stmt 0 view .LVU291
 1091 0252 0FB0     		add	sp, sp, #60
 1092              	.LCFI9:
 1093              		.cfi_def_cfa_offset 28
 1094              		@ sp needed
 1095 0254 BDE8F083 		pop	{r4, r5, r6, r7, r8, r9, pc}
 1096              		.loc 1 348 1 view .LVU292
 1097              		.cfi_endproc
 1098              	.LFE31:
 1099              		.fnend
 1101              		.section	.text._ZN6AES1286setKeyEPKhj,"ax",%progbits
 1102              		.align	1
 1103              		.global	_ZN6AES1286setKeyEPKhj
 1104              		.syntax unified
 1105              		.thumb
 1106              		.thumb_func
 1107              		.fpu softvfp
 1109              	_ZN6AES1286setKeyEPKhj:
 1110              		.fnstart
 1111              	.LVL73:
 1112              	.LFB9:
  63:AES128.cpp    ****     if (len != 16)
 1113              		.loc 1 63 1 is_stmt 1 view -0
 1114              		.cfi_startproc
 1115              		@ args = 0, pretend = 0, frame = 0
 1116              		@ frame_needed = 0, uses_anonymous_args = 0
  64:AES128.cpp    ****         return false;
 1117              		.loc 1 64 5 view .LVU294
 1118 0000 102A     		cmp	r2, #16
  63:AES128.cpp    ****     if (len != 16)
 1119              		.loc 1 63 1 is_stmt 0 view .LVU295
 1120 0002 F8B5     		push	{r3, r4, r5, r6, r7, lr}
 1121              		.save {r3, r4, r5, r6, r7, lr}
 1122              	.LCFI10:
 1123              		.cfi_def_cfa_offset 24
 1124              		.cfi_offset 3, -24
 1125              		.cfi_offset 4, -20
 1126              		.cfi_offset 5, -16
 1127              		.cfi_offset 6, -12
 1128              		.cfi_offset 7, -8
 1129              		.cfi_offset 14, -4
  64:AES128.cpp    ****         return false;
 1130              		.loc 1 64 5 view .LVU296
 1131 0004 4BD1     		bne	.L44
 1132              	.LVL74:
 1133              	.LBB24:
 1134              	.LBI24:
  62:AES128.cpp    **** {
 1135              		.loc 1 62 6 is_stmt 1 view .LVU297
 1136              	.LBB25:
  68:AES128.cpp    ****     memcpy(schedule, key, 16);
 1137              		.loc 1 68 5 view .LVU298
  69:AES128.cpp    **** 
 1138              		.loc 1 69 5 view .LVU299
  69:AES128.cpp    **** 
 1139              		.loc 1 69 11 is_stmt 0 view .LVU300
 1140 0006 00F10C03 		add	r3, r0, #12
 1141 000a 01F11002 		add	r2, r1, #16
 1142              	.LVL75:
 1143              	.L40:
  69:AES128.cpp    **** 
 1144              		.loc 1 69 11 view .LVU301
 1145 000e 51F8044B 		ldr	r4, [r1], #4	@ unaligned
 1146 0012 43F8044B 		str	r4, [r3], #4	@ unaligned
 1147 0016 9142     		cmp	r1, r2
 1148 0018 F9D1     		bne	.L40
  72:AES128.cpp    ****     uint8_t n = 16;
 1149              		.loc 1 72 5 is_stmt 1 view .LVU302
 1150              	.LVL76:
  73:AES128.cpp    ****     uint8_t w = 4;
 1151              		.loc 1 73 5 view .LVU303
  74:AES128.cpp    ****     while (n < 176) {
 1152              		.loc 1 74 5 view .LVU304
  75:AES128.cpp    ****         if (w == 4) {
 1153              		.loc 1 75 5 view .LVU305
  75:AES128.cpp    ****         if (w == 4) {
 1154              		.loc 1 75 14 view .LVU306
 1155 001a 00F11804 		add	r4, r0, #24
 1156 001e 00F1B806 		add	r6, r0, #184
  72:AES128.cpp    ****     uint8_t n = 16;
 1157              		.loc 1 72 13 is_stmt 0 view .LVU307
 1158 0022 0125     		movs	r5, #1
  74:AES128.cpp    ****     while (n < 176) {
 1159              		.loc 1 74 13 view .LVU308
 1160 0024 0423     		movs	r3, #4
 1161              	.LVL77:
 1162              	.L43:
  76:AES128.cpp    ****             // Every 16 bytes (4 words) we need to apply the key schedule core.
 1163              		.loc 1 76 9 is_stmt 1 view .LVU309
 1164 0026 042B     		cmp	r3, #4
 1165 0028 04F10407 		add	r7, r4, #4
 1166 002c 22D1     		bne	.L41
 1167              	.LVL78:
  78:AES128.cpp    ****             schedule[16] ^= schedule[0];
 1168              		.loc 1 78 13 view .LVU310
  78:AES128.cpp    ****             schedule[16] ^= schedule[0];
 1169              		.loc 1 78 28 is_stmt 0 view .LVU311
 1170 002e 2A46     		mov	r2, r5
 1171 0030 2146     		mov	r1, r4
 1172 0032 3846     		mov	r0, r7
 1173 0034 FFF7FEFF 		bl	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 1174              	.LVL79:
  79:AES128.cpp    ****             schedule[17] ^= schedule[1];
 1175              		.loc 1 79 13 is_stmt 1 view .LVU312
  79:AES128.cpp    ****             schedule[17] ^= schedule[1];
 1176              		.loc 1 79 26 is_stmt 0 view .LVU313
 1177 0038 2379     		ldrb	r3, [r4, #4]	@ zero_extendqisi2
 1178 003a 14F80C2C 		ldrb	r2, [r4, #-12]	@ zero_extendqisi2
 1179 003e 5340     		eors	r3, r3, r2
 1180 0040 2371     		strb	r3, [r4, #4]
  80:AES128.cpp    ****             schedule[18] ^= schedule[2];
 1181              		.loc 1 80 13 is_stmt 1 view .LVU314
  80:AES128.cpp    ****             schedule[18] ^= schedule[2];
 1182              		.loc 1 80 26 is_stmt 0 view .LVU315
 1183 0042 14F80B2C 		ldrb	r2, [r4, #-11]	@ zero_extendqisi2
 1184 0046 6379     		ldrb	r3, [r4, #5]	@ zero_extendqisi2
 1185 0048 5340     		eors	r3, r3, r2
 1186 004a 6371     		strb	r3, [r4, #5]
  81:AES128.cpp    ****             schedule[19] ^= schedule[3];
 1187              		.loc 1 81 13 is_stmt 1 view .LVU316
  81:AES128.cpp    ****             schedule[19] ^= schedule[3];
 1188              		.loc 1 81 26 is_stmt 0 view .LVU317
 1189 004c 14F80A2C 		ldrb	r2, [r4, #-10]	@ zero_extendqisi2
 1190 0050 A379     		ldrb	r3, [r4, #6]	@ zero_extendqisi2
 1191 0052 5340     		eors	r3, r3, r2
 1192 0054 A371     		strb	r3, [r4, #6]
  82:AES128.cpp    ****             ++iteration;
 1193              		.loc 1 82 13 is_stmt 1 view .LVU318
  82:AES128.cpp    ****             ++iteration;
 1194              		.loc 1 82 26 is_stmt 0 view .LVU319
 1195 0056 14F8092C 		ldrb	r2, [r4, #-9]	@ zero_extendqisi2
 1196 005a E379     		ldrb	r3, [r4, #7]	@ zero_extendqisi2
  83:AES128.cpp    ****             w = 0;
 1197              		.loc 1 83 13 view .LVU320
 1198 005c 0135     		adds	r5, r5, #1
 1199              	.LVL80:
  82:AES128.cpp    ****             ++iteration;
 1200              		.loc 1 82 26 view .LVU321
 1201 005e 5340     		eors	r3, r3, r2
 1202 0060 E371     		strb	r3, [r4, #7]
  83:AES128.cpp    ****             w = 0;
 1203              		.loc 1 83 13 is_stmt 1 view .LVU322
 1204 0062 EDB2     		uxtb	r5, r5
 1205              	.LVL81:
  84:AES128.cpp    ****         } else {
 1206              		.loc 1 84 13 view .LVU323
  84:AES128.cpp    ****         } else {
 1207              		.loc 1 84 15 is_stmt 0 view .LVU324
 1208 0064 0023     		movs	r3, #0
 1209              	.LVL82:
 1210              	.L42:
  94:AES128.cpp    ****         n += 4;
 1211              		.loc 1 94 9 is_stmt 1 view .LVU325
  95:AES128.cpp    ****         ++w;
 1212              		.loc 1 95 9 view .LVU326
  96:AES128.cpp    ****     }
 1213              		.loc 1 96 9 view .LVU327
 1214 0066 0133     		adds	r3, r3, #1
 1215              	.LVL83:
  75:AES128.cpp    ****         if (w == 4) {
 1216              		.loc 1 75 14 is_stmt 0 view .LVU328
 1217 0068 B742     		cmp	r7, r6
  96:AES128.cpp    ****     }
 1218              		.loc 1 96 9 view .LVU329
 1219 006a DBB2     		uxtb	r3, r3
 1220              	.LVL84:
  75:AES128.cpp    ****         if (w == 4) {
 1221              		.loc 1 75 5 is_stmt 1 view .LVU330
  75:AES128.cpp    ****         if (w == 4) {
 1222              		.loc 1 75 14 view .LVU331
  75:AES128.cpp    ****         if (w == 4) {
 1223              		.loc 1 75 14 is_stmt 0 view .LVU332
 1224 006c 3C46     		mov	r4, r7
 1225 006e DAD1     		bne	.L43
 1226              	.LVL85:
  75:AES128.cpp    ****         if (w == 4) {
 1227              		.loc 1 75 14 view .LVU333
 1228 0070 0120     		movs	r0, #1
 1229              	.LVL86:
 1230              	.L39:
  75:AES128.cpp    ****         if (w == 4) {
 1231              		.loc 1 75 14 view .LVU334
 1232              	.LBE25:
 1233              	.LBE24:
 100:AES128.cpp    **** 
 1234              		.loc 1 100 1 view .LVU335
 1235 0072 F8BD     		pop	{r3, r4, r5, r6, r7, pc}
 1236              	.LVL87:
 1237              	.L41:
 1238              	.LBB27:
 1239              	.LBB26:
  87:AES128.cpp    ****             schedule[17] = schedule[13] ^ schedule[1];
 1240              		.loc 1 87 13 is_stmt 1 view .LVU336
  87:AES128.cpp    ****             schedule[17] = schedule[13] ^ schedule[1];
 1241              		.loc 1 87 41 is_stmt 0 view .LVU337
 1242 0074 14F80C1C 		ldrb	r1, [r4, #-12]	@ zero_extendqisi2
 1243 0078 2278     		ldrb	r2, [r4]	@ zero_extendqisi2
 1244 007a 4A40     		eors	r2, r2, r1
  87:AES128.cpp    ****             schedule[17] = schedule[13] ^ schedule[1];
 1245              		.loc 1 87 26 view .LVU338
 1246 007c 2271     		strb	r2, [r4, #4]
  88:AES128.cpp    ****             schedule[18] = schedule[14] ^ schedule[2];
 1247              		.loc 1 88 13 is_stmt 1 view .LVU339
  88:AES128.cpp    ****             schedule[18] = schedule[14] ^ schedule[2];
 1248              		.loc 1 88 41 is_stmt 0 view .LVU340
 1249 007e 14F80B1C 		ldrb	r1, [r4, #-11]	@ zero_extendqisi2
 1250 0082 6278     		ldrb	r2, [r4, #1]	@ zero_extendqisi2
 1251 0084 4A40     		eors	r2, r2, r1
  88:AES128.cpp    ****             schedule[18] = schedule[14] ^ schedule[2];
 1252              		.loc 1 88 26 view .LVU341
 1253 0086 6271     		strb	r2, [r4, #5]
  89:AES128.cpp    ****             schedule[19] = schedule[15] ^ schedule[3];
 1254              		.loc 1 89 13 is_stmt 1 view .LVU342
  89:AES128.cpp    ****             schedule[19] = schedule[15] ^ schedule[3];
 1255              		.loc 1 89 41 is_stmt 0 view .LVU343
 1256 0088 14F80A1C 		ldrb	r1, [r4, #-10]	@ zero_extendqisi2
 1257 008c A278     		ldrb	r2, [r4, #2]	@ zero_extendqisi2
 1258 008e 4A40     		eors	r2, r2, r1
  89:AES128.cpp    ****             schedule[19] = schedule[15] ^ schedule[3];
 1259              		.loc 1 89 26 view .LVU344
 1260 0090 A271     		strb	r2, [r4, #6]
  90:AES128.cpp    ****         }
 1261              		.loc 1 90 13 is_stmt 1 view .LVU345
  90:AES128.cpp    ****         }
 1262              		.loc 1 90 41 is_stmt 0 view .LVU346
 1263 0092 14F8091C 		ldrb	r1, [r4, #-9]	@ zero_extendqisi2
 1264 0096 E278     		ldrb	r2, [r4, #3]	@ zero_extendqisi2
 1265 0098 4A40     		eors	r2, r2, r1
  90:AES128.cpp    ****         }
 1266              		.loc 1 90 26 view .LVU347
 1267 009a E271     		strb	r2, [r4, #7]
 1268 009c E3E7     		b	.L42
 1269              	.LVL88:
 1270              	.L44:
  90:AES128.cpp    ****         }
 1271              		.loc 1 90 26 view .LVU348
 1272              	.LBE26:
 1273              	.LBE27:
  65:AES128.cpp    **** 
 1274              		.loc 1 65 16 view .LVU349
 1275 009e 0020     		movs	r0, #0
 1276              	.LVL89:
  65:AES128.cpp    **** 
 1277              		.loc 1 65 16 view .LVU350
 1278 00a0 E7E7     		b	.L39
 1279              		.cfi_endproc
 1280              	.LFE9:
 1281              		.fnend
 1283              		.section	.text._ZN11AESSmall1286setKeyEPKhj,"ax",%progbits
 1284              		.align	1
 1285              		.global	_ZN11AESSmall1286setKeyEPKhj
 1286              		.syntax unified
 1287              		.thumb
 1288              		.thumb_func
 1289              		.fpu softvfp
 1291              	_ZN11AESSmall1286setKeyEPKhj:
 1292              		.fnstart
 1293              	.LVL90:
 1294              	.LFB30:
 281:AES128.cpp    ****     uint8_t *schedule;
 1295              		.loc 1 281 1 is_stmt 1 view -0
 1296              		.cfi_startproc
 1297              		@ args = 0, pretend = 0, frame = 8
 1298              		@ frame_needed = 0, uses_anonymous_args = 0
 281:AES128.cpp    ****     uint8_t *schedule;
 1299              		.loc 1 281 1 is_stmt 0 view .LVU352
 1300 0000 2DE9F347 		push	{r0, r1, r4, r5, r6, r7, r8, r9, r10, lr}
 1301              		.save {r4, r5, r6, r7, r8, r9, r10, lr}
 1302              		.pad #8
 1303              	.LCFI11:
 1304              		.cfi_def_cfa_offset 40
 1305              		.cfi_offset 4, -32
 1306              		.cfi_offset 5, -28
 1307              		.cfi_offset 6, -24
 1308              		.cfi_offset 7, -20
 1309              		.cfi_offset 8, -16
 1310              		.cfi_offset 9, -12
 1311              		.cfi_offset 10, -8
 1312              		.cfi_offset 14, -4
 281:AES128.cpp    ****     uint8_t *schedule;
 1313              		.loc 1 281 1 view .LVU353
 1314 0004 0446     		mov	r4, r0
 1315 0006 0D46     		mov	r5, r1
 282:AES128.cpp    ****     uint8_t round;
 1316              		.loc 1 282 5 is_stmt 1 view .LVU354
 283:AES128.cpp    ****     uint8_t temp[4];
 1317              		.loc 1 283 5 view .LVU355
 284:AES128.cpp    **** 
 1318              		.loc 1 284 5 view .LVU356
 287:AES128.cpp    ****         return false;
 1319              		.loc 1 287 5 view .LVU357
 287:AES128.cpp    ****         return false;
 1320              		.loc 1 287 28 is_stmt 0 view .LVU358
 1321 0008 FFF7FEFF 		bl	_ZN10AESTiny1286setKeyEPKhj
 1322              	.LVL91:
 287:AES128.cpp    ****         return false;
 1323              		.loc 1 287 5 view .LVU359
 1324 000c 8046     		mov	r8, r0
 1325 000e 0028     		cmp	r0, #0
 1326 0010 5AD0     		beq	.L48
 1327              	.LVL92:
 1328              	.LBB30:
 1329              	.LBI30:
 280:AES128.cpp    **** {
 1330              		.loc 1 280 6 is_stmt 1 view .LVU360
 1331              	.LBB31:
 293:AES128.cpp    ****     memcpy(schedule, key, 16);
 1332              		.loc 1 293 5 view .LVU361
 294:AES128.cpp    ****     for (round = 1; round <= 10; ++round) {
 1333              		.loc 1 294 5 view .LVU362
 294:AES128.cpp    ****     for (round = 1; round <= 10; ++round) {
 1334              		.loc 1 294 11 is_stmt 0 view .LVU363
 1335 0012 2946     		mov	r1, r5
 1336 0014 04F11403 		add	r3, r4, #20
 1337              	.LVL93:
 294:AES128.cpp    ****     for (round = 1; round <= 10; ++round) {
 1338              		.loc 1 294 11 view .LVU364
 1339 0018 05F11002 		add	r2, r5, #16
 1340              	.LVL94:
 1341              	.L49:
 294:AES128.cpp    ****     for (round = 1; round <= 10; ++round) {
 1342              		.loc 1 294 11 view .LVU365
 1343 001c 51F8040B 		ldr	r0, [r1], #4	@ unaligned
 1344 0020 43F8040B 		str	r0, [r3], #4	@ unaligned
 1345 0024 9142     		cmp	r1, r2
 1346 0026 F9D1     		bne	.L49
 295:AES128.cpp    ****         KCORE(round);
 1347              		.loc 1 295 5 is_stmt 1 view .LVU366
 1348              	.LVL95:
 295:AES128.cpp    ****         KCORE(round);
 1349              		.loc 1 295 27 view .LVU367
 295:AES128.cpp    ****         KCORE(round);
 1350              		.loc 1 295 16 is_stmt 0 view .LVU368
 1351 0028 4FF00109 		mov	r9, #1
 296:AES128.cpp    ****         KXOR(1, 0);
 1352              		.loc 1 296 9 view .LVU369
 1353 002c 04F1200A 		add	r10, r4, #32
 1354              	.LVL96:
 1355              	.L50:
 296:AES128.cpp    ****         KXOR(1, 0);
 1356              		.loc 1 296 9 is_stmt 1 view .LVU370
 296:AES128.cpp    ****         KXOR(1, 0);
 1357              		.loc 1 296 9 view .LVU371
 1358 0030 4A46     		mov	r2, r9
 1359 0032 5146     		mov	r1, r10
 1360 0034 01A8     		add	r0, sp, #4
 1361 0036 FFF7FEFF 		bl	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 1362              	.LVL97:
 296:AES128.cpp    ****         KXOR(1, 0);
 1363              		.loc 1 296 9 view .LVU372
 1364 003a 277D     		ldrb	r7, [r4, #20]	@ zero_extendqisi2
 1365 003c 9DF80430 		ldrb	r3, [sp, #4]	@ zero_extendqisi2
 1366 0040 667D     		ldrb	r6, [r4, #21]	@ zero_extendqisi2
 1367 0042 A57D     		ldrb	r5, [r4, #22]	@ zero_extendqisi2
 1368 0044 E27D     		ldrb	r2, [r4, #23]	@ zero_extendqisi2
 1369 0046 5F40     		eors	r7, r7, r3
 1370 0048 9DF80530 		ldrb	r3, [sp, #5]	@ zero_extendqisi2
 1371 004c 2775     		strb	r7, [r4, #20]
 296:AES128.cpp    ****         KXOR(1, 0);
 1372              		.loc 1 296 9 view .LVU373
 1373 004e 5E40     		eors	r6, r6, r3
 1374 0050 9DF80630 		ldrb	r3, [sp, #6]	@ zero_extendqisi2
 1375 0054 6675     		strb	r6, [r4, #21]
 296:AES128.cpp    ****         KXOR(1, 0);
 1376              		.loc 1 296 9 view .LVU374
 1377 0056 5D40     		eors	r5, r5, r3
 1378 0058 9DF80730 		ldrb	r3, [sp, #7]	@ zero_extendqisi2
 1379 005c A575     		strb	r5, [r4, #22]
 296:AES128.cpp    ****         KXOR(1, 0);
 1380              		.loc 1 296 9 view .LVU375
 1381 005e 5340     		eors	r3, r3, r2
 297:AES128.cpp    ****         KXOR(2, 1);
 1382              		.loc 1 297 9 is_stmt 0 view .LVU376
 1383 0060 227E     		ldrb	r2, [r4, #24]	@ zero_extendqisi2
 296:AES128.cpp    ****         KXOR(1, 0);
 1384              		.loc 1 296 9 view .LVU377
 1385 0062 E375     		strb	r3, [r4, #23]
 297:AES128.cpp    ****         KXOR(2, 1);
 1386              		.loc 1 297 9 is_stmt 1 view .LVU378
 297:AES128.cpp    ****         KXOR(2, 1);
 1387              		.loc 1 297 9 view .LVU379
 1388 0064 5740     		eors	r7, r7, r2
 1389 0066 627E     		ldrb	r2, [r4, #25]	@ zero_extendqisi2
 1390 0068 2776     		strb	r7, [r4, #24]
 297:AES128.cpp    ****         KXOR(2, 1);
 1391              		.loc 1 297 9 view .LVU380
 1392 006a 5640     		eors	r6, r6, r2
 1393 006c A27E     		ldrb	r2, [r4, #26]	@ zero_extendqisi2
 1394 006e 6676     		strb	r6, [r4, #25]
 297:AES128.cpp    ****         KXOR(2, 1);
 1395              		.loc 1 297 9 view .LVU381
 1396 0070 5540     		eors	r5, r5, r2
 1397 0072 E27E     		ldrb	r2, [r4, #27]	@ zero_extendqisi2
 1398 0074 A576     		strb	r5, [r4, #26]
 297:AES128.cpp    ****         KXOR(2, 1);
 1399              		.loc 1 297 9 view .LVU382
 1400 0076 5340     		eors	r3, r3, r2
 298:AES128.cpp    ****         KXOR(3, 2);
 1401              		.loc 1 298 9 is_stmt 0 view .LVU383
 1402 0078 227F     		ldrb	r2, [r4, #28]	@ zero_extendqisi2
 297:AES128.cpp    ****         KXOR(2, 1);
 1403              		.loc 1 297 9 view .LVU384
 1404 007a E376     		strb	r3, [r4, #27]
 298:AES128.cpp    ****         KXOR(3, 2);
 1405              		.loc 1 298 9 is_stmt 1 view .LVU385
 298:AES128.cpp    ****         KXOR(3, 2);
 1406              		.loc 1 298 9 view .LVU386
 1407 007c 5740     		eors	r7, r7, r2
 1408 007e 627F     		ldrb	r2, [r4, #29]	@ zero_extendqisi2
 1409 0080 2777     		strb	r7, [r4, #28]
 298:AES128.cpp    ****         KXOR(3, 2);
 1410              		.loc 1 298 9 view .LVU387
 1411 0082 5640     		eors	r6, r6, r2
 1412 0084 A27F     		ldrb	r2, [r4, #30]	@ zero_extendqisi2
 1413 0086 6677     		strb	r6, [r4, #29]
 298:AES128.cpp    ****         KXOR(3, 2);
 1414              		.loc 1 298 9 view .LVU388
 1415 0088 5540     		eors	r5, r5, r2
 1416 008a E27F     		ldrb	r2, [r4, #31]	@ zero_extendqisi2
 1417 008c A577     		strb	r5, [r4, #30]
 298:AES128.cpp    ****         KXOR(3, 2);
 1418              		.loc 1 298 9 view .LVU389
 1419 008e 5340     		eors	r3, r3, r2
 299:AES128.cpp    ****     }
 1420              		.loc 1 299 9 is_stmt 0 view .LVU390
 1421 0090 94F82020 		ldrb	r2, [r4, #32]	@ zero_extendqisi2
 298:AES128.cpp    ****         KXOR(3, 2);
 1422              		.loc 1 298 9 view .LVU391
 1423 0094 E377     		strb	r3, [r4, #31]
 299:AES128.cpp    ****     }
 1424              		.loc 1 299 9 is_stmt 1 view .LVU392
 299:AES128.cpp    ****     }
 1425              		.loc 1 299 9 view .LVU393
 1426 0096 5740     		eors	r7, r7, r2
 1427 0098 94F82120 		ldrb	r2, [r4, #33]	@ zero_extendqisi2
 1428 009c 84F82070 		strb	r7, [r4, #32]
 299:AES128.cpp    ****     }
 1429              		.loc 1 299 9 view .LVU394
 1430 00a0 5640     		eors	r6, r6, r2
 1431 00a2 84F82160 		strb	r6, [r4, #33]
 299:AES128.cpp    ****     }
 1432              		.loc 1 299 9 view .LVU395
 1433 00a6 94F82220 		ldrb	r2, [r4, #34]	@ zero_extendqisi2
 295:AES128.cpp    ****         KCORE(round);
 1434              		.loc 1 295 5 is_stmt 0 view .LVU396
 1435 00aa 09F10109 		add	r9, r9, #1
 1436              	.LVL98:
 299:AES128.cpp    ****     }
 1437              		.loc 1 299 9 view .LVU397
 1438 00ae 5540     		eors	r5, r5, r2
 1439 00b0 94F82320 		ldrb	r2, [r4, #35]	@ zero_extendqisi2
 1440 00b4 84F82250 		strb	r5, [r4, #34]
 299:AES128.cpp    ****     }
 1441              		.loc 1 299 9 is_stmt 1 view .LVU398
 295:AES128.cpp    ****         KCORE(round);
 1442              		.loc 1 295 5 is_stmt 0 view .LVU399
 1443 00b8 5FFA89F9 		uxtb	r9, r9
 299:AES128.cpp    ****     }
 1444              		.loc 1 299 9 view .LVU400
 1445 00bc 5340     		eors	r3, r3, r2
 295:AES128.cpp    ****         KCORE(round);
 1446              		.loc 1 295 27 view .LVU401
 1447 00be B9F10B0F 		cmp	r9, #11
 299:AES128.cpp    ****     }
 1448              		.loc 1 299 9 view .LVU402
 1449 00c2 84F82330 		strb	r3, [r4, #35]
 295:AES128.cpp    ****         KCORE(round);
 1450              		.loc 1 295 5 is_stmt 1 view .LVU403
 1451              	.LVL99:
 295:AES128.cpp    ****         KCORE(round);
 1452              		.loc 1 295 27 view .LVU404
 1453 00c6 B3D1     		bne	.L50
 1454              	.LVL100:
 1455              	.L48:
 295:AES128.cpp    ****         KCORE(round);
 1456              		.loc 1 295 27 is_stmt 0 view .LVU405
 1457              	.LBE31:
 1458              	.LBE30:
 304:AES128.cpp    **** 
 1459              		.loc 1 304 1 view .LVU406
 1460 00c8 4046     		mov	r0, r8
 1461 00ca 02B0     		add	sp, sp, #8
 1462              	.LCFI12:
 1463              		.cfi_def_cfa_offset 32
 1464              		@ sp needed
 1465 00cc BDE8F087 		pop	{r4, r5, r6, r7, r8, r9, r10, pc}
 304:AES128.cpp    **** 
 1466              		.loc 1 304 1 view .LVU407
 1467              		.cfi_endproc
 1468              	.LFE30:
 1469              		.fnend
 1471              		.section	.text._ZN11AESSmall1285clearEv,"ax",%progbits
 1472              		.align	1
 1473              		.global	_ZN11AESSmall1285clearEv
 1474              		.syntax unified
 1475              		.thumb
 1476              		.thumb_func
 1477              		.fpu softvfp
 1479              	_ZN11AESSmall1285clearEv:
 1480              		.fnstart
 1481              	.LVL101:
 1482              	.LFB32:
 349:AES128.cpp    **** 
 350:AES128.cpp    **** void AESSmall128::clear()
 351:AES128.cpp    **** {
 1483              		.loc 1 351 1 is_stmt 1 view -0
 1484              		.cfi_startproc
 1485              		@ args = 0, pretend = 0, frame = 0
 1486              		@ frame_needed = 0, uses_anonymous_args = 0
 352:AES128.cpp    ****     clean(reverse);
 1487              		.loc 1 352 5 view .LVU409
 1488              	.LBB38:
 1489              	.LBI38:
  32:Crypto.h      **** {
 1490              		.loc 2 32 13 view .LVU410
 1491              	.LBE38:
 351:AES128.cpp    ****     clean(reverse);
 1492              		.loc 1 351 1 is_stmt 0 view .LVU411
 1493 0000 10B5     		push	{r4, lr}
 1494              		.save {r4, lr}
 1495              	.LCFI13:
 1496              		.cfi_def_cfa_offset 8
 1497              		.cfi_offset 4, -8
 1498              		.cfi_offset 14, -4
 1499              	.LBB41:
 1500              	.LBB39:
 1501              		.loc 2 34 10 view .LVU412
 1502 0002 1021     		movs	r1, #16
 1503              	.LBE39:
 1504              	.LBE41:
 351:AES128.cpp    ****     clean(reverse);
 1505              		.loc 1 351 1 view .LVU413
 1506 0004 0446     		mov	r4, r0
 1507              	.LBB42:
 1508              	.LBB40:
 1509              		.loc 2 34 10 view .LVU414
 1510 0006 1430     		adds	r0, r0, #20
 1511              	.LVL102:
 1512              		.loc 2 34 10 view .LVU415
 1513 0008 FFF7FEFF 		bl	_Z5cleanPvj
 1514              	.LVL103:
 1515              		.loc 2 34 10 view .LVU416
 1516              	.LBE40:
 1517              	.LBE42:
 353:AES128.cpp    ****     AESTiny128::clear();
 1518              		.loc 1 353 5 is_stmt 1 view .LVU417
 1519              	.LBB43:
 1520              	.LBI43:
 240:AES128.cpp    **** {
 1521              		.loc 1 240 6 view .LVU418
 1522              	.LBB44:
 242:AES128.cpp    **** }
 1523              		.loc 1 242 5 view .LVU419
 1524              	.LBB45:
 1525              	.LBI45:
  32:Crypto.h      **** {
 1526              		.loc 2 32 13 view .LVU420
 1527              	.LBB46:
 1528              		.loc 2 34 10 is_stmt 0 view .LVU421
 1529 000c 201D     		adds	r0, r4, #4
 1530              	.LVL104:
 1531              		.loc 2 34 10 view .LVU422
 1532 000e 1021     		movs	r1, #16
 1533              	.LBE46:
 1534              	.LBE45:
 1535              	.LBE44:
 1536              	.LBE43:
 354:AES128.cpp    **** }
 1537              		.loc 1 354 1 view .LVU423
 1538 0010 BDE81040 		pop	{r4, lr}
 1539              	.LCFI14:
 1540              		.cfi_restore 14
 1541              		.cfi_restore 4
 1542              		.cfi_def_cfa_offset 0
 1543              	.LVL105:
 1544              	.LBB50:
 1545              	.LBB49:
 1546              	.LBB48:
 1547              	.LBB47:
 1548              		.loc 2 34 10 view .LVU424
 1549 0014 FFF7FEBF 		b	_Z5cleanPvj
 1550              	.LVL106:
 1551              		.loc 2 34 10 view .LVU425
 1552              	.LBE47:
 1553              	.LBE48:
 1554              	.LBE49:
 1555              	.LBE50:
 1556              		.cfi_endproc
 1557              	.LFE32:
 1558              		.fnend
 1560              		.section	.text._ZN11AESSmall128D2Ev,"ax",%progbits
 1561              		.align	1
 1562              		.global	_ZN11AESSmall128D2Ev
 1563              		.syntax unified
 1564              		.thumb
 1565              		.thumb_func
 1566              		.fpu softvfp
 1568              	_ZN11AESSmall128D2Ev:
 1569              		.fnstart
 1570              	.LVL107:
 1571              	.LFB27:
 275:AES128.cpp    **** {
 1572              		.loc 1 275 1 is_stmt 1 view -0
 1573              		.cfi_startproc
 1574              		@ args = 0, pretend = 0, frame = 0
 1575              		@ frame_needed = 0, uses_anonymous_args = 0
 275:AES128.cpp    **** {
 1576              		.loc 1 275 1 is_stmt 0 view .LVU427
 1577 0000 10B5     		push	{r4, lr}
 1578              		.save {r4, lr}
 1579              	.LCFI15:
 1580              		.cfi_def_cfa_offset 8
 1581              		.cfi_offset 4, -8
 1582              		.cfi_offset 14, -4
 1583              	.LBB54:
 275:AES128.cpp    **** {
 1584              		.loc 1 275 27 view .LVU428
 1585 0002 064B     		ldr	r3, .L58
 1586              	.LBE54:
 275:AES128.cpp    **** {
 1587              		.loc 1 275 1 view .LVU429
 1588 0004 0446     		mov	r4, r0
 1589              	.LBB59:
 1590              	.LBB55:
 1591              	.LBB56:
 1592              		.loc 2 34 10 view .LVU430
 1593 0006 1021     		movs	r1, #16
 1594              	.LBE56:
 1595              	.LBE55:
 275:AES128.cpp    **** {
 1596              		.loc 1 275 27 view .LVU431
 1597 0008 40F8143B 		str	r3, [r0], #20
 1598              	.LVL108:
 277:AES128.cpp    **** }
 1599              		.loc 1 277 5 is_stmt 1 view .LVU432
 1600              	.LBB58:
 1601              	.LBI55:
  32:Crypto.h      **** {
 1602              		.loc 2 32 13 view .LVU433
 1603              	.LBB57:
 1604              		.loc 2 34 10 is_stmt 0 view .LVU434
 1605 000c FFF7FEFF 		bl	_Z5cleanPvj
 1606              	.LVL109:
 1607              		.loc 2 34 10 view .LVU435
 1608              	.LBE57:
 1609              	.LBE58:
 275:AES128.cpp    **** {
 1610              		.loc 1 275 27 view .LVU436
 1611 0010 2046     		mov	r0, r4
 1612 0012 FFF7FEFF 		bl	_ZN10AESTiny128D2Ev
 1613              	.LVL110:
 1614              	.LBE59:
 278:AES128.cpp    **** 
 1615              		.loc 1 278 1 view .LVU437
 1616 0016 2046     		mov	r0, r4
 1617 0018 10BD     		pop	{r4, pc}
 1618              	.LVL111:
 1619              	.L59:
 278:AES128.cpp    **** 
 1620              		.loc 1 278 1 view .LVU438
 1621 001a 00BF     		.align	2
 1622              	.L58:
 1623 001c 58000000 		.word	.LANCHOR0+88
 1624              		.cfi_endproc
 1625              	.LFE27:
 1626              		.personality	__gxx_personality_v0
 1627              		.handlerdata
 1628              	.LLSDA27:
 1629 0008 FF       		.byte	0xff
 1630 0009 FF       		.byte	0xff
 1631 000a 01       		.byte	0x1
 1632 000b 00       		.uleb128 .LLSDACSE27-.LLSDACSB27
 1633              	.LLSDACSB27:
 1634              	.LLSDACSE27:
 1635              		.section	.text._ZN11AESSmall128D2Ev
 1636              		.fnend
 1638              		.global	_ZN11AESSmall128D1Ev
 1639              		.thumb_set _ZN11AESSmall128D1Ev,_ZN11AESSmall128D2Ev
 1640              		.section	.text._ZN11AESSmall128D0Ev,"ax",%progbits
 1641              		.align	1
 1642              		.global	_ZN11AESSmall128D0Ev
 1643              		.syntax unified
 1644              		.thumb
 1645              		.thumb_func
 1646              		.fpu softvfp
 1648              	_ZN11AESSmall128D0Ev:
 1649              		.fnstart
 1650              	.LVL112:
 1651              	.LFB29:
 275:AES128.cpp    **** {
 1652              		.loc 1 275 1 is_stmt 1 view -0
 1653              		.cfi_startproc
 1654              		@ args = 0, pretend = 0, frame = 0
 1655              		@ frame_needed = 0, uses_anonymous_args = 0
 275:AES128.cpp    **** {
 1656              		.loc 1 275 1 is_stmt 0 view .LVU440
 1657 0000 10B5     		push	{r4, lr}
 1658              	.LCFI16:
 1659              		.cfi_def_cfa_offset 8
 1660              		.cfi_offset 4, -8
 1661              		.cfi_offset 14, -4
 275:AES128.cpp    **** {
 1662              		.loc 1 275 1 view .LVU441
 1663 0002 0446     		mov	r4, r0
 278:AES128.cpp    **** 
 1664              		.loc 1 278 1 view .LVU442
 1665 0004 FFF7FEFF 		bl	_ZN11AESSmall128D1Ev
 1666              	.LVL113:
 278:AES128.cpp    **** 
 1667              		.loc 1 278 1 view .LVU443
 1668 0008 2046     		mov	r0, r4
 1669 000a 2421     		movs	r1, #36
 1670 000c FFF7FEFF 		bl	_ZdlPvj
 1671              	.LVL114:
 1672 0010 2046     		mov	r0, r4
 1673 0012 10BD     		pop	{r4, pc}
 278:AES128.cpp    **** 
 1674              		.loc 1 278 1 view .LVU444
 1675              		.cfi_endproc
 1676              	.LFE29:
 1677              		.cantunwind
 1678              		.fnend
 1680              		.section	.text._ZN10AESTiny1285clearEv,"ax",%progbits
 1681              		.align	1
 1682              		.global	_ZN10AESTiny1285clearEv
 1683              		.syntax unified
 1684              		.thumb
 1685              		.thumb_func
 1686              		.fpu softvfp
 1688              	_ZN10AESTiny1285clearEv:
 1689              		.fnstart
 1690              	.LVL115:
 1691              	.LFB22:
 241:AES128.cpp    ****     clean(schedule);
 1692              		.loc 1 241 1 is_stmt 1 view -0
 1693              		.cfi_startproc
 1694              		@ args = 0, pretend = 0, frame = 0
 1695              		@ frame_needed = 0, uses_anonymous_args = 0
 1696              		@ link register save eliminated.
 242:AES128.cpp    **** }
 1697              		.loc 1 242 5 view .LVU446
 1698              	.LBB62:
 1699              	.LBI62:
  32:Crypto.h      **** {
 1700              		.loc 2 32 13 view .LVU447
 1701              	.LBB63:
 1702              		.loc 2 34 10 is_stmt 0 view .LVU448
 1703 0000 1021     		movs	r1, #16
 1704 0002 0430     		adds	r0, r0, #4
 1705              	.LVL116:
 1706              		.loc 2 34 10 view .LVU449
 1707 0004 FFF7FEBF 		b	_Z5cleanPvj
 1708              	.LVL117:
 1709              		.loc 2 34 10 view .LVU450
 1710              	.LBE63:
 1711              	.LBE62:
 1712              		.cfi_endproc
 1713              	.LFE22:
 1714              		.cantunwind
 1715              		.fnend
 1717              		.section	.text._ZN6AES128C2Ev,"ax",%progbits
 1718              		.align	1
 1719              		.global	_ZN6AES128C2Ev
 1720              		.syntax unified
 1721              		.thumb
 1722              		.thumb_func
 1723              		.fpu softvfp
 1725              	_ZN6AES128C2Ev:
 1726              		.fnstart
 1727              	.LVL118:
 1728              	.LFB2:
  42:AES128.cpp    **** {
 1729              		.loc 1 42 1 is_stmt 1 view -0
 1730              		.cfi_startproc
 1731              		@ args = 0, pretend = 0, frame = 0
 1732              		@ frame_needed = 0, uses_anonymous_args = 0
  42:AES128.cpp    **** {
 1733              		.loc 1 42 1 is_stmt 0 view .LVU452
 1734 0000 10B5     		push	{r4, lr}
 1735              		.save {r4, lr}
 1736              	.LCFI17:
 1737              		.cfi_def_cfa_offset 8
 1738              		.cfi_offset 4, -8
 1739              		.cfi_offset 14, -4
  42:AES128.cpp    **** {
 1740              		.loc 1 42 1 view .LVU453
 1741 0002 0446     		mov	r4, r0
 1742              	.LBB64:
  42:AES128.cpp    **** {
 1743              		.loc 1 42 16 view .LVU454
 1744 0004 FFF7FEFF 		bl	_ZN9AESCommonC2Ev
 1745              	.LVL119:
  42:AES128.cpp    **** {
 1746              		.loc 1 42 16 view .LVU455
 1747 0008 044B     		ldr	r3, .L63
 1748 000a 2360     		str	r3, [r4]
  44:AES128.cpp    ****     schedule = sched;
 1749              		.loc 1 44 5 is_stmt 1 view .LVU456
  44:AES128.cpp    ****     schedule = sched;
 1750              		.loc 1 44 12 is_stmt 0 view .LVU457
 1751 000c 0A23     		movs	r3, #10
 1752 000e 2371     		strb	r3, [r4, #4]
  45:AES128.cpp    **** }
 1753              		.loc 1 45 5 is_stmt 1 view .LVU458
  45:AES128.cpp    **** }
 1754              		.loc 1 45 16 is_stmt 0 view .LVU459
 1755 0010 04F10C03 		add	r3, r4, #12
  45:AES128.cpp    **** }
 1756              		.loc 1 45 14 view .LVU460
 1757 0014 A360     		str	r3, [r4, #8]
 1758              	.LBE64:
  46:AES128.cpp    **** 
 1759              		.loc 1 46 1 view .LVU461
 1760 0016 2046     		mov	r0, r4
 1761 0018 10BD     		pop	{r4, pc}
 1762              	.LVL120:
 1763              	.L64:
  46:AES128.cpp    **** 
 1764              		.loc 1 46 1 view .LVU462
 1765 001a 00BF     		.align	2
 1766              	.L63:
 1767 001c 08000000 		.word	.LANCHOR0+8
 1768              		.cfi_endproc
 1769              	.LFE2:
 1770              		.fnend
 1772              		.global	_ZN6AES128C1Ev
 1773              		.thumb_set _ZN6AES128C1Ev,_ZN6AES128C2Ev
 1774              		.section	.text._ZN10AESTiny128C2Ev,"ax",%progbits
 1775              		.align	1
 1776              		.global	_ZN10AESTiny128C2Ev
 1777              		.syntax unified
 1778              		.thumb
 1779              		.thumb_func
 1780              		.fpu softvfp
 1782              	_ZN10AESTiny128C2Ev:
 1783              		.fnstart
 1784              	.LVL121:
 1785              	.LFB11:
 152:AES128.cpp    **** {
 1786              		.loc 1 152 1 is_stmt 1 view -0
 1787              		.cfi_startproc
 1788              		@ args = 0, pretend = 0, frame = 0
 1789              		@ frame_needed = 0, uses_anonymous_args = 0
 152:AES128.cpp    **** {
 1790              		.loc 1 152 1 is_stmt 0 view .LVU464
 1791 0000 10B5     		push	{r4, lr}
 1792              		.save {r4, lr}
 1793              	.LCFI18:
 1794              		.cfi_def_cfa_offset 8
 1795              		.cfi_offset 4, -8
 1796              		.cfi_offset 14, -4
 152:AES128.cpp    **** {
 1797              		.loc 1 152 1 view .LVU465
 1798 0002 0446     		mov	r4, r0
 1799              	.LBB65:
 152:AES128.cpp    **** {
 1800              		.loc 1 152 24 view .LVU466
 1801 0004 FFF7FEFF 		bl	_ZN11BlockCipherC2Ev
 1802              	.LVL122:
 152:AES128.cpp    **** {
 1803              		.loc 1 152 24 view .LVU467
 1804 0008 014B     		ldr	r3, .L66
 1805 000a 2360     		str	r3, [r4]
 1806              	.LBE65:
 154:AES128.cpp    **** 
 1807              		.loc 1 154 1 view .LVU468
 1808 000c 2046     		mov	r0, r4
 1809 000e 10BD     		pop	{r4, pc}
 1810              	.LVL123:
 1811              	.L67:
 154:AES128.cpp    **** 
 1812              		.loc 1 154 1 view .LVU469
 1813              		.align	2
 1814              	.L66:
 1815 0010 30000000 		.word	.LANCHOR0+48
 1816              		.cfi_endproc
 1817              	.LFE11:
 1818              		.fnend
 1820              		.global	_ZN10AESTiny128C1Ev
 1821              		.thumb_set _ZN10AESTiny128C1Ev,_ZN10AESTiny128C2Ev
 1822              		.section	.text._ZN11AESSmall128C2Ev,"ax",%progbits
 1823              		.align	1
 1824              		.global	_ZN11AESSmall128C2Ev
 1825              		.syntax unified
 1826              		.thumb
 1827              		.thumb_func
 1828              		.fpu softvfp
 1830              	_ZN11AESSmall128C2Ev:
 1831              		.fnstart
 1832              	.LVL124:
 1833              	.LFB24:
 271:AES128.cpp    **** {
 1834              		.loc 1 271 1 is_stmt 1 view -0
 1835              		.cfi_startproc
 1836              		@ args = 0, pretend = 0, frame = 0
 1837              		@ frame_needed = 0, uses_anonymous_args = 0
 271:AES128.cpp    **** {
 1838              		.loc 1 271 1 is_stmt 0 view .LVU471
 1839 0000 10B5     		push	{r4, lr}
 1840              		.save {r4, lr}
 1841              	.LCFI19:
 1842              		.cfi_def_cfa_offset 8
 1843              		.cfi_offset 4, -8
 1844              		.cfi_offset 14, -4
 271:AES128.cpp    **** {
 1845              		.loc 1 271 1 view .LVU472
 1846 0002 0446     		mov	r4, r0
 1847              	.LBB66:
 271:AES128.cpp    **** {
 1848              		.loc 1 271 26 view .LVU473
 1849 0004 FFF7FEFF 		bl	_ZN10AESTiny128C2Ev
 1850              	.LVL125:
 271:AES128.cpp    **** {
 1851              		.loc 1 271 26 view .LVU474
 1852 0008 014B     		ldr	r3, .L69
 1853 000a 2360     		str	r3, [r4]
 1854              	.LBE66:
 273:AES128.cpp    **** 
 1855              		.loc 1 273 1 view .LVU475
 1856 000c 2046     		mov	r0, r4
 1857 000e 10BD     		pop	{r4, pc}
 1858              	.LVL126:
 1859              	.L70:
 273:AES128.cpp    **** 
 1860              		.loc 1 273 1 view .LVU476
 1861              		.align	2
 1862              	.L69:
 1863 0010 58000000 		.word	.LANCHOR0+88
 1864              		.cfi_endproc
 1865              	.LFE24:
 1866              		.fnend
 1868              		.global	_ZN11AESSmall128C1Ev
 1869              		.thumb_set _ZN11AESSmall128C1Ev,_ZN11AESSmall128C2Ev
 1870              		.global	_ZTS6AES128
 1871              		.global	_ZTI6AES128
 1872              		.global	_ZTS10AESTiny128
 1873              		.global	_ZTI10AESTiny128
 1874              		.global	_ZTS11AESSmall128
 1875              		.global	_ZTI11AESSmall128
 1876              		.global	_ZTV6AES128
 1877              		.global	_ZTV10AESTiny128
 1878              		.global	_ZTV11AESSmall128
 1879              		.section	.rodata
 1880              		.align	2
 1881              		.set	.LANCHOR0,. + 0
 1884              	_ZTV6AES128:
 1885 0000 00000000 		.word	0
 1886 0004 00000000 		.word	_ZTI6AES128
 1887 0008 00000000 		.word	_ZN6AES128D1Ev
 1888 000c 00000000 		.word	_ZN6AES128D0Ev
 1889 0010 00000000 		.word	_ZNK9AESCommon9blockSizeEv
 1890 0014 00000000 		.word	_ZNK6AES1287keySizeEv
 1891 0018 00000000 		.word	_ZN6AES1286setKeyEPKhj
 1892 001c 00000000 		.word	_ZN9AESCommon12encryptBlockEPhPKh
 1893 0020 00000000 		.word	_ZN9AESCommon12decryptBlockEPhPKh
 1894 0024 00000000 		.word	_ZN9AESCommon5clearEv
 1897              	_ZTV10AESTiny128:
 1898 0028 00000000 		.word	0
 1899 002c 00000000 		.word	_ZTI10AESTiny128
 1900 0030 00000000 		.word	_ZN10AESTiny128D1Ev
 1901 0034 00000000 		.word	_ZN10AESTiny128D0Ev
 1902 0038 00000000 		.word	_ZNK10AESTiny1289blockSizeEv
 1903 003c 00000000 		.word	_ZNK10AESTiny1287keySizeEv
 1904 0040 00000000 		.word	_ZN10AESTiny1286setKeyEPKhj
 1905 0044 00000000 		.word	_ZN10AESTiny12812encryptBlockEPhPKh
 1906 0048 00000000 		.word	_ZN10AESTiny12812decryptBlockEPhPKh
 1907 004c 00000000 		.word	_ZN10AESTiny1285clearEv
 1910              	_ZTV11AESSmall128:
 1911 0050 00000000 		.word	0
 1912 0054 00000000 		.word	_ZTI11AESSmall128
 1913 0058 00000000 		.word	_ZN11AESSmall128D1Ev
 1914 005c 00000000 		.word	_ZN11AESSmall128D0Ev
 1915 0060 00000000 		.word	_ZNK10AESTiny1289blockSizeEv
 1916 0064 00000000 		.word	_ZNK10AESTiny1287keySizeEv
 1917 0068 00000000 		.word	_ZN11AESSmall1286setKeyEPKhj
 1918 006c 00000000 		.word	_ZN10AESTiny12812encryptBlockEPhPKh
 1919 0070 00000000 		.word	_ZN11AESSmall12812decryptBlockEPhPKh
 1920 0074 00000000 		.word	_ZN11AESSmall1285clearEv
 1923              	_ZTS6AES128:
 1924 0078 36414553 		.ascii	"6AES128\000"
 1924      31323800 
 1927              	_ZTI6AES128:
 1928 0080 08000000 		.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
 1929 0084 00000000 		.word	_ZTS6AES128
 1930 0088 00000000 		.word	_ZTI9AESCommon
 1933              	_ZTS10AESTiny128:
 1934 008c 31304145 		.ascii	"10AESTiny128\000"
 1934      5354696E 
 1934      79313238 
 1934      00
 1935 0099 000000   		.space	3
 1938              	_ZTI10AESTiny128:
 1939 009c 08000000 		.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
 1940 00a0 00000000 		.word	_ZTS10AESTiny128
 1941 00a4 00000000 		.word	_ZTI11BlockCipher
 1944              	_ZTS11AESSmall128:
 1945 00a8 31314145 		.ascii	"11AESSmall128\000"
 1945      53536D61 
 1945      6C6C3132 
 1945      3800
 1946 00b6 0000     		.space	2
 1949              	_ZTI11AESSmall128:
 1950 00b8 08000000 		.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
 1951 00bc 00000000 		.word	_ZTS11AESSmall128
 1952 00c0 00000000 		.word	_ZTI10AESTiny128
 1953              		.text
 1954              	.Letext0:
 1955              		.file 3 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 1956              		.file 4 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
 1957              		.file 5 "AES.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 AES128.cpp
     /tmp/ccvmC9sX.s:16     .text._ZNK6AES1287keySizeEv:0000000000000000 $t
     /tmp/ccvmC9sX.s:24     .text._ZNK6AES1287keySizeEv:0000000000000000 _ZNK6AES1287keySizeEv
.ARM.exidx.text._ZNK6AES1287keySizeEv:0000000000000000 $d
     /tmp/ccvmC9sX.s:24     .text._ZNK6AES1287keySizeEv:0000000000000000 _ZNK10AESTiny1287keySizeEv
     /tmp/ccvmC9sX.s:24     .text._ZNK6AES1287keySizeEv:0000000000000000 _ZNK10AESTiny1289blockSizeEv
     /tmp/ccvmC9sX.s:50     .text._ZN10AESTiny12812decryptBlockEPhPKh:0000000000000000 $t
     /tmp/ccvmC9sX.s:57     .text._ZN10AESTiny12812decryptBlockEPhPKh:0000000000000000 _ZN10AESTiny12812decryptBlockEPhPKh
.ARM.exidx.text._ZN10AESTiny12812decryptBlockEPhPKh:0000000000000000 $d
     /tmp/ccvmC9sX.s:74     .text._ZN6AES128D2Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:81     .text._ZN6AES128D2Ev:0000000000000000 _ZN6AES128D2Ev
     /tmp/ccvmC9sX.s:137    .text._ZN6AES128D2Ev:000000000000001c $d
   .ARM.extab.text._ZN6AES128D2Ev:0000000000000000 $d
   .ARM.exidx.text._ZN6AES128D2Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:81     .text._ZN6AES128D2Ev:0000000000000000 _ZN6AES128D1Ev
     /tmp/ccvmC9sX.s:156    .text._ZN6AES128D0Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:163    .text._ZN6AES128D0Ev:0000000000000000 _ZN6AES128D0Ev
   .ARM.exidx.text._ZN6AES128D0Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:196    .text._ZN10AESTiny1286setKeyEPKhj:0000000000000000 $t
     /tmp/ccvmC9sX.s:203    .text._ZN10AESTiny1286setKeyEPKhj:0000000000000000 _ZN10AESTiny1286setKeyEPKhj
.ARM.exidx.text._ZN10AESTiny1286setKeyEPKhj:0000000000000000 $d
     /tmp/ccvmC9sX.s:245    .text._ZN10AESTiny128D2Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:252    .text._ZN10AESTiny128D2Ev:0000000000000000 _ZN10AESTiny128D2Ev
     /tmp/ccvmC9sX.s:307    .text._ZN10AESTiny128D2Ev:000000000000001c $d
.ARM.extab.text._ZN10AESTiny128D2Ev:0000000000000000 $d
.ARM.exidx.text._ZN10AESTiny128D2Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:252    .text._ZN10AESTiny128D2Ev:0000000000000000 _ZN10AESTiny128D1Ev
     /tmp/ccvmC9sX.s:325    .text._ZN10AESTiny128D0Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:332    .text._ZN10AESTiny128D0Ev:0000000000000000 _ZN10AESTiny128D0Ev
.ARM.exidx.text._ZN10AESTiny128D0Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:365    .text._ZN10AESTiny12812encryptBlockEPhPKh:0000000000000000 $t
     /tmp/ccvmC9sX.s:372    .text._ZN10AESTiny12812encryptBlockEPhPKh:0000000000000000 _ZN10AESTiny12812encryptBlockEPhPKh
.ARM.exidx.text._ZN10AESTiny12812encryptBlockEPhPKh:0000000000000000 $d
     /tmp/ccvmC9sX.s:733    .text._ZN11AESSmall12812decryptBlockEPhPKh:0000000000000000 $t
     /tmp/ccvmC9sX.s:740    .text._ZN11AESSmall12812decryptBlockEPhPKh:0000000000000000 _ZN11AESSmall12812decryptBlockEPhPKh
.ARM.exidx.text._ZN11AESSmall12812decryptBlockEPhPKh:0000000000000000 $d
     /tmp/ccvmC9sX.s:1102   .text._ZN6AES1286setKeyEPKhj:0000000000000000 $t
     /tmp/ccvmC9sX.s:1109   .text._ZN6AES1286setKeyEPKhj:0000000000000000 _ZN6AES1286setKeyEPKhj
.ARM.exidx.text._ZN6AES1286setKeyEPKhj:0000000000000000 $d
     /tmp/ccvmC9sX.s:1284   .text._ZN11AESSmall1286setKeyEPKhj:0000000000000000 $t
     /tmp/ccvmC9sX.s:1291   .text._ZN11AESSmall1286setKeyEPKhj:0000000000000000 _ZN11AESSmall1286setKeyEPKhj
.ARM.exidx.text._ZN11AESSmall1286setKeyEPKhj:0000000000000000 $d
     /tmp/ccvmC9sX.s:1472   .text._ZN11AESSmall1285clearEv:0000000000000000 $t
     /tmp/ccvmC9sX.s:1479   .text._ZN11AESSmall1285clearEv:0000000000000000 _ZN11AESSmall1285clearEv
.ARM.exidx.text._ZN11AESSmall1285clearEv:0000000000000000 $d
     /tmp/ccvmC9sX.s:1561   .text._ZN11AESSmall128D2Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:1568   .text._ZN11AESSmall128D2Ev:0000000000000000 _ZN11AESSmall128D2Ev
     /tmp/ccvmC9sX.s:1623   .text._ZN11AESSmall128D2Ev:000000000000001c $d
.ARM.extab.text._ZN11AESSmall128D2Ev:0000000000000000 $d
.ARM.exidx.text._ZN11AESSmall128D2Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:1568   .text._ZN11AESSmall128D2Ev:0000000000000000 _ZN11AESSmall128D1Ev
     /tmp/ccvmC9sX.s:1641   .text._ZN11AESSmall128D0Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:1648   .text._ZN11AESSmall128D0Ev:0000000000000000 _ZN11AESSmall128D0Ev
.ARM.exidx.text._ZN11AESSmall128D0Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:1681   .text._ZN10AESTiny1285clearEv:0000000000000000 $t
     /tmp/ccvmC9sX.s:1688   .text._ZN10AESTiny1285clearEv:0000000000000000 _ZN10AESTiny1285clearEv
.ARM.exidx.text._ZN10AESTiny1285clearEv:0000000000000000 $d
     /tmp/ccvmC9sX.s:1718   .text._ZN6AES128C2Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:1725   .text._ZN6AES128C2Ev:0000000000000000 _ZN6AES128C2Ev
     /tmp/ccvmC9sX.s:1767   .text._ZN6AES128C2Ev:000000000000001c $d
   .ARM.exidx.text._ZN6AES128C2Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:1725   .text._ZN6AES128C2Ev:0000000000000000 _ZN6AES128C1Ev
     /tmp/ccvmC9sX.s:1775   .text._ZN10AESTiny128C2Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:1782   .text._ZN10AESTiny128C2Ev:0000000000000000 _ZN10AESTiny128C2Ev
     /tmp/ccvmC9sX.s:1815   .text._ZN10AESTiny128C2Ev:0000000000000010 $d
.ARM.exidx.text._ZN10AESTiny128C2Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:1782   .text._ZN10AESTiny128C2Ev:0000000000000000 _ZN10AESTiny128C1Ev
     /tmp/ccvmC9sX.s:1823   .text._ZN11AESSmall128C2Ev:0000000000000000 $t
     /tmp/ccvmC9sX.s:1830   .text._ZN11AESSmall128C2Ev:0000000000000000 _ZN11AESSmall128C2Ev
     /tmp/ccvmC9sX.s:1863   .text._ZN11AESSmall128C2Ev:0000000000000010 $d
.ARM.exidx.text._ZN11AESSmall128C2Ev:0000000000000000 $d
     /tmp/ccvmC9sX.s:1830   .text._ZN11AESSmall128C2Ev:0000000000000000 _ZN11AESSmall128C1Ev
     /tmp/ccvmC9sX.s:1923   .rodata:0000000000000078 _ZTS6AES128
     /tmp/ccvmC9sX.s:1927   .rodata:0000000000000080 _ZTI6AES128
     /tmp/ccvmC9sX.s:1933   .rodata:000000000000008c _ZTS10AESTiny128
     /tmp/ccvmC9sX.s:1938   .rodata:000000000000009c _ZTI10AESTiny128
     /tmp/ccvmC9sX.s:1944   .rodata:00000000000000a8 _ZTS11AESSmall128
     /tmp/ccvmC9sX.s:1949   .rodata:00000000000000b8 _ZTI11AESSmall128
     /tmp/ccvmC9sX.s:1884   .rodata:0000000000000000 _ZTV6AES128
     /tmp/ccvmC9sX.s:1897   .rodata:0000000000000028 _ZTV10AESTiny128
     /tmp/ccvmC9sX.s:1910   .rodata:0000000000000050 _ZTV11AESSmall128
     /tmp/ccvmC9sX.s:1880   .rodata:0000000000000000 $d

UNDEFINED SYMBOLS
_Z5cleanPvj
_ZN9AESCommonD2Ev
__gxx_personality_v0
_ZdlPvj
_ZN11BlockCipherD2Ev
_ZN9AESCommon15keyScheduleCoreEPhPKhh
_ZN9AESCommon20subBytesAndShiftRowsEPhPKh
_ZN9AESCommon9mixColumnEPhS0_
__aeabi_unwind_cpp_pr0
_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
_ZN9AESCommon16inverseMixColumnEPhPKh
_ZN9AESCommonC2Ev
_ZN11BlockCipherC2Ev
_ZNK9AESCommon9blockSizeEv
_ZN9AESCommon12encryptBlockEPhPKh
_ZN9AESCommon12decryptBlockEPhPKh
_ZN9AESCommon5clearEv
_ZTVN10__cxxabiv120__si_class_type_infoE
_ZTI9AESCommon
_ZTI11BlockCipher
