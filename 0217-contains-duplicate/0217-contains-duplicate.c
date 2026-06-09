#include <stdbool.h>
#include <stdlib.h>

// Ham so sanh can thiet de chay qsort
int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    // 1. Sap xep mang tang dan (O(n log n))
    qsort(nums, numsSize, sizeof(int), compare);
    
    // 2. Duyet mang de kiem tra cac phan tu dung canh nhau
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true; // Thay hai thang giong nhau dung canh nhau thi bao trung luon
        }
    }
    
    // Duyet het mang ma khong thay cap nao trung thi tra ve false
    return false;
}