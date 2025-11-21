/*
* Sửa lỗi và hoàn thiện đoạn code thực hiện công việc
* nhập vào số tiền cần vay, lãi suất tính theo năm theo %, và thời gian vay tính theo năm
* Hãy viết chương trình tính số tiền phải trả (bao gồm cả lãi)
* công thức tính dạng đơn giản là
* tien_tra = tien_vay *(1+lai_suat/100)^thoi_gian_vay
* Để tính mũ dạng x^n ta dùng hàm pow: x^n = pow(x,n)
*/
#include <stdio.h>
#include <math.h>

int main()
{
	double tien_vay, lai_suat, tien_tra;
	int thoi_gian_vay;

	// nhập các giá trị phù hợp
	scanf("%lf%lf%d", &tien_vay, &lai_suat, &thoi_gian_vay);

	// tính số tiền phải trả
	tien_tra = tien_vay * pow(1 + lai_suat / 100, thoi_gian_vay);
	// in ra tiền trả
	printf("%.2lf VND\n", tien_tra);
}