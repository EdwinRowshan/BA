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
  11              		.file	"AESCommon.cpp"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text._ZNK9AESCommon9blockSizeEv,"ax",%progbits
  16              		.align	1
  17              		.global	_ZNK9AESCommon9blockSizeEv
  18              		.arch armv7e-m
  19              		.syntax unified
  20              		.thumb
  21              		.thumb_func
  22              		.fpu softvfp
  24              	_ZNK9AESCommon9blockSizeEv:
  25              		.fnstart
  26              	.LVL0:
  27              	.LFB8:
  28              		.file 1 "AESCommon.cpp"
   1:AESCommon.cpp **** /*
   2:AESCommon.cpp ****  * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
   3:AESCommon.cpp ****  *
   4:AESCommon.cpp ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:AESCommon.cpp ****  * copy of this software and associated documentation files (the "Software"),
   6:AESCommon.cpp ****  * to deal in the Software without restriction, including without limitation
   7:AESCommon.cpp ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:AESCommon.cpp ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:AESCommon.cpp ****  * Software is furnished to do so, subject to the following conditions:
  10:AESCommon.cpp ****  *
  11:AESCommon.cpp ****  * The above copyright notice and this permission notice shall be included
  12:AESCommon.cpp ****  * in all copies or substantial portions of the Software.
  13:AESCommon.cpp ****  *
  14:AESCommon.cpp ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:AESCommon.cpp ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:AESCommon.cpp ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:AESCommon.cpp ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:AESCommon.cpp ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:AESCommon.cpp ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:AESCommon.cpp ****  * DEALINGS IN THE SOFTWARE.
  21:AESCommon.cpp ****  */
  22:AESCommon.cpp **** 
  23:AESCommon.cpp **** #include "AES.h"
  24:AESCommon.cpp **** #include "Crypto.h"
  25:AESCommon.cpp **** #include "ProgMemUtil.h"
  26:AESCommon.cpp **** 
  27:AESCommon.cpp **** #if defined(CRYPTO_AES_DEFAULT) || defined(CRYPTO_DOC)
  28:AESCommon.cpp **** 
  29:AESCommon.cpp **** /**
  30:AESCommon.cpp ****  * \class AESCommon AES.h <AES.h>
  31:AESCommon.cpp ****  * \brief Abstract base class for AES block ciphers.
  32:AESCommon.cpp ****  *
  33:AESCommon.cpp ****  * This class is abstract.  The caller should instantiate AES128,
  34:AESCommon.cpp ****  * AES192, or AES256 to create an AES block cipher with a specific
  35:AESCommon.cpp ****  * key size.
  36:AESCommon.cpp ****  *
  37:AESCommon.cpp ****  * \note This AES implementation does not have constant cache behaviour due
  38:AESCommon.cpp ****  * to the use of table lookups.  It may not be safe to use this implementation
  39:AESCommon.cpp ****  * in an environment where the attacker can observe the timing of encryption
  40:AESCommon.cpp ****  * and decryption operations.  Unless AES compatibility is required,
  41:AESCommon.cpp ****  * it is recommended that the ChaCha stream cipher be used instead.
  42:AESCommon.cpp ****  *
  43:AESCommon.cpp ****  * Reference: http://en.wikipedia.org/wiki/Advanced_Encryption_Standard
  44:AESCommon.cpp ****  *
  45:AESCommon.cpp ****  * \sa ChaCha, AES128, AES192, AES256
  46:AESCommon.cpp ****  */
  47:AESCommon.cpp **** 
  48:AESCommon.cpp **** /** @cond sbox */
  49:AESCommon.cpp **** 
  50:AESCommon.cpp **** // AES S-box (http://en.wikipedia.org/wiki/Rijndael_S-box)
  51:AESCommon.cpp **** static uint8_t const sbox[256] PROGMEM = {
  52:AESCommon.cpp ****     0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5,     // 0x00
  53:AESCommon.cpp ****     0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
  54:AESCommon.cpp ****     0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0,     // 0x10
  55:AESCommon.cpp ****     0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
  56:AESCommon.cpp ****     0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC,     // 0x20
  57:AESCommon.cpp ****     0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
  58:AESCommon.cpp ****     0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A,     // 0x30
  59:AESCommon.cpp ****     0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
  60:AESCommon.cpp ****     0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0,     // 0x40
  61:AESCommon.cpp ****     0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
  62:AESCommon.cpp ****     0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B,     // 0x50
  63:AESCommon.cpp ****     0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
  64:AESCommon.cpp ****     0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85,     // 0x60
  65:AESCommon.cpp ****     0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
  66:AESCommon.cpp ****     0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5,     // 0x70
  67:AESCommon.cpp ****     0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
  68:AESCommon.cpp ****     0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17,     // 0x80
  69:AESCommon.cpp ****     0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
  70:AESCommon.cpp ****     0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88,     // 0x90
  71:AESCommon.cpp ****     0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
  72:AESCommon.cpp ****     0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C,     // 0xA0
  73:AESCommon.cpp ****     0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
  74:AESCommon.cpp ****     0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9,     // 0xB0
  75:AESCommon.cpp ****     0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
  76:AESCommon.cpp ****     0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6,     // 0xC0
  77:AESCommon.cpp ****     0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
  78:AESCommon.cpp ****     0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E,     // 0xD0
  79:AESCommon.cpp ****     0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
  80:AESCommon.cpp ****     0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94,     // 0xE0
  81:AESCommon.cpp ****     0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
  82:AESCommon.cpp ****     0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68,     // 0xF0
  83:AESCommon.cpp ****     0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
  84:AESCommon.cpp **** };
  85:AESCommon.cpp **** 
  86:AESCommon.cpp **** // AES inverse S-box (http://en.wikipedia.org/wiki/Rijndael_S-box)
  87:AESCommon.cpp **** static uint8_t const sbox_inverse[256] PROGMEM = {
  88:AESCommon.cpp ****     0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38,     // 0x00
  89:AESCommon.cpp ****     0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
  90:AESCommon.cpp ****     0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87,     // 0x10
  91:AESCommon.cpp ****     0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
  92:AESCommon.cpp ****     0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D,     // 0x20
  93:AESCommon.cpp ****     0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
  94:AESCommon.cpp ****     0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2,     // 0x30
  95:AESCommon.cpp ****     0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
  96:AESCommon.cpp ****     0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16,     // 0x40
  97:AESCommon.cpp ****     0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
  98:AESCommon.cpp ****     0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA,     // 0x50
  99:AESCommon.cpp ****     0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
 100:AESCommon.cpp ****     0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A,     // 0x60
 101:AESCommon.cpp ****     0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
 102:AESCommon.cpp ****     0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02,     // 0x70
 103:AESCommon.cpp ****     0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
 104:AESCommon.cpp ****     0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA,     // 0x80
 105:AESCommon.cpp ****     0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
 106:AESCommon.cpp ****     0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85,     // 0x90
 107:AESCommon.cpp ****     0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
 108:AESCommon.cpp ****     0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89,     // 0xA0
 109:AESCommon.cpp ****     0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
 110:AESCommon.cpp ****     0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20,     // 0xB0
 111:AESCommon.cpp ****     0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
 112:AESCommon.cpp ****     0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31,     // 0xC0
 113:AESCommon.cpp ****     0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
 114:AESCommon.cpp ****     0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D,     // 0xD0
 115:AESCommon.cpp ****     0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
 116:AESCommon.cpp ****     0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0,     // 0xE0
 117:AESCommon.cpp ****     0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
 118:AESCommon.cpp ****     0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26,     // 0xF0
 119:AESCommon.cpp ****     0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
 120:AESCommon.cpp **** };
 121:AESCommon.cpp **** 
 122:AESCommon.cpp **** /** @endcond */
 123:AESCommon.cpp **** 
 124:AESCommon.cpp **** /**
 125:AESCommon.cpp ****  * \brief Constructs an AES block cipher object.
 126:AESCommon.cpp ****  */
 127:AESCommon.cpp **** AESCommon::AESCommon()
 128:AESCommon.cpp ****     : rounds(0), schedule(0)
 129:AESCommon.cpp **** {
 130:AESCommon.cpp **** }
 131:AESCommon.cpp **** 
 132:AESCommon.cpp **** /**
 133:AESCommon.cpp ****  * \brief Destroys this AES block cipher object after clearing
 134:AESCommon.cpp ****  * sensitive information.
 135:AESCommon.cpp ****  */
 136:AESCommon.cpp **** AESCommon::~AESCommon()
 137:AESCommon.cpp **** {
 138:AESCommon.cpp **** }
 139:AESCommon.cpp **** 
 140:AESCommon.cpp **** /**
 141:AESCommon.cpp ****  * \brief Size of an AES block in bytes.
 142:AESCommon.cpp ****  * \return Always returns 16.
 143:AESCommon.cpp ****  */
 144:AESCommon.cpp **** size_t AESCommon::blockSize() const
 145:AESCommon.cpp **** {
  29              		.loc 1 145 1 view -0
  30              		.cfi_startproc
  31              		@ args = 0, pretend = 0, frame = 0
  32              		@ frame_needed = 0, uses_anonymous_args = 0
  33              		@ link register save eliminated.
 146:AESCommon.cpp ****     return 16;
  34              		.loc 1 146 5 view .LVU1
 147:AESCommon.cpp **** }
  35              		.loc 1 147 1 is_stmt 0 view .LVU2
  36 0000 1020     		movs	r0, #16
  37              	.LVL1:
  38              		.loc 1 147 1 view .LVU3
  39 0002 7047     		bx	lr
  40              		.cfi_endproc
  41              	.LFE8:
  42              		.cantunwind
  43              		.fnend
  45              		.section	.text._ZN9AESCommon5clearEv,"ax",%progbits
  46              		.align	1
  47              		.global	_ZN9AESCommon5clearEv
  48              		.syntax unified
  49              		.thumb
  50              		.thumb_func
  51              		.fpu softvfp
  53              	_ZN9AESCommon5clearEv:
  54              		.fnstart
  55              	.LVL2:
  56              	.LFB15:
 148:AESCommon.cpp **** 
 149:AESCommon.cpp **** // Constants to correct Galois multiplication for the high bits
 150:AESCommon.cpp **** // that are shifted out when multiplying by powers of two.
 151:AESCommon.cpp **** static uint8_t const K[8] = {
 152:AESCommon.cpp ****     0x00,
 153:AESCommon.cpp ****     0x1B,
 154:AESCommon.cpp ****     (0x1B << 1),
 155:AESCommon.cpp ****     (0x1B << 1) ^ 0x1B,
 156:AESCommon.cpp ****     (0x1B << 2),
 157:AESCommon.cpp ****     (0x1B << 2) ^ 0x1B,
 158:AESCommon.cpp ****     (0x1B << 2) ^ (0x1B << 1),
 159:AESCommon.cpp ****     (0x1B << 2) ^ (0x1B << 1) ^ 0x1B
 160:AESCommon.cpp **** };
 161:AESCommon.cpp **** 
 162:AESCommon.cpp **** // Multiply x by 2 in the Galois field, to achieve the effect of the following:
 163:AESCommon.cpp **** //
 164:AESCommon.cpp **** //     if (x & 0x80)
 165:AESCommon.cpp **** //         return (x << 1) ^ 0x1B;
 166:AESCommon.cpp **** //     else
 167:AESCommon.cpp **** //         return (x << 1);
 168:AESCommon.cpp **** //
 169:AESCommon.cpp **** // However, we don't want to use runtime conditionals if we can help it
 170:AESCommon.cpp **** // to avoid leaking timing information from the implementation.
 171:AESCommon.cpp **** // In this case, multiplication is slightly faster than table lookup on AVR.
 172:AESCommon.cpp **** #define gmul2(x)    (t = ((uint16_t)(x)) << 1, \
 173:AESCommon.cpp ****                      ((uint8_t)t) ^ (uint8_t)(0x1B * ((uint8_t)(t >> 8))))
 174:AESCommon.cpp **** 
 175:AESCommon.cpp **** // Multiply x by 4 in the Galois field.
 176:AESCommon.cpp **** #define gmul4(x)    (t = ((uint16_t)(x)) << 2, ((uint8_t)t) ^ K[t >> 8])
 177:AESCommon.cpp **** 
 178:AESCommon.cpp **** // Multiply x by 8 in the Galois field.
 179:AESCommon.cpp **** #define gmul8(x)    (t = ((uint16_t)(x)) << 3, ((uint8_t)t) ^ K[t >> 8])
 180:AESCommon.cpp **** 
 181:AESCommon.cpp **** #define OUT(col, row)   output[(col) * 4 + (row)]
 182:AESCommon.cpp **** #define IN(col, row)    input[(col) * 4 + (row)]
 183:AESCommon.cpp **** 
 184:AESCommon.cpp **** /** @cond aes_funcs */
 185:AESCommon.cpp **** 
 186:AESCommon.cpp **** void AESCommon::subBytesAndShiftRows(uint8_t *output, const uint8_t *input)
 187:AESCommon.cpp **** {
 188:AESCommon.cpp ****     OUT(0, 0) = pgm_read_byte(sbox + IN(0, 0));
 189:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox + IN(1, 1));
 190:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox + IN(2, 2));
 191:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox + IN(3, 3));
 192:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox + IN(1, 0));
 193:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox + IN(2, 1));
 194:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox + IN(3, 2));
 195:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox + IN(0, 3));
 196:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox + IN(2, 0));
 197:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox + IN(3, 1));
 198:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox + IN(0, 2));
 199:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox + IN(1, 3));
 200:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox + IN(3, 0));
 201:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox + IN(0, 1));
 202:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox + IN(1, 2));
 203:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox + IN(2, 3));
 204:AESCommon.cpp **** }
 205:AESCommon.cpp **** 
 206:AESCommon.cpp **** void AESCommon::inverseShiftRowsAndSubBytes(uint8_t *output, const uint8_t *input)
 207:AESCommon.cpp **** {
 208:AESCommon.cpp ****     OUT(0, 0) = pgm_read_byte(sbox_inverse + IN(0, 0));
 209:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox_inverse + IN(3, 1));
 210:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox_inverse + IN(2, 2));
 211:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox_inverse + IN(1, 3));
 212:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox_inverse + IN(1, 0));
 213:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox_inverse + IN(0, 1));
 214:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox_inverse + IN(3, 2));
 215:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox_inverse + IN(2, 3));
 216:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox_inverse + IN(2, 0));
 217:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox_inverse + IN(1, 1));
 218:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox_inverse + IN(0, 2));
 219:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox_inverse + IN(3, 3));
 220:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox_inverse + IN(3, 0));
 221:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox_inverse + IN(2, 1));
 222:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox_inverse + IN(1, 2));
 223:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox_inverse + IN(0, 3));
 224:AESCommon.cpp **** }
 225:AESCommon.cpp **** 
 226:AESCommon.cpp **** void AESCommon::mixColumn(uint8_t *output, uint8_t *input)
 227:AESCommon.cpp **** {
 228:AESCommon.cpp ****     uint16_t t; // Needed by the gmul2 macro.
 229:AESCommon.cpp ****     uint8_t a = input[0];
 230:AESCommon.cpp ****     uint8_t b = input[1];
 231:AESCommon.cpp ****     uint8_t c = input[2];
 232:AESCommon.cpp ****     uint8_t d = input[3];
 233:AESCommon.cpp ****     uint8_t a2 = gmul2(a);
 234:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 235:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 236:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 237:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 238:AESCommon.cpp ****     output[1] = a ^ b2 ^ c2 ^ c ^ d;
 239:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 240:AESCommon.cpp ****     output[3] = a2 ^ a ^ b ^ c ^ d2;
 241:AESCommon.cpp **** }
 242:AESCommon.cpp **** 
 243:AESCommon.cpp **** void AESCommon::inverseMixColumn(uint8_t *output, const uint8_t *input)
 244:AESCommon.cpp **** {
 245:AESCommon.cpp ****     uint16_t t; // Needed by the gmul2, gmul4, and gmul8 macros.
 246:AESCommon.cpp ****     uint8_t a = input[0];
 247:AESCommon.cpp ****     uint8_t b = input[1];
 248:AESCommon.cpp ****     uint8_t c = input[2];
 249:AESCommon.cpp ****     uint8_t d = input[3];
 250:AESCommon.cpp ****     uint8_t a2 = gmul2(a);
 251:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 252:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 253:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 254:AESCommon.cpp ****     uint8_t a4 = gmul4(a);
 255:AESCommon.cpp ****     uint8_t b4 = gmul4(b);
 256:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 257:AESCommon.cpp ****     uint8_t d4 = gmul4(d);
 258:AESCommon.cpp ****     uint8_t a8 = gmul8(a);
 259:AESCommon.cpp ****     uint8_t b8 = gmul8(b);
 260:AESCommon.cpp ****     uint8_t c8 = gmul8(c);
 261:AESCommon.cpp ****     uint8_t d8 = gmul8(d);
 262:AESCommon.cpp ****     output[0] = a8 ^ a4 ^ a2 ^ b8 ^ b2 ^ b ^ c8 ^ c4 ^ c ^ d8 ^ d;
 263:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 264:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 265:AESCommon.cpp ****     output[3] = a8 ^ a2 ^ a ^ b8 ^ b4 ^ b ^ c8 ^ c ^ d8 ^ d4 ^ d2;
 266:AESCommon.cpp **** }
 267:AESCommon.cpp **** 
 268:AESCommon.cpp **** /** @endcond */
 269:AESCommon.cpp **** 
 270:AESCommon.cpp **** void AESCommon::encryptBlock(uint8_t *output, const uint8_t *input)
 271:AESCommon.cpp **** {
 272:AESCommon.cpp ****     const uint8_t *roundKey = schedule;
 273:AESCommon.cpp ****     uint8_t posn;
 274:AESCommon.cpp ****     uint8_t round;
 275:AESCommon.cpp ****     uint8_t state1[16];
 276:AESCommon.cpp ****     uint8_t state2[16];
 277:AESCommon.cpp **** 
 278:AESCommon.cpp ****     // Copy the input into the state and XOR with the first round key.
 279:AESCommon.cpp ****     for (posn = 0; posn < 16; ++posn)
 280:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 281:AESCommon.cpp ****     roundKey += 16;
 282:AESCommon.cpp **** 
 283:AESCommon.cpp ****     // Perform all rounds except the last.
 284:AESCommon.cpp ****     for (round = rounds; round > 1; --round) {
 285:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 286:AESCommon.cpp ****         mixColumn(state1,      state2);
 287:AESCommon.cpp ****         mixColumn(state1 + 4,  state2 + 4);
 288:AESCommon.cpp ****         mixColumn(state1 + 8,  state2 + 8);
 289:AESCommon.cpp ****         mixColumn(state1 + 12, state2 + 12);
 290:AESCommon.cpp ****         for (posn = 0; posn < 16; ++posn)
 291:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 292:AESCommon.cpp ****         roundKey += 16;
 293:AESCommon.cpp ****     }
 294:AESCommon.cpp **** 
 295:AESCommon.cpp ****     // Perform the final round.
 296:AESCommon.cpp ****     subBytesAndShiftRows(state2, state1);
 297:AESCommon.cpp ****     for (posn = 0; posn < 16; ++posn)
 298:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 299:AESCommon.cpp **** }
 300:AESCommon.cpp **** 
 301:AESCommon.cpp **** void AESCommon::decryptBlock(uint8_t *output, const uint8_t *input)
 302:AESCommon.cpp **** {
 303:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 304:AESCommon.cpp ****     uint8_t round;
 305:AESCommon.cpp ****     uint8_t posn;
 306:AESCommon.cpp ****     uint8_t state1[16];
 307:AESCommon.cpp ****     uint8_t state2[16];
 308:AESCommon.cpp **** 
 309:AESCommon.cpp ****     // Copy the input into the state and reverse the final round.
 310:AESCommon.cpp ****     for (posn = 0; posn < 16; ++posn)
 311:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 312:AESCommon.cpp ****     inverseShiftRowsAndSubBytes(state2, state1);
 313:AESCommon.cpp **** 
 314:AESCommon.cpp ****     // Perform all other rounds in reverse.
 315:AESCommon.cpp ****     for (round = rounds; round > 1; --round) {
 316:AESCommon.cpp ****         roundKey -= 16;
 317:AESCommon.cpp ****         for (posn = 0; posn < 16; ++posn)
 318:AESCommon.cpp ****             state2[posn] ^= roundKey[posn];
 319:AESCommon.cpp ****         inverseMixColumn(state1,      state2);
 320:AESCommon.cpp ****         inverseMixColumn(state1 + 4,  state2 + 4);
 321:AESCommon.cpp ****         inverseMixColumn(state1 + 8,  state2 + 8);
 322:AESCommon.cpp ****         inverseMixColumn(state1 + 12, state2 + 12);
 323:AESCommon.cpp ****         inverseShiftRowsAndSubBytes(state2, state1);
 324:AESCommon.cpp ****     }
 325:AESCommon.cpp **** 
 326:AESCommon.cpp ****     // Reverse the initial round and create the output words.
 327:AESCommon.cpp ****     roundKey -= 16;
 328:AESCommon.cpp ****     for (posn = 0; posn < 16; ++posn)
 329:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 330:AESCommon.cpp **** }
 331:AESCommon.cpp **** 
 332:AESCommon.cpp **** void AESCommon::clear()
 333:AESCommon.cpp **** {
  57              		.loc 1 333 1 is_stmt 1 view -0
  58              		.cfi_startproc
  59              		@ args = 0, pretend = 0, frame = 0
  60              		@ frame_needed = 0, uses_anonymous_args = 0
  61              		@ link register save eliminated.
 334:AESCommon.cpp ****     clean(schedule, (rounds + 1) * 16);
  62              		.loc 1 334 5 view .LVU5
  63              		.loc 1 334 22 is_stmt 0 view .LVU6
  64 0000 0179     		ldrb	r1, [r0, #4]	@ zero_extendqisi2
  65              		.loc 1 334 10 view .LVU7
  66 0002 8068     		ldr	r0, [r0, #8]
  67              	.LVL3:
  68              		.loc 1 334 29 view .LVU8
  69 0004 0131     		adds	r1, r1, #1
  70              		.loc 1 334 10 view .LVU9
  71 0006 0901     		lsls	r1, r1, #4
  72 0008 FFF7FEBF 		b	_Z5cleanPvj
  73              	.LVL4:
  74              		.cfi_endproc
  75              	.LFE15:
  76              		.cantunwind
  77              		.fnend
  79              		.section	.text._ZN9AESCommonC2Ev,"ax",%progbits
  80              		.align	1
  81              		.global	_ZN9AESCommonC2Ev
  82              		.syntax unified
  83              		.thumb
  84              		.thumb_func
  85              		.fpu softvfp
  87              	_ZN9AESCommonC2Ev:
  88              		.fnstart
  89              	.LVL5:
  90              	.LFB2:
 127:AESCommon.cpp ****     : rounds(0), schedule(0)
  91              		.loc 1 127 1 is_stmt 1 view -0
  92              		.cfi_startproc
  93              		@ args = 0, pretend = 0, frame = 0
  94              		@ frame_needed = 0, uses_anonymous_args = 0
 127:AESCommon.cpp ****     : rounds(0), schedule(0)
  95              		.loc 1 127 1 is_stmt 0 view .LVU11
  96 0000 10B5     		push	{r4, lr}
  97              		.save {r4, lr}
  98              	.LCFI0:
  99              		.cfi_def_cfa_offset 8
 100              		.cfi_offset 4, -8
 101              		.cfi_offset 14, -4
 127:AESCommon.cpp ****     : rounds(0), schedule(0)
 102              		.loc 1 127 1 view .LVU12
 103 0002 0446     		mov	r4, r0
 104              	.LBB2:
 128:AESCommon.cpp **** {
 105              		.loc 1 128 28 view .LVU13
 106 0004 FFF7FEFF 		bl	_ZN11BlockCipherC2Ev
 107              	.LVL6:
 128:AESCommon.cpp **** {
 108              		.loc 1 128 28 view .LVU14
 109 0008 034B     		ldr	r3, .L4
 110 000a 2360     		str	r3, [r4]
 111 000c 0023     		movs	r3, #0
 112 000e 2371     		strb	r3, [r4, #4]
 113 0010 A360     		str	r3, [r4, #8]
 114              	.LBE2:
 130:AESCommon.cpp **** 
 115              		.loc 1 130 1 view .LVU15
 116 0012 2046     		mov	r0, r4
 117 0014 10BD     		pop	{r4, pc}
 118              	.LVL7:
 119              	.L5:
 130:AESCommon.cpp **** 
 120              		.loc 1 130 1 view .LVU16
 121 0016 00BF     		.align	2
 122              	.L4:
 123 0018 08000000 		.word	.LANCHOR0+8
 124              		.cfi_endproc
 125              	.LFE2:
 126              		.fnend
 128              		.global	_ZN9AESCommonC1Ev
 129              		.thumb_set _ZN9AESCommonC1Ev,_ZN9AESCommonC2Ev
 130              		.section	.text._ZN9AESCommonD2Ev,"ax",%progbits
 131              		.align	1
 132              		.global	_ZN9AESCommonD2Ev
 133              		.syntax unified
 134              		.thumb
 135              		.thumb_func
 136              		.fpu softvfp
 138              	_ZN9AESCommonD2Ev:
 139              		.fnstart
 140              	.LVL8:
 141              	.LFB5:
 136:AESCommon.cpp **** {
 142              		.loc 1 136 1 is_stmt 1 view -0
 143              		.cfi_startproc
 144              		@ args = 0, pretend = 0, frame = 0
 145              		@ frame_needed = 0, uses_anonymous_args = 0
 136:AESCommon.cpp **** {
 146              		.loc 1 136 1 is_stmt 0 view .LVU18
 147 0000 10B5     		push	{r4, lr}
 148              	.LCFI1:
 149              		.cfi_def_cfa_offset 8
 150              		.cfi_offset 4, -8
 151              		.cfi_offset 14, -4
 152              	.LBB3:
 136:AESCommon.cpp **** {
 153              		.loc 1 136 23 view .LVU19
 154 0002 034B     		ldr	r3, .L7
 155 0004 0360     		str	r3, [r0]
 156              	.LBE3:
 136:AESCommon.cpp **** {
 157              		.loc 1 136 1 view .LVU20
 158 0006 0446     		mov	r4, r0
 159              	.LBB4:
 136:AESCommon.cpp **** {
 160              		.loc 1 136 23 view .LVU21
 161 0008 FFF7FEFF 		bl	_ZN11BlockCipherD2Ev
 162              	.LVL9:
 136:AESCommon.cpp **** {
 163              		.loc 1 136 23 view .LVU22
 164              	.LBE4:
 138:AESCommon.cpp **** 
 165              		.loc 1 138 1 view .LVU23
 166 000c 2046     		mov	r0, r4
 167 000e 10BD     		pop	{r4, pc}
 168              	.LVL10:
 169              	.L8:
 138:AESCommon.cpp **** 
 170              		.loc 1 138 1 view .LVU24
 171              		.align	2
 172              	.L7:
 173 0010 08000000 		.word	.LANCHOR0+8
 174              		.cfi_endproc
 175              	.LFE5:
 176              		.cantunwind
 177              		.fnend
 179              		.global	_ZN9AESCommonD1Ev
 180              		.thumb_set _ZN9AESCommonD1Ev,_ZN9AESCommonD2Ev
 181              		.section	.text._ZN9AESCommonD0Ev,"ax",%progbits
 182              		.align	1
 183              		.global	_ZN9AESCommonD0Ev
 184              		.syntax unified
 185              		.thumb
 186              		.thumb_func
 187              		.fpu softvfp
 189              	_ZN9AESCommonD0Ev:
 190              		.fnstart
 191              	.LVL11:
 192              	.LFB7:
 136:AESCommon.cpp **** {
 193              		.loc 1 136 1 is_stmt 1 view -0
 194              		.cfi_startproc
 195              		@ args = 0, pretend = 0, frame = 0
 196              		@ frame_needed = 0, uses_anonymous_args = 0
 136:AESCommon.cpp **** {
 197              		.loc 1 136 1 is_stmt 0 view .LVU26
 198 0000 10B5     		push	{r4, lr}
 199              	.LCFI2:
 200              		.cfi_def_cfa_offset 8
 201              		.cfi_offset 4, -8
 202              		.cfi_offset 14, -4
 136:AESCommon.cpp **** {
 203              		.loc 1 136 1 view .LVU27
 204 0002 0446     		mov	r4, r0
 138:AESCommon.cpp **** 
 205              		.loc 1 138 1 view .LVU28
 206 0004 FFF7FEFF 		bl	_ZN9AESCommonD1Ev
 207              	.LVL12:
 138:AESCommon.cpp **** 
 208              		.loc 1 138 1 view .LVU29
 209 0008 2046     		mov	r0, r4
 210 000a 0C21     		movs	r1, #12
 211 000c FFF7FEFF 		bl	_ZdlPvj
 212              	.LVL13:
 213 0010 2046     		mov	r0, r4
 214 0012 10BD     		pop	{r4, pc}
 138:AESCommon.cpp **** 
 215              		.loc 1 138 1 view .LVU30
 216              		.cfi_endproc
 217              	.LFE7:
 218              		.cantunwind
 219              		.fnend
 221              		.section	.text._ZN9AESCommon20subBytesAndShiftRowsEPhPKh,"ax",%progbits
 222              		.align	1
 223              		.global	_ZN9AESCommon20subBytesAndShiftRowsEPhPKh
 224              		.syntax unified
 225              		.thumb
 226              		.thumb_func
 227              		.fpu softvfp
 229              	_ZN9AESCommon20subBytesAndShiftRowsEPhPKh:
 230              		.fnstart
 231              	.LVL14:
 232              	.LFB9:
 187:AESCommon.cpp ****     OUT(0, 0) = pgm_read_byte(sbox + IN(0, 0));
 233              		.loc 1 187 1 is_stmt 1 view -0
 234              		.cfi_startproc
 235              		@ args = 0, pretend = 0, frame = 0
 236              		@ frame_needed = 0, uses_anonymous_args = 0
 237              		@ link register save eliminated.
 188:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox + IN(1, 1));
 238              		.loc 1 188 5 view .LVU32
 188:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox + IN(1, 1));
 239              		.loc 1 188 17 is_stmt 0 view .LVU33
 240 0000 284B     		ldr	r3, .L11
 241 0002 0A78     		ldrb	r2, [r1]	@ zero_extendqisi2
 242 0004 1A44     		add	r2, r2, r3
 243 0006 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 188:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox + IN(1, 1));
 244              		.loc 1 188 15 view .LVU34
 245 000a 0270     		strb	r2, [r0]
 189:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox + IN(2, 2));
 246              		.loc 1 189 5 is_stmt 1 view .LVU35
 189:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox + IN(2, 2));
 247              		.loc 1 189 17 is_stmt 0 view .LVU36
 248 000c 4A79     		ldrb	r2, [r1, #5]	@ zero_extendqisi2
 249 000e 1A44     		add	r2, r2, r3
 250 0010 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 189:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox + IN(2, 2));
 251              		.loc 1 189 15 view .LVU37
 252 0014 4270     		strb	r2, [r0, #1]
 190:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox + IN(3, 3));
 253              		.loc 1 190 5 is_stmt 1 view .LVU38
 190:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox + IN(3, 3));
 254              		.loc 1 190 17 is_stmt 0 view .LVU39
 255 0016 8A7A     		ldrb	r2, [r1, #10]	@ zero_extendqisi2
 256 0018 1A44     		add	r2, r2, r3
 257 001a 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 190:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox + IN(3, 3));
 258              		.loc 1 190 15 view .LVU40
 259 001e 8270     		strb	r2, [r0, #2]
 191:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox + IN(1, 0));
 260              		.loc 1 191 5 is_stmt 1 view .LVU41
 191:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox + IN(1, 0));
 261              		.loc 1 191 17 is_stmt 0 view .LVU42
 262 0020 CA7B     		ldrb	r2, [r1, #15]	@ zero_extendqisi2
 263 0022 1A44     		add	r2, r2, r3
 264 0024 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 191:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox + IN(1, 0));
 265              		.loc 1 191 15 view .LVU43
 266 0028 C270     		strb	r2, [r0, #3]
 192:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox + IN(2, 1));
 267              		.loc 1 192 5 is_stmt 1 view .LVU44
 192:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox + IN(2, 1));
 268              		.loc 1 192 17 is_stmt 0 view .LVU45
 269 002a 0A79     		ldrb	r2, [r1, #4]	@ zero_extendqisi2
 270 002c 1A44     		add	r2, r2, r3
 271 002e 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 192:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox + IN(2, 1));
 272              		.loc 1 192 15 view .LVU46
 273 0032 0271     		strb	r2, [r0, #4]
 193:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox + IN(3, 2));
 274              		.loc 1 193 5 is_stmt 1 view .LVU47
 193:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox + IN(3, 2));
 275              		.loc 1 193 17 is_stmt 0 view .LVU48
 276 0034 4A7A     		ldrb	r2, [r1, #9]	@ zero_extendqisi2
 277 0036 1A44     		add	r2, r2, r3
 278 0038 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 193:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox + IN(3, 2));
 279              		.loc 1 193 15 view .LVU49
 280 003c 4271     		strb	r2, [r0, #5]
 194:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox + IN(0, 3));
 281              		.loc 1 194 5 is_stmt 1 view .LVU50
 194:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox + IN(0, 3));
 282              		.loc 1 194 17 is_stmt 0 view .LVU51
 283 003e 8A7B     		ldrb	r2, [r1, #14]	@ zero_extendqisi2
 284 0040 1A44     		add	r2, r2, r3
 285 0042 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 194:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox + IN(0, 3));
 286              		.loc 1 194 15 view .LVU52
 287 0046 8271     		strb	r2, [r0, #6]
 195:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox + IN(2, 0));
 288              		.loc 1 195 5 is_stmt 1 view .LVU53
 195:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox + IN(2, 0));
 289              		.loc 1 195 17 is_stmt 0 view .LVU54
 290 0048 CA78     		ldrb	r2, [r1, #3]	@ zero_extendqisi2
 291 004a 1A44     		add	r2, r2, r3
 292 004c 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 195:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox + IN(2, 0));
 293              		.loc 1 195 15 view .LVU55
 294 0050 C271     		strb	r2, [r0, #7]
 196:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox + IN(3, 1));
 295              		.loc 1 196 5 is_stmt 1 view .LVU56
 196:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox + IN(3, 1));
 296              		.loc 1 196 17 is_stmt 0 view .LVU57
 297 0052 0A7A     		ldrb	r2, [r1, #8]	@ zero_extendqisi2
 298 0054 1A44     		add	r2, r2, r3
 299 0056 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 196:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox + IN(3, 1));
 300              		.loc 1 196 15 view .LVU58
 301 005a 0272     		strb	r2, [r0, #8]
 197:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox + IN(0, 2));
 302              		.loc 1 197 5 is_stmt 1 view .LVU59
 197:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox + IN(0, 2));
 303              		.loc 1 197 17 is_stmt 0 view .LVU60
 304 005c 4A7B     		ldrb	r2, [r1, #13]	@ zero_extendqisi2
 305 005e 1A44     		add	r2, r2, r3
 306 0060 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 197:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox + IN(0, 2));
 307              		.loc 1 197 15 view .LVU61
 308 0064 4272     		strb	r2, [r0, #9]
 198:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox + IN(1, 3));
 309              		.loc 1 198 5 is_stmt 1 view .LVU62
 198:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox + IN(1, 3));
 310              		.loc 1 198 17 is_stmt 0 view .LVU63
 311 0066 8A78     		ldrb	r2, [r1, #2]	@ zero_extendqisi2
 312 0068 1A44     		add	r2, r2, r3
 313 006a 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 198:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox + IN(1, 3));
 314              		.loc 1 198 15 view .LVU64
 315 006e 8272     		strb	r2, [r0, #10]
 199:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox + IN(3, 0));
 316              		.loc 1 199 5 is_stmt 1 view .LVU65
 199:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox + IN(3, 0));
 317              		.loc 1 199 17 is_stmt 0 view .LVU66
 318 0070 CA79     		ldrb	r2, [r1, #7]	@ zero_extendqisi2
 319 0072 1A44     		add	r2, r2, r3
 320 0074 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 199:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox + IN(3, 0));
 321              		.loc 1 199 15 view .LVU67
 322 0078 C272     		strb	r2, [r0, #11]
 200:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox + IN(0, 1));
 323              		.loc 1 200 5 is_stmt 1 view .LVU68
 200:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox + IN(0, 1));
 324              		.loc 1 200 17 is_stmt 0 view .LVU69
 325 007a 0A7B     		ldrb	r2, [r1, #12]	@ zero_extendqisi2
 326 007c 1A44     		add	r2, r2, r3
 327 007e 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 200:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox + IN(0, 1));
 328              		.loc 1 200 15 view .LVU70
 329 0082 0273     		strb	r2, [r0, #12]
 201:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox + IN(1, 2));
 330              		.loc 1 201 5 is_stmt 1 view .LVU71
 201:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox + IN(1, 2));
 331              		.loc 1 201 17 is_stmt 0 view .LVU72
 332 0084 4A78     		ldrb	r2, [r1, #1]	@ zero_extendqisi2
 333 0086 1A44     		add	r2, r2, r3
 334 0088 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 201:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox + IN(1, 2));
 335              		.loc 1 201 15 view .LVU73
 336 008c 4273     		strb	r2, [r0, #13]
 202:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox + IN(2, 3));
 337              		.loc 1 202 5 is_stmt 1 view .LVU74
 202:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox + IN(2, 3));
 338              		.loc 1 202 17 is_stmt 0 view .LVU75
 339 008e 8A79     		ldrb	r2, [r1, #6]	@ zero_extendqisi2
 340 0090 1A44     		add	r2, r2, r3
 341 0092 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 202:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox + IN(2, 3));
 342              		.loc 1 202 15 view .LVU76
 343 0096 8273     		strb	r2, [r0, #14]
 203:AESCommon.cpp **** }
 344              		.loc 1 203 5 is_stmt 1 view .LVU77
 203:AESCommon.cpp **** }
 345              		.loc 1 203 17 is_stmt 0 view .LVU78
 346 0098 CA7A     		ldrb	r2, [r1, #11]	@ zero_extendqisi2
 347 009a 1344     		add	r3, r3, r2
 348 009c 93F82830 		ldrb	r3, [r3, #40]	@ zero_extendqisi2
 203:AESCommon.cpp **** }
 349              		.loc 1 203 15 view .LVU79
 350 00a0 C373     		strb	r3, [r0, #15]
 204:AESCommon.cpp **** 
 351              		.loc 1 204 1 view .LVU80
 352 00a2 7047     		bx	lr
 353              	.L12:
 354              		.align	2
 355              	.L11:
 356 00a4 00000000 		.word	.LANCHOR0
 357              		.cfi_endproc
 358              	.LFE9:
 359              		.cantunwind
 360              		.fnend
 362              		.section	.text._ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh,"ax",%progbits
 363              		.align	1
 364              		.global	_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
 365              		.syntax unified
 366              		.thumb
 367              		.thumb_func
 368              		.fpu softvfp
 370              	_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh:
 371              		.fnstart
 372              	.LVL15:
 373              	.LFB10:
 207:AESCommon.cpp ****     OUT(0, 0) = pgm_read_byte(sbox_inverse + IN(0, 0));
 374              		.loc 1 207 1 is_stmt 1 view -0
 375              		.cfi_startproc
 376              		@ args = 0, pretend = 0, frame = 0
 377              		@ frame_needed = 0, uses_anonymous_args = 0
 378              		@ link register save eliminated.
 208:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox_inverse + IN(3, 1));
 379              		.loc 1 208 5 view .LVU82
 208:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox_inverse + IN(3, 1));
 380              		.loc 1 208 17 is_stmt 0 view .LVU83
 381 0000 284B     		ldr	r3, .L14
 382 0002 0A78     		ldrb	r2, [r1]	@ zero_extendqisi2
 383 0004 1A44     		add	r2, r2, r3
 384 0006 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 208:AESCommon.cpp ****     OUT(0, 1) = pgm_read_byte(sbox_inverse + IN(3, 1));
 385              		.loc 1 208 15 view .LVU84
 386 000a 0270     		strb	r2, [r0]
 209:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox_inverse + IN(2, 2));
 387              		.loc 1 209 5 is_stmt 1 view .LVU85
 209:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox_inverse + IN(2, 2));
 388              		.loc 1 209 17 is_stmt 0 view .LVU86
 389 000c 4A7B     		ldrb	r2, [r1, #13]	@ zero_extendqisi2
 390 000e 1A44     		add	r2, r2, r3
 391 0010 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 209:AESCommon.cpp ****     OUT(0, 2) = pgm_read_byte(sbox_inverse + IN(2, 2));
 392              		.loc 1 209 15 view .LVU87
 393 0014 4270     		strb	r2, [r0, #1]
 210:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox_inverse + IN(1, 3));
 394              		.loc 1 210 5 is_stmt 1 view .LVU88
 210:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox_inverse + IN(1, 3));
 395              		.loc 1 210 17 is_stmt 0 view .LVU89
 396 0016 8A7A     		ldrb	r2, [r1, #10]	@ zero_extendqisi2
 397 0018 1A44     		add	r2, r2, r3
 398 001a 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 210:AESCommon.cpp ****     OUT(0, 3) = pgm_read_byte(sbox_inverse + IN(1, 3));
 399              		.loc 1 210 15 view .LVU90
 400 001e 8270     		strb	r2, [r0, #2]
 211:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox_inverse + IN(1, 0));
 401              		.loc 1 211 5 is_stmt 1 view .LVU91
 211:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox_inverse + IN(1, 0));
 402              		.loc 1 211 17 is_stmt 0 view .LVU92
 403 0020 CA79     		ldrb	r2, [r1, #7]	@ zero_extendqisi2
 404 0022 1A44     		add	r2, r2, r3
 405 0024 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 211:AESCommon.cpp ****     OUT(1, 0) = pgm_read_byte(sbox_inverse + IN(1, 0));
 406              		.loc 1 211 15 view .LVU93
 407 0028 C270     		strb	r2, [r0, #3]
 212:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox_inverse + IN(0, 1));
 408              		.loc 1 212 5 is_stmt 1 view .LVU94
 212:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox_inverse + IN(0, 1));
 409              		.loc 1 212 17 is_stmt 0 view .LVU95
 410 002a 0A79     		ldrb	r2, [r1, #4]	@ zero_extendqisi2
 411 002c 1A44     		add	r2, r2, r3
 412 002e 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 212:AESCommon.cpp ****     OUT(1, 1) = pgm_read_byte(sbox_inverse + IN(0, 1));
 413              		.loc 1 212 15 view .LVU96
 414 0032 0271     		strb	r2, [r0, #4]
 213:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox_inverse + IN(3, 2));
 415              		.loc 1 213 5 is_stmt 1 view .LVU97
 213:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox_inverse + IN(3, 2));
 416              		.loc 1 213 17 is_stmt 0 view .LVU98
 417 0034 4A78     		ldrb	r2, [r1, #1]	@ zero_extendqisi2
 418 0036 1A44     		add	r2, r2, r3
 419 0038 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 213:AESCommon.cpp ****     OUT(1, 2) = pgm_read_byte(sbox_inverse + IN(3, 2));
 420              		.loc 1 213 15 view .LVU99
 421 003c 4271     		strb	r2, [r0, #5]
 214:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox_inverse + IN(2, 3));
 422              		.loc 1 214 5 is_stmt 1 view .LVU100
 214:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox_inverse + IN(2, 3));
 423              		.loc 1 214 17 is_stmt 0 view .LVU101
 424 003e 8A7B     		ldrb	r2, [r1, #14]	@ zero_extendqisi2
 425 0040 1A44     		add	r2, r2, r3
 426 0042 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 214:AESCommon.cpp ****     OUT(1, 3) = pgm_read_byte(sbox_inverse + IN(2, 3));
 427              		.loc 1 214 15 view .LVU102
 428 0046 8271     		strb	r2, [r0, #6]
 215:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox_inverse + IN(2, 0));
 429              		.loc 1 215 5 is_stmt 1 view .LVU103
 215:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox_inverse + IN(2, 0));
 430              		.loc 1 215 17 is_stmt 0 view .LVU104
 431 0048 CA7A     		ldrb	r2, [r1, #11]	@ zero_extendqisi2
 432 004a 1A44     		add	r2, r2, r3
 433 004c 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 215:AESCommon.cpp ****     OUT(2, 0) = pgm_read_byte(sbox_inverse + IN(2, 0));
 434              		.loc 1 215 15 view .LVU105
 435 0050 C271     		strb	r2, [r0, #7]
 216:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox_inverse + IN(1, 1));
 436              		.loc 1 216 5 is_stmt 1 view .LVU106
 216:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox_inverse + IN(1, 1));
 437              		.loc 1 216 17 is_stmt 0 view .LVU107
 438 0052 0A7A     		ldrb	r2, [r1, #8]	@ zero_extendqisi2
 439 0054 1A44     		add	r2, r2, r3
 440 0056 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 216:AESCommon.cpp ****     OUT(2, 1) = pgm_read_byte(sbox_inverse + IN(1, 1));
 441              		.loc 1 216 15 view .LVU108
 442 005a 0272     		strb	r2, [r0, #8]
 217:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox_inverse + IN(0, 2));
 443              		.loc 1 217 5 is_stmt 1 view .LVU109
 217:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox_inverse + IN(0, 2));
 444              		.loc 1 217 17 is_stmt 0 view .LVU110
 445 005c 4A79     		ldrb	r2, [r1, #5]	@ zero_extendqisi2
 446 005e 1A44     		add	r2, r2, r3
 447 0060 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 217:AESCommon.cpp ****     OUT(2, 2) = pgm_read_byte(sbox_inverse + IN(0, 2));
 448              		.loc 1 217 15 view .LVU111
 449 0064 4272     		strb	r2, [r0, #9]
 218:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox_inverse + IN(3, 3));
 450              		.loc 1 218 5 is_stmt 1 view .LVU112
 218:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox_inverse + IN(3, 3));
 451              		.loc 1 218 17 is_stmt 0 view .LVU113
 452 0066 8A78     		ldrb	r2, [r1, #2]	@ zero_extendqisi2
 453 0068 1A44     		add	r2, r2, r3
 454 006a 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 218:AESCommon.cpp ****     OUT(2, 3) = pgm_read_byte(sbox_inverse + IN(3, 3));
 455              		.loc 1 218 15 view .LVU114
 456 006e 8272     		strb	r2, [r0, #10]
 219:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox_inverse + IN(3, 0));
 457              		.loc 1 219 5 is_stmt 1 view .LVU115
 219:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox_inverse + IN(3, 0));
 458              		.loc 1 219 17 is_stmt 0 view .LVU116
 459 0070 CA7B     		ldrb	r2, [r1, #15]	@ zero_extendqisi2
 460 0072 1A44     		add	r2, r2, r3
 461 0074 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 219:AESCommon.cpp ****     OUT(3, 0) = pgm_read_byte(sbox_inverse + IN(3, 0));
 462              		.loc 1 219 15 view .LVU117
 463 0078 C272     		strb	r2, [r0, #11]
 220:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox_inverse + IN(2, 1));
 464              		.loc 1 220 5 is_stmt 1 view .LVU118
 220:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox_inverse + IN(2, 1));
 465              		.loc 1 220 17 is_stmt 0 view .LVU119
 466 007a 0A7B     		ldrb	r2, [r1, #12]	@ zero_extendqisi2
 467 007c 1A44     		add	r2, r2, r3
 468 007e 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 220:AESCommon.cpp ****     OUT(3, 1) = pgm_read_byte(sbox_inverse + IN(2, 1));
 469              		.loc 1 220 15 view .LVU120
 470 0082 0273     		strb	r2, [r0, #12]
 221:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox_inverse + IN(1, 2));
 471              		.loc 1 221 5 is_stmt 1 view .LVU121
 221:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox_inverse + IN(1, 2));
 472              		.loc 1 221 17 is_stmt 0 view .LVU122
 473 0084 4A7A     		ldrb	r2, [r1, #9]	@ zero_extendqisi2
 474 0086 1A44     		add	r2, r2, r3
 475 0088 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 221:AESCommon.cpp ****     OUT(3, 2) = pgm_read_byte(sbox_inverse + IN(1, 2));
 476              		.loc 1 221 15 view .LVU123
 477 008c 4273     		strb	r2, [r0, #13]
 222:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox_inverse + IN(0, 3));
 478              		.loc 1 222 5 is_stmt 1 view .LVU124
 222:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox_inverse + IN(0, 3));
 479              		.loc 1 222 17 is_stmt 0 view .LVU125
 480 008e 8A79     		ldrb	r2, [r1, #6]	@ zero_extendqisi2
 481 0090 1A44     		add	r2, r2, r3
 482 0092 92F82821 		ldrb	r2, [r2, #296]	@ zero_extendqisi2
 222:AESCommon.cpp ****     OUT(3, 3) = pgm_read_byte(sbox_inverse + IN(0, 3));
 483              		.loc 1 222 15 view .LVU126
 484 0096 8273     		strb	r2, [r0, #14]
 223:AESCommon.cpp **** }
 485              		.loc 1 223 5 is_stmt 1 view .LVU127
 223:AESCommon.cpp **** }
 486              		.loc 1 223 17 is_stmt 0 view .LVU128
 487 0098 CA78     		ldrb	r2, [r1, #3]	@ zero_extendqisi2
 488 009a 1344     		add	r3, r3, r2
 489 009c 93F82831 		ldrb	r3, [r3, #296]	@ zero_extendqisi2
 223:AESCommon.cpp **** }
 490              		.loc 1 223 15 view .LVU129
 491 00a0 C373     		strb	r3, [r0, #15]
 224:AESCommon.cpp **** 
 492              		.loc 1 224 1 view .LVU130
 493 00a2 7047     		bx	lr
 494              	.L15:
 495              		.align	2
 496              	.L14:
 497 00a4 00000000 		.word	.LANCHOR0
 498              		.cfi_endproc
 499              	.LFE10:
 500              		.cantunwind
 501              		.fnend
 503              		.section	.text._ZN9AESCommon9mixColumnEPhS0_,"ax",%progbits
 504              		.align	1
 505              		.global	_ZN9AESCommon9mixColumnEPhS0_
 506              		.syntax unified
 507              		.thumb
 508              		.thumb_func
 509              		.fpu softvfp
 511              	_ZN9AESCommon9mixColumnEPhS0_:
 512              		.fnstart
 513              	.LVL16:
 514              	.LFB11:
 227:AESCommon.cpp ****     uint16_t t; // Needed by the gmul2 macro.
 515              		.loc 1 227 1 is_stmt 1 view -0
 516              		.cfi_startproc
 517              		@ args = 0, pretend = 0, frame = 0
 518              		@ frame_needed = 0, uses_anonymous_args = 0
 228:AESCommon.cpp ****     uint8_t a = input[0];
 519              		.loc 1 228 5 view .LVU132
 229:AESCommon.cpp ****     uint8_t b = input[1];
 520              		.loc 1 229 5 view .LVU133
 227:AESCommon.cpp ****     uint16_t t; // Needed by the gmul2 macro.
 521              		.loc 1 227 1 is_stmt 0 view .LVU134
 522 0000 F0B5     		push	{r4, r5, r6, r7, lr}
 523              	.LCFI3:
 524              		.cfi_def_cfa_offset 20
 525              		.cfi_offset 4, -20
 526              		.cfi_offset 5, -16
 527              		.cfi_offset 6, -12
 528              		.cfi_offset 7, -8
 529              		.cfi_offset 14, -4
 229:AESCommon.cpp ****     uint8_t b = input[1];
 530              		.loc 1 229 13 view .LVU135
 531 0002 0E78     		ldrb	r6, [r1]	@ zero_extendqisi2
 532              	.LVL17:
 230:AESCommon.cpp ****     uint8_t c = input[2];
 533              		.loc 1 230 5 is_stmt 1 view .LVU136
 230:AESCommon.cpp ****     uint8_t c = input[2];
 534              		.loc 1 230 13 is_stmt 0 view .LVU137
 535 0004 91F801C0 		ldrb	ip, [r1, #1]	@ zero_extendqisi2
 536              	.LVL18:
 231:AESCommon.cpp ****     uint8_t d = input[3];
 537              		.loc 1 231 5 is_stmt 1 view .LVU138
 231:AESCommon.cpp ****     uint8_t d = input[3];
 538              		.loc 1 231 13 is_stmt 0 view .LVU139
 539 0008 8D78     		ldrb	r5, [r1, #2]	@ zero_extendqisi2
 540              	.LVL19:
 232:AESCommon.cpp ****     uint8_t a2 = gmul2(a);
 541              		.loc 1 232 5 is_stmt 1 view .LVU140
 232:AESCommon.cpp ****     uint8_t a2 = gmul2(a);
 542              		.loc 1 232 13 is_stmt 0 view .LVU141
 543 000a CF78     		ldrb	r7, [r1, #3]	@ zero_extendqisi2
 544              	.LVL20:
 233:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 545              		.loc 1 233 5 is_stmt 1 view .LVU142
 233:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 546              		.loc 1 233 18 is_stmt 0 view .LVU143
 547 000c F409     		lsrs	r4, r6, #7
 548 000e 04EB4404 		add	r4, r4, r4, lsl #1
 234:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 549              		.loc 1 234 18 view .LVU144
 550 0012 4FEADC11 		lsr	r1, ip, #7
 551              	.LVL21:
 233:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 552              		.loc 1 233 18 view .LVU145
 553 0016 04EBC404 		add	r4, r4, r4, lsl #3
 234:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 554              		.loc 1 234 18 view .LVU146
 555 001a 01EB4101 		add	r1, r1, r1, lsl #1
 233:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 556              		.loc 1 233 18 view .LVU147
 557 001e 84EA4604 		eor	r4, r4, r6, lsl #1
 237:AESCommon.cpp ****     output[1] = a ^ b2 ^ c2 ^ c ^ d;
 558              		.loc 1 237 33 view .LVU148
 559 0022 8CEA050E 		eor	lr, ip, r5
 234:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 560              		.loc 1 234 18 view .LVU149
 561 0026 01EBC101 		add	r1, r1, r1, lsl #3
 233:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 562              		.loc 1 233 18 view .LVU150
 563 002a E4B2     		uxtb	r4, r4
 564              	.LVL22:
 234:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 565              		.loc 1 234 5 is_stmt 1 view .LVU151
 235:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 566              		.loc 1 235 18 is_stmt 0 view .LVU152
 567 002c EB09     		lsrs	r3, r5, #7
 237:AESCommon.cpp ****     output[1] = a ^ b2 ^ c2 ^ c ^ d;
 568              		.loc 1 237 33 view .LVU153
 569 002e 87EA0E0E 		eor	lr, r7, lr
 234:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 570              		.loc 1 234 18 view .LVU154
 571 0032 81EA4C01 		eor	r1, r1, ip, lsl #1
 572 0036 C9B2     		uxtb	r1, r1
 573              	.LVL23:
 235:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 574              		.loc 1 235 5 is_stmt 1 view .LVU155
 236:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 575              		.loc 1 236 18 is_stmt 0 view .LVU156
 576 0038 FA09     		lsrs	r2, r7, #7
 235:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 577              		.loc 1 235 18 view .LVU157
 578 003a 03EB4303 		add	r3, r3, r3, lsl #1
 237:AESCommon.cpp ****     output[1] = a ^ b2 ^ c2 ^ c ^ d;
 579              		.loc 1 237 33 view .LVU158
 580 003e 84EA0E0E 		eor	lr, r4, lr
 581 0042 81EA0E0E 		eor	lr, r1, lr
 235:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 582              		.loc 1 235 18 view .LVU159
 583 0046 03EBC303 		add	r3, r3, r3, lsl #3
 236:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 584              		.loc 1 236 18 view .LVU160
 585 004a 02EB4202 		add	r2, r2, r2, lsl #1
 235:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 586              		.loc 1 235 18 view .LVU161
 587 004e 83EA4503 		eor	r3, r3, r5, lsl #1
 236:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 588              		.loc 1 236 18 view .LVU162
 589 0052 02EBC202 		add	r2, r2, r2, lsl #3
 237:AESCommon.cpp ****     output[1] = a ^ b2 ^ c2 ^ c ^ d;
 590              		.loc 1 237 15 view .LVU163
 591 0056 80F800E0 		strb	lr, [r0]
 238:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 592              		.loc 1 238 33 view .LVU164
 593 005a 86EA050E 		eor	lr, r6, r5
 594 005e 86EA0C06 		eor	r6, r6, ip
 595              	.LVL24:
 235:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 596              		.loc 1 235 18 view .LVU165
 597 0062 DBB2     		uxtb	r3, r3
 598              	.LVL25:
 236:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 599              		.loc 1 236 5 is_stmt 1 view .LVU166
 236:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 600              		.loc 1 236 18 is_stmt 0 view .LVU167
 601 0064 82EA4702 		eor	r2, r2, r7, lsl #1
 238:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 602              		.loc 1 238 33 view .LVU168
 603 0068 87EA0E0E 		eor	lr, r7, lr
 240:AESCommon.cpp **** }
 604              		.loc 1 240 28 view .LVU169
 605 006c 7540     		eors	r5, r5, r6
 606              	.LVL26:
 239:AESCommon.cpp ****     output[3] = a2 ^ a ^ b ^ c ^ d2;
 607              		.loc 1 239 33 view .LVU170
 608 006e 7740     		eors	r7, r7, r6
 609              	.LVL27:
 236:AESCommon.cpp ****     output[0] = a2 ^ b2 ^ b ^ c ^ d;
 610              		.loc 1 236 18 view .LVU171
 611 0070 D2B2     		uxtb	r2, r2
 612              	.LVL28:
 237:AESCommon.cpp ****     output[1] = a ^ b2 ^ c2 ^ c ^ d;
 613              		.loc 1 237 5 is_stmt 1 view .LVU172
 238:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 614              		.loc 1 238 5 view .LVU173
 238:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 615              		.loc 1 238 33 is_stmt 0 view .LVU174
 616 0072 81EA0E01 		eor	r1, r1, lr
 617              	.LVL29:
 239:AESCommon.cpp ****     output[3] = a2 ^ a ^ b ^ c ^ d2;
 618              		.loc 1 239 33 view .LVU175
 619 0076 5F40     		eors	r7, r7, r3
 240:AESCommon.cpp **** }
 620              		.loc 1 240 28 view .LVU176
 621 0078 6540     		eors	r5, r5, r4
 239:AESCommon.cpp ****     output[3] = a2 ^ a ^ b ^ c ^ d2;
 622              		.loc 1 239 33 view .LVU177
 623 007a 5740     		eors	r7, r7, r2
 238:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 624              		.loc 1 238 33 view .LVU178
 625 007c 5940     		eors	r1, r1, r3
 240:AESCommon.cpp **** }
 626              		.loc 1 240 32 view .LVU179
 627 007e 6A40     		eors	r2, r2, r5
 628              	.LVL30:
 238:AESCommon.cpp ****     output[2] = a ^ b ^ c2 ^ d2 ^ d;
 629              		.loc 1 238 15 view .LVU180
 630 0080 4170     		strb	r1, [r0, #1]
 239:AESCommon.cpp ****     output[3] = a2 ^ a ^ b ^ c ^ d2;
 631              		.loc 1 239 5 is_stmt 1 view .LVU181
 239:AESCommon.cpp ****     output[3] = a2 ^ a ^ b ^ c ^ d2;
 632              		.loc 1 239 15 is_stmt 0 view .LVU182
 633 0082 8770     		strb	r7, [r0, #2]
 240:AESCommon.cpp **** }
 634              		.loc 1 240 5 is_stmt 1 view .LVU183
 240:AESCommon.cpp **** }
 635              		.loc 1 240 15 is_stmt 0 view .LVU184
 636 0084 C270     		strb	r2, [r0, #3]
 241:AESCommon.cpp **** 
 637              		.loc 1 241 1 view .LVU185
 638 0086 F0BD     		pop	{r4, r5, r6, r7, pc}
 241:AESCommon.cpp **** 
 639              		.loc 1 241 1 view .LVU186
 640              		.cfi_endproc
 641              	.LFE11:
 642              		.cantunwind
 643              		.fnend
 645              		.section	.text._ZN9AESCommon12encryptBlockEPhPKh,"ax",%progbits
 646              		.align	1
 647              		.global	_ZN9AESCommon12encryptBlockEPhPKh
 648              		.syntax unified
 649              		.thumb
 650              		.thumb_func
 651              		.fpu softvfp
 653              	_ZN9AESCommon12encryptBlockEPhPKh:
 654              		.fnstart
 655              	.LVL31:
 656              	.LFB13:
 271:AESCommon.cpp ****     const uint8_t *roundKey = schedule;
 657              		.loc 1 271 1 is_stmt 1 view -0
 658              		.cfi_startproc
 659              		@ args = 0, pretend = 0, frame = 32
 660              		@ frame_needed = 0, uses_anonymous_args = 0
 271:AESCommon.cpp ****     const uint8_t *roundKey = schedule;
 661              		.loc 1 271 1 is_stmt 0 view .LVU188
 662 0000 2DE9F041 		push	{r4, r5, r6, r7, r8, lr}
 663              	.LCFI4:
 664              		.cfi_def_cfa_offset 24
 665              		.cfi_offset 4, -24
 666              		.cfi_offset 5, -20
 667              		.cfi_offset 6, -16
 668              		.cfi_offset 7, -12
 669              		.cfi_offset 8, -8
 670              		.cfi_offset 14, -4
 272:AESCommon.cpp ****     uint8_t posn;
 671              		.loc 1 272 20 view .LVU189
 672 0004 8468     		ldr	r4, [r0, #8]
 271:AESCommon.cpp ****     const uint8_t *roundKey = schedule;
 673              		.loc 1 271 1 view .LVU190
 674 0006 88B0     		sub	sp, sp, #32
 675              	.LCFI5:
 676              		.cfi_def_cfa_offset 56
 677 0008 531E     		subs	r3, r2, #1
 271:AESCommon.cpp ****     const uint8_t *roundKey = schedule;
 678              		.loc 1 271 1 view .LVU191
 679 000a 0D46     		mov	r5, r1
 272:AESCommon.cpp ****     uint8_t posn;
 680              		.loc 1 272 5 is_stmt 1 view .LVU192
 681              	.LVL32:
 273:AESCommon.cpp ****     uint8_t round;
 682              		.loc 1 273 5 view .LVU193
 274:AESCommon.cpp ****     uint8_t state1[16];
 683              		.loc 1 274 5 view .LVU194
 275:AESCommon.cpp ****     uint8_t state2[16];
 684              		.loc 1 275 5 view .LVU195
 276:AESCommon.cpp **** 
 685              		.loc 1 276 5 view .LVU196
 279:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 686              		.loc 1 279 5 view .LVU197
 279:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 687              		.loc 1 279 25 view .LVU198
 688 000c 671E     		subs	r7, r4, #1
 689 000e 0F32     		adds	r2, r2, #15
 690              	.LVL33:
 272:AESCommon.cpp ****     uint8_t posn;
 691              		.loc 1 272 20 is_stmt 0 view .LVU199
 692 0010 6E46     		mov	r6, sp
 693              	.LVL34:
 694              	.L18:
 280:AESCommon.cpp ****     roundKey += 16;
 695              		.loc 1 280 9 is_stmt 1 discriminator 2 view .LVU200
 280:AESCommon.cpp ****     roundKey += 16;
 696              		.loc 1 280 36 is_stmt 0 discriminator 2 view .LVU201
 697 0012 13F8011F 		ldrb	r1, [r3, #1]!	@ zero_extendqisi2
 698              	.LVL35:
 280:AESCommon.cpp ****     roundKey += 16;
 699              		.loc 1 280 36 discriminator 2 view .LVU202
 700 0016 17F801CF 		ldrb	ip, [r7, #1]!	@ zero_extendqisi2
 279:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 701              		.loc 1 279 25 discriminator 2 view .LVU203
 702 001a 9342     		cmp	r3, r2
 280:AESCommon.cpp ****     roundKey += 16;
 703              		.loc 1 280 36 discriminator 2 view .LVU204
 704 001c 81EA0C01 		eor	r1, r1, ip
 280:AESCommon.cpp ****     roundKey += 16;
 705              		.loc 1 280 22 discriminator 2 view .LVU205
 706 0020 06F8011B 		strb	r1, [r6], #1
 279:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 707              		.loc 1 279 5 is_stmt 1 discriminator 2 view .LVU206
 708              	.LVL36:
 279:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 709              		.loc 1 279 25 discriminator 2 view .LVU207
 710 0024 F5D1     		bne	.L18
 281:AESCommon.cpp **** 
 711              		.loc 1 281 5 view .LVU208
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 712              		.loc 1 284 16 is_stmt 0 view .LVU209
 713 0026 0779     		ldrb	r7, [r0, #4]	@ zero_extendqisi2
 281:AESCommon.cpp **** 
 714              		.loc 1 281 14 view .LVU210
 715 0028 1034     		adds	r4, r4, #16
 716              	.LVL37:
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 717              		.loc 1 284 5 is_stmt 1 view .LVU211
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 718              		.loc 1 284 16 is_stmt 0 view .LVU212
 719 002a 3E46     		mov	r6, r7
 281:AESCommon.cpp **** 
 720              		.loc 1 281 14 view .LVU213
 721 002c A046     		mov	r8, r4
 722              	.LVL38:
 723              	.L21:
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 724              		.loc 1 284 32 is_stmt 1 discriminator 1 view .LVU214
 725 002e 012E     		cmp	r6, #1
 726 0030 26D9     		bls	.L19
 285:AESCommon.cpp ****         mixColumn(state1,      state2);
 727              		.loc 1 285 9 view .LVU215
 285:AESCommon.cpp ****         mixColumn(state1,      state2);
 728              		.loc 1 285 29 is_stmt 0 view .LVU216
 729 0032 04A8     		add	r0, sp, #16
 730 0034 6946     		mov	r1, sp
 731 0036 FFF7FEFF 		bl	_ZN9AESCommon20subBytesAndShiftRowsEPhPKh
 732              	.LVL39:
 286:AESCommon.cpp ****         mixColumn(state1 + 4,  state2 + 4);
 733              		.loc 1 286 9 is_stmt 1 view .LVU217
 286:AESCommon.cpp ****         mixColumn(state1 + 4,  state2 + 4);
 734              		.loc 1 286 18 is_stmt 0 view .LVU218
 735 003a 0146     		mov	r1, r0
 736 003c 6846     		mov	r0, sp
 737 003e FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 738              	.LVL40:
 287:AESCommon.cpp ****         mixColumn(state1 + 8,  state2 + 8);
 739              		.loc 1 287 9 is_stmt 1 view .LVU219
 287:AESCommon.cpp ****         mixColumn(state1 + 8,  state2 + 8);
 740              		.loc 1 287 18 is_stmt 0 view .LVU220
 741 0042 05A9     		add	r1, sp, #20
 742 0044 01A8     		add	r0, sp, #4
 743 0046 FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 744              	.LVL41:
 288:AESCommon.cpp ****         mixColumn(state1 + 12, state2 + 12);
 745              		.loc 1 288 9 is_stmt 1 view .LVU221
 288:AESCommon.cpp ****         mixColumn(state1 + 12, state2 + 12);
 746              		.loc 1 288 18 is_stmt 0 view .LVU222
 747 004a 06A9     		add	r1, sp, #24
 748 004c 02A8     		add	r0, sp, #8
 749 004e FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 750              	.LVL42:
 289:AESCommon.cpp ****         for (posn = 0; posn < 16; ++posn)
 751              		.loc 1 289 9 is_stmt 1 view .LVU223
 289:AESCommon.cpp ****         for (posn = 0; posn < 16; ++posn)
 752              		.loc 1 289 18 is_stmt 0 view .LVU224
 753 0052 03A8     		add	r0, sp, #12
 754 0054 07A9     		add	r1, sp, #28
 755 0056 FFF7FEFF 		bl	_ZN9AESCommon9mixColumnEPhS0_
 756              	.LVL43:
 290:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 757              		.loc 1 290 9 is_stmt 1 view .LVU225
 290:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 758              		.loc 1 290 29 view .LVU226
 759 005a 08F1FF33 		add	r3, r8, #-1
 289:AESCommon.cpp ****         for (posn = 0; posn < 16; ++posn)
 760              		.loc 1 289 18 is_stmt 0 view .LVU227
 761 005e 6A46     		mov	r2, sp
 290:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 762              		.loc 1 290 29 view .LVU228
 763 0060 08F10F00 		add	r0, r8, #15
 764              	.LVL44:
 765              	.L20:
 291:AESCommon.cpp ****         roundKey += 16;
 766              		.loc 1 291 13 is_stmt 1 discriminator 2 view .LVU229
 291:AESCommon.cpp ****         roundKey += 16;
 767              		.loc 1 291 26 is_stmt 0 discriminator 2 view .LVU230
 768 0064 13F801CF 		ldrb	ip, [r3, #1]!	@ zero_extendqisi2
 769 0068 1178     		ldrb	r1, [r2]	@ zero_extendqisi2
 290:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 770              		.loc 1 290 29 discriminator 2 view .LVU231
 771 006a 8342     		cmp	r3, r0
 291:AESCommon.cpp ****         roundKey += 16;
 772              		.loc 1 291 26 discriminator 2 view .LVU232
 773 006c 81EA0C01 		eor	r1, r1, ip
 774 0070 02F8011B 		strb	r1, [r2], #1
 775              	.LVL45:
 290:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 776              		.loc 1 290 9 is_stmt 1 discriminator 2 view .LVU233
 290:AESCommon.cpp ****             state1[posn] ^= roundKey[posn];
 777              		.loc 1 290 29 discriminator 2 view .LVU234
 778 0074 F6D1     		bne	.L20
 292:AESCommon.cpp ****     }
 779              		.loc 1 292 9 discriminator 2 view .LVU235
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 780              		.loc 1 284 5 is_stmt 0 discriminator 2 view .LVU236
 781 0076 013E     		subs	r6, r6, #1
 782              	.LVL46:
 292:AESCommon.cpp ****     }
 783              		.loc 1 292 18 discriminator 2 view .LVU237
 784 0078 08F11008 		add	r8, r8, #16
 785              	.LVL47:
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 786              		.loc 1 284 5 is_stmt 1 discriminator 2 view .LVU238
 787 007c F6B2     		uxtb	r6, r6
 788              	.LVL48:
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 789              		.loc 1 284 5 is_stmt 0 discriminator 2 view .LVU239
 790 007e D6E7     		b	.L21
 791              	.LVL49:
 792              	.L19:
 284:AESCommon.cpp ****         subBytesAndShiftRows(state2, state1);
 793              		.loc 1 284 5 discriminator 2 view .LVU240
 794 0080 7B1E     		subs	r3, r7, #1
 795 0082 002F     		cmp	r7, #0
 796 0084 DBB2     		uxtb	r3, r3
 797 0086 4FEA0313 		lsl	r3, r3, #4
 798 008a 08BF     		it	eq
 799 008c 0023     		moveq	r3, #0
 800 008e 1C44     		add	r4, r4, r3
 296:AESCommon.cpp ****     for (posn = 0; posn < 16; ++posn)
 801              		.loc 1 296 5 is_stmt 1 view .LVU241
 296:AESCommon.cpp ****     for (posn = 0; posn < 16; ++posn)
 802              		.loc 1 296 25 is_stmt 0 view .LVU242
 803 0090 6946     		mov	r1, sp
 804 0092 04A8     		add	r0, sp, #16
 805 0094 FFF7FEFF 		bl	_ZN9AESCommon20subBytesAndShiftRowsEPhPKh
 806              	.LVL50:
 297:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 807              		.loc 1 297 5 is_stmt 1 view .LVU243
 297:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 808              		.loc 1 297 25 view .LVU244
 809 0098 013D     		subs	r5, r5, #1
 810              	.LVL51:
 297:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 811              		.loc 1 297 25 is_stmt 0 view .LVU245
 812 009a 631E     		subs	r3, r4, #1
 813 009c 0F34     		adds	r4, r4, #15
 814              	.LVL52:
 815              	.L22:
 298:AESCommon.cpp **** }
 816              		.loc 1 298 9 is_stmt 1 discriminator 2 view .LVU246
 298:AESCommon.cpp **** }
 817              		.loc 1 298 37 is_stmt 0 discriminator 2 view .LVU247
 818 009e 13F8011F 		ldrb	r1, [r3, #1]!	@ zero_extendqisi2
 298:AESCommon.cpp **** }
 819              		.loc 1 298 35 discriminator 2 view .LVU248
 820 00a2 10F8012B 		ldrb	r2, [r0], #1	@ zero_extendqisi2
 821              	.LVL53:
 297:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 822              		.loc 1 297 25 discriminator 2 view .LVU249
 823 00a6 A342     		cmp	r3, r4
 298:AESCommon.cpp **** }
 824              		.loc 1 298 37 discriminator 2 view .LVU250
 825 00a8 82EA0102 		eor	r2, r2, r1
 298:AESCommon.cpp **** }
 826              		.loc 1 298 22 discriminator 2 view .LVU251
 827 00ac 05F8012F 		strb	r2, [r5, #1]!
 297:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 828              		.loc 1 297 5 is_stmt 1 discriminator 2 view .LVU252
 829              	.LVL54:
 297:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 830              		.loc 1 297 25 discriminator 2 view .LVU253
 831 00b0 F5D1     		bne	.L22
 299:AESCommon.cpp **** 
 832              		.loc 1 299 1 is_stmt 0 view .LVU254
 833 00b2 08B0     		add	sp, sp, #32
 834              	.LCFI6:
 835              		.cfi_def_cfa_offset 24
 836              		@ sp needed
 837 00b4 BDE8F081 		pop	{r4, r5, r6, r7, r8, pc}
 299:AESCommon.cpp **** 
 838              		.loc 1 299 1 view .LVU255
 839              		.cfi_endproc
 840              	.LFE13:
 841              		.cantunwind
 842              		.fnend
 844              		.section	.text._ZN9AESCommon16inverseMixColumnEPhPKh,"ax",%progbits
 845              		.align	1
 846              		.global	_ZN9AESCommon16inverseMixColumnEPhPKh
 847              		.syntax unified
 848              		.thumb
 849              		.thumb_func
 850              		.fpu softvfp
 852              	_ZN9AESCommon16inverseMixColumnEPhPKh:
 853              		.fnstart
 854              	.LVL55:
 855              	.LFB12:
 244:AESCommon.cpp ****     uint16_t t; // Needed by the gmul2, gmul4, and gmul8 macros.
 856              		.loc 1 244 1 is_stmt 1 view -0
 857              		.cfi_startproc
 858              		@ args = 0, pretend = 0, frame = 24
 859              		@ frame_needed = 0, uses_anonymous_args = 0
 245:AESCommon.cpp ****     uint8_t a = input[0];
 860              		.loc 1 245 5 view .LVU257
 246:AESCommon.cpp ****     uint8_t b = input[1];
 861              		.loc 1 246 5 view .LVU258
 244:AESCommon.cpp ****     uint16_t t; // Needed by the gmul2, gmul4, and gmul8 macros.
 862              		.loc 1 244 1 is_stmt 0 view .LVU259
 863 0000 2DE9F04F 		push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
 864              	.LCFI7:
 865              		.cfi_def_cfa_offset 36
 866              		.cfi_offset 4, -36
 867              		.cfi_offset 5, -32
 868              		.cfi_offset 6, -28
 869              		.cfi_offset 7, -24
 870              		.cfi_offset 8, -20
 871              		.cfi_offset 9, -16
 872              		.cfi_offset 10, -12
 873              		.cfi_offset 11, -8
 874              		.cfi_offset 14, -4
 875 0004 87B0     		sub	sp, sp, #28
 876              	.LCFI8:
 877              		.cfi_def_cfa_offset 64
 250:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 878              		.loc 1 250 18 view .LVU260
 879 0006 91F80080 		ldrb	r8, [r1]	@ zero_extendqisi2
 246:AESCommon.cpp ****     uint8_t b = input[1];
 880              		.loc 1 246 13 view .LVU261
 881 000a 0B78     		ldrb	r3, [r1]	@ zero_extendqisi2
 882 000c 0093     		str	r3, [sp]
 883              	.LVL56:
 247:AESCommon.cpp ****     uint8_t c = input[2];
 884              		.loc 1 247 5 is_stmt 1 view .LVU262
 247:AESCommon.cpp ****     uint8_t c = input[2];
 885              		.loc 1 247 13 is_stmt 0 view .LVU263
 886 000e 4B78     		ldrb	r3, [r1, #1]	@ zero_extendqisi2
 887 0010 0193     		str	r3, [sp, #4]
 888              	.LVL57:
 248:AESCommon.cpp ****     uint8_t d = input[3];
 889              		.loc 1 248 5 is_stmt 1 view .LVU264
 250:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 890              		.loc 1 250 18 is_stmt 0 view .LVU265
 891 0012 4FEAD813 		lsr	r3, r8, #7
 892 0016 03EB4303 		add	r3, r3, r3, lsl #1
 893 001a 03EBC303 		add	r3, r3, r3, lsl #3
 248:AESCommon.cpp ****     uint8_t d = input[3];
 894              		.loc 1 248 13 view .LVU266
 895 001e 91F802A0 		ldrb	r10, [r1, #2]	@ zero_extendqisi2
 896              	.LVL58:
 249:AESCommon.cpp ****     uint8_t a2 = gmul2(a);
 897              		.loc 1 249 5 is_stmt 1 view .LVU267
 251:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 898              		.loc 1 251 18 is_stmt 0 view .LVU268
 899 0022 4D78     		ldrb	r5, [r1, #1]	@ zero_extendqisi2
 249:AESCommon.cpp ****     uint8_t a2 = gmul2(a);
 900              		.loc 1 249 13 view .LVU269
 901 0024 91F803B0 		ldrb	fp, [r1, #3]	@ zero_extendqisi2
 902              	.LVL59:
 250:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 903              		.loc 1 250 5 is_stmt 1 view .LVU270
 255:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 904              		.loc 1 255 18 is_stmt 0 view .LVU271
 905 0028 534E     		ldr	r6, .L27
 250:AESCommon.cpp ****     uint8_t b2 = gmul2(b);
 906              		.loc 1 250 18 view .LVU272
 907 002a 83EA4803 		eor	r3, r3, r8, lsl #1
 908 002e DBB2     		uxtb	r3, r3
 909 0030 0293     		str	r3, [sp, #8]
 910              	.LVL60:
 251:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 911              		.loc 1 251 5 is_stmt 1 view .LVU273
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 912              		.loc 1 252 18 is_stmt 0 view .LVU274
 913 0032 5446     		mov	r4, r10
 251:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 914              		.loc 1 251 18 view .LVU275
 915 0034 EB09     		lsrs	r3, r5, #7
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 916              		.loc 1 252 18 view .LVU276
 917 0036 E209     		lsrs	r2, r4, #7
 251:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 918              		.loc 1 251 18 view .LVU277
 919 0038 03EB4303 		add	r3, r3, r3, lsl #1
 920 003c 03EBC303 		add	r3, r3, r3, lsl #3
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 921              		.loc 1 252 18 view .LVU278
 922 0040 02EB4202 		add	r2, r2, r2, lsl #1
 251:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 923              		.loc 1 251 18 view .LVU279
 924 0044 83EA4503 		eor	r3, r3, r5, lsl #1
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 925              		.loc 1 252 18 view .LVU280
 926 0048 02EBC202 		add	r2, r2, r2, lsl #3
 927 004c 82EA4A02 		eor	r2, r2, r10, lsl #1
 251:AESCommon.cpp ****     uint8_t c2 = gmul2(c);
 928              		.loc 1 251 18 view .LVU281
 929 0050 DBB2     		uxtb	r3, r3
 930 0052 0393     		str	r3, [sp, #12]
 931              	.LVL61:
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 932              		.loc 1 252 5 is_stmt 1 view .LVU282
 257:AESCommon.cpp ****     uint8_t a8 = gmul8(a);
 933              		.loc 1 257 18 is_stmt 0 view .LVU283
 934 0054 06EB9B11 		add	r1, r6, fp, lsr #6
 935              	.LVL62:
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 936              		.loc 1 252 18 view .LVU284
 937 0058 D3B2     		uxtb	r3, r2
 253:AESCommon.cpp ****     uint8_t a4 = gmul4(a);
 938              		.loc 1 253 18 view .LVU285
 939 005a 4FEADB12 		lsr	r2, fp, #7
 940 005e 02EB4202 		add	r2, r2, r2, lsl #1
 257:AESCommon.cpp ****     uint8_t a8 = gmul8(a);
 941              		.loc 1 257 18 view .LVU286
 942 0062 91F828C2 		ldrb	ip, [r1, #552]	@ zero_extendqisi2
 252:AESCommon.cpp ****     uint8_t d2 = gmul2(d);
 943              		.loc 1 252 18 view .LVU287
 944 0066 0493     		str	r3, [sp, #16]
 945              	.LVL63:
 253:AESCommon.cpp ****     uint8_t a4 = gmul4(a);
 946              		.loc 1 253 5 is_stmt 1 view .LVU288
 258:AESCommon.cpp ****     uint8_t b8 = gmul8(b);
 947              		.loc 1 258 18 is_stmt 0 view .LVU289
 948 0068 06EB5811 		add	r1, r6, r8, lsr #5
 253:AESCommon.cpp ****     uint8_t a4 = gmul4(a);
 949              		.loc 1 253 18 view .LVU290
 950 006c 02EBC202 		add	r2, r2, r2, lsl #3
 951 0070 82EA4B02 		eor	r2, r2, fp, lsl #1
 258:AESCommon.cpp ****     uint8_t b8 = gmul8(b);
 952              		.loc 1 258 18 view .LVU291
 953 0074 91F82872 		ldrb	r7, [r1, #552]	@ zero_extendqisi2
 253:AESCommon.cpp ****     uint8_t a4 = gmul4(a);
 954              		.loc 1 253 18 view .LVU292
 955 0078 D3B2     		uxtb	r3, r2
 259:AESCommon.cpp ****     uint8_t c8 = gmul8(c);
 956              		.loc 1 259 18 view .LVU293
 957 007a 06EB5511 		add	r1, r6, r5, lsr #5
 255:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 958              		.loc 1 255 18 view .LVU294
 959 007e 06EB9512 		add	r2, r6, r5, lsr #6
 259:AESCommon.cpp ****     uint8_t c8 = gmul8(c);
 960              		.loc 1 259 18 view .LVU295
 961 0082 91F82812 		ldrb	r1, [r1, #552]	@ zero_extendqisi2
 255:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 962              		.loc 1 255 18 view .LVU296
 963 0086 92F828E2 		ldrb	lr, [r2, #552]	@ zero_extendqisi2
 253:AESCommon.cpp ****     uint8_t a4 = gmul4(a);
 964              		.loc 1 253 18 view .LVU297
 965 008a 0593     		str	r3, [sp, #20]
 966              	.LVL64:
 254:AESCommon.cpp ****     uint8_t b4 = gmul4(b);
 967              		.loc 1 254 5 is_stmt 1 view .LVU298
 255:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 968              		.loc 1 255 5 view .LVU299
 255:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 969              		.loc 1 255 18 is_stmt 0 view .LVU300
 970 008c 8EEA850E 		eor	lr, lr, r5, lsl #2
 259:AESCommon.cpp ****     uint8_t c8 = gmul8(c);
 971              		.loc 1 259 18 view .LVU301
 972 0090 81EAC505 		eor	r5, r1, r5, lsl #3
 973              	.LVL65:
 260:AESCommon.cpp ****     uint8_t d8 = gmul8(d);
 974              		.loc 1 260 18 view .LVU302
 975 0094 06EB5A11 		add	r1, r6, r10, lsr #5
 256:AESCommon.cpp ****     uint8_t d4 = gmul4(d);
 976              		.loc 1 256 18 view .LVU303
 977 0098 06EB9A12 		add	r2, r6, r10, lsr #6
 260:AESCommon.cpp ****     uint8_t d8 = gmul8(d);
 978              		.loc 1 260 18 view .LVU304
 979 009c 91F82812 		ldrb	r1, [r1, #552]	@ zero_extendqisi2
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 980              		.loc 1 262 63 view .LVU305
 981 00a0 019B     		ldr	r3, [sp, #4]
 256:AESCommon.cpp ****     uint8_t d4 = gmul4(d);
 982              		.loc 1 256 18 view .LVU306
 983 00a2 92F82822 		ldrb	r2, [r2, #552]	@ zero_extendqisi2
 260:AESCommon.cpp ****     uint8_t d8 = gmul8(d);
 984              		.loc 1 260 18 view .LVU307
 985 00a6 81EACA04 		eor	r4, r1, r10, lsl #3
 261:AESCommon.cpp ****     output[0] = a8 ^ a4 ^ a2 ^ b8 ^ b2 ^ b ^ c8 ^ c4 ^ c ^ d8 ^ d;
 986              		.loc 1 261 18 view .LVU308
 987 00aa 06EB5B11 		add	r1, r6, fp, lsr #5
 254:AESCommon.cpp ****     uint8_t b4 = gmul4(b);
 988              		.loc 1 254 18 view .LVU309
 989 00ae 06EB9816 		add	r6, r6, r8, lsr #6
 258:AESCommon.cpp ****     uint8_t b8 = gmul8(b);
 990              		.loc 1 258 18 view .LVU310
 991 00b2 87EAC807 		eor	r7, r7, r8, lsl #3
 254:AESCommon.cpp ****     uint8_t b4 = gmul4(b);
 992              		.loc 1 254 18 view .LVU311
 993 00b6 96F82862 		ldrb	r6, [r6, #552]	@ zero_extendqisi2
 261:AESCommon.cpp ****     output[0] = a8 ^ a4 ^ a2 ^ b8 ^ b2 ^ b ^ c8 ^ c4 ^ c ^ d8 ^ d;
 994              		.loc 1 261 18 view .LVU312
 995 00ba 91F82812 		ldrb	r1, [r1, #552]	@ zero_extendqisi2
 254:AESCommon.cpp ****     uint8_t b4 = gmul4(b);
 996              		.loc 1 254 18 view .LVU313
 997 00be 86EA8808 		eor	r8, r6, r8, lsl #2
 998              	.LVL66:
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 999              		.loc 1 262 63 view .LVU314
 1000 00c2 83EA0A06 		eor	r6, r3, r10
 1001 00c6 029B     		ldr	r3, [sp, #8]
 1002 00c8 8BEA0606 		eor	r6, fp, r6
 1003 00cc 5E40     		eors	r6, r6, r3
 1004 00ce 039B     		ldr	r3, [sp, #12]
 256:AESCommon.cpp ****     uint8_t d4 = gmul4(d);
 1005              		.loc 1 256 18 view .LVU315
 1006 00d0 82EA8A02 		eor	r2, r2, r10, lsl #2
 1007 00d4 D2B2     		uxtb	r2, r2
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1008              		.loc 1 262 63 view .LVU316
 1009 00d6 5E40     		eors	r6, r6, r3
 259:AESCommon.cpp ****     uint8_t c8 = gmul8(c);
 1010              		.loc 1 259 18 view .LVU317
 1011 00d8 EDB2     		uxtb	r5, r5
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1012              		.loc 1 262 63 view .LVU318
 1013 00da 5640     		eors	r6, r6, r2
 260:AESCommon.cpp ****     uint8_t d8 = gmul8(d);
 1014              		.loc 1 260 18 view .LVU319
 1015 00dc E4B2     		uxtb	r4, r4
 258:AESCommon.cpp ****     uint8_t b8 = gmul8(b);
 1016              		.loc 1 258 18 view .LVU320
 1017 00de FFB2     		uxtb	r7, r7
 261:AESCommon.cpp ****     output[0] = a8 ^ a4 ^ a2 ^ b8 ^ b2 ^ b ^ c8 ^ c4 ^ c ^ d8 ^ d;
 1018              		.loc 1 261 18 view .LVU321
 1019 00e0 81EACB01 		eor	r1, r1, fp, lsl #3
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1020              		.loc 1 262 63 view .LVU322
 1021 00e4 6E40     		eors	r6, r6, r5
 261:AESCommon.cpp ****     output[0] = a8 ^ a4 ^ a2 ^ b8 ^ b2 ^ b ^ c8 ^ c4 ^ c ^ d8 ^ d;
 1022              		.loc 1 261 18 view .LVU323
 1023 00e6 C9B2     		uxtb	r1, r1
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1024              		.loc 1 262 20 view .LVU324
 1025 00e8 87EA0808 		eor	r8, r7, r8
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1026              		.loc 1 262 63 view .LVU325
 1027 00ec 6640     		eors	r6, r6, r4
 263:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 1028              		.loc 1 263 63 view .LVU326
 1029 00ee 009B     		ldr	r3, [sp]
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1030              		.loc 1 262 20 view .LVU327
 1031 00f0 5FFA88F8 		uxtb	r8, r8
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1032              		.loc 1 262 63 view .LVU328
 1033 00f4 4E40     		eors	r6, r6, r1
 1034 00f6 88EA0606 		eor	r6, r8, r6
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1035              		.loc 1 262 15 view .LVU329
 1036 00fa 0670     		strb	r6, [r0]
 263:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 1037              		.loc 1 263 63 view .LVU330
 1038 00fc 83EA0A06 		eor	r6, r3, r10
 1039 0100 039B     		ldr	r3, [sp, #12]
 1040 0102 8BEA0606 		eor	r6, fp, r6
 1041 0106 7340     		eors	r3, r3, r6
 1042 0108 049E     		ldr	r6, [sp, #16]
 255:AESCommon.cpp ****     uint8_t c4 = gmul4(c);
 1043              		.loc 1 255 18 view .LVU331
 1044 010a 5FFA8EFE 		uxtb	lr, lr
 1045              	.LVL67:
 256:AESCommon.cpp ****     uint8_t d4 = gmul4(d);
 1046              		.loc 1 256 5 is_stmt 1 view .LVU332
 257:AESCommon.cpp ****     uint8_t a8 = gmul8(a);
 1047              		.loc 1 257 5 view .LVU333
 257:AESCommon.cpp ****     uint8_t a8 = gmul8(a);
 1048              		.loc 1 257 18 is_stmt 0 view .LVU334
 1049 010e 8CEA8B0C 		eor	ip, ip, fp, lsl #2
 263:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 1050              		.loc 1 263 63 view .LVU335
 1051 0112 7340     		eors	r3, r3, r6
 257:AESCommon.cpp ****     uint8_t a8 = gmul8(a);
 1052              		.loc 1 257 18 view .LVU336
 1053 0114 5FFA8CFC 		uxtb	ip, ip
 1054              	.LVL68:
 258:AESCommon.cpp ****     uint8_t b8 = gmul8(b);
 1055              		.loc 1 258 5 is_stmt 1 view .LVU337
 259:AESCommon.cpp ****     uint8_t c8 = gmul8(c);
 1056              		.loc 1 259 5 view .LVU338
 260:AESCommon.cpp ****     uint8_t d8 = gmul8(d);
 1057              		.loc 1 260 5 view .LVU339
 261:AESCommon.cpp ****     output[0] = a8 ^ a4 ^ a2 ^ b8 ^ b2 ^ b ^ c8 ^ c4 ^ c ^ d8 ^ d;
 1058              		.loc 1 261 5 view .LVU340
 262:AESCommon.cpp ****     output[1] = a8 ^ a ^ b8 ^ b4 ^ b2 ^ c8 ^ c2 ^ c ^ d8 ^ d4 ^ d;
 1059              		.loc 1 262 5 view .LVU341
 263:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 1060              		.loc 1 263 5 view .LVU342
 263:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 1061              		.loc 1 263 63 is_stmt 0 view .LVU343
 1062 0118 8EEA0303 		eor	r3, lr, r3
 1063 011c 8CEA0303 		eor	r3, ip, r3
 1064 0120 7B40     		eors	r3, r3, r7
 1065 0122 6B40     		eors	r3, r3, r5
 1066 0124 6340     		eors	r3, r3, r4
 1067 0126 4B40     		eors	r3, r3, r1
 263:AESCommon.cpp ****     output[2] = a8 ^ a4 ^ a ^ b8 ^ b ^ c8 ^ c4 ^ c2 ^ d8 ^ d2 ^ d;
 1068              		.loc 1 263 15 view .LVU344
 1069 0128 4370     		strb	r3, [r0, #1]
 264:AESCommon.cpp ****     output[3] = a8 ^ a2 ^ a ^ b8 ^ b4 ^ b ^ c8 ^ c ^ d8 ^ d4 ^ d2;
 1070              		.loc 1 264 5 is_stmt 1 view .LVU345
 1071 012a DDE90036 		ldrd	r3, r6, [sp]
 1072 012e 7340     		eors	r3, r3, r6
 264:AESCommon.cpp ****     output[3] = a8 ^ a2 ^ a ^ b8 ^ b4 ^ b ^ c8 ^ c ^ d8 ^ d4 ^ d2;
 1073              		.loc 1 264 63 is_stmt 0 view .LVU346
 1074 0130 049E     		ldr	r6, [sp, #16]
 1075 0132 8BEA030B 		eor	fp, fp, r3
 1076              	.LVL69:
 264:AESCommon.cpp ****     output[3] = a8 ^ a2 ^ a ^ b8 ^ b4 ^ b ^ c8 ^ c ^ d8 ^ d4 ^ d2;
 1077              		.loc 1 264 63 view .LVU347
 1078 0136 86EA0B0B 		eor	fp, r6, fp
 1079 013a 059E     		ldr	r6, [sp, #20]
 1080 013c 86EA0B0B 		eor	fp, r6, fp
 1081 0140 82EA0B02 		eor	r2, r2, fp
 1082              	.LVL70:
 264:AESCommon.cpp ****     output[3] = a8 ^ a2 ^ a ^ b8 ^ b4 ^ b ^ c8 ^ c ^ d8 ^ d4 ^ d2;
 1083              		.loc 1 264 63 view .LVU348
 1084 0144 6A40     		eors	r2, r2, r5
 1085 0146 6240     		eors	r2, r2, r4
 1086 0148 4A40     		eors	r2, r2, r1
 1087 014a 88EA0208 		eor	r8, r8, r2
 265:AESCommon.cpp **** }
 1088              		.loc 1 265 62 view .LVU349
 1089 014e 029A     		ldr	r2, [sp, #8]
 264:AESCommon.cpp ****     output[3] = a8 ^ a2 ^ a ^ b8 ^ b4 ^ b ^ c8 ^ c ^ d8 ^ d4 ^ d2;
 1090              		.loc 1 264 15 view .LVU350
 1091 0150 80F80280 		strb	r8, [r0, #2]
 265:AESCommon.cpp **** }
 1092              		.loc 1 265 5 is_stmt 1 view .LVU351
 265:AESCommon.cpp **** }
 1093              		.loc 1 265 62 is_stmt 0 view .LVU352
 1094 0154 8AEA0303 		eor	r3, r10, r3
 1095 0158 5340     		eors	r3, r3, r2
 1096 015a 7340     		eors	r3, r3, r6
 1097 015c 8EEA030E 		eor	lr, lr, r3
 1098              	.LVL71:
 265:AESCommon.cpp **** }
 1099              		.loc 1 265 62 view .LVU353
 1100 0160 8CEA0E0C 		eor	ip, ip, lr
 1101              	.LVL72:
 265:AESCommon.cpp **** }
 1102              		.loc 1 265 62 view .LVU354
 1103 0164 87EA0C07 		eor	r7, r7, ip
 1104              	.LVL73:
 265:AESCommon.cpp **** }
 1105              		.loc 1 265 62 view .LVU355
 1106 0168 7D40     		eors	r5, r5, r7
 1107              	.LVL74:
 265:AESCommon.cpp **** }
 1108              		.loc 1 265 62 view .LVU356
 1109 016a 6C40     		eors	r4, r4, r5
 1110              	.LVL75:
 265:AESCommon.cpp **** }
 1111              		.loc 1 265 62 view .LVU357
 1112 016c 6140     		eors	r1, r1, r4
 1113              	.LVL76:
 265:AESCommon.cpp **** }
 1114              		.loc 1 265 15 view .LVU358
 1115 016e C170     		strb	r1, [r0, #3]
 266:AESCommon.cpp **** 
 1116              		.loc 1 266 1 view .LVU359
 1117 0170 07B0     		add	sp, sp, #28
 1118              	.LCFI9:
 1119              		.cfi_def_cfa_offset 36
 1120              	.LVL77:
 266:AESCommon.cpp **** 
 1121              		.loc 1 266 1 view .LVU360
 1122              		@ sp needed
 1123 0172 BDE8F08F 		pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
 1124              	.LVL78:
 1125              	.L28:
 266:AESCommon.cpp **** 
 1126              		.loc 1 266 1 view .LVU361
 1127 0176 00BF     		.align	2
 1128              	.L27:
 1129 0178 00000000 		.word	.LANCHOR0
 1130              		.cfi_endproc
 1131              	.LFE12:
 1132              		.cantunwind
 1133              		.fnend
 1135              		.section	.text._ZN9AESCommon12decryptBlockEPhPKh,"ax",%progbits
 1136              		.align	1
 1137              		.global	_ZN9AESCommon12decryptBlockEPhPKh
 1138              		.syntax unified
 1139              		.thumb
 1140              		.thumb_func
 1141              		.fpu softvfp
 1143              	_ZN9AESCommon12decryptBlockEPhPKh:
 1144              		.fnstart
 1145              	.LVL79:
 1146              	.LFB14:
 302:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 1147              		.loc 1 302 1 is_stmt 1 view -0
 1148              		.cfi_startproc
 1149              		@ args = 0, pretend = 0, frame = 32
 1150              		@ frame_needed = 0, uses_anonymous_args = 0
 302:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 1151              		.loc 1 302 1 is_stmt 0 view .LVU363
 1152 0000 2DE9F043 		push	{r4, r5, r6, r7, r8, r9, lr}
 1153              	.LCFI10:
 1154              		.cfi_def_cfa_offset 28
 1155              		.cfi_offset 4, -28
 1156              		.cfi_offset 5, -24
 1157              		.cfi_offset 6, -20
 1158              		.cfi_offset 7, -16
 1159              		.cfi_offset 8, -12
 1160              		.cfi_offset 9, -8
 1161              		.cfi_offset 14, -4
 303:AESCommon.cpp ****     uint8_t round;
 1162              		.loc 1 303 20 view .LVU364
 1163 0004 8468     		ldr	r4, [r0, #8]
 303:AESCommon.cpp ****     uint8_t round;
 1164              		.loc 1 303 49 view .LVU365
 1165 0006 0379     		ldrb	r3, [r0, #4]	@ zero_extendqisi2
 302:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 1166              		.loc 1 302 1 view .LVU366
 1167 0008 89B0     		sub	sp, sp, #36
 1168              	.LCFI11:
 1169              		.cfi_def_cfa_offset 64
 303:AESCommon.cpp ****     uint8_t round;
 1170              		.loc 1 303 20 view .LVU367
 1171 000a 04EB0314 		add	r4, r4, r3, lsl #4
 302:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 1172              		.loc 1 302 1 view .LVU368
 1173 000e 0D46     		mov	r5, r1
 303:AESCommon.cpp ****     uint8_t round;
 1174              		.loc 1 303 5 is_stmt 1 view .LVU369
 1175              	.LVL80:
 304:AESCommon.cpp ****     uint8_t posn;
 1176              		.loc 1 304 5 view .LVU370
 305:AESCommon.cpp ****     uint8_t state1[16];
 1177              		.loc 1 305 5 view .LVU371
 306:AESCommon.cpp ****     uint8_t state2[16];
 1178              		.loc 1 306 5 view .LVU372
 307:AESCommon.cpp **** 
 1179              		.loc 1 307 5 view .LVU373
 310:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 1180              		.loc 1 310 5 view .LVU374
 310:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 1181              		.loc 1 310 25 view .LVU375
 1182 0010 6946     		mov	r1, sp
 1183              	.LVL81:
 310:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 1184              		.loc 1 310 25 is_stmt 0 view .LVU376
 1185 0012 531E     		subs	r3, r2, #1
 302:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 1186              		.loc 1 302 1 view .LVU377
 1187 0014 0646     		mov	r6, r0
 1188 0016 671E     		subs	r7, r4, #1
 1189 0018 0F32     		adds	r2, r2, #15
 1190              	.LVL82:
 302:AESCommon.cpp ****     const uint8_t *roundKey = schedule + rounds * 16;
 1191              		.loc 1 302 1 view .LVU378
 1192 001a 8946     		mov	r9, r1
 1193              	.LVL83:
 1194              	.L30:
 311:AESCommon.cpp ****     inverseShiftRowsAndSubBytes(state2, state1);
 1195              		.loc 1 311 9 is_stmt 1 discriminator 2 view .LVU379
 311:AESCommon.cpp ****     inverseShiftRowsAndSubBytes(state2, state1);
 1196              		.loc 1 311 36 is_stmt 0 discriminator 2 view .LVU380
 1197 001c 13F8010F 		ldrb	r0, [r3, #1]!	@ zero_extendqisi2
 1198              	.LVL84:
 311:AESCommon.cpp ****     inverseShiftRowsAndSubBytes(state2, state1);
 1199              		.loc 1 311 36 discriminator 2 view .LVU381
 1200 0020 17F801CF 		ldrb	ip, [r7, #1]!	@ zero_extendqisi2
 310:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 1201              		.loc 1 310 25 discriminator 2 view .LVU382
 1202 0024 9342     		cmp	r3, r2
 311:AESCommon.cpp ****     inverseShiftRowsAndSubBytes(state2, state1);
 1203              		.loc 1 311 36 discriminator 2 view .LVU383
 1204 0026 80EA0C00 		eor	r0, r0, ip
 311:AESCommon.cpp ****     inverseShiftRowsAndSubBytes(state2, state1);
 1205              		.loc 1 311 22 discriminator 2 view .LVU384
 1206 002a 01F8010B 		strb	r0, [r1], #1
 310:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 1207              		.loc 1 310 5 is_stmt 1 discriminator 2 view .LVU385
 1208              	.LVL85:
 310:AESCommon.cpp ****         state1[posn] = input[posn] ^ roundKey[posn];
 1209              		.loc 1 310 25 discriminator 2 view .LVU386
 1210 002e F5D1     		bne	.L30
 312:AESCommon.cpp **** 
 1211              		.loc 1 312 5 view .LVU387
 312:AESCommon.cpp **** 
 1212              		.loc 1 312 32 is_stmt 0 view .LVU388
 1213 0030 4946     		mov	r1, r9
 1214 0032 04A8     		add	r0, sp, #16
 1215 0034 FFF7FEFF 		bl	_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
 1216              	.LVL86:
 315:AESCommon.cpp ****         roundKey -= 16;
 1217              		.loc 1 315 5 is_stmt 1 view .LVU389
 315:AESCommon.cpp ****         roundKey -= 16;
 1218              		.loc 1 315 16 is_stmt 0 view .LVU390
 1219 0038 96F80480 		ldrb	r8, [r6, #4]	@ zero_extendqisi2
 1220              	.LVL87:
 303:AESCommon.cpp ****     uint8_t round;
 1221              		.loc 1 303 20 view .LVU391
 1222 003c 2746     		mov	r7, r4
 315:AESCommon.cpp ****         roundKey -= 16;
 1223              		.loc 1 315 16 view .LVU392
 1224 003e 4646     		mov	r6, r8
 1225              	.LVL88:
 1226              	.L33:
 315:AESCommon.cpp ****         roundKey -= 16;
 1227              		.loc 1 315 32 is_stmt 1 discriminator 1 view .LVU393
 1228 0040 012E     		cmp	r6, #1
 316:AESCommon.cpp ****         for (posn = 0; posn < 16; ++posn)
 1229              		.loc 1 316 18 is_stmt 0 discriminator 1 view .LVU394
 1230 0042 A7F11007 		sub	r7, r7, #16
 1231              	.LVL89:
 315:AESCommon.cpp ****         roundKey -= 16;
 1232              		.loc 1 315 32 discriminator 1 view .LVU395
 1233 0046 23D9     		bls	.L31
 1234 0048 04AA     		add	r2, sp, #16
 315:AESCommon.cpp ****         roundKey -= 16;
 1235              		.loc 1 315 32 view .LVU396
 1236 004a 3B46     		mov	r3, r7
 317:AESCommon.cpp ****             state2[posn] ^= roundKey[posn];
 1237              		.loc 1 317 29 view .LVU397
 1238 004c 07F11000 		add	r0, r7, #16
 1239              	.LVL90:
 1240              	.L32:
 318:AESCommon.cpp ****         inverseMixColumn(state1,      state2);
 1241              		.loc 1 318 13 is_stmt 1 discriminator 2 view .LVU398
 318:AESCommon.cpp ****         inverseMixColumn(state1,      state2);
 1242              		.loc 1 318 42 is_stmt 0 discriminator 2 view .LVU399
 1243 0050 13F801CB 		ldrb	ip, [r3], #1	@ zero_extendqisi2
 318:AESCommon.cpp ****         inverseMixColumn(state1,      state2);
 1244              		.loc 1 318 26 discriminator 2 view .LVU400
 1245 0054 1178     		ldrb	r1, [r2]	@ zero_extendqisi2
 317:AESCommon.cpp ****             state2[posn] ^= roundKey[posn];
 1246              		.loc 1 317 29 discriminator 2 view .LVU401
 1247 0056 8342     		cmp	r3, r0
 318:AESCommon.cpp ****         inverseMixColumn(state1,      state2);
 1248              		.loc 1 318 26 discriminator 2 view .LVU402
 1249 0058 81EA0C01 		eor	r1, r1, ip
 1250 005c 02F8011B 		strb	r1, [r2], #1
 1251              	.LVL91:
 317:AESCommon.cpp ****             state2[posn] ^= roundKey[posn];
 1252              		.loc 1 317 9 is_stmt 1 discriminator 2 view .LVU403
 317:AESCommon.cpp ****             state2[posn] ^= roundKey[posn];
 1253              		.loc 1 317 29 discriminator 2 view .LVU404
 1254 0060 F6D1     		bne	.L32
 319:AESCommon.cpp ****         inverseMixColumn(state1 + 4,  state2 + 4);
 1255              		.loc 1 319 9 discriminator 2 view .LVU405
 319:AESCommon.cpp ****         inverseMixColumn(state1 + 4,  state2 + 4);
 1256              		.loc 1 319 25 is_stmt 0 discriminator 2 view .LVU406
 1257 0062 04A9     		add	r1, sp, #16
 1258 0064 4846     		mov	r0, r9
 1259 0066 FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 1260              	.LVL92:
 320:AESCommon.cpp ****         inverseMixColumn(state1 + 8,  state2 + 8);
 1261              		.loc 1 320 9 is_stmt 1 discriminator 2 view .LVU407
 320:AESCommon.cpp ****         inverseMixColumn(state1 + 8,  state2 + 8);
 1262              		.loc 1 320 25 is_stmt 0 discriminator 2 view .LVU408
 1263 006a 05A9     		add	r1, sp, #20
 1264 006c 01A8     		add	r0, sp, #4
 1265 006e FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 1266              	.LVL93:
 321:AESCommon.cpp ****         inverseMixColumn(state1 + 12, state2 + 12);
 1267              		.loc 1 321 9 is_stmt 1 discriminator 2 view .LVU409
 321:AESCommon.cpp ****         inverseMixColumn(state1 + 12, state2 + 12);
 1268              		.loc 1 321 25 is_stmt 0 discriminator 2 view .LVU410
 1269 0072 06A9     		add	r1, sp, #24
 1270 0074 02A8     		add	r0, sp, #8
 1271 0076 FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 1272              	.LVL94:
 322:AESCommon.cpp ****         inverseShiftRowsAndSubBytes(state2, state1);
 1273              		.loc 1 322 9 is_stmt 1 discriminator 2 view .LVU411
 322:AESCommon.cpp ****         inverseShiftRowsAndSubBytes(state2, state1);
 1274              		.loc 1 322 25 is_stmt 0 discriminator 2 view .LVU412
 1275 007a 07A9     		add	r1, sp, #28
 1276 007c 03A8     		add	r0, sp, #12
 1277 007e FFF7FEFF 		bl	_ZN9AESCommon16inverseMixColumnEPhPKh
 1278              	.LVL95:
 323:AESCommon.cpp ****     }
 1279              		.loc 1 323 9 is_stmt 1 discriminator 2 view .LVU413
 315:AESCommon.cpp ****         roundKey -= 16;
 1280              		.loc 1 315 5 is_stmt 0 discriminator 2 view .LVU414
 1281 0082 013E     		subs	r6, r6, #1
 1282              	.LVL96:
 323:AESCommon.cpp ****     }
 1283              		.loc 1 323 36 discriminator 2 view .LVU415
 1284 0084 4946     		mov	r1, r9
 1285 0086 04A8     		add	r0, sp, #16
 1286 0088 FFF7FEFF 		bl	_ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
 1287              	.LVL97:
 315:AESCommon.cpp ****         roundKey -= 16;
 1288              		.loc 1 315 5 is_stmt 1 discriminator 2 view .LVU416
 1289 008c F6B2     		uxtb	r6, r6
 1290              	.LVL98:
 315:AESCommon.cpp ****         roundKey -= 16;
 1291              		.loc 1 315 5 is_stmt 0 discriminator 2 view .LVU417
 1292 008e D7E7     		b	.L33
 1293              	.LVL99:
 1294              	.L31:
 315:AESCommon.cpp ****         roundKey -= 16;
 1295              		.loc 1 315 5 discriminator 2 view .LVU418
 1296 0090 08F1FF33 		add	r3, r8, #-1
 1297 0094 6FF00F02 		mvn	r2, #15
 1298 0098 DBB2     		uxtb	r3, r3
 1299 009a B8F1000F 		cmp	r8, #0
 1300 009e 02FB03F3 		mul	r3, r2, r3
 1301 00a2 08BF     		it	eq
 1302 00a4 0023     		moveq	r3, #0
 1303 00a6 1C44     		add	r4, r4, r3
 1304 00a8 A218     		adds	r2, r4, r2
 1305 00aa 04AB     		add	r3, sp, #16
 1306 00ac 013D     		subs	r5, r5, #1
 1307              	.LVL100:
 1308              	.L34:
 329:AESCommon.cpp **** }
 1309              		.loc 1 329 9 is_stmt 1 discriminator 2 view .LVU419
 329:AESCommon.cpp **** }
 1310              		.loc 1 329 52 is_stmt 0 discriminator 2 view .LVU420
 1311 00ae 12F8010B 		ldrb	r0, [r2], #1	@ zero_extendqisi2
 329:AESCommon.cpp **** }
 1312              		.loc 1 329 35 discriminator 2 view .LVU421
 1313 00b2 13F8011B 		ldrb	r1, [r3], #1	@ zero_extendqisi2
 1314              	.LVL101:
 328:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 1315              		.loc 1 328 25 discriminator 2 view .LVU422
 1316 00b6 A242     		cmp	r2, r4
 329:AESCommon.cpp **** }
 1317              		.loc 1 329 37 discriminator 2 view .LVU423
 1318 00b8 81EA0001 		eor	r1, r1, r0
 329:AESCommon.cpp **** }
 1319              		.loc 1 329 22 discriminator 2 view .LVU424
 1320 00bc 05F8011F 		strb	r1, [r5, #1]!
 328:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 1321              		.loc 1 328 5 is_stmt 1 discriminator 2 view .LVU425
 1322              	.LVL102:
 328:AESCommon.cpp ****         output[posn] = state2[posn] ^ roundKey[posn];
 1323              		.loc 1 328 25 discriminator 2 view .LVU426
 1324 00c0 F5D1     		bne	.L34
 330:AESCommon.cpp **** 
 1325              		.loc 1 330 1 is_stmt 0 view .LVU427
 1326 00c2 09B0     		add	sp, sp, #36
 1327              	.LCFI12:
 1328              		.cfi_def_cfa_offset 28
 1329              		@ sp needed
 1330 00c4 BDE8F083 		pop	{r4, r5, r6, r7, r8, r9, pc}
 330:AESCommon.cpp **** 
 1331              		.loc 1 330 1 view .LVU428
 1332              		.cfi_endproc
 1333              	.LFE14:
 1334              		.cantunwind
 1335              		.fnend
 1337              		.section	.text._ZN9AESCommon15keyScheduleCoreEPhPKhh,"ax",%progbits
 1338              		.align	1
 1339              		.global	_ZN9AESCommon15keyScheduleCoreEPhPKhh
 1340              		.syntax unified
 1341              		.thumb
 1342              		.thumb_func
 1343              		.fpu softvfp
 1345              	_ZN9AESCommon15keyScheduleCoreEPhPKhh:
 1346              		.fnstart
 1347              	.LVL103:
 1348              	.LFB16:
 335:AESCommon.cpp **** }
 336:AESCommon.cpp **** 
 337:AESCommon.cpp **** /** @cond aes_keycore */
 338:AESCommon.cpp **** 
 339:AESCommon.cpp **** void AESCommon::keyScheduleCore(uint8_t *output, const uint8_t *input, uint8_t iteration)
 340:AESCommon.cpp **** {
 1349              		.loc 1 340 1 is_stmt 1 view -0
 1350              		.cfi_startproc
 1351              		@ args = 0, pretend = 0, frame = 0
 1352              		@ frame_needed = 0, uses_anonymous_args = 0
 341:AESCommon.cpp ****     // Rcon(i), 2^i in the Rijndael finite field, for i = 0..10.
 342:AESCommon.cpp ****     // http://en.wikipedia.org/wiki/Rijndael_key_schedule
 343:AESCommon.cpp ****     static uint8_t const rcon[11] PROGMEM = {
 1353              		.loc 1 343 5 view .LVU430
 344:AESCommon.cpp ****         0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40,     // 0x00
 345:AESCommon.cpp ****         0x80, 0x1B, 0x36
 346:AESCommon.cpp ****     };
 347:AESCommon.cpp ****     output[0] = pgm_read_byte(sbox + input[1]) ^ pgm_read_byte(rcon + iteration);
 1354              		.loc 1 347 5 view .LVU431
 340:AESCommon.cpp ****     // Rcon(i), 2^i in the Rijndael finite field, for i = 0..10.
 1355              		.loc 1 340 1 is_stmt 0 view .LVU432
 1356 0000 30B5     		push	{r4, r5, lr}
 1357              	.LCFI13:
 1358              		.cfi_def_cfa_offset 12
 1359              		.cfi_offset 4, -12
 1360              		.cfi_offset 5, -8
 1361              		.cfi_offset 14, -4
 1362              		.loc 1 347 17 view .LVU433
 1363 0002 0D4B     		ldr	r3, .L39
 1364 0004 4D78     		ldrb	r5, [r1, #1]	@ zero_extendqisi2
 1365              		.loc 1 347 50 view .LVU434
 1366 0006 9C18     		adds	r4, r3, r2
 1367              		.loc 1 347 17 view .LVU435
 1368 0008 1D44     		add	r5, r5, r3
 1369              		.loc 1 347 48 view .LVU436
 1370 000a 94F83042 		ldrb	r4, [r4, #560]	@ zero_extendqisi2
 1371 000e 95F82820 		ldrb	r2, [r5, #40]	@ zero_extendqisi2
 1372              	.LVL104:
 1373              		.loc 1 347 48 view .LVU437
 1374 0012 6240     		eors	r2, r2, r4
 1375              		.loc 1 347 15 view .LVU438
 1376 0014 0270     		strb	r2, [r0]
 348:AESCommon.cpp ****     output[1] = pgm_read_byte(sbox + input[2]);
 1377              		.loc 1 348 5 is_stmt 1 view .LVU439
 1378              		.loc 1 348 17 is_stmt 0 view .LVU440
 1379 0016 8A78     		ldrb	r2, [r1, #2]	@ zero_extendqisi2
 1380 0018 1A44     		add	r2, r2, r3
 1381 001a 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 1382              		.loc 1 348 15 view .LVU441
 1383 001e 4270     		strb	r2, [r0, #1]
 349:AESCommon.cpp ****     output[2] = pgm_read_byte(sbox + input[3]);
 1384              		.loc 1 349 5 is_stmt 1 view .LVU442
 1385              		.loc 1 349 17 is_stmt 0 view .LVU443
 1386 0020 CA78     		ldrb	r2, [r1, #3]	@ zero_extendqisi2
 1387 0022 1A44     		add	r2, r2, r3
 1388 0024 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 1389              		.loc 1 349 15 view .LVU444
 1390 0028 8270     		strb	r2, [r0, #2]
 350:AESCommon.cpp ****     output[3] = pgm_read_byte(sbox + input[0]);
 1391              		.loc 1 350 5 is_stmt 1 view .LVU445
 1392              		.loc 1 350 17 is_stmt 0 view .LVU446
 1393 002a 0A78     		ldrb	r2, [r1]	@ zero_extendqisi2
 1394 002c 1344     		add	r3, r3, r2
 1395 002e 93F82830 		ldrb	r3, [r3, #40]	@ zero_extendqisi2
 1396              		.loc 1 350 15 view .LVU447
 1397 0032 C370     		strb	r3, [r0, #3]
 351:AESCommon.cpp **** }
 1398              		.loc 1 351 1 view .LVU448
 1399 0034 30BD     		pop	{r4, r5, pc}
 1400              	.L40:
 1401 0036 00BF     		.align	2
 1402              	.L39:
 1403 0038 00000000 		.word	.LANCHOR0
 1404              		.cfi_endproc
 1405              	.LFE16:
 1406              		.cantunwind
 1407              		.fnend
 1409              		.section	.text._ZN9AESCommon9applySboxEPhPKh,"ax",%progbits
 1410              		.align	1
 1411              		.global	_ZN9AESCommon9applySboxEPhPKh
 1412              		.syntax unified
 1413              		.thumb
 1414              		.thumb_func
 1415              		.fpu softvfp
 1417              	_ZN9AESCommon9applySboxEPhPKh:
 1418              		.fnstart
 1419              	.LVL105:
 1420              	.LFB17:
 352:AESCommon.cpp **** 
 353:AESCommon.cpp **** void AESCommon::applySbox(uint8_t *output, const uint8_t *input)
 354:AESCommon.cpp **** {
 1421              		.loc 1 354 1 is_stmt 1 view -0
 1422              		.cfi_startproc
 1423              		@ args = 0, pretend = 0, frame = 0
 1424              		@ frame_needed = 0, uses_anonymous_args = 0
 1425              		@ link register save eliminated.
 355:AESCommon.cpp ****     output[0] = pgm_read_byte(sbox + input[0]);
 1426              		.loc 1 355 5 view .LVU450
 1427              		.loc 1 355 17 is_stmt 0 view .LVU451
 1428 0000 0A78     		ldrb	r2, [r1]	@ zero_extendqisi2
 1429 0002 0A4B     		ldr	r3, .L42
 1430 0004 1A44     		add	r2, r2, r3
 1431 0006 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 1432              		.loc 1 355 15 view .LVU452
 1433 000a 0270     		strb	r2, [r0]
 356:AESCommon.cpp ****     output[1] = pgm_read_byte(sbox + input[1]);
 1434              		.loc 1 356 5 is_stmt 1 view .LVU453
 1435              		.loc 1 356 17 is_stmt 0 view .LVU454
 1436 000c 4A78     		ldrb	r2, [r1, #1]	@ zero_extendqisi2
 1437 000e 1A44     		add	r2, r2, r3
 1438 0010 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 1439              		.loc 1 356 15 view .LVU455
 1440 0014 4270     		strb	r2, [r0, #1]
 357:AESCommon.cpp ****     output[2] = pgm_read_byte(sbox + input[2]);
 1441              		.loc 1 357 5 is_stmt 1 view .LVU456
 1442              		.loc 1 357 17 is_stmt 0 view .LVU457
 1443 0016 8A78     		ldrb	r2, [r1, #2]	@ zero_extendqisi2
 1444 0018 1A44     		add	r2, r2, r3
 1445 001a 92F82820 		ldrb	r2, [r2, #40]	@ zero_extendqisi2
 1446              		.loc 1 357 15 view .LVU458
 1447 001e 8270     		strb	r2, [r0, #2]
 358:AESCommon.cpp ****     output[3] = pgm_read_byte(sbox + input[3]);
 1448              		.loc 1 358 5 is_stmt 1 view .LVU459
 1449              		.loc 1 358 17 is_stmt 0 view .LVU460
 1450 0020 CA78     		ldrb	r2, [r1, #3]	@ zero_extendqisi2
 1451 0022 1344     		add	r3, r3, r2
 1452 0024 93F82830 		ldrb	r3, [r3, #40]	@ zero_extendqisi2
 1453              		.loc 1 358 15 view .LVU461
 1454 0028 C370     		strb	r3, [r0, #3]
 359:AESCommon.cpp **** }
 1455              		.loc 1 359 1 view .LVU462
 1456 002a 7047     		bx	lr
 1457              	.L43:
 1458              		.align	2
 1459              	.L42:
 1460 002c 00000000 		.word	.LANCHOR0
 1461              		.cfi_endproc
 1462              	.LFE17:
 1463              		.cantunwind
 1464              		.fnend
 1466              		.global	_ZTS9AESCommon
 1467              		.global	_ZTI9AESCommon
 1468              		.global	_ZTV9AESCommon
 1469              		.section	.rodata
 1470              		.align	2
 1471              		.set	.LANCHOR0,. + 0
 1474              	_ZTV9AESCommon:
 1475 0000 00000000 		.word	0
 1476 0004 00000000 		.word	_ZTI9AESCommon
 1477 0008 00000000 		.word	0
 1478 000c 00000000 		.word	0
 1479 0010 00000000 		.word	_ZNK9AESCommon9blockSizeEv
 1480 0014 00000000 		.word	__cxa_pure_virtual
 1481 0018 00000000 		.word	__cxa_pure_virtual
 1482 001c 00000000 		.word	_ZN9AESCommon12encryptBlockEPhPKh
 1483 0020 00000000 		.word	_ZN9AESCommon12decryptBlockEPhPKh
 1484 0024 00000000 		.word	_ZN9AESCommon5clearEv
 1487              	_ZL4sbox:
 1488 0028 637C777B 		.ascii	"c|w{\362ko\3050\001g+\376\327\253v\312\202\311}\372"
 1488      F26B6FC5 
 1488      3001672B 
 1488      FED7AB76 
 1488      CA82C97D 
 1489 003d 5947F0AD 		.ascii	"YG\360\255\324\242\257\234\244r\300\267\375\223&6?\367"
 1489      D4A2AF9C 
 1489      A472C0B7 
 1489      FD932636 
 1489      3FF7
 1490 004f CC34A5E5 		.ascii	"\3144\245\345\361q\3301\025\004\307#\303\030\226\005"
 1490      F171D831 
 1490      1504C723 
 1490      C3189605 
 1491 005f 9A071280 		.ascii	"\232\007\022\200\342\353'\262u\011\203,\032\033nZ\240"
 1491      E2EB27B2 
 1491      7509832C 
 1491      1A1B6E5A 
 1491      A0
 1492 0070 523BD6B3 		.ascii	"R;\326\263)\343/\204S\321\000\355 \374\261[j\313\276"
 1492      29E32F84 
 1492      53D100ED 
 1492      20FCB15B 
 1492      6ACBBE
 1493 0083 394A4C58 		.ascii	"9JLX\317\320\357\252\373CM3\205E\371\002\177P<\237\250"
 1493      CFD0EFAA 
 1493      FB434D33 
 1493      8545F902 
 1493      7F503C9F 
 1494 0098 51A3408F 		.ascii	"Q\243@\217\222\2358\365\274\266\332!\020\377\363\322"
 1494      929D38F5 
 1494      BCB6DA21 
 1494      10FFF3D2 
 1495 00a8 CD0C13EC 		.ascii	"\315\014\023\354_\227D\027\304\247~=d]\031s`\201O\334"
 1495      5F974417 
 1495      C4A77E3D 
 1495      645D1973 
 1495      60814FDC 
 1496 00bc 222A9088 		.ascii	"\"*\220\210F\356\270\024\336^\013\333\3402:\012I\006"
 1496      46EEB814 
 1496      DE5E0BDB 
 1496      E0323A0A 
 1496      4906
 1497 00ce 245CC2D3 		.ascii	"$\\\302\323\254b\221\225\344y\347\3107m\215\325N\251"
 1497      AC629195 
 1497      E479E7C8 
 1497      376D8DD5 
 1497      4EA9
 1498 00e0 6C56F4EA 		.ascii	"lV\364\352ez\256\010\272x%.\034\246\264\306\350\335"
 1498      657AAE08 
 1498      BA78252E 
 1498      1CA6B4C6 
 1498      E8DD
 1499 00f2 741F4BBD 		.ascii	"t\037K\275\213\212p>\265fH\003\366\016a5W\271\206\301"
 1499      8B8A703E 
 1499      B5664803 
 1499      F60E6135 
 1499      57B986C1 
 1500 0106 1D9EE1F8 		.ascii	"\035\236\341\370\230\021i\331\216\224\233\036\207\351"
 1500      981169D9 
 1500      8E949B1E 
 1500      87E9
 1501 0114 CE5528DF 		.ascii	"\316U(\337\214\241\211\015\277\346BhA\231-\017\260T"
 1501      8CA1890D 
 1501      BFE64268 
 1501      41992D0F 
 1501      B054
 1502 0126 BB16     		.ascii	"\273\026"
 1505              	_ZL12sbox_inverse:
 1506 0128 52096AD5 		.ascii	"R\011j\32506\2458\277@\243\236\201\363\327\373|\343"
 1506      3036A538 
 1506      BF40A39E 
 1506      81F3D7FB 
 1506      7CE3
 1507 013a 39829B2F 		.ascii	"9\202\233/\377\2074\216CD\304\336\351\313T{\2242\246"
 1507      FF87348E 
 1507      4344C4DE 
 1507      E9CB547B 
 1507      9432A6
 1508 014d C2233DEE 		.ascii	"\302#=\356L\225\013B\372\303N\010.\241f(\331$\262v["
 1508      4C950B42 
 1508      FAC34E08 
 1508      2EA16628 
 1508      D924B276 
 1509 0162 A2496D8B 		.ascii	"\242Im\213\321%r\370\366d\206h\230\026\324\244\\\314"
 1509      D12572F8 
 1509      F6648668 
 1509      9816D4A4 
 1509      5CCC
 1510 0174 5D65B692 		.ascii	"]e\266\222lpHP\375\355\271\332^\025FW\247\215\235\204"
 1510      6C704850 
 1510      FDEDB9DA 
 1510      5E154657 
 1510      A78D9D84 
 1511 0188 90D8AB00 		.ascii	"\220\330\253\000\214\274\323\012\367\344X\005\270\263"
 1511      8CBCD30A 
 1511      F7E45805 
 1511      B8B3
 1512 0196 4506D02C 		.ascii	"E\006\320,\036\217\312?\017\002\301\257\275\003\001"
 1512      1E8FCA3F 
 1512      0F02C1AF 
 1512      BD0301
 1513 01a5 138A6B3A 		.ascii	"\023\212k:\221\021AOg\334\352\227\362\317\316\360\264"
 1513      9111414F 
 1513      67DCEA97 
 1513      F2CFCEF0 
 1513      B4
 1514 01b6 E67396AC 		.ascii	"\346s\226\254t\"\347\2555\205\342\3717\350\034u\337"
 1514      7422E7AD 
 1514      3585E2F9 
 1514      37E81C75 
 1514      DF
 1515 01c7 6E47F11A 		.ascii	"nG\361\032q\035)\305\211o\267b\016\252\030\276\033\374"
 1515      711D29C5 
 1515      896FB762 
 1515      0EAA18BE 
 1515      1BFC
 1516 01d9 563E4BC6 		.ascii	"V>K\306\322y \232\333\300\376x\315Z\364\037\335\250"
 1516      D279209A 
 1516      DBC0FE78 
 1516      CD5AF41F 
 1516      DDA8
 1517 01eb 338807C7 		.ascii	"3\210\007\3071\261\022\020Y'\200\354_`Q\177\251\031"
 1517      31B11210 
 1517      592780EC 
 1517      5F60517F 
 1517      A919
 1518 01fd B54A0D2D 		.ascii	"\265J\015-\345z\237\223\311\234\357\240\340;M\256*\365"
 1518      E57A9F93 
 1518      C99CEFA0 
 1518      E03B4DAE 
 1518      2AF5
 1519 020f B0C8EBBB 		.ascii	"\260\310\353\273<\203S\231a\027+\004~\272w\326&\341"
 1519      3C835399 
 1519      61172B04 
 1519      7EBA77D6 
 1519      26E1
 1520 0221 69146355 		.ascii	"i\024cU!\014}"
 1520      210C7D
 1523              	_ZL1K:
 1524 0228 001B362D 		.ascii	"\000\0336-lwZA"
 1524      6C775A41 
 1527              	_ZZN9AESCommon15keyScheduleCoreEPhPKhhE4rcon:
 1528 0230 00010204 		.ascii	"\000\001\002\004\010\020 @\200\0336"
 1528      08102040 
 1528      801B36
 1531              	_ZTS9AESCommon:
 1532 023b 39414553 		.ascii	"9AESCommon\000"
 1532      436F6D6D 
 1532      6F6E00
 1533 0246 0000     		.space	2
 1536              	_ZTI9AESCommon:
 1537 0248 08000000 		.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
 1538 024c 00000000 		.word	_ZTS9AESCommon
 1539 0250 00000000 		.word	_ZTI11BlockCipher
 1540              		.text
 1541              	.Letext0:
 1542              		.file 2 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 1543              		.file 3 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
 1544              		.file 4 "AES.h"
 1545              		.file 5 "Crypto.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 AESCommon.cpp
     /tmp/ccz2OvMD.s:16     .text._ZNK9AESCommon9blockSizeEv:0000000000000000 $t
     /tmp/ccz2OvMD.s:24     .text._ZNK9AESCommon9blockSizeEv:0000000000000000 _ZNK9AESCommon9blockSizeEv
.ARM.exidx.text._ZNK9AESCommon9blockSizeEv:0000000000000000 $d
     /tmp/ccz2OvMD.s:46     .text._ZN9AESCommon5clearEv:0000000000000000 $t
     /tmp/ccz2OvMD.s:53     .text._ZN9AESCommon5clearEv:0000000000000000 _ZN9AESCommon5clearEv
.ARM.exidx.text._ZN9AESCommon5clearEv:0000000000000000 $d
     /tmp/ccz2OvMD.s:80     .text._ZN9AESCommonC2Ev:0000000000000000 $t
     /tmp/ccz2OvMD.s:87     .text._ZN9AESCommonC2Ev:0000000000000000 _ZN9AESCommonC2Ev
     /tmp/ccz2OvMD.s:123    .text._ZN9AESCommonC2Ev:0000000000000018 $d
.ARM.exidx.text._ZN9AESCommonC2Ev:0000000000000000 $d
     /tmp/ccz2OvMD.s:87     .text._ZN9AESCommonC2Ev:0000000000000000 _ZN9AESCommonC1Ev
     /tmp/ccz2OvMD.s:131    .text._ZN9AESCommonD2Ev:0000000000000000 $t
     /tmp/ccz2OvMD.s:138    .text._ZN9AESCommonD2Ev:0000000000000000 _ZN9AESCommonD2Ev
     /tmp/ccz2OvMD.s:173    .text._ZN9AESCommonD2Ev:0000000000000010 $d
.ARM.exidx.text._ZN9AESCommonD2Ev:0000000000000000 $d
     /tmp/ccz2OvMD.s:138    .text._ZN9AESCommonD2Ev:0000000000000000 _ZN9AESCommonD1Ev
     /tmp/ccz2OvMD.s:182    .text._ZN9AESCommonD0Ev:0000000000000000 $t
     /tmp/ccz2OvMD.s:189    .text._ZN9AESCommonD0Ev:0000000000000000 _ZN9AESCommonD0Ev
.ARM.exidx.text._ZN9AESCommonD0Ev:0000000000000000 $d
     /tmp/ccz2OvMD.s:222    .text._ZN9AESCommon20subBytesAndShiftRowsEPhPKh:0000000000000000 $t
     /tmp/ccz2OvMD.s:229    .text._ZN9AESCommon20subBytesAndShiftRowsEPhPKh:0000000000000000 _ZN9AESCommon20subBytesAndShiftRowsEPhPKh
     /tmp/ccz2OvMD.s:356    .text._ZN9AESCommon20subBytesAndShiftRowsEPhPKh:00000000000000a4 $d
.ARM.exidx.text._ZN9AESCommon20subBytesAndShiftRowsEPhPKh:0000000000000000 $d
     /tmp/ccz2OvMD.s:363    .text._ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh:0000000000000000 $t
     /tmp/ccz2OvMD.s:370    .text._ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh:0000000000000000 _ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh
     /tmp/ccz2OvMD.s:497    .text._ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh:00000000000000a4 $d
.ARM.exidx.text._ZN9AESCommon27inverseShiftRowsAndSubBytesEPhPKh:0000000000000000 $d
     /tmp/ccz2OvMD.s:504    .text._ZN9AESCommon9mixColumnEPhS0_:0000000000000000 $t
     /tmp/ccz2OvMD.s:511    .text._ZN9AESCommon9mixColumnEPhS0_:0000000000000000 _ZN9AESCommon9mixColumnEPhS0_
.ARM.exidx.text._ZN9AESCommon9mixColumnEPhS0_:0000000000000000 $d
     /tmp/ccz2OvMD.s:646    .text._ZN9AESCommon12encryptBlockEPhPKh:0000000000000000 $t
     /tmp/ccz2OvMD.s:653    .text._ZN9AESCommon12encryptBlockEPhPKh:0000000000000000 _ZN9AESCommon12encryptBlockEPhPKh
.ARM.exidx.text._ZN9AESCommon12encryptBlockEPhPKh:0000000000000000 $d
     /tmp/ccz2OvMD.s:845    .text._ZN9AESCommon16inverseMixColumnEPhPKh:0000000000000000 $t
     /tmp/ccz2OvMD.s:852    .text._ZN9AESCommon16inverseMixColumnEPhPKh:0000000000000000 _ZN9AESCommon16inverseMixColumnEPhPKh
     /tmp/ccz2OvMD.s:1129   .text._ZN9AESCommon16inverseMixColumnEPhPKh:0000000000000178 $d
.ARM.exidx.text._ZN9AESCommon16inverseMixColumnEPhPKh:0000000000000000 $d
     /tmp/ccz2OvMD.s:1136   .text._ZN9AESCommon12decryptBlockEPhPKh:0000000000000000 $t
     /tmp/ccz2OvMD.s:1143   .text._ZN9AESCommon12decryptBlockEPhPKh:0000000000000000 _ZN9AESCommon12decryptBlockEPhPKh
.ARM.exidx.text._ZN9AESCommon12decryptBlockEPhPKh:0000000000000000 $d
     /tmp/ccz2OvMD.s:1338   .text._ZN9AESCommon15keyScheduleCoreEPhPKhh:0000000000000000 $t
     /tmp/ccz2OvMD.s:1345   .text._ZN9AESCommon15keyScheduleCoreEPhPKhh:0000000000000000 _ZN9AESCommon15keyScheduleCoreEPhPKhh
     /tmp/ccz2OvMD.s:1403   .text._ZN9AESCommon15keyScheduleCoreEPhPKhh:0000000000000038 $d
.ARM.exidx.text._ZN9AESCommon15keyScheduleCoreEPhPKhh:0000000000000000 $d
     /tmp/ccz2OvMD.s:1410   .text._ZN9AESCommon9applySboxEPhPKh:0000000000000000 $t
     /tmp/ccz2OvMD.s:1417   .text._ZN9AESCommon9applySboxEPhPKh:0000000000000000 _ZN9AESCommon9applySboxEPhPKh
     /tmp/ccz2OvMD.s:1460   .text._ZN9AESCommon9applySboxEPhPKh:000000000000002c $d
.ARM.exidx.text._ZN9AESCommon9applySboxEPhPKh:0000000000000000 $d
     /tmp/ccz2OvMD.s:1531   .rodata:000000000000023b _ZTS9AESCommon
     /tmp/ccz2OvMD.s:1536   .rodata:0000000000000248 _ZTI9AESCommon
     /tmp/ccz2OvMD.s:1474   .rodata:0000000000000000 _ZTV9AESCommon
     /tmp/ccz2OvMD.s:1470   .rodata:0000000000000000 $d
     /tmp/ccz2OvMD.s:1487   .rodata:0000000000000028 _ZL4sbox
     /tmp/ccz2OvMD.s:1505   .rodata:0000000000000128 _ZL12sbox_inverse
     /tmp/ccz2OvMD.s:1523   .rodata:0000000000000228 _ZL1K
     /tmp/ccz2OvMD.s:1527   .rodata:0000000000000230 _ZZN9AESCommon15keyScheduleCoreEPhPKhhE4rcon

UNDEFINED SYMBOLS
_Z5cleanPvj
_ZN11BlockCipherC2Ev
__aeabi_unwind_cpp_pr0
_ZN11BlockCipherD2Ev
_ZdlPvj
__cxa_pure_virtual
_ZTVN10__cxxabiv120__si_class_type_infoE
_ZTI11BlockCipher
