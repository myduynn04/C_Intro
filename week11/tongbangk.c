// Nhập vào 1 danh sách n số nguyên (2<=n<=1000) và 1 số nguyên k.
// Hãy tìm xem có tồn tại 2 số khác nhau trong mảng mà tổng bằng k hay không?
// Nếu có thì in ra 2 số a<b (a nhỏ nhất có thể).
// Ngược lại in ra -1 

// Đầu vào theo thứ tự lần lượt sẽ là n k và danh sách n số nguyên

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int a[1005]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) {
                if (a[i] < a[j]) {
                    printf("%d %d", a[i], a[j]);
                    return 0; 
                }
            }
            if (a[i] + a[j] > k) {
                break; 
            }
        }
    }

    printf("-1");
    return 0;
}
