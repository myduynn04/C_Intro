#include <stdio.h>
int main() {
    int a = 7, b = 2;
    float x, y;
    x = a / b;
    y = (float)(a / b);
    printf("x = %.2f, y = %.2f\n", x, y);
    return 0;
}