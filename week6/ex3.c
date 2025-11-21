// Viết chương trình nhâp vào mốc ngày theo dạng DD-MM-YYYY.
// Kiểm tra xem đó có phải ngày tháng hợp lệ, nếu hợp lệ thì in xem đó là ngày thứ bao nhiêu trong năm. 
// Nếu ngày nhập vào là không hợp lệ thì in ra -1.

// Chú ý. Ngày tháng năm phải là số dương
// INPUT
// 29-02-2024

// OUTPUT
// 60

// #include <stdio.h>
// #include <stdbool.h>

// static bool is_leap(long long y) {
//     return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
// }

// int main(void) {
//     long long D, M, Y;
//     if (scanf("%lld-%lld-%lld", &D, &M, &Y) != 3) {
//         printf("-1\n");
//         return 0;
//     }

//     if (D <= 0 || M <= 0 || Y <= 0) {
//         printf("-1\n");
//         return 0;
//     }


//     if (M < 1 || M > 12) {
//         printf("-1\n");
//         return 0;
//     }

//     int mdays[13] = {0,
//         31,28,31,30,31,30,31,31,30,31,30,31
//     };
//     if (is_leap(Y)) mdays[2] = 29;
//     if (D > mdays[M]) {
//         printf("-1\n");
//         return 0;
//     }

//     int day_of_year = 0;
//     for (int m = 1; m < M; ++m) day_of_year += mdays[m];
//     day_of_year += (int)D;

//     printf("%d\n", day_of_year);
//     return 0;
// }


#include <stdio.h>


int isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1:  return 31;
        case 2:  return isLeapYear(year) ? 29 : 28;
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

int daysUptoMonth(int month, int year) {
    int sum = 0;
    for (int m = 1; m < month; ++m) {
        sum += daysInMonth(m, year);
    }
    return sum;
}

int main(void) {
    int day, month, year;
    if (scanf("%d-%d-%d", &day, &month, &year) != 3) {
        printf("-1\n");
        return 0;
    }

    if (day <= 0 || month <= 0 || month > 12 || year <= 0) {
        printf("-1\n");
        return 0;
    }

    int dim = daysInMonth(month, year);
    if (dim == 0 || day > dim) {  
        printf("-1\n");
        return 0;
    }

    int day_of_year = daysUptoMonth(month, year) + day;
    printf("%d\n", day_of_year);
    return 0;
}
