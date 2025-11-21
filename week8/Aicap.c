// Khi loài người bắt đầu có sự phân hóa giàu nghèo thì cũng là lúc đồng thời nhu cầu đếm và chia phát sinh. Để chia cho kết quả công bằng, phân số được ra đời. Lịch sử ghi nhận phân số được đưa thành kí hiệu Toán học đầu tiên là của người Ai Cập cách đây khoảng 3.650 năm. Lúc đó, các phân số đều chỉ có tử số là 1, các mẫu số là số tự nhiên lớn hơn 0. Ngày ấy, loài người thống nhất gọi đó là những phân số Ai Cập.

// Do người Ai Cập cổ đại chỉ công nhận các phân số có tử số bằng 1 nên các phân số có tử số lớn hơn 1 đều dược viết dưới dạng tổng các phân số có tử bằng 1 và mẫu số khác nhau.

// Người ta tin rằng mọi phân số đều biểu diễn được dưới dạng tổng của nhiều phân số. Bởi vậy, không cần đưa thêm những phân số có tử số khác 1 vào. Những phân số hay được sử dụng để biểu diễn nhất là những phân số Ai Cập mà mẫu số có nhiều ước số như 12, 24, 60, 36, 144... Có lẽ đó cũng là nguyên nhân hình thành đơn vị như: tá (12 giờ của nửa ngày, 12 chi trong chu kì lịch, 12 tháng của một năm), 24 giờ (trong một ngày), 60 giây (trong một phút), 60 phút (trong một giờ).

// Hãy viết chương trình nhập vào 1 phân số dạng a/b (b>a) và phân tích ra phân số ai cập dạng tổng các số 1/c + 1/d + ... với số lượng phân số là nhỏ nhất 
// Test Case mẫu

// INPUT
// 2/3
// OUTPUT
// 1/2 1/6

// Tức là phân số 2/3 sẽ được phân tách thành tổng của 1/2 và 1/6

// INPUT
// 5/7
// OUTPUT
// 1/2 1/5 1/70

// INPUT
// 5/3
// OUTPUT
// -1

// Vì giá trị đầu vào của a và b là không hợp lệ

#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void phanTichAiCap(long long a, long long b) {
    if (a <= 0 || b <= 0 || a >= b) {
        printf("-1\n");
        return;
    }

    while (a > 0) {
        long long c = (b + a - 1) / a;

        printf("1/%lld", c);

        long long new_a = a * c - b;
        long long new_b = b * c;
        a = new_a;
        b = new_b;
        if (a > 0) {
            long long common = gcd(a, b);
            a = a / common;
            b = b / common;
            
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    long long tuSo, mauSo;
    if (scanf("%lld/%lld", &tuSo, &mauSo) == 2) {
        phanTichAiCap(tuSo, mauSo);
    } else {
        printf("-1\n");
    }

    return 0;
}