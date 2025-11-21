// File khi lưu trữ trên ổ cứng sẽ được lưu trữ theo 1 số nguyên lần kích thước 1 block.
// Ví dụ kích thước 1 block trên ổ cứng đang định dạng là 4KB và kích thước của file là 342 Byte.
// Để lưu trữ file này ta cần dùng 1 block, kích thước file lưu trên ổ cứng (size on disk) sẽ là 4096 Bytes.

// Hãy viết chương trình nhập vào 
// + kích thước 1 block (theo KB)
// + kích thước file theo Byte

// In ra số lượng block và kích thước thực sự của file lưu trên ổ cứng.

// 1KB = 1024 Byte
// Test Case mẫu

// INPUT
// 4 342
// OUTPUT
// 1 4096

// INPUT
// 4 3456783
// OUTPUT
// 844 3457024
#include <stdio.h>

int main() {
    int blockSizeKB;
    long long fileSizeBytes;

    scanf("%d %lld", &blockSizeKB, &fileSizeBytes);

    long long blockSizeBytes = blockSizeKB * 1024;

    long long numBlocks = (fileSizeBytes + blockSizeBytes - 1) / blockSizeBytes;

    long long sizeOnDisk = numBlocks * blockSizeBytes;

    printf("%lld %lld\n", numBlocks, sizeOnDisk);

    return 0;
}