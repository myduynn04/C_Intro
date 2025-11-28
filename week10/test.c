#include <stdio.h>


int rem(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int temp[n];
    int j = 0;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];

    temp[j++] = arr[n-1];

    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

#include <stdio.h>

int main() {
    // Giả sử mảng A theo đề bài
    int A[] = {1, 4, 6, 4, 3, 5, 7, 8, -4, 3}; 
    int n = 10, sum = 0, k = 5;
    int t = 0; // Biến đếm số lượng phần tử thỏa mãn

    for(int i = 0; i < n; i++) {
        if(A[i] > k) { // Nếu phần tử > 5
            sum += A[i];
            t++;
        }
    }
    
    // Lưu ý: Phép chia sum/t
    printf("Trung binh cong %2d", sum/t); 
    return 0;
}