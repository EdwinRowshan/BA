#include "XTS.h"
#include "BlockCipher.h"
#include <cstdint>
#include "AES.h"
#include <iostream>
#define MAX_SECTOR_SIZE 64

typedef unsigned char byte;

struct TestVector
{
    const char *name;
    byte key1[16];
    byte key2[16];
    byte plaintext[MAX_SECTOR_SIZE];
    byte ciphertext[MAX_SECTOR_SIZE];
    byte tweak[16];
    size_t sectorSize;
};

static const struct TestVector testVectorXTSAES128_1 = {
    .name        = "XTS-AES-128 #1",
    .key1        = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    .key2        = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    .plaintext   = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    .ciphertext  = {0x91, 0x7c, 0xf6, 0x9e, 0xbd, 0x68, 0xb2, 0xec,
                    0x9b, 0x9f, 0xe9, 0xa3, 0xea, 0xdd, 0xa6, 0x92,
                    0xcd, 0x43, 0xd2, 0xf5, 0x95, 0x98, 0xed, 0x85,
                    0x8c, 0x02, 0xc2, 0x65, 0x2f, 0xbf, 0x92, 0x2e},
    .tweak       = {0x00},
    .sectorSize  = 32
};


XTS<AES128> *xtsaes128;
struct TestVector testVector;
byte buffer[MAX_SECTOR_SIZE];

void testXTS(XTSCommon *cipher, const struct TestVector *test) {

    memcpy(&testVector, test, sizeof(testVector));

    std::cout << testVector.name;

    cipher->setSectorSize(testVector.sectorSize);
    cipher->setKey(testVector.key1, 32);
    cipher->setTweak(testVector.tweak, sizeof(testVector.tweak));

    std::cout << "ENCRYPTING..." << "\n";
    cipher->encryptSector(buffer, testVector.plaintext);
    if (!memcmp(buffer, testVector.ciphertext, testVector.sectorSize))
        std::cout << "PASSED ENCRYPTION" << "\n";
    else
        std::cout << "FAILED ENCRYPTION" << "\n";

    std::cout << "DECRYPTING..." << "\n";
    cipher->decryptSector(buffer, testVector.ciphertext);
    if (!memcmp(buffer, testVector.plaintext, testVector.sectorSize))
        std::cout << "PASSED DECRYPTION" << "\n";
    else
        std::cout << "FAILED DECRYPTION" << "\n";


    std::cout << "ENCRYPTING IN PLACE" << "\n";
    memcpy(buffer, testVector.plaintext, testVector.sectorSize);
    cipher->encryptSector(buffer, buffer);
    if (!memcmp(buffer, testVector.ciphertext, testVector.sectorSize))
        std::cout << "PASSED IN PLACE ENCRYPT" << "\n";
    else
        std::cout << "FAILED IN PLACE ENCRYPT" << "\n";

    std::cout << "DECRYPTING IN PLACE" << "\n";
    memcpy(buffer, testVector.ciphertext, testVector.sectorSize);
    cipher->decryptSector(buffer, buffer);
    if (!memcmp(buffer, testVector.plaintext, testVector.sectorSize))
        std::cout << "PASSED IN PLACE DECRYPT" << "\n";
    else
        std::cout << "FAILED IN PLACE DECRYPT" << "\n"; 
}

int main() {
    
    //NO MAKE FILE XD
    //g++ -o xts_test main.cpp AESCommon.cpp AES128.cpp XTS.cpp BlockCipher.cpp Crypto.cpp GF128.cpp -std=c++11
    xtsaes128 = new XTS<AES128>();
    testXTS(xtsaes128, &testVectorXTSAES128_1);
    return 0;
}