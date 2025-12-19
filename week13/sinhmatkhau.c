// Để tạo ra 1 mật khẩu mạnh và dễ nhớ thì ta có thể dùng 1 xâu ký tự đầu vào (ít nhất có 10 ký tự trở lên) và ngày tháng năm hiện tại(dạng YYYYMMDD).
// Xâu các ký tự đặc biệt sẽ gồm 10 ký tự như sau "!@#$%^&*()".
// Thuật toán để tạo mật khẩu độ dài 8-16 ký tự như sau
// + Lấy lần lượt các chữ cái in hoa trong xâu đầu vào
// + Mỗi ký tự lấy được lại lấy tiếp 1 ký tự thứ k trong xâu đặc biệt (với k là số thứ i trong trong chuỗi ngày tháng năm tương ứng).
// Nếu đủ độ dài thì dừng, nếu chưa lại lặp tiếp các ký tự thường còn lại 

// Ví dụ.  
// Xâu đầu vào: Nguyen Van A
// Ngày tháng năm : 20241216
// Xâu đặc biệt !@#$%^&*()

// Tạo mật khẩu độ dài 8: N#V!A#g%
// Tạo mật khẩu độ dài 10: N#V!A#g%u@

// Chú ý. Mật khẩu không chứa dấu cách trống!
// Nếu tham số đầu vào không đúng, in ra "tham so khong hop le!"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10005];        
    char date[20];       
    char special[20];    
    int n;               

    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    s[strcspn(s, "\n")] = 0;

    scanf("%s", date);
    scanf("%s", special);
    scanf("%d", &n);

    if (strlen(s) < 10 || n < 8 || n > 16) {
        printf("tham so khong hop le!");
        return 0;
    }

    char userPool[10005];
    int poolCount = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i])) {
            userPool[poolCount++] = s[i];
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            userPool[poolCount++] = s[i];
        }
    }
    userPool[poolCount] = '\0';

    int userIdx = 0;      
    int specialCnt = 0;  
    int dateLen = strlen(date);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (userIdx < poolCount) {
                printf("%c", userPool[userIdx]);
                userIdx++;
            }
        } else {
            int dateCharIdx = specialCnt % dateLen;
            int k = date[dateCharIdx] - '0'; 
            
            printf("%c", special[k]);
            
            specialCnt++; 
        }
    }

    return 0;
}
