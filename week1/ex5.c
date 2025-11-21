#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a/b); //Ra 1 
    printf("%f\n", a/b); //Sẽ luôn trả về 0 do không đúng kiểu dữ liệu 
    printf("%f", (float)a/b); // Như này mới đúng
    return 0;}