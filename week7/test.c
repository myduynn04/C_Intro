#include <stdio.h>
#define MONTHS 12

float calculateInterest(int principal, float rate) {
    return (int)(principal * rate / 100);
}

double accumulateSavings(int principal, float rate) {
    double total = principal;
    for (int i = 0; i < MONTHS; ++i) {
        float interest = calculateInterest(total, rate);
        total += interest;
    }
    return total;
}

int main() {
    int principal = 100000;  // 100k VNĐ
    float rate = 0.8f;         // 0.8% mỗi tháng
    
    double result = accumulateSavings(principal, rate);
    printf("Tổng tiền sau 12 tháng: %.2f\n", result);
    return 0;
}