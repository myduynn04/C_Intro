#include <stdio.h>

int main() {
    int n;
    
    // Nhập số n
    scanf("%d", &n);

    // Kiểm tra nếu n không phải số nguyên dương (n <= 0)
    if (n <= 0) {
        printf("-1\n");
    } else {
        int count = 0;
        
        // Thuật toán Brian Kernighan:
        // Lặp lại việc xóa bit 1 ở vị trí cuối cùng (ngoài cùng bên phải)
        // cho đến khi n = 0.
        // Phép toán n & (n - 1) sẽ xóa bit 1 cuối cùng đó.
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        
        // In ra số lượng bit 1
        printf("%d\n", count);
    }

    return 0;
}