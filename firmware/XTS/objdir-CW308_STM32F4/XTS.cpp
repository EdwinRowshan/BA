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
  11              		.file	"XTS.cpp"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text._ZNK9XTSCommon7keySizeEv,"ax",%progbits
  16              		.align	1
  17              		.global	_ZNK9XTSCommon7keySizeEv
  18              		.arch armv7e-m
  19              		.syntax unified
  20              		.thumb
  21              		.thumb_func
  22              		.fpu softvfp
  24              	_ZNK9XTSCommon7keySizeEv:
  25              		.fnstart
  26              	.LVL0:
  27              	.LFB25:
  28              		.file 1 "XTS.cpp"
   1:XTS.cpp       **** /*
   2:XTS.cpp       ****  * Copyright (C) 2016 Southern Storm Software, Pty Ltd.
   3:XTS.cpp       ****  *
   4:XTS.cpp       ****  * Permission is hereby granted, free of charge, to any person obtaining a
   5:XTS.cpp       ****  * copy of this software and associated documentation files (the "Software"),
   6:XTS.cpp       ****  * to deal in the Software without restriction, including without limitation
   7:XTS.cpp       ****  * the rights to use, copy, modify, merge, publish, distribute, sublicense,
   8:XTS.cpp       ****  * and/or sell copies of the Software, and to permit persons to whom the
   9:XTS.cpp       ****  * Software is furnished to do so, subject to the following conditions:
  10:XTS.cpp       ****  *
  11:XTS.cpp       ****  * The above copyright notice and this permission notice shall be included
  12:XTS.cpp       ****  * in all copies or substantial portions of the Software.
  13:XTS.cpp       ****  *
  14:XTS.cpp       ****  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  15:XTS.cpp       ****  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  16:XTS.cpp       ****  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  17:XTS.cpp       ****  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  18:XTS.cpp       ****  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  19:XTS.cpp       ****  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  20:XTS.cpp       ****  * DEALINGS IN THE SOFTWARE.
  21:XTS.cpp       ****  */
  22:XTS.cpp       **** 
  23:XTS.cpp       **** #include "XTS.h"
  24:XTS.cpp       **** #include "Crypto.h"
  25:XTS.cpp       **** #include "GF128.h"
  26:XTS.cpp       **** #include <string.h>
  27:XTS.cpp       **** 
  28:XTS.cpp       **** extern "C" {
  29:XTS.cpp       ****     #include "simpleserial.h"
  30:XTS.cpp       ****     #include "hal.h"
  31:XTS.cpp       **** }
  32:XTS.cpp       **** 
  33:XTS.cpp       **** /**
  34:XTS.cpp       ****  * \class XTSCommon XTS.h <XTS.h>
  35:XTS.cpp       ****  * \brief Concrete base class to assist with implementing XTS mode for
  36:XTS.cpp       ****  * 128-bit block ciphers.
  37:XTS.cpp       ****  *
  38:XTS.cpp       ****  * References: <a href="http://libeccio.di.unisa.it/Crypto14/Lab/p1619.pdf">IEEE Std. 1619-2007</a>
  39:XTS.cpp       ****  *
  40:XTS.cpp       ****  * \sa XTS, XTSSingleKey
  41:XTS.cpp       ****  */
  42:XTS.cpp       **** 
  43:XTS.cpp       **** /**
  44:XTS.cpp       ****  * \brief Constructs an XTS object with a default sector size of 512 bytes.
  45:XTS.cpp       ****  */
  46:XTS.cpp       **** XTSCommon::XTSCommon()
  47:XTS.cpp       ****     : sectSize(512)
  48:XTS.cpp       **** {
  49:XTS.cpp       **** }
  50:XTS.cpp       **** 
  51:XTS.cpp       **** /**
  52:XTS.cpp       ****  * \brief Clears all sensitive information and destroys this object.
  53:XTS.cpp       ****  */
  54:XTS.cpp       **** XTSCommon::~XTSCommon()
  55:XTS.cpp       **** {
  56:XTS.cpp       ****     clean(twk);
  57:XTS.cpp       **** }
  58:XTS.cpp       **** 
  59:XTS.cpp       **** /**
  60:XTS.cpp       ****  * \brief Gets the size of the key for XTS mode.
  61:XTS.cpp       ****  *
  62:XTS.cpp       ****  * The key size for XTS mode is twice the size of the underlying
  63:XTS.cpp       ****  * block cipher key size.
  64:XTS.cpp       ****  *
  65:XTS.cpp       ****  * \sa setKey(), tweakSize()
  66:XTS.cpp       ****  */
  67:XTS.cpp       **** size_t XTSCommon::keySize() const
  68:XTS.cpp       **** {
  29              		.loc 1 68 1 view -0
  30              		.cfi_startproc
  31              		@ args = 0, pretend = 0, frame = 0
  32              		@ frame_needed = 0, uses_anonymous_args = 0
  69:XTS.cpp       ****     return blockCipher1->keySize() * 2;
  33              		.loc 1 69 5 view .LVU1
  34              		.loc 1 69 12 is_stmt 0 view .LVU2
  35 0000 4068     		ldr	r0, [r0, #4]
  36              	.LVL1:
  68:XTS.cpp       ****     return blockCipher1->keySize() * 2;
  37              		.loc 1 68 1 view .LVU3
  38 0002 08B5     		push	{r3, lr}
  39              		.save {r3, lr}
  40              	.LCFI0:
  41              		.cfi_def_cfa_offset 8
  42              		.cfi_offset 3, -8
  43              		.cfi_offset 14, -4
  44              		.loc 1 69 34 view .LVU4
  45 0004 0368     		ldr	r3, [r0]
  46              		.loc 1 69 33 view .LVU5
  47 0006 DB68     		ldr	r3, [r3, #12]
  48 0008 9847     		blx	r3
  49              	.LVL2:
  70:XTS.cpp       **** }
  50              		.loc 1 70 1 view .LVU6
  51 000a 4000     		lsls	r0, r0, #1
  52 000c 08BD     		pop	{r3, pc}
  53              		.cfi_endproc
  54              	.LFE25:
  55              		.fnend
  57              		.section	.text._ZN9XTSCommon6setKeyEPKhj,"ax",%progbits
  58              		.align	1
  59              		.global	_ZN9XTSCommon6setKeyEPKhj
  60              		.syntax unified
  61              		.thumb
  62              		.thumb_func
  63              		.fpu softvfp
  65              	_ZN9XTSCommon6setKeyEPKhj:
  66              		.fnstart
  67              	.LVL3:
  68              	.LFB28:
  71:XTS.cpp       **** 
  72:XTS.cpp       **** /**
  73:XTS.cpp       ****  * \brief Gets the maximum supported size for the tweak.
  74:XTS.cpp       ****  *
  75:XTS.cpp       ****  * This function returns 16, which indicates that any tweak up to 16 bytes
  76:XTS.cpp       ****  * in size can be specified via setTweak().
  77:XTS.cpp       ****  */
  78:XTS.cpp       **** size_t XTSCommon::tweakSize() const
  79:XTS.cpp       **** {
  80:XTS.cpp       ****     return 16;
  81:XTS.cpp       **** }
  82:XTS.cpp       **** 
  83:XTS.cpp       **** /**
  84:XTS.cpp       ****  * \fn size_t XTSCommon::sectorSize() const
  85:XTS.cpp       ****  * \brief Gets the size of sectors encrypted or decrypted by this class.
  86:XTS.cpp       ****  *
  87:XTS.cpp       ****  * The default value is 512 bytes.
  88:XTS.cpp       ****  *
  89:XTS.cpp       ****  * \sa setSectorSize()
  90:XTS.cpp       ****  */
  91:XTS.cpp       **** 
  92:XTS.cpp       **** /**
  93:XTS.cpp       ****  * \brief Sets the size of sectors encrypted or decrypted by this class.
  94:XTS.cpp       ****  *
  95:XTS.cpp       ****  * \param size The sector size in bytes, which must be greater than or
  96:XTS.cpp       ****  * equal to 16.
  97:XTS.cpp       ****  *
  98:XTS.cpp       ****  * \return Returns false if \a size is less than 16.
  99:XTS.cpp       ****  *
 100:XTS.cpp       ****  * \sa sectorSize(), encryptSector()
 101:XTS.cpp       ****  */
 102:XTS.cpp       **** bool XTSCommon::setSectorSize(size_t size)
 103:XTS.cpp       **** {
 104:XTS.cpp       ****     if (size < 16)
 105:XTS.cpp       ****         return false;
 106:XTS.cpp       ****     sectSize = size;
 107:XTS.cpp       ****     return true;
 108:XTS.cpp       **** }
 109:XTS.cpp       **** 
 110:XTS.cpp       **** /**
 111:XTS.cpp       ****  * \brief Sets the key to use for XTS mode.
 112:XTS.cpp       ****  *
 113:XTS.cpp       ****  * \param key Points to the key.
 114:XTS.cpp       ****  * \param len The size of the key in bytes which must be twice the
 115:XTS.cpp       ****  * size of the underlying block cipher's key size.
 116:XTS.cpp       ****  *
 117:XTS.cpp       ****  * \return Returns true if the key was set or false if \a len was incorrect.
 118:XTS.cpp       ****  *
 119:XTS.cpp       ****  * This function should be followed by a call to setTweak() to specify
 120:XTS.cpp       ****  * the sector-specific tweak.
 121:XTS.cpp       ****  *
 122:XTS.cpp       ****  * \sa keySize(), setTweak(), encryptSector()
 123:XTS.cpp       ****  */
 124:XTS.cpp       **** bool XTSCommon::setKey(const uint8_t *key, size_t len)
 125:XTS.cpp       **** {
  69              		.loc 1 125 1 is_stmt 1 view -0
  70              		.cfi_startproc
  71              		@ args = 0, pretend = 0, frame = 0
  72              		@ frame_needed = 0, uses_anonymous_args = 0
 126:XTS.cpp       ****     if (!blockCipher1->setKey(key, len / 2))
  73              		.loc 1 126 5 view .LVU8
 125:XTS.cpp       ****     if (!blockCipher1->setKey(key, len / 2))
  74              		.loc 1 125 1 is_stmt 0 view .LVU9
  75 0000 2DE9F041 		push	{r4, r5, r6, r7, r8, lr}
  76              		.save {r4, r5, r6, r7, r8, lr}
  77              	.LCFI1:
  78              		.cfi_def_cfa_offset 24
  79              		.cfi_offset 4, -24
  80              		.cfi_offset 5, -20
  81              		.cfi_offset 6, -16
  82              		.cfi_offset 7, -12
  83              		.cfi_offset 8, -8
  84              		.cfi_offset 14, -4
 125:XTS.cpp       ****     if (!blockCipher1->setKey(key, len / 2))
  85              		.loc 1 125 1 view .LVU10
  86 0004 0546     		mov	r5, r0
  87              		.loc 1 126 10 view .LVU11
  88 0006 4068     		ldr	r0, [r0, #4]
  89              	.LVL4:
  90              		.loc 1 126 43 view .LVU12
  91 0008 0368     		ldr	r3, [r0]
  92              		.loc 1 126 30 view .LVU13
  93 000a 5608     		lsrs	r6, r2, #1
 125:XTS.cpp       ****     if (!blockCipher1->setKey(key, len / 2))
  94              		.loc 1 125 1 view .LVU14
  95 000c 1446     		mov	r4, r2
  96              		.loc 1 126 30 view .LVU15
  97 000e 1B69     		ldr	r3, [r3, #16]
  98 0010 3246     		mov	r2, r6
  99              	.LVL5:
 125:XTS.cpp       ****     if (!blockCipher1->setKey(key, len / 2))
 100              		.loc 1 125 1 view .LVU16
 101 0012 0F46     		mov	r7, r1
 102              		.loc 1 126 30 view .LVU17
 103 0014 9847     		blx	r3
 104              	.LVL6:
 105              		.loc 1 126 5 view .LVU18
 106 0016 38B1     		cbz	r0, .L3
 127:XTS.cpp       ****         return false;
 128:XTS.cpp       ****     return blockCipher2->setKey(key + len / 2, len - (len / 2));
 107              		.loc 1 128 5 is_stmt 1 view .LVU19
 108              		.loc 1 128 12 is_stmt 0 view .LVU20
 109 0018 A868     		ldr	r0, [r5, #8]
 110              		.loc 1 128 63 view .LVU21
 111 001a 0368     		ldr	r3, [r0]
 112              		.loc 1 128 32 view .LVU22
 113 001c A21B     		subs	r2, r4, r6
 114 001e B919     		adds	r1, r7, r6
 115 0020 1B69     		ldr	r3, [r3, #16]
 129:XTS.cpp       **** }
 116              		.loc 1 129 1 view .LVU23
 117 0022 BDE8F041 		pop	{r4, r5, r6, r7, r8, lr}
 118              	.LCFI2:
 119              		.cfi_remember_state
 120              		.cfi_restore 14
 121              		.cfi_restore 8
 122              		.cfi_restore 7
 123              		.cfi_restore 6
 124              		.cfi_restore 5
 125              		.cfi_restore 4
 126              		.cfi_def_cfa_offset 0
 127              	.LVL7:
 128:XTS.cpp       **** }
 128              		.loc 1 128 32 view .LVU24
 129 0026 1847     		bx	r3
 130              	.LVL8:
 131              	.L3:
 132              	.LCFI3:
 133              		.cfi_restore_state
 134              		.loc 1 129 1 view .LVU25
 135 0028 BDE8F081 		pop	{r4, r5, r6, r7, r8, pc}
 136              		.loc 1 129 1 view .LVU26
 137              		.cfi_endproc
 138              	.LFE28:
 139              		.fnend
 141              		.section	.text._ZNK18XTSSingleKeyCommon7keySizeEv,"ax",%progbits
 142              		.align	1
 143              		.global	_ZNK18XTSSingleKeyCommon7keySizeEv
 144              		.syntax unified
 145              		.thumb
 146              		.thumb_func
 147              		.fpu softvfp
 149              	_ZNK18XTSSingleKeyCommon7keySizeEv:
 150              		.fnstart
 151              	.LVL9:
 152              	.LFB37:
 130:XTS.cpp       **** 
 131:XTS.cpp       **** /**
 132:XTS.cpp       ****  * \brief Sets the tweak value for the current sector to encrypt or decrypt.
 133:XTS.cpp       ****  *
 134:XTS.cpp       ****  * \param tweak Points to the tweak.
 135:XTS.cpp       ****  * \param len The length of the tweak which must be less than or equal to 16.
 136:XTS.cpp       ****  *
 137:XTS.cpp       ****  * \return Returns true if the tweak was set or false if \a len was incorrect.
 138:XTS.cpp       ****  *
 139:XTS.cpp       ****  * If \a len is less than 16, then the \a tweak will be zero-padded to
 140:XTS.cpp       ****  * 16 bytes.
 141:XTS.cpp       ****  *
 142:XTS.cpp       ****  * The \a tweak is encrypted with the second half of the XTS key to generate
 143:XTS.cpp       ****  * the actual tweak value for the sector.
 144:XTS.cpp       ****  *
 145:XTS.cpp       ****  * \sa tweakSize(), setKey(), encryptSector()
 146:XTS.cpp       ****  */
 147:XTS.cpp       **** bool XTSCommon::setTweak(const uint8_t *tweak, size_t len)
 148:XTS.cpp       **** {
 149:XTS.cpp       ****     if (len > 16)
 150:XTS.cpp       ****         return false;
 151:XTS.cpp       ****     memcpy(twk, tweak, len);
 152:XTS.cpp       ****     memset(((uint8_t *)twk) + len, 0, 16 - len);
 153:XTS.cpp       ****     blockCipher2->encryptBlock((uint8_t *)twk, (uint8_t *)twk);
 154:XTS.cpp       ****     return true;
 155:XTS.cpp       **** }
 156:XTS.cpp       **** // uint8_t XTSCommon::setTweak(const uint8_t *tweak, size_t len)
 157:XTS.cpp       **** // {
 158:XTS.cpp       **** //     if (len > 16)
 159:XTS.cpp       **** //         return false;
 160:XTS.cpp       **** //     memcpy(twk, tweak, len);
 161:XTS.cpp       **** //     memset(((uint8_t *)twk) + len, 0, 16 - len);
 162:XTS.cpp       **** //     blockCipher2->encryptBlock((uint8_t *)twk, (uint8_t *)twk);
 163:XTS.cpp       **** //     return twk[0];
 164:XTS.cpp       **** // }
 165:XTS.cpp       **** 
 166:XTS.cpp       **** #define xorTweak(output, input, tweak) \
 167:XTS.cpp       ****     do { \
 168:XTS.cpp       ****         for (uint8_t i = 0; i < 16; ++i) \
 169:XTS.cpp       ****             (output)[i] = (input)[i] ^ ((const uint8_t *)(tweak))[i]; \
 170:XTS.cpp       ****     } while (0)
 171:XTS.cpp       **** 
 172:XTS.cpp       **** /**
 173:XTS.cpp       ****  * \brief Encrypts an entire sector of data.
 174:XTS.cpp       ****  *
 175:XTS.cpp       ****  * \param output The output buffer to write the ciphertext to, which can
 176:XTS.cpp       ****  * be the same as \a input.
 177:XTS.cpp       ****  * \param input The input buffer to read the plaintext from.
 178:XTS.cpp       ****  *
 179:XTS.cpp       ****  * The \a input and \a output buffers must be at least sectorSize()
 180:XTS.cpp       ****  * bytes in length.
 181:XTS.cpp       ****  *
 182:XTS.cpp       ****  * \sa decryptSector(), setKey(), setTweak()
 183:XTS.cpp       ****  */
 184:XTS.cpp       **** // void XTSCommon::encryptSector(uint8_t *output, const uint8_t *input, uint8_t iteration)
 185:XTS.cpp       **** // XTS.cpp XTSCommon 
 186:XTS.cpp       **** // XTS.h 
 187:XTS.cpp       **** // main.c 
 188:XTS.cpp       **** 
 189:XTS.cpp       **** void XTSCommon::encryptSector(uint8_t *output, const uint8_t *input, uint8_t iteration)
 190:XTS.cpp       **** {
 191:XTS.cpp       ****     uint8_t ctr = 0;
 192:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 193:XTS.cpp       ****     size_t posn = 0;
 194:XTS.cpp       ****     uint32_t t[4];
 195:XTS.cpp       ****     memcpy(t, twk, sizeof(t));
 196:XTS.cpp       ****     while (posn < sectLast) {
 197:XTS.cpp       ****         // Process all complete 16-byte blocks.
 198:XTS.cpp       ****         xorTweak(output, input, t);
 199:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 200:XTS.cpp       ****         xorTweak(output, output, t);
 201:XTS.cpp       **** 
 202:XTS.cpp       ****         if(ctr == iteration) {
 203:XTS.cpp       ****             trigger_high();
 204:XTS.cpp       ****         }
 205:XTS.cpp       ****         //trigger_high();
 206:XTS.cpp       ****         //simpleserial_put('r', 16, (uint8_t*) t);
 207:XTS.cpp       ****         GF128::dblXTS(t);
 208:XTS.cpp       ****         //trigger_low();
 209:XTS.cpp       ****         if(ctr == iteration) {
 210:XTS.cpp       ****             trigger_low();
 211:XTS.cpp       ****         }
 212:XTS.cpp       ****         ctr+=1;
 213:XTS.cpp       ****         input += 16;
 214:XTS.cpp       ****         output += 16;
 215:XTS.cpp       ****         posn += 16;
 216:XTS.cpp       ****     }
 217:XTS.cpp       ****     if (posn < sectSize) {
 218:XTS.cpp       ****         // Perform ciphertext stealing on the final partial block.
 219:XTS.cpp       ****         uint8_t leftOver = sectSize - posn;
 220:XTS.cpp       ****         output -= 16;
 221:XTS.cpp       ****         while (leftOver > 0) {
 222:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 223:XTS.cpp       ****             --leftOver;
 224:XTS.cpp       ****             uint8_t temp = input[leftOver];
 225:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 226:XTS.cpp       ****             output[leftOver] = temp;
 227:XTS.cpp       ****         }
 228:XTS.cpp       ****         xorTweak(output, output, t);
 229:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 230:XTS.cpp       ****         xorTweak(output, output, t);
 231:XTS.cpp       ****     }
 232:XTS.cpp       **** }
 233:XTS.cpp       **** 
 234:XTS.cpp       **** /**
 235:XTS.cpp       ****  * \brief Decrypts an entire sector of data.
 236:XTS.cpp       ****  *
 237:XTS.cpp       ****  * \param output The output buffer to write the plaintext to, which can
 238:XTS.cpp       ****  * be the same as \a input.
 239:XTS.cpp       ****  * \param input The input buffer to read the ciphertext from.
 240:XTS.cpp       ****  *
 241:XTS.cpp       ****  * The \a input and \a output buffers must be at least sectorSize()
 242:XTS.cpp       ****  * bytes in length.
 243:XTS.cpp       ****  *
 244:XTS.cpp       ****  * \sa encryptSector(), setKey(), setTweak()
 245:XTS.cpp       ****  */
 246:XTS.cpp       **** void XTSCommon::decryptSector(uint8_t *output, const uint8_t *input)
 247:XTS.cpp       **** {
 248:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 249:XTS.cpp       ****     size_t posn = 0;
 250:XTS.cpp       ****     uint32_t t[4];
 251:XTS.cpp       ****     memcpy(t, twk, sizeof(t));
 252:XTS.cpp       ****     if (sectLast != sectSize)
 253:XTS.cpp       ****         sectLast -= 16;
 254:XTS.cpp       ****     while (posn < sectLast) {
 255:XTS.cpp       ****         // Process all complete 16-byte blocks.
 256:XTS.cpp       ****         xorTweak(output, input, t);
 257:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 258:XTS.cpp       ****         xorTweak(output, output, t);
 259:XTS.cpp       ****         GF128::dblXTS(t);
 260:XTS.cpp       ****         input += 16;
 261:XTS.cpp       ****         output += 16;
 262:XTS.cpp       ****         posn += 16;
 263:XTS.cpp       ****     }
 264:XTS.cpp       ****     if (posn < sectSize) {
 265:XTS.cpp       ****         // Perform ciphertext stealing on the final two blocks.
 266:XTS.cpp       ****         uint8_t leftOver = sectSize - 16 - posn;
 267:XTS.cpp       ****         uint32_t u[4];
 268:XTS.cpp       **** 
 269:XTS.cpp       ****         // Decrypt the second-last block of ciphertext to recover
 270:XTS.cpp       ****         // the last partial block of plaintext.  We need to use
 271:XTS.cpp       ****         // dblXTS(t) as the tweak for this block.  Save the current
 272:XTS.cpp       ****         // tweak in "u" for use later.
 273:XTS.cpp       ****         memcpy(u, t, sizeof(t));
 274:XTS.cpp       ****         GF128::dblXTS(t);
 275:XTS.cpp       ****         xorTweak(output, input, t);
 276:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 277:XTS.cpp       ****         xorTweak(output, output, t);
 278:XTS.cpp       **** 
 279:XTS.cpp       ****         // Swap the left-over bytes in the last two blocks.
 280:XTS.cpp       ****         while (leftOver > 0) {
 281:XTS.cpp       ****             --leftOver;
 282:XTS.cpp       ****             uint8_t temp = input[leftOver + 16];
 283:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 284:XTS.cpp       ****             output[leftOver] = temp;
 285:XTS.cpp       ****         }
 286:XTS.cpp       **** 
 287:XTS.cpp       ****         // Decrypt the second-last block using the second-last tweak.
 288:XTS.cpp       ****         xorTweak(output, output, u);
 289:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 290:XTS.cpp       ****         xorTweak(output, output, u);
 291:XTS.cpp       ****     }
 292:XTS.cpp       **** }
 293:XTS.cpp       **** 
 294:XTS.cpp       **** /**
 295:XTS.cpp       ****  * \brief Clears all security-sensitive state from this XTS object.
 296:XTS.cpp       ****  */
 297:XTS.cpp       **** void XTSCommon::clear()
 298:XTS.cpp       **** {
 299:XTS.cpp       ****     clean(twk);
 300:XTS.cpp       ****     blockCipher1->clear();
 301:XTS.cpp       ****     blockCipher2->clear();
 302:XTS.cpp       **** }
 303:XTS.cpp       **** 
 304:XTS.cpp       **** /**
 305:XTS.cpp       ****  * \fn void XTSCommon::setBlockCiphers(BlockCipher *cipher1, BlockCipher *cipher2)
 306:XTS.cpp       ****  * \brief Sets the two block ciphers to use for XTS mode.
 307:XTS.cpp       ****  *
 308:XTS.cpp       ****  * \param cipher1 Points to the first block cipher object, which must be
 309:XTS.cpp       ****  * capable of both encryption and decryption.
 310:XTS.cpp       ****  * \param cipher2 Points to the second block cipher object, which must be
 311:XTS.cpp       ****  * capable of both encryption but does not need to be capable of decryption.
 312:XTS.cpp       ****  *
 313:XTS.cpp       ****  * Both block ciphers must have a 128-bit block size.
 314:XTS.cpp       ****  */
 315:XTS.cpp       **** 
 316:XTS.cpp       **** /**
 317:XTS.cpp       ****  * \class XTSSingleKeyCommon XTS.h <XTS.h>
 318:XTS.cpp       ****  * \brief Concrete base class to assist with implementing single-key XTS
 319:XTS.cpp       ****  * mode for 128-bit block ciphers.
 320:XTS.cpp       ****  *
 321:XTS.cpp       ****  * References: <a href="http://libeccio.di.unisa.it/Crypto14/Lab/p1619.pdf">IEEE Std. 1619-2007</a>
 322:XTS.cpp       ****  *
 323:XTS.cpp       ****  * \sa XTSSingleKey, XTSCommon
 324:XTS.cpp       ****  */
 325:XTS.cpp       **** 
 326:XTS.cpp       **** /**
 327:XTS.cpp       ****  * \fn XTSSingleKeyCommon::XTSSingleKeyCommon()
 328:XTS.cpp       ****  * \brief Constructs an XTS object with a default sector size of 512 bytes.
 329:XTS.cpp       ****  */
 330:XTS.cpp       **** 
 331:XTS.cpp       **** /**
 332:XTS.cpp       ****  * \brief Clears all sensitive information and destroys this object.
 333:XTS.cpp       ****  */
 334:XTS.cpp       **** XTSSingleKeyCommon::~XTSSingleKeyCommon()
 335:XTS.cpp       **** {
 336:XTS.cpp       **** }
 337:XTS.cpp       **** 
 338:XTS.cpp       **** /**
 339:XTS.cpp       ****  * \brief Gets the size of the key for single-pkey XTS mode.
 340:XTS.cpp       ****  *
 341:XTS.cpp       ****  * The key size for single-key XTS mode is the same as the key size
 342:XTS.cpp       ****  * for the underlying block cipher.
 343:XTS.cpp       ****  *
 344:XTS.cpp       ****  * \sa setKey(), tweakSize()
 345:XTS.cpp       ****  */
 346:XTS.cpp       **** size_t XTSSingleKeyCommon::keySize() const
 347:XTS.cpp       **** {
 153              		.loc 1 347 1 is_stmt 1 view -0
 154              		.cfi_startproc
 155              		@ args = 0, pretend = 0, frame = 0
 156              		@ frame_needed = 0, uses_anonymous_args = 0
 157              		@ link register save eliminated.
 348:XTS.cpp       ****     return blockCipher1->keySize();
 158              		.loc 1 348 5 view .LVU28
 159              		.loc 1 348 12 is_stmt 0 view .LVU29
 160 0000 4068     		ldr	r0, [r0, #4]
 161              	.LVL10:
 162              		.loc 1 348 34 view .LVU30
 163 0002 0368     		ldr	r3, [r0]
 164              		.loc 1 348 33 view .LVU31
 165 0004 DB68     		ldr	r3, [r3, #12]
 166 0006 1847     		bx	r3
 167              	.LVL11:
 168              		.cfi_endproc
 169              	.LFE37:
 170              		.cantunwind
 171              		.fnend
 173              		.section	.text._ZN18XTSSingleKeyCommon6setKeyEPKhj,"ax",%progbits
 174              		.align	1
 175              		.global	_ZN18XTSSingleKeyCommon6setKeyEPKhj
 176              		.syntax unified
 177              		.thumb
 178              		.thumb_func
 179              		.fpu softvfp
 181              	_ZN18XTSSingleKeyCommon6setKeyEPKhj:
 182              		.fnstart
 183              	.LVL12:
 184              	.LFB38:
 349:XTS.cpp       **** }
 350:XTS.cpp       **** 
 351:XTS.cpp       **** /**
 352:XTS.cpp       ****  * \brief Sets the key to use for single-keyh XTS mode.
 353:XTS.cpp       ****  *
 354:XTS.cpp       ****  * \param key Points to the key.
 355:XTS.cpp       ****  * \param len The size of the key in bytes which must be same as the
 356:XTS.cpp       ****  * size of the underlying block cipher.
 357:XTS.cpp       ****  *
 358:XTS.cpp       ****  * \return Returns true if the key was set or false if \a len was incorrect.
 359:XTS.cpp       ****  *
 360:XTS.cpp       ****  * This function should be followed by a call to setTweak() to specify
 361:XTS.cpp       ****  * the sector-specific tweak.
 362:XTS.cpp       ****  *
 363:XTS.cpp       ****  * \sa keySize(), setTweak(), encryptSector()
 364:XTS.cpp       ****  */
 365:XTS.cpp       **** bool XTSSingleKeyCommon::setKey(const uint8_t *key, size_t len)
 366:XTS.cpp       **** {
 185              		.loc 1 366 1 is_stmt 1 view -0
 186              		.cfi_startproc
 187              		@ args = 0, pretend = 0, frame = 0
 188              		@ frame_needed = 0, uses_anonymous_args = 0
 189              		@ link register save eliminated.
 367:XTS.cpp       ****     return blockCipher1->setKey(key, len);
 190              		.loc 1 367 5 view .LVU33
 191              		.loc 1 367 12 is_stmt 0 view .LVU34
 192 0000 4068     		ldr	r0, [r0, #4]
 193              	.LVL13:
 194              		.loc 1 367 41 view .LVU35
 195 0002 0368     		ldr	r3, [r0]
 196              		.loc 1 367 32 view .LVU36
 197 0004 1B69     		ldr	r3, [r3, #16]
 198 0006 1847     		bx	r3
 199              	.LVL14:
 200              		.loc 1 367 32 view .LVU37
 201              		.cfi_endproc
 202              	.LFE38:
 203              		.cantunwind
 204              		.fnend
 206              		.section	.text._ZN9XTSCommonD2Ev,"ax",%progbits
 207              		.align	1
 208              		.global	_ZN9XTSCommonD2Ev
 209              		.syntax unified
 210              		.thumb
 211              		.thumb_func
 212              		.fpu softvfp
 214              	_ZN9XTSCommonD2Ev:
 215              		.fnstart
 216              	.LVL15:
 217              	.LFB22:
  54:XTS.cpp       **** {
 218              		.loc 1 54 1 is_stmt 1 view -0
 219              		.cfi_startproc
 220              		@ args = 0, pretend = 0, frame = 0
 221              		@ frame_needed = 0, uses_anonymous_args = 0
  54:XTS.cpp       **** {
 222              		.loc 1 54 1 is_stmt 0 view .LVU39
 223 0000 10B5     		push	{r4, lr}
 224              		.save {r4, lr}
 225              	.LCFI4:
 226              		.cfi_def_cfa_offset 8
 227              		.cfi_offset 4, -8
 228              		.cfi_offset 14, -4
 229              	.LBB5:
  54:XTS.cpp       **** {
 230              		.loc 1 54 23 view .LVU40
 231 0002 044B     		ldr	r3, .L7
 232              	.LBE5:
  54:XTS.cpp       **** {
 233              		.loc 1 54 1 view .LVU41
 234 0004 0446     		mov	r4, r0
 235              	.LBB10:
 236              	.LBB6:
 237              	.LBB7:
 238              		.file 2 "Crypto.h"
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
 239              		.loc 2 34 10 view .LVU42
 240 0006 1021     		movs	r1, #16
 241              	.LBE7:
 242              	.LBE6:
  54:XTS.cpp       **** {
 243              		.loc 1 54 23 view .LVU43
 244 0008 40F80C3B 		str	r3, [r0], #12
 245              	.LVL16:
  56:XTS.cpp       **** }
 246              		.loc 1 56 5 is_stmt 1 view .LVU44
 247              	.LBB9:
 248              	.LBI6:
  32:Crypto.h      **** {
 249              		.loc 2 32 13 view .LVU45
 250              	.LBB8:
 251              		.loc 2 34 10 is_stmt 0 view .LVU46
 252 000c FFF7FEFF 		bl	_Z5cleanPvj
 253              	.LVL17:
 254              		.loc 2 34 10 view .LVU47
 255              	.LBE8:
 256              	.LBE9:
 257              	.LBE10:
  57:XTS.cpp       **** 
 258              		.loc 1 57 1 view .LVU48
 259 0010 2046     		mov	r0, r4
 260 0012 10BD     		pop	{r4, pc}
 261              	.LVL18:
 262              	.L8:
  57:XTS.cpp       **** 
 263              		.loc 1 57 1 view .LVU49
 264              		.align	2
 265              	.L7:
 266 0014 08000000 		.word	.LANCHOR0+8
 267              		.cfi_endproc
 268              	.LFE22:
 269              		.global	__gxx_personality_v0
 270              		.personality	__gxx_personality_v0
 271              		.handlerdata
 272              	.LLSDA22:
 273 0008 FF       		.byte	0xff
 274 0009 FF       		.byte	0xff
 275 000a 01       		.byte	0x1
 276 000b 00       		.uleb128 .LLSDACSE22-.LLSDACSB22
 277              	.LLSDACSB22:
 278              	.LLSDACSE22:
 279              		.section	.text._ZN9XTSCommonD2Ev
 280              		.fnend
 282              		.global	_ZN9XTSCommonD1Ev
 283              		.thumb_set _ZN9XTSCommonD1Ev,_ZN9XTSCommonD2Ev
 284              		.section	.text._ZN9XTSCommonD0Ev,"ax",%progbits
 285              		.align	1
 286              		.global	_ZN9XTSCommonD0Ev
 287              		.syntax unified
 288              		.thumb
 289              		.thumb_func
 290              		.fpu softvfp
 292              	_ZN9XTSCommonD0Ev:
 293              		.fnstart
 294              	.LVL19:
 295              	.LFB24:
  54:XTS.cpp       **** {
 296              		.loc 1 54 1 is_stmt 1 view -0
 297              		.cfi_startproc
 298              		@ args = 0, pretend = 0, frame = 0
 299              		@ frame_needed = 0, uses_anonymous_args = 0
  54:XTS.cpp       **** {
 300              		.loc 1 54 1 is_stmt 0 view .LVU51
 301 0000 10B5     		push	{r4, lr}
 302              	.LCFI5:
 303              		.cfi_def_cfa_offset 8
 304              		.cfi_offset 4, -8
 305              		.cfi_offset 14, -4
  54:XTS.cpp       **** {
 306              		.loc 1 54 1 view .LVU52
 307 0002 0446     		mov	r4, r0
  57:XTS.cpp       **** 
 308              		.loc 1 57 1 view .LVU53
 309 0004 FFF7FEFF 		bl	_ZN9XTSCommonD1Ev
 310              	.LVL20:
  57:XTS.cpp       **** 
 311              		.loc 1 57 1 view .LVU54
 312 0008 2046     		mov	r0, r4
 313 000a 2021     		movs	r1, #32
 314 000c FFF7FEFF 		bl	_ZdlPvj
 315              	.LVL21:
 316 0010 2046     		mov	r0, r4
 317 0012 10BD     		pop	{r4, pc}
  57:XTS.cpp       **** 
 318              		.loc 1 57 1 view .LVU55
 319              		.cfi_endproc
 320              	.LFE24:
 321              		.cantunwind
 322              		.fnend
 324              		.section	.text._ZN18XTSSingleKeyCommonD2Ev,"ax",%progbits
 325              		.align	1
 326              		.global	_ZN18XTSSingleKeyCommonD2Ev
 327              		.syntax unified
 328              		.thumb
 329              		.thumb_func
 330              		.fpu softvfp
 332              	_ZN18XTSSingleKeyCommonD2Ev:
 333              		.fnstart
 334              	.LVL22:
 335              	.LFB34:
 334:XTS.cpp       **** {
 336              		.loc 1 334 1 is_stmt 1 view -0
 337              		.cfi_startproc
 338              		@ args = 0, pretend = 0, frame = 0
 339              		@ frame_needed = 0, uses_anonymous_args = 0
 334:XTS.cpp       **** {
 340              		.loc 1 334 1 is_stmt 0 view .LVU57
 341 0000 10B5     		push	{r4, lr}
 342              	.LCFI6:
 343              		.cfi_def_cfa_offset 8
 344              		.cfi_offset 4, -8
 345              		.cfi_offset 14, -4
 346              	.LBB11:
 334:XTS.cpp       **** {
 347              		.loc 1 334 41 view .LVU58
 348 0002 034B     		ldr	r3, .L11
 349 0004 0360     		str	r3, [r0]
 350              	.LBE11:
 334:XTS.cpp       **** {
 351              		.loc 1 334 1 view .LVU59
 352 0006 0446     		mov	r4, r0
 353              	.LBB12:
 334:XTS.cpp       **** {
 354              		.loc 1 334 41 view .LVU60
 355 0008 FFF7FEFF 		bl	_ZN9XTSCommonD2Ev
 356              	.LVL23:
 334:XTS.cpp       **** {
 357              		.loc 1 334 41 view .LVU61
 358              	.LBE12:
 336:XTS.cpp       **** 
 359              		.loc 1 336 1 view .LVU62
 360 000c 2046     		mov	r0, r4
 361 000e 10BD     		pop	{r4, pc}
 362              	.LVL24:
 363              	.L12:
 336:XTS.cpp       **** 
 364              		.loc 1 336 1 view .LVU63
 365              		.align	2
 366              	.L11:
 367 0010 20000000 		.word	.LANCHOR0+32
 368              		.cfi_endproc
 369              	.LFE34:
 370              		.cantunwind
 371              		.fnend
 373              		.global	_ZN18XTSSingleKeyCommonD1Ev
 374              		.thumb_set _ZN18XTSSingleKeyCommonD1Ev,_ZN18XTSSingleKeyCommonD2Ev
 375              		.section	.text._ZN18XTSSingleKeyCommonD0Ev,"ax",%progbits
 376              		.align	1
 377              		.global	_ZN18XTSSingleKeyCommonD0Ev
 378              		.syntax unified
 379              		.thumb
 380              		.thumb_func
 381              		.fpu softvfp
 383              	_ZN18XTSSingleKeyCommonD0Ev:
 384              		.fnstart
 385              	.LVL25:
 386              	.LFB36:
 334:XTS.cpp       **** {
 387              		.loc 1 334 1 is_stmt 1 view -0
 388              		.cfi_startproc
 389              		@ args = 0, pretend = 0, frame = 0
 390              		@ frame_needed = 0, uses_anonymous_args = 0
 334:XTS.cpp       **** {
 391              		.loc 1 334 1 is_stmt 0 view .LVU65
 392 0000 10B5     		push	{r4, lr}
 393              	.LCFI7:
 394              		.cfi_def_cfa_offset 8
 395              		.cfi_offset 4, -8
 396              		.cfi_offset 14, -4
 334:XTS.cpp       **** {
 397              		.loc 1 334 1 view .LVU66
 398 0002 0446     		mov	r4, r0
 336:XTS.cpp       **** 
 399              		.loc 1 336 1 view .LVU67
 400 0004 FFF7FEFF 		bl	_ZN18XTSSingleKeyCommonD1Ev
 401              	.LVL26:
 336:XTS.cpp       **** 
 402              		.loc 1 336 1 view .LVU68
 403 0008 2046     		mov	r0, r4
 404 000a 2021     		movs	r1, #32
 405 000c FFF7FEFF 		bl	_ZdlPvj
 406              	.LVL27:
 407 0010 2046     		mov	r0, r4
 408 0012 10BD     		pop	{r4, pc}
 336:XTS.cpp       **** 
 409              		.loc 1 336 1 view .LVU69
 410              		.cfi_endproc
 411              	.LFE36:
 412              		.cantunwind
 413              		.fnend
 415              		.section	.text.led_ok,"ax",%progbits
 416              		.align	1
 417              		.weak	led_ok
 418              		.syntax unified
 419              		.thumb
 420              		.thumb_func
 421              		.fpu softvfp
 423              	led_ok:
 424              		.fnstart
 425              	.LVL28:
 426              	.LFB16:
 427              		.file 3 ".././hal/hal.h"
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
 428              		.loc 3 201 1 is_stmt 1 view -0
 429              		.cfi_startproc
 430              		@ args = 0, pretend = 0, frame = 0
 431              		@ frame_needed = 0, uses_anonymous_args = 0
 432              		@ link register save eliminated.
 202:.././hal/hal.h **** }
 433              		.loc 3 202 1 is_stmt 0 view .LVU71
 434 0000 7047     		bx	lr
 435              		.cfi_endproc
 436              	.LFE16:
 437              		.cantunwind
 438              		.fnend
 440              		.section	.text.led_error,"ax",%progbits
 441              		.align	1
 442              		.weak	led_error
 443              		.syntax unified
 444              		.thumb
 445              		.thumb_func
 446              		.fpu softvfp
 448              	led_error:
 449              		.fnstart
 450              	.LFB41:
 451              		.cfi_startproc
 452              		@ args = 0, pretend = 0, frame = 0
 453              		@ frame_needed = 0, uses_anonymous_args = 0
 454              		@ link register save eliminated.
 455 0000 7047     		bx	lr
 456              		.cfi_endproc
 457              	.LFE41:
 458              		.cantunwind
 459              		.fnend
 461              		.section	.text._ZN9XTSCommonC2Ev,"ax",%progbits
 462              		.align	1
 463              		.global	_ZN9XTSCommonC2Ev
 464              		.syntax unified
 465              		.thumb
 466              		.thumb_func
 467              		.fpu softvfp
 469              	_ZN9XTSCommonC2Ev:
 470              		.fnstart
 471              	.LVL29:
 472              	.LFB19:
  46:XTS.cpp       ****     : sectSize(512)
 473              		.loc 1 46 1 is_stmt 1 view -0
 474              		.cfi_startproc
 475              		@ args = 0, pretend = 0, frame = 0
 476              		@ frame_needed = 0, uses_anonymous_args = 0
 477              		@ link register save eliminated.
 478              	.LBB13:
  47:XTS.cpp       **** {
 479              		.loc 1 47 19 is_stmt 0 view .LVU73
 480 0000 024A     		ldr	r2, .L17
 481 0002 0260     		str	r2, [r0]
 482 0004 4FF40072 		mov	r2, #512
 483 0008 C261     		str	r2, [r0, #28]
 484              	.LBE13:
  49:XTS.cpp       **** 
 485              		.loc 1 49 1 view .LVU74
 486 000a 7047     		bx	lr
 487              	.L18:
 488              		.align	2
 489              	.L17:
 490 000c 08000000 		.word	.LANCHOR0+8
 491              		.cfi_endproc
 492              	.LFE19:
 493              		.cantunwind
 494              		.fnend
 496              		.global	_ZN9XTSCommonC1Ev
 497              		.thumb_set _ZN9XTSCommonC1Ev,_ZN9XTSCommonC2Ev
 498              		.section	.text._ZNK9XTSCommon9tweakSizeEv,"ax",%progbits
 499              		.align	1
 500              		.global	_ZNK9XTSCommon9tweakSizeEv
 501              		.syntax unified
 502              		.thumb
 503              		.thumb_func
 504              		.fpu softvfp
 506              	_ZNK9XTSCommon9tweakSizeEv:
 507              		.fnstart
 508              	.LVL30:
 509              	.LFB26:
  79:XTS.cpp       ****     return 16;
 510              		.loc 1 79 1 is_stmt 1 view -0
 511              		.cfi_startproc
 512              		@ args = 0, pretend = 0, frame = 0
 513              		@ frame_needed = 0, uses_anonymous_args = 0
 514              		@ link register save eliminated.
  80:XTS.cpp       **** }
 515              		.loc 1 80 5 view .LVU76
  81:XTS.cpp       **** 
 516              		.loc 1 81 1 is_stmt 0 view .LVU77
 517 0000 1020     		movs	r0, #16
 518              	.LVL31:
  81:XTS.cpp       **** 
 519              		.loc 1 81 1 view .LVU78
 520 0002 7047     		bx	lr
 521              		.cfi_endproc
 522              	.LFE26:
 523              		.cantunwind
 524              		.fnend
 526              		.section	.text._ZN9XTSCommon13setSectorSizeEj,"ax",%progbits
 527              		.align	1
 528              		.global	_ZN9XTSCommon13setSectorSizeEj
 529              		.syntax unified
 530              		.thumb
 531              		.thumb_func
 532              		.fpu softvfp
 534              	_ZN9XTSCommon13setSectorSizeEj:
 535              		.fnstart
 536              	.LVL32:
 537              	.LFB27:
 103:XTS.cpp       ****     if (size < 16)
 538              		.loc 1 103 1 is_stmt 1 view -0
 539              		.cfi_startproc
 540              		@ args = 0, pretend = 0, frame = 0
 541              		@ frame_needed = 0, uses_anonymous_args = 0
 542              		@ link register save eliminated.
 104:XTS.cpp       ****         return false;
 543              		.loc 1 104 5 view .LVU80
 544 0000 0F29     		cmp	r1, #15
 106:XTS.cpp       ****     return true;
 545              		.loc 1 106 5 view .LVU81
 106:XTS.cpp       ****     return true;
 546              		.loc 1 106 14 is_stmt 0 view .LVU82
 547 0002 86BF     		itte	hi
 548 0004 C161     		strhi	r1, [r0, #28]
 107:XTS.cpp       **** }
 549              		.loc 1 107 5 is_stmt 1 view .LVU83
 107:XTS.cpp       **** }
 550              		.loc 1 107 12 is_stmt 0 view .LVU84
 551 0006 0120     		movhi	r0, #1
 552              	.LVL33:
 105:XTS.cpp       ****     sectSize = size;
 553              		.loc 1 105 16 view .LVU85
 554 0008 0020     		movls	r0, #0
 108:XTS.cpp       **** 
 555              		.loc 1 108 1 view .LVU86
 556 000a 7047     		bx	lr
 557              		.cfi_endproc
 558              	.LFE27:
 559              		.cantunwind
 560              		.fnend
 562              		.section	.text._ZN9XTSCommon8setTweakEPKhj,"ax",%progbits
 563              		.align	1
 564              		.global	_ZN9XTSCommon8setTweakEPKhj
 565              		.syntax unified
 566              		.thumb
 567              		.thumb_func
 568              		.fpu softvfp
 570              	_ZN9XTSCommon8setTweakEPKhj:
 571              		.fnstart
 572              	.LVL34:
 573              	.LFB29:
 148:XTS.cpp       ****     if (len > 16)
 574              		.loc 1 148 1 is_stmt 1 view -0
 575              		.cfi_startproc
 576              		@ args = 0, pretend = 0, frame = 0
 577              		@ frame_needed = 0, uses_anonymous_args = 0
 149:XTS.cpp       ****         return false;
 578              		.loc 1 149 5 view .LVU88
 579 0000 102A     		cmp	r2, #16
 148:XTS.cpp       ****     if (len > 16)
 580              		.loc 1 148 1 is_stmt 0 view .LVU89
 581 0002 70B5     		push	{r4, r5, r6, lr}
 582              		.save {r4, r5, r6, lr}
 583              	.LCFI8:
 584              		.cfi_def_cfa_offset 16
 585              		.cfi_offset 4, -16
 586              		.cfi_offset 5, -12
 587              		.cfi_offset 6, -8
 588              		.cfi_offset 14, -4
 148:XTS.cpp       ****     if (len > 16)
 589              		.loc 1 148 1 view .LVU90
 590 0004 0546     		mov	r5, r0
 591 0006 1446     		mov	r4, r2
 149:XTS.cpp       ****         return false;
 592              		.loc 1 149 5 view .LVU91
 593 0008 12D8     		bhi	.L25
 151:XTS.cpp       ****     memset(((uint8_t *)twk) + len, 0, 16 - len);
 594              		.loc 1 151 5 is_stmt 1 view .LVU92
 151:XTS.cpp       ****     memset(((uint8_t *)twk) + len, 0, 16 - len);
 595              		.loc 1 151 12 is_stmt 0 view .LVU93
 596 000a 00F10C06 		add	r6, r0, #12
 151:XTS.cpp       ****     memset(((uint8_t *)twk) + len, 0, 16 - len);
 597              		.loc 1 151 11 view .LVU94
 598 000e 3046     		mov	r0, r6
 599              	.LVL35:
 151:XTS.cpp       ****     memset(((uint8_t *)twk) + len, 0, 16 - len);
 600              		.loc 1 151 11 view .LVU95
 601 0010 FFF7FEFF 		bl	memcpy
 602              	.LVL36:
 152:XTS.cpp       ****     blockCipher2->encryptBlock((uint8_t *)twk, (uint8_t *)twk);
 603              		.loc 1 152 5 is_stmt 1 view .LVU96
 152:XTS.cpp       ****     blockCipher2->encryptBlock((uint8_t *)twk, (uint8_t *)twk);
 604              		.loc 1 152 11 is_stmt 0 view .LVU97
 605 0014 C4F11002 		rsb	r2, r4, #16
 606 0018 0021     		movs	r1, #0
 607 001a 3019     		adds	r0, r6, r4
 608 001c FFF7FEFF 		bl	memset
 609              	.LVL37:
 153:XTS.cpp       ****     return true;
 610              		.loc 1 153 5 is_stmt 1 view .LVU98
 611 0020 A868     		ldr	r0, [r5, #8]
 153:XTS.cpp       ****     return true;
 612              		.loc 1 153 62 is_stmt 0 view .LVU99
 613 0022 0368     		ldr	r3, [r0]
 153:XTS.cpp       ****     return true;
 614              		.loc 1 153 31 view .LVU100
 615 0024 3246     		mov	r2, r6
 616 0026 5B69     		ldr	r3, [r3, #20]
 617 0028 3146     		mov	r1, r6
 618 002a 9847     		blx	r3
 619              	.LVL38:
 154:XTS.cpp       **** }
 620              		.loc 1 154 5 is_stmt 1 view .LVU101
 154:XTS.cpp       **** }
 621              		.loc 1 154 12 is_stmt 0 view .LVU102
 622 002c 0120     		movs	r0, #1
 623              	.L24:
 155:XTS.cpp       **** // uint8_t XTSCommon::setTweak(const uint8_t *tweak, size_t len)
 624              		.loc 1 155 1 view .LVU103
 625 002e 70BD     		pop	{r4, r5, r6, pc}
 626              	.LVL39:
 627              	.L25:
 150:XTS.cpp       ****     memcpy(twk, tweak, len);
 628              		.loc 1 150 16 view .LVU104
 629 0030 0020     		movs	r0, #0
 630              	.LVL40:
 150:XTS.cpp       ****     memcpy(twk, tweak, len);
 631              		.loc 1 150 16 view .LVU105
 632 0032 FCE7     		b	.L24
 633              		.cfi_endproc
 634              	.LFE29:
 635              		.fnend
 637              		.section	.text._ZN9XTSCommon13encryptSectorEPhPKhh,"ax",%progbits
 638              		.align	1
 639              		.global	_ZN9XTSCommon13encryptSectorEPhPKhh
 640              		.syntax unified
 641              		.thumb
 642              		.thumb_func
 643              		.fpu softvfp
 645              	_ZN9XTSCommon13encryptSectorEPhPKhh:
 646              		.fnstart
 647              	.LVL41:
 648              	.LFB30:
 190:XTS.cpp       ****     uint8_t ctr = 0;
 649              		.loc 1 190 1 is_stmt 1 view -0
 650              		.cfi_startproc
 651              		@ args = 0, pretend = 0, frame = 24
 652              		@ frame_needed = 0, uses_anonymous_args = 0
 190:XTS.cpp       ****     uint8_t ctr = 0;
 653              		.loc 1 190 1 is_stmt 0 view .LVU107
 654 0000 2DE9F04F 		push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
 655              		.save {r4, r5, r6, r7, r8, r9, r10, fp, lr}
 656              	.LCFI9:
 657              		.cfi_def_cfa_offset 36
 658              		.cfi_offset 4, -36
 659              		.cfi_offset 5, -32
 660              		.cfi_offset 6, -28
 661              		.cfi_offset 7, -24
 662              		.cfi_offset 8, -20
 663              		.cfi_offset 9, -16
 664              		.cfi_offset 10, -12
 665              		.cfi_offset 11, -8
 666              		.cfi_offset 14, -4
 667 0004 9946     		mov	r9, r3
 192:XTS.cpp       ****     size_t posn = 0;
 668              		.loc 1 192 12 view .LVU108
 669 0006 C369     		ldr	r3, [r0, #28]
 670              	.LVL42:
 190:XTS.cpp       ****     uint8_t ctr = 0;
 671              		.loc 1 190 1 view .LVU109
 672              		.pad #28
 673 0008 87B0     		sub	sp, sp, #28
 674              	.LCFI10:
 675              		.cfi_def_cfa_offset 64
 192:XTS.cpp       ****     size_t posn = 0;
 676              		.loc 1 192 12 view .LVU110
 677 000a 23F00F03 		bic	r3, r3, #15
 678 000e 0193     		str	r3, [sp, #4]
 190:XTS.cpp       ****     uint8_t ctr = 0;
 679              		.loc 1 190 1 view .LVU111
 680 0010 0546     		mov	r5, r0
 191:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 681              		.loc 1 191 5 is_stmt 1 view .LVU112
 682              	.LVL43:
 192:XTS.cpp       ****     size_t posn = 0;
 683              		.loc 1 192 5 view .LVU113
 193:XTS.cpp       ****     uint32_t t[4];
 684              		.loc 1 193 5 view .LVU114
 194:XTS.cpp       ****     memcpy(t, twk, sizeof(t));
 685              		.loc 1 194 5 view .LVU115
 195:XTS.cpp       ****     while (posn < sectLast) {
 686              		.loc 1 195 5 view .LVU116
 190:XTS.cpp       ****     uint8_t ctr = 0;
 687              		.loc 1 190 1 is_stmt 0 view .LVU117
 688 0012 0C46     		mov	r4, r1
 689 0014 1646     		mov	r6, r2
 195:XTS.cpp       ****     while (posn < sectLast) {
 690              		.loc 1 195 11 view .LVU118
 691 0016 00F10C03 		add	r3, r0, #12
 692              	.LVL44:
 195:XTS.cpp       ****     while (posn < sectLast) {
 693              		.loc 1 195 11 view .LVU119
 694 001a 02AF     		add	r7, sp, #8
 695 001c 00F11C0C 		add	ip, r0, #28
 696              	.LVL45:
 697              	.L27:
 195:XTS.cpp       ****     while (posn < sectLast) {
 698              		.loc 1 195 11 view .LVU120
 699 0020 1868     		ldr	r0, [r3]	@ unaligned
 700 0022 5968     		ldr	r1, [r3, #4]	@ unaligned
 701 0024 3A46     		mov	r2, r7
 702 0026 03C2     		stmia	r2!, {r0, r1}
 703 0028 0833     		adds	r3, r3, #8
 704 002a 6345     		cmp	r3, ip
 705 002c 1746     		mov	r7, r2
 706 002e F7D1     		bne	.L27
 707 0030 4FF00008 		mov	r8, #0
 708 0034 013C     		subs	r4, r4, #1
 709              	.LVL46:
 193:XTS.cpp       ****     uint32_t t[4];
 710              		.loc 1 193 12 view .LVU121
 711 0036 4746     		mov	r7, r8
 712              	.LVL47:
 713              	.L33:
 196:XTS.cpp       ****         // Process all complete 16-byte blocks.
 714              		.loc 1 196 17 view .LVU122
 715 0038 019B     		ldr	r3, [sp, #4]
 716 003a 9F42     		cmp	r7, r3
 717 003c 04F10102 		add	r2, r4, #1
 718              	.LVL48:
 196:XTS.cpp       ****         // Process all complete 16-byte blocks.
 719              		.loc 1 196 5 is_stmt 1 view .LVU123
 196:XTS.cpp       ****         // Process all complete 16-byte blocks.
 720              		.loc 1 196 17 view .LVU124
 721 0040 32D2     		bcs	.L28
 196:XTS.cpp       ****         // Process all complete 16-byte blocks.
 722              		.loc 1 196 17 is_stmt 0 view .LVU125
 723 0042 0DF1080A 		add	r10, sp, #8
 724 0046 731E     		subs	r3, r6, #1
 725 0048 2046     		mov	r0, r4
 726 004a D446     		mov	ip, r10
 727              	.LBB14:
 728              	.LBB15:
 198:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 729              		.loc 1 198 9 view .LVU126
 730 004c 06F10F0E 		add	lr, r6, #15
 731              	.L29:
 198:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 732              		.loc 1 198 9 is_stmt 1 discriminator 2 view .LVU127
 733 0050 13F801BF 		ldrb	fp, [r3, #1]!	@ zero_extendqisi2
 734 0054 1CF8011B 		ldrb	r1, [ip], #1	@ zero_extendqisi2
 735 0058 7345     		cmp	r3, lr
 736 005a 81EA0B01 		eor	r1, r1, fp
 737 005e 00F8011F 		strb	r1, [r0, #1]!
 198:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 738              		.loc 1 198 9 discriminator 2 view .LVU128
 198:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 739              		.loc 1 198 9 discriminator 2 view .LVU129
 740 0062 F5D1     		bne	.L29
 741              	.LBE15:
 199:XTS.cpp       ****         xorTweak(output, output, t);
 742              		.loc 1 199 9 view .LVU130
 743 0064 6868     		ldr	r0, [r5, #4]
 199:XTS.cpp       ****         xorTweak(output, output, t);
 744              		.loc 1 199 50 is_stmt 0 view .LVU131
 745 0066 0368     		ldr	r3, [r0]
 199:XTS.cpp       ****         xorTweak(output, output, t);
 746              		.loc 1 199 35 view .LVU132
 747 0068 1146     		mov	r1, r2
 748 006a 5B69     		ldr	r3, [r3, #20]
 749 006c 9847     		blx	r3
 750              	.LVL49:
 751              	.LBB16:
 200:XTS.cpp       **** 
 752              		.loc 1 200 9 is_stmt 1 view .LVU133
 753              	.LBE16:
 199:XTS.cpp       ****         xorTweak(output, output, t);
 754              		.loc 1 199 35 is_stmt 0 view .LVU134
 755 006e 2146     		mov	r1, r4
 756 0070 1034     		adds	r4, r4, #16
 757              	.LVL50:
 758              	.L30:
 759              	.LBB17:
 200:XTS.cpp       **** 
 760              		.loc 1 200 9 is_stmt 1 discriminator 2 view .LVU135
 761 0072 11F8012F 		ldrb	r2, [r1, #1]!	@ zero_extendqisi2
 762              	.LVL51:
 200:XTS.cpp       **** 
 763              		.loc 1 200 9 is_stmt 0 discriminator 2 view .LVU136
 764 0076 1AF8013B 		ldrb	r3, [r10], #1	@ zero_extendqisi2
 765 007a A142     		cmp	r1, r4
 766 007c 83EA0203 		eor	r3, r3, r2
 767 0080 0B70     		strb	r3, [r1]
 200:XTS.cpp       **** 
 768              		.loc 1 200 9 is_stmt 1 discriminator 2 view .LVU137
 769              	.LVL52:
 200:XTS.cpp       **** 
 770              		.loc 1 200 9 discriminator 2 view .LVU138
 771 0082 F6D1     		bne	.L30
 772              	.LBE17:
 202:XTS.cpp       ****             trigger_high();
 773              		.loc 1 202 9 view .LVU139
 774 0084 5FFA88FA 		uxtb	r10, r8
 775 0088 D145     		cmp	r9, r10
 776 008a 01D1     		bne	.L31
 203:XTS.cpp       ****         }
 777              		.loc 1 203 13 view .LVU140
 203:XTS.cpp       ****         }
 778              		.loc 1 203 25 is_stmt 0 view .LVU141
 779 008c FFF7FEFF 		bl	trigger_high
 780              	.LVL53:
 781              	.L31:
 207:XTS.cpp       ****         //trigger_low();
 782              		.loc 1 207 9 is_stmt 1 view .LVU142
 207:XTS.cpp       ****         //trigger_low();
 783              		.loc 1 207 22 is_stmt 0 view .LVU143
 784 0090 02A8     		add	r0, sp, #8
 785 0092 FFF7FEFF 		bl	_ZN5GF1286dblXTSEPm
 786              	.LVL54:
 209:XTS.cpp       ****             trigger_low();
 787              		.loc 1 209 9 is_stmt 1 view .LVU144
 788 0096 D145     		cmp	r9, r10
 789 0098 01D1     		bne	.L32
 210:XTS.cpp       ****         }
 790              		.loc 1 210 13 view .LVU145
 210:XTS.cpp       ****         }
 791              		.loc 1 210 24 is_stmt 0 view .LVU146
 792 009a FFF7FEFF 		bl	trigger_low
 793              	.LVL55:
 794              	.L32:
 212:XTS.cpp       ****         input += 16;
 795              		.loc 1 212 9 is_stmt 1 view .LVU147
 213:XTS.cpp       ****         output += 16;
 796              		.loc 1 213 9 view .LVU148
 213:XTS.cpp       ****         output += 16;
 797              		.loc 1 213 15 is_stmt 0 view .LVU149
 798 009e 1036     		adds	r6, r6, #16
 799              	.LVL56:
 214:XTS.cpp       ****         posn += 16;
 800              		.loc 1 214 9 is_stmt 1 view .LVU150
 215:XTS.cpp       ****     }
 801              		.loc 1 215 9 view .LVU151
 215:XTS.cpp       ****     }
 802              		.loc 1 215 14 is_stmt 0 view .LVU152
 803 00a0 1037     		adds	r7, r7, #16
 804              	.LVL57:
 215:XTS.cpp       ****     }
 805              		.loc 1 215 14 view .LVU153
 806 00a2 08F10108 		add	r8, r8, #1
 807              	.LVL58:
 215:XTS.cpp       ****     }
 808              		.loc 1 215 14 view .LVU154
 809              	.LBE14:
 196:XTS.cpp       ****         // Process all complete 16-byte blocks.
 810              		.loc 1 196 5 view .LVU155
 811 00a6 C7E7     		b	.L33
 812              	.LVL59:
 813              	.L28:
 217:XTS.cpp       ****         // Perform ciphertext stealing on the final partial block.
 814              		.loc 1 217 5 is_stmt 1 view .LVU156
 815              	.LBB18:
 217:XTS.cpp       ****         // Perform ciphertext stealing on the final partial block.
 816              		.loc 1 217 16 is_stmt 0 view .LVU157
 817 00a8 EB69     		ldr	r3, [r5, #28]
 217:XTS.cpp       ****         // Perform ciphertext stealing on the final partial block.
 818              		.loc 1 217 5 view .LVU158
 819 00aa BB42     		cmp	r3, r7
 820 00ac 28D9     		bls	.L26
 821              	.LBB19:
 219:XTS.cpp       ****         output -= 16;
 822              		.loc 1 219 9 is_stmt 1 view .LVU159
 219:XTS.cpp       ****         output -= 16;
 823              		.loc 1 219 17 is_stmt 0 view .LVU160
 824 00ae DF1B     		subs	r7, r3, r7
 825              	.LVL60:
 219:XTS.cpp       ****         output -= 16;
 826              		.loc 1 219 17 view .LVU161
 827 00b0 FFB2     		uxtb	r7, r7
 828              	.LVL61:
 220:XTS.cpp       ****         while (leftOver > 0) {
 829              		.loc 1 220 9 is_stmt 1 view .LVU162
 220:XTS.cpp       ****         while (leftOver > 0) {
 830              		.loc 1 220 16 is_stmt 0 view .LVU163
 831 00b2 A4F10F03 		sub	r3, r4, #15
 832              	.LVL62:
 833              	.L36:
 221:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 834              		.loc 1 221 9 is_stmt 1 view .LVU164
 221:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 835              		.loc 1 221 25 view .LVU165
 836 00b6 37B1     		cbz	r7, .L35
 837              	.LBB20:
 223:XTS.cpp       ****             uint8_t temp = input[leftOver];
 838              		.loc 1 223 13 view .LVU166
 839 00b8 013F     		subs	r7, r7, #1
 840              	.LVL63:
 223:XTS.cpp       ****             uint8_t temp = input[leftOver];
 841              		.loc 1 223 13 is_stmt 0 view .LVU167
 842 00ba FFB2     		uxtb	r7, r7
 843              	.LVL64:
 224:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 844              		.loc 1 224 13 is_stmt 1 view .LVU168
 224:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 845              		.loc 1 224 21 is_stmt 0 view .LVU169
 846 00bc F15D     		ldrb	r1, [r6, r7]	@ zero_extendqisi2
 847              	.LVL65:
 225:XTS.cpp       ****             output[leftOver] = temp;
 848              		.loc 1 225 13 is_stmt 1 view .LVU170
 225:XTS.cpp       ****             output[leftOver] = temp;
 849              		.loc 1 225 52 is_stmt 0 view .LVU171
 850 00be D85D     		ldrb	r0, [r3, r7]	@ zero_extendqisi2
 225:XTS.cpp       ****             output[leftOver] = temp;
 851              		.loc 1 225 35 view .LVU172
 852 00c0 D055     		strb	r0, [r2, r7]
 226:XTS.cpp       ****         }
 853              		.loc 1 226 13 is_stmt 1 view .LVU173
 226:XTS.cpp       ****         }
 854              		.loc 1 226 30 is_stmt 0 view .LVU174
 855 00c2 D955     		strb	r1, [r3, r7]
 856              	.LBE20:
 221:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 857              		.loc 1 221 9 view .LVU175
 858 00c4 F7E7     		b	.L36
 859              	.LVL66:
 860              	.L35:
 221:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 861              		.loc 1 221 9 view .LVU176
 862 00c6 02AF     		add	r7, sp, #8
 863              	.LVL67:
 221:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 864              		.loc 1 221 9 view .LVU177
 865 00c8 1E46     		mov	r6, r3
 866              	.LVL68:
 221:XTS.cpp       ****             // Swap the left-over bytes in the last two blocks.
 867              		.loc 1 221 25 view .LVU178
 868 00ca 3846     		mov	r0, r7
 869 00cc 1A46     		mov	r2, r3
 870              	.L37:
 871              	.LVL69:
 872              	.LBB21:
 228:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 873              		.loc 1 228 9 is_stmt 1 discriminator 2 view .LVU179
 874 00ce 1178     		ldrb	r1, [r2]	@ zero_extendqisi2
 875 00d0 10F801EB 		ldrb	lr, [r0], #1	@ zero_extendqisi2
 876 00d4 9446     		mov	ip, r2
 877 00d6 81EA0E01 		eor	r1, r1, lr
 878 00da A445     		cmp	ip, r4
 879 00dc 02F8011B 		strb	r1, [r2], #1
 880              	.LVL70:
 228:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 881              		.loc 1 228 9 discriminator 2 view .LVU180
 228:XTS.cpp       ****         blockCipher1->encryptBlock(output, output);
 882              		.loc 1 228 9 discriminator 2 view .LVU181
 883 00e0 F5D1     		bne	.L37
 884              	.LBE21:
 229:XTS.cpp       ****         xorTweak(output, output, t);
 885              		.loc 1 229 9 view .LVU182
 886 00e2 6868     		ldr	r0, [r5, #4]
 229:XTS.cpp       ****         xorTweak(output, output, t);
 887              		.loc 1 229 50 is_stmt 0 view .LVU183
 888 00e4 0268     		ldr	r2, [r0]
 889              	.LVL71:
 229:XTS.cpp       ****         xorTweak(output, output, t);
 890              		.loc 1 229 35 view .LVU184
 891 00e6 1946     		mov	r1, r3
 892 00e8 5569     		ldr	r5, [r2, #20]
 893              	.LVL72:
 229:XTS.cpp       ****         xorTweak(output, output, t);
 894              		.loc 1 229 35 view .LVU185
 895 00ea 1A46     		mov	r2, r3
 896 00ec A847     		blx	r5
 897              	.LVL73:
 898              	.LBB22:
 230:XTS.cpp       ****     }
 899              		.loc 1 230 9 is_stmt 1 view .LVU186
 900              	.L38:
 230:XTS.cpp       ****     }
 901              		.loc 1 230 9 discriminator 2 view .LVU187
 902 00ee 3378     		ldrb	r3, [r6]	@ zero_extendqisi2
 903 00f0 17F8011B 		ldrb	r1, [r7], #1	@ zero_extendqisi2
 904 00f4 3246     		mov	r2, r6
 905 00f6 4B40     		eors	r3, r3, r1
 906 00f8 A242     		cmp	r2, r4
 907 00fa 06F8013B 		strb	r3, [r6], #1
 908              	.LVL74:
 230:XTS.cpp       ****     }
 909              		.loc 1 230 9 discriminator 2 view .LVU188
 230:XTS.cpp       ****     }
 910              		.loc 1 230 9 discriminator 2 view .LVU189
 911 00fe F6D1     		bne	.L38
 912              	.LVL75:
 913              	.L26:
 230:XTS.cpp       ****     }
 914              		.loc 1 230 9 is_stmt 0 discriminator 2 view .LVU190
 915              	.LBE22:
 916              	.LBE19:
 917              	.LBE18:
 232:XTS.cpp       **** 
 918              		.loc 1 232 1 view .LVU191
 919 0100 07B0     		add	sp, sp, #28
 920              	.LCFI11:
 921              		.cfi_def_cfa_offset 36
 922              		@ sp needed
 923 0102 BDE8F08F 		pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
 232:XTS.cpp       **** 
 924              		.loc 1 232 1 view .LVU192
 925              		.cfi_endproc
 926              	.LFE30:
 927              		.fnend
 929              		.section	.text._ZN9XTSCommon13decryptSectorEPhPKh,"ax",%progbits
 930              		.align	1
 931              		.global	_ZN9XTSCommon13decryptSectorEPhPKh
 932              		.syntax unified
 933              		.thumb
 934              		.thumb_func
 935              		.fpu softvfp
 937              	_ZN9XTSCommon13decryptSectorEPhPKh:
 938              		.fnstart
 939              	.LVL76:
 940              	.LFB31:
 247:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 941              		.loc 1 247 1 is_stmt 1 view -0
 942              		.cfi_startproc
 943              		@ args = 0, pretend = 0, frame = 40
 944              		@ frame_needed = 0, uses_anonymous_args = 0
 247:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 945              		.loc 1 247 1 is_stmt 0 view .LVU194
 946 0000 2DE9F04F 		push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
 947              		.save {r4, r5, r6, r7, r8, r9, r10, fp, lr}
 948              	.LCFI12:
 949              		.cfi_def_cfa_offset 36
 950              		.cfi_offset 4, -36
 951              		.cfi_offset 5, -32
 952              		.cfi_offset 6, -28
 953              		.cfi_offset 7, -24
 954              		.cfi_offset 8, -20
 955              		.cfi_offset 9, -16
 956              		.cfi_offset 10, -12
 957              		.cfi_offset 11, -8
 958              		.cfi_offset 14, -4
 248:XTS.cpp       ****     size_t posn = 0;
 959              		.loc 1 248 23 view .LVU195
 960 0004 D0F81CC0 		ldr	ip, [r0, #28]
 247:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 961              		.loc 1 247 1 view .LVU196
 962              		.pad #44
 963 0008 8BB0     		sub	sp, sp, #44
 964              	.LCFI13:
 965              		.cfi_def_cfa_offset 80
 251:XTS.cpp       ****     if (sectLast != sectSize)
 966              		.loc 1 251 11 view .LVU197
 967 000a 02AF     		add	r7, sp, #8
 247:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 968              		.loc 1 247 1 view .LVU198
 969 000c 8046     		mov	r8, r0
 248:XTS.cpp       ****     size_t posn = 0;
 970              		.loc 1 248 5 is_stmt 1 view .LVU199
 247:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 971              		.loc 1 247 1 is_stmt 0 view .LVU200
 972 000e 0C46     		mov	r4, r1
 973 0010 9246     		mov	r10, r2
 248:XTS.cpp       ****     size_t posn = 0;
 974              		.loc 1 248 12 view .LVU201
 975 0012 2CF00F05 		bic	r5, ip, #15
 976              	.LVL77:
 249:XTS.cpp       ****     uint32_t t[4];
 977              		.loc 1 249 5 is_stmt 1 view .LVU202
 250:XTS.cpp       ****     memcpy(t, twk, sizeof(t));
 978              		.loc 1 250 5 view .LVU203
 251:XTS.cpp       ****     if (sectLast != sectSize)
 979              		.loc 1 251 5 view .LVU204
 251:XTS.cpp       ****     if (sectLast != sectSize)
 980              		.loc 1 251 11 is_stmt 0 view .LVU205
 981 0016 00F10C03 		add	r3, r0, #12
 982 001a 3E46     		mov	r6, r7
 983 001c 00F11C0E 		add	lr, r0, #28
 984              	.LVL78:
 985              	.L45:
 251:XTS.cpp       ****     if (sectLast != sectSize)
 986              		.loc 1 251 11 view .LVU206
 987 0020 1868     		ldr	r0, [r3]	@ unaligned
 988 0022 5968     		ldr	r1, [r3, #4]	@ unaligned
 989 0024 3246     		mov	r2, r6
 990 0026 03C2     		stmia	r2!, {r0, r1}
 991 0028 0833     		adds	r3, r3, #8
 992 002a 7345     		cmp	r3, lr
 993 002c 1646     		mov	r6, r2
 994 002e F7D1     		bne	.L45
 252:XTS.cpp       ****         sectLast -= 16;
 995              		.loc 1 252 5 is_stmt 1 view .LVU207
 996 0030 AC45     		cmp	ip, r5
 253:XTS.cpp       ****     while (posn < sectLast) {
 997              		.loc 1 253 9 view .LVU208
 253:XTS.cpp       ****     while (posn < sectLast) {
 998              		.loc 1 253 18 is_stmt 0 view .LVU209
 999 0032 18BF     		it	ne
 1000 0034 103D     		subne	r5, r5, #16
 1001              	.LVL79:
 253:XTS.cpp       ****     while (posn < sectLast) {
 1002              		.loc 1 253 18 view .LVU210
 1003 0036 013C     		subs	r4, r4, #1
 1004              	.LVL80:
 247:XTS.cpp       ****     size_t sectLast = sectSize & ~15;
 1005              		.loc 1 247 1 view .LVU211
 1006 0038 0026     		movs	r6, #0
 1007              	.LVL81:
 1008              	.L50:
 254:XTS.cpp       ****         // Process all complete 16-byte blocks.
 1009              		.loc 1 254 17 view .LVU212
 1010 003a AE42     		cmp	r6, r5
 1011 003c 04F10109 		add	r9, r4, #1
 1012              	.LVL82:
 254:XTS.cpp       ****         // Process all complete 16-byte blocks.
 1013              		.loc 1 254 5 is_stmt 1 view .LVU213
 254:XTS.cpp       ****         // Process all complete 16-byte blocks.
 1014              		.loc 1 254 17 view .LVU214
 1015 0040 29D2     		bcs	.L47
 254:XTS.cpp       ****         // Process all complete 16-byte blocks.
 1016              		.loc 1 254 17 is_stmt 0 view .LVU215
 1017 0042 0AF1FF33 		add	r3, r10, #-1
 1018 0046 BB46     		mov	fp, r7
 1019 0048 2146     		mov	r1, r4
 1020 004a 3846     		mov	r0, r7
 1021              	.LBB23:
 1022              	.LBB24:
 256:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1023              		.loc 1 256 9 view .LVU216
 1024 004c 0AF10F0C 		add	ip, r10, #15
 1025              	.L48:
 256:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1026              		.loc 1 256 9 is_stmt 1 discriminator 2 view .LVU217
 1027 0050 13F801EF 		ldrb	lr, [r3, #1]!	@ zero_extendqisi2
 1028 0054 10F8012B 		ldrb	r2, [r0], #1	@ zero_extendqisi2
 1029 0058 6345     		cmp	r3, ip
 1030 005a 82EA0E02 		eor	r2, r2, lr
 1031 005e 01F8012F 		strb	r2, [r1, #1]!
 256:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1032              		.loc 1 256 9 discriminator 2 view .LVU218
 256:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1033              		.loc 1 256 9 discriminator 2 view .LVU219
 1034 0062 F5D1     		bne	.L48
 1035              	.LBE24:
 257:XTS.cpp       ****         xorTweak(output, output, t);
 1036              		.loc 1 257 9 view .LVU220
 1037 0064 D8F80400 		ldr	r0, [r8, #4]
 257:XTS.cpp       ****         xorTweak(output, output, t);
 1038              		.loc 1 257 50 is_stmt 0 view .LVU221
 1039 0068 0368     		ldr	r3, [r0]
 257:XTS.cpp       ****         xorTweak(output, output, t);
 1040              		.loc 1 257 35 view .LVU222
 1041 006a 4A46     		mov	r2, r9
 1042 006c 9B69     		ldr	r3, [r3, #24]
 1043 006e 4946     		mov	r1, r9
 1044 0070 9847     		blx	r3
 1045              	.LVL83:
 1046              	.LBB25:
 258:XTS.cpp       ****         GF128::dblXTS(t);
 1047              		.loc 1 258 9 is_stmt 1 view .LVU223
 1048 0072 04F11002 		add	r2, r4, #16
 1049              	.LVL84:
 1050              	.L49:
 258:XTS.cpp       ****         GF128::dblXTS(t);
 1051              		.loc 1 258 9 discriminator 2 view .LVU224
 1052 0076 14F8011F 		ldrb	r1, [r4, #1]!	@ zero_extendqisi2
 1053              	.LVL85:
 258:XTS.cpp       ****         GF128::dblXTS(t);
 1054              		.loc 1 258 9 is_stmt 0 discriminator 2 view .LVU225
 1055 007a 1BF8013B 		ldrb	r3, [fp], #1	@ zero_extendqisi2
 1056 007e 9442     		cmp	r4, r2
 1057 0080 83EA0103 		eor	r3, r3, r1
 1058 0084 2370     		strb	r3, [r4]
 258:XTS.cpp       ****         GF128::dblXTS(t);
 1059              		.loc 1 258 9 is_stmt 1 discriminator 2 view .LVU226
 1060              	.LVL86:
 258:XTS.cpp       ****         GF128::dblXTS(t);
 1061              		.loc 1 258 9 discriminator 2 view .LVU227
 1062 0086 F6D1     		bne	.L49
 1063              	.LBE25:
 259:XTS.cpp       ****         input += 16;
 1064              		.loc 1 259 9 view .LVU228
 259:XTS.cpp       ****         input += 16;
 1065              		.loc 1 259 22 is_stmt 0 view .LVU229
 1066 0088 3846     		mov	r0, r7
 1067 008a FFF7FEFF 		bl	_ZN5GF1286dblXTSEPm
 1068              	.LVL87:
 260:XTS.cpp       ****         output += 16;
 1069              		.loc 1 260 9 is_stmt 1 view .LVU230
 260:XTS.cpp       ****         output += 16;
 1070              		.loc 1 260 15 is_stmt 0 view .LVU231
 1071 008e 0AF1100A 		add	r10, r10, #16
 1072              	.LVL88:
 261:XTS.cpp       ****         posn += 16;
 1073              		.loc 1 261 9 is_stmt 1 view .LVU232
 262:XTS.cpp       ****     }
 1074              		.loc 1 262 9 view .LVU233
 262:XTS.cpp       ****     }
 1075              		.loc 1 262 14 is_stmt 0 view .LVU234
 1076 0092 1036     		adds	r6, r6, #16
 1077              	.LVL89:
 262:XTS.cpp       ****     }
 1078              		.loc 1 262 14 view .LVU235
 1079              	.LBE23:
 254:XTS.cpp       ****         // Process all complete 16-byte blocks.
 1080              		.loc 1 254 5 view .LVU236
 1081 0094 D1E7     		b	.L50
 1082              	.LVL90:
 1083              	.L47:
 264:XTS.cpp       ****         // Perform ciphertext stealing on the final two blocks.
 1084              		.loc 1 264 5 is_stmt 1 view .LVU237
 1085              	.LBB26:
 264:XTS.cpp       ****         // Perform ciphertext stealing on the final two blocks.
 1086              		.loc 1 264 16 is_stmt 0 view .LVU238
 1087 0096 D8F81C50 		ldr	r5, [r8, #28]
 1088              	.LVL91:
 264:XTS.cpp       ****         // Perform ciphertext stealing on the final two blocks.
 1089              		.loc 1 264 5 view .LVU239
 1090 009a B542     		cmp	r5, r6
 1091 009c 59D9     		bls	.L44
 1092              	.LBB27:
 266:XTS.cpp       ****         uint32_t u[4];
 1093              		.loc 1 266 9 is_stmt 1 view .LVU240
 273:XTS.cpp       ****         GF128::dblXTS(t);
 1094              		.loc 1 273 15 is_stmt 0 view .LVU241
 1095 009e 97E80F00 		ldm	r7, {r0, r1, r2, r3}
 266:XTS.cpp       ****         uint32_t u[4];
 1096              		.loc 1 266 17 view .LVU242
 1097 00a2 103D     		subs	r5, r5, #16
 1098 00a4 AD1B     		subs	r5, r5, r6
 273:XTS.cpp       ****         GF128::dblXTS(t);
 1099              		.loc 1 273 15 view .LVU243
 1100 00a6 06AE     		add	r6, sp, #24
 1101              	.LVL92:
 273:XTS.cpp       ****         GF128::dblXTS(t);
 1102              		.loc 1 273 15 view .LVU244
 1103 00a8 86E80F00 		stm	r6, {r0, r1, r2, r3}
 274:XTS.cpp       ****         xorTweak(output, input, t);
 1104              		.loc 1 274 22 view .LVU245
 1105 00ac 3846     		mov	r0, r7
 1106 00ae FFF7FEFF 		bl	_ZN5GF1286dblXTSEPm
 1107              	.LVL93:
 266:XTS.cpp       ****         uint32_t u[4];
 1108              		.loc 1 266 17 view .LVU246
 1109 00b2 EDB2     		uxtb	r5, r5
 1110              	.LVL94:
 267:XTS.cpp       **** 
 1111              		.loc 1 267 9 is_stmt 1 view .LVU247
 273:XTS.cpp       ****         GF128::dblXTS(t);
 1112              		.loc 1 273 9 view .LVU248
 274:XTS.cpp       ****         xorTweak(output, input, t);
 1113              		.loc 1 274 9 view .LVU249
 1114              	.LBB28:
 275:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1115              		.loc 1 275 9 view .LVU250
 1116 00b4 0AF1FF32 		add	r2, r10, #-1
 1117 00b8 3B46     		mov	r3, r7
 1118 00ba A346     		mov	fp, r4
 1119 00bc 0AF10F0C 		add	ip, r10, #15
 1120              	.LBE28:
 274:XTS.cpp       ****         xorTweak(output, input, t);
 1121              		.loc 1 274 22 is_stmt 0 view .LVU251
 1122 00c0 2046     		mov	r0, r4
 1123              	.LVL95:
 1124              	.L52:
 1125              	.LBB29:
 275:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1126              		.loc 1 275 9 is_stmt 1 discriminator 2 view .LVU252
 1127 00c2 12F801EF 		ldrb	lr, [r2, #1]!	@ zero_extendqisi2
 1128 00c6 17F8011B 		ldrb	r1, [r7], #1	@ zero_extendqisi2
 1129 00ca 6245     		cmp	r2, ip
 1130 00cc 81EA0E01 		eor	r1, r1, lr
 1131 00d0 00F8011F 		strb	r1, [r0, #1]!
 275:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1132              		.loc 1 275 9 discriminator 2 view .LVU253
 275:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1133              		.loc 1 275 9 discriminator 2 view .LVU254
 1134 00d4 F5D1     		bne	.L52
 1135              	.LBE29:
 276:XTS.cpp       ****         xorTweak(output, output, t);
 1136              		.loc 1 276 9 is_stmt 0 view .LVU255
 1137 00d6 D8F80400 		ldr	r0, [r8, #4]
 1138 00da 0193     		str	r3, [sp, #4]
 276:XTS.cpp       ****         xorTweak(output, output, t);
 1139              		.loc 1 276 9 is_stmt 1 view .LVU256
 276:XTS.cpp       ****         xorTweak(output, output, t);
 1140              		.loc 1 276 50 is_stmt 0 view .LVU257
 1141 00dc 0268     		ldr	r2, [r0]
 276:XTS.cpp       ****         xorTweak(output, output, t);
 1142              		.loc 1 276 35 view .LVU258
 1143 00de 4946     		mov	r1, r9
 1144 00e0 9769     		ldr	r7, [r2, #24]
 1145 00e2 4A46     		mov	r2, r9
 1146 00e4 B847     		blx	r7
 1147              	.LVL96:
 1148              	.LBB30:
 277:XTS.cpp       **** 
 1149              		.loc 1 277 9 is_stmt 1 view .LVU259
 1150              	.LBE30:
 276:XTS.cpp       ****         xorTweak(output, output, t);
 1151              		.loc 1 276 35 is_stmt 0 view .LVU260
 1152 00e6 019B     		ldr	r3, [sp, #4]
 1153 00e8 04F11007 		add	r7, r4, #16
 1154 00ec 2246     		mov	r2, r4
 1155              	.LVL97:
 1156              	.L53:
 1157              	.LBB31:
 277:XTS.cpp       **** 
 1158              		.loc 1 277 9 is_stmt 1 discriminator 2 view .LVU261
 1159 00ee 12F8010F 		ldrb	r0, [r2, #1]!	@ zero_extendqisi2
 1160              	.LVL98:
 277:XTS.cpp       **** 
 1161              		.loc 1 277 9 is_stmt 0 discriminator 2 view .LVU262
 1162 00f2 13F8011B 		ldrb	r1, [r3], #1	@ zero_extendqisi2
 1163 00f6 BA42     		cmp	r2, r7
 1164 00f8 81EA0001 		eor	r1, r1, r0
 1165 00fc 1170     		strb	r1, [r2]
 277:XTS.cpp       **** 
 1166              		.loc 1 277 9 is_stmt 1 discriminator 2 view .LVU263
 1167              	.LVL99:
 277:XTS.cpp       **** 
 1168              		.loc 1 277 9 discriminator 2 view .LVU264
 1169 00fe F6D1     		bne	.L53
 1170              	.LVL100:
 1171              	.L55:
 277:XTS.cpp       **** 
 1172              		.loc 1 277 9 is_stmt 0 discriminator 2 view .LVU265
 1173              	.LBE31:
 280:XTS.cpp       ****             --leftOver;
 1174              		.loc 1 280 9 is_stmt 1 view .LVU266
 280:XTS.cpp       ****             --leftOver;
 1175              		.loc 1 280 25 view .LVU267
 1176 0100 65B1     		cbz	r5, .L54
 1177              	.LBB32:
 281:XTS.cpp       ****             uint8_t temp = input[leftOver + 16];
 1178              		.loc 1 281 13 view .LVU268
 1179 0102 013D     		subs	r5, r5, #1
 1180              	.LVL101:
 281:XTS.cpp       ****             uint8_t temp = input[leftOver + 16];
 1181              		.loc 1 281 13 is_stmt 0 view .LVU269
 1182 0104 EDB2     		uxtb	r5, r5
 1183              	.LVL102:
 282:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 1184              		.loc 1 282 13 is_stmt 1 view .LVU270
 282:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 1185              		.loc 1 282 47 is_stmt 0 view .LVU271
 1186 0106 05F11003 		add	r3, r5, #16
 283:XTS.cpp       ****             output[leftOver] = temp;
 1187              		.loc 1 283 52 view .LVU272
 1188 010a 19F80510 		ldrb	r1, [r9, r5]	@ zero_extendqisi2
 282:XTS.cpp       ****             output[leftOver + 16] = output[leftOver];
 1189              		.loc 1 282 21 view .LVU273
 1190 010e 1AF80320 		ldrb	r2, [r10, r3]	@ zero_extendqisi2
 1191              	.LVL103:
 283:XTS.cpp       ****             output[leftOver] = temp;
 1192              		.loc 1 283 13 is_stmt 1 view .LVU274
 283:XTS.cpp       ****             output[leftOver] = temp;
 1193              		.loc 1 283 35 is_stmt 0 view .LVU275
 1194 0112 09F80310 		strb	r1, [r9, r3]
 284:XTS.cpp       ****         }
 1195              		.loc 1 284 13 is_stmt 1 view .LVU276
 284:XTS.cpp       ****         }
 1196              		.loc 1 284 30 is_stmt 0 view .LVU277
 1197 0116 09F80520 		strb	r2, [r9, r5]
 1198              	.LBE32:
 280:XTS.cpp       ****             --leftOver;
 1199              		.loc 1 280 9 view .LVU278
 1200 011a F1E7     		b	.L55
 1201              	.LVL104:
 1202              	.L54:
 280:XTS.cpp       ****             --leftOver;
 1203              		.loc 1 280 25 view .LVU279
 1204 011c 3246     		mov	r2, r6
 1205              	.L56:
 1206              	.LVL105:
 1207              	.LBB33:
 288:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1208              		.loc 1 288 9 is_stmt 1 discriminator 2 view .LVU280
 1209 011e 14F8011F 		ldrb	r1, [r4, #1]!	@ zero_extendqisi2
 1210              	.LVL106:
 288:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1211              		.loc 1 288 9 is_stmt 0 discriminator 2 view .LVU281
 1212 0122 12F8013B 		ldrb	r3, [r2], #1	@ zero_extendqisi2
 1213 0126 BC42     		cmp	r4, r7
 1214 0128 83EA0103 		eor	r3, r3, r1
 1215 012c 2370     		strb	r3, [r4]
 288:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1216              		.loc 1 288 9 is_stmt 1 discriminator 2 view .LVU282
 1217              	.LVL107:
 288:XTS.cpp       ****         blockCipher1->decryptBlock(output, output);
 1218              		.loc 1 288 9 discriminator 2 view .LVU283
 1219 012e F6D1     		bne	.L56
 1220              	.LBE33:
 289:XTS.cpp       ****         xorTweak(output, output, u);
 1221              		.loc 1 289 9 view .LVU284
 1222 0130 D8F80400 		ldr	r0, [r8, #4]
 289:XTS.cpp       ****         xorTweak(output, output, u);
 1223              		.loc 1 289 50 is_stmt 0 view .LVU285
 1224 0134 0368     		ldr	r3, [r0]
 289:XTS.cpp       ****         xorTweak(output, output, u);
 1225              		.loc 1 289 35 view .LVU286
 1226 0136 4A46     		mov	r2, r9
 1227 0138 9B69     		ldr	r3, [r3, #24]
 1228 013a 4946     		mov	r1, r9
 1229 013c 9847     		blx	r3
 1230              	.LVL108:
 1231              	.LBB34:
 290:XTS.cpp       ****     }
 1232              		.loc 1 290 9 is_stmt 1 view .LVU287
 1233              	.L57:
 290:XTS.cpp       ****     }
 1234              		.loc 1 290 9 discriminator 2 view .LVU288
 1235 013e 1BF8012F 		ldrb	r2, [fp, #1]!	@ zero_extendqisi2
 1236              	.LVL109:
 290:XTS.cpp       ****     }
 1237              		.loc 1 290 9 is_stmt 0 discriminator 2 view .LVU289
 1238 0142 16F8013B 		ldrb	r3, [r6], #1	@ zero_extendqisi2
 1239 0146 BB45     		cmp	fp, r7
 1240 0148 83EA0203 		eor	r3, r3, r2
 1241 014c 8BF80030 		strb	r3, [fp]
 290:XTS.cpp       ****     }
 1242              		.loc 1 290 9 is_stmt 1 discriminator 2 view .LVU290
 1243              	.LVL110:
 290:XTS.cpp       ****     }
 1244              		.loc 1 290 9 discriminator 2 view .LVU291
 1245 0150 F5D1     		bne	.L57
 1246              	.LVL111:
 1247              	.L44:
 290:XTS.cpp       ****     }
 1248              		.loc 1 290 9 is_stmt 0 discriminator 2 view .LVU292
 1249              	.LBE34:
 1250              	.LBE27:
 1251              	.LBE26:
 292:XTS.cpp       **** 
 1252              		.loc 1 292 1 view .LVU293
 1253 0152 0BB0     		add	sp, sp, #44
 1254              	.LCFI14:
 1255              		.cfi_def_cfa_offset 36
 1256              		@ sp needed
 1257 0154 BDE8F08F 		pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
 292:XTS.cpp       **** 
 1258              		.loc 1 292 1 view .LVU294
 1259              		.cfi_endproc
 1260              	.LFE31:
 1261              		.fnend
 1263              		.section	.text._ZN9XTSCommon5clearEv,"ax",%progbits
 1264              		.align	1
 1265              		.global	_ZN9XTSCommon5clearEv
 1266              		.syntax unified
 1267              		.thumb
 1268              		.thumb_func
 1269              		.fpu softvfp
 1271              	_ZN9XTSCommon5clearEv:
 1272              		.fnstart
 1273              	.LVL112:
 1274              	.LFB32:
 298:XTS.cpp       ****     clean(twk);
 1275              		.loc 1 298 1 is_stmt 1 view -0
 1276              		.cfi_startproc
 1277              		@ args = 0, pretend = 0, frame = 0
 1278              		@ frame_needed = 0, uses_anonymous_args = 0
 299:XTS.cpp       ****     blockCipher1->clear();
 1279              		.loc 1 299 5 view .LVU296
 1280              	.LBB37:
 1281              	.LBI37:
  32:Crypto.h      **** {
 1282              		.loc 2 32 13 view .LVU297
 1283              	.LBE37:
 298:XTS.cpp       ****     clean(twk);
 1284              		.loc 1 298 1 is_stmt 0 view .LVU298
 1285 0000 10B5     		push	{r4, lr}
 1286              		.save {r4, lr}
 1287              	.LCFI15:
 1288              		.cfi_def_cfa_offset 8
 1289              		.cfi_offset 4, -8
 1290              		.cfi_offset 14, -4
 298:XTS.cpp       ****     clean(twk);
 1291              		.loc 1 298 1 view .LVU299
 1292 0002 0446     		mov	r4, r0
 1293              	.LBB39:
 1294              	.LBB38:
 1295              		.loc 2 34 10 view .LVU300
 1296 0004 1021     		movs	r1, #16
 1297 0006 0C30     		adds	r0, r0, #12
 1298              	.LVL113:
 1299              		.loc 2 34 10 view .LVU301
 1300 0008 FFF7FEFF 		bl	_Z5cleanPvj
 1301              	.LVL114:
 1302              		.loc 2 34 10 view .LVU302
 1303              	.LBE38:
 1304              	.LBE39:
 300:XTS.cpp       ****     blockCipher2->clear();
 1305              		.loc 1 300 5 is_stmt 1 view .LVU303
 1306 000c 6068     		ldr	r0, [r4, #4]
 300:XTS.cpp       ****     blockCipher2->clear();
 1307              		.loc 1 300 25 is_stmt 0 view .LVU304
 1308 000e 0368     		ldr	r3, [r0]
 300:XTS.cpp       ****     blockCipher2->clear();
 1309              		.loc 1 300 24 view .LVU305
 1310 0010 DB69     		ldr	r3, [r3, #28]
 1311 0012 9847     		blx	r3
 1312              	.LVL115:
 301:XTS.cpp       **** }
 1313              		.loc 1 301 5 is_stmt 1 view .LVU306
 1314 0014 A068     		ldr	r0, [r4, #8]
 301:XTS.cpp       **** }
 1315              		.loc 1 301 25 is_stmt 0 view .LVU307
 1316 0016 0368     		ldr	r3, [r0]
 302:XTS.cpp       **** 
 1317              		.loc 1 302 1 view .LVU308
 1318 0018 BDE81040 		pop	{r4, lr}
 1319              	.LCFI16:
 1320              		.cfi_restore 14
 1321              		.cfi_restore 4
 1322              		.cfi_def_cfa_offset 0
 1323              	.LVL116:
 301:XTS.cpp       **** }
 1324              		.loc 1 301 24 view .LVU309
 1325 001c DB69     		ldr	r3, [r3, #28]
 1326 001e 1847     		bx	r3	@ indirect register sibling call
 1327              	.LVL117:
 1328              		.cfi_endproc
 1329              	.LFE32:
 1330              		.fnend
 1332              		.global	_ZTS9XTSCommon
 1333              		.global	_ZTI9XTSCommon
 1334              		.global	_ZTS18XTSSingleKeyCommon
 1335              		.global	_ZTI18XTSSingleKeyCommon
 1336              		.global	_ZTV9XTSCommon
 1337              		.global	_ZTV18XTSSingleKeyCommon
 1338              		.section	.rodata
 1339              		.align	2
 1340              		.set	.LANCHOR0,. + 0
 1343              	_ZTV9XTSCommon:
 1344 0000 00000000 		.word	0
 1345 0004 00000000 		.word	_ZTI9XTSCommon
 1346 0008 00000000 		.word	_ZN9XTSCommonD1Ev
 1347 000c 00000000 		.word	_ZN9XTSCommonD0Ev
 1348 0010 00000000 		.word	_ZNK9XTSCommon7keySizeEv
 1349 0014 00000000 		.word	_ZN9XTSCommon6setKeyEPKhj
 1352              	_ZTV18XTSSingleKeyCommon:
 1353 0018 00000000 		.word	0
 1354 001c 00000000 		.word	_ZTI18XTSSingleKeyCommon
 1355 0020 00000000 		.word	_ZN18XTSSingleKeyCommonD1Ev
 1356 0024 00000000 		.word	_ZN18XTSSingleKeyCommonD0Ev
 1357 0028 00000000 		.word	_ZNK18XTSSingleKeyCommon7keySizeEv
 1358 002c 00000000 		.word	_ZN18XTSSingleKeyCommon6setKeyEPKhj
 1361              	_ZTS9XTSCommon:
 1362 0030 39585453 		.ascii	"9XTSCommon\000"
 1362      436F6D6D 
 1362      6F6E00
 1363 003b 00       		.space	1
 1366              	_ZTI9XTSCommon:
 1367 003c 08000000 		.word	_ZTVN10__cxxabiv117__class_type_infoE+8
 1368 0040 00000000 		.word	_ZTS9XTSCommon
 1371              	_ZTS18XTSSingleKeyCommon:
 1372 0044 31385854 		.ascii	"18XTSSingleKeyCommon\000"
 1372      5353696E 
 1372      676C654B 
 1372      6579436F 
 1372      6D6D6F6E 
 1373 0059 000000   		.space	3
 1376              	_ZTI18XTSSingleKeyCommon:
 1377 005c 08000000 		.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
 1378 0060 00000000 		.word	_ZTS18XTSSingleKeyCommon
 1379 0064 00000000 		.word	_ZTI9XTSCommon
 1380              		.text
 1381              	.Letext0:
 1382              		.file 4 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stdint.h"
 1383              		.file 5 "/usr/lib/gcc/arm-none-eabi/10.3.1/include/stddef.h"
 1384              		.file 6 "GF128.h"
 1385              		.file 7 "XTS.h"
 1386              		.file 8 ".././hal/stm32f4/stm32f4_hal.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 XTS.cpp
     /tmp/ccmVcecc.s:16     .text._ZNK9XTSCommon7keySizeEv:0000000000000000 $t
     /tmp/ccmVcecc.s:24     .text._ZNK9XTSCommon7keySizeEv:0000000000000000 _ZNK9XTSCommon7keySizeEv
.ARM.extab.text._ZNK9XTSCommon7keySizeEv:0000000000000000 $d
.ARM.exidx.text._ZNK9XTSCommon7keySizeEv:0000000000000000 $d
     /tmp/ccmVcecc.s:58     .text._ZN9XTSCommon6setKeyEPKhj:0000000000000000 $t
     /tmp/ccmVcecc.s:65     .text._ZN9XTSCommon6setKeyEPKhj:0000000000000000 _ZN9XTSCommon6setKeyEPKhj
.ARM.exidx.text._ZN9XTSCommon6setKeyEPKhj:0000000000000000 $d
     /tmp/ccmVcecc.s:142    .text._ZNK18XTSSingleKeyCommon7keySizeEv:0000000000000000 $t
     /tmp/ccmVcecc.s:149    .text._ZNK18XTSSingleKeyCommon7keySizeEv:0000000000000000 _ZNK18XTSSingleKeyCommon7keySizeEv
.ARM.exidx.text._ZNK18XTSSingleKeyCommon7keySizeEv:0000000000000000 $d
     /tmp/ccmVcecc.s:174    .text._ZN18XTSSingleKeyCommon6setKeyEPKhj:0000000000000000 $t
     /tmp/ccmVcecc.s:181    .text._ZN18XTSSingleKeyCommon6setKeyEPKhj:0000000000000000 _ZN18XTSSingleKeyCommon6setKeyEPKhj
.ARM.exidx.text._ZN18XTSSingleKeyCommon6setKeyEPKhj:0000000000000000 $d
     /tmp/ccmVcecc.s:207    .text._ZN9XTSCommonD2Ev:0000000000000000 $t
     /tmp/ccmVcecc.s:214    .text._ZN9XTSCommonD2Ev:0000000000000000 _ZN9XTSCommonD2Ev
     /tmp/ccmVcecc.s:266    .text._ZN9XTSCommonD2Ev:0000000000000014 $d
.ARM.extab.text._ZN9XTSCommonD2Ev:0000000000000000 $d
.ARM.exidx.text._ZN9XTSCommonD2Ev:0000000000000000 $d
     /tmp/ccmVcecc.s:214    .text._ZN9XTSCommonD2Ev:0000000000000000 _ZN9XTSCommonD1Ev
     /tmp/ccmVcecc.s:285    .text._ZN9XTSCommonD0Ev:0000000000000000 $t
     /tmp/ccmVcecc.s:292    .text._ZN9XTSCommonD0Ev:0000000000000000 _ZN9XTSCommonD0Ev
.ARM.exidx.text._ZN9XTSCommonD0Ev:0000000000000000 $d
     /tmp/ccmVcecc.s:325    .text._ZN18XTSSingleKeyCommonD2Ev:0000000000000000 $t
     /tmp/ccmVcecc.s:332    .text._ZN18XTSSingleKeyCommonD2Ev:0000000000000000 _ZN18XTSSingleKeyCommonD2Ev
     /tmp/ccmVcecc.s:367    .text._ZN18XTSSingleKeyCommonD2Ev:0000000000000010 $d
.ARM.exidx.text._ZN18XTSSingleKeyCommonD2Ev:0000000000000000 $d
     /tmp/ccmVcecc.s:332    .text._ZN18XTSSingleKeyCommonD2Ev:0000000000000000 _ZN18XTSSingleKeyCommonD1Ev
     /tmp/ccmVcecc.s:376    .text._ZN18XTSSingleKeyCommonD0Ev:0000000000000000 $t
     /tmp/ccmVcecc.s:383    .text._ZN18XTSSingleKeyCommonD0Ev:0000000000000000 _ZN18XTSSingleKeyCommonD0Ev
.ARM.exidx.text._ZN18XTSSingleKeyCommonD0Ev:0000000000000000 $d
     /tmp/ccmVcecc.s:416    .text.led_ok:0000000000000000 $t
     /tmp/ccmVcecc.s:423    .text.led_ok:0000000000000000 led_ok
           .ARM.exidx.text.led_ok:0000000000000000 $d
     /tmp/ccmVcecc.s:441    .text.led_error:0000000000000000 $t
     /tmp/ccmVcecc.s:448    .text.led_error:0000000000000000 led_error
        .ARM.exidx.text.led_error:0000000000000000 $d
     /tmp/ccmVcecc.s:462    .text._ZN9XTSCommonC2Ev:0000000000000000 $t
     /tmp/ccmVcecc.s:469    .text._ZN9XTSCommonC2Ev:0000000000000000 _ZN9XTSCommonC2Ev
     /tmp/ccmVcecc.s:490    .text._ZN9XTSCommonC2Ev:000000000000000c $d
.ARM.exidx.text._ZN9XTSCommonC2Ev:0000000000000000 $d
     /tmp/ccmVcecc.s:469    .text._ZN9XTSCommonC2Ev:0000000000000000 _ZN9XTSCommonC1Ev
     /tmp/ccmVcecc.s:499    .text._ZNK9XTSCommon9tweakSizeEv:0000000000000000 $t
     /tmp/ccmVcecc.s:506    .text._ZNK9XTSCommon9tweakSizeEv:0000000000000000 _ZNK9XTSCommon9tweakSizeEv
.ARM.exidx.text._ZNK9XTSCommon9tweakSizeEv:0000000000000000 $d
     /tmp/ccmVcecc.s:527    .text._ZN9XTSCommon13setSectorSizeEj:0000000000000000 $t
     /tmp/ccmVcecc.s:534    .text._ZN9XTSCommon13setSectorSizeEj:0000000000000000 _ZN9XTSCommon13setSectorSizeEj
.ARM.exidx.text._ZN9XTSCommon13setSectorSizeEj:0000000000000000 $d
     /tmp/ccmVcecc.s:563    .text._ZN9XTSCommon8setTweakEPKhj:0000000000000000 $t
     /tmp/ccmVcecc.s:570    .text._ZN9XTSCommon8setTweakEPKhj:0000000000000000 _ZN9XTSCommon8setTweakEPKhj
.ARM.exidx.text._ZN9XTSCommon8setTweakEPKhj:0000000000000000 $d
     /tmp/ccmVcecc.s:638    .text._ZN9XTSCommon13encryptSectorEPhPKhh:0000000000000000 $t
     /tmp/ccmVcecc.s:645    .text._ZN9XTSCommon13encryptSectorEPhPKhh:0000000000000000 _ZN9XTSCommon13encryptSectorEPhPKhh
.ARM.exidx.text._ZN9XTSCommon13encryptSectorEPhPKhh:0000000000000000 $d
     /tmp/ccmVcecc.s:930    .text._ZN9XTSCommon13decryptSectorEPhPKh:0000000000000000 $t
     /tmp/ccmVcecc.s:937    .text._ZN9XTSCommon13decryptSectorEPhPKh:0000000000000000 _ZN9XTSCommon13decryptSectorEPhPKh
.ARM.exidx.text._ZN9XTSCommon13decryptSectorEPhPKh:0000000000000000 $d
     /tmp/ccmVcecc.s:1264   .text._ZN9XTSCommon5clearEv:0000000000000000 $t
     /tmp/ccmVcecc.s:1271   .text._ZN9XTSCommon5clearEv:0000000000000000 _ZN9XTSCommon5clearEv
.ARM.exidx.text._ZN9XTSCommon5clearEv:0000000000000000 $d
     /tmp/ccmVcecc.s:1361   .rodata:0000000000000030 _ZTS9XTSCommon
     /tmp/ccmVcecc.s:1366   .rodata:000000000000003c _ZTI9XTSCommon
     /tmp/ccmVcecc.s:1371   .rodata:0000000000000044 _ZTS18XTSSingleKeyCommon
     /tmp/ccmVcecc.s:1376   .rodata:000000000000005c _ZTI18XTSSingleKeyCommon
     /tmp/ccmVcecc.s:1343   .rodata:0000000000000000 _ZTV9XTSCommon
     /tmp/ccmVcecc.s:1352   .rodata:0000000000000018 _ZTV18XTSSingleKeyCommon
     /tmp/ccmVcecc.s:1339   .rodata:0000000000000000 $d

UNDEFINED SYMBOLS
__aeabi_unwind_cpp_pr1
__aeabi_unwind_cpp_pr0
_Z5cleanPvj
__gxx_personality_v0
_ZdlPvj
memcpy
memset
trigger_high
_ZN5GF1286dblXTSEPm
trigger_low
_ZTVN10__cxxabiv117__class_type_infoE
_ZTVN10__cxxabiv120__si_class_type_infoE
