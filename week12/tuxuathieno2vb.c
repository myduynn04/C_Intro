// Trung bình
// Hai văn bản được coi là tương đồng (sao chép) nếu chúng có số lượng từ chung giống nhau nhiều.
// Hãy viết chương trình nhập và 2 đoạn văn, mỗi đoạn văn trên 1 dòng, và in ra các từ xuất hiện ở cả 2 đoạn văn đó.
// Chú ý:
// + Không phân biệt chữ hoa/thường
// + Các từ xuất hiện nhiều lần chỉ đếm 1 lần
// + thứ tự từ in ra theo thứ tự xuất hiện trong đoạn văn thứ nhất
// + Độ dài mỗi đoạn văn không quá 1000 ký tự.
// + các từ chung được in ra cách nhau 1 dấu cách trống
// + Các từ cần có độ dài ít nhất từ 3 ký tự
// + các từ trong văn đơn giản, chỉ ngăn cách bằng dấu ,.!?:

// Gợi ý:
// + Tách đoạn văn thành mảng các từ
// + chuyển từ về chữ thường và lọc hết các từ ngắn hơn 3 ký tự
// + Kiểm tra lần lượt các từ trong đoạn văn 1 tồn tại trong đoạn văn 2 dùng hàm strcmp
// + ghi nhận từ đã in ra để tránh in lại 
// Test Case mẫu

// INPUT
// It burns beautifully. It's a Russian S-300. On Russian territory. The first days after permission to use Western weapons on enemy territory.
// The missile launch is visually striking. It appears to be a Russian S-300 surface-to-air missile system. The location seems to be within Russia's borders. This footage may be from the initial period after Ukraine was permitted to employ Western-supplied weapons against enemy targets on Russian territory.

// OUTPUT
// russian s-300 territory the after weapons enemy