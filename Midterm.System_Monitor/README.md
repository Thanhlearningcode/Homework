# 📊 System Monitor - Hệ Thống Giám Sát Cấu Hình Máy Tính Nhúng

## 🧠 Giới thiệu
**System Monitor** là một ứng dụng mô phỏng chức năng giám sát hệ thống trong môi trường máy tính nhúng. Ứng dụng sử dụng kiến trúc **MVC (Model - View - Controller)** để tách biệt rõ ràng giữa thu thập dữ liệu, xử lý logic và hiển thị giao diện.

## 🛠️ Tính năng chính
- Thu thập thông tin cấu hình máy như:
  - CPU usage
  - RAM usage
  - Disk storage
  - Network status (tuỳ chọn mở rộng)
- Hiển thị dashboard đơn giản qua dòng lệnh
- Dễ mở rộng để tích hợp GUI hoặc xuất dữ liệu API

## 🧩 Kiến trúc thư mục

```
Midterm.System_Monitor/
│
├── Inc/                    # Thư mục chứa các file header
│   ├── MVP/               # Các thành phần của mô hình MVC
│   ├── System/            # Định nghĩa dữ liệu hệ thống
│   └── Lib_Log/Inc/       # Logging module (nếu có)
│
├── Src/                   # Thư mục chứa các file triển khai
│   ├── MVP/
│   └── Lib_Log/
│
├── main.c                 # File chạy chính
├── Makefile               # File biên dịch
├── system_monitor         # File thực thi sau khi build
├── README.md              # Tài liệu giới thiệu
└── Documents/             # Báo cáo PDF, tài liệu liên quan
```

## 🚀 Hướng dẫn build

```bash
# Biên dịch chương trình
make

# Chạy chương trình
./system_monitor
```

## ⏱️ Giới hạn hiện tại
- Hiển thị bằng dòng lệnh, chưa có giao diện đồ hoạ
- Chỉ chạy được trên Linux (sử dụng `sysinfo`, `stat`, ...)
- Dữ liệu cập nhật mỗi 7 giây (delay cố định)

## 📌 Công nghệ sử dụng
- Ngôn ngữ: C
- Kiến trúc: MVC
- Công cụ: `make`, `gcc`

## 👨‍💻 Tác giả
- Nguyễn Văn Thành  
- Bách Khoa Đà Nẵng  
- Github: [github.com/thanhnguyen](https://github.com/your_username)

---

📄 _Mọi đóng góp và góp ý đều được chào đón để cải tiến dự án!_