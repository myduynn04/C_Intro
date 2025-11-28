
// Múi giờ của VN là GMT+7.
// Hãy viết chương trình nhập vào thời điểm hiện tại theo giờ VN dạng YYYY-MM-DD HH:MM:SS
// và nhập vào múi giờ cần chuyển đổi.
// In ra giờ chuyển đổi theo múi giờ đó cũng theo định dạng YYYY-MM-DD HH:MM:SS
// Test Case mẫu

// INPUT 
// 2024-10-28 15:25:00
// +9
// OUTPUT
// 2024-10-28 17:25:00

// INPUT
// 2024-10-28 15:25:00
// 0
// OUTPUT
// 2024-10-28 08:25:00


#include <stdio.h>
#include <time.h>

int main() {
    int y, m, d, h, min, s;
    int target_timezone;

    if (scanf("%d-%d-%d %d:%d:%d", &y, &m, &d, &h, &min, &s) != 6) {
        return 1; 
    }

    scanf("%d", &target_timezone);

    struct tm t = {0}; 
    t.tm_year = y - 1900; 
    t.tm_mon  = m - 1;    
    t.tm_mday = d;
    t.tm_hour = h;
    t.tm_min  = min;
    t.tm_sec  = s;
    t.tm_isdst = -1;      

    int offset = target_timezone - 7;
    t.tm_hour += offset;

    mktime(&t);

    printf("%04d-%02d-%02d %02d:%02d:%02d\n", 
           t.tm_year + 1900, 
           t.tm_mon + 1, 
           t.tm_mday, 
           t.tm_hour, 
           t.tm_min, 
           t.tm_sec);

    return 0;
}