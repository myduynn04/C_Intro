// Chương trình nhập vào một số nguyên từ bàn phím, (giá trị số tối đa lên tới 18 chữ số) và đọc số theo dạng chữ
// Hãy hoàn thiện chương trình trên dựa trên 1 số hàm cho sẵn

// INPUT
// 1234
// OUTPUT
// một nghìn hai trăm ba mươi tư

// INPUT
// 100006
// OUTPUT
// mot tram nghin le sau

// INPUT
// -1230002234
// OUTPUT
// am mot ty hai tram ba muoi trieu hai nghin hai tram ba muoi bon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char DIGIT[10][6] = { "khong","mot","hai","ba","bon","nam","sau","bay","tam","chin" };
const char POWERS_OF_TEN[7][9] = { "", "nghin", "trieu", "ty", "nghin ty", "trieu ty", "ty ty" };

void docso(int digit, char* result)
{
    strcat(result, DIGIT[digit]);
}

void docbo3so(int num, char* result)
{
    int a, b, c;
    a = num / 100;
    b = num % 100 / 10;
    c = num % 10;
    if (a > 0) {
        docso(a, result);
        //printf(" tram");
        strcat(result, " tram");
        if (b == 0) {
            if (c != 0) strcat(result, " le");//printf(" le");
        }
        else {
            if (b > 1) {
                strcat(result, " ");//printf(" "); 
                docso(b, result);
            }
            //printf(" muoi");
            strcat(result, " muoi");
        }
        if (c != 0) {
            strcat(result, " ");//printf(" ");
            docso(c, result);
        }
    }
    else if (b != 0)
    {
        if (b > 1) {
            docso(b, result);
            strcat(result, " muoi");//printf(" muoi");
        }
        else strcat(result, "muoi");//printf("muoi");
        if (c != 0) {
            strcat(result, " ");//printf(" ");
            docso(c, result);
        }
    }
    else docso(c, result);
}

void them_khoang_trang(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] != ' ')
        strcat(s, " ");
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    char result[1024];
    result[0] = '\0';

    if (n == 0) {
        strcat(result, DIGIT[0]); 
        printf("%s", result);
        return 0;
    }

    if (n < 0) {
        strcat(result, "am ");
        n = -n;
    }


    int blocks[7];  
    int cnt = 0;
    while (n > 0) {
        blocks[cnt++] = (int)(n % 1000);
        n /= 1000;
    }
    int highest = cnt - 1;

    for (int i = highest; i >= 0; --i) {
        if (blocks[i] == 0) continue;  

        if (i == 0 && blocks[i] > 0 && blocks[i] < 10 && highest > 0) {
            them_khoang_trang(result);
            strcat(result, "le");
        }

        them_khoang_trang(result);
        docbo3so(blocks[i], result);

        if (i > 0) { 
            them_khoang_trang(result);
            strcat(result, POWERS_OF_TEN[i]);
        }
    }

    printf("%s", result);
    return 0;
}