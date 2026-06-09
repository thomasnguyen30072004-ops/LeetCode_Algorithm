#include <stdio.h>

int thirdMax(int* nums, int numsSize) {
    // Dung long long va chon mot gia tri lam "co hieu" (flag) nam ngoai range cua int 32-bit
    long long max1 = -2222222222222LL;
    long long max2 = -2222222222222LL;
    long long max3 = -2222222222222LL;
    
    for (int i = 0; i < numsSize; i++) {
        long long v = nums[i];
        
        // Neu gap so da ton tai trong cac bien max thi bo qua de dam bao tinh phan biet (distinct)
        if (v == max1 || v == max2 || v == max3) {
            continue;
        }
        
        // Thuc hien don cap cac bien max nhu xep hang dung vi tri
        if (v > max1) {
            max3 = max2;
            max2 = max1;
            max1 = v;
        } else if (v > max2) {
            max3 = max2;
            max2 = v;
        } else if (v > max3) {
            max3 = v;
        }
    }
    
    // Neu max3 van giu nguyen gia tri flag ban dau, chung to mang khong co du 3 so max phan biet
    if (max3 == -2222222222222LL) {
        return (int)max1; // Tra ve so lon nhat theo yeu cau de bai
    }
    
    return (int)max3;
}