// Một người gửi ngân hàng với lãi suất tính theo kỳ hạn (1,3,6,12,24,36 tháng) là r%/năm.
// Hỏi người đó cần gửi ít nhất bao nhiêu tháng để thu được số tiền gấp đôi số tiền gửi ban đầu.


// INPUT
// 6 3.2

// OUTPUT
// 264


#include <stdio.h>
#include <math.h>

int main(void) {
    int T;          
    double r;       
    if (scanf("%d %lf", &T, &r) != 2) return 0;

    double factor = 1.0 + (r/100.0) * (T/12.0);
    if (factor <= 1.0) { printf("0\n"); return 0; } // khong tang

    long long k = (long long)ceil(log(2.0) / log(factor));
    long long months = k * T;
    printf("%lld\n", months);
    return 0;
}
