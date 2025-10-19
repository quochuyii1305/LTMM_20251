// ===== rc4_encrypt.h =====
#ifndef RC4_ENCRYPT_H
#define RC4_ENCRYPT_H

#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define RC4_STATE_SIZE 256

typedef struct {
    uint8_t S[RC4_STATE_SIZE];
    int i;
    int j;
} RC4_State;

// Khởi tạo vector S với các giá trị từ 0-255
void RC4_Initialize(RC4_State *state) {
    for (int i = 0; i < RC4_STATE_SIZE; i++) {
        state->S[i] = i;
    }
    state->i = 0;
    state->j = 0;
}

// Hoán vị khởi tạo S dựa trên khóa
void RC4_KeyScheduling(RC4_State *state, uint8_t *key, int keylen) {
    uint8_t T[RC4_STATE_SIZE];
    
    // Tạo vector T từ khóa K
    for (int i = 0; i < RC4_STATE_SIZE; i++) {
        T[i] = key[i % keylen];
    }
    
    // Hoán vị khởi tạo
    int j = 0;
    for (int i = 0; i < RC4_STATE_SIZE; i++) {
        j = (j + state->S[i] + T[i]) % RC4_STATE_SIZE;
        // Hoán đổi S[i] và S[j]
        uint8_t temp = state->S[i];
        state->S[i] = state->S[j];
        state->S[j] = temp;
    }
}

// Tạo dòng khóa
uint8_t RC4_GenerateKeyByte(RC4_State *state) {
    state->i = (state->i + 1) % RC4_STATE_SIZE;
    state->j = (state->j + state->S[state->i]) % RC4_STATE_SIZE;
    
    // Hoán đổi S[i] và S[j]
    uint8_t temp = state->S[state->i];
    state->S[state->i] = state->S[state->j];
    state->S[state->j] = temp;
    
    // Lấy byte khóa
    int t = (state->S[state->i] + state->S[state->j]) % RC4_STATE_SIZE;
    return state->S[t];
}

// Mã hoá chuỗi dữ liệu
void RC4_Encrypt(uint8_t *plaintext, int plaintext_len, 
                 uint8_t *key, int keylen, 
                 uint8_t *ciphertext) {
    RC4_State state;
    
    // Bước 1: Khởi tạo
    RC4_Initialize(&state);
    
    // Bước 2: Hoán vị khởi tạo
    RC4_KeyScheduling(&state, key, keylen);
    
    // Bước 3: Tạo dòng khóa và mã hoá
    for (int i = 0; i < plaintext_len; i++) {
        uint8_t keyByte = RC4_GenerateKeyByte(&state);

        printf("KeyByte: %02X\n",keyByte);
        ciphertext[i] = plaintext[i] ^ keyByte;
    }
}

#endif