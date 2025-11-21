// Nhà mạng Viettel hiện có các đầu số 096, 097, 098, 086, 032, 033, 034, 035, 036, 037, 038, 039
// Nhà mạng Vinaphone  088, 091, 094, 081, 082, 083, 084, 085
// Nhà mạng Mobiphone 090, 093, 089, 070, 076, 077, 078 và 079
// Nhà mạng Vietnamobile 092, 056 và 058
// Nhà mạng Gmobile(ITelecom) 099 và 0199
// Nhà mạng Reddi(Wintel) 055

// Hãy nhập vào 1 SDT di động hợp lệ và trả về nhà mạng của SDT đó

// SDT di động ở VN thường có 2 dạng là 
// 0962124234 hoặc 84962124234

// Tên nhà mạng viết đúng theo dạng: Viettel, Vinaphone, Mobiphone, Vietnamobile, Gmobile, Wintel
// INPUT
// 0962124234
// OUTPUT
// Viettel

// INPUT
// 84992124234
// OUTPUT
// ITelecom

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char in[64];
    if (scanf("%63s", in) != 1) return 0;

    char buf[64];
    int bi = 0;
    for (int i = 0; in[i] && bi < 63; ++i) {
        if (i == 0 && in[i] == '+') continue;
        buf[bi++] = in[i];
    }
    buf[bi] = '\0';

    char num[64];
    if (strncmp(buf, "84", 2) == 0) {

        num[0] = '0';
        strcpy(num + 1, buf + 2);
    } else {
        strcpy(num, buf);
    }

    for (int i = 0; num[i]; ++i) {
        if (!isdigit((unsigned char)num[i])) {
            puts("INVALID");
            return 0;
        }
    }

    if (num[0] != '0') {
        puts("INVALID");
        return 0;
    }

    int len = (int)strlen(num);

    if (len == 11 && strncmp(num, "0199", 4) == 0) {
        puts("ITelecom");
        return 0;
    }

    if (len != 10) {
        puts("INVALID");
        return 0;
    }

    char p3[4]; memcpy(p3, num, 3); p3[3] = '\0';
    if (!strcmp(p3,"096")||!strcmp(p3,"097")||!strcmp(p3,"098")||!strcmp(p3,"086")||
        !strcmp(p3,"032")||!strcmp(p3,"033")||!strcmp(p3,"034")||!strcmp(p3,"035")||
        !strcmp(p3,"036")||!strcmp(p3,"037")||!strcmp(p3,"038")||!strcmp(p3,"039")) {
        puts("Viettel"); return 0;
    }
    if (!strcmp(p3,"088")||!strcmp(p3,"091")||!strcmp(p3,"094")||
        !strcmp(p3,"081")||!strcmp(p3,"082")||!strcmp(p3,"083")||
        !strcmp(p3,"084")||!strcmp(p3,"085")) {
        puts("Vinaphone"); return 0;
    }
    // Mobiphone
    if (!strcmp(p3,"090")||!strcmp(p3,"093")||!strcmp(p3,"089")||
        !strcmp(p3,"070")||!strcmp(p3,"076")||!strcmp(p3,"077")||
        !strcmp(p3,"078")||!strcmp(p3,"079")) {
        puts("Mobiphone"); return 0;
    }
    if (!strcmp(p3,"092")||!strcmp(p3,"056")||!strcmp(p3,"058")) {
        puts("Vietnamobile"); return 0;
    }
    if (!strcmp(p3,"099")) {
        puts("ITelecom"); return 0;
    }
    if (!strcmp(p3,"055")) {
        puts("Wintel"); return 0;
    }

    puts("INVALID");
    return 0;
}
