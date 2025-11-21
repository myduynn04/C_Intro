// Người dùng kiếm lãi thu động khi để coin trên sàn bằng cách tham gia Earn theo ngày.
// Ví dụ khi người dùng tham gia Earn bằng cách stake 1000 coin của mình với APR cố định là 3.5% (lãi suất theo năm cố định) trong thời gian 12 ngày thì số lượng coin lãi nhận được sẽ là
// 12*1000*((3.5/100)/360) = 1.1666666
// Chú ý. 1 năm tính 360 ngày.
// Hãy viết chương trình nhập vào lần lượt: số lượng coin stake, APR, thời gian stake theo ngày.
// In ra số lượng coin lãi nhận được, lấy tới 8 chữ số thập phân (phần bỏ đi sẽ KHÔNG được làm tròn lên).
// Test Case mẫu

// Ví dụ.

// INPUT
// 1000 3.5 12
// OUTPUT
// 1.1666666

// INPUT
// 100 1.5 120
// OUTPUT
// 0.50000000

// INPUT
// 1502.52 4.26 165
// OUTPUT
// 29.33670300


#include <stdio.h>
#include <math.h>

int main() {
    double k, apr;
    int d;
    scanf("%lf %lf %d", &k, &apr, &d);

    double ur = (double)d * k * ((apr / 100.0) / 360.0);

    double scale = pow(10.0, 8.0);
    double truncated_ur = floor(ur * scale) / scale;
    
    printf("%.8f\n", truncated_ur);
    return 0;
}