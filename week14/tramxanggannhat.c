// Đầu vào là danh sách n trạm xăng với thông tin gồm
// + địa chỉ cửa hàng
// + tọa độ (theo kinh độ và vĩ độ)
// Hãy xây dựng chương trình nhập vào vị trí hiện tại của người dùng và ước tính khoảng cách tối đa mà người đó còn có thể di chuyển bằng o tô.
// Hãy đưa ra danh sách 3 cửa hàng gần nhất với vị trí hiện tại (tính theo khoảng cách trực tiếp).
// Trong trường hợp không có thì in ra -1
// Đầu vào gồm n là số cửa hàng trong danh sách
// các dòng tiếp theo là thông tin cửa hàng, trong đó
// + dòng thứ nhất là tên cửa hàng
// + dòng tiếp là địa chỉ cửa hàng
// + dòng tiếp là kinh độ và vĩ độ cách nhau bởi dấu ','
// Truy vấn về địa chỉ sẽ bắt đầu bằng dấu hỏi ?loc
// tiếp đến là kinh độ và vĩ độ , sau đó là quãng đường tối đa còn đi được tính theo km
// ?loc 21.01139779286402, 105.83112897045073 2.5
// Đầu ra in ra danh sách các cửa hàng gần nhất và khoảng cách (lấy đến 4 chữ số thập phân)


// INPUT
// 10
// Cua hang xang dau so 01
// So 01 duong Tran Quang Khai, phuong Trang Tien, quan Hoan Kiem, thanh pho Ha Noi.
// 21.027029053665203, 105.85788283796315
// Cua hang xang dau so 04
// So 09 pho Tran Hung Dao, phuong Phan Chu Trinh, quan Hoan Kiem, thanh pho Ha Noi.
// 21.019264464568003, 105.85792493796282
// Cua hang xang dau so 05
// So 01 pho Hang Bun, phuong Nguyen Trung Truc, quan Ba Dinh, thanh pho Ha Noi.
// 21.044682858579506, 105.8459573956352
// Cua hang xang dau so 18
// So 625 duong De La Thanh, phuong Thanh Cong, quan Ba Dinh, thanh pho Ha Noi.
// 21.023958129304855, 105.81538145330641
// Cua hang xang dau so 19
// So 01 pho Thanh Cong, phuong Thanh Cong, quan Ba Dinh, thanh pho Ha Noi.
// 21.021572717236847, 105.81567626679875
// Cua hang xang dau so 14
// So 276 duong Thuy Khue, phuong Thuy Khue, quan Tay Ho, thanh pho Ha Noi.
// 21.046369473033028, 105.81551255822745
// Cua hang xang dau so 06
// So nha 838 duong Bach Dang, phuong Thanh Luong, quan Hai Ba Trung, thanh pho Ha Noi.
// 21.004436495134794, 105.87344921097747
// Cua hang xang dau so 50
// So 01 pho Luong Yen, phuong Bach Dang, quan Hai Ba Trung, thanh pho Ha Noi.
// 21.013083187825714, 105.86312023796269
// Cua hang xang dau so 51
// So 484 pho Minh Khai, phuong Vinh Tuy, quan Hai Ba Trung, thanh pho Ha Noi.
// 20.99867378885691, 105.8685730514546
// Cua hang xang dau so 30
// So 185 pho Nguyen Luong Bang, phuong Quang Trung, quan Dong Da, thanh pho Ha Noi.
// 21.013581148493703, 105.826891080291
// ?loc 21.01139779286402, 105.83112897045073 2.5

// OUTPUT
// 0.4759
// Cua hang xang dau so 30
// So 185 pho Nguyen Luong Bang, phuong Quang Trung, quan Dong Da, thanh pho Ha Noi.
// 1.7457
// Cua hang xang dau so 19
// So 01 pho Thanh Cong, phuong Thanh Cong, quan Ba Dinh, thanh pho Ha Noi.
// 1.7920
// Cua hang xang dau so 18
// So 625 duong De La Thanh, phuong Thanh Cong, quan Ba Dinh, thanh pho Ha Noi.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Định nghĩa cấu trúc lưu trữ thông tin trạm xăng
typedef struct {
    char name[256];
    char address[256];
    double lat;
    double lon;
    double distance; // Biến tạm để lưu khoảng cách tính được
} Station;

// Hàm chuyển đổi độ sang radian
double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// Hàm tính khoảng cách Haversine (trả về km)
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371.0; // Bán kính Trái Đất (km)

    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);

    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

// Hàm so sánh dùng cho qsort
int compareStations(const void *a, const void *b) {
    Station *stationA = (Station *)a;
    Station *stationB = (Station *)b;

    if (stationA->distance < stationB->distance) return -1;
    if (stationA->distance > stationB->distance) return 1;
    return 0;
}

// Hàm xóa ký tự xuống dòng (\n) thừa khi dùng fgets
void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int n;
    
    // Đọc số lượng cửa hàng
    if (scanf("%d", &n) != 1) return 0;
    
    // Tiêu thụ ký tự xuống dòng sau khi nhập số n
    char tempBuffer[100];
    fgets(tempBuffer, sizeof(tempBuffer), stdin); 

    // Cấp phát bộ nhớ động cho danh sách trạm
    Station *stations = (Station *)malloc(n * sizeof(Station));
    if (stations == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Nhập thông tin từng trạm
    for (int i = 0; i < n; i++) {
        // Đọc tên
        if (fgets(stations[i].name, sizeof(stations[i].name), stdin) == NULL) break;
        trimNewline(stations[i].name);

        // Đọc địa chỉ
        if (fgets(stations[i].address, sizeof(stations[i].address), stdin) == NULL) break;
        trimNewline(stations[i].address);

        // Đọc tọa độ
        // Lưu ý: scanf chỉ đọc đến khoảng trắng/xuống dòng, nên phải xử lý cẩn thận
        char coordsLine[100];
        if (fgets(coordsLine, sizeof(coordsLine), stdin) == NULL) break;
        
        // Parse tọa độ từ chuỗi, xử lý dấu phẩy
        // Format trong đề: "lat, lon" nhưng thực tế có thể là "lon, lat"
        // Thử đọc và kiểm tra - dựa vào expected output, có vẻ là "lat, lon" nhưng tính toán thì dùng "lon, lat"
        char *commaPos = strchr(coordsLine, ',');
        if (commaPos != NULL) {
            *commaPos = ' '; // Thay dấu phẩy bằng dấu cách để dùng sscanf dễ hơn
        }
        // Đọc theo thứ tự lat, lon nhưng lưu vào lon, lat (đảo ngược)
        double temp1, temp2;
        sscanf(coordsLine, "%lf %lf", &temp1, &temp2);
        stations[i].lon = temp1;  // Đảo ngược
        stations[i].lat = temp2;
    }

    // Đọc dòng truy vấn ?loc
    char queryLine[256];
    if (fgets(queryLine, sizeof(queryLine), stdin) != NULL) {
        if (strncmp(queryLine, "?loc", 4) == 0) {
            double curLat, curLon, maxDist;
            
            // Xử lý chuỗi query: "?loc lat, lon dist"
            char *params = queryLine + 4; // Bỏ qua "?loc"
            
            // Thay dấu phẩy bằng dấu cách
            char *comma = strchr(params, ',');
            if (comma) *comma = ' ';

            // Đọc theo thứ tự lat, lon nhưng lưu vào lon, lat (đảo ngược)
            double temp1, temp2;
            sscanf(params, "%lf %lf %lf", &temp1, &temp2, &maxDist);
            curLon = temp1;  // Đảo ngược
            curLat = temp2;

            // Tính khoảng cách và lọc danh sách hợp lệ
            Station validStations[n]; // Mảng tạm chứa các trạm thỏa mãn
            int validCount = 0;

            for (int i = 0; i < n; i++) {
                double d = calculateDistance(curLat, curLon, stations[i].lat, stations[i].lon);
                if (d <= maxDist) {
                    validStations[validCount] = stations[i];
                    validStations[validCount].distance = d;
                    validCount++;
                }
            }

            // Sắp xếp
            if (validCount == 0) {
                printf("-1\n");
            } else {
                qsort(validStations, validCount, sizeof(Station), compareStations);

                // In ra tối đa 3 kết quả
                int limit = (validCount < 3) ? validCount : 3;
                for (int i = 0; i < limit; i++) {
                    printf("%.4f\n", validStations[i].distance);
                    printf("%s\n", validStations[i].name);
                    printf("%s\n", validStations[i].address);
                }
            }
        }
    }

    // Giải phóng bộ nhớ
    free(stations);
    return 0;
}