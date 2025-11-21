// Nhập vào năm và thứ của ngày đầu tiên trong năm đó (ngày 01/01)
// Quy ước: 
// + 0 là thứ 2
// + 1 là thứ 3
// + 2 là thứ 4
// + 3 là thứ 5
// + 4 là thứ 6
// + 5 là thứ 7
// + 6 là thứ CN 
// In ra những ngày là thứ 6 ngày 13 trong năm đó theo dạng DD-MM-YYYY, mỗi ngày được in trên 1 dòng riêng

// INPUT
// 0 2024

// OUTPUT
// 13-09-2024
// 13-12-2024
// Test Case mẫu

// INPUT
// 0 2024

// OUTPUT
// 13-09-2024
// 13-12-2024

#include <stdio.h>

int laNamNhuan(int nam) {
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
        return 1; 
    }
    return 0; 
}

int main() {
    int thuDauNam, nam;
    
    scanf("%d %d", &thuDauNam, &nam);

    int soNgayTrongThang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (laNamNhuan(nam)) {
        soNgayTrongThang[2] = 29;
    }

    int thuHienTai = (thuDauNam + 12) % 7;

    for (int thang = 1; thang <= 12; thang++) {
        
        if (thuHienTai == 4) {
            printf("13-%02d-%d\n", thang, nam);
        }

        if (thang < 12) {
            int soNgay = soNgayTrongThang[thang];
            thuHienTai = (thuHienTai + soNgay) % 7;
        }
    }

    return 0;
}