// ===== main_encrypt.c =====
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "encrypt.h"

int main() {
    // Dữ liệu mã hoá
    char plaintext[] = "Hanoi University of Science and Technology";
    int plaintext_len = strlen(plaintext);
    char key_text[] = "DHBK";
    int keylen = strlen(key_text);
    // Khóa mã hoá
    uint8_t key[256];
    for(int i = 0; i < keylen; i++){
        key[i] = (uint8_t)key_text[i];
    }
    
    
    // Mảng chứa bản mã
    uint8_t ciphertext[256];
    
    printf("========== RC4 ENCRYPTION PROJECT ==========\n\n");
    printf("Plaintext:  %s\n", plaintext);
    printf("Plaintext Length: %d\n", plaintext_len);
    printf("Key: ");
    for (int i = 0; i < keylen; i++) {
        printf("%02X ", key[i]);
    }
    printf("\n\n");
    
    // Gọi hàm mã hoá từ rc4_encrypt.h
    RC4_Encrypt((uint8_t *)plaintext, plaintext_len, key, keylen, ciphertext);
    
    // Hiển thị bản mã (dạng hex)
    printf("Ciphertext (HEX): ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n\n");
    
    // Hiển thị bản mã (dạng ký tự, nếu có thể hiển thị)
    printf("Ciphertext (ASCII): ");
    for (int i = 0; i < plaintext_len; i++) {
        if (ciphertext[i] >= 32 && ciphertext[i] < 127) {
            printf("%c", ciphertext[i]);
        } else {
            printf(".");
        }
    }
    printf("\n\n");
    
    printf("Mã hoá thành công!\n");
    
    return 0;
}