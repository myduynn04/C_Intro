// Viết chương trình nhập vào nhiệt độ tính theo oC, in ra màn hình giá trị nhiệt độ tính theo độ K
// Công thức chuyển đổi tương ứng là 1 °C = 274.15 K

// INPUT
// 1

// OUTPUT
// 274.15

// Kết quả ra lấy đến 2 chữ số thập phân


#include <stdio.h>

int main()
{   double degree_c;
    scanf("%lf", &degree_c);
    printf("%.2lf", degree_c+273.15);
}