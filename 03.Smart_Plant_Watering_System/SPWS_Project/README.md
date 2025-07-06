# 🌱 Smart Plant Watering System (SPWS)

## 📌 Giới thiệu
Hệ thống tưới cây tự động thông minh mô phỏng hoạt động trên vi điều khiển.
Quản lý bơm nước, LED trạng thái, cảm biến độ ẩm và nhiệt độ, cùng 2 nút nhấn điều khiển.

---

## ⚙️ Tính năng chính
- Đọc cảm biến độ ẩm đất và nhiệt độ môi trường.
- Điều khiển bơm nước tự động dựa trên ngưỡng cấu hình.
- Tưới thủ công khi người dùng nhấn nút (ở chế độ MANUAL).
- LED báo trạng thái (bình thường, đang tưới, cảnh báo).
- Chuyển đổi giữa **MODE_AUTO** và **MODE_MANUAL**.
- In thông báo mô phỏng trạng thái ra console.

---

## 🧩 Thành phần chính
- **Vi điều khiển** (mô phỏng): Quản lý toàn bộ hoạt động.
- **Cảm biến**:
  - Độ ẩm đất (0–100%)
  - Nhiệt độ môi trường
- **Bơm nước mini**: BẬT/TẮT tưới cây.
- **LED RGB hoặc 3 LED đơn sắc**: Hiển thị trạng thái.
- **2 nút nhấn**:
  - Nút 1: BẬT/TẮT chế độ tự động.
  - Nút 2: Kích hoạt tưới nước thủ công.

---

## 📦 Cấu trúc thư mục
```text
├── Inc/                # File header (.h)
│   ├── Actuators.h
│   ├── Buttons.h
│   ├── Config.h
│   ├── Sensors.h
│   └── Watering_Logic.h
├── Src/                # File cài đặt (.c)
│   ├── Actuators.c
│   ├── Buttons.c
│   ├── Sensors.c
│   └── Watering_Logic.c
├── main.c              # Hàm main, vòng lặp chính
├── Makefile            # Script build dự án
└── README.md           # Tài liệu mô tả dự án

🔧 Build & chạy
bash
Copy
Edit
make           # Biên dịch dự án
./SPWS         # Chạy mô phỏng
make clean     # Xoá file build
Output:

![image](https://github.com/user-attachments/assets/751d146c-5d0e-4d5d-a070-9f6f6e76bbb0)
