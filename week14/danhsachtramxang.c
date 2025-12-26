// Đưa ra danh sách các trạm xăng trong cùng phường/xã
// Trung bình

// Đề bài
// Đầu vào là danh sách n trạm xăng với thông tin gồm 
// + tên cửa hàng
// + địa chỉ cửa hàng

// Hãy nhập vào 1 tên phường/xã và in ra thông tin (tên và địa chỉ) các cửa hàng trong phường đó
 
// Trong trường hợp không có thì in ra -1  

// Đầu vào gồm n là số cửa hàng trong danh sách
// các dòng tiếp theo là thông tin cửa hàng, trong đó 
// + dòng thứ nhất là tên cửa hàng
// + dòng tiếp là địa chỉ cửa hàng
// Truy vấn về địa chỉ sẽ bắt đầu bằng dấu hỏi ?query
// tiếp đến là tên phường

// ?query Phan Chu Trinh

// Danh sách các cửa hàng nếu có được in theo đúng thứ tự xuất hiện
// Test Case mẫu

// INPUT
// 10
// Cua hang xang dau so 01
// So 01 duong Tran Quang Khai, phuong Trang Tien, quan Hoan Kiem, thanh pho Ha Noi.
// Cua hang xang dau so 04
// So 09 pho Tran Hung Dao, phuong Phan Chu Trinh, quan Hoan Kiem, thanh pho Ha Noi.
// Cua hang xang dau so 05
// So 01 pho Hang Bun, phuong Nguyen Trung Truc, quan Ba Dinh, thanh pho Ha Noi.
// Cua hang xang dau so 18
// So 625 duong De La Thanh, phuong Thanh Cong, quan Ba Dinh, thanh pho Ha Noi.
// Cua hang xang dau so 19
// So 01 pho Thanh Cong, phuong Thanh Cong, quan Ba Dinh, thanh pho Ha Noi.
// Cua hang xang dau so 14
// So 276 duong Thuy Khue, phuong Thuy Khue, quan Tay Ho, thanh pho Ha Noi.
// Cua hang xang dau so 06
// So nha 838 duong Bach Dang, phuong Thanh Luong, quan Hai Ba Trung, thanh pho Ha Noi.
// Cua hang xang dau so 50
// So 01 pho Luong Yen, phuong Bach Dang, quan Hai Ba Trung, thanh pho Ha Noi.
// Cua hang xang dau so 51
// So 484 pho Minh Khai, phuong Vinh Tuy, quan Hai Ba Trung, thanh pho Ha Noi.
// Cua hang xang dau so 30
// So 185 pho Nguyen Luong Bang, phuong Quang Trung, quan Dong Da, thanh pho Ha Noi.
// ?query Phan Chu Trinh

// OUTPUT
// Cua hang xang dau so 04
// So 09 pho Tran Hung Dao, phuong Phan Chu Trinh, quan Hoan Kiem, thanh pho Ha Noi.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1000 // Giả định số lượng trạm tối đa

// Định nghĩa cấu trúc lưu trữ thông tin trạm xăng
typedef struct {
    char name[256];
    char address[512];
} GasStation;

// Hàm xóa ký tự xuống dòng (\n) ở cuối chuỗi do fgets để lại
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int n;
    
    // 1. Nhập số lượng trạm xăng
    if (scanf("%d", &n) != 1) return 0;
    
    // QUAN TRỌNG: Xóa ký tự xuống dòng còn sót lại trong buffer sau khi nhập số n
    // Nếu không có dòng này, lệnh fgets đầu tiên sẽ đọc phải ký tự \n và bị trôi
    while (getchar() != '\n'); 

    // Khai báo mảng chứa các trạm xăng
    GasStation stations[MAX_N];

    // 2. Nhập thông tin từng trạm
    for (int i = 0; i < n; i++) {
        // Nhập tên
        fgets(stations[i].name, sizeof(stations[i].name), stdin);
        remove_newline(stations[i].name);

        // Nhập địa chỉ
        fgets(stations[i].address, sizeof(stations[i].address), stdin);
        remove_newline(stations[i].address);
    }

    // 3. Xử lý truy vấn
    char queryLine[256];
    fgets(queryLine, sizeof(queryLine), stdin);
    remove_newline(queryLine);

    // Tách tên phường từ chuỗi truy vấn "?query Ten Phuong"
    // Cắt bỏ 7 ký tự đầu ("?query ") để lấy phần tên phường
    char *targetWard = queryLine + 7; 

    // 4. Tìm kiếm và in kết quả
    int found = 0; // Cờ đánh dấu xem có tìm thấy hay không
    
    for (int i = 0; i < n; i++) {
        // Hàm strstr kiểm tra xem targetWard có nằm trong address không
        if (strstr(stations[i].address, targetWard) != NULL) {
            printf("%s\n", stations[i].name);
            printf("%s\n", stations[i].address);
            found = 1;
        }
    }

    // Nếu không tìm thấy cửa hàng nào
    if (!found) {
        printf("-1\n");
    }

    return 0;
}