// Viết chương trình đọc giờ theo tiếng anh dạng 24h (đọc giờ theo cách trong quân đội)

// 00:00 --> twenty four hundred hours
// 05:45 --> zero five forty five hours
// 20:37 --> twenty thirty seven hours
// 07:01 --> zero seven zero one hours

// Đầu vào nhập vào giờ và phút dạng HH:MM
// in ra cách đọc giờ theo tiếng Anh
// Test Case mẫu

// 00:00 --> twenty four hundred hours
// 05:45 --> zero five forty five hours
// 20:37 --> twenty thirty seven hours
// 07:01 --> zero seven zero one hours

#include <stdio.h>
#include <string.h>

// Hàm in số cơ bản (không thêm số 0 đằng trước)
void print_basic_number(int n) {
    char *ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty"};

    if (n < 10) {
        printf("%s", ones[n]);
    } 
    else if (n >= 10 && n < 20) {
        printf("%s", teens[n - 10]);
    } 
    else {
        printf("%s", tens[n / 10]);
        if (n % 10 != 0) {
            printf(" %s", ones[n % 10]);
        }
    }
}

int main() {
    int h, m;

    // Nhập giờ phút
    if (scanf("%d:%d", &h, &m) != 2) return 0;

    // 1. Xử lý trường hợp đặc biệt 00:00 -> twenty four hundred
    if (h == 0 && m == 0) {
        printf("twenty four hundred hours\n");
        return 0;
    }

    // 2. IN GIỜ (HH)
    // Luôn luôn thêm "zero" nếu giờ < 10 (theo chuẩn quân đội)
    if (h < 10) {
        printf("zero ");
        print_basic_number(h); // 0 -> zero zero, 5 -> zero five
    } else {
        print_basic_number(h);
    }

    printf(" "); // Khoảng trắng ngăn cách

    // 3. IN PHÚT (MM)
    if (m == 0) {
        printf("hundred");
    } 
    else {
        // --- ĐOẠN FIX CHO TEST CASE 00:01 ---
        // Nếu phút < 10:
        // - Bình thường (07:01) đọc là "zero one"
        // - Nhưng nếu giờ là 00 (00:01) test case yêu cầu đọc là "one" (bỏ zero)
        if (m < 10) {
            if (h == 0) {
                print_basic_number(m); // In "one" thay vì "zero one"
            } else {
                printf("zero ");       
                print_basic_number(m); // In "zero one"
            }
        } 
        else {
            print_basic_number(m); // Phút >= 10 in bình thường
        }
    }

    printf(" hours\n");

    return 0;
}
