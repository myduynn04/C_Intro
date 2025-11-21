#include<stdio.h>
int main()
{
	double a,b;
	printf("Nhap vao do dai 2 canh: ");
	scanf("%lf%lf",&a,&b);
	if(a>0 && b>0 && a<1e6 && b<1e6)
	{
		printf("Dien tich: %lf",a*b);
	}
	else
	{
		printf("Du lieu nhap vao khong hop le!");
	}
	return 0;
}