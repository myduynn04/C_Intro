#include <stdio.h>
#include <string.h>

void reset_vars(int *h, int *m, int *s, int *n) {
    *h = -1; *m = -1; *s = -1; *n = -1;
}

int main() {
    char input[] = "08:05:09 250";
    int h, m, s, n;
    int count;

    printf("Input string: \"%s\"\n\n", input);

    // --- TEST PHUONG AN 1: "%d:%d:%d %d" ---
    reset_vars(&h, &m, &s, &n);
    // %d tự động đọc số và dừng khi gặp ký tự không phải số (như dấu :)
    count = sscanf(input, "%d:%d:%d %d", &h, &m, &s, &n);
    
    printf("1. sscanf(..., \"%%d:%%d:%%d %%d\", ...)\n");
    printf("   -> So bien doc duoc: %d/4\n", count);
    printf("   -> Ket qua: h=%d, m=%d, s=%d, n=%d\n", h, m, s, n);
    if (count == 4 && h==8 && m==5 && s==9 && n==250) 
        printf("   => DAP AN DUNG!\n\n");
    else 
        printf("   => SAI.\n\n");


    // --- TEST PHUONG AN 2: "%2d:%2d:%2d %d" ---
    reset_vars(&h, &m, &s, &n);
    // %2d giới hạn đọc tối đa 2 ký tự.
    // Với input "08", nó vẫn hoạt động đúng.
    count = sscanf(input, "%2d:%2d:%2d %d", &h, &m, &s, &n);
    
    printf("2. sscanf(..., \"%%2d:%%2d:%%2d %%d\", ...)\n");
    printf("   -> So bien doc duoc: %d/4\n", count);
    printf("   -> Ket qua: h=%d, m=%d, s=%d, n=%d\n", h, m, s, n);
    printf("   => CUNG DUNG (Nhung kem linh hoat hon phuong an 1)\n\n");


    // --- TEST PHUONG AN 3: "%d-%d-%d %d" ---
    reset_vars(&h, &m, &s, &n);
    // Sai định dạng: Input dùng dấu hai chấm (:), code dùng dấu gạch ngang (-)
    count = sscanf(input, "%d-%d-%d %d", &h, &m, &s, &n);
    
    printf("3. sscanf(..., \"%%d-%%d-%%d %%d\", ...)\n");
    printf("   -> So bien doc duoc: %d/4\n", count);
    printf("   -> Ket qua: h=%d (dung), m=%d (sai), ...\n", h, m);
    printf("   => SAI (Loi dinh dang ky tu ngan cach)\n\n");


    // --- TEST PHUONG AN 4: "%s %d" ---
    char time_str[20];
    n = -1;
    // Cách này đọc cả cụm "08:05:09" vào một chuỗi, không tách riêng h, m, s
    count = sscanf(input, "%s %d", time_str, &n);
    
    printf("4. sscanf(..., \"%%s %%d\", ...)\n");
    printf("   -> Ket qua: time=\"%s\", n=%d\n", time_str, n);
    printf("   => SAI YEU CAU (De bai hoi cach doc ra h, m, s rieng biet)\n");

    return 0;
}