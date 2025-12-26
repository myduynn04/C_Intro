#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[20];
    int x, y;
} toado;

int main() {
    toado A = {"Diem A", 4, 5}, B;

    B = A;
    B.x = 5;
    A.y = 7;

    strcpy(B.ten, "Diem B");

    printf("B = %-5s|%3d%3d", B.ten, B.x, B.y);
    return 0;
}
