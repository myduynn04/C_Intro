// Khi bạn stake 1 coin bạn sẽ nhận được lãi theo kỳ hạn gửi.
// Ví dụ lãi APR 2.5% (2.5%/năm - 360 ngày) với kỳ hạn 120 ngày.
// Bạn stake 100 coin và muốn được gấp đôi thì 
// Lãi suất 1 kỳ hạn là 0.025 * 120 / 360 = 0.00833333333
// Công thức lãi suất kép khi quay vòng vốn n vòng  (1+rate)^n >= 2, thì n>= 1/log(1+rate)
// số ngày tối thiểu sẽ là ceil(n) * 120 = 84 * 120 = 10080 (cỡ 28 năm).

// Viết chương trình nhập vào
// APR(theo %) và <kỳ hạn(theo ngày)>

// In ra số ngày tối thiểu và số năm tối thiểu cần gửi (làm tròn lên phần nguyên)
// Test Case mẫu


// INPUT
// 2.5 120
// OUTPUT
// 10080 28


// INPUT
// 1.2 30
// OUTPUT
// 20820 58

#include <stdio.h>
#include <math.h>

int main() {
    double apr_percent, term_days;
    scanf("%lf %lf", &apr_percent, &term_days);

    // Tính lãi suất cho một kỳ hạn (rate) - Dùng 360 ngày/năm
    double rate_per_term = (apr_percent / 100.0) * (term_days / 360.0);

    // Tìm số kỳ hạn (n) cần thiết để nhân đôi
    double num_terms = log(2) / log(1.0 + rate_per_term);

    // Tính tổng số ngày tối thiểu
    long long min_days = (long long)ceil(num_terms) * (long long)term_days;

    // Tính số năm tối thiểu - SỬA LỖI Ở ĐÂY: Dùng 360 ngày/năm
    int min_years = (min_days + 360 - 1) / 360;

    printf("%lld %d\n", min_days, min_years);

    return 0;
}