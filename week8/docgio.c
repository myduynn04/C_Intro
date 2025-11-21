// Viết chương trình đọc giờ theo tiếng anh dạng 24h (đọc giờ theo cách trong quân đội)

// 00:00 --> twenty four hundred hours
// 05:45 --> zero five forty five hours
// 20:37 --> twenty thirty seven hours
// 07:01 --> zero seven zero one hours

// Đầu vào nhập vào giờ và phút dạng HH:MM
// in ra cách đọc giờ theo tiếng Anh
// Test Case mẫu

// 00:00 --> twenty four hundred hours
// 05:45 --> zero five forty five hours
// 20:37 --> twenty thirty seven hours
// 07:01 --> zero seven zero one hours

#include <stdio.h>
#include <string.h>

void readNumber(int n, char *out) {
    const char *tens[] = {
        "zero", "ten", "twenty", "thirty", "forty", "fifty"
    };

    const char *ones[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    if (n < 10) {
        sprintf(out, "zero %s", ones[n]);
    } else if (n < 20) {
        // 10–19
        const char *teens[] = {
            "ten", "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
        };
        sprintf(out, "%s", teens[n - 10]);
    } else {
        int t = n / 10;
        int o = n % 10;
        if (o == 0)
            sprintf(out, "%s", tens[t]);
        else
            sprintf(out, "%s %s", tens[t], ones[o]);
    }
}

int main() {
    int h, m;
    char hour_word[50], min_word[50];

    scanf("%d:%d", &h, &m);

    if (h == 0) {
        strcpy(hour_word, "twenty four");
    } else {
        readNumber(h, hour_word);
    }

    readNumber(m, min_word);

    printf("%s %s hours\n", hour_word, min_word);

    return 0;
}
