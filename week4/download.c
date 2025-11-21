// //Một đường truyền mạng có tốc độ tối đa 12.5Mbps, nếu cần tải 1 file có dung lượng 250MB, thời gian tối thiểu cần để tải file sẽ là
// 250 * 8388608/12500000 = 167.77216 seconds (168s)


// Tốc độ đường truyền tính theo hệ 10: 1Mbps = 1000Kbps = 1000000bps
// Dung lượng file trong máy tính theo hệ 2: 1MB = 1024 KB = 1048576 B = 8388608 b
// B = Byte
// b = bit

// Hãy xây dựng chương trình tính thời gian này vơi đầu vào lần lượt là
// Tốc độ đường truyền tối đa tính theo Mbps, dung lượng file tính theo MB.
// In ra thời gian tính theo giây (làm tròn lên nếu lẻ)
// Test Case mẫu

// INPUT
// 12.5 250
// OUTPUT
// 168

// INPUT
// 25.5 2500
// OUTPUT
// 823
#include <stdio.h>
#include <math.h>
int main() {
    double speed, size;
    scanf("%lf %lf", &speed, &size);
    double time = (size * 8388608) / (speed * 1000000);
    printf("%d", (int)ceil(time));
    return 0;
}
