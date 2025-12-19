// Giai tro choi o chu don gian
// Trung bình
// Đã giải
// Nhập vào 1 ma trận các ký tự hoa kích thước NxM và danh sách các từ.
// Kết thúc danh sách các từ là ký tự #
// Hãy viết chương trình tìm xem các từ đó có xuất hiện trong ma trận ký tự (ô chữ) đầu vào không.
// Nếu có hãy in ra vị trí ô bắt đầu theo tọa độ hàng và cột, và hướng (mã hướng như mô tả ở dưới).
// Ngược lại in ra -1 (là từ đó không xuất hiện).
// Có 8 hướng (dx, dy) có thể gồm 
// 0 1 là  từ trái sang phải
// 0 -1 là  từ phải sang trái
// 1 0 là từ trên xuống dưới
// -1 0 là từ dưới hướng lên trên
// 1 1 là chéo từ trên xuống dưới, từ trái sang phải
// -1 1 là chéo từ dưới lên trên, từ trái sang phải
// 1 -1 là chéo từ trên xuống dưới, từ phải sang trái
// -1 -1 là chéo từ dưới lên trên, từ phải sang trái
// Test Case mẫu

// Ví dụ
// INPUT
// 10 10
// H  E  L  L  O  A  B  C  D  E
// A  I  G  L  E  O  P  L  A  N
// P  R  O  G  R  A  M  M  E  R
// C  A  T  S  D  O  G  X  Y  Z
// S  T  A  C  K  Q  U  E  U  E
// E  D  C  B  R  E  U  T  R  E
// R  Q  U  I  C  K  K  E  T  S
// F  O  X  Y  Z  D  L  I  E  K
// J  U  M  P  K  H  O  U  S  N
// S  I  T  U  W  P  R  O  C  K
// HELLO
// CAT
// QUEEN
// JUMP
// LEARN
// #

// OUTPUT
// HELLO 0 0 0 1
// CAT 3 0 0 1
// QUEEN 4 5 1 1
// JUMP 8 0 0 1
// LEARN -1

#include <stdio.h>
#include <string.h>

// Định nghĩa kích thước tối đa cho ma trận (tùy chỉnh theo đề bài thực tế)
#define MAX_N 100
#define MAX_M 100

// Mảng chứa các hướng di chuyển (dx, dy)
// Tương ứng: Ngang, Dọc, Chéo
int dir_x[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dir_y[] = {1, -1, 0, 0, 1, 1, -1, -1};

// Hàm kiểm tra xem toạ độ có nằm trong ma trận không
int isValid(int r, int c, int N, int M) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int main() {
    int N, M;
    char grid[MAX_N][MAX_M];
    
    // 1. Nhập kích thước
    if (scanf("%d %d", &N, &M) != 2) return 0;

    // 2. Nhập ma trận ký tự
    // Lưu ý: " %c" có dấu cách phía trước để bỏ qua khoảng trắng/xuống dòng
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    char word[101]; // Biến lưu từ cần tìm
    
    // 3. Vòng lặp đọc từng từ cho đến khi gặp dấu #
    while (1) {
        scanf("%s", word);
        
        // Điều kiện dừng
        if (strcmp(word, "#") == 0) {
            break;
        }

        int len = strlen(word);
        int found = 0; // Cờ đánh dấu đã tìm thấy hay chưa

        // Duyệt qua từng ô trong ma trận
        for (int r = 0; r < N && !found; r++) {
            for (int c = 0; c < M && !found; c++) {
                
                // Nếu ký tự đầu tiên khớp
                if (grid[r][c] == word[0]) {
                    
                    // Kiểm tra 8 hướng
                    for (int d = 0; d < 8; d++) {
                        int k;
                        int dr = dir_x[d];
                        int dc = dir_y[d];
                        
                        // Kiểm tra các ký tự tiếp theo của từ
                        for (k = 1; k < len; k++) {
                            int next_r = r + k * dr;
                            int next_c = c + k * dc;

                            // Nếu vượt ra ngoài ma trận hoặc ký tự không khớp
                            if (!isValid(next_r, next_c, N, M) || grid[next_r][next_c] != word[k]) {
                                break;
                            }
                        }

                        // Nếu k chạy hết độ dài từ, nghĩa là tìm thấy
                        if (k == len) {
                            printf("%s %d %d %d %d\n", word, r, c, dr, dc);
                            found = 1;
                            break; // Thoát khỏi vòng lặp hướng
                        }
                    }
                }
            }
        }

        // Nếu duyệt hết mà không tìm thấy
        if (!found) {
            printf("%s -1\n", word);
        }
    }

    return 0;
}