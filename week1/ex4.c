// Đối với dòng điện xoay chiều AC thì các mức điện áp nguy hiểm sẽ được phân loại như sau:
// Điện áp dưới 24V là an toàn đối với người dùng. 
// Điện áp từ 30V trở lên có thể gây giật cho người tiếp xúc. 
// Điện áp trên 40V được coi là nguy hiểm đối với con người. 

// Hãy viết chương trình đơn giản nhập vào điện áp hoạt động của thiết bị điện và in ra 
// + thông báo nếu có thể gây giật
// + và in ra cảnh báo điện áp đó là nguy hiểm

// INPUT
// 12
// OUTPUT
// An toan

// INPUT
// 28
// OUTPUT
// Khong co du lieu

// INPUT
// 36
// OUTPUT
// Co the gay giat

// INPUT
// 48
// OUTPUT
// Canh bao nguy hiem voi dien



#include <stdio.h>

void check (int a){
    if(a<24) printf("An toan\n");
    else if(a>=30 && a<=40) printf("Co the gay giat\n");
    else if (a>40) printf("Canh bao nguy hiem voi dien\n");
    else printf("Khong co du lieu\n");
    
}

int main()
{
    int v;
 
    scanf("%d", &v);
    check(v);
    return 0;

}