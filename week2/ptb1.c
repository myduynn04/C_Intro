#include <stdio.h>
int main() {
    double a, b, c;
    double x;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if (a == 0) {
        if (b == c)
            printf("VO SO NGHIEM\n");
        else
            printf("VO NGHIEM\n");
    } else {
        x = (c - b) / a;
        printf("%.4f\n", x);
    }

}