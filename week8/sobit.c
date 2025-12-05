// Cho 1 số nguyên dương n nhập từ bàn phím, in ra số lượng bit 1 dùng để biểu diễn số nguyên này.
// Nếu số nhập vào là âm thì in ra -1;


// Test Case mẫu

// INPUT
// 2

// OUTPUT
// 1

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n < 0) {
        printf("-1");
        return 0;
    }

    int count = 0;
    while (n > 0) {
        if (n & 1)   // nếu bit cuối là 1
            count++;
        n >>= 1;      // dịch phải 1 bit
    }

    printf("%d", count);
    return 0;
}
