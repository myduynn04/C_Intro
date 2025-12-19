// W11P3 Tìm các thời điểm mà bãi xe quá tải
// Trung bình
// Một bãi xe ô tô có tối đa n vị trí đỗ, tuy nhiên do chưa cài đặt các hệ thống quản lý từng vị trí gửi xe nên chủ bãi xe chỉ có thể quản lý dựa trên lịch sử gửi xe.
// Khi có 1 yêu cầu vào gửi xe, bãi sẽ check còn chỗ trống không, nếu còn thì yêu cầu gửi xe được chấp nhận. Lái xe có thể đỗ ở vị trí còn trống bất kỳ trong bãi. 
// Ngược lại, yêu cầu của lái xe sẽ bị từ chối.

 
// Đầu vào theo format:
// n là số lượng vị trí đỗ tối đa
// m là số lượng vị trí đỗ đã dùng tới thời điểm đầu ngày
// Tiếp đến là k các dòng dạng hh:mm 1/0 trong đó 1 là yêu cầu gửi vào và 0 là lấy xe ra.
// Hãy in ra các khoảng thời gian mà bãi xe đầy và số lượng xe bị từ chối vào trong khoảng thời gian đó.

 
// n m k
// hh1:mm1 1
// hh2:mm2 1
// ..
// Test Case mẫu

// INPUT
// 10 8 6 
// 08:15 1
// 08:25 1
// 08:45 1
// 08:50 1
// 09:10 0
// 09:15 0

// OUTPUT
// 08:45-09:10 2


#include <stdio.h>
#include <string.h>

int main() {
    int n, m, k;
    
    // Đọc n, m, k
    if (scanf("%d %d %d", &n, &m, &k) != 3) {
        return 0;
    }

    int current_cars = m;       // Số xe hiện tại
    int reject_count = 0;       // Số xe bị từ chối trong đợt hiện tại
    char start_time[20];        // Lưu thời điểm bắt đầu quá tải (lần từ chối đầu tiên)
    char time_str[20];          // Biến tạm lưu thời gian của sự kiện
    int type;                   // Loại sự kiện (1: vào, 0: ra)

    for (int i = 0; i < k; i++) {
        scanf("%s %d", time_str, &type);

        if (type == 1) { 
            // --- Xử lý xe VÀO ---
            if (current_cars < n) {
                // Còn chỗ thì cho vào
                current_cars++;
            } else {
                // Hết chỗ -> Bị từ chối
                if (reject_count == 0) {
                    // Nếu đây là xe đầu tiên bị từ chối, đánh dấu thời gian bắt đầu
                    strcpy(start_time, time_str);
                }
                reject_count++;
            }
        } else {
            // --- Xử lý xe RA ---
            // Trước khi cho xe ra, kiểm tra xem có đợt quá tải nào cần kết thúc không
            if (reject_count > 0) {
                // In ra khoảng thời gian và số lượng từ chối
                printf("%s-%s %d\n", start_time, time_str, reject_count);
                
                // Reset lại biến đếm từ chối để chờ đợt sau
                reject_count = 0;
            }

            // Giảm số lượng xe trong bãi
            if (current_cars > 0) {
                current_cars--;
            }
        }
    }

    return 0;
}