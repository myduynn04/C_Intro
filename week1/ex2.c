#include <stdio.h>
int main()
{
	double a,b,c;
	printf("Nhap vao do dai 3 canh: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a>=0 && b>=0 && c>0  && a+b>c && b+c>a && b+a>c)
	{
		printf("%f",a+b+c);
	}
	else
	{
		printf("khong hop le");
	}
	return 0;
}