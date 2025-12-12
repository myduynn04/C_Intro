// Kiểm tra 2 danh sách có tương đồng hay không
// Trung bình
// Hai danh sách được gọi là tương đồng nếu nó 
// + chứa số lượng phần tử giống nhau
// + có thứ tự tăng giảm của các phần tử theo thứ tự giống nhau (chỉ cần kiểm tra 2 phần tử cạnh nhau)

// VD. 
// + arr1[] = {1, 2, 4, 7} và arr2[]= {3, 7, 10, 15} là tương đồng
// + arr1[] = {1, 2, 2, 3} và arr2[]= {3, 7, 7, 15} là tương đồng 
// + arr1[] = {1, 2, 2, 3} và arr2[]= {3, 7, 8, 15} là không tương đồng 

// Hãy viết chương trình nhập vào 2 mảng với số lượng phần tử là n (n<=100)
// Nếu 1 mảng là tương đồng thì in ra giá trị 1
// Nếu không phải tương đồng thì in ra -1 và cặp phần tử không tương đồng đầu tiên
// Test Case mẫu

// INPUT
// 4
// 1 2 4 7
// 3 7 10 15
// OUTPUT
// 1


// INPUT
// 4
// 1 2 2 7
// 3 7 10 15
// OUTPUT
// -1 2 10

#include <stdio.h>

int main() {
    int n;
    int a[100], b[100];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

  
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int similar = 1;

    for (int i = 1; i < n; i++) {
        int s1, s2;

        if (a[i] > a[i - 1]) s1 = 1;      
        else if (a[i] < a[i - 1]) s1 = -1; 
        else s1 = 0;                      

        if (b[i] > b[i - 1]) s2 = 1;
        else if (b[i] < b[i - 1]) s2 = -1;
        else s2 = 0;

        if (s1 != s2) {
            printf("-1 %d %d", a[i], b[i]);  
            similar = 0;
            break;
        }
    }

    if (similar) {
        printf("1");
    }

    return 0;
}
