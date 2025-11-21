#include <stdio.h>
int main() {
    int x = 3, y = 0;

    switch (x) {
        case 1:
            y += 10;
            break;
        case 2:
        case 3:
            y += 5;
        case 4:
            y += 2;
            break;
        default:
            y += 100;
    }

    printf("%d\n", y);
    return 0;
}