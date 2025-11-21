// Trong một cuộc thi chạy cự ly trung bình, các vận động viên được chia thành các nhóm nhỏ và chạy tính giờ.
// Thời gian hoàn thành bài thi của mỗi vận động viên sẽ là thời gian kết thúc trừ đi thời gian bắt đầu.
// Hãy viết chương trình tính thời gian hoàn thành bài thi của vận động viên và in ra dưới dạng HH:MM:SS.

// Đầu vào cũng là dạng HH:MM:SS và đảm bảo thời điểm bắt đầu luôn nhỏ hơn thời điểm kết thúc.
// Test Case mẫu

// Ví dụ.

// INPUT
// 12:25:34 12:35:37
// OUTPUT
// 00:10:03

// INPUT
// 12:40:34 12:49:31
// OUTPUT
// 00:08:57

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s1, s2;
    int h1, h2;
    int m1, m2;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

    int time = abs((h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1));
    int hours = time / 3600;
    int minutes = (time % 3600) / 60;
    int seconds = time % 60;
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    return 0;
}