// Để bảo mật thì mật khẩu cần có ít nhất 8 và nhiều nhất 15 ký tự
// trong đó
// + Phải có chứa đủ ít nhất 1 chữ cái hoa, 1 chữ cái thường, chữ số
// + Phải có các ký tự đặc biệt gồm !@#$%^&*().?`~,<>
// + Không chứa các tổ hợp ký tự thông dụng trong nhóm 

// abcdef
// 123456
// password
// 123321

// Hãy viết chương trình kiểm tra mật khẩu người dùng tạo có phải là 1 mật khẩu mạnh.
// Hàm in ra giá trị 0 nếu mật khẩu không thỏa mãn là mật khẩu mạnh, và 1 trong trường hợp ngược lại.
// Test Case mẫu

// INPUT
// password
// OUTPUT
// 0

// INPUT
// p@ssWord12#
// OUTPUT
// 1


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int checkStrongPassword(char *password) {
    int len = strlen(password);

    if (len < 8 || len > 15) {
        return 0;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    
    const char *specialChars = "!@#$%^&*().?`~,<>";

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUpper = true;
        } else if (islower(password[i])) {
            hasLower = true;
        } else if (isdigit(password[i])) {
            hasDigit = true;
        } else if (strchr(specialChars, password[i]) != NULL) {
            hasSpecial = true;
        }
    }

    if (!hasUpper || !hasLower || !hasDigit || !hasSpecial) {
        return 0;
    }

    const char *forbidden[] = {"abcdef", "123456", "password", "123321"};
    int numForbidden = 4;

    for (int i = 0; i < numForbidden; i++) {
        if (strstr(password, forbidden[i]) != NULL) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char password[100];

    if (fgets(password, sizeof(password), stdin) != NULL) {
        password[strcspn(password, "\n")] = '\0'; 
    }

    printf("%d", checkStrongPassword(password));

    return 0;
}