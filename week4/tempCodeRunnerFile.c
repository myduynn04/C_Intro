#include <stdio.h>

int main() {
    int blockSize;
    long long fileSize;

    scanf("%d %lld", &blockSize, &fileSize);

    long long blockSize = blockSize * 1024;
    long long numBlocks = (fileSize + blockSize - 1) / blockSize;
    long long sizeOnDisk = numBlocks * blockSize;

    printf("%lld %lld\n", numBlocks, sizeOnDisk);

    return 0;
}