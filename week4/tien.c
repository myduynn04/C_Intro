// Một sàn giao dịch niêm yết tỉ giá giữa BTC/USDT và USDT/VND như sau
// BTC/USDT = 89450.4565
// USDT/VND = 26045

// Phí giao dịch qua sàn là 0.1% cho mỗi giao dịch.

// Giả sử bạn có tiền VND và muốn mua BTC, bạn cần 2 bước chuyển đổi là từ VND --> USDT và từ USDT --> BTC
// Nếu bạn có 10000000 VND khi đổi ra USDT theo tỉ lệ trên bạn sẽ thu được 383.95085429 USDT (lấy tới 8 chữ số), trừ đi 0.1% phí giao dịch bạn thực nhận 383.56690343
// với số lượng USDT trên khi đổi ra BTC sẽ là 0.00428803, trừ phí giao dịch bạn sẽ thực nhận 0.00428374 BTC


// Hãy viết chương trình nhập vào 
// + tỉ giá BTC/USDT và USDT/VND
// + Số tiền bạn định mua BTC theo VND 

// In ra số lượng BTC bạn sẽ nhận được.

// Các kết quả chỉ lấy đến 8 chữ số thập phân và KHÔNG làm tròn
// Test Case mẫu

// INPUT
// 89450.4565 26045 10000000
// OUTPUT
// 0.00428374


// INPUT
// 82450.65 25945 10000000
// OUTPUT
// 0.00466532




#include <stdio.h>

double cut8(double n) {
    return (double)((long long)(n * 100000000.0)) / 100000000.0;
}

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double x = cut8(c / b);
    x = cut8(x * 0.999);
    x = cut8(x / a);
    x = cut8(x * 0.999);

    printf("%.8lf\n", x);
    return 0;
}