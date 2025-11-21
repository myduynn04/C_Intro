// Một người nông dân muốn đưa trái sầu riêng của nông trại mình lên sàn, tuy nhiên ông không biết nên đặt giá cụ thể bao nhiêu để tránh rơi vào trường hợp giá thấp quá hoặc cao quá.
// Người nông dân nghĩ ra cách là theo dõi giá khớp của các giao dịch gần đây nhất và sẽ đưa ra giá của mình dựa trên trung bình giá của các giao dịch gần nhất.
// Hãy viết chương trình giúp người nông dân làm được việc đó.
 

// INPUT
// 126.5 125.4 125 124.5 125 -1

// OUTPUT
// 125.28

// Dòng tiếp theo là các giá khớp lệnh của các giao dịch gần đây, mỗi giá cách nhau bởi dấu cách trống, kết thúc chuỗi giá sẽ là giá trị -1

// Đầu ra in ra giá trung bình trong các giao dịch được khớp gần nhất, kết quả lấy đến 2 chữ số thập phân

// Chú ý. Trong trường hợp không có giá của các giao dịch thì in ra -1

#include <stdio.h>


int main(){
	double avg_price = 0.0;
	double sum = 0.0;
	int count = 0;
	while (1){
		double price = 0.0;
		if(scanf("%lf", &price)!=1) break;
		if(price == -1) break;
		count++;
		sum+= price;
		
	}
	if (count == 0) {
		printf("-1");
	} else {
		printf("%.2lf", sum/count);
	}
	
} 
