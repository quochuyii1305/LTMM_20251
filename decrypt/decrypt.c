// ===== main_decrypt.c =====
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "decrypt.h"

int main() {
    // Bản mã đã mã hoá (từ project mã hoá)
     uint8_t ciphertext[] = {
        0x8C, 0x07, 0x8C, 0xD2, 0xE4, 0xA3, 0xCA, 0xA0, 0xE7, 0x11, 0xE8, 0xBC,
        0x53, 0x95, 0xFA, 0x68, 0x50, 0xB8, 0x86, 0x91, 0x9D, 0x1A, 0xAA, 0x70,
        0x06, 0x2C, 0xEE, 0x30, 0xDA, 0x59, 0xB4, 0x88, 0xD7, 0xBF, 0x95, 0xCC,
        0xFE, 0x47, 0x2C, 0xEA, 0x67, 0x0F
    };
    int ciphertext_len = sizeof(ciphertext);
    
    // Khóa giải mã (phải giống khóa mã hoá)
  char key_text[] = "DHBK";
    int keylen = strlen(key_text);
    // Khóa mã hoá
    uint8_t key[256];
    for(int i = 0; i < keylen; i++){
        key[i] = (uint8_t)key_text[i];
    }
    
    // Mảng chứa bản giải mã
    uint8_t plaintext[256];
    
    printf("========== RC4 DECRYPTION PROJECT ==========\n\n");
    printf("Ciphertext (HEX): ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");
    printf("Ciphertext Length: %d\n", ciphertext_len);
    printf("Key: ");
    for (int i = 0; i < keylen; i++) {
        printf("%02X ", key[i]);
    }
    printf("\n\n");
    
    // Gọi hàm giải mã từ rc4_decrypt.h
    RC4_Decrypt(ciphertext, ciphertext_len, key, keylen, plaintext);
    
    // Hiển thị bản giải mã
    printf("Plaintext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n\n");
    
    printf("Giải mã thành công!\n");
    
    return 0;
}