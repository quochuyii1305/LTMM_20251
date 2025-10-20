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
RC4-Project/
│
├── Encryption Project/
│   ├── rc4_encrypt.h          # Header chứa thuật toán mã hoá
│   └── main_encrypt.c         # Chương trình chính mã hoá
│
├── Decryption Project/
│   ├── rc4_decrypt.h          # Header chứa thuật toán giải mã
│   └── main_decrypt.c         # Chương trình chính giải mã
│
└── README.md                   # File này
```

---

## 🛠️ Hướng dẫn biên dịch

### **Yêu cầu:**
- GCC compiler (hoặc Clang, MSVC)
- Terminal/Command Prompt

### **Project 1: Mã hoá**

```bash
gcc -o encrypt main_encrypt.c
```

### **Project 2: Giải mã**

```bash
gcc -o decrypt main_decrypt.c
```

### **Biên dịch trên các hệ điều hành:**

#### Linux/macOS:
```bash
gcc -o encrypt main_encrypt.c
./encrypt
```

#### Windows (CMD):
```bash
gcc -o encrypt.exe main_encrypt.c
encrypt.exe
```

#### Windows (PowerShell):
```powershell
gcc -o encrypt.exe main_encrypt.c
.\encrypt.exe
```

---

## 🚀 Hướng dẫn chạy

### **Bước 1: Vào thư mục Encryption**

Mở Terminal tại thư mục chứa `main_encrypt.c`

#### Cách mở Terminal tại thư mục (Windows):
- Shift + Right Click → "Open PowerShell here"
- hoặc Shift + Right Click → "Open Command Window here"

#### Linux/macOS:
```bash
cd /đường/dẫn/đến/Encryption
```

### **Bước 2: Biên dịch chương trình mã hoá**

```bash
gcc -o encrypt main_encrypt.c
```

### **Bước 3: Chạy chương trình**

```bash
./encrypt        # Linux/macOS
.\encrypt.exe    # Windows PowerShell
encrypt.exe      # Windows CMD
```

**Kết quả mong đợi:**
```
========== RC4 ENCRYPTION PROJECT (Text Key) ==========

Plaintext:  Hanoi University of Science and Technology
Plaintext Length: 43
Key (Text): SecretKey123
Key Length: 12

Key (HEX): 53 65 63 72 65 74 4B 65 79 31 32 33

Ciphertext (HEX): 8C 07 8C D2 E4 A3 CA A0 E7 11 E8 BC 53 95 FA 68 50 B8 86 91 9D 1A AA 70 06 2C EE 30 DA 59 B4 88 D7 BF 95 CC FE 47 2C EA 67 0F

Ciphertext (ASCII): ....d.....S.......

Mã hoá thành công!
```

### **Bước 4: Copy ciphertext**

Lấy dòng HEX từ output:
```
8C 07 8C D2 E4 A3 CA A0 E7 11 E8 BC 53 95 FA 68 50 B8 86 91 9D 1A AA 70 06 2C EE 30 DA 59 B4 88 D7 BF 95 CC FE 47 2C EA 67 0F
```

### **Bước 5: Cập nhật ciphertext trong main_decrypt.c**

Mở file `main_decrypt.c` và tìm:
```c
uint8_t ciphertext[] = {
    0x8C, 0x07, 0x8C, 0xD2, ...
};
```

Thay thế bằng ciphertext vừa tạo (có dạng: `0x8C, 0x07, 0x8C, ...`)

### **Bước 6: Biên dịch và chạy giải mã**

```bash
gcc -o decrypt main_decrypt.c
./decrypt        # Linux/macOS
.\decrypt.exe    # Windows PowerShell
decrypt.exe      # Windows CMD
```

**Kết quả mong đợi:**
```
========== RC4 DECRYPTION PROJECT (Text Key) ==========

Ciphertext (HEX): 8C 07 8C D2 E4 A3 CA A0 E7 11 E8 BC 53 95 FA 68 50 B8 86 91 9D 1A AA 70 06 2C EE 30 DA 59 B4 88 D7 BF 95 CC FE 47 2C EA 67 0F

Ciphertext Length: 43
Key (Text): SecretKey123
Key Length: 12

Key (HEX): 53 65 63 72 65 74 4B 65 79 31 32 33

Plaintext: Hanoi University of Science and Technology

Giải mã thành công!
```

---

## 🧪 Test Vector

### **Test Vector 1: Tài liệu chính (Text Key)**

| Thành phần | Giá trị |
|-----------|--------|
| **Plaintext** | `Hanoi University of Science and Technology` |
| **Key** | `SecretKey123` |
| **Plaintext Length** | 43 bytes |
| **Key Length** | 12 bytes |

**Key (HEX):**
```
53 65 63 72 65 74 4B 65 79 31 32 33
S  e  c  r  e  t  K  e  y  1  2  3
```

**Expected Ciphertext (HEX):**
```
8C 07 8C D2 E4 A3 CA A0 E7 11 E8 BC 53 95 FA 68 
50 B8 86 91 9D 1A AA 70 06 2C EE 30 DA 59 B4 88 
D7 BF 95 CC FE 47 2C EA 67 0F
```

---

### **Test Vector 2: Số Key**

| Thành phần | Giá trị |
|-----------|--------|
| **Plaintext** | `Hello World` |
| **Key (Array)** | `[0x01, 0x02, 0x03, 0x06]` |
| **Plaintext Length** | 11 bytes |
| **Key Length** | 4 bytes |

**Key (HEX):**
```
01 02 03 06
```

**Cách chạy:**

Sửa `main_encrypt.c`:
```c
char plaintext[] = "Hello World";
int plaintext_len = strlen(plaintext);

uint8_t key[] = {0x01, 0x02, 0x03, 0x06};
int keylen = sizeof(key);

// Comment out phần key_text
```

---

### **Test Vector 3: Key đơn giản**

| Thành phần | Giá trị |
|-----------|--------|
| **Plaintext** | `RC4` |
| **Key** | `Key` |
| **Plaintext Length** | 3 bytes |
| **Key Length** | 3 bytes |

**Key (HEX):**
```
4B 65 79
K  e  y
```

---

### **Test Vector 4: Dữ liệu nhị phân**

| Thành phần | Giá trị |
|-----------|--------|
| **Plaintext** | `12345` |
| **Key** | `Secret` |
| **Plaintext Length** | 5 bytes |
| **Key Length** | 6 bytes |

**Key (HEX):**
```
53 65 63 72 65 74
S  e  c  r  e  t
```

---

## ✅ Kết quả mong đợi

### **Tiêu chí kiểm tra:**

1. ✅ **Mã hoá thành công:**
   - Plaintext được chuyển thành Ciphertext (HEX)
   - Ciphertext có độ dài = Plaintext
   - Giá trị HEX nằm trong khoảng 00-FF

2. ✅ **Giải mã thành công:**
   - Ciphertext được giải mã trở lại Plaintext ban đầu
   - Plaintext khớp 100% với input

3. ✅ **Xác minh:**
   ```
   Plaintext → (Encrypt) → Ciphertext → (Decrypt) → Plaintext
   ```

### **Ví dụ kiểm tra:**

```bash
# Chạy mã hoá
./encrypt
# Output: Ciphertext (HEX) = 8C 07 8C D2 ...

# Copy vào main_decrypt.c

# Chạy giải mã
./decrypt
# Output: Plaintext = "Hanoi University of Science and Technology"
```

---

## 🔍 Lưu ý khi chạy

### **Lỗi thường gặp:**

#### 1. Lỗi: `gcc: command not found`
**Giải pháp:** Cài đặt GCC
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
brew install gcc

# Windows
Tải từ MinGW hoặc use WSL
```

#### 2. Lỗi: `undefined reference to main`
**Giải pháp:** Đảm bảo file `.c` có hàm `main()`

#### 3. Ciphertext không khớp
**Giải pháp:**
- Kiểm tra plaintext (có space, ký tự đặc biệt?)
- Kiểm tra key (phải giống nhau)
- Kiểm tra độ dài plaintext

#### 4. Giải mã ra rác
**Giải pháp:**
- Ciphertext phải giống 100%
- Key phải giống nhau
- Kiểm tra lại HEX copy

---

## 📝 Chỉnh sửa Test Vector

### **Để thử plaintext khác:**

**main_encrypt.c:**
```c
char plaintext[] = "Your text here";
char key_text[] = "YourKeyHere";
```

**main_decrypt.c:**
- Chỉ cần update `ciphertext[]`
- `key_text[]` phải giống `main_encrypt.c`

---

## 🎓 Cách học từ project này

1. **Hiểu thuật toán RC4:**
   - Đọc các file `.h` (header)
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
# 1. Vào thư mục Encryption
cd Encryption

# 2. Biên dịch mã hoá
gcc -o encrypt main_encrypt.c

# 3. Chạy mã hoá
./encrypt

# 4. Copy ciphertext từ output

# 5. Vào thư mục Decryption
cd ../Decryption

# 6. Cập nhật ciphertext trong main_decrypt.c

# 7. Biên dịch giải mã
gcc -o decrypt main_decrypt.c

# 8. Chạy giải mã
./decrypt

# 9. Kiểm tra plaintext có giống không
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
✅ **Lưu output** - Có thể copy paste dễ hơn  
✅ **Kiểm tra kỹ** - Mỗi byte phải chính xác  

---

**Chúc bạn học tập vui vẻ!** 🚀
