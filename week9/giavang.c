// Một người theo dõi và lưu lại giá vàng lúc đóng cửa thị trường trong nhiều ngày.
// Dựa vào lịch sử giá vàng đó, hãy in ra chuỗi ngày tăng giá dài nhất.

// Chuỗi ngày tăng giá độ dài k là k ngày liên tiếp mà a[i]<a[i+1] trong đó a[i] và a[i+1] là giá vàng của 2 ngày liên tiếp.
// Đầu vào là giá vàng của các ngày liên tiếp, kết thúc là giá trị -1.
// Đầu ra là độ dài chuỗi ngày tăng dài nhất.
// Test Case mẫu

// INPUT 
// 2 3 4 3 5 -1

// OUTPUT 
// 3

// 2063.80 2058.51 2040.19 2043.26 2045.50 2027.84 2029.59 2023.40 2028.09 2048.72 2054.49 2027.59 2005.72 2022.67 2029.09 2020.09 2027.68 2012.59 2019.75 2018.34 2031.75 2036.12 2037.19 2054.09 2038.59 2024.67 2035.46 2034.22 2033.18 2024.16 2019.79 1992.13 1992.39 2004.09 2013.10 2017.63 2023.53 2024.99 2024.11 2035.72 2030.66 2029.64 2034.62 2043.24 2083.39 2114.99 2127.55 2148.29 2159.16 2177.51 2182.47 2157.99 2174.40 2161.01 2155.54 2159.99 2157.23 2185.96 2180.81 2164.15 2171.45 2178.58 2194.02 2232.38 2250.36 2280.10 2299.17 2289.43 2329.50 2338.89 2352.58 2332.79 2373.24 2343.43 2382.51 2382.83 2360.81 2378.25 2390.45 2326.29 2317.60 -1

#include <stdio.h>

int main(){
	int max_count = 0;
	double prev = 0.0;
	int count = 0;

    scanf("%lf", &prev);
    if (prev == -1) {
        printf("0");
        return 0;
    }
    count = 1;
    max_count = count;

	while(1){
		double n;
		scanf("%lf", &n);
        // printf("n=%lf\n", n);
		if (n == -1) break;
		if (n > prev) {
            count ++;
            // printf("count=%d\n", count);
        }
		else {
			if (count > max_count) max_count = count;
			count = 1;
            // printf("count=%d\n", count);
		}
        prev = n;
	}
	printf("%d", max_count);
} 
