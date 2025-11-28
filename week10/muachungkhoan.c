// Một nhà đầu tư chứng khoán muốn test lại thuật toán mua bán chứng khoán của mình theo chiến thuật mua và bán sau T+2 (sau ngày mua 2 ngày). Người này sẽ lấy dữ liệu giá đóng cửa của thị trường trong n ngày liên tiếp của mã chứng khoán đó. Sau đó chạy thuật toán để tìm ra ngày mua và ngày bán (sau T+2) sao cho có lãi cao nhất . 
// Hãy viết chương trình  tìm và in ra giá ngày mua và giá ngày bán theo T+2 trong chuỗi giá đã nhập 

// Chú ý. Giá được lấy đến 2 chữ số thập phân

// Đầu vào sẽ là n và giá của n ngày cách nhau bởi 1 dấu cách trống.
// Nếu ít hơn 2 ngày thì in ra 0
// Test Case mẫu

// INPUT
// 7 123.4 125.4 125.7 126.7 125.3 126.8 127.2
// OUTPUT
// 123.40 127.2

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if(n < 2) {
        printf("0");
        return 0;
    }

    double price[100000], buy = 0, sell = 0;
    for(int i = 0; i < n; i++) scanf("%lf", &price[i]);

    double max_profit = -1e9;

    for(int i = 0; i < n - 2; i++) {               // mua ngày i
        for(int j = i + 2; j < n; j++) {           // bán sau T+2 
            double profit = price[j] - price[i];
            if(profit > max_profit) {
                max_profit = profit;
                buy = price[i];
                sell = price[j];
            }
        }
    }

    if(max_profit <= 0) 
        printf("0");                  // trường hợp không có lãi
    else
        printf("%.2lf %.2lf", buy, sell);

    return 0;
}
