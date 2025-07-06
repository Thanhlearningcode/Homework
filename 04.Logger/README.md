# 📌 Bài tập Logger trong C

Đây là một module logger nhỏ gọn được viết bằng ngôn ngữ C, phục vụ mục đích ghi log trong các dự án nhúng hoặc ứng dụng nhỏ.

**Tính năng chính:**
- Ghi log ra console và/hoặc file văn bản.
- Hỗ trợ 8 mức độ log theo chuẩn syslog (EMERGENCY, ALERT, CRITICAL, ERROR, WARNING, NOTICE, INFO, DEBUG).
- Tự động thêm thông tin thời gian, tên file và số dòng vào mỗi thông điệp log.
- Lọc thông điệp dựa trên mức độ log cấu hình sẵn.
- Sử dụng macro tiện lợi `log_message(...)` để dễ dàng ghi log mà không cần tự truyền `__FILE__` và `__LINE__`.

**Mục đích:**  
Giúp sinh viên hiểu cách xây dựng một module logger hoàn chỉnh, có thể tái sử dụng, dễ bảo trì và phù hợp với các dự án C thực tế.

---

✅ *Dễ tích hợp – Dễ sử dụng – Phù hợp cho cả ứng dụng nhúng và ứng dụng desktop.*
