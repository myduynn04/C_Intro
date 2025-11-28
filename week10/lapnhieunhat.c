// Nhập vào 1 số nguyên tối đa có thể lên tới 19 chữ số.
// hãy in ra chữ số lớn nhất có tần số lặp lại nhiều nhất trong số đó.
// Test Case mẫu

// INPUT
// 123456654321

// OUTPUT
// 6


#include <stdio.h>
#include <string.h>

int main() {
    char num[21];               // Lưu tối đa 19 chữ số + '\0'
    int freq[10] = {0};         // Tần suất các chữ số 0-9
    int i, len;

    scanf("%20s", num);         // Nhập dưới dạng chuỗi (tránh tràn)

    len = strlen(num);
    for(i = 0; i < len; i++) {
        if(num[i] >= '0' && num[i] <= '9')
            freq[num[i] - '0']++;   // Đếm tần suất
    }

    int max_count = 0, digit = 0;
    for(i = 0; i < 10; i++) {
        if(freq[i] > max_count || (freq[i] == max_count && i > digit)) {
            max_count = freq[i];
            digit = i;
        }
    }

    printf("%d", digit);
    return 0;
}
