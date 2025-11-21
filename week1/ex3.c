// Theo quy định của Tổ chức Khí tượng thế giới (WMO), mưa lớn được chia làm 3 cấp: 
// - Mưa vừa: Lượng mưa đo được từ 16 đến 50 mm/24h, hoặc 8 đến 25 mm/12h. 
// - Mưa to: Lượng mưa đo được từ 51 đến 100 mm/24h, hoặc 26 đến 50mm/12h. 
// - Mưa rất to: Lượng mưa đo được > 100 mm/24h, hoặc > 50 mm/12h

// Chương trình sau đọc vào lượng mưa theo 24h và in ra cấp độ mưa.
// Tuy nhiên vẫn còn có lỗi trong chương trình hãy sửa lại cho đúng.


#include<stdio.h>
int capDoMua(int luongMua24h)
{
	if(luongMua24h<=0) return -1;
	if (luongMua24h < 16) return 0;
	if (luongMua24h <= 50) return 1;
	if (luongMua24h <= 100) return 2;
	return 3;
}

void inCapDoMua(int level)
{
	switch (level)
	{
	case 0: printf("mua nho!");
		break;
	case 1: printf("mua vua!");
		break;
	case 2: printf("mua to!");
		break;
	case 3: printf("mua rat to!");
		break;
	default: printf("du lieu loi!");
	}
}

int main()
{
	double luongMua24h;
	printf("Luong mua trong 24h: ");
	scanf("%lf", &luongMua24h);
	int capdo = capDoMua(luongMua24h);
	inCapDoMua(capdo);
	return 0;
}