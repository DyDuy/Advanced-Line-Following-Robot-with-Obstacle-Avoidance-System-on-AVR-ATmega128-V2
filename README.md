# Advanced Line Following Robot with Obstacle Avoidance System on AVR ATmega128 V2

## 🧠 Giới thiệu

Dự án này là một hệ thống robot dò line nâng cao tích hợp khả năng tránh vật cản, sử dụng vi điều khiển **AVR ATmega128**. Robot hoạt động hoàn toàn dựa vào các thuật toán điều khiển logic thay vì PID, phù hợp cho các ứng dụng giáo dục, nghiên cứu, và phát triển hệ thống nhúng cơ bản.

---

## ⚙️ Thông số kỹ thuật

- **Vi điều khiển chính**: ATmega128
- **Số lượng cảm biến dò line**: 3 (Hồng ngoại – trái, giữa, phải)
- **Cảm biến tránh vật cản**: HC-SR04 (Siêu âm)
- **Driver động cơ**: L298N
- **Ngôn ngữ lập trình**: C (AVR-GCC)
- **Nguồn cấp**: Pin 7.4V – 12V hoặc cấp từ adapter

---

## 📦 Phần cứng sử dụng

| Thiết bị | Số lượng | Ghi chú |
|---------|----------|--------|
| ATmega128 | 1 | Vi điều khiển chính |
| Cảm biến hồng ngoại | 3 | Dò line (trái – giữa – phải) |
| Cảm biến siêu âm HC-SR04 | 1 | Phát hiện và tránh vật cản |
| L298N Driver | 1 | Điều khiển 2 động cơ DC |
| Động cơ DC | 2 | Gắn với bánh xe |
| Bánh xe robot | 2 | Gắn với động cơ |
| Nguồn 7.4V–12V | 1 | Có thể dùng pin Li-ion |
| Buzzer | 1 | Cảnh báo vật cản (nếu muốn) |

---

## 🧭 Nguyên lý hoạt động

### 1. **Dò line bằng 3 cảm biến hồng ngoại**
- Cảm biến giữa phát hiện line màu đen.
- Nếu cảm biến giữa nhận line → robot đi thẳng.
- Nếu cảm biến trái nhận line → robot rẽ trái.
- Nếu cảm biến phải nhận line → robot rẽ phải.
- Nếu cả 3 cảm biến không nhận line → dừng lại hoặc quay đầu (tùy cấu hình mở rộng).

### 2. **Tránh vật cản bằng cảm biến siêu âm**
- Khoảng cách được đo bằng HC-SR04.
- Nếu phát hiện vật cản trong khoảng cách < 15cm → dừng lại, quay phải (hoặc trái) và tiếp tục dò line.
- Không dùng thuật toán PID → chỉ dùng các ngưỡng cố định và logic điều khiển tuyến tính.

---

## 💡 Điểm nổi bật
- Không sử dụng PID → dễ hiểu và phù hợp với người mới học.
- Phân chia chức năng rõ ràng: dò line và tránh vật cản hoạt động độc lập nhưng phối hợp.
- Điều khiển động cơ trực tiếp thông qua L298N và các chân điều khiển logic của vi điều khiển.

---

## 🛠️ Cấu trúc thư mục

