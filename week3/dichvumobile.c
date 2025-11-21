// Một người dùng có đăng ký gói cước internet trong ngày của một nhà mạng chi tiết như sau
// + chi phí đăng ký 7000 VND sẽ được sử dụng 3GB dung lượng data
// + Nếu hết 3GB dung lượng vượt quá sẽ được tính theo giá thông thường là 60 VND/MB
// Dung lượng vượt quá sẽ được làm trong lên 1 MB.
// đơn vị đo dung lượng 
// 1GB = 1000MB
// 1MB = 1000KB
// 1KB = 1000B

// Hãy viết chương trình nhập vào tổng dung lượng người dùng đã dùng trong ngày theo Byte và in ra tổng tiền phải trả 

// Test Case mẫu

// Ví dụ.

// INPUT
// 2050060720
// OUTPUT
// 7000

// INPUT
// 3000012510
// OUTPUT
// 7060

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int usedBytes;
    scanf("%lld", &usedBytes);
    double cost = 7000;
    if (usedBytes <= 3000000000) 
    {
        printf("%.f\n", cost);
        return 0;
    }
    usedBytes -= 3000000000; 

    long long extraMB = (usedBytes + 999999) / 1000000; 
    cost += extraMB * 60.00;

    printf("%.f\n", cost);
    return 0;
}