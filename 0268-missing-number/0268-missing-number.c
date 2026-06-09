#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    // 1. Tinh tong ly thuyet cua day tu 0 den n (n chinh la numsSize)
    int expectedSum = (numsSize * (numsSize + 1)) / 2;
    
    int actualSum = 0;
    // 2. Tinh tong thuc te cua cac phan tu dang co trong mang
    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }
    
    // 3. Hieu hai so chinh la so con thieu
    return expectedSum - actualSum;
}

/* Cach 2:
int missingNumberXOR(int* nums, int numsSize) {
    int res = numsSize; // Khoi tao bang n
    
    for (int i = 0; i < numsSize; i++) {
        // XOR lien tuc ca index (i) va gia tri (nums[i])
        res ^= i ^ nums[i];
    }
    
    return res;
}
*/