# RC4 Encryption/Decryption Project

## 📋 Mục lục
- [Giới thiệu](#giới-thiệu)
- [Cấu trúc Project](#cấu-trúc-project)
- [Hướng dẫn biên dịch](#hướng-dẫn-biên-dịch)
- [Hướng dẫn chạy](#hướng-dẫn-chạy)
- [Test Vector](#test-vector)
- [Kết quả mong đợi](#kết-quả-mong-đợi)

---

## 🔐 Giới thiệu

**RC4** là một thuật toán mã hoá luồng (stream cipher) phát triển bởi Ron Rivest năm 1987.

### Đặc điểm:
- ✅ Mã hoá dòng (stream cipher)
- ✅ Khóa có độ dài tuỳ biến (1-256 bytes)
- ✅ Tạo ra dòng khóa giả ngẫu nhiên
- ✅ Sử dụng phép XOR để mã hoá/giải mã
- ✅ Đối xứng (mã hoá = giải mã)

### Cảnh báo:
⚠️ **RC4 có những lỗ hổng bảo mật được phát hiện, không nên dùng trong sản xuất. Project này chỉ dùng cho mục đích học tập.**

---

## 📁 Cấu trúc Project

```
LTMM_20251/
│
├── .vscode/                    # VS Code config
├── build/                      # Folder chứa file .exe sau biên dịch
│
├── encrypt/                    # Project mã hoá
│   ├── encrypt.h          # Header chứa thuật toán mã hoá
│   └── encryption.c         # Chương trình chính mã hoá
│
├── decrypt/                    # Project giải mã
│   ├── decrypt.h          # Header chứa thuật toán giải mã
│   └── decryption.c         # Chương trình chính giải mã
│
└── README.md              
```

---

## 🛠️ Hướng dẫn biên dịch

### **Yêu cầu:**
- GCC compiler (hoặc Clang, MSVC)
- Terminal/PowerShell

### **Project 1: Mã hoá**

```bash
gcc -o build/encrypt encrypt/encryption.c
```

### **Project 2: Giải mã**

```bash
gcc -o build/decrypt decrypt/decryptiont.c
```

### **Biên dịch trên các hệ điều hành:**

#### Windows (PowerShell):
```powershell
gcc -o build/encrypt.exe encrypt/encryption.c
gcc -o build/decrypt.exe decrypt/decryption.c
```

#### Linux/macOS:
```bash
gcc -o build/encrypt encrypt/encryption.c
gcc -o build/decrypt decrypt/decryption.c
```

---

## 🚀 Hướng dẫn chạy

### **Bước 1: Mở Terminal tại thư mục project**

Shift + Right Click → "Open PowerShell here"

### **Bước 2: Biên dịch (nếu chưa biên dịch)**

```bash
gcc -o build/encrypt encrypt/encryption.c
```

### **Bước 3: Chạy chương trình mã hoá**

```bash
.\build\encrypt.exe    # Windows PowerShell
./build/encrypt        # Linux/macOS
```

**Kết quả mong đợi:**
```
========== RC4 ENCRYPTION PROJECT ==========

Plaintext:  Hanoi University of Science and Technology
Plaintext Length: 42
Key: 44 48 42 4B

KeyByte: C7
KeyByte: 02
KeyByte: D6
KeyByte: BA
... (42 keybytes)

Ciphertext (HEX): 8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 9E 6D A5 9C BA 19 2E 0A BC 52

Ciphertext (ASCII): .c..a.S..r. .(?<2q.1^U.......n...m.......R
```

### **Bước 4: Copy ciphertext**

Lấy dòng HEX từ output:
```
8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 9E 6D A5 9C BA 19 2E 0A BC 52
```

### **Bước 5: Cập nhật ciphertext trong decrypt/main_decrypt.c**

Mở file `decrypt/decryption.c` và tìm:
```c
uint8_t ciphertext[] = {
    0x8F, 0x63, 0xB8, 0xD5, ...
};
```

Thay thế bằng ciphertext vừa tạo.

### **Bước 6: Biên dịch và chạy giải mã**

```bash
gcc -o build/decrypt decrypt/decryption.c
.\build\decrypt.exe    # Windows PowerShell
./build/decrypt        # Linux/macOS
```

**Kết quả mong đợi:**
```
========== RC4 DECRYPTION PROJECT ==========

Ciphertext (HEX): 8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 9E 6D A5 9C BA 19 2E 0A BC 52

Ciphertext Length: 42
Key: 44 48 42 4B

Plaintext: Hanoi University of Science and Technology
```

---

## 🧪 Test Vector

### **Test Vector 1: Key = "DHBK" (0x44 0x48 0x42 0x4B)**

| Thành phần | Giá trị |
|-----------|--------|
| **Plaintext** | `Hanoi University of Science and Technology` |
| **Key (Array)** | `[0x44, 0x48, 0x42, 0x4B]` |
| **Plaintext Length** | 42 bytes |
| **Key Length** | 4 bytes |

**Key (HEX):**
```
44 48 42 4B
D  H  B  K
```

**Expected Ciphertext (HEX):**
```
8F 63 B8 D5 61 E9 53 AE BC 72 EA 20 FA 28 3F 3C 
32 71 AA 31 5E 55 F7 13 DD 99 A9 9D 02 6E DB FD 
9E 6D A5 9C BA 19 2E 0A BC 52
```

**Keybytes sinh ra:**
```
C7 02 D6 BA 08 C9 06 C0 D5 04 8F 52 89 41 4B 45 
12 1E CC 11 0D 36 9E 76 B3 FA CC BD 63 00 BF DD 
CA 08 C6 F4 D4 76 42 65 DB 2B
```

---

### **Test Vector 2: Key = "SecretKey123"**

| Thành phần | Giá trị |
|-----------|--------|
| **Plaintext** | `Hanoi University of Science and Technology` |
| **Key** | `SecretKey123` |
| **Plaintext Length** | 42 bytes |
| **Key Length** | 12 bytes |

**Key (HEX):**
```
53 65 63 72 65 74 4B 65 79 31 32 33
S  e  c  r  e  t  K  e  y  1  2  3
```

**Expected Ciphertext (HEX):**
```
20 86 B7 7E A3 D4 2B 8A 66 92 38 5C 6E CD F3 F6 
3B 30 46 77 DD 84 3D EE 9C 6D 85 59 94 8D 75 69 
CB 6E 2D 28 B1 32 0D F4 BC DF
```

**Keybytes sinh ra:**
```
68 E7 D9 11 CA F4 7E E4 0F E4 5D 2E 1D A4 87 8F 
1B 5F 20 57 8E E7 54 8B F2 0E E0 79 F5 E3 11 49 
9F 0B 4E 40 DF 5D 61 9B DB A6
```

---

## ✅ Kết quả mong đợi

### **Tiêu chí kiểm tra:**

1. ✅ **Mã hoá thành công:**
   - Plaintext được chuyển thành Ciphertext (HEX)
   - Ciphertext có độ dài = Plaintext
   - Giá trị HEX nằm trong khoảng 00-FF
   - Hiển thị tất cả 42 Keybytes

2. ✅ **Giải mã thành công:**
   - Ciphertext được giải mã trở lại Plaintext ban đầu
   - Plaintext khớp 100%: `Hanoi University of Science and Technology`

3. ✅ **Xác minh:**
   ```
   Plaintext → (Encrypt) → Ciphertext → (Decrypt) → Plaintext
   ```

### **Ví dụ kiểm tra:**

```bash
# Chạy mã hoá
.\build\encryption.exe
# Output: Ciphertext (HEX) = 8F 63 B8 D5 ...

# Copy vào decrypt/main_decrypt.c

# Chạy giải mã
.\build\decryption.exe
# Output: Plaintext = "Hanoi University of Science and Technology"
```

---

## 🔍 Lưu ý khi chạy

### **Lỗi thường gặp:**

#### 1. Lỗi: `gcc: command not found`
**Giải pháp:** Cài đặt GCC
```bash
# Windows: Tải MinGW hoặc use WSL
# macOS: brew install gcc
# Linux: sudo apt-get install build-essential
```

#### 2. Lỗi: `cannot find folder build`
**Giải pháp:** Tạo folder build trước
```bash
mkdir build
```

#### 3. Ciphertext không khớp
**Giải pháp:**
- Kiểm tra plaintext (42 bytes đúng không?)
- Kiểm tra key (giống nhau chưa?)
- Chạy lại từ đầu

#### 4. Giải mã ra rác
**Giải pháp:**
- Ciphertext phải giống 100%
- Key phải giống nhau
- Kiểm tra lại HEX copy

---

## 📝 Chỉnh sửa Test Vector

### **Để thử plaintext khác:**

**encrypt/main_encrypt.c:**
```c
char plaintext[] = "Your text here";
char key_text[] = "YourKeyHere";
```

**decrypt/main_decrypt.c:**
- Chỉ cần update `ciphertext[]`
- `key[]` phải giống `encrypt/encryption.c`

---

## 🎓 Cách học từ project này

1. **Hiểu thuật toán RC4:**
   - Đọc `decrypt.h` và `decrypt.h`
   - Theo dõi từng bước khởi tạo, hoán vị, sinh khóa

2. **Xem XOR hoạt động:**
   - Thêm `printf()` để in keyByte
   - So sánh plaintext vs ciphertext byte by byte

3. **Thử nghiệm:**
   - Thay đổi plaintext, key
   - Kiểm tra output thay đổi như thế nào

4. **An toàn:**
   - Học tại sao RC4 không an toàn
   - Tìm hiểu về các cuộc tấn công RC4

---

## 🎯 Quy trình hoàn chỉnh

```bash
# 1. Tạo folder build
mkdir build

# 2. Biên dịch mã hoá
gcc -o build/encrypt encrypt/encryption.c

# 3. Chạy mã hoá
.\build\encryption.exe

# 4. Copy ciphertext từ output

# 5. Cập nhật decrypt/decryption.c

# 6. Biên dịch giải mã
gcc -o build/decrypt decrypt/decryption.c

# 7. Chạy giải mã
.\build\decryption.exe

# 8. Kiểm tra plaintext
```

---

## 📚 Tài liệu tham khảo

- **Wikipedia RC4:** https://en.wikipedia.org/wiki/RC4
- **RFC 6234:** Streaming ciphers
- **Các lỗ hổng RC4:** KVA attacks, WEP cracking

---

## 💡 Mẹo sử dụng

✅ **Sử dụng VS Code** - Có terminal tích hợp  
✅ **Sử dụng PowerShell** - Dễ dùng hơn CMD  
✅ **Tạo folder build** - Để file .exe gọn gàng  
✅ **Kiểm tra kỹ** - Mỗi byte phải chính xác  

---

**Chúc bạn học tập vui vẻ!** 🚀
