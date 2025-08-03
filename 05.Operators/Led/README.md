# 🟩 Addressable RGB LED Strip Driver (WS2812B / NeoPixel)

Bài tập mô phỏng cách điều khiển dải đèn LED RGB địa chỉ hóa như **WS2812B (NeoPixel)** bằng phần mềm.  
Vi điều khiển không gửi tín hiệu analog riêng biệt mà chỉ cần truyền **luồng dữ liệu số (digital data stream)**, mỗi LED "nhận" phần dữ liệu của mình và chuyển tiếp phần còn lại.

---

## 🛠 Chức năng chính
- Quản lý buffer chứa dữ liệu màu của toàn bộ dải LED.
- Thao tác bit để đóng gói màu (Green, Red, Blue) vào đúng định dạng 24-bit (GRB).
- Tiện ích:
  - Đặt màu cho từng pixel (`led_set_pixel_color`)
  - Tô màu toàn bộ dải (`led_fill`)
  - Tắt tất cả pixel (`led_clear`)
- Quản lý bộ nhớ:
  - Khởi tạo (`led_init`)
  - Giải phóng (`led_shutdown`)

---



---

## ✅ Kiểm thử
- Khởi tạo dải LED với 10 pixel.
- Đặt màu cho pixel đầu, cuối và giữa.
- In buffer để kiểm tra giá trị hexa đúng định dạng.
- Dùng `led_fill` tô toàn bộ dải LED với màu xanh lá.
- Giải phóng bộ nhớ.

---
## ⚙️ Build & chạy
```bash
make
./LED
make clean
```

## Result:

![image](https://github.com/user-attachments/assets/ce3a6f79-257e-4f7b-8e21-7da5dd277547)



