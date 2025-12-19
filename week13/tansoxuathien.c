// Nhập vào 1 đoạn văn từ bán phím (tối đa 10000 chữ cái).
// Hãy in ra các tên riêng có trong đoạn văn theo thứ tự xuất hiện và tần số.
// Tên riêng là từ có ký tự đầu tiên được viết hoa, các từ được ngăn cách với nhau bởi 1 dấu cách trống hoặc dấu câu.
// Độ dài tên riêng từ 2 ký tự trở lên và bắt đầu phải bằng chữ cái.
// Mỗi từ và tần số sẽ được in trên 1 dòng riêng
// Test Case mẫu

// INPUT
// A rights group based in New York City says it has documents from Chinese officials that show a plan to push rural Tibetans into cities against their will.Human Rights Watch released a report recently that provides evidence against official Chinese statements that many Tibetans have moved voluntarily. The report said that, by the end of 2025, more than 930,000 rural Tibetans will have been moved to city areas. It said the Tibetans will not be able to get traditional jobs and will be limited in ways to make money.

// OUTPUT
// New 1
// York 1
// City 1
// Chinese 2
// Tibetans 4
// Human 1
// Rights 1
// Watch 1
// The 1
// It 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char val[100];
    int count;
} Word;

int check(char *s) {
    if (strlen(s) < 2) return 0;
    if (!isupper(s[0])) return 0;
    return 1;
}

int findPos(Word list[], int n, char *s) {
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].val, s) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char text[10005]; // Mảng lưu toàn bộ văn bản sau khi lọc
    int n = 0;
    char c;

    while (scanf("%c", &c) != -1) { 
        if (isalnum(c) || c == '\'' || c == '-') {
            text[n++] = c;
        } else {
            text[n++] = ' ';
        }
    }
    text[n] = '\0'; 

    Word list[2000]; 
    int countWord = 0;

    char *token = strtok(text, " ");

    while (token != NULL) {
        if (check(token)) {
            int idx = findPos(list, countWord, token);
            if (idx != -1) {
                list[idx].count++;
            } else {
                strcpy(list[countWord].val, token);
                list[countWord].count = 1;
                countWord++;
            }
        }
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < countWord; i++) {
        printf("%s %d\n", list[i].val, list[i].count);
    }

    return 0;
}