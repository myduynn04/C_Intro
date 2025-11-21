/*
Một người sử dụng thiết bị đeo tay thông minh có GPS để theo dõi hành trình của mình khi chạy bộ bên ngoài.
Thiết bị đeo tay sẽ ghi lại tọa độ của người đó theo kinh độ và vĩ độ cứ sau 1 khoảng thời gian.
Dựa vào log đó hãy tĩnh tổng quãng đường mà người đó đã chạy được.

Đầu vào là danh sách các tọa độ long:lat dạng 
long1:lat1 long2:lat2 .. longn:latn -1

Mỗi một giá trị sẽ có 2 giá trị là long:lat là kinh độ và vĩ độ.
Cuối danh sách sẽ là giá trị -1

Quãng đường di chuyển được sẽ được tính bằng tổng quãng đường giữa 2 thời điểm liên tiếp.

Khoảng cách giữa 2 điểm trên trái đất tính theo kinh độ và vĩ độ sử dụng công thức haversine (theo km).
Kết quả in ra tổng quãng đường tính theo m, lấy đến 2 chữ số thập phân.
Test Case mẫu

INPUT
21.00749193345454:105.84215723372469 21.007531996362417:105.84297262524909 21.007652185021474:105.84376655910181 21.00749193345454:105.84387384746027 -1

OUTPUT
191.92m*/


#include <stdio.h>
#include <math.h>


#define EARTH_RADIUS 6371.0 // Bán kính trái đất trong km

// Hàm tính khoảng cách giữa hai điểm dựa trên kinh độ và vĩ độ
// Khoảng cách trả về tính theo km
double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    // Chuyển đổi độ sang radian
    double lat1_rad = lat1 * M_PI / 180.0;
    double lon1_rad = lon1 * M_PI / 180.0;
    double lat2_rad = lat2 * M_PI / 180.0;
    double lon2_rad = lon2 * M_PI / 180.0;

    // Tính sai số giữa các tọa độ
    double delta_lat = lat2_rad - lat1_rad;
    double delta_lon = lon2_rad - lon1_rad;

    // Áp dụng công thức haversine
    double a = pow(sin(delta_lat / 2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(delta_lon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    // Tính khoảng cách
    double distance = EARTH_RADIUS * c;

    return distance;
}

int main(){
    double total_distance_km = 0.0;
    double prev_lat, prev_lon;
    int first_point = 1;

    while (1) {
        double lon, lat;

        if (scanf("%lf:%lf", &lon, &lat) != 2) break;
        if (lon == -1 && lat == -1) break;

        if (!first_point) {
            double distance = haversineDistance(prev_lat, prev_lon, lat, lon);
            total_distance_km += distance;
        } else {
            first_point = 0;
        }

        prev_lat = lat;
        prev_lon = lon;
    }

    printf("%.2fm\n", total_distance_km * 1000.0);

    return 0;
}

