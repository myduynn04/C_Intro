# Viết chương trình nhập vào số tự nhiên hệ 10, chuyển đổi sang số la mã
# Cách chuyển là trừ dần cho giá trị số lớn nhất có thể
# M : 1000
# CM : 900
# D : 500
# CD : 400
# C : 100
# XC : 90
# L : 50
# XL : 40
# X : 10
# IX : 9
# V : 5
# IV : 4
# I : 1

# VD 
# 101 = 100 +1 = CI
# 125 = 100 + 10 + 10 + 5 = CXXV


# int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
# char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

# INPUT
# 125

# OUTPUT
# CXXV


# Chú ý. Trong trường hợp số >5000 thì in ra -1
# Test Case mẫu

# INPUT
# 125

# OUTPUT
# CXXV
#include <stdio.h>

int main() {
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    int n;

    scanf("%d", &n);

    if (n > 5000) {
        printf("-1");
        return 0;
    }

    for (int i = 0; i < 13; i++) {

        while (n >= num[i]) {
            printf("%s", roman[i]); 
            n = n - num[i];         
        }
    }
    
    return 0;
}