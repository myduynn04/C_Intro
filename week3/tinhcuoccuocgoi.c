// Một hãng viễn thông cung cấp gói cước gọi điện thoại như sau
// + Block đầu (6s): là giá 159 VND
// + Các giây tiếp theo từ giây thứ 7 là: 26.5 VND 

// Với các cuộc gọi nhỏ hơn 6s đầu được tính giá là 1 block.
// Hãy viết chương trình nhập vào thời gian bắt đầu và kết thúc gọi (trong ngày) dạng HH:MM:SS.
// Tính và in ra tiền cho cuộc gọi đó.
// Đầu ra lấy tới 2 chữ số thập phân.
// Test Case mẫu

// Ví dụ.

// INPUT
// 12:25:34 12:25:37
// OUTPUT
// 159.00

// INPUT
// 12:25:34 12:25:41
// OUTPUT
// 185.50

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s1, s2;
    int h1, h2;
    int m1, m2;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

    int time = abs((h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1));
    double cost = 0;
    if (time <= 6)
        cost = 159.00;
    else
        cost = 159.00 + (time - 6) * 26.50;

    printf("%.2f\n", cost);
}