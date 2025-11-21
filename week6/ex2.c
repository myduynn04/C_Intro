// Viết chương trình nhập vào thời gian bắt đầu và thời gian kết thúc cuộc gọi theo dạng YYYY-MM-DD HH:MM:SS.
// In ra thời lượng của cuộc gọi theo giây.

// Chú ý. Nếu thời gian bắt đầu lớn hơn thời gian kết thúc (lỗi thời gian) thì in ra giá trị -1 

// INPUT
// 2024-04-01 12:35:25 2024-04-01 15:35:27 
// OUTPUT
// 10802

// INPUT
// 2024-04-01 12:35:14 2024-04-01 11:35:12 
// OUTPUT
// -1

#include <stdio.h>
#include <time.h>

int main(void) {
    int Y1,M1,D1,h1,m1,s1, Y2,M2,D2,h2,m2,s2;

    if (scanf("%d-%d-%d %d:%d:%d %d-%d-%d %d:%d:%d",
              &Y1,&M1,&D1,&h1,&m1,&s1, &Y2,&M2,&D2,&h2,&m2,&s2) != 12)
        return 0;

    struct tm t1 = {0}, t2 = {0};
    t1.tm_year = Y1 - 1900; t1.tm_mon = M1 - 1; t1.tm_mday = D1;
    t1.tm_hour = h1; t1.tm_min = m1; t1.tm_sec = s1;

    t2.tm_year = Y2 - 1900; t2.tm_mon = M2 - 1; t2.tm_mday = D2;
    t2.tm_hour = h2; t2.tm_min = m2; t2.tm_sec = s2;

    time_t start = mktime(&t1);
    time_t end   = mktime(&t2);

    if (start == (time_t)-1 || end == (time_t)-1 || difftime(end, start) < 0)
        printf("-1\n");
    else
        printf("%.0f\n", difftime(end, start));

    return 0;
}
