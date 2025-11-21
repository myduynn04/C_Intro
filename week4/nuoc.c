// Lượng mưa là chiều dày của lớp nước mưa rơi xuống tại một địa điểm nào đó. Nếu trong chương trình dự báo thời tiết, người ta thông báo "đo được lượng mưa khoảng 300mm", thì điều đó có nghĩa, đường sẽ ngập khoảng 300mm nước sau cơn mưa nếu đất không ngấm nước. Tuy nhiên trong thực tế, đất sẽ ngấm nước và lượng nước đó lại chảy ra các sông, suối… nên chúng ta sẽ không thể cảm nhận trực tiếp được lượng nước mưa.

// Với một cơn mưa có lượng mưa 200mm và cái sân 100m2 sẽ thu được 20m3 nước. 

// Tổ chức Khí tượng thế giới (WMO) quy định lượng nước mưa lớn hay nhỏ căn cứ theo số liệu dưới đây.

// Mưa vừa: Từ 16 đến 50mm/24h, hoặc 8 đến 25mm/12h
// Mưa to: Từ 51 đến 100mm/24h, hoặc 26 đến 50mm/12h
// Mưa rất to: > 100mm/24h, hoặc > 50mm/12h

// Giả sử trong cơn mưa có lượng nước trung bình đo được là a mm/24h, và mái nhà của bạn có diện tích là x m2. thời gian mưa là y h.
// Hỏi lượng nước mưa thu được từ mái nhà là bao nhiêu m3 (kết quả in ra lấy tới 4 chữ số thập phân)
// Test Case mẫu

// INPUT
// 32 35 3.2
// OUTPUT
// 0.1493 m3

#include <stdio.h>

int main() {
    // Khai báo các biến kiểu double để xử lý số thực
    double avg_rain_rate; // Lượng mưa trung bình (a mm/24h)
    double roof_area;     // Diện tích mái nhà (x m2)
    double rain_duration; // Thời gian mưa (y h)

    // Đọc 3 giá trị đầu vào từ người dùng
    scanf("%lf %lf %lf", &avg_rain_rate, &roof_area, &rain_duration);

    // Bước 1: Tính tổng lượng mưa (chiều cao lớp nước) trong suốt thời gian mưa
    // Lượng mưa mỗi giờ = a / 24 (mm/h)
    // Tổng lượng mưa = (a / 24) * y (mm)
    double total_rain_height_mm = (avg_rain_rate / 24.0) * rain_duration;

    // Bước 2: Đổi đơn vị của tổng lượng mưa từ milimét (mm) sang mét (m)
    // 1 mét = 1000 mm
    double total_rain_height_m = total_rain_height_mm / 1000.0;

    // Bước 3: Tính thể tích nước thu được
    // Thể tích (m3) = Diện tích (m2) * Chiều cao (m)
    double water_volume_m3 = roof_area * total_rain_height_m;

    // In kết quả ra màn hình, định dạng lấy 4 chữ số thập phân
    printf("%.4f m3\n", water_volume_m3);

    return 0;
}