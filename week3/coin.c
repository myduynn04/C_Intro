// Một sàn giao dịch tiền ảo sẽ thưởng cho người dùng tiền ảo là coin $CINTRO khi người dùng stake đồng coin $C của sàn.
// Trong đợt này giả sử sẽ có tổng cộng N coin $CINTRO được thưởng.
// Tổng số coin $C mà người dùng trong sàn tham gia stake là M.
// Tổng thời gian stake để thu được coin thưởng là H.
// Người dùng stake k coin $C của mình có với thời gian tham gia stake của người dùng mà sàn snapshoot được là hh:mm.
// Cứ 30' sẽ trả thưởng 1 lần.
// Hãy tính số lượng coin $CINTRO mà người dùng này nhận được.

// Đầu vào lần lượt N M H k hh:mm 
// Đầu ra lấy tới 8 chữ số thập phân (KHÔNG làm tròn)
// Test Case mẫu

// Ví dụ.

// INPUT
// 100000 4000000 12 3.5 12:00
// OUTPUT
// 0.08750000

// INPUT
// 100000 4000000 12 3.5 10:35
// OUTPUT
// 0.07656250

// INPUT
// 1000000 400000000 240 300.5 201:10

// OUTPUT
// 0.62917187

// INPUT
// 2500000 100000000 360 2500.56 350:10

// OUTPUT
// 60.77750000



#include <stdio.h>
#include <math.h> // Cần thư viện math.h cho pow

#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    double N, M, H, k;
    char time_str[10];
    int h, m;
    
    scanf("%lf %lf %lf %lf %s", &N, &M, &H, &k, time_str);
    
    sscanf(time_str, "%d:%d", &h, &m);

    double total_minutes = (double)h * 60.0 + (double)m;
    double user_intervals = floor(total_minutes / 30.0);
    double total_intervals = H * 2.0;
    
    double reward = (k / M) * N * (user_intervals / total_intervals);
    
    double scale = 100000000.0; 
    double reward_trunc = floor(reward * scale) / scale;
    
    printf("%.8f\n", reward_trunc);
    
    return 0;
}