// Nhập vào 1 danh sách n số nguyên (0<=n<=1000).
// Hãy tìm và in ra màn hình số nhỏ nhất có tần số xuất hiện nhỏ nhất trong dãy.
// Nếu số lượng số nhập vào là 0 thì in ra -1

// Đầu vào sẽ lần lượt là 
// n - số lượng số trong dãy
// tiếp đến là n giá trị số nguyên ngăn cách bởi 1 dấu cách trống.

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
    int n;
    
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) {
        printf("-1");
        return 0;
    }

    int a[1005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int min_freq = n + 1; 
    int result = a[0];    

    int i = 0;
    while (i < n) {
        int count = 1;
        int current_val = a[i];

        while (i + count < n && a[i + count] == current_val) {
            count++;
        }

        if (count < min_freq) {
            min_freq = count;
            result = current_val;
        }
        i += count;
    }

    printf("%d", result);

    return 0;
}
