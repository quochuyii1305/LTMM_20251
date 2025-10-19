# LTMM_20251
RC4 Encryption/Decryption Project


Giới thiệu
RC4 là một thuật toán mã hoá luồng (stream cipher) phát triển bởi Ron Rivest năm 1987.
Đặc điểm:

- Mã hoá dòng (stream cipher)
- Khóa có độ dài tuỳ biến (1-256 bytes)
- Tạo ra dòng khóa giả ngẫu nhiên
- Sử dụng phép XOR để mã hoá/giải mã
- Đối xứng (mã hoá = giải mã)

Cảnh báo:
 RC4 có những lỗ hổng bảo mật được phát hiện, không nên dùng trong sản xuất. Project này chỉ dùng cho mục đích học tập.

 Cấu trúc Project
RC4-Project/
│
├── Encryption Project (Mã hoá)
│   ├── rc4_encrypt.h          # Header chứa thuật toán mã hoá
│   └── main_encrypt.c         # Chương trình chính mã hoá
│
├── Decryption Project (Giải mã)
│   ├── rc4_decrypt.h          # Header chứa thuật toán giải mã
│   └── main_decrypt.c         # Chương trình chính giải mã
│
└── README.md                

Hướng dẫn biên dịch
Yêu cầu:

GCC compiler (hoặc Clang, MSVC)
Terminal/Command Prompt

- Project 1: Mã hoá
+ cd encrypt
+ gcc -o encrypt encryption.c
+ .\encrypt.exe 
Project 2: Giải mã
+ cd .. (nếu đã chạy mã hóa trước đó, tức là đang ở folder encrypt)
+ cd decrypt
+ gcc -o decrypt decryption.c
+ .\decrypt.exe



Kết quả mong đợi:
========== RC4 ENCRYPTION PROJECT (Text Key) ==========

Plaintext:  Hanoi University of Science and Technology
Plaintext Length: 42
Key (Text): DHBK
Key (Hex): 44 48 42 4B
KeyByte: C7
KeyByte: 02
KeyByte: D6
KeyByte: BA
KeyByte: 08
KeyByte: C9
KeyByte: 06
KeyByte: C0
KeyByte: D5
KeyByte: 04
KeyByte: 8F
KeyByte: 52
KeyByte: 89
KeyByte: 41
KeyByte: 4B
KeyByte: 45
KeyByte: 12
KeyByte: 1E
KeyByte: CC
KeyByte: 11
KeyByte: 0D
KeyByte: 36
KeyByte: 9E
KeyByte: 76
KeyByte: B3
KeyByte: FA
KeyByte: CC
KeyByte: BD
KeyByte: 63
KeyByte: 00
KeyByte: BF
KeyByte: DD
KeyByte: CA
KeyByte: 08
KeyByte: C6
KeyByte: F4
KeyByte: D4
KeyByte: 76
KeyByte: 42
KeyByte: 65
KeyByte: DB
KeyByte: 2B


Ciphertext (HEX): 8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 9E 6D A5 9C BA 19 2E 0A BC 52

Ciphertext (ASCII): .c..a.S..r. .(?<2q.1^U.......n...m.......R
...

Decryption
Lấy dòng hex từ output:
8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 9E 6D A5 9C BA 19 2E 0A BC 52

Kết quả mong đợi:
========== RC4 DECRYPTION PROJECT (Text Key) ==========

Ciphertext (HEX): 8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 9E 6D A5 9C BA 19 2E 0A BC 52

Ciphertext Length: 42
Key (Text): DHBK
Key (Hex): 44 48 42 4B


Plaintext: Hanoi University of Science and Technology


- Test Vector
Test Vector 1: Text Key 
Plaintext: Hanoi University of Science and Technology
Key: SecretKey123
Plaintext Length: 42 bytes
Key Length: 12 bytes
Key (HEX):
53 65 63 72 65 74 4B 65 79 31 32 33
S  e  c  r  e  t  K  e  y  1  2  3
KeyByte: 68
KeyByte: E7
KeyByte: D9
KeyByte: 11
KeyByte: CA
KeyByte: F4
KeyByte: 7E
KeyByte: E4
KeyByte: 0F
KeyByte: E4
KeyByte: 5D
KeyByte: 2E
KeyByte: 1D
KeyByte: A4
KeyByte: 87
KeyByte: 8F
KeyByte: 1B
KeyByte: 5F
KeyByte: 20
KeyByte: 57
KeyByte: 8E
KeyByte: E7
KeyByte: 54
KeyByte: 8B
KeyByte: F2
KeyByte: 0E
KeyByte: E0
KeyByte: 79
KeyByte: F5
KeyByte: E3
KeyByte: 11
KeyByte: 49
KeyByte: 9F
KeyByte: 0B
KeyByte: 4E
KeyByte: 40
KeyByte: DF
KeyByte: 5D
KeyByte: 61
KeyByte: 9B
KeyByte: DB
KeyByte: A6
Ciphertext (HEX): 20 86 B7 7E A3 D4 2B 8A 66 92 38 5C 6E CD F3 F6 3B 30 46 77 DD 84 3D EE 9C 6D 85 59 94 8D 75 69 CB 6E 2D 28 B1 32 0D F4 BC DF
Ciphertext (ASCII):  ..~..+.f.8\n...;0Fw..=..m.Y..ui.n-(.2....


- Test Vector 2:  Key số

Plaintext: Hanoi University of Science and Technology
Key[] = {1,2,3,6}
Plaintext Length: 42 bytes
+ Cách chạy:
Sửa encryption.c:

char key_text[] = "";  // Không dùng text key

uint8_t key[] = {0x01, 0x02, 0x03, 0x06};
int keylen = 4;
bỏ    for(int i = 0; i < keylen; i++){
        key[i] = (uint8_t)key_text[i];
    }