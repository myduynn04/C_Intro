#include <stdio.h>
#include <math.h>

int main() {
    int sv, m1, m2, m3, m4, m5, m6;
    scanf("%d%d%d%d%d%d%d", &sv, &m1, &m2, &m3, &m4, &m5, &m6);
    int tong_may = m1 + m2 + m3 + m4 + m5 + m6;
    int kip = (int)ceil((double)sv / tong_may);
    printf("%d\n", kip);
}