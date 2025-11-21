#include <stdio.h>
int calculate_reward(int steps) {
    if (steps < 10000) {
        return 0;
    } else if (steps < 20000) {
        return 1;
    } else if (steps < 30000) {
        return 2;
    } else if (steps < 40000) {
        return 4;
    } else if (steps < 50000) {
        return 5;
    } else {
        return 7;
    }
}

int main() {
    int steps;
    printf("So buoc trong ngay: ");
    scanf("%d", &steps);

    int reward = calculate_reward(steps);
    printf("Diem thuong cho %d buoc la %d\n", steps, reward);

    return 0;
}