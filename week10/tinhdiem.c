#include <stdio.h>

#define MAX 100     // tối đa 100 bài, có thể điều chỉnh
#define TAKE 10     // chỉ lấy 10 bài cao nhất

void sort_desc(double arr[], int n) {
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] < arr[j]) {
                double tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

double tinhTrungBinh() {
    int a, b;
    double scores[MAX];
    int n = 0;

    printf("Nhap diem dang a/b (nhap 0/0 de dung):\n");

    while(1) {
        scanf("%d/%d", &a, &b);
        if(a==0 && b==0) break;       // kết thúc nhập

        scores[n++] = (a * 10.0) / b; // chuẩn hoá về thang 10
        if(n >= MAX) break;
    }

    if(n == 0) return 0;              // tránh lỗi chia 0

    sort_desc(scores, n);             // sắp xếp giảm dần

    double sum = 0;
    int count = (n < TAKE) ? n : TAKE;

    for(int i=0;i<count;i++)
        sum += scores[i];

    return sum / count;
}

int main() {
    double avg = tinhTrungBinh();
    printf("\nDiem trung binh top 10 = %.2f\n", avg);
    return 0;
}

