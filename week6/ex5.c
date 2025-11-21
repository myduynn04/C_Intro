// Bạn nhập vào ngày hôm nay là thứ 2, ngày 08-04-2024 thì thứ tiếp theo sẽ là 15-04-2024
// Hãy viết chương trình nhập vào ngày và thứ, in ra này tiếp theo của thứ đó

// Chú ý. Ngày tháng nhập vào đã hợp lệ
// INPUT
// 08-04-2024

// OUTPUT
// 15-04-2024

#include <stdio.h>

int isLeap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int m, int y) {
    switch (m) {
        case 1:  return 31;
        case 2:  return isLeap(y) ? 29 : 28;
        case 3:  return 31;
        case 4:  return 30;
        case 5:  return 31;
        case 6:  return 30;
        case 7:  return 31;
        case 8:  return 31;
        case 9:  return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;  
    }
}

int main(void) {
    int d, m, y;
    if (scanf("%d-%d-%d", &d, &m, &y) != 3) return 0;

    d += 7;

    while (1) {
        int dim = daysInMonth(m, y);
        if (d <= dim) break;
        d -= dim;
        m++;
        if (m > 12) { m = 1; y++; }
    }

    printf("%02d-%02d-%04d\n", d, m, y);
    return 0;
}
